<?php
/**
 * Plugin info
 */
$plugin = array(
  'title' => t('Upcoming events'),
  'single' => TRUE,
  'category' => array(t('Front Page'), -9),
);

/**
 * Run-time rendering of the body of the block.
 */
function rp_plugins_upcoming_events_content_type_render($subtype, $conf, $args, $context) {
  $output = '';
  $link = '';
  $vertical = '';
  $content = new stdClass();
  if($conf['vertical']){
    $vertical = 'vertical';
  }
  if($conf['link'] && $conf['link_title']){
    $link = '<a class="view-more" href="' . $conf['link'] . '">' . t($conf['link_title']) . '</a>';
  }
  if($conf['title']){
    if($vertical)
      $output .= '<h2 class="pane-title">' . t($conf['title']) . '</h2>';
    else $output .= '<h2 class="pane-title">' . t($conf['title']) . $link . '</h2>';
  }
  $output .= '<div class="content ' . $vertical . '">';
  $nids = array_fill(0,3, '');
  $view = views_get_view_result('event_panel', 'block');
    foreach ($view as $key => $result) {
        $nids[$key] = $result->nid;
    }
    foreach ($nids as $key => $nid){
      //$event_id = 'event_' . $key;
      $event_id = $nid;
      if($event_id){
        $event_id_node = node_load($event_id);
        if($event_id_node) {
          $node = node_view($event_id_node, 'hp_large_article');
          $output .= render($node);
        }
      }
    }
  $output .= '<div class="view-more-bottom"><a class="view-more" href="' . $conf['link'] . '">' . t($conf['link_title']) . '</a></div>';
  if($vertical && $link) {
    $output .= '<div class="link-bottom"><hr>' . $link . '</div>';
  }
  $output .= '</div>';

/*  store_pane_content('upcoming_events',
    array(
      'title' => $conf['title'], 
      'link' => $conf['link'], 
      'link_title' => $conf['link_title'],
        'nid_1' => $nids[0],
        'nid_2' => $nids[1],
        'nid_3' => $nids[2],
    ),
    $conf['pid']
  );*/

    $content->node_id = array(
        '1' => $nids[0],
        '2' => $nids[1],
        '3' => $nids[2],
    );


    if(isset($conf['api'])){
        return $content;
    }


    $block = new stdClass();
  $block->title = '';
  $block->content = $output;

  return $block;
}

function rp_plugins_upcoming_events_content_type_edit_form($form, &$form_state) {

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
  $form['vertical'] = array(
    '#type' => 'checkbox',
    '#title' => t('Display Vertically'),
    '#default_value' => !empty($conf['vertical']) ? $conf['vertical'] : '0',
  );
/*  $form['event_id1'] = array(
    '#type' => 'textfield',
    '#title' => t('Event ID'),
    '#maxlength' => 512,
    '#description' => t('A valid event id.'),
    '#autocomplete_path' => 'ctools/autocomplete/node',
    '#default_value' => !empty($conf['event_id1']) ? $conf['event_id1'] : '0',
  );
  $form['event_id2'] = array(
    '#type' => 'textfield',
    '#title' => t('Event ID'),
    '#maxlength' => 512,
    '#description' => t('A valid event id.'),
    '#autocomplete_path' => 'ctools/autocomplete/node',
    '#default_value' => !empty($conf['event_id2']) ? $conf['event_id2'] : '0',
  );
  $form['event_id3'] = array(
    '#type' => 'textfield',
    '#title' => t('Event ID'),
    '#maxlength' => 512,
    '#description' => t('A valid event id.'),
    '#autocomplete_path' => 'ctools/autocomplete/node',
    '#default_value' => !empty($conf['event_id3']) ? $conf['event_id3'] : '0',
  );*/
  return $form;
}

function rp_plugins_upcoming_events_content_type_edit_form_submit($form, &$form_state){
    $form_state['conf']['pid'] = $form_state['pane']->pid;
    $form_state['conf']['title'] = $form_state['values']['title'];    
    $form_state['conf']['link'] = $form_state['values']['link'];    
    $form_state['conf']['link_title'] = $form_state['values']['link_title'];    
    $form_state['conf']['vertical'] = $form_state['values']['vertical'];    
    $form_state['conf']['event_id1'] = $form_state['values']['event_id1'];    
    $form_state['conf']['event_id2'] = $form_state['values']['event_id2'];    
    $form_state['conf']['event_id3'] = $form_state['values']['event_id3'];    
}

function rp_plugins_upcoming_events_content_type_edit_form_validate(&$form, &$form_state) {
  foreach (array('event_id1', 'event_id2', 'event_id3') as $key) {
    $node = rp_plugins_upcoming_events_autocomplete($form_state['values'][$key]);
    if ($node) {
      $form_state['values'][$key] = $node->nid;
    }
    if ($form_state['values'][$key] == '0')
      $form_state['values'][$key] = 0; 
    if (($node->type != 'event' || !node_access('view', $node)) && $form_state['values'][$key] != '0') {
      form_error($form[$key], t('Invalid node'));
    }
  }      
}
function rp_plugins_upcoming_events_autocomplete($nid)  {
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