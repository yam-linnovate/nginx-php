<?php
/**
 * @file
 * rp_feature_jobs.features.inc
 */

/**
 * Implements hook_views_api().
 */
function rp_feature_jobs_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function rp_feature_jobs_node_info() {
  $items = array(
    'job' => array(
      'name' => t('משרה'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('תאור משרה'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
