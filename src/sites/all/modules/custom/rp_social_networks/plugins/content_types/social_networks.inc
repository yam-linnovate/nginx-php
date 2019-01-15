<?php
/**
 * Plugin info
 */
$plugin = array(
  'title' => t('Social networks '),
  'single' => TRUE,
  'category' => array(t('footer'), -10),
);

function rp_social_networks_social_networks_content_type_render($subtype, $conf, $args, $context) {

    drupal_add_css(drupal_get_path('module', 'rp_social_networks') . '/css/rp_social_networks.css');

    $output = '';
  if($conf['title']){
    $output .= '<h2 class="pane-title">' . t($conf['title']). '</h2>';
  }
  $output .= '<div class="social-networks" >';
  $output .= '<div class="linkdin" >';
  $output .= '<a aria-label="link to linkdin" target="_blank" href="' . $conf['linkdin'] . '"> <img src="/'. drupal_get_path('module', 'rp_social_networks') .'/img/linkdin.png" width="17" height="16"> </a>';
  $output .= '</div>';
  $output .= '<div class="facebook" >';
  $output .= '<a aria-label="link to facebook" target="_blank" href="' . $conf['facebook'] . '"> <img src="/'. drupal_get_path('module', 'rp_social_networks') .'/img/facebook.png" width="11" height="19"> </a>';
  $output .= '</div>';
  $output .= '<div class="twitter" >';
  $output .= '<a aria-label="link to twitter" target="_blank" href="' . $conf['twitter'] . '"> <img src="/'. drupal_get_path('module', 'rp_social_networks') .'/img/twitter.png" width="20" height="16"> </a>';
  $output .= '</div>';
  $output .= '</div>';
  $output .= '<div class="store-networks" >';
  $output .= '<div class="desc-to-download" >';
  $output .= '<p>'. $conf['desc_to_download']['value'] . '</p>';
  $output .= '</div>';
  $output .= '<div class="wrap-btn-store" >';
  $output .= '<div class="google-play" >';
  $output .= '<a aria-label="link to google play" target="_blank" href="' . $conf['google_play'] . '"> <img src="/'. drupal_get_path('module', 'rp_social_networks') .'/img/google_play.png" width="136" height="47"> </a>';
  $output .= '</div>';
  $output .= '<div class="apple-store" >';
  $output .= '<a aria-label="link to apple store" target="_blank" href="' . $conf['apple_store'] . '"> <img src="/'. drupal_get_path('module', 'rp_social_networks') .'/img/app_store.png" width="139" height="47"> </a>';
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

function rp_social_networks_social_networks_content_type_edit_form($form, &$form_state) {

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
  $form['linkdin'] = array(
    '#type' => 'textfield',
    '#title' => t('Add link to Linkdin'),
    '#maxlength' => 512,
    '#description' => t('Add link to Linkdin'),
    '#default_value' => !empty($conf['linkdin']) ? $conf['linkdin'] : 'https://www.linkedin.com/',
  );
  $form['facebook'] = array(
    '#type' => 'textfield',
    '#title' => t('Add link to Facebook'),
    '#maxlength' => 512,
    '#description' => t('Add link to Facebook'),
    '#default_value' => !empty($conf['facebook']) ? $conf['facebook'] : 'https://www.facebook.com/',
  );
  $form['twitter'] = array(
    '#type' => 'textfield',
    '#title' => t('Add link to Twitter'),
    '#maxlength' => 512,
    '#description' => t('Add link to Twitter'),
    '#default_value' => !empty($conf['twitter']) ? $conf['twitter'] : 'https://twitter.com/',
  );
  $form['google_plus'] = array(
    '#type' => 'textfield',
    '#title' => t('Add link to Google plus'),
    '#maxlength' => 512,
    '#description' => t('Add link to Google plus'),
    '#default_value' => !empty($conf['google_plus']) ? $conf['google_plus'] : 'https://plus.google.com/',
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
function rp_social_networks_social_networks_content_type_edit_form_submit($form, &$form_state) {
  $list = array();
  $form_state['conf']['title'] = $form_state['values']['title'];
  $form_state['conf']['linkdin'] = $form_state['values']['linkdin'];
  $form_state['conf']['facebook'] = $form_state['values']['facebook'];
  $form_state['conf']['twitter'] = $form_state['values']['twitter'];
  $form_state['conf']['google_plus'] = $form_state['values']['google_plus'];
  $form_state['conf']['desc_to_download']['value'] = $form_state['values']['desc_to_download']['value'];
  $form_state['conf']['google_play'] = $form_state['values']['google_play'];
  $form_state['conf']['apple_store'] = $form_state['values']['apple_store'];
}
