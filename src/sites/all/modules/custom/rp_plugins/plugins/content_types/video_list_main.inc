<?php
/**
 * Plugin info
 */
$plugin = array(
  'title' => t('Video List Main'),
  'single' => TRUE,
  'category' => array(t('Video Page'), -9),
);

/**
 * Run-time rendering of the body of the block.
 */
function rp_plugins_video_list_main_content_type_render($subtype, $conf, $args, $context) {
    $output = '';
    $content = new stdClass();
    if($conf['auto']) {
      $view = views_get_view_result('video', 'block_2');
      $large_id = isset($view[0]->nid) ? $view[0]->nid : 0;
      $left_id1 = isset($view[1]->nid) ? $view[1]->nid : 0;
      $left_id2 = isset($view[2]->nid) ? $view[2]->nid : 0;
      $bottom_id1 = isset($view[3]->nid) ? $view[3]->nid : 0;
      $bottom_id2 = isset($view[4]->nid) ? $view[4]->nid : 0;
      $bottom_id3 = isset($view[5]->nid) ? $view[5]->nid : 0;

    }
    else {
      $large_id = $conf['large_id'];
      $left_id1 = $conf['left_id1'];
      $left_id2 = $conf['left_id2'];
      $bottom_id1 = $conf['bottom_id1'];
      $bottom_id2 = $conf['bottom_id2'];
      $bottom_id3 = $conf['bottom_id3'];
    }
    $large = '';
    if($large_id){
      $large .= rp_plugins_video_list_main_render_item($large_id, '700x400');
    }

    $left = '';
    if($left_id1){
      $left .= rp_plugins_video_list_main_render_item($left_id1, '700x400');
    }
    if($left_id2){
      $left .= rp_plugins_video_list_main_render_item($left_id2, '700x400');
    }

    $bottom = '';
    if($bottom_id1){
      $bottom .= rp_plugins_video_list_main_render_item($bottom_id1, '700x400');
    }
    if($bottom_id2){
      $bottom .= rp_plugins_video_list_main_render_item($bottom_id2, '700x400');
    }
    if($bottom_id3){
      $bottom .= rp_plugins_video_list_main_render_item($bottom_id3, '700x400');
    }
/*    store_pane_content('video_list_main',
      array(
        'nid_1' => $large_id,
        'nid_2' => $left_id1,
        'nid_3' => $left_id2,
        'nid_4' => $bottom_id1,
        'nid_5' => $bottom_id2,
        'nid_6' => $bottom_id3
      ),
      $conf['pid']
    );*/
    $output = '<div class="video-main-large">' . $large . '</div><div class="video-main-left">' . $left . '</div><div class="video-main-bottom">' . $bottom . '</div>';


        $content->node_id[1] =  $large_id;
        $content->node_id[2] = $left_id1;
        $content->node_id[3] =  $left_id2;
        $content->node_id[4] = $bottom_id1;
        $content->node_id[5] =  $bottom_id2;
        $content->node_id[6] = $bottom_id3;

    if(isset($conf['api'])){
        return $content;
    }

    $block = new stdClass();
    $block->title = '';
    $block->content = $output;

    return $block;
}

function rp_plugins_video_list_main_content_type_edit_form($form, &$form_state) {

  unset($form['override_title']);
  unset($form['override_title_text']);
  unset($form['override_title_markup']);
  unset($form['override_title_heading']);
  
  $conf = $form_state['conf'];
  $form['auto'] = array(
    '#type' => 'checkbox',
    '#title' => t('Automatic Load last videos'),
    '#default_value' => !empty($conf['auto']) ? $conf['auto'] : '0',
  );
  $form['large_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Large Video ID'),
    '#maxlength' => 512,
    '#description' => t('A valid video id.'),
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
    '#title' => t('Left Video ID 1'),
    '#maxlength' => 512,
    '#description' => t('A valid video id.'),
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
    '#title' => t('Left Video ID 2'),
    '#maxlength' => 512,
    '#description' => t('A valid video id.'),
    '#autocomplete_path' => 'ctools/autocomplete/node',
    '#default_value' => !empty($conf['left_id2']) ? $conf['left_id2'] : '0',
    '#states' => array(
      'invisible' => array(
        ':input[name="auto"]' => array('checked' => TRUE),
      ),
    ),
  );

  $form['bottom_id1'] = array(
    '#type' => 'textfield',
    '#title' => t('Bottom Video ID 1'),
    '#maxlength' => 512,
    '#description' => t('A valid video id.'),
    '#autocomplete_path' => 'ctools/autocomplete/node',
    '#default_value' => !empty($conf['bottom_id1']) ? $conf['bottom_id1'] : '0',
    '#states' => array(
      'invisible' => array(
        ':input[name="auto"]' => array('checked' => TRUE),
      ),
    ),
  );

  $form['bottom_id2'] = array(
    '#type' => 'textfield',
    '#title' => t('Bottom Video ID 2'),
    '#maxlength' => 512,
    '#description' => t('A valid video id.'),
    '#autocomplete_path' => 'ctools/autocomplete/node',
    '#default_value' => !empty($conf['bottom_id2']) ? $conf['bottom_id2'] : '0',
    '#states' => array(
      'invisible' => array(
        ':input[name="auto"]' => array('checked' => TRUE),
      ),
    ),
  );

  $form['bottom_id3'] = array(
    '#type' => 'textfield',
    '#title' => t('Bottom Video ID 3'),
    '#maxlength' => 512,
    '#description' => t('A valid video id.'),
    '#autocomplete_path' => 'ctools/autocomplete/node',
    '#default_value' => !empty($conf['bottom_id3']) ? $conf['bottom_id3'] : '0',
    '#states' => array(
      'invisible' => array(
        ':input[name="auto"]' => array('checked' => TRUE),
      ),
    ),
  );
  return $form;
}

function rp_plugins_video_list_main_content_type_edit_form_submit($form, &$form_state){
    $form_state['conf']['pid'] = $form_state['pane']->pid;
    $form_state['conf']['auto'] = $form_state['values']['auto'];    
    $form_state['conf']['large_id'] = $form_state['values']['large_id'];    
    $form_state['conf']['left_id1'] = $form_state['values']['left_id1'];    
    $form_state['conf']['left_id2'] = $form_state['values']['left_id2'];    
    $form_state['conf']['bottom_id1'] = $form_state['values']['bottom_id1'];    
    $form_state['conf']['bottom_id2'] = $form_state['values']['bottom_id2'];    
    $form_state['conf']['bottom_id3'] = $form_state['values']['bottom_id3'];
    if($form_state['conf']['auto']){
      variable_set('video_list_main', 'auto');
    }
    else variable_set('video_list_main', array($form_state['conf']['large_id'], $form_state['conf']['left_id1'], $form_state['conf']['left_id2'], $form_state['conf']['bottom_id1'], $form_state['conf']['bottom_id3'], $form_state['conf']['bottom_id3']));
}

function rp_plugins_video_list_main_content_type_edit_form_validate(&$form, &$form_state) {
  foreach (array('large_id', 'left_id1', 'left_id2', 'bottom_id1', 'bottom_id2', 'bottom_id3') as $key) {
    $node = rp_plugins_video_list_main_autocomplete($form_state['values'][$key]);
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
function rp_plugins_video_list_main_autocomplete($nid)  {
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

function rp_plugins_video_list_main_render_item($id, $image_style){
  $node = node_load($id);
  if($node) {
    $detect = mobile_detect_get_object();
    $is_mobile = $detect->isMobile();
    $is_tablet = $detect->isTablet();
    $tid = $node->field_writer['und'][0]['tid'];
    $term = taxonomy_term_load($tid);
    $writer_name = $term->name;
    $link_to_node = drupal_get_path_alias('node/' . $node->nid);
    $output = '';
    $field_images = field_collection_item_load($node->field_images[LANGUAGE_NONE][0]['value']);
    if($field_images){
      $output = '<a class="video-img-wrapper" href="' . $link_to_node . '"><div class="video-img"><div class="img"><div class="video icon"><span class="icon"></span></div>';
      $output .= theme('image_style', array('style_name' => $image_style, 'alt' => $field_images->field_image['und'][0]['alt'], 'path' => $field_images->field_image[LANGUAGE_NONE][0]['uri'])); 
      $output .= '</div><div class="video icon"><span class="icon"></span></div>';
    }
    if(!$is_mobile && !$is_tablet){
      $output .= '<div class="video-title"><div class="title">' . $node->field_front_page_title[LANGUAGE_NONE][0]['value'] . '</div></div>';
    } else if($is_mobile || $is_tablet) {
      $output .= '<div class="video-title"><div class="title">' . $node->field_front_page_title[LANGUAGE_NONE][0]['value'] . '</div><div class="video-view-more"">' . $writer_name . '</div></div>';
    }
    $output .= '</div></a>';
    return $output;
  }
}