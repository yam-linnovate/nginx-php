<?php

$plugin = array(
  'title' => t('Special Project'),
  'single' => TRUE,
  'category' => array(t('Front Page'), -9),
);




function rp_plugins_special_project_content_type_render($subtype, $conf, $args, $context) {
  drupal_add_js(drupal_get_path('module', 'rp_plugins') . '/js/special_projects.js');
  $output = '';
  $content = new stdClass();
  if($conf['title'])
    $output .= '<h2 class="special-project-title">'. t($conf['title']) . '</h2>';

  $output .= '<div class="special-projects-wrapper">';
  $view = views_get_view('special_projects');
  $view->set_display('page');
  $view->set_arguments(array($conf['subqueue']));
  $view->execute();

    foreach ($view->result as $key => $value) {
        $index = $key + 1;
        $content->node_id[$index] = $value->nid;
    }
    //store_pane_content('special_project', $content, $conf['pid']);

  if (!empty($view->result)) {
    $output .= $view->preview();
  }else{
    $output .= t("no result Special Project");
  }
  $output .= '</div>';


  if(isset($conf['api'])){
        return $content;
    }


    $block = new stdClass();
  $block->title = '';
  $block->content = $output;
  return $block;

}


function rp_plugins_special_project_content_type_edit_form($form, &$form_state) {

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
  $queues = nodequeue_load_queues_by_type('node_special_projects');
  foreach ($queues as $sqid => $subqueue) {
    if (!empty($subqueue->title)) {
      $nodequeues[$subqueue->name] = $subqueue->title;
    }
  }
  $form['subqueue'] = array(
    '#type' => 'select',
    '#title' => t('choose gallery'),
    '#description' => t('choose gallery do you make on node queue'),
    '#options' => $nodequeues,
    '#default_value' => !empty($conf['subqueue']) ? $conf['subqueue'] : '',
  );
  return $form;
}

function rp_plugins_special_project_content_type_edit_form_submit($form, &$form_state){
  $form_state['conf']['pid'] = $form_state['pane']->pid;
  $form_state['conf']['title'] = $form_state['values']['title'];
  $form_state['conf']['subqueue'] = $form_state['values']['subqueue'];

}