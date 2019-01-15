<?php
/**
 * @file
 * rp_feature_head_to_head.features.inc
 */

/**
 * Implements hook_node_info().
 */
function rp_feature_head_to_head_node_info() {
  $items = array(
    'head_to_head' => array(
      'name' => t('ראש בראש'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
