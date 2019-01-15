<?php

$plugin = array(
  'title' => t('Hp Articles List'),
  'single' => TRUE,
  'category' => array(t('Front Page'), -9),
);
define('NUM_ITEM_GROUP', 30);

function rp_plugins_hp_articles_list_content_type_render($subtype, $conf, $args, $context) {
  $output = '';
  $link = '';
  $field_image = '';
  $unit = '';
  $cassification = '';
  $content = new stdClass();
  if($conf['link'] && $conf['link_title']){
    $link = '<a class="view-more" href="' . $conf['link'] . '">' . t($conf['link_title']) . '</a>';
  }
  if(isset($conf['title']))
    $output .= '<h2 class="pane-title">' . t($conf['title']) . $link . '</h2>';

  if(isset($conf['title']))
    $content->title = $conf['title'];

  if(isset($conf['link']))  
    $content->link = $conf['link'];

  if(isset($conf['link_title']))  
    $content->link_title = $conf['link_title'];

  foreach ($conf['node_id'] as $key => $value) {
    $index = $key + 1;
    $content->node_id[$index] = $value;
    $node = node_load($value);
    if($node) {
      $node_type = $node->type;

      if(isset($node->field_hp_image_picture)){
        $field_image = $node->field_hp_image_picture;
       $field_image_url = file_create_url($field_image[LANGUAGE_NONE][0]['uri']);
       $field_image = '<img src="' . $field_image_url .'"/>';
      }
      if($node->field_images[LANGUAGE_NONE][0]['value']) {
          $field_image = field_collection_item_load($node->field_images[LANGUAGE_NONE][0]['value']);
          $field_image = $field_image->view('hp_large_video');
          $field_image = render($field_image);
      }
    

      $field_title = $node->title;;
      
      if(isset($node->field_front_page_intro[LANGUAGE_NONE][0]['value'])) {
        $field_intro = $node->field_front_page_intro[LANGUAGE_NONE][0]['value']; 
      } else {
        $field_intro = '';
      }
      $link_to_node = drupal_get_path_alias('node/' . $node->nid);
      $field_created = date('d.m.y' ,$node->created);
      if(isset($node->field_section[LANGUAGE_NONE][0]['tid'])) {
        $section = taxonomy_term_load($node->field_section[LANGUAGE_NONE][0]['tid']);
      }

      if(isset($node->field_unit[LANGUAGE_NONE][0]['tid'])){
        $term_unit = taxonomy_term_load($node->field_unit[LANGUAGE_NONE][0]['tid']);
        $unit = $term_unit->name;
      } 

      if(isset($node->field_cassification[LANGUAGE_NONE][0]['tid'])){
        $term_cassification = taxonomy_term_load($node->field_cassification[LANGUAGE_NONE][0]['tid']);
        $cassification = $term_cassification->name;
      }  
   
      $output .= '<div class="article" >
                    <div class="article-right">
                      <a href="' . $link_to_node . '">' . $field_image . '</a>
                      <div class="' . $node_type . ' icon"><span class="icon"></span></div>
                    </div>
                    <div class="article-left">
                      <a href="' . $link_to_node . '" class="title">' . $field_title . '</a>   
                      <a href="' . $link_to_node . '" class="intro">' . $field_intro . '</a>   
                      <div class="details">
                        <span class="unit"> Unit: '  . $unit . '</span><span class="separator">|</span>
                        <span class="cassification"><span class="ttl">Classification: </span>' . $cassification . '</span><span class="separator">|</span>
                        <span class="created">' . $field_created . '</span> 
                    </div> 
                    </div>
                    <hr>
                </div>';
    }
  }

  if(isset($conf['api'])){
    return $content;
  }


  $block = new stdClass();
  $block->title = '';
  $block->content = $output;
  return $block;
}


function rp_plugins_hp_articles_list_content_type_edit_form($form, &$form_state) {

  drupal_add_js(drupal_get_path('module', 'rp_plugins') . '/js/hp_articles_list.js');

  unset($form['override_title']);
  unset($form['override_title_text']);
  unset($form['override_title_markup']);
  unset($form['override_title_heading']);

  $conf = $form_state['conf'];
  $form['design'] = array(
    '#type' => 'select',
    '#title' => t('Design type'),
    '#default_value' => !empty($conf['design']) ? $conf['design'] : '',
    '#options' => drupal_map_assoc(array(t('default'), t('alternative'))),
  );
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
  $form['group'] = array(
    '#type' => 'fieldset',
    '#prefix' => '<div class="sortable">',
    '#suffix' => '</div>',
  );
  for ($i = 0; $i < NUM_ITEM_GROUP; $i++) {
    $form['group'][$i] = array(
      '#type' => 'fieldset',
      '#prefix' => '<div class="item">',
      '#suffix' => '</div>',
    );
    $form['group'][$i]['weight-' . $i] = array(
      '#prefix' => '<div class="form-item-weight" style="display:none">',
      '#suffix' => '</div>',
      '#type' => 'textfield',
      '#default_value' => isset($conf['group'][$i]['weight']) ? $conf['group'][$i]['weight'] : $i,
    );
    $form['group'][$i]['choose-' . $i] = array(
      '#prefix' => '<div class="form-item-choose" style="display:none">',
      '#suffix' => '</div>',
      '#type' => 'textfield',
      '#maxlength' => 1,
      '#default_value' => rp_plugins_hp_articles_list_choose($conf, $i),
    );
    $form['group'][$i]['nid-' . $i] = array(
      '#prefix' => '<div class="form-item-nid">',
      '#suffix' => '</div>',
      '#type' => 'textfield',
      '#title' => t('Article ID'),
      '#maxlength' => 100,
      '#autocomplete_path' => 'ctools/autocomplete/node',
      '#default_value' => !empty($conf['group'][$i]['nid']) ? $conf['group'][$i]['nid'] : '',
    );
    $form['group'][$i]['remove'] = array(      
      '#markup' => '<input type="button" value="' . t('Remove Article') . '"/>',
      '#prefix' => '<div class="remove-item">',
      '#suffix' => '</div>',
    );
  }

  $form['add-item'] = array(
    '#markup' => '<input type="button" value="' . t('Add Article') . '"/>',
    '#prefix' => '<div class="add-item">',
    '#suffix' => '</div>',
  );

  return $form;
}

function rp_plugins_hp_articles_list_content_type_edit_form_submit($form, &$form_state) {
  $form_state['conf']['pid'] = $form_state['pane']->pid;
  $list = array();
  $form_state['conf']['title'] = $form_state['values']['title'];
  $form_state['conf']['design'] = $form_state['values']['design'];     
  $form_state['conf']['link'] = $form_state['values']['link'];    
  $form_state['conf']['link_title'] = $form_state['values']['link_title']; 
  for ($i = 0; $i < NUM_ITEM_GROUP; $i++) {
    $form_state['conf']['group'][$i]['choose'] = $form_state['values']['choose-' . $i];
    $form_state['conf']['group'][$i]['weight'] = intval($form_state['values']['weight-' . $i]);
    $form_state['conf']['group'][$i]['nid'] = $form_state['values']['nid-' . $i];
    if($form_state['values']['nid-' . $i] != '')
      $list[] = $form_state['values']['nid-' . $i];
  }
  $form_state['conf']['node_id'] = $list;
}

function rp_plugins_hp_articles_list_content_type_edit_form_validate(&$form, &$form_state) {
  for ($i = 0; $i < NUM_ITEM_GROUP; $i++) {
    $node = rp_plugins_hp_articles_list_autocomplete($form_state['values']['nid-' . $i]);
    if ($node) {
      $form_state['values']['nid-' . $i] = $node->nid;
    }
    if ($form_state['values']['nid-' . $i] == '')
      $form_state['values']['nid-' . $i] = ''; 
    if (( !node_access('view', $node)) && $form_state['values']['nid-' . $i] != '') {
      form_error($form['group'][$i]['nid-' . $i], t('Invalid node'));
    }
  }
}

function rp_plugins_hp_articles_list_autocomplete($nid) {
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

function rp_plugins_hp_articles_list_choose($conf, $i) {
  $choose = isset($conf['group']) ? $conf['group'][$i]['choose'] : null;
  if (isset($choose))
    return $choose;
  if ($i == 0)
    return 1;
  else {
    return 0;
  }
}

