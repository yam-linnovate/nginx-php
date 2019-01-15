<?php
/**
 * Plugin info
 */
$plugin = array(
  'title' => t('Section Title'),
  'single' => TRUE,
  'category' => array(t('Front Page'), -9),
);

/**
 * Run-time rendering of the body of the block.
 */
function rp_plugins_section_title_content_type_render($subtype, $conf, $args, $context) {
  $link = '';
    $content = new stdClass();
  $section_id = $conf['section'];
  $section = taxonomy_term_load($section_id);
  $option = $conf['link_options'];
  $text_link = ($conf['custom_text'] != '') ? $conf['custom_text'] : t('More Articles');
  if($option == 0)  {
    $term = taxonomy_term_load($section_id);
    $link = entity_uri('taxonomy_term', $term);
    $link = url($link['path'], $link['options']);
  }
  elseif($option == 1)
    $link =  $conf['custom_link'];
  if(isset($conf['title']) && $conf['title'] != '')
    $title = $conf['title'];
  else
    $title = $section->name;
  $title = urldecode($title);
  $link = '<a class="view-more" href="' . $link . '">' . t($text_link) . '</a>';
  
  $link = urldecode($link);
  $output = '<h2 class="pane-title">' . $title . $link . '</h2>';;

  if(isset($conf['api'])){
        return $content;
    }


    $block = new stdClass();
  $block->title =  '';
  $block->content = $output;
  return $block;
}

/**
 * Edit form callback for the content type.
 */
function rp_plugins_section_title_content_type_edit_form($form, &$form_state) {
    
  unset($form['override_title']);
  unset($form['override_title_text']);
  unset($form['override_title_markup']);
  unset($form['override_title_heading']);
  
  $conf = $form_state['conf'];

  // prepare the section options
  $options = array();
  $section = taxonomy_vocabulary_machine_name_load('section');
  if ($terms = taxonomy_get_tree($section->vid)) {
    foreach ($terms as $term) {
      $depth = '';
      if($term->depth > 0)
       $depth = ' > ';
      $options[$term->tid] = $depth.$term->name;
    }
  }
  $form['title'] = array(
    '#type' => 'textfield',
    '#title' => t('Override title'),
    '#default_value' => !empty($conf['title']) ? $conf['title'] : '',
    '#size' => '20'
  );
  $form['section'] = array(
    '#type' => 'select',
    '#title' => t('Sections'),
    '#default_value' => !empty($conf['section']) ? $conf['section'] : 0,
    '#options' => $options,
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

/**
 * Submit edit form callback for the content type.
 */
function rp_plugins_section_title_content_type_edit_form_submit($form, &$form_state) {
  $form_state['conf']['section'] = $form_state['values']['section'];
  $form_state['conf']['link_options'] = $form_state['values']['link_options'];
  $form_state['conf']['custom_link'] = $form_state['values']['custom_link'];
  $form_state['conf']['custom_text'] = $form_state['values']['custom_text'];
  $form_state['conf']['title'] = $form_state['values']['title'];
}
