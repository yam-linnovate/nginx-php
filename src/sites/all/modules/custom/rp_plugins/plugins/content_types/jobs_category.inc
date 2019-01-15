<?php
/**
 * Plugin info
 */
$plugin = array(
    'title' => t('jobs category'),
    'single' => TRUE,
    'category' => array(t('jobs Page'), -9),
);

/**
 * Run-time rendering of the body of the block.
 */
function rp_plugins_jobs_category_content_type_render($subtype, $conf, $args, $context) {
    $output = '';
    $data = $conf;
    $view = views_get_view('jobs', TRUE);
    if (!empty($args)){
        $term = taxonomy_term_load($args[0]);
        switch ($term->vocabulary_machine_name) {
            case 'company':
                $data['term'] = 'company';
                break;
            case 'jobs_category':
                $data['term'] = 'jobs_category';
                break;
        }
        $view->set_display('block');
        $view->set_arguments($args);
        $data['is_page_term'] = FALSE;
    }else{
        $view->set_display('block');
        $view->set_arguments(array($data['category']));
        $data['term'] = 'jobs_category';
        $data['is_page_term'] = TRUE;
    }
    $view->execute();

    $data['result'] = $view->result;

    $content = array(
        '#theme' => 'jobs_category',
        '#content' => $data,
    );

    $content_api = new stdClass();
    if(isset($conf['api'])){
        return $content_api;
    }

    $block = new stdClass();
    $block->title = '';
    $block->content = $content;

    return $block;

}


/**
 * form contact us
 */
function rp_plugins_jobs_category_content_type_edit_form($form, &$form_state){
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
    if(empty($form_state['contexts'])){

    $vocabulary = taxonomy_vocabulary_machine_name_load('jobs_category');
    $terms = entity_load('taxonomy_term', FALSE, array('vid' => $vocabulary->vid));
    $op = array();
    foreach ($terms as $key => $value){
        $op[$key] = $value->name;
    }

        $form['category'] = array(
            '#type' => 'select',
            '#title' => t('Choose category'),
            '#description' => t('if this page is term it Will ignore from choosing'),
            '#options' => $op,
            '#default_value' => !empty($conf['category']) ? $conf['category'] : '',
        );
    }

    return $form;

}

function rp_plugins_jobs_category_content_type_edit_form_submit($form, &$form_state){
    $form_state['conf']['title'] = $form_state['values']['title'];
    $form_state['conf']['category'] = $form_state['values']['category'];
}