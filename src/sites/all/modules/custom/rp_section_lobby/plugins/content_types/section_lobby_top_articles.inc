<?php
/**
 * Plugin info
 */
$plugin = array(
  'title' => t('Section Lobby Top Articles'),
  'single' => TRUE,
  'category' => array(t('Section Lobby'), -9),
);

/**
 * Run-time rendering of the body of the block.
 */
function rp_section_lobby_section_lobby_top_articles_content_type_render($subtype, $conf, $args, $context) {
    $output = '';
    $tid = $conf['tid'];
    $content = new stdClass();
    $video_nids = array();
    if($conf['auto']) {
      $view = views_get_view_result('section_lobby', 'block_1', $tid);
      $large_id = isset($view[0]->nid) ? $view[0]->nid : 0;
      $left_id1 = isset($view[1]->nid) ? $view[1]->nid : 0;
      $left_id2 = isset($view[2]->nid) ? $view[2]->nid : 0;
    }
    else {
      $large_id = $conf['large_id'];
      $left_id1 = $conf['left_id1'];
      $left_id2 = $conf['left_id2'];
    }
    $large = '';
    if($large_id){
      $node = node_load($large_id);
      if($node->type == 'video')
        $video_nids[] = $large_id;
      $large .= section_lobby_top_articles_render_item($node, '700x400');
    }

    $left = '';
    if($left_id1){
      $node = node_load($left_id1);
      if($node->type == 'video')
        $video_nids[] = $left_id1;
      $left .= section_lobby_top_articles_render_item($node, '700x400');
    }
    if($left_id2){
      $node = node_load($left_id2);
      if($node->type == 'video')
        $video_nids[] = $left_id2;
      $left .= section_lobby_top_articles_render_item($node, '700x400');
    }
    /*store_pane_content('section_lobby_top_articles',
      array(
        'nid_1' => $large_id,
        'nid_2' => $left_id1,
        'nid_3' => $left_id2,
      ),
      $conf['pid']
    );*/
    variable_set('video_nids_' . $tid, $video_nids);
    $output = '<div class="main-large">' . $large . '</div><div class="main-left">' . $left . '</div>';
    $content->node_id = array(
        'nid_1' => $large_id,
        'nid_2' => $left_id1,
        'nid_3' => $left_id2,
    );
    if(isset($conf['api'])){
        return $content;
    }

    $block = new stdClass();
    $block->title = '';
    $block->content = $output;

    return $block;
}

function rp_section_lobby_section_lobby_top_articles_content_type_edit_form($form, &$form_state) {

  unset($form['override_title']);
  unset($form['override_title_text']);
  unset($form['override_title_markup']);
  unset($form['override_title_heading']);
  
  $conf = $form_state['conf'];
  $form['auto'] = array(
    '#type' => 'checkbox',
    '#title' => t('Automatic Load last articles by the page section'),
    '#default_value' => !empty($conf['auto']) ? $conf['auto'] : '0',
  );
  $form['large_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Large article ID'),
    '#maxlength' => 512,
    '#description' => t('A valid article id.'),
    '#autocomplete_path' => 'ctools/autocomplete/node',
    '#default_value' => !empty($conf['large_id']) ? $conf['large_id'] : '0',
    '#states' => array(
      'invisible' => array(
        ':input[name="auto"]' => array('checked' => TRUE),
      ),
    ),
  );

  $form['left_id1'] = array(
    '#type' => 'textfield',
    '#title' => t('Left article ID 1'),
    '#maxlength' => 512,
    '#description' => t('A valid article id.'),
    '#autocomplete_path' => 'ctools/autocomplete/node',
    '#default_value' => !empty($conf['left_id1']) ? $conf['left_id1'] : '0',
    '#states' => array(
      'invisible' => array(
        ':input[name="auto"]' => array('checked' => TRUE),
      ),
    ),
  );

  $form['left_id2'] = array(
    '#type' => 'textfield',
    '#title' => t('Left article ID 2'),
    '#maxlength' => 512,
    '#description' => t('A valid article id.'),
    '#autocomplete_path' => 'ctools/autocomplete/node',
    '#default_value' => !empty($conf['left_id2']) ? $conf['left_id2'] : '0',
    '#states' => array(
      'invisible' => array(
        ':input[name="auto"]' => array('checked' => TRUE),
      ),
    ),
  );
  return $form;
}

function rp_section_lobby_section_lobby_top_articles_content_type_edit_form_submit($form, &$form_state){
    $form_state['conf']['pid'] = $form_state['pane']->pid;
    $form_state['conf']['auto'] = $form_state['values']['auto'];    
    $form_state['conf']['large_id'] = $form_state['values']['large_id'];    
    $form_state['conf']['left_id1'] = $form_state['values']['left_id1'];    
    $form_state['conf']['left_id2'] = $form_state['values']['left_id2'];
    $display = $form_state['display'];
    $array = array_values($display->context);
    $tid = $array[0]->data->tid;
    $form_state['conf']['tid'] = $tid;
    if($form_state['conf']['auto']){
      variable_set('section_lobby_main_' . $tid , 'auto');
    }
    else variable_set('section_lobby_main_' . $tid, array($form_state['conf']['large_id'], $form_state['conf']['left_id1'], $form_state['conf']['left_id2']));
}

function rp_section_lobby_section_lobby_top_articles_content_type_edit_form_validate(&$form, &$form_state) {
  foreach (array('large_id', 'left_id1', 'left_id2') as $key) {
    $node = rp_section_lobby_section_lobby_top_articles_autocomplete($form_state['values'][$key]);
    if ($node) {
      $form_state['values'][$key] = $node->nid;
    }
    if ($form_state['values'][$key] == '0')
      $form_state['values'][$key] = 0; 
    if ((($node->type != 'video'  &&  $node->type != 'article')|| !node_access('view', $node)) && $form_state['values'][$key] != '0') {
      form_error($form[$key], t('Invalid node'));
    }
  }      
}
function rp_section_lobby_section_lobby_top_articles_autocomplete($nid)  {
  $preg_matches = array();
  $match = preg_match('/\[id: (\d+)\]/', $nid, $preg_matches);
  if (!$match) {
    $match = preg_match('/^id: (\d+)/', $nid, $preg_matches);
  }

  if ($match) {
    $nid = $preg_matches[1];
  }
  if (is_numeric($nid)) {
    $node = db_query('SELECT nid, status, type FROM {node} WHERE nid = :nid', array(':nid' => $nid))->fetchObject();
  }
  else {
    $node = db_query('SELECT nid, status, type FROM {node} WHERE LOWER(title) = LOWER(:title)', array(':title' => $nid))->fetchObject();
  }
  return $node;
}

function section_lobby_top_articles_render_item($node, $image_style) {
  $link_to_node = drupal_get_path_alias('node/' . $node->nid);
  $output = '';
  $output = '<div class="img-wrapper">';
  $field_images = field_collection_item_load($node->field_images[LANGUAGE_NONE][0]['value']);
  if($field_images){
    $output .= '<div class="img"><a href="' . $link_to_node . '">';
    $output .= theme('image_style', array('style_name' => $image_style, 'alt' => $field_images->field_image['und'][0]['alt'], 'path' => $field_images->field_image[LANGUAGE_NONE][0]['uri']));
    $output .= '</a></div>';
    $output .= '<div class="' . $node->type . ' icon"><span class="icon"></span></div>';
  }
  $writer = taxonomy_term_load($node->field_writer[LANGUAGE_NONE][0]['tid']);
  $writer_output ='<div class="writer-wrapper"><a href="/search?writer=' . $writer->tid . '">' . $writer->name . '</a></div>';
  $output .= '<div class="content-wrapper"><a href="' . $link_to_node . '"><div class="title">' . $node->field_front_page_title[LANGUAGE_NONE][0]['value'] . '</div></a>' . $writer_output . '</div><div class="lobby-view-more"><a href="' . $link_to_node . '">< קרא עוד</a></div>' ;
  $output .= '</div>';
  return $output;
  return $node->nid;
}