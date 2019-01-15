<?php
/**
 * Plugin info
 */
$plugin = array(
  'title' => t('Upcoming events newsflash'),
  'single' => TRUE,
  'category' => array(t('Front Page'), -9),
);

/**
 * Run-time rendering of the body of the block.
 */
function rp_plugins_upcoming_events_flash_content_type_render($subtype, $conf, $args, $context) {
  $output = '';
    $content =  new stdClass();
  if($conf['title']){
    $output .= '<h2 class="pane-title">' . t($conf['title']) . '</h2>';
  }
  $view = views_get_view('events', TRUE);
  $view->set_display('block_1');
  $view->execute();
  foreach ($view->result as $key => $value) {
    $index = $key + 1;
    $content->node_id[$index] = $value->nid;
  }    
  //store_pane_content('upcoming_events_flash', $content, $conf['pid']);
  $output .= '<div class="upcoming-events-content">';
  $output .= $view->preview();

  if(isset($conf['api'])){
        return $content;
    }

    $block = new stdClass();
  $block->title = '';
  $block->content = $output . '</div>';

  return $block;
}

function rp_plugins_upcoming_events_flash_content_type_edit_form($form, &$form_state) {

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

function rp_plugins_upcoming_events_flash_content_type_edit_form_submit($form, &$form_state){
    $form_state['conf']['pid'] = $form_state['pane']->pid;
    $form_state['conf']['title'] = $form_state['values']['title'];  
}