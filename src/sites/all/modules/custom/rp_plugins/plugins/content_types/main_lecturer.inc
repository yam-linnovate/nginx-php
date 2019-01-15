<?php
/**
 * Plugin info
 */
$plugin = array(
  'title' => t('Main lecturer'),
  'single' => TRUE,
  'category' => array(t('Lecturer Page'), -10),
);

/**
 * Run-time rendering of the body of the block.
 */
function rp_plugins_main_lecturer_content_type_render($subtype, $conf, $args, $context) {
    $content = new stdClass();
    drupal_add_js(drupal_get_path('module', 'rp_plugins') . '/js/jquery.quicksearch.js');
  drupal_add_js(drupal_get_path('module', 'rp_plugins') . '/js/search.js');
  $output = '<div id="search-filters" class="clearfix">
					<div class="filter-wrapper" id="all-wrapper">
						<div id="all-option" class="filter" tag="all">כל הסגל </div>
						<div id="l-option" class="filter" tag="מנהל אקדמי"> מנהלים אקדמיים </div>
						<div id="m-option" class="filter" tag="מרצה">מרצים</div>
					</div>
				</div>
				<form action="#" id="filterer" class="quicksearch">
				<label for="freetext" class="qs_label">DEV ONLY</label> 
				<input type="text" value="" rel="freetext" class="qs_input" id="freetext"> 
				</form>
				';
  $view = views_get_view('faculty_page');
  $view->set_display('page');
  $view->execute();
  if (!empty($view->result)) {
    $output .= $view->preview();
  }

  if(isset($conf['api'])){
        return $content;
    }


    $block = new stdClass();
  $block->title = '';
  $block->content = $output;

  return $block;

}