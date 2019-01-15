<?php
/**
 * Plugin info
 */
$plugin = array(
  'title' => t('Most Viewed Opinions'),
  'single' => TRUE,
  'category' => array(t('Front Page'), -9),
);

/**
 * Run-time rendering of the body of the block.
 */
function rp_google_analytics_most_viewed_opinions_content_type_render($subtype, $conf, $args, $context) {
	$output = '';
  $link = '';
  if($conf['link'] && $conf['link_title']){
    $link = '<a class="view-more" href="' . $conf['link'] . '">' . t($conf['link_title']) . '</a>';
  }
  if($conf['title'])
    $output .= '<h2 class="pane-title">' . t($conf['title'])  . '</h2>';
  
  $output .= '<div id="most-viewed-opinions-wrapper"></div>';
  
	
  $output .= '<div class="link-bottom"><hr>' . $link . '</div>';

  $block = new stdClass();
  $block->title = '';
  $block->content = $output;

  return $block;
}

function rp_google_analytics_most_viewed_opinions_content_type_edit_form($form, &$form_state) {
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
	return $form;
}
function rp_google_analytics_most_viewed_opinions_content_type_edit_form_submit($form, &$form_state){
    $form_state['conf']['title'] = $form_state['values']['title'];    
    $form_state['conf']['link'] = $form_state['values']['link'];    
    $form_state['conf']['link_title'] = $form_state['values']['link_title'];    
}
