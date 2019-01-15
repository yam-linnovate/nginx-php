<?php
/**
 * @file
 * rp_feature_hp_image.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function rp_feature_hp_image_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'hp_image';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'hp image';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'hp image';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'עוד';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Header: Global: Unfiltered text */
  $handler->display->display_options['header']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['header']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['content'] = '<a href="">View More > </a>';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: תמונה */
  $handler->display->display_options['fields']['field_hp_image_picture']['id'] = 'field_hp_image_picture';
  $handler->display->display_options['fields']['field_hp_image_picture']['table'] = 'field_data_field_hp_image_picture';
  $handler->display->display_options['fields']['field_hp_image_picture']['field'] = 'field_hp_image_picture';
  $handler->display->display_options['fields']['field_hp_image_picture']['label'] = '';
  $handler->display->display_options['fields']['field_hp_image_picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_hp_image_picture']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_hp_image_picture']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Content: תאור */
  $handler->display->display_options['fields']['field_hp_image_desc']['id'] = 'field_hp_image_desc';
  $handler->display->display_options['fields']['field_hp_image_desc']['table'] = 'field_data_field_hp_image_desc';
  $handler->display->display_options['fields']['field_hp_image_desc']['field'] = 'field_hp_image_desc';
  $handler->display->display_options['fields']['field_hp_image_desc']['label'] = '';
  $handler->display->display_options['fields']['field_hp_image_desc']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'hp_image' => 'hp_image',
  );
  /* Filter criterion: Content: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: תמונה */
  $handler->display->display_options['fields']['field_hp_image_picture']['id'] = 'field_hp_image_picture';
  $handler->display->display_options['fields']['field_hp_image_picture']['table'] = 'field_data_field_hp_image_picture';
  $handler->display->display_options['fields']['field_hp_image_picture']['field'] = 'field_hp_image_picture';
  $handler->display->display_options['fields']['field_hp_image_picture']['label'] = '';
  $handler->display->display_options['fields']['field_hp_image_picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_hp_image_picture']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_hp_image_picture']['settings'] = array(
    'image_style' => '1300x735',
    'image_link' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: תאור */
  $handler->display->display_options['fields']['field_hp_image_desc']['id'] = 'field_hp_image_desc';
  $handler->display->display_options['fields']['field_hp_image_desc']['table'] = 'field_data_field_hp_image_desc';
  $handler->display->display_options['fields']['field_hp_image_desc']['field'] = 'field_hp_image_desc';
  $handler->display->display_options['fields']['field_hp_image_desc']['label'] = '';
  $handler->display->display_options['fields']['field_hp_image_desc']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_hp_image_desc']['element_label_colon'] = FALSE;
  /* Field: Content: יחידה */
  $handler->display->display_options['fields']['field_unit']['id'] = 'field_unit';
  $handler->display->display_options['fields']['field_unit']['table'] = 'field_data_field_unit';
  $handler->display->display_options['fields']['field_unit']['field'] = 'field_unit';
  $handler->display->display_options['fields']['field_unit']['label'] = 'Unit';
  $handler->display->display_options['fields']['field_unit']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_unit']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_unit']['alter']['text'] = '<span class"unit">Unit: [field_unit]</span>';
  $handler->display->display_options['fields']['field_unit']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_unit']['delta_offset'] = '0';
  /* Field: Content: סיווג */
  $handler->display->display_options['fields']['field_cassification']['id'] = 'field_cassification';
  $handler->display->display_options['fields']['field_cassification']['table'] = 'field_data_field_cassification';
  $handler->display->display_options['fields']['field_cassification']['field'] = 'field_cassification';
  $handler->display->display_options['fields']['field_cassification']['label'] = 'Cassification';
  $handler->display->display_options['fields']['field_cassification']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_cassification']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_cassification']['alter']['text'] = '<span>Cassification: [field_cassification]</span>';
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = '';
  $handler->display->display_options['fields']['created']['exclude'] = TRUE;
  $handler->display->display_options['fields']['created']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['created']['alter']['text'] = '<span>[created]</span>';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'd.m.y';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['label'] = '';
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = '<div class="inner"><div class="ttl">[title]</div><p> [field_hp_image_desc] </p><div class="tax"> [field_cassification]  |  [field_unit]  |  [created] </div></div>';
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
  $translatables['hp_image'] = array(
    t('Master'),
    t('hp image'),
    t('עוד'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('<a href="">View More > </a>'),
    t('Block'),
    t('more'),
    t('Unit'),
    t('<span class"unit">Unit: [field_unit]</span>'),
    t('Cassification'),
    t('<span>Cassification: [field_cassification]</span>'),
    t('<span>[created]</span>'),
    t('<div class="inner"><div class="ttl">[title]</div><p> [field_hp_image_desc] </p><div class="tax"> [field_cassification]  |  [field_unit]  |  [created] </div></div>'),
  );
  $export['hp_image'] = $view;

  return $export;
}
