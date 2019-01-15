<?php
/**
 * Plugin info
 */
$plugin = array(
  'title' => t('HP Main videos'),
  'single' => TRUE,
  'category' => array(t('Front Page'), -9),
);

/**
 * Run-time rendering of the body of the block.
 */
function rp_plugins_hp_main_videos_content_type_render($subtype, $conf, $args, $context) {    
    $link = '';
    $content = new stdClass();
    if($conf['link'] && $conf['link_title']){
      $link = '<span class="view-more" >' . t($conf['link_title']) . '</span>';
    }
    $output = '<a href="' . $conf['link'] . '"><h2 class="pane-title"><div class="title-text">' . t('נדל"ן') .'<span>' . t('TV') . '</span>' . $link . '</div></h2></a>';
    $large = '';
    $large_id = $conf['large_id'];
    if($large_id){
      $large_id_node = node_load($large_id);
      if($large_id_node) {
        $node = node_view($large_id_node, 'hp_video_large');
        $large = render($node);
      }
    }

    $small = '<div class="small">';
    $small1_id = $conf['small_id1'];
    if($small1_id){
      $small1_id_node = node_load($small1_id);
      if($small1_id_node) {
        $node = node_view($small1_id_node, 'hp_small_article');
        $small1 = render($node);
        $small .= $small1;
      }
    }
    $small2_id = $conf['small_id2'];
    if($small2_id){
      $small2_id_node = node_load($small2_id);
      if($small2_id_node) {
        $node = node_view($small2_id_node, 'hp_small_article');
        $small2 = render($node);
        $small .= $small2;
      }
    }
    $small3_id = $conf['small_id3'];
    if($small3_id){
      $small3_id_node = node_load($small3_id);
      if($small3_id_node) {
        $node = node_view($small3_id_node, 'hp_small_article');
        $small3 = render($node);
        $small .= $small3;
      }
    }
    $small .= '</div>';


    $output .= '<div class="hp-videos-right">' . $large . '</div><div class="hp-videos-left">' . $small . '</div>';
    $content->node_id = array(
        'link' => $conf['link'],
        'link_title' => $conf['link_title'],
        '1' => $large_id,
        '2' => $small1_id,
        '3' => $small2_id,
        '4' => $small3_id,
    );

  if(isset($conf['api'])){

        return $content;
    }

    $block = new stdClass();
    $block->title = '';
    $block->content = $output;

    return $block;
}

function rp_plugins_hp_main_videos_content_type_edit_form($form, &$form_state) {

  unset($form['override_title']);
  unset($form['override_title_text']);
  unset($form['override_title_markup']);
  unset($form['override_title_heading']);
  
  $conf = $form_state['conf'];

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

  $form['large_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Large Article ID'),
    '#maxlength' => 512,
    '#description' => t('A valid article id.'),
    '#autocomplete_path' => 'ctools/autocomplete/node',
    '#default_value' => !empty($conf['large_id']) ? $conf['large_id'] : '0',
  );

  $form['small_id1'] = array(
    '#type' => 'textfield',
    '#title' => t('Small Article ID 1'),
    '#maxlength' => 512,
    '#description' => t('A valid article id.'),
    '#autocomplete_path' => 'ctools/autocomplete/node',
    '#default_value' => !empty($conf['small_id1']) ? $conf['small_id1'] : '0',
  );

  $form['small_id2'] = array(
    '#type' => 'textfield',
    '#title' => t('Small Article ID 2'),
    '#maxlength' => 512,
    '#description' => t('A valid article id.'),
    '#autocomplete_path' => 'ctools/autocomplete/node',
    '#default_value' => !empty($conf['small_id2']) ? $conf['small_id2'] : '0',
  );

  $form['small_id3'] = array(
    '#type' => 'textfield',
    '#title' => t('Small Article ID 3'),
    '#maxlength' => 512,
    '#description' => t('A valid article id.'),
    '#autocomplete_path' => 'ctools/autocomplete/node',
    '#default_value' => !empty($conf['small_id3']) ? $conf['small_id3'] : '0',
  );
  return $form;
}

function rp_plugins_hp_main_videos_content_type_edit_form_submit($form, &$form_state){
    $form_state['conf']['pid'] = $form_state['pane']->pid;
    $form_state['conf']['link'] = $form_state['values']['link'];    
    $form_state['conf']['link_title'] = $form_state['values']['link_title'];    
    $form_state['conf']['large_id'] = $form_state['values']['large_id'];    
    $form_state['conf']['small_id1'] = $form_state['values']['small_id1'];    
    $form_state['conf']['small_id2'] = $form_state['values']['small_id2'];    
    $form_state['conf']['small_id3'] = $form_state['values']['small_id3'];
    $form_state['conf']['node_id'][0] = $form_state['values']['large_id'];
    $form_state['conf']['node_id'][1] = $form_state['values']['small_id1'];
    $form_state['conf']['node_id'][2] = $form_state['values']['small_id2'];
    $form_state['conf']['node_id'][3] = $form_state['values']['small_id3'];

}

function rp_plugins_hp_main_videos_content_type_edit_form_validate(&$form, &$form_state) {
  foreach (array('large_id', 'small_id1', 'small_id2', 'small_id3') as $key) {
    $node = rp_plugins_hp_main_videos_autocomplete($form_state['values'][$key]);
    if ($node) {
      $form_state['values'][$key] = $node->nid;
    }
    if ($form_state['values'][$key] == '0')
      $form_state['values'][$key] = 0; 
    if (($node->type != 'video' || !node_access('view', $node)) && $form_state['values'][$key] != '0') {
      form_error($form[$key], t('Invalid node'));
    }
  }      
}
function rp_plugins_hp_main_videos_autocomplete($nid)  {
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