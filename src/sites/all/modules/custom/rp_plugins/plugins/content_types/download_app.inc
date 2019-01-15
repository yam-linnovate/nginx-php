<?php
/**
 * Plugin info
 */
$plugin = array(
    'title' => t('Download App'),
    'single' => TRUE,
    'category' => array(t('Front Page'), -9),
);

/**
 * Run-time rendering of the body of the block.
 */
function rp_plugins_download_app_content_type_render($subtype, $conf, $args, $context) {
    $image = '';
    $output = '';
    $output .= '<div class="download-app" style="background-image: url(' ;
    if($conf['image']){
        $file = file_load($conf['image']);
        $url = file_create_url($file->uri);
        $output .= $url;
    }
    $output .= ')">' ;

    $output .= '<div class="desc-download" >';
    $output .= '<p>'. $conf['desc_to_download']['value'] . '</p>';
    $output .= '</div>';
    $output .= '<div class="wrap-btn-down" >';
    $output .= '<div class="google-play" >';
    $output .= '<a aria-label="link to google play" target="_blank" href="' . $conf['google_play'] . '"> <img src="/'. drupal_get_path('module', 'rp_social_networks') .'/img/google_play.png"> </a>';
    $output .= '</div>';
    $output .= '<div class="apple-store" >';
    $output .= '<a aria-label="link to apple store" target="_blank" href="' . $conf['apple_store'] . '"> <img src="/'. drupal_get_path('module', 'rp_social_networks') .'/img/app_store.png"> </a>';
    $output .= '</div>';
    $output .= '</div>';
    $output .= '</div>';


  if(isset($conf['api'])){
        $content = new stdClass();
        return $content;
    }


    $block = new stdClass();
    $block->title = '';
    $block->content = $output;

    return $block;

}

function rp_plugins_download_app_content_type_edit_form($form, &$form_state) {
    form_load_include($form_state, 'inc', 'file', 'file.field');
    form_load_include($form_state, 'inc', 'rp_plugins','plugins/content_types/download_app');

    unset($form['override_title']);
    unset($form['override_title_text']);
    unset($form['override_title_markup']);
    unset($form['override_title_heading']);

    $conf = $form_state['conf'];
    $form['image'] = array(
        '#type' => 'managed_file',
        '#upload_location' => 'public://panes/download_app/',
        '#title' => t('Download image'),
        '#default_value' => !empty($conf['image']) ? $conf['image'] : '',
    );

    $form['desc_to_download'] = array(
        '#type' => 'text_format',
        '#title' => t('Add description to download'),
        '#maxlength' => 512,
        '#description' => t('Add description to download'),
        '#default_value' => !empty($conf['desc_to_download']['value']) ? $conf['desc_to_download']['value'] : t('click to download'),
    );
    $form['google_play'] = array(
        '#type' => 'textfield',
        '#title' => t('Add link to Google play'),
        '#maxlength' => 512,
        '#description' => t('Add link to Google play'),
        '#default_value' => !empty($conf['google_play']) ? $conf['google_play'] : 'https://play.google.com/store',
    );
    $form['apple_store'] = array(
        '#type' => 'textfield',
        '#title' => t('Add link to Apple store'),
        '#maxlength' => 512,
        '#description' => t('Add link to Apple store'),
        '#default_value' => !empty($conf['apple_store']) ? $conf['apple_store'] : 'https://itunes.apple.com/',
    );
    return $form;

}

function rp_plugins_download_app_content_type_edit_form_submit($form, &$form_state){
     if($form_state['values']['image']){
        $file = file_load($form_state['values']['image']);
        // Change status to permanent.
        $file->status = FILE_STATUS_PERMANENT;
        // Save.
        file_save($file);
        // Record that the module (in this example, user module) is using the file.
        file_usage_add($file,  'rp_plugins' ,'app_down' , $file->fid);
    }
    $form_state['conf']['image'] = $form_state['values']['image'];
    $form_state['conf']['desc_to_download']['value'] = $form_state['values']['desc_to_download']['value'];
    $form_state['conf']['google_play'] = $form_state['values']['google_play'];
    $form_state['conf']['apple_store'] = $form_state['values']['apple_store'];


}