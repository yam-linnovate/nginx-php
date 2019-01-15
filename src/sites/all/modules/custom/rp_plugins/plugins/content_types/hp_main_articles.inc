<?php
/**
 * Plugin info
 */
$plugin = array(
  'title' => t('HP Main articles'),
  'single' => TRUE,
  'category' => array(t('Front Page'), -9),
);

/**
 * Run-time rendering of the body of the block.
 */
function rp_plugins_hp_main_articles_content_type_render($subtype, $conf, $args, $context) {
    $output = '';
    $content = new stdClass();
    $large = '';
    $large_id = $conf['large_id'];
    if($large_id){
      $large_id_node = node_load($large_id);
      if($large_id_node) {
        $node = node_view($large_id_node, 'hp_large_article');
        $large = render($node);
      }
    }

    $content_bottom = '<div class="bottom-row">';
    $content_bottom_1 = $conf['content_bottom_1'];
    if($content_bottom_1){
      $content_bottom_1_node = node_load($content_bottom_1);
      if($content_bottom_1_node) {
        $node = node_view($content_bottom_1_node, 'hp_small_article');
        $bottom_1 = render($node);
        $content_bottom .= $bottom_1;
      }
    }

    $content_bottom_2 = $conf['content_bottom_2'];
    if($content_bottom_2){
      $content_bottom_2_node = node_load($content_bottom_2);
      if($content_bottom_2_node) {
        $node = node_view($content_bottom_2_node, 'hp_small_article');
        $bottom_2 = render($node);
        $content_bottom .= $bottom_2;
      }
    }
    $content_bottom_3 = $conf['content_bottom_3'];
    if($content_bottom_3){
      $content_bottom_3_node = node_load($content_bottom_3);
      if($content_bottom_3_node) {
        $node = node_view($content_bottom_3_node, 'hp_small_article');
        $bottom_3 = render($node);
        $content_bottom .= $bottom_3;
      }
    }
    $content_bottom .= '</div><div class="bottom-row">';
    $content_bottom_4 = $conf['content_bottom_4'];
    if($content_bottom_4){
      $content_bottom_4_node = node_load($content_bottom_4);
      if($content_bottom_4_node) {
        $node = node_view($content_bottom_4_node, 'hp_small_article');
        $bottom_4 = render($node);
        $content_bottom .= $bottom_4;
      }
    }
    $content_bottom_5 = $conf['content_bottom_5'];
    if($content_bottom_5){
      $content_bottom_5_node = node_load($content_bottom_5);
      if($content_bottom_5_node) {
        $node = node_view($content_bottom_5_node, 'hp_small_article');
        $bottom_5 = render($node);
        $content_bottom .= $bottom_5;
      }
    }
    $content_bottom_6 = $conf['content_bottom_6'];
    if($content_bottom_6){
      $content_bottom_6_node = node_load($content_bottom_6);
      if($content_bottom_6_node) {
        $node = node_view($content_bottom_6_node, 'hp_small_article');
        $bottom_6 = render($node);
        $content_bottom .= $bottom_6;
      }
    }
    $content_bottom .= '</div>';

    $output = '<div class="hp-articles-top">' . $large . '</div><div class="hp-articles-bottom">' . $content_bottom . '</div>';

    $content->node_id = array(
        '1' => $large_id,
        '2' => $content_bottom_1,
        '3' => $content_bottom_2,
        '4' => $content_bottom_3,
        '5' => $content_bottom_4,
        '6' => $content_bottom_5,
        '7' => $content_bottom_6,
    );

  if(isset($conf['api'])){

        return $content;
    }

    $block = new stdClass();
    $block->title = '';
    $block->content = $output;

    return $block;
}

function rp_plugins_hp_main_articles_content_type_edit_form($form, &$form_state) {

  unset($form['override_title']);
  unset($form['override_title_text']);
  unset($form['override_title_markup']);
  unset($form['override_title_heading']);
  
  $conf = $form_state['conf'];

  $form['large_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Large Article ID'),
    '#maxlength' => 512,
    '#description' => t('A valid article id.'),
    '#autocomplete_path' => 'ctools/autocomplete/node',
    '#default_value' => !empty($conf['large_id']) ? $conf['large_id'] : '0',
  );

  $form['content_bottom_1'] = array(
    '#type' => 'textfield',
    '#title' => t('Article ID 1'),
    '#maxlength' => 512,
    '#description' => t('A valid article id.'),
    '#autocomplete_path' => 'ctools/autocomplete/node',
    '#default_value' => !empty($conf['content_bottom_1']) ? $conf['content_bottom_1'] : '0',
  );

  $form['content_bottom_2'] = array(
    '#type' => 'textfield',
    '#title' => t('Article ID 2'),
    '#maxlength' => 512,
    '#description' => t('A valid article id.'),
    '#autocomplete_path' => 'ctools/autocomplete/node',
    '#default_value' => !empty($conf['content_bottom_2']) ? $conf['content_bottom_2'] : '0',
  );

  $form['content_bottom_3'] = array(
    '#type' => 'textfield',
    '#title' => t('Article ID 3'),
    '#maxlength' => 512,
    '#description' => t('A valid article id.'),
    '#autocomplete_path' => 'ctools/autocomplete/node',
    '#default_value' => !empty($conf['content_bottom_3']) ? $conf['content_bottom_3'] : '0',
  );

  $form['content_bottom_4'] = array(
    '#type' => 'textfield',
    '#title' => t('Article ID 4'),
    '#maxlength' => 512,
    '#description' => t('A valid article id.'),
    '#autocomplete_path' => 'ctools/autocomplete/node',
    '#default_value' => !empty($conf['content_bottom_4']) ? $conf['content_bottom_4'] : '0',
  );

  $form['content_bottom_5'] = array(
    '#type' => 'textfield',
    '#title' => t('Article ID 5'),
    '#maxlength' => 512,
    '#description' => t('A valid article id.'),
    '#autocomplete_path' => 'ctools/autocomplete/node',
    '#default_value' => !empty($conf['content_bottom_5']) ? $conf['content_bottom_5'] : '0',
  );

  $form['content_bottom_6'] = array(
    '#type' => 'textfield',
    '#title' => t('Article ID 6'),
    '#maxlength' => 512,
    '#description' => t('A valid article id.'),
    '#autocomplete_path' => 'ctools/autocomplete/node',
    '#default_value' => !empty($conf['content_bottom_6']) ? $conf['content_bottom_6'] : '0',
  );
  return $form;
}

function rp_plugins_hp_main_articles_content_type_edit_form_submit($form, &$form_state){
    $form_state['conf']['pid'] = $form_state['pane']->pid;
    $form_state['conf']['large_id'] = $form_state['values']['large_id'];    
    $form_state['conf']['content_bottom_1'] = $form_state['values']['content_bottom_1'];    
    $form_state['conf']['content_bottom_2'] = $form_state['values']['content_bottom_2'];    
    $form_state['conf']['content_bottom_3'] = $form_state['values']['content_bottom_3'];    
    $form_state['conf']['content_bottom_4'] = $form_state['values']['content_bottom_4'];    
    $form_state['conf']['content_bottom_5'] = $form_state['values']['content_bottom_5'];    
    $form_state['conf']['content_bottom_6'] = $form_state['values']['content_bottom_6'];
    $form_state['conf']['node_id'][0] = $form_state['values']['large_id'];
    $form_state['conf']['node_id'][1] = $form_state['values']['content_bottom_1'];
    $form_state['conf']['node_id'][2] = $form_state['values']['content_bottom_2'];
    $form_state['conf']['node_id'][3] = $form_state['values']['content_bottom_3'];
    $form_state['conf']['node_id'][4] = $form_state['values']['content_bottom_4'];
    $form_state['conf']['node_id'][5] = $form_state['values']['content_bottom_5'];
    $form_state['conf']['node_id'][6] = $form_state['values']['content_bottom_6'];

}

function rp_plugins_hp_main_articles_content_type_edit_form_validate(&$form, &$form_state) {
  foreach (array('large_id', 'content_bottom_1', 'content_bottom_2', 'content_bottom_3', 'content_bottom_4', 'content_bottom_5', 'content_bottom_6') as $key) {
    $node = rp_plugins_hp_main_articles_autocomplete($form_state['values'][$key]);
    if ($node) {
      $form_state['values'][$key] = $node->nid;
    }
    if ($form_state['values'][$key] == '0')
      $form_state['values'][$key] = 0; 
    if ((($node->type != 'article' && $node->type != 'video') || !node_access('view', $node)) && $form_state['values'][$key] != '0') {
      form_error($form[$key], t('Invalid node'));
    }
  }      
}
function rp_plugins_hp_main_articles_autocomplete($nid)  {
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