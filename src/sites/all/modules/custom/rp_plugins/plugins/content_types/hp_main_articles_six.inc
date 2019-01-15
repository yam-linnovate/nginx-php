<?php
/**
 * Plugin info
 */
$plugin = array(
  'title' => t('HP Main articles six'),
  'single' => FALSE,
  'category' => array(t('Front Page'), -9),
);

/**
 * Run-time rendering of the body of the block.
 */
function rp_plugins_hp_main_articles_six_content_type_render($subtype, $conf, $args, $context) {
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

    $middle_bottom = '<div class="bottom-row middle-row">';
    $middle_bottom_1 = $conf['middle_bottom_1'];
    if($middle_bottom_1){
      $middle_bottom_1_node = node_load($middle_bottom_1);
      if($middle_bottom_1_node) {
        $node = node_view($middle_bottom_1_node, 'hp_small_article');
        $bottom_1 = render($node);
        $middle_bottom .= $bottom_1;
      }
    }

    $middle_bottom_2 = $conf['middle_bottom_2'];
    if($middle_bottom_2){
      $middle_bottom_2_node = node_load($middle_bottom_2);
      if($middle_bottom_2_node) {
        $node = node_view($middle_bottom_2_node, 'hp_small_article');
        $bottom_2 = render($node);
        $middle_bottom .= $bottom_2;
      }
    }
    $middle_bottom .= '</div>';

    $small_bottom = '<div class="bottom-row small-row">';
    $small_bottom_1 = $conf['small_bottom_1'];
    if($small_bottom_1){
      $small_bottom_1_node = node_load($small_bottom_1);
      if($small_bottom_1_node) {
        $node = node_view($small_bottom_1_node, 'hp_small_article');
        $bottom_1 = render($node);
        $small_bottom .= $bottom_1;
      }
    }

    $small_bottom_2 = $conf['small_bottom_2'];
    if($small_bottom_2){
      $small_bottom_2_node = node_load($small_bottom_2);
      if($small_bottom_2_node) {
        $node = node_view($small_bottom_2_node, 'hp_small_article');
        $bottom_2 = render($node);
        $small_bottom .= $bottom_2;
      }
    }

    $small_bottom_3 = $conf['small_bottom_3'];
    if($small_bottom_3){
      $small_bottom_3_node = node_load($small_bottom_3);
      if($small_bottom_3_node) {
        $node = node_view($small_bottom_3_node, 'hp_small_article');
        $bottom_3 = render($node);
        $small_bottom .= $bottom_3;
      }
    }

    $small_bottom_4 = $conf['small_bottom_4'];
    if($small_bottom_4){
      $small_bottom_4_node = node_load($small_bottom_4);
      if($small_bottom_4_node) {
        $node = node_view($small_bottom_4_node, 'hp_small_article');
        $bottom_4 = render($node);
        $small_bottom .= $bottom_4;
      }
    }
    $small_bottom .= '</div>';

    $output = '<div class="hp-articles-top">' . $large . '</div><div class="hp-articles-bottom-wrapper"><div class="hp-articles-bottom">' . $middle_bottom . '</div><div class="hp-articles-bottom">' . $small_bottom . '</div></div>';

    $content->node_id = array(
        '1' => $large_id,
        '2' => $middle_bottom_1,
        '3' => $middle_bottom_2,
        '4' => $small_bottom_1,
        '5' => $small_bottom_2,
        '6' => $small_bottom_3,
        '7' => $small_bottom_4,
    );

  if(isset($conf['api'])){

        return $content;
    }

    $block = new stdClass();
    $block->title = '';
    $block->content = $output;

    return $block;
}

function rp_plugins_hp_main_articles_six_content_type_edit_form($form, &$form_state) {

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

  $form['middle_bottom_1'] = array(
    '#type' => 'textfield',
    '#title' => t('Middle ID 1'),
    '#maxlength' => 512,
    '#description' => t('A valid article id.'),
    '#autocomplete_path' => 'ctools/autocomplete/node',
    '#default_value' => !empty($conf['middle_bottom_1']) ? $conf['middle_bottom_1'] : '0',
  );

  $form['middle_bottom_2'] = array(
    '#type' => 'textfield',
    '#title' => t('Middle ID 2'),
    '#maxlength' => 512,
    '#description' => t('A valid article id.'),
    '#autocomplete_path' => 'ctools/autocomplete/node',
    '#default_value' => !empty($conf['middle_bottom_2']) ? $conf['middle_bottom_2'] : '0',
  );

  $form['small_bottom_1'] = array(
    '#type' => 'textfield',
    '#title' => t('Small Article ID 1'),
    '#maxlength' => 512,
    '#description' => t('A valid article id.'),
    '#autocomplete_path' => 'ctools/autocomplete/node',
    '#default_value' => !empty($conf['small_bottom_1']) ? $conf['small_bottom_1'] : '0',
  );

  $form['small_bottom_2'] = array(
    '#type' => 'textfield',
    '#title' => t('Small Article ID 2'),
    '#maxlength' => 512,
    '#description' => t('A valid article id.'),
    '#autocomplete_path' => 'ctools/autocomplete/node',
    '#default_value' => !empty($conf['small_bottom_2']) ? $conf['small_bottom_2'] : '0',
  );

  $form['small_bottom_3'] = array(
    '#type' => 'textfield',
    '#title' => t('Small Article ID 3'),
    '#maxlength' => 512,
    '#description' => t('A valid article id.'),
    '#autocomplete_path' => 'ctools/autocomplete/node',
    '#default_value' => !empty($conf['small_bottom_3']) ? $conf['small_bottom_3'] : '0',
  );

  $form['small_bottom_4'] = array(
    '#type' => 'textfield',
    '#title' => t('Small Article ID 4'),
    '#maxlength' => 512,
    '#description' => t('A valid article id.'),
    '#autocomplete_path' => 'ctools/autocomplete/node',
    '#default_value' => !empty($conf['small_bottom_4']) ? $conf['small_bottom_4'] : '0',
  );

  return $form;
}

function rp_plugins_hp_main_articles_six_content_type_edit_form_submit($form, &$form_state){
    $form_state['conf']['pid'] = $form_state['pane']->pid;
    $form_state['conf']['large_id'] = $form_state['values']['large_id'];    
    $form_state['conf']['middle_bottom_1'] = $form_state['values']['middle_bottom_1'];    
    $form_state['conf']['middle_bottom_2'] = $form_state['values']['middle_bottom_2'];    
    $form_state['conf']['small_bottom_1'] = $form_state['values']['small_bottom_1'];
    $form_state['conf']['small_bottom_2'] = $form_state['values']['small_bottom_2'];  
    $form_state['conf']['small_bottom_3'] = $form_state['values']['small_bottom_3'];  
    $form_state['conf']['small_bottom_4'] = $form_state['values']['small_bottom_4'];      
    $form_state['conf']['node_id'][0] = $form_state['values']['large_id'];
    $form_state['conf']['node_id'][1] = $form_state['values']['middle_bottom_1'];
    $form_state['conf']['node_id'][2] = $form_state['values']['middle_bottom_2'];
    $form_state['conf']['node_id'][3] = $form_state['values']['small_bottom_1'];
    $form_state['conf']['node_id'][3] = $form_state['values']['small_bottom_2'];
    $form_state['conf']['node_id'][3] = $form_state['values']['small_bottom_3'];
    $form_state['conf']['node_id'][3] = $form_state['values']['small_bottom_4'];
}

function rp_plugins_hp_main_articles_six_content_type_edit_form_validate(&$form, &$form_state) {
  foreach (array('large_id', 'middle_bottom_1', 'middle_bottom_2', 'small_bottom_1', 'small_bottom_2', 'small_bottom_3', 'small_bottom_4') as $key) {
    $node = rp_plugins_hp_main_articles_six_autocomplete($form_state['values'][$key]);
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
function rp_plugins_hp_main_articles_six_autocomplete($nid)  {
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