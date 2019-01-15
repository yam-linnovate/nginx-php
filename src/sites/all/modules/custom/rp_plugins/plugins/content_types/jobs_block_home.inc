<?php
/**
 * Plugin info
 */
$plugin = array(
    'title' => t('Block jobs at home page'),
    'single' => TRUE,
    'category' => array(t('Front Page'), -9),
);

function rp_plugins_jobs_block_home_content_type_render($subtype, $conf, $args, $context) {
    $content_api = new stdClass();
    $data = $conf;
    $view = views_get_view('jobs', TRUE);
    $view->set_display('block_2');
    $view->execute();
    $detect = mobile_detect_get_object();
    $is_mobile = $detect->isMobile();
    $is_tablet = $detect->isTablet();

    $data['result'] = $view->result;
    $count = count($data['result']);

    $content = array(
        '#theme' => 'jobs_block',
        '#content' => $data,
        '#count' => $count,
    );

    if(!$is_mobile && !$is_tablet) {
        unset($content['#content']['mobile_link_title']);
    }

    if(isset($conf['api'])){
        foreach ($content['#content']['result'] as $item => $nid){
            $index = $item + 1;
            $content_api->node_id[$index] = $content['#content']['result'][$item]->nid;
        }
        return $content_api;
    }


    $block = new stdClass();
    $block->title = '';
    $block->content = $content;
    return $block;

}

function rp_plugins_jobs_block_home_content_type_edit_form($form, &$form_state)
{
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
    $form['link'] = array(
        '#type' => 'textfield',
        '#title' => t('Link to view more'),
        '#maxlength' => 512,
        '#default_value' => !empty($conf['link']) ? $conf['link'] : '',
    );
    $form['link_title'] = array(
        '#type' => 'textfield',
        '#title' => t('Link title'),
        '#maxlength' => 512,
        '#default_value' => !empty($conf['link_title']) ? $conf['link_title'] : '',
    );
    $form['mobile_link_title'] = array(
        '#type' => 'textfield',
        '#title' => t('Mobile link title'),
        '#maxlength' => 512,
        '#default_value' => !empty($conf['mobile_link_title']) ? $conf['mobile_link_title'] : '',
    );
    return $form;
}


function rp_plugins_jobs_block_home_content_type_edit_form_submit($form, &$form_state){
    $form_state['conf']['pid'] = $form_state['pane']->pid;
    $form_state['conf']['title'] = $form_state['values']['title'];
    $form_state['conf']['link'] = $form_state['values']['link'];
    $form_state['conf']['link_title'] = $form_state['values']['link_title'];
    $form_state['conf']['mobile_link_title'] = $form_state['values']['mobile_link_title'];
}