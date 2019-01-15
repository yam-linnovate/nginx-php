<?php
/**
 * @file
 * rp_feature_article.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function rp_feature_article_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_attached_files|node|article|form';
  $field_group->group_name = 'group_attached_files';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'article';
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
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-attached-files field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_attached_files|node|article|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_content|node|article|form';
  $field_group->group_name = 'group_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'article';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'תוכן',
    'weight' => '0',
    'children' => array(
      0 => 'body',
      1 => 'field_front_page_title',
      2 => 'field_pre_title',
      3 => 'field_writer',
      4 => 'field_section',
      5 => 'field_tags',
      6 => 'field_intro',
      7 => 'field_main_intro',
      8 => 'field_front_page_intro',
      9 => 'field_hide_description',
      10 => 'field_hide_image',
      11 => 'title',
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
  $field_groups['group_content|node|article|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_details|node|article|form';
  $field_group->group_name = 'group_details';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'article';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'פרטים',
    'weight' => '4',
    'children' => array(
      0 => 'field_cassification',
      1 => 'field_unit',
      2 => 'field_extra_details',
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
  $field_groups['group_details|node|article|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_pictures|node|article|form';
  $field_group->group_name = 'group_pictures';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'article';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'תמונות',
    'weight' => '2',
    'children' => array(
      0 => 'field_images',
      1 => 'field_video_file',
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
  $field_groups['group_pictures|node|article|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_quote|node|article|form';
  $field_group->group_name = 'group_quote';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'article';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'ציטוט',
    'weight' => '3',
    'children' => array(
      0 => 'field_quote_source',
      1 => 'field_quote_body',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-quote field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_quote|node|article|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('פרטים');
  t('ציטוט');
  t('קבצים מצורפים');
  t('תוכן');
  t('תמונות');

  return $field_groups;
}
