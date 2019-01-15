<?php
/**
 * @file
 * rp_feature_daily_component.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function rp_feature_daily_component_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_area|node|daily_component|form';
  $field_group->group_name = 'group_area';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'daily_component';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'גיזרה',
    'weight' => '6',
    'children' => array(
      0 => 'field_area',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-area field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_area|node|daily_component|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_attached_files|node|daily_component|form';
  $field_group->group_name = 'group_attached_files';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'daily_component';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'קבצים מצורפים',
    'weight' => '5',
    'children' => array(
      0 => 'field_attached_files',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-attached-files field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_attached_files|node|daily_component|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_details|node|daily_component|form';
  $field_group->group_name = 'group_details';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'daily_component';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'פרטים',
    'weight' => '7',
    'children' => array(
      0 => 'field_cassification',
      1 => 'field_extra_details',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-details field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_details|node|daily_component|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('גיזרה');
  t('פרטים');
  t('קבצים מצורפים');

  return $field_groups;
}
