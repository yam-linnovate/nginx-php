<?php
/**
 * Plugin info
 */
$plugin = array(
    'title' => t('Hp Image Block'),
    'single' => TRUE,
    'category' => array(t('Front Page'), -9),
);

/**
 * Run-time rendering of the body of the block.
 */
function rp_plugins_hp_image_block_content_type_render($subtype, $conf, $args, $context) {
    drupal_add_js(drupal_get_path('module', 'rp_plugins') . '/js/hp_image_block.js');
    $content = new stdClass();
    $output = '';
    if($conf['title']){
        $output .= '<h2 class="pane-title">' . t($conf['title']) . '</h2>';
    }
    $output_block = views_embed_view('hp_image', 'block');
    //store_pane_content('hp_image', array('nid_1'=>$nid));
    $output .= $output_block;


  if(isset($conf['api'])){
        return $content;
    }


    $block = new stdClass();
    $block->title = '';
    $block->content = $output;

    return $block;
}

function rp_plugins_hp_image_block_content_type_edit_form($form, &$form_state) {

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
    return $form;
}

function rp_plugins_hp_image_block_content_type_edit_form_submit($form, &$form_state){
    $form_state['conf']['pid'] = $form_state['pane']->pid;
    $form_state['conf']['title'] = $form_state['values']['title'];
}