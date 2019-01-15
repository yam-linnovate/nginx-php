<?php
/**
 * @file
 * rp_feature_daily_component.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function rp_feature_daily_component_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_image_default_styles().
 */
function rp_feature_daily_component_image_default_styles() {
  $styles = array();

  // Exported image style: area_354x195.
  $styles['area_354x195'] = array(
    'label' => 'area_354x195',
    'effects' => array(
      22 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 354,
          'height' => 195,
        ),
        'weight' => -10,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function rp_feature_daily_component_node_info() {
  $items = array(
    'daily_component' => array(
      'name' => t('הרכיב היומי'),
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
