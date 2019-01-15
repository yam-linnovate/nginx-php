<?php
/**
 * @file
 * rp_feature_jobs.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function rp_feature_jobs_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'jobs';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'jobs';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'jobs';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'עוד';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '7';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Content: Taxonomy terms on node */
  $handler->display->display_options['relationships']['term_node_tid']['id'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['table'] = 'node';
  $handler->display->display_options['relationships']['term_node_tid']['field'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['vocabularies'] = array(
    'company' => 'company',
    'writer' => 0,
    'lecturer' => 0,
    'section' => 0,
    'jobs_category' => 0,
    'tags' => 0,
  );
  /* Field: Content: גודל משרה */
  $handler->display->display_options['fields']['field_jobs_size']['id'] = 'field_jobs_size';
  $handler->display->display_options['fields']['field_jobs_size']['table'] = 'field_data_field_jobs_size';
  $handler->display->display_options['fields']['field_jobs_size']['field'] = 'field_jobs_size';
  $handler->display->display_options['fields']['field_jobs_size']['label'] = '';
  $handler->display->display_options['fields']['field_jobs_size']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: נסיון */
  $handler->display->display_options['fields']['field_experience']['id'] = 'field_experience';
  $handler->display->display_options['fields']['field_experience']['table'] = 'field_data_field_experience';
  $handler->display->display_options['fields']['field_experience']['field'] = 'field_experience';
  $handler->display->display_options['fields']['field_experience']['label'] = '';
  $handler->display->display_options['fields']['field_experience']['element_label_colon'] = FALSE;
  /* Field: Content: משרה בקטגוריה */
  $handler->display->display_options['fields']['field_category']['id'] = 'field_category';
  $handler->display->display_options['fields']['field_category']['table'] = 'field_data_field_category';
  $handler->display->display_options['fields']['field_category']['field'] = 'field_category';
  $handler->display->display_options['fields']['field_category']['label'] = '';
  $handler->display->display_options['fields']['field_category']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_category']['alter']['text'] = 'משרות בתחום [field_category]';
  $handler->display->display_options['fields']['field_category']['element_label_colon'] = FALSE;
  /* Field: Content: חברה */
  $handler->display->display_options['fields']['field_company']['id'] = 'field_company';
  $handler->display->display_options['fields']['field_company']['table'] = 'field_data_field_company';
  $handler->display->display_options['fields']['field_company']['field'] = 'field_company';
  $handler->display->display_options['fields']['field_company']['label'] = '';
  $handler->display->display_options['fields']['field_company']['element_label_colon'] = FALSE;
  /* Field: Content: מקושר לכתבה */
  $handler->display->display_options['fields']['field_ref_to_article']['id'] = 'field_ref_to_article';
  $handler->display->display_options['fields']['field_ref_to_article']['table'] = 'field_data_field_ref_to_article';
  $handler->display->display_options['fields']['field_ref_to_article']['field'] = 'field_ref_to_article';
  $handler->display->display_options['fields']['field_ref_to_article']['label'] = '';
  $handler->display->display_options['fields']['field_ref_to_article']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_ref_to_article']['settings'] = array(
    'bypass_access' => 0,
    'link' => 0,
  );
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Has taxonomy term ID */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
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
    'job' => 'job',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '0';
  $handler->display->display_options['pager']['options']['offset'] = '0';

  /* Display: jobs at company */
  $handler = $view->new_display('block', 'jobs at company', 'block_1');
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: חברה (field_company) */
  $handler->display->display_options['arguments']['field_company_tid']['id'] = 'field_company_tid';
  $handler->display->display_options['arguments']['field_company_tid']['table'] = 'field_data_field_company';
  $handler->display->display_options['arguments']['field_company_tid']['field'] = 'field_company_tid';
  $handler->display->display_options['arguments']['field_company_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_company_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_company_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_company_tid']['summary_options']['items_per_page'] = '25';

  /* Display: jobs home page */
  $handler = $view->new_display('block', 'jobs home page', 'block_2');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '4';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: מקושר לכתבה */
  $handler->display->display_options['fields']['field_ref_to_article']['id'] = 'field_ref_to_article';
  $handler->display->display_options['fields']['field_ref_to_article']['table'] = 'field_data_field_ref_to_article';
  $handler->display->display_options['fields']['field_ref_to_article']['field'] = 'field_ref_to_article';
  $handler->display->display_options['fields']['field_ref_to_article']['label'] = '';
  $handler->display->display_options['fields']['field_ref_to_article']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_ref_to_article']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_ref_to_article']['settings'] = array(
    'bypass_access' => 0,
    'link' => 0,
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['path'] = '[field_ref_to_article]';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Taxonomy term: location */
  $handler->display->display_options['fields']['field_location']['id'] = 'field_location';
  $handler->display->display_options['fields']['field_location']['table'] = 'field_data_field_location';
  $handler->display->display_options['fields']['field_location']['field'] = 'field_location';
  $handler->display->display_options['fields']['field_location']['relationship'] = 'term_node_tid';
  $handler->display->display_options['fields']['field_location']['label'] = '';
  $handler->display->display_options['fields']['field_location']['element_label_colon'] = FALSE;
  /* Field: Content: איזור בארץ */
  $handler->display->display_options['fields']['field_region_in_israel']['id'] = 'field_region_in_israel';
  $handler->display->display_options['fields']['field_region_in_israel']['table'] = 'field_data_field_region_in_israel';
  $handler->display->display_options['fields']['field_region_in_israel']['field'] = 'field_region_in_israel';
  $handler->display->display_options['fields']['field_region_in_israel']['label'] = '';
  $handler->display->display_options['fields']['field_region_in_israel']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_region_in_israel']['type'] = 'taxonomy_term_reference_link';
  $translatables['jobs'] = array(
    t('Master'),
    t('jobs'),
    t('עוד'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('term'),
    t('משרות בתחום [field_category]'),
    t('All'),
    t('Block'),
    t('jobs at company'),
    t('jobs home page'),
  );
  $export['jobs'] = $view;

  return $export;
}
