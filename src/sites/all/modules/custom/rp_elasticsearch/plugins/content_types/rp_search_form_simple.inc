<?php



/**
 * Plugin info
 */
$plugin = array(
    'title' => t('Republish Search Form Simple'),
    'single' => TRUE,
    'category' => array(t('Miscellaneous'), -9),
);

/**
 * Run-time rendering of the body of the block.
 */
function rp_elasticsearch_rp_search_form_simple_content_type_render($subtype, $conf, $args, $context) {

  if(isset($conf['api'])){
        $content = new stdClass();
        return $content;
    }

    $block = new stdClass();
    $block->title = '';
    $form_search = drupal_get_form('rp_elasticsearch_rp_search_form_simple');
    $form_search = drupal_render($form_search);
    $block->content = '<div class="rp_search_form_simple_wrapper">'.$form_search.'</div>';

    return $block;

}

function rp_elasticsearch_rp_search_form_simple($form, &$form_state){
    $form = array();
    $form['key'] = array(
        '#title' => t('key'),
        '#attributes' => array('placeholder' => t('Search')),
        '#type' => 'textfield',
        '#size' => '17',
    );

    $form['submit'] = array(
        '#type' => 'submit',
        '#value' => t('search'),
        '#attributes' => array('class' => array('form_simple_submit')),
    );
    return $form;
}

function rp_elasticsearch_rp_search_form_simple_submit($form, &$form_state){
    $key = $form_state['input']['key'];
    drupal_goto('/search', array('query' => array('key' => $key)));

}