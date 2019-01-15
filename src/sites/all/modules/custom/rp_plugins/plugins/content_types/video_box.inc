<?php
/**
 * Plugin info
 */
$plugin = array(
  'title' => t('Video Box'),
  'single' => TRUE,
  'category' => array(t('Front Page'), -9),
);

/**
 * Run-time rendering of the body of the block.
 */
function rp_plugins_video_box_content_type_render($subtype, $conf, $args, $context) {
    $output = '';
    if($conf['title'])
      $output .= '<h2 class="pane-title">' . t($conf['title']) . '</h2>';
    
    $article_id = $conf['article_id'];
    if($article_id){
      $article_id_node = node_load($article_id);
      if($article_id_node) {
        $link_to_node = drupal_get_path_alias('node/' . $article_id_node->nid);
        $image = '';
        if (is_object($article_id_node)){
          $field_image = field_collection_item_load($article_id_node->field_images[LANGUAGE_NONE][0]['value']);
        }
        if(isset($field_image)){
          $image = '<a href="' . $link_to_node . '">';
          $field_image = $field_image->view('hp_small_image');
          $image .= render($field_image);
          $image .= '<div class="video icon"><span class="icon"></span></div></a>';
        }
        $output .= $image;
        $output .= '<a href="' . $link_to_node . '"><div class="title">' . $article_id_node->field_front_page_title[LANGUAGE_NONE][0]['value'] . '</div></a>';
        $output .= '<div class="created">' . date('d.m.y' , $article_id_node->created) . '</div>';
      }
      
    }
/*    store_pane_content('video_box',
      array(
        'title' => $conf['title'], 
        'nid_1' => $article_id,
      ),
      $conf['pid']
    );*/
    $content = new stdClass();
    $content->node_id[1] = $article_id;
    if(isset($conf['api'])){
        return $content;
    }

    $block = new stdClass();
    $block->title = '';
    $block->content = $output;
    return $block;
}

function rp_plugins_video_box_content_type_edit_form($form, &$form_state) {

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
  $form['article_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Video ID'),
    '#maxlength' => 512,
    '#description' => t('A valid article id.'),
    '#autocomplete_path' => 'ctools/autocomplete/node',
    '#default_value' => !empty($conf['article_id']) ? $conf['article_id'] : '0',
  );
  return $form;
}

function rp_plugins_video_box_content_type_edit_form_submit($form, &$form_state){
  $form_state['conf']['pid'] = $form_state['pane']->pid;
  $form_state['conf']['title'] = $form_state['values']['title'];    
  $form_state['conf']['article_id'] = $form_state['values']['article_id'];
}

function rp_plugins_video_box_content_type_edit_form_validate(&$form, &$form_state) {
  $node = rp_plugins_video_box_autocomplete($form_state['values']['article_id']);
  if ($node) {
    $form_state['values']['article_id'] = $node->nid;
  }
  if ($form_state['values']['article_id'] == '0')
    $form_state['values']['article_id'] = 0; 
  if (($node->type != 'video' || !node_access('view', $node)) && $form_state['values']['article_id'] != '0') {
    form_error($form['article_id'], t('Invalid node'));
  }     
}
function rp_plugins_video_box_autocomplete($nid)  {
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