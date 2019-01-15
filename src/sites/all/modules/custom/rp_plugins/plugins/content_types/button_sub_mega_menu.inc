<?php
/**
 * Plugin info
 */
$plugin = array(
    'title' => t('Button on sub mega menu'),
    'single' => TRUE,
    'category' => array(t('Header'), -9),
);

/**
 * Run-time rendering of the body of the block.
 */
function rp_plugins_button_sub_mega_menu_content_type_render($subtype, $conf, $args, $context){
    $output = '';

    $output .= '<div class="button" >';
    $output .= '<a href="' . $conf['link'] .'">' . $conf['title'] . '</a>';
    $output .= '</div>';
    $output .= '<div class="social-networks-sub-mega-menu" >';
    $output .= '<div class="email" >';
    $output .= '<a aria-label="link to email" href="/' . $conf['email'] . '"> <img src="/'. drupal_get_path('module', 'rp_plugins') .'/img/email.png"> </a>';
    $output .= '</div>';
    $output .= '<div class="facebook" >';
    $output .= '<a aria-label="link to facebook" target="_blank" href="' . $conf['facebook'] . '"> <img src="/'. drupal_get_path('module', 'rp_plugins') .'/img/facebook.png"> </a>';
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

function rp_plugins_button_sub_mega_menu_content_type_edit_form($form, &$form_state){
    $conf = $form_state['conf'];
    $form['title'] = array(
        '#type' => 'textfield',
        '#title' => t('Title'),
        '#maxlength' => 512,
        '#default_value' => !empty($conf['title']) ? $conf['title'] : '',
    );
    $form['link'] = array(
        '#type' => 'textfield',
        '#title' => t('Link'),
        '#maxlength' => 512,
        '#default_value' => !empty($conf['link']) ? $conf['link'] : '',
    );
    $form['facebook'] = array(
        '#type' => 'textfield',
        '#title' => t('Add link to Facebook'),
        '#maxlength' => 512,
        '#description' => t('Add link to Facebook'),
        '#default_value' => !empty($conf['facebook']) ? $conf['facebook'] : 'https://www.facebook.com/',
    );
    $form['email'] = array(
        '#type' => 'textfield',
        '#title' => t('Add contact us url '),
        '#maxlength' => 512,
        '#description' => t('Add contact us url'),
        '#default_value' => !empty($conf['email']) ? $conf['email'] : '',
    );

    return $form;

}

function rp_plugins_button_sub_mega_menu_content_type_edit_form_submit($form, &$form_state) {
  $form_state['conf']['title'] = $form_state['values']['title'];
  $form_state['conf']['link'] = $form_state['values']['link'];
  $form_state['conf']['facebook'] = $form_state['values']['facebook'];
  $form_state['conf']['email'] = $form_state['values']['email'];
}