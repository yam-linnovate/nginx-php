<?php
/**
 * Plugin info
 */
$plugin = array(
  'title' => t('Article Image'),
  'single' => TRUE,
  'category' => array(t('Front Page'), -9),
);

/**
 * Run-time rendering of the body of the block.
 */
function rp_plugins_image_article_content_type_render($subtype, $conf, $args, $context) {
  $output = "";
  $content = new stdClass();
  $nid      = $conf['nid'];
  $node = node_load($nid);
  if($node) {
    if (!node_access('view', $node)) {
      return;
    }
    $node_path  = drupal_get_path_alias('node/' . $nid);
    $wrp              = entity_metadata_wrapper('node', $nid);
    $text             = $wrp->field_front_page_title->value();
    $section_name     = $wrp->field_section->name->value();
    $section_id       = $wrp->field_section->tid->value();

    $link = '';
    $option = $conf['link_options'];
    $text_link = ($conf['custom_text'] != '') ? $conf['custom_text'] : t('More Articles');
    if($option == 0){
      $term = taxonomy_term_load($section_id);
      $term_path = entity_uri('taxonomy_term', $term);
      $term_path = url($term_path['path'], $term_path['options']);
      $link = l($text_link . ' >', $term_path, array('attributes' => array('class' => 'pane-title-link')));
    }
    elseif($option == 1)
      $link = l($text_link . ' >', $conf['custom_link'], array('attributes' => array('class' => 'pane-title-link')));  
    
    $image_coll = $wrp->field_images->value();
    $image_uri = $image_coll->field_image[LANGUAGE_NONE][0]['uri'];
    $img = theme('image_style', array('path' => $image_uri , 'alt' => $field_images->field_image['und'][0]['alt'], 'style_name' => '275x155'));
    $image = '<a href="'. $node_path . '">' . $img . '</a>';
    $link = urldecode($link);
    //Set the output.
    $output .= '<div class="article-image-link">' . $link . '</div>';
    $output .= '<div class="article-image">' . $image . '</div>';
    $output .= '<div class="article-image-description image-label">' . $text . '</div>';
    $content->node_id[1] = $conf['nid'];
    if(isset($conf['api'])){
        return $content;
    }
  }
  
  


  $block = new stdClass();
  $block->title = '';
  $block->content = $output;

  return $block;
}


function rp_plugins_image_article_content_type_edit_form($form, &$form_state) {
  unset($form['override_title']);
  unset($form['override_title_text']);
  unset($form['override_title_markup']);
  unset($form['override_title_heading']);
  $conf = $form_state['conf'];

  $form['nid'] = array(
    '#type' => 'textfield',
    '#title' => t('Article ID'),
    '#size' => 60,
    '#description' => t('A valid number.'),
    '#autocomplete_path' => 'ctools/autocomplete/node',
    '#default_value' => !empty($conf['nid']) ? $conf['nid'] : '',
  );
  $link_options = array(0 => t('Auto Link'), 1 => t('Custom Link'),2 => t('No link'));
  $form['link_options'] = array(
    '#type' => 'radios',
    '#title' => t('Select Options link'),
    '#default_value' => !empty($conf['link_options']) ? $conf['link_options'] : 0,
    '#options' => $link_options,
  );
  $form['custom_link'] = array(
    '#type' => 'textfield',
    '#title' => t('link for more'),
    '#default_value' => !empty($conf['custom_link']) ? $conf['custom_link'] : '',
    '#size' => '20',
    '#states' => array(
      'visible' => array(
        ':input[name="link_options"]' => array('value' => '1'),
      ),
    ),
  );
  $form['custom_text'] = array(
    '#type' => 'textfield',
    '#title' => t('text for more'),
    '#default_value' => !empty($conf['custom_text']) ? $conf['custom_text'] : t('More Articles'),
    '#size' => '20'
  );
  return $form;
}


function rp_plugins_image_article_content_type_edit_form_submit($form, &$form_state) {
  $form_state['conf']['nid'] = $form_state['values']['nid'];  
  $form_state['conf']['link_options'] = $form_state['values']['link_options'];
  $form_state['conf']['custom_link'] = $form_state['values']['custom_link'];
  $form_state['conf']['custom_text'] = $form_state['values']['custom_text'];
  
}

function rp_plugins_image_article_content_type_edit_form_validate(&$form, &$form_state) {
  $nid = $form_state['values']['nid'];
  $node = rp_plugins_image_article_autocomplete($nid);
  if ($node) {
    $form_state['values']['nid'] = $node->nid;
  } 
  if ((($node->type != 'opinion' && $node->type != 'article' && $node->type != 'video') || !node_access('view', $node)) && $form_state['values']['nid'] != '0') {
    form_error($form['nid'], t('Invalid node'));
  }
}

function rp_plugins_image_article_autocomplete($nid)  {
  $preg_matches = array();
  $match = preg_match('/\[id: (\d+)\]/', $nid, $preg_matches);
  if (!$match) {
    $match = preg_match('/^id: (\d+)/', $nid, $preg_matches);
  }

  if ($match) {
    $nid = $preg_matches[1];
  }
  if (is_numeric($nid)) {
    $node = db_query('SELECT nid, status, type FROM {node} WHERE nid = :nid', array(':nid' => $nid))->fetchObject();
  }
  else {
    $node = db_query('SELECT nid, status, type FROM {node} WHERE LOWER(title) = LOWER(:title)', array(':title' => $nid))->fetchObject();
  }
  return $node;
}