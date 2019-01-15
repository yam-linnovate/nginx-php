<?php
/**
 * @file
 * rp_feature_opinion.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function rp_feature_opinion_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_content|node|opinion|form';
  $field_group->group_name = 'group_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'opinion';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'תוכן',
    'weight' => '0',
    'children' => array(
      0 => 'body',
      1 => 'field_front_page_intro',
      2 => 'field_front_page_title',
      3 => 'field_intro',
      4 => 'field_writer',
      5 => 'field_section',
      6 => 'field_hide_description',
      7 => 'title',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-content field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_content|node|opinion|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_pictures|node|opinion|form';
  $field_group->group_name = 'group_pictures';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'opinion';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'תמונות',
    'weight' => '1',
    'children' => array(
      0 => 'field_images',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-pictures field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_pictures|node|opinion|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('תוכן');
  t('תמונות');

  return $field_groups;
}
