<?php
/**
 * @file
 * rp_feature_newsflash.features.inc
 */

/**
 * Implements hook_views_api().
 */
function rp_feature_newsflash_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function rp_feature_newsflash_node_info() {
  $items = array(
    'newsflash' => array(
      'name' => t('מבזק חדשות'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('כותרת'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
