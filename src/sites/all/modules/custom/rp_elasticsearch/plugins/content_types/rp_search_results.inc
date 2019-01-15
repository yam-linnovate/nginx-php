<?php
/**
 * Plugin info
 */
$plugin = array(
  'title' => t('Republish Search Results'),
  'single' => TRUE,
  'category' => array(t('Miscellaneous'), -9),
);

/**
 * Run-time rendering of the body of the block.
 */
function rp_elasticsearch_rp_search_results_content_type_render($subtype, $conf, $args, $context) {

  drupal_add_css(drupal_get_path('module', 'rp_elasticsearch') . '/css/rp_elasticsearch.css');
  drupal_add_js(drupal_get_path('module', 'rp_elasticsearch') . '/js/rp_elasticsearch.js');
  drupal_add_js('https://ajax.cdnjs.com/ajax/libs/mustache.js/0.7.0/mustache.min.js', 'external');

  $tpl = 'rp_elasticsearch';
  $img_prefix =  image_style_url('125x125', '');


  if(isset($conf['api'])){
        $content = new stdClass();
        return $content;
    }


    $block = new stdClass();
  $block->title = "";
  $block->content = '<div class="info"><span class="total-results"></span>' . t('Search results ') . '</div>' . theme($tpl, array('img_prefix' => $img_prefix));

  return $block;
}