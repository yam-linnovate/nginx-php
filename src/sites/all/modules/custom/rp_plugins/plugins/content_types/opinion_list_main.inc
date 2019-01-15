<?php
/**
 * Plugin info
 */
$plugin = array(
  'title' => t('Opinion List Main'),
  'single' => TRUE,
  'category' => array(t('Opinion Page'), -9),
);

/**
 * Run-time rendering of the body of the block.
 */
function rp_plugins_opinion_list_main_content_type_render($subtype, $conf, $args, $context) {
    $output = '';
    if($conf['auto']) {
      $view = views_get_view_result('opinions', 'block_1');
      $large_id = isset($view[0]->nid) ? $view[0]->nid : 0;
      $left_id1 = isset($view[1]->nid) ? $view[1]->nid : 0;
      $left_id2 = isset($view[2]->nid) ? $view[2]->nid : 0;
    }
    else {
      $large_id = $conf['large_id'];
      $left_id1 = $conf['left_id1'];
      $left_id2 = $conf['left_id2'];
    }
    $large = '';
    if($large_id){
      $large .= rp_plugins_opinion_list_main_render_item($large_id, '890x550');
    }

    $left = '';
    if($left_id1){
      $left .= rp_plugins_opinion_list_main_render_item($left_id1, '460x260');
    }
    if($left_id2){
      $left .= rp_plugins_opinion_list_main_render_item($left_id2, '460x260');
    }
    $output = '<div class="opinion-main-large">' . $large . '</div><div class="opinion-main-left">' . $left . '</div>';
    $content = new stdClass();
    $content->node_id = array(
        '1' => $large_id,
        '2' => $left_id1,
        '3' => $left_id2
    );

  if(isset($conf['api'])){
        return $content;
    }

    $block = new stdClass();
    $block->title = '';
    $block->content = $output;

    return $block;
}

function rp_plugins_opinion_list_main_content_type_edit_form($form, &$form_state) {

  unset($form['override_title']);
  unset($form['override_title_text']);
  unset($form['override_title_markup']);
  unset($form['override_title_heading']);
  
  $conf = $form_state['conf'];
  $form['auto'] = array(
    '#type' => 'checkbox',
    '#title' => t('Automatic Load last opinions'),
    '#default_value' => !empty($conf['auto']) ? $conf['auto'] : '0',
  );
  $form['large_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Large opinion ID'),
    '#maxlength' => 512,
    '#description' => t('A valid opinion id.'),
    '#autocomplete_path' => 'ctools/autocomplete/node',
    '#default_value' => !empty($conf['large_id']) ? $conf['large_id'] : '0',
    '#states' => array(
      'invisible' => array(
        ':input[name="auto"]' => array('checked' => TRUE),
      ),
    ),
  );

  $form['left_id1'] = array(
    '#type' => 'textfield',
    '#title' => t('Left opinion ID 1'),
    '#maxlength' => 512,
    '#description' => t('A valid opinion id.'),
    '#autocomplete_path' => 'ctools/autocomplete/node',
    '#default_value' => !empty($conf['left_id1']) ? $conf['left_id1'] : '0',
    '#states' => array(
      'invisible' => array(
        ':input[name="auto"]' => array('checked' => TRUE),
      ),
    ),
  );

  $form['left_id2'] = array(
    '#type' => 'textfield',
    '#title' => t('Left opinion ID 2'),
    '#maxlength' => 512,
    '#description' => t('A valid opinion id.'),
    '#autocomplete_path' => 'ctools/autocomplete/node',
    '#default_value' => !empty($conf['left_id2']) ? $conf['left_id2'] : '0',
    '#states' => array(
      'invisible' => array(
        ':input[name="auto"]' => array('checked' => TRUE),
      ),
    ),
  );
  return $form;
}

function rp_plugins_opinion_list_main_content_type_edit_form_submit($form, &$form_state){
    $form_state['conf']['pid'] = $form_state['pane']->pid;
    $form_state['conf']['auto'] = $form_state['values']['auto'];    
    $form_state['conf']['large_id'] = $form_state['values']['large_id'];    
    $form_state['conf']['left_id1'] = $form_state['values']['left_id1'];    
    $form_state['conf']['left_id2'] = $form_state['values']['left_id2'];
    if($form_state['conf']['auto']){
      variable_set('opinion_list_main', 'auto');
    }
    else variable_set('opinion_list_main', array($form_state['conf']['large_id'], $form_state['conf']['left_id1'], $form_state['conf']['left_id2']));
}

function rp_plugins_opinion_list_main_content_type_edit_form_validate(&$form, &$form_state) {
  foreach (array('large_id', 'left_id1', 'left_id2') as $key) {
    $node = rp_plugins_opinion_list_main_autocomplete($form_state['values'][$key]);
    if ($node) {
      $form_state['values'][$key] = $node->nid;
    }
    if ($form_state['values'][$key] == '0')
      $form_state['values'][$key] = 0; 
    if (($node->type != 'opinion' || !node_access('view', $node)) && $form_state['values'][$key] != '0') {
      form_error($form[$key], t('Invalid node'));
    }
  }      
}
function rp_plugins_opinion_list_main_autocomplete($nid)  {
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

function rp_plugins_opinion_list_main_render_item($id, $image_style){
  $node = node_load($id);
  if($node) {
    $link_to_node = drupal_get_path_alias('node/' . $node->nid);
    $output = '';
    $output = '<div class="opinion-img-wrapper">';
    $field_images = field_collection_item_load($node->field_images[LANGUAGE_NONE][0]['value']);
    if($field_images){
      $output .= '<div class="opinion-img"><a href="' . $link_to_node . '">';
      $output .= theme('image_style', array('style_name' => $image_style, 'alt' => $field_images->field_image['und'][0]['alt'], 'path' => $field_images->field_image[LANGUAGE_NONE][0]['uri']));
      $output .= '</a></div>';
    }
    $writer = taxonomy_term_load($node->field_writer[LANGUAGE_NONE][0]['tid']);
    $writer_image = theme('image_style', array('style_name'=> 'writer_120x120', 'alt' => $field_images->field_image['und'][0]['alt'], 'path' => $writer->field_opinion_drawing[LANGUAGE_NONE][0]['uri']));
    $writer_name = $writer->name;
    $writer_output ='<div class="opinion-writer-wrapper"><div class="opinion-writer-img"><a href="/search?writer=' . $writer->tid . '">' . $writer_image . '</a></div><div class="opinion-writer-name"><a href="/search?writer=' . $writer->tid . '">' . $writer_name . '</a></div></div>';
    $output .= '<div class="opinion-title-wrapper"><a href="' . $link_to_node . '"><div class="opinion-title">' . $node->field_front_page_title[LANGUAGE_NONE][0]['value'] . '</div></a></div>' . $writer_output . '';
    $output .= '</div>';
    return $output;
  }
}