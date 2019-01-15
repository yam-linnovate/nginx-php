<?php
/**
 * Plugin info
 */
$plugin = array(
  'title' => t('Opinion List Second'),
  'single' => TRUE,
  'category' => array(t('Opinion Page'), -9),
);

/**
 * Run-time rendering of the body of the block.
 */
function rp_plugins_opinion_list_second_content_type_render($subtype, $conf, $args, $context) {
    $output = '';
    $offset = variable_get('opinion_list', FALSE) ? 4 : 0;
    $nids = variable_get('opinion_list_main', '');
    if(is_array($nids))
      $nids = implode('+', $nids);
    else if($nids == 'auto'){
      $offset += 3;
      $nids = '';
    }
    $view = views_get_view('opinions', TRUE);
    $view->set_display('block_2');
    if($nids)
      $view->set_arguments(array($nids));
    $view->set_items_per_page(10);
    $view->set_offset($offset);
    $view->execute();
    $content = new stdClass();
    foreach ($view->result as $key => $value) {
      $index = $key + 1;
      $content->node_id[$index] = $value->nid;
    }    
    //store_pane_content('opinion_list_second', $content);
    $output .= $view->preview();

  if(isset($conf['api'])){
        return $content;
    }


    $block = new stdClass();
    $block->title = '';
    $block->content = $output;

    return $block;
}
