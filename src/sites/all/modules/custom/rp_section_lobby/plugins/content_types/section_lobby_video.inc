<?php
/**
 * Plugin info
 */
$plugin = array(
  'title' => t('Section Lobby Video'),
  'single' => TRUE,
  'category' => array(t('Section Lobby'), -9),
);

/**
 * Run-time rendering of the body of the block.
 */
function rp_section_lobby_section_lobby_video_content_type_render($subtype, $conf, $args, $context) {
  $output = '';
  $title = '';
  $tid = $conf['tid'];
  $args = array($tid);
  $content_api = new stdClass();
  $link = '';
  if($conf['link'] && $conf['link_title']){
    $link = '<a class="view-more" href="' . $conf['link'] . '">' . t($conf['link_title']) . '</a>';
  }
  if($conf['default_title']) {
    if($conf['tid_title']){
      $title = '<span class="black-span first">' . t('נדל"ן') .'</span><span>' . t('TV') .'</span><span class="black-span second">' . ' - ' . $conf['tid_title'] . '</span>';
    }
  }
  else $title = $conf['title'];  
  if($title)
    $output .= '<h2 class="pane-title">' . $title . $link . '</h2>';

  $content = array(
    'title' => $title,
    'link' => $conf['link'],
    'link_title' => $conf['link_title'],
  );
  $view = views_get_view('section_lobby', TRUE);
  $view->set_display('block_2');
  if(!empty($args))
    $view->set_arguments($args);
  $view->execute();
  foreach ($view->result as $key => $value) {
    $content_api->node_id[$key] = $value->nid;
  }
  //store_pane_content('section_lobby_video', $content, $conf['pid']);
  $output .= $view->preview();

  if(isset($conf['api'])){
        //$content_api->conf = $content;
        return $content_api;
    }

    $block = new stdClass();
  $block->title = '';
  $block->content = $output;

  return $block;
}

function rp_section_lobby_section_lobby_video_content_type_edit_form($form, &$form_state) {
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

function rp_section_lobby_section_lobby_video_content_type_edit_form_submit($form, &$form_state) {
  $form_state['conf']['pid'] = $form_state['pane']->pid;
  $form_state['conf']['default_title'] = $form_state['values']['default_title'];
  $form_state['conf']['title'] = $form_state['values']['title'];
  $form_state['conf']['link'] = $form_state['values']['link'];
  $form_state['conf']['link_title'] = $form_state['values']['link_title'];
  
  $display = $form_state['display'];
  $array = array_values($display->context);
  $tid = $array[0]->data->tid;
  $term = taxonomy_term_load($tid);
  $form_state['conf']['tid_title'] = $term->name;
  $form_state['conf']['tid'] = $tid;

}

