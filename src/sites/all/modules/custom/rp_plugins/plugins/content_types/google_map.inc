<?php
/**
 * Plugin info
 */
$plugin = array(
    'title' => t('Google Map'),
    'single' => TRUE,
    'category' => array(t('Contact Page'), -9),
);

/**
 * Run-time rendering of the body of the block.
 */
function rp_plugins_google_map_content_type_render($subtype, $conf, $args, $context) {
    drupal_add_js(drupal_get_path('module', 'rp_plugins') . '/js/map.js');


    $data = array();
    $data = $conf;
    $content = array(
        '#theme' => 'map_block',
        '#content' => $data,
    );
/*    drupal_add_js( '"https://maps.googleapis.com/maps/api/js?key='. $conf['api_key'] . '&callback=initMap" ',array(
        'type' => 'inline',
        'scope' => 'footer',
        'defer' => TRUE,
        //'src' => '"https://maps.googleapis.com/maps/api/js?key='. $conf['api_key'] . '&callback=initMap" ',
    ));
    //async defer src=*/

  if(isset($conf['api'])){
        $content = new stdClass();
        return $content;
    }


    $block = new stdClass();
    $block->title = '';
    $block->content = $content;

    return $block;

}


/**
 * form contact us
 */
function rp_plugins_google_map_content_type_edit_form($form, &$form_state){
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
    $form['place'] = array(
        '#type' => 'textfield',
        '#title' => t('place'),
        '#maxlength' => 512,
        '#default_value' => !empty($conf['place']) ? $conf['place'] : '',
    );
    $form['api_key'] = array(
        '#type' => 'textfield',
        '#title' => t('api_key'),
        '#maxlength' => 512,
        '#default_value' => !empty($conf['api_key']) ? $conf['api_key'] : '',
    );
    $form['zoom'] = array(
        '#type' => 'textfield',
        '#title' => t('zoom'),
        '#maxlength' => 512,
        '#default_value' => !empty($conf['zoom']) ? $conf['zoom'] : '',
    );
    $form['height'] = array(
        '#type' => 'textfield',
        '#title' => t('height'),
        '#maxlength' => 512,
        '#default_value' => !empty($conf['height']) ? $conf['height'] : '',
    );

    $form['html'] = array(
        '#type' => 'markup',
        '#markup' => '<div id="map"></div>',
    );
   /* $form['script'] = array(
        '#type' => 'markup',
        '#markup' => '<script async defer src="https://maps.googleapis.com/maps/api/js?key='. $conf['api_key'] . '&callback=initMap" type="text/javascript"></script>',
    );*/

    return $form;

}

function rp_plugins_google_map_content_type_edit_form_submit($form, &$form_state){
    $form_state['conf']['title'] = $form_state['values']['title'];
    $form_state['conf']['place'] = $form_state['values']['place'];
    $form_state['conf']['api_key'] = $form_state['values']['api_key'];
    $form_state['conf']['zoom'] = $form_state['values']['zoom'];
    $form_state['conf']['height'] = $form_state['values']['height'];
}