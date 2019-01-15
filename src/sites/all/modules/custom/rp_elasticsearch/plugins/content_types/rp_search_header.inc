<?php
/**
 * Plugin info
 */
$plugin = array(
  'title' => t('Republish Search Header'),
  'single' => TRUE,
  'category' => array(t('Miscellaneous'), -9),
);

/**
 * Run-time rendering of the body of the block.
 */
function rp_elasticsearch_rp_search_header_content_type_render($subtype, $conf, $args, $context) {
    $output = '';
    $image = '';
    $title = '';
    if($conf['title']){
      $title = '<h1 class="title">' . t($conf['title']) . '</h1>';
    }
    if($conf['image']){
      $file = file_load($conf['image']);
      $image = $file ? '<div class="img-background">' . theme('image', array('path' => $file->uri)) . '</div>' : '';
    }
    $params = drupal_get_query_parameters();
    $key = isset($params['key']) && $params['key']? $params['key'] : '';
    if($key)
      $key = '<span class="key">' . $key . '</span>';

    $tag = isset($params['tag']) && $params['tag'] ? taxonomy_term_load($params['tag'])->name : '';
    if($tag)
      $tag = t(' מתויגות תחת ') . '<span class="tag">' . $tag . '</span>';

    $output = $image;
    $output .= '<div class="content">' . $title . '</div>';

  if(isset($conf['api'])){
        $content = new stdClass();
        return $content;
    }


    $block = new stdClass();
    $block->title = '';
    $block->content = $output;

    return $block;
}

function rp_elasticsearch_rp_search_header_content_type_edit_form($form, &$form_state) {
  form_load_include($form_state, 'inc', 'file', 'file.field');
  form_load_include($form_state, 'inc', 'rp_elasticsearch','plugins/content_types/rp_search_header');
  unset($form['override_title']);
  unset($form['override_title_text']);
  unset($form['override_title_markup']);
  unset($form['override_title_heading']);
  
  $conf = $form_state['conf'];
  $form['title'] = array(
    '#type' => 'textfield',
    '#title' => t('Title'),
    '#maxlength' => 512,
    '#default_value' => !empty($conf['title']) ? $conf['title'] : '',
  );
  $form['image'] = array(
    '#type' => 'managed_file',
    '#upload_location' => 'public://panes/search_header_',
    '#title' => t('Header image'),
    '#default_value' => !empty($conf['image']) ? $conf['image'] : '',
  );
  return $form;
}

function rp_elasticsearch_rp_search_header_content_type_edit_form_submit($form, &$form_state){
  if($form_state['values']['image']){
    $file = file_load($form_state['values']['image']);
    // Change status to permanent.
    $file->status = FILE_STATUS_PERMANENT;
    // Save.
    file_save($file);
    // Record that the module (in this example, user module) is using the file.
    file_usage_add($file,  'rp_elasticsearch' ,'search_header' , $file->fid);
  }
  $form_state['conf']['title'] = $form_state['values']['title'];
  $form_state['conf']['image'] = $form_state['values']['image'];
}