<?php
/**
 * Plugin info
 */
$plugin = array(
  'title' => t('Head to Head'),
  'single' => TRUE,
  'category' => array(t('Front Page'), -9),
);

/**
 * Run-time rendering of the body of the block.
 */
function rp_head_to_head_head_to_head_content_type_render($subtype, $conf, $args, $context) {

  $head_to_head_node = NULL;
  $head_to_head_nid = NULL;
  $head_to_head_title = '';
  $head_to_head_img = '';
  $positive_opinion_node = NULL;
  $positive_opinion_title = '';
  $positive_opinion_writer = NULL;
  $positive_opinion_writer_name = '';
  $positive_opinion_writer_img = '';
  $negative_opinion_node = NULL;
  $negative_opinion_title = '';
  $negative_opinion_writer = NULL;
  $negative_opinion_writer_name = '';
  $negative_opinion_writer_img = '';



  if(!empty($conf['head_to_head_nid'])){

    $head_to_head_node = node_load($conf['head_to_head_nid']);
    if($head_to_head_node){
      $head_to_head_nid = $head_to_head_node -> nid;
      $head_to_head_title = !empty($conf['title']) ? $conf['title'] : $head_to_head_node->title; 
      $head_to_head_img = isset($head_to_head_node->field_image_head_to_head[LANGUAGE_NONE][0]['uri'])?image_style_url('writer_120x120', $head_to_head_node->field_image_head_to_head[LANGUAGE_NONE][0]['uri']): ''; 
      $positive_opinion_node =isset($head_to_head_node->field_positive_opinion[LANGUAGE_NONE][0]['target_id'])? node_load($head_to_head_node->field_positive_opinion[LANGUAGE_NONE][0]['target_id']): NULL;
      $positive_opinion_title =isset($positive_opinion_node->field_front_page_intro[LANGUAGE_NONE][0]['value'])? $positive_opinion_node->field_front_page_intro[LANGUAGE_NONE][0]['value']: '';
      $positive_opinion_writer = isset($positive_opinion_node->field_writer[LANGUAGE_NONE][0]["tid"])?taxonomy_term_load($positive_opinion_node->field_writer[LANGUAGE_NONE][0]["tid"]):NULL;
      if($positive_opinion_writer){
        $positive_opinion_writer_name = $positive_opinion_writer->name;
        $positive_opinion_writer_img = isset($positive_opinion_writer->field_drawing[LANGUAGE_NONE][0]['uri'])?image_style_url('writer_120x120', $positive_opinion_writer->field_drawing[LANGUAGE_NONE][0]['uri']): '';
      }
      $negative_opinion_node =isset($head_to_head_node->field_negative_opinion[LANGUAGE_NONE][0]['target_id'])? node_load($head_to_head_node->field_negative_opinion[LANGUAGE_NONE][0]['target_id']): NULL;
      $negative_opinion_title = isset($negative_opinion_node->field_front_page_intro[LANGUAGE_NONE][0]['value'])?$negative_opinion_node->field_front_page_intro[LANGUAGE_NONE][0]['value']: '';
      $negative_opinion_writer = isset($negative_opinion_node->field_writer[LANGUAGE_NONE][0]['tid'])?taxonomy_term_load($negative_opinion_node->field_writer[LANGUAGE_NONE][0]['tid']):NULL;
      if($negative_opinion_writer){
        $negative_opinion_writer_name = $negative_opinion_writer->name;
        $negative_opinion_writer_img =isset($negative_opinion_writer->field_drawing[LANGUAGE_NONE][0]['uri'])? image_style_url('writer_120x120',$negative_opinion_writer->field_drawing[LANGUAGE_NONE][0]['uri']):'';
      }
    }
  }

  $tpl = 'rp_head_to_head';

  if(isset($conf['api'])){
        $content = new stdClass();
        return $content;
    }


    $block = new stdClass();
  $block->title = '';
  $block->content = 
  theme($tpl,
   array('head_to_head_img'=> $head_to_head_img,
         'head_to_head_title'=> $head_to_head_title,
         'positive_opinion_title' => $positive_opinion_title,
         'positive_opinion_writer_name' => $positive_opinion_writer_name,
         'positive_opinion_writer_img' => $positive_opinion_writer_img,
         'negative_opinion_title' => $negative_opinion_title,
         'negative_opinion_writer_name' => $negative_opinion_writer_name,
         'negative_opinion_writer_img' => $negative_opinion_writer_img,
         'head_to_head_path' => drupal_get_path_alias('node/' . $head_to_head_nid),
         'head_to_head_nid' =>  $head_to_head_nid
         )
  );
  return $block;

}

function rp_head_to_head_head_to_head_content_type_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];


  // //update the node from mongo
  // if(!empty($conf['head_to_head_nid'])){
  //   $nid = $conf['head_to_head_nid'];
  //   $data = array(
  //         'nid' => $nid,
  //       );
  //   global $base_url;
  //   $url = url($base_url .'/head-to-head/get-polls',  array('query' => $data));    
  //   $res = drupal_http_request($url);
  //   if($res->data){
  //     $data = drupal_json_decode($res->data);
  //     $node= node_load($nid);
  //     $node->field_positive_opinion_count[LANGUAGE_NONE][0]["value"] = $data["positive"];
  //     $node->field_negative_opinion_count[LANGUAGE_NONE][0]["value"] = $data["negative"];
  //     node_save($node);

  //   }

  // }





  unset($form['override_title']);
  unset($form['override_title_text']);
  unset($form['override_title_markup']); 

 $form['head_to_head_nid'] = array(
    '#type' => 'textfield',
    '#title' => t('Enter nid head to head'),
    '#default_value' => !empty($conf['head_to_head_nid']) ? $conf['head_to_head_nid'] : '',
   
  );
 

  $form['override_main_title'] = array(
    '#type' => 'checkbox',
    '#title' => t('Override title'),
    '#default_value' => !empty($conf['title']) ? 1 : 0,
  );


  $form['title'] = array(
    '#type' => 'container',
    '#states' => array (
      'visible' => array(
        ':input[name="override_main_title"]' => array('checked' => TRUE),
        ),
      ),
    );

  $form['title'] ['title_name'] = array(
    '#type' => 'textfield',
     '#default_value' => !empty($conf['title']) ? $conf['title'] : '',
    

    );
  
  return $form;
}


function rp_head_to_head_head_to_head_content_type_edit_form_validate (&$form, &$form_state){
  if(empty($form_state['values']['head_to_head_nid'])){
    form_set_error('head_to_head_nid', t('Nid is a required field'));
  }
 

 }

function rp_head_to_head_head_to_head_content_type_edit_form_submit($form, &$form_state) {
  $form_state['conf']['head_to_head_nid'] = $form_state['values']['head_to_head_nid'];
  $form_state['conf']['override_main_title'] = $form_state['values']['override_main_title'];
  $form_state['conf']['title'] = $form_state['values']['title_name'];
  
}