<?php
/**
 * Plugin info
 */
$plugin = array(
  'title' => t('Smart banner'),
  'single' => TRUE,
  'category' => array(t('Front Page'), -9),
);

/**
 * Run-time rendering of the body of the block.
 */
function rp_smart_banner_rp_smart_banner_content_type_render($subtype, $conf, $args, $context) {
	$path = drupal_get_path('module', 'rp_smart_banner');
  global $base_url;
  	$output = '';
    $output .= '<div id="smart-banner-wrapper">
    	<div class="smart-banner-close">&#x2716;</div>
    	<div class="smart-banner-image"><img src="' . $base_url . '/' . $path . '/images/logo.jpg"></div>
      <div class="middle">
        <div class="smart-banner-title">מרכז הנדל"ן</div>
        <div class="smart-banner-text">חדשות, אנשים, עסקאות בעולם הנדל"ן</div>
        <div class="smart-banner-statistics">
          <div class="smart-banner-rating rating-container">
            <div class="rating-stars">
              <span class="rating">&nbsp;</span>
            </div>
          </div>
          <svg width="0" height="0"><defs><clipPath id="svgStars" clipPathUnits = "objectBoundingBox"><polygon points=".80 .073 .738 .118 .762 .19 .70 .145 .638 .19 .662 .118 .60 .073 .538 .118 .562 .19 .50 .145 .438 .19 .462 .118 .40 .073 .338 .118 .362 .19 .30 .145 .238 .19 .262 .118 .20 .073 .138 .118 .162 .19 .10 .145 .038 .19 .062 .118 0 .073 .076 .073 .10 0 .124 .073 .276 .073 .30 0 .324 .073 .476 .073 .50 0 .524 .073 .676 .073 .70 0 .724 .073 .876 .073 .90 0 .924 .073 1 .073 .938 .118 .962 .19 .90 .145 .838 .19 .862 .118 "/></clipPath></defs></svg>
          <div class="smart-banner-downloads"></div>
        </div>
      </div>
    	<div class="smart-banner-button"><a href="http:/">פתח</a></div>
    </div>';

    $block = new stdClass();
    $block->title = '';
    $block->content = $output;

    return $block;
}