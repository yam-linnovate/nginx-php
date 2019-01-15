<?php
/**
 * Plugin info
 */
$plugin = array(
  'title' => t('Title lecturer'),
  'single' => TRUE,
  'category' => array(t('Lecturer Page'), -10),
);

/*
 * Run-time rendering of the body of the block.
 */
function rp_plugins_title_lecturer_content_type_render($subtype, $conf, $args, $context) {
  $output = '';
  $image = '';
  $title = '';
  $description = '';
  $description_mobile = '';
  $detect = mobile_detect_get_object();
  $is_mobile = $detect->isMobile();
  $is_tablet = $detect->isTablet();

  if($conf['title']) {
    $title = '<h1 class="pane-title">' . t($conf['title']) . '</h1>';
  }
  if ($conf['description']['value']){
    $description = '<div class="description">'. $conf['description']['value'] . '</div>';
    if($is_mobile || $is_tablet) {
      $router_path = menu_get_active_trail();
      if(isset($router_path[1]['router_path'])) {
        if($router_path[1]['router_path'] == 'contact_us') {
          $description = '';
        }
      }
    }
  }
  if ($conf['description_mobile']['value']){
    $description_mobile = '<div class="description">'. $conf['description_mobile']['value'] . '</div>';
    if($is_mobile || $is_tablet) {
      $router_path = menu_get_active_trail();
      if(isset($router_path[1]['router_path'])) {
        if($router_path[1]['router_path'] == 'contact_us') {
          $description_mobile = '';
        }
      }
    }
  }

  if(!$is_mobile && !$is_tablet){
    if($conf['image']) {
      $file = file_load($conf['image']);
      $uri = $file->uri;
      $url = file_create_url($uri);
      $divimage = '<div class="img-background" style="background-image: url('. $url . ');">' .$title . $description . '</div>' ;
    }
  } else if($is_mobile || $is_tablet) {
    if($conf['image_mobile']) {
      $file = file_load($conf['image_mobile']);
      $uri = $file->uri;
      $url = file_create_url($uri);
      $divimage = '<div class="img-background" style="background-image: url('. $url . ');">' .$title . $description_mobile . '</div>' ;
    } else {
      $file = file_load($conf['image']);
      $uri = $file->uri;
      $url = file_create_url($uri);
      $divimage = '<div class="img-background" style="background-image: url('. $url . ');">' .$title . $description_mobile . '</div>' ;
    }
  }

  $output = $divimage;

  if(isset($conf['api'])){
    $content = new stdClass();
    return $content;
  }


  $block = new stdClass();
  $block->title = '';
  $block->content = $output;

  return $block;

}

function rp_plugins_title_lecturer_content_type_edit_form($form, &$form_state) {
  form_load_include($form_state, 'inc', 'file', 'file.field');
  form_load_include($form_state, 'inc', 'rp_plugins','plugins/content_types/title_lecturer');

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
    '#upload_location' => 'public://images/panes-images/',
    '#title' => t('Header image'),
    '#default_value' => !empty($conf['image']) ? $conf['image'] : '',
  );
  $form['image_mobile'] = array(
    '#type' => 'managed_file',
    '#upload_location' => 'public://images/panes-images/',
    '#title' => t('Header mobile image'),
    '#default_value' => !empty($conf['image_mobile']) ? $conf['image_mobile'] : '',
  );
  $form['description'] = array(
    '#type' => 'text_format',
    '#title' => t('Add description to page segel'),
    '#maxlength' => 512,
    '#description' => t('Add description to page segel'),
    '#default_value' => !empty($conf['description']['value']) ? $conf['description']['value'] : '',
  );
  $form['description_mobile'] = array(
    '#type' => 'text_format',
    '#title' => t('Add description for mobiles to page segel'),
    '#maxlength' => 512,
    '#description' => t('Add description for mobile to page segel'),
    '#default_value' => !empty($conf['description_mobile']['value']) ? $conf['description_mobile']['value'] : '',
  );

  return $form;
}


function rp_plugins_title_lecturer_content_type_edit_form_submit($form, &$form_state){
  if($form_state['values']['image']){
    // Load the file via file.fid.
    $file = file_load($form_state['values']['image']);
    // Change status to permanent.
    $file->status = FILE_STATUS_PERMANENT;
    // Save.
    file_save($file);
    // Record that the module (in this example, user module) is using the file.
    file_usage_add($file, 'rp_plugins', 'title_lecturer' , $file->fid);
  }
  if($form_state['values']['image_mobile']){
    // Load the file via file.fid.
    $file = file_load($form_state['values']['image_mobile']);
    // Change status to permanent.
    $file->status = FILE_STATUS_PERMANENT;
    // Save.
    file_save($file);
    // Record that the module (in this example, user module) is using the file.
    file_usage_add($file, 'rp_plugins', 'title_lecturer' , $file->fid);
  }

  $form_state['conf']['title'] = $form_state['values']['title'];
  $form_state['conf']['image'] = $form_state['values']['image'];
  $form_state['conf']['image_mobile'] = $form_state['values']['image_mobile'];
  $form_state['conf']['description']['value'] = $form_state['values']['description']['value'];
  $form_state['conf']['description_mobile']['value'] = $form_state['values']['description_mobile']['value'];

}