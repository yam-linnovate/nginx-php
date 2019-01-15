<?php
/**
 * Plugin info
 */
$plugin = array(
  'title' => t('Home Page Opinions Mobile'),
  'single' => TRUE,
  'category' => array(t('Front Page'), -9),
);

/**
 * Run-time rendering of the body of the block.
 */
function rp_plugins_hp_opinions_mobile_content_type_render($subtype, $conf, $args, $context) {
  $output = '';
  $link = '';
    $content = new stdClass();
  if($conf['link'] && $conf['link_title']){
    $link = '<a class="view-more" href="' . $conf['link'] . '"> ' . t($conf['link_title']) . ' </a>';
  }
  $output .= '<h2 class="pane-title">
  <a class="view-more" href="' . $conf['link'] . '"> </a>
  </h2>';

      $content->title = $conf['title'];
      $content->link = $conf['link'];
      $content->link_title = $conf['link_title'];

  $view = views_get_view('opinions', TRUE);
  $view->set_display('block_4');
  $view->execute();
  foreach ($view->result as $key => $value) {
    $index = $key + 1;
    $content->node_id[$index] = $value->nid;
  }
  //store_pane_content('hp_opinions_mobile', $content, $conf['pid']);
  $output .= $view->preview();
  $output .= '<div class="pane-bottom view-more-bottom">' . $link . '</div>';


    if(isset($conf['api'])){

      return $content;
  }

  $block = new stdClass();
  $block->title = '';
  $block->content = $output;

  return $block;
}

function rp_plugins_hp_opinions_mobile_content_type_edit_form($form, &$form_state) {

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
  return $form;
}

function rp_plugins_hp_opinions_mobile_content_type_edit_form_submit($form, &$form_state){
    $form_state['conf']['pid'] = $form_state['pane']->pid;
    $form_state['conf']['title'] = $form_state['values']['title'];    
    $form_state['conf']['link'] = $form_state['values']['link'];    
    $form_state['conf']['link_title'] = $form_state['values']['link_title'];    
}