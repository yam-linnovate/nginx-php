<?php
/**
 * @file
 * rp_feature_article.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function rp_feature_article_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'articles';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'articles';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'עוד';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: תמונות */
  $handler->display->display_options['fields']['field_images']['id'] = 'field_images';
  $handler->display->display_options['fields']['field_images']['table'] = 'field_data_field_images';
  $handler->display->display_options['fields']['field_images']['field'] = 'field_images';
  $handler->display->display_options['fields']['field_images']['label'] = '';
  $handler->display->display_options['fields']['field_images']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_images']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['field_images']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_images']['type'] = 'field_collection_fields';
  $handler->display->display_options['fields']['field_images']['settings'] = array(
    'view_mode' => 'article_by_cat',
  );
  /* Field: Content: כותרת ראשית עמוד ראשי */
  $handler->display->display_options['fields']['field_front_page_title']['id'] = 'field_front_page_title';
  $handler->display->display_options['fields']['field_front_page_title']['table'] = 'field_data_field_front_page_title';
  $handler->display->display_options['fields']['field_front_page_title']['field'] = 'field_front_page_title';
  $handler->display->display_options['fields']['field_front_page_title']['label'] = '';
  $handler->display->display_options['fields']['field_front_page_title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_front_page_title']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['field_front_page_title']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: קטגוריה (field_section) */
  $handler->display->display_options['arguments']['field_section_tid']['id'] = 'field_section_tid';
  $handler->display->display_options['arguments']['field_section_tid']['table'] = 'field_data_field_section';
  $handler->display->display_options['arguments']['field_section_tid']['field'] = 'field_section_tid';
  $handler->display->display_options['arguments']['field_section_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_section_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_section_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_section_tid']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['not'] = TRUE;
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
    'article' => 'article',
  );

  /* Display: 3 articles by  category */
  $handler = $view->new_display('block', '3 articles by  category', 'block_1');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: תמונות */
  $handler->display->display_options['fields']['field_images']['id'] = 'field_images';
  $handler->display->display_options['fields']['field_images']['table'] = 'field_data_field_images';
  $handler->display->display_options['fields']['field_images']['field'] = 'field_images';
  $handler->display->display_options['fields']['field_images']['label'] = '';
  $handler->display->display_options['fields']['field_images']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_images']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['field_images']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_images']['type'] = 'field_collection_fields';
  $handler->display->display_options['fields']['field_images']['settings'] = array(
    'view_mode' => 'article_by_cat',
  );
  /* Field: Content: כותרת ראשית עמוד ראשי */
  $handler->display->display_options['fields']['field_front_page_title']['id'] = 'field_front_page_title';
  $handler->display->display_options['fields']['field_front_page_title']['table'] = 'field_data_field_front_page_title';
  $handler->display->display_options['fields']['field_front_page_title']['field'] = 'field_front_page_title';
  $handler->display->display_options['fields']['field_front_page_title']['label'] = '';
  $handler->display->display_options['fields']['field_front_page_title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_front_page_title']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['field_front_page_title']['element_type'] = 'h3';
  $handler->display->display_options['fields']['field_front_page_title']['element_label_colon'] = FALSE;

  /* Display: 5 last articles */
  $handler = $view->new_display('block', '5 last articles', 'block_2');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: תמונות */
  $handler->display->display_options['fields']['field_images']['id'] = 'field_images';
  $handler->display->display_options['fields']['field_images']['table'] = 'field_data_field_images';
  $handler->display->display_options['fields']['field_images']['field'] = 'field_images';
  $handler->display->display_options['fields']['field_images']['label'] = '';
  $handler->display->display_options['fields']['field_images']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_images']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['field_images']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_images']['type'] = 'field_collection_fields';
  $handler->display->display_options['fields']['field_images']['settings'] = array(
    'view_mode' => 'last_articles',
  );
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['type']['alter']['text'] = '<div class="[type] icon"><span class="icon"></span></div>';
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['type']['machine_name'] = TRUE;
  /* Field: Content: כותרת ראשית עמוד ראשי */
  $handler->display->display_options['fields']['field_front_page_title']['id'] = 'field_front_page_title';
  $handler->display->display_options['fields']['field_front_page_title']['table'] = 'field_data_field_front_page_title';
  $handler->display->display_options['fields']['field_front_page_title']['field'] = 'field_front_page_title';
  $handler->display->display_options['fields']['field_front_page_title']['label'] = '';
  $handler->display->display_options['fields']['field_front_page_title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_front_page_title']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['field_front_page_title']['element_label_colon'] = FALSE;
  /* Field: Content: מאת */
  $handler->display->display_options['fields']['field_writer']['id'] = 'field_writer';
  $handler->display->display_options['fields']['field_writer']['table'] = 'field_data_field_writer';
  $handler->display->display_options['fields']['field_writer']['field'] = 'field_writer';
  $handler->display->display_options['fields']['field_writer']['label'] = '';
  $handler->display->display_options['fields']['field_writer']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_writer']['delta_offset'] = '0';
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = '';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'd.m.y';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['break_phrase'] = TRUE;
  $handler->display->display_options['arguments']['nid']['not'] = TRUE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid_1']['id'] = 'nid_1';
  $handler->display->display_options['arguments']['nid_1']['table'] = 'node';
  $handler->display->display_options['arguments']['nid_1']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid_1']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid_1']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid_1']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid_1']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid_1']['not'] = TRUE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid_2']['id'] = 'nid_2';
  $handler->display->display_options['arguments']['nid_2']['table'] = 'node';
  $handler->display->display_options['arguments']['nid_2']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid_2']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid_2']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid_2']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid_2']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid_2']['not'] = TRUE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid_3']['id'] = 'nid_3';
  $handler->display->display_options['arguments']['nid_3']['table'] = 'node';
  $handler->display->display_options['arguments']['nid_3']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid_3']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid_3']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid_3']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid_3']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid_3']['not'] = TRUE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    'video' => 'video',
    'article' => 'article',
  );

  /* Display: 4 articles by category */
  $handler = $view->new_display('block', '4 articles by category', 'block_3');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '4';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: תמונות */
  $handler->display->display_options['fields']['field_images']['id'] = 'field_images';
  $handler->display->display_options['fields']['field_images']['table'] = 'field_data_field_images';
  $handler->display->display_options['fields']['field_images']['field'] = 'field_images';
  $handler->display->display_options['fields']['field_images']['label'] = '';
  $handler->display->display_options['fields']['field_images']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_images']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['field_images']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_images']['type'] = 'field_collection_fields';
  $handler->display->display_options['fields']['field_images']['settings'] = array(
    'view_mode' => 'hp_large_video',
  );
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['type']['alter']['text'] = '<div class="[type] icon"><span class="icon"></span></div>';
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['type']['machine_name'] = TRUE;
  /* Field: Content: כותרת ראשית עמוד ראשי */
  $handler->display->display_options['fields']['field_front_page_title']['id'] = 'field_front_page_title';
  $handler->display->display_options['fields']['field_front_page_title']['table'] = 'field_data_field_front_page_title';
  $handler->display->display_options['fields']['field_front_page_title']['field'] = 'field_front_page_title';
  $handler->display->display_options['fields']['field_front_page_title']['label'] = '';
  $handler->display->display_options['fields']['field_front_page_title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_front_page_title']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['field_front_page_title']['element_label_colon'] = FALSE;
  /* Field: Content: מאת */
  $handler->display->display_options['fields']['field_writer']['id'] = 'field_writer';
  $handler->display->display_options['fields']['field_writer']['table'] = 'field_data_field_writer';
  $handler->display->display_options['fields']['field_writer']['field'] = 'field_writer';
  $handler->display->display_options['fields']['field_writer']['label'] = '';
  $handler->display->display_options['fields']['field_writer']['element_label_colon'] = FALSE;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = '';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'd.m.y';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    'video' => 'video',
    'article' => 'article',
  );
  $translatables['articles'] = array(
    t('Master'),
    t('עוד'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('All'),
    t('3 articles by  category'),
    t('more'),
    t('5 last articles'),
    t('<div class="[type] icon"><span class="icon"></span></div>'),
    t('4 articles by category'),
  );
  $export['articles'] = $view;

  return $export;
}
