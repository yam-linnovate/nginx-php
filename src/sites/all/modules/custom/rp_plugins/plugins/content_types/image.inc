<?php
/**
 * Plugin info
 */
$plugin = array(
    'title' => t('Add image'),
    'single' => TRUE,
    'category' => array(t('Elements'), -9),
);

function rp_plugins_image_content_type_render($subtype, $conf, $args, $context) {
    $content = array();
    $content_api = new stdClass();
    $data = $conf;

    $content = array(
        '#theme' => 'pane_image',
        '#content' => $data,
    );


  if(isset($conf['api'])){

        return $content_api;
    }


    $block = new stdClass();
    $block->title = '';
    $block->content = $content;

    return $block;
}

function rp_plugins_image_content_type_edit_form($form, &$form_state){
    form_load_include($form_state, 'inc', 'file', 'file.field');
    form_load_include($form_state, 'inc', 'rp_plugins','plugins/content_types/image');

    unset($form['override_title']);
    unset($form['override_title_text']);
    unset($form['override_title_markup']);
    unset($form['override_title_heading']);

    $conf = $form_state['conf'];
    $form['image'] = array(
        '#type' => 'managed_file',
        '#upload_location' => 'public://images/panes-images/',
        '#title' => t('Image'),
        '#default_value' => !empty($conf['image']) ? $conf['image'] : '',
    );
    $form['alt'] = array(
        '#type' => 'textfield',
        '#title' => t('Alt text'),
        '#maxlength' => 512,
        '#default_value' => !empty($conf['alt']) ? $conf['alt'] : '',
    );


    $all_image_styles = image_styles();
    $list = array_column($all_image_styles, 'name', 'name');
    array_unshift($list, t('Original'));


    $form['img_style'] = array(
        '#type' => 'select',
        '#title' => t('Menu'),
        '#options' => $list,
        '#default_value' => !empty($conf['img_style']) ? $conf['img_style'] : '',
    );

    return $form;

}

function rp_plugins_image_content_type_edit_form_submit($form, &$form_state){
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

    $form_state['conf']['image'] = $form_state['values']['image'];
    $form_state['conf']['alt'] = $form_state['values']['alt'];
    $form_state['conf']['img_style'] = $form_state['values']['img_style'];
}