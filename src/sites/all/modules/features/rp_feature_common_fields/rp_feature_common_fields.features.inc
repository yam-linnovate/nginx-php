<?php
/**
 * @file
 * rp_feature_common_fields.features.inc
 */

/**
 * Implements hook_node_info().
 */
function rp_feature_common_fields_node_info() {
  $items = array(
    'node_special_projects' => array(
      'name' => t('פרוייקטים מיוחדים'),
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
