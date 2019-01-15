<?php
/**
 * Plugin info
 */
$plugin = array(
    'title' => t('jobs company'),
    'single' => TRUE,
    'category' => array(t('jobs Page'), -9),
);

/**
 * Run-time rendering of the body of the block.
 */
function rp_plugins_jobs_company_content_type_render($subtype, $conf, $args, $context) {
    drupal_add_js(drupal_get_path('module', 'rp_plugins') . '/js/jobs_company.js');
    $output = '';
    $data = $conf;
    $detect = mobile_detect_get_object();
    $is_mobile = $detect->isMobile();
    $is_tablet = $detect->isTablet();
    if($is_mobile || $is_tablet) {
        $mobile = 'mobile';
    }

    if(!$is_mobile && !$is_tablet) {
        if ($conf['view_all_text']){
            $view_all_text = $conf['view_all_text'];
        }
        if ($conf['view_all_link']){
            $view_all_link = '<div class="view-all-container"><a class="view-all-button" href="' . $conf['view_all_link'] . '">'. $view_all_text . '</a></div>';
        }
    } else {
        $view_all_link = '';
    }

    foreach ($conf['category'] as $item => $value){
        if ($value > 0 ){
            $data['term'][$item] = taxonomy_term_load($value);
        }
    }


    if(!$is_mobile && !$is_tablet) {
        $content = array(
            '#theme' => 'jobs_company',
            '#view_all' => $view_all_link,
            '#content' => $data,
        );
    } else {
        $content = array(
            '#theme' => 'jobs_company',
            '#view_all' => $view_all_link,
            '#content' => $data,
            '#mobile' => $mobile,
        );
    }

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
function rp_plugins_jobs_company_content_type_edit_form($form, &$form_state){
    unset($form['override_title']);
    unset($form['override_title_text']);
    unset($form['override_title_markup']);
    unset($form['override_title_heading']);

    $conf = $form_state['conf'];
    $form['view_all_text'] = array(
        '#type' => 'textfield',
        '#title' => t('view all link text'),
        '#maxlength' => 512,
        '#default_value' => !empty($conf['view_all_text']) ? $conf['view_all_text'] : '',
    );
    $form['view_all_link'] = array(
        '#type' => 'textfield',
        '#title' => t('view all link value (example: /xxx/abc)'),
        '#maxlength' => 512,
        '#default_value' => !empty($conf['view_all_link']) ? $conf['view_all_link'] : '',
    );
    $form['title'] = array(
        '#type' => 'textfield',
        '#title' => t('Title'),
        '#maxlength' => 512,
        '#default_value' => !empty($conf['title']) ? $conf['title'] : '',
    );
    if(empty($form_state['contexts'])){

        $vocabulary = taxonomy_vocabulary_machine_name_load('company');
        $terms = entity_load('taxonomy_term', FALSE, array('vid' => $vocabulary->vid));
        $op = array();
        $op[0] = t('- select -');
        foreach ($terms as $key => $value){
            $op[$key] = $value->name;
        }
        $form['category'] = array(
            '#type' => 'fieldset',
            '#prefix' => '<div class="sortable">hi',
            '#suffix' => '</div>',
        );
        for ($i=0; $i<2; $i++){
            $form['category']['tid-' . $i] = array(
                '#type' => 'select',
                '#title' => t('Choose company'),
                '#options' => $op,
                '#default_value' => !empty($conf['category'][$i]) ? $conf['category'][$i] : $op[0],
            );
        }
    }

    return $form;

}

function rp_plugins_jobs_company_content_type_edit_form_submit($form, &$form_state){
    $form_state['conf']['view_all_text'] = $form_state['values']['view_all_text'];
    $form_state['conf']['view_all_link'] = $form_state['values']['view_all_link'];
    $form_state['conf']['title'] = $form_state['values']['title'];
    for ($i=0; $i<2; $i++){
        $form_state['conf']['category'][$i] = $form_state['values']['tid-' . $i];
    }
}