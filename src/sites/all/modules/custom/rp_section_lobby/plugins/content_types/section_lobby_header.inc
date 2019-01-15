<?php
/**
 * Plugin info
 */
$plugin = array(
  'title' => t('Section Lobby Header'),
  'single' => TRUE,
  'category' => array(t('Section Lobby'), -9),
);

/**
 * Run-time rendering of the body of the block.
 */
function rp_section_lobby_section_lobby_header_content_type_render($subtype, $conf, $args, $context) {
  $output = '';
  $title = '';
  $content = new stdClass();
  if($conf['default_title']) {
    if($conf['tid_title']){
      $title = $conf['tid_title'];
    }
  }
  else $title = $conf['title'];
  /*store_pane_content('section_lobby_header',
    array(
      'title' => $title, 
    ),
    $conf['pid']
  );*/
  $output .= '<h1 class="title">' . $title . '</h1>';

  if(isset($conf['api'])){
        return $content;
    }

    $block = new stdClass();
  $block->title = '';
  $block->content = $output;

  return $block;
}

function rp_section_lobby_section_lobby_header_content_type_edit_form($form, &$form_state) {
  unset($form['override_title']);
  unset($form['override_title_text']);
  unset($form['override_title_markup']);
  unset($form['override_title_heading']);
  $conf = $form_state['conf'];
  $form['default_title'] = array(
    '#type' => 'checkbox',
    '#title' => t('Use the section name as page title'),
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

function rp_section_lobby_section_lobby_header_content_type_edit_form_submit($form, &$form_state) {
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

