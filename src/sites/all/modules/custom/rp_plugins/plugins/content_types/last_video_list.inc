<?php
/**
 * Plugin info
 */
$plugin = array(
  'title' => t('Last Video List'),
  'single' => TRUE,
  'category' => array(t('Video Page'), -9),
);

/**
 * Run-time rendering of the body of the block.
 */
function rp_plugins_last_video_list_content_type_render($subtype, $conf, $args, $context) {
	variable_set('last_video_list', TRUE);
	$video_list_main = variable_get('video_list_main', array());
	if(is_array($video_list_main)){
    	$video_list_main = implode('+', $video_list_main);
    	$offset = 0;
	}
  	else {
	    $offset = 6;
	    $video_list_main = '';
  	}
	
	$view = views_get_view('video', TRUE);
  	$view->set_display('block_1');
  	if($video_list_main)
  		$view->set_arguments(array($video_list_main));
  	$view->set_offset($offset);
  	$view->execute();
    $content = new stdClass();
    foreach ($view->result as $key => $value) {
      $index = $key + 1;
      $content->node_id[$index] = $value->nid;
    }    
    //store_pane_content('last_video_list', $content);
  	$output = $view->preview();

  if(isset($conf['api'])){
        return $content;
    }


    $block = new stdClass();
    $block->title = '';
    $block->content = $output;

    return $block;
}