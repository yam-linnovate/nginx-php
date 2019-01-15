<?php
/**
 * Plugin info
 */
$plugin = array(
  'title' => t('Video don\'t miss list'),
  'single' => TRUE,
  'category' => array(t('Video Page'), -9),
);

/**
 * Run-time rendering of the body of the block.
 */
function rp_plugins_video_dont_miss_list_content_type_render($subtype, $conf, $args, $context) {
  $args = array();
  $tid = '';
	$offset = variable_get('last_video_list', FALSE) ? 5 : 0;
	$nids = variable_get('video_list_main', '');
  if(is_array($nids))
    $nids = implode('+', $nids);
  else if($nids == 'auto'){
    $offset += 1;
    $nids = '';
  }
  
  $node = menu_get_object();
  if($node && isset($node->type) && in_array($node->type, array('article', 'video'))){
    $offset = 0;
    $nids = array($node->nid);
    $tid = $node->field_section[LANGUAGE_NONE][0]['tid'];
    $view = views_get_view_result('video', 'block');
    foreach ($view as $key => $result) {
      $nids[] = $result->nid;
    }
    $nids = implode('+', $nids);
  }
  $content = new stdClass();
  if($nids)
    $args[] = $nids;
  if($tid)
    $args[] = $tid;
  $view = views_get_view('video', TRUE);
  $view->set_display('block_3');
  if(!empty($args))
    $view->set_arguments($args);
  $view->set_offset($offset);
  $view->execute();
  foreach ($view->result as $key => $value) {
    $index = $key + 1;
    $content->node_id[$index] = $value->nid;
  }    
  //store_pane_content('video_dont_miss_list', $content, $conf['pid']);
  $output = '';
  if($conf['title'])
    $output .= '<h2 class="pane-title">' . t($conf['title']) . '</h2>';
  $output .= $view->preview();

    if(isset($conf['api'])){
        return $content;
    }


    $block = new stdClass();
  $block->title = '';
  $block->content = $output;

  return $block;
}

function rp_plugins_video_dont_miss_list_content_type_edit_form($form, &$form_state) {

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

function rp_plugins_video_dont_miss_list_content_type_edit_form_submit($form, &$form_state){
  $form_state['conf']['pid'] = $form_state['pane']->pid;
  $form_state['conf']['title'] = $form_state['values']['title'];    
}