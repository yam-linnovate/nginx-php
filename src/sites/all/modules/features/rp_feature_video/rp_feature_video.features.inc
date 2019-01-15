<?php
/**
 * @file
 * rp_feature_video.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function rp_feature_video_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function rp_feature_video_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function rp_feature_video_node_info() {
  $items = array(
    'video' => array(
      'name' => t('וידאו'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('כותרת ראשית עמוד פנימי'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
