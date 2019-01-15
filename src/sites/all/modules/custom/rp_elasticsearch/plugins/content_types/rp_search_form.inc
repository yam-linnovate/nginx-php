<?php
/**
 * Plugin info
 */
$plugin = array(
  'title' => t('Republish Search Form'),  
  'single' => TRUE,
  'category' => array(t('Miscellaneous'), -9),
);



/**
 * Run-time rendering of the body of the block.
 */
function rp_elasticsearch_rp_search_form_content_type_render($subtype, $conf, $args, $context) {

  drupal_add_css('https://cdnjs.cloudflare.com/ajax/libs/select2/4.0.6-rc.0/css/select2.min.css', 'external');
  drupal_add_css('https://maxcdn.bootstrapcdn.com/font-awesome/4.7.0/css/font-awesome.min.css', 'external');
  drupal_add_js('https://cdnjs.cloudflare.com/ajax/libs/select2/4.0.6-rc.0/js/select2.min.js', 'external');

  if(isset($conf['api'])){
        $content = new stdClass();
        return $content;
    }

  $block = new stdClass();
  $block->title = '';
  $form_search = drupal_get_form('rp_elasticsearch_rp_search_form');
  $form_search = drupal_render($form_search);
  $block->content = '<h2 class="pane-title">' . t($conf['title']) . '</h2><div class="rp_search_form_wrapper">'.$form_search.'</div>';

  return $block;
}

function rp_elasticsearch_rp_search_form($form, &$form_state)  {
  $form = array();

  $cassifications = array();
  $cassification_v = taxonomy_vocabulary_machine_name_load('cassification');
  if ($cassifications_list = taxonomy_get_tree($cassification_v->vid)) {
    foreach ($cassifications_list as $cassification => $value){
      $term = taxonomy_term_load($value->tid);      
      $cassifications[$value->tid] = $value->name;          
    }    
  }

  $units = array();
  $unit_v = taxonomy_vocabulary_machine_name_load('unit');
  if ($unit_list = taxonomy_get_tree($unit_v->vid)) {
    foreach ($unit_list as $unit => $value){
      $term = taxonomy_term_load($value->tid);      
      $units[$value->tid] = $value->name;          
    }    
  }

  // $article_types = array();
  // $article_type_v = taxonomy_vocabulary_machine_name_load('article_type');
  // if ($article_type_list = taxonomy_get_tree($article_type_v->vid)) {
  //   foreach ($article_type_list as $article_type => $value){
  //     $term = taxonomy_term_load($value->tid);      
  //     $article_types[$value->tid] = $value->name;          
  //   }    
  // }

  $article_type = field_info_field('field_article_type');
  $articles_type = list_allowed_values($article_type);


  $attached_file = field_info_field('field_file_type');
  $attached_files = list_allowed_values($attached_file);

  // $attached_files = array();
  // //
  // $attached_file_v = taxonomy_vocabulary_machine_name_load('article_type');
  // if ($attached_file_list = taxonomy_get_tree($attached_file_v->vid)) {
  //   foreach ($attached_file_list as $attached_file => $value){
  //     $term = taxonomy_term_load($value->tid);      
  //     $attached_files[$value->tid] = $value->name;          
  //   }    
  // }
  
  $tags = array();
  $tags_v = taxonomy_vocabulary_machine_name_load('tags');
  // $tags[0] = '';
  if ($tags_list = taxonomy_get_tree($tags_v->vid)) {
    foreach ($tags_list as $tag => $value){
      $term = taxonomy_term_load($value->tid);      
      $tags[$value->tid] = $value->name;          
    }    
  }

  
  // //writer options
  // if(cache_get('writers', 'cache_search'))
  //   $writers = cache_get('writers', 'cache_search')->data;  
  // else  $writers = update_writer();
  

  // // section options
  // if(cache_get('sections', 'cache_search'))
  //   $sections = cache_get('sections', 'cache_search')->data;
  // else $sections = update_section();
 

  // //tag options
  // if(cache_get('tags', 'cache_search'))
  //   $tags = cache_get('tags', 'cache_search')->data;
  // else $tags = update_tags();
   
   
  // $form['key'] = array(
  //   '#title' => t('key'),
  //   '#type' => 'textfield',
  //   '#size' => '17',
  // );

  // $form['section'] = array(
  //   '#type' => 'select',
  //   '#options' => $sections,
  // );
  
  $form['reset'] = array(
    '#type' => 'submit',
    '#value' => t('Reset'),
    '#submit' => array('rp_elasticsearch_rp_search_form'),
  );
  
  $form['unit'] = array(
    '#type' => 'select',
    '#options' => $units,
    //'#default_value' => '',
  );

  $form['cassifications'] = array(
    '#type' => 'select',
    '#options' => $cassifications,
    //'#default_value' => '',
  );

  $form['tag'] = array(
    '#type' => 'select',
    '#options' => $tags,
  );

  $years_ago = date('Y') - 2008;
    
  $form['start_date'] = array(
    '#type' => 'date_popup',
    '#date_format' => 'Y m d',
    '#date_label_position' => 'none',
    '#date_year_range' => '-' . $years_ago . ':+0',
    '#title' => t('from date'),
    '#default_value' => '',
  );

  $form['end_date'] = array(
    '#type' => 'date_popup',
    '#date_format' => 'Y m d',
    '#date_label_position' => 'none',
    '#date_year_range' => '-' . $years_ago . ':+0',
    '#title' => t('to date'),
    '#default_value' => '',
  );

  $form['articles_type'] = array(
    '#type' => 'select',
    '#options' => $articles_type,
  );

  $form['attached_files'] = array(
    '#type' => 'select',
    '#options' => $attached_files,
  );

  $form['submit'] = array(
    '#type' => 'button',
    '#value' => t('search'),
    '#attributes' => array('class' => array('rp_search_form_submit')),
  );

  return $form;
}

function rp_elasticsearch_rp_search_form_content_type_edit_form($form, &$form_state) {
  unset($form['override_title']);

  $conf = $form_state['conf'];

  $form['title'] = array(
    '#type' => 'textfield',
    '#title' => t('Title'),
    '#maxlength' => 512,
    '#default_value' => !empty($conf['title']) ? $conf['title'] : '',
  );
  return $form;
}

function rp_elasticsearch_rp_search_form_content_type_edit_form_submit($form, &$form_state){
  $form_state['conf']['title'] = $form_state['values']['title'];  

}

function rp_elasticsearch_rp_search_form_form_reset($form, &$form_state) {
  $form_state['rebuild'] = FALSE;
}