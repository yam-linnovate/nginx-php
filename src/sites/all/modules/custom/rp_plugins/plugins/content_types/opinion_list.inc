<?php
/**
 * Plugin info
 */
$plugin = array(
  'title' => t('Opinion List'),
  'single' => TRUE,
  'category' => array(t('Opinion Page'), -9),
);

/**
 * Run-time rendering of the body of the block.
 */
function rp_plugins_opinion_list_content_type_render($subtype, $conf, $args, $context) {
    $output = '';
    $offset = 0;
    variable_set('opinion_list', TRUE);
    $nids = variable_get('opinion_list_main', '');
    if(is_array($nids))
      $nids = implode('+', $nids);
    else if($nids == 'auto'){
      $offset = 3;
      $nids = '';
    }
    $view = views_get_view('opinions', TRUE);
    $view->set_display('block_2');
    if($nids)
      $view->set_arguments(array($nids));
    if($offset)
      $view->set_offset($offset);
    $view->execute();
    $content = new stdClass();
    foreach ($view->result as $key => $value) {
      $index = $key + 1;
      $content->node_id[$index] = $value->nid;
    }    
    //store_pane_content('opinion_list', $content);
    $output .= $view->preview();

      if(isset($conf['api'])){
          return $content;
      }


    $block = new stdClass();
    $block->title = '';
    $block->content = $output;

    return $block;
}
