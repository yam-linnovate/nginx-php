<?php
/**
 * Plugin info
 */
$plugin = array(
    'title' => t('Contact us'),
    'single' => TRUE,
    'category' => array(t('Contact Page'), -9),
);

/**
 * Run-time rendering of the body of the block.
 */
function rp_plugins_contact_us_content_type_render($subtype, $conf, $args, $context) {
    $output = '';
    $data = $conf;
    $content = array(
        '#theme' => 'contact_us_block',
        '#content' => $data,
    );


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
function rp_plugins_contact_us_content_type_edit_form($form, &$form_state){
    unset($form['override_title']);
    unset($form['override_title_text']);
    unset($form['override_title_markup']);
    unset($form['override_title_heading']);

    $conf = $form_state['conf'];
    $form['title'] = array(
        '#type' => 'text_format',
        '#title' => t('Title'),
        '#default_value' => !empty($conf['title']['value']) ? $conf['title']['value'] : '',
        '#format' => 'full_html',
    );
    $form['call'] = array(
        '#type' => 'text_format',
        '#title' => t('call'),
        '#default_value' => !empty($conf['call']['value']) ? $conf['call']['value'] : '',
        '#format' => 'full_html',
    );
    $form['fax'] = array(
        '#type' => 'text_format',
        '#title' => t('Fax'),
        '#default_value' => !empty($conf['fax']['value']) ? $conf['fax']['value'] : '',
        '#format' => 'full_html'
    );
    $form['email'] = array(
        '#type' => 'text_format',
        '#title' => t('email'),
        '#default_value' => !empty($conf['email']['value']) ? $conf['email']['value'] : '',
        '#format' => 'full_html'
    );
    $form['address'] = array(
        '#type' => 'text_format',
        '#title' => t('address'),
        '#default_value' => !empty($conf['address']['value']) ? $conf['address']['value'] : '',
        '#format' => 'full_html'
    );

    return $form;

}

function rp_plugins_contact_us_content_type_edit_form_submit($form, &$form_state){
    $form_state['conf']['title'] = $form_state['values']['title'];
    $form_state['conf']['call'] = $form_state['values']['call'];
    $form_state['conf']['fax'] = $form_state['values']['fax'];
    $form_state['conf']['email'] = $form_state['values']['email'];
    $form_state['conf']['address'] = $form_state['values']['address'];
}