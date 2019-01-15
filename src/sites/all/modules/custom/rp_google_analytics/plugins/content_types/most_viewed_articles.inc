<?php
/**
 * Plugin info
 */
$plugin = array(
  'title' => t('Most Viewed Articles'),
  'single' => TRUE,
  'category' => array(t('Front Page'), -9),
);

/**
 * Run-time rendering of the body of the block.
 */
function rp_google_analytics_most_viewed_articles_content_type_render($subtype, $conf, $args, $context) {
  	$output = '';
    if($conf['title'])
      $output .= '<h2 class="pane-title">' . t($conf['title']) . '</h2>';
    $output .= '<div id="most-viewed-articles-wrapper"></div>';

    $block = new stdClass();
    $block->title = '';
    $block->content = $output;

    return $block;
}

function rp_google_analytics_most_viewed_articles_content_type_edit_form($form, &$form_state) {
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
	return $form;
}
function rp_google_analytics_most_viewed_articles_content_type_edit_form_submit($form, &$form_state){
    $form_state['conf']['title'] = $form_state['values']['title'];    
}