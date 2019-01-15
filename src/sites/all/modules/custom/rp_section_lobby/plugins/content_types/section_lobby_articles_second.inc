<?php
/**
 * Plugin info
 */
$plugin = array(
  'title' => t('Section Lobby Articles Second'),
  'single' => TRUE,
  'category' => array(t('Section Lobby'), -9),
);

/**
 * Run-time rendering of the body of the block.
 */
function rp_section_lobby_section_lobby_articles_second_content_type_render($subtype, $conf, $args, $context) {
  $output = '';
  $title = '';
  $tid = $conf['tid'];
  $args = array($tid);
  $nids = '';
  $offset =  4;
  $nids = variable_get('section_lobby_main_' . $tid, '');
  if(is_array($nids))
    $nids = implode('+', $nids);
  else if($nids == 'auto'){
    $offset += 3;
    $nids = '';
  }
  if($nids)
    $args[] = $nids;

  if($conf['default_title']) {
    if($conf['tid_title']){
      $title = t('כתבות אחרונות ב') . '<span class="term_name">' . $conf['tid_title'] . '</span>';
    }
  }
  else $title = $conf['title'];  
  if($title)
    $output .= '<h2 class="pane-title">' . $title . '</h2>';


  $view = views_get_view('section_lobby', TRUE);
  $view->set_display('block');
  if(!empty($args))
    $view->set_arguments($args);
  if($offset)
    $view->set_offset($offset);
  $view->set_items_per_page(10);
  $view->execute();
  $video_nids = variable_get('video_nids_' . $tid, array());
  $content = new stdClass();
  foreach ($view->result as $key => $value) {
    $index = $key + 1;
    $content->node_id[$index] = $value->nid;
    if($value->node_type == 'video'){
      $video_nids[] = $value->nid;
    }
  }
  //store_pane_content('section_lobby_articles_second', $content, $conf['pid']);
  $video_nids = array_unique($video_nids); 
  variable_set('video_nids_' . $tid , $video_nids);
  $output .= $view->preview();

  if(isset($conf['api'])){

        return $content;
    }

    $block = new stdClass();
  $block->title = '';
  $block->content = $output;

  return $block;
}

function rp_section_lobby_section_lobby_articles_second_content_type_edit_form($form, &$form_state) {
  unset($form['override_title']);
  unset($form['override_title_text']);
  unset($form['override_title_markup']);
  unset($form['override_title_heading']);
  $conf = $form_state['conf'];
  $form['default_title'] = array(
    '#type' => 'checkbox',
    '#title' => t('Use the section name as pane title'),
    '#default_value' => isset($conf['default_title']) ? $conf['default_title'] : '1',
  );
  $form['title'] = array(
    '#type' => 'textfield',
    '#title' => t('Custom Title'),
    '#maxlength' => 512,
    '#default_value' => !empty($conf['title']) ? $conf['title'] : '',
    '#states' => array(
      'visible' => array(
        ':input[name="default_title"]' => array('checked' => FALSE),
      ),
    ),
  );
  return $form;
}

function rp_section_lobby_section_lobby_articles_second_content_type_edit_form_submit($form, &$form_state) {
  $form_state['conf']['pid'] = $form_state['pane']->pid;
  $form_state['conf']['default_title'] = $form_state['values']['default_title'];
  $form_state['conf']['title'] = $form_state['values']['title'];
  
  $display = $form_state['display'];
  $array = array_values($display->context);
  $tid = $array[0]->data->tid;
  $term = taxonomy_term_load($tid);
  $form_state['conf']['tid_title'] = $term->name;
  $form_state['conf']['tid'] = $tid;

}

