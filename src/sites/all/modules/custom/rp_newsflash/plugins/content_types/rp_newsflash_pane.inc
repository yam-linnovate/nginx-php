<?php
/**
 * Plugin info
 */
$plugin = array(
  'title' => t('No Cache Newsflash'),
  'single' => TRUE,
  'category' => array(t('Front Page'), -9),
);

/**
 * Run-time rendering of the body of the block.
 */
function rp_newsflash_rp_newsflash_pane_content_type_render($subtype, $conf, $args, $context) {
    $output = '<div class="pane-newsflash-wrapper" id="pane-newsflash-wrapper"></div>';
    $content = new stdClass();
    $view = views_get_view('newsflash');
    // if($conf['vertical']){
    //     $view->set_display('page_1');
    // }
    // if($conf['horizontal']){
    //     $view->set_display('page_1');
    // }

    //$view->execute();

    foreach ($view->result as $key => $value) {
        $index = $key + 1;
        $content->node_id[$index] = $value->nid;
    }
    //store_pane_content('rp_newsflash_pane', $content);

  if(isset($conf['api'])){
        return $content;
    }


    $block = new stdClass();
    $block->title = $conf['title'];
    $block->content = $output;

    return $block;
}


function rp_newsflash_rp_newsflash_pane_content_type_edit_form($form, &$form_state) {
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
    $form['vertical'] = array(
		'#type' => 'checkbox',
		'#title' => t('Vertical'),
		'#maxlength' => 512,
		'#default_value' => !empty($conf['vertical']) ? $conf['vertical'] : '',
    );
    $form['horizontal'] = array(
		'#type' => 'checkbox',
		'#title' => t('Horizontal'),
		'#maxlength' => 512,
		'#default_value' => !empty($conf['horizontal']) ? $conf['horizontal'] : '',
	);
    return $form;
}

function rp_newsflash_rp_newsflash_pane_content_type_edit_form_submit($form, &$form_state){
    $form_state['conf']['title'] = $form_state['values']['title'];  
    $form_state['conf']['vertical'] = $form_state['values']['vertical']; 
    $form_state['conf']['horizontal'] = $form_state['values']['horizontal'];  
}