<?php
/**
 * Plugin info
 */
$plugin = array(
  'title' => t('Editor\'s recommendation'),
  'single' => TRUE,
  'category' => array(t('Front Page'), -9),
);

/**
 * Run-time rendering of the body of the block.
 */
function rp_plugins_editors_recommendation_content_type_render($subtype, $conf, $args, $context) {
    $output = '';
    $content = new stdClass();
    if($conf['title'])
      $output .= '<h2 class="pane-title">' . t($conf['title']) . '</h2>';
    
    $article_id1 = $conf['article_id1'];
    if($article_id1){
      $article_id1_node = node_load($article_id1);
      if($article_id1_node) {
        $node = node_view($article_id1_node, 'hp_small_article');
        $output .= render($node);
      }
    }
    $article_id2 = $conf['article_id2'];
    if($article_id2){
      $article_id2_node = node_load($article_id2);
      if($article_id2_node) {
        $node = node_view($article_id2_node, 'hp_small_article');
        $output .= render($node);
      }
    }
    $article_id3 = $conf['article_id3'];
    if($article_id3){
      $article_id3_node = node_load($article_id3);
      if($article_id3_node) {
        $node = node_view($article_id3_node, 'hp_small_article');
        $output .= render($node);
      }
    }
    $article_id4 = $conf['article_id4'];
    if($article_id4){
      $article_id4_node = node_load($article_id4);
      if($article_id4_node) {
        $node = node_view($article_id4_node, 'hp_small_article');
        $output .= render($node);
      }
    }
    $article_id5 = $conf['article_id5'];
    if($article_id5){
      $article_id5_node = node_load($article_id5);
      if($article_id5_node) {
        $node = node_view($article_id5_node, 'hp_small_article');
        $output .= render($node);
      }
    }
    $content->node_id[1] = $article_id1;
    $content->node_id[2] = $article_id2;
    $content->node_id[3] = $article_id3;
    $content->node_id[4] = $article_id4;
    $content->node_id[5] = $article_id5;
/*    store_pane_content('editors_recommendation',
      array(
        'title' => $conf['title'], 
        'nid_1' => $article_id1,
        'nid_2' => $article_id2,
        'nid_3' => $article_id3,
        'nid_4' => $article_id4,
        'nid_5' => $article_id5
      ),
      $conf['pid']
    );*/


  if(isset($conf['api'])){

        return $content;
    }


    $block = new stdClass();
    $block->title = '';
    $block->content = $output;

    return $block;
}

function rp_plugins_editors_recommendation_content_type_edit_form($form, &$form_state) {

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
  $form['article_id1'] = array(
    '#type' => 'textfield',
    '#title' => t('Article ID'),
    '#maxlength' => 512,
    '#description' => t('A valid article id.'),
    '#autocomplete_path' => 'ctools/autocomplete/node',
    '#default_value' => !empty($conf['article_id1']) ? $conf['article_id1'] : '0',
  );
  $form['article_id2'] = array(
    '#type' => 'textfield',
    '#title' => t('Article ID'),
    '#maxlength' => 512,
    '#description' => t('A valid article id.'),
    '#autocomplete_path' => 'ctools/autocomplete/node',
    '#default_value' => !empty($conf['article_id2']) ? $conf['article_id2'] : '0',
  );
  $form['article_id3'] = array(
    '#type' => 'textfield',
    '#title' => t('Article ID'),
    '#maxlength' => 512,
    '#description' => t('A valid article id.'),
    '#autocomplete_path' => 'ctools/autocomplete/node',
    '#default_value' => !empty($conf['article_id3']) ? $conf['article_id3'] : '0',
  );
  $form['article_id4'] = array(
    '#type' => 'textfield',
    '#title' => t('Article ID'),
    '#maxlength' => 512,
    '#description' => t('A valid article id.'),
    '#autocomplete_path' => 'ctools/autocomplete/node',
    '#default_value' => !empty($conf['article_id4']) ? $conf['article_id4'] : '0',
  );
  $form['article_id5'] = array(
    '#type' => 'textfield',
    '#title' => t('Article ID'),
    '#maxlength' => 512,
    '#description' => t('A valid article id.'),
    '#autocomplete_path' => 'ctools/autocomplete/node',
    '#default_value' => !empty($conf['article_id5']) ? $conf['article_id5'] : '0',
  );
  return $form;
}

function rp_plugins_editors_recommendation_content_type_edit_form_submit($form, &$form_state){
    $form_state['conf']['pid'] = $form_state['pane']->pid;
    $form_state['conf']['title'] = $form_state['values']['title'];    
    $form_state['conf']['article_id1'] = $form_state['values']['article_id1'];    
    $form_state['conf']['article_id2'] = $form_state['values']['article_id2'];    
    $form_state['conf']['article_id3'] = $form_state['values']['article_id3'];    
    $form_state['conf']['article_id4'] = $form_state['values']['article_id4'];    
    $form_state['conf']['article_id5'] = $form_state['values']['article_id5'];    
}

function rp_plugins_editors_recommendation_content_type_edit_form_validate(&$form, &$form_state) {
  foreach (array('article_id1', 'article_id2', 'article_id3', 'article_id4', 'article_id5') as $key) {
    $node = rp_plugins_editors_recommendation_autocomplete($form_state['values'][$key]);
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
function rp_plugins_editors_recommendation_autocomplete($nid)  {
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