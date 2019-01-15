<?php
/**
 * @file
 * rp_feature_most_viewed_contnet.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function rp_feature_most_viewed_contnet_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'top_viewed_articles_videos';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'google_analytics';
  $view->human_name = 'top viewed articles & videos';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'עוד';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access google analytics reports';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'pageTitle' => 'pageTitle',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'pageTitle' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Field: Page Tracking: Page Title */
  $handler->display->display_options['fields']['pageTitle']['id'] = 'pageTitle';
  $handler->display->display_options['fields']['pageTitle']['table'] = 'google_analytics';
  $handler->display->display_options['fields']['pageTitle']['field'] = 'pageTitle';
  $handler->display->display_options['fields']['pageTitle']['label'] = '';
  $handler->display->display_options['fields']['pageTitle']['element_label_colon'] = FALSE;
  /* Field: Page Tracking: Pageviews */
  $handler->display->display_options['fields']['pageviews']['id'] = 'pageviews';
  $handler->display->display_options['fields']['pageviews']['table'] = 'google_analytics';
  $handler->display->display_options['fields']['pageviews']['field'] = 'pageviews';
  $handler->display->display_options['fields']['pageviews']['label'] = '';
  $handler->display->display_options['fields']['pageviews']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['pageviews']['precision'] = '0';
  /* Field: Page Tracking: Page */
  $handler->display->display_options['fields']['pagePath']['id'] = 'pagePath';
  $handler->display->display_options['fields']['pagePath']['table'] = 'google_analytics';
  $handler->display->display_options['fields']['pagePath']['field'] = 'pagePath';
  $handler->display->display_options['fields']['pagePath']['label'] = '';
  $handler->display->display_options['fields']['pagePath']['element_label_colon'] = FALSE;
  /* Sort criterion: Page Tracking: Pageviews */
  $handler->display->display_options['sorts']['pageviews']['id'] = 'pageviews';
  $handler->display->display_options['sorts']['pageviews']['table'] = 'google_analytics';
  $handler->display->display_options['sorts']['pageviews']['field'] = 'pageviews';
  $handler->display->display_options['sorts']['pageviews']['order'] = 'DESC';
  /* Filter criterion: Google Analytics: Start date of report */
  $handler->display->display_options['filters']['start_date']['id'] = 'start_date';
  $handler->display->display_options['filters']['start_date']['table'] = 'google_analytics';
  $handler->display->display_options['filters']['start_date']['field'] = 'start_date';
  $handler->display->display_options['filters']['start_date']['value']['value'] = '-31 day';
  $handler->display->display_options['filters']['start_date']['value']['type'] = 'offset';
  $handler->display->display_options['filters']['start_date']['group'] = 1;
  $handler->display->display_options['filters']['start_date']['expose']['operator'] = FALSE;
  /* Filter criterion: Google Analytics: End date of report */
  $handler->display->display_options['filters']['end_date']['id'] = 'end_date';
  $handler->display->display_options['filters']['end_date']['table'] = 'google_analytics';
  $handler->display->display_options['filters']['end_date']['field'] = 'end_date';
  $handler->display->display_options['filters']['end_date']['value']['value'] = '+1 day';
  $handler->display->display_options['filters']['end_date']['value']['type'] = 'offset';
  $handler->display->display_options['filters']['end_date']['group'] = 1;
  $handler->display->display_options['filters']['end_date']['expose']['operator'] = FALSE;
  /* Filter criterion: Page Tracking: Page */
  $handler->display->display_options['filters']['pagePath']['id'] = 'pagePath';
  $handler->display->display_options['filters']['pagePath']['table'] = 'google_analytics';
  $handler->display->display_options['filters']['pagePath']['field'] = 'pagePath';
  $handler->display->display_options['filters']['pagePath']['operator'] = 'regular_expression';
  $handler->display->display_options['filters']['pagePath']['value'] = 'opinion\\/.+';
  $handler->display->display_options['filters']['pagePath']['expose']['operator_id'] = 'pagePath_op';
  $handler->display->display_options['filters']['pagePath']['expose']['label'] = 'Page';
  $handler->display->display_options['filters']['pagePath']['expose']['operator'] = 'pagePath_op';
  $handler->display->display_options['filters']['pagePath']['expose']['identifier'] = 'pagePath';

  /* Display: top viewed articles & videos */
  $handler = $view->new_display('block', 'top viewed articles & videos', 'block');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Google Analytics: Start date of report */
  $handler->display->display_options['filters']['start_date']['id'] = 'start_date';
  $handler->display->display_options['filters']['start_date']['table'] = 'google_analytics';
  $handler->display->display_options['filters']['start_date']['field'] = 'start_date';
  $handler->display->display_options['filters']['start_date']['value']['value'] = '-31 day';
  $handler->display->display_options['filters']['start_date']['value']['type'] = 'offset';
  $handler->display->display_options['filters']['start_date']['group'] = 1;
  $handler->display->display_options['filters']['start_date']['expose']['operator'] = FALSE;
  /* Filter criterion: Google Analytics: End date of report */
  $handler->display->display_options['filters']['end_date']['id'] = 'end_date';
  $handler->display->display_options['filters']['end_date']['table'] = 'google_analytics';
  $handler->display->display_options['filters']['end_date']['field'] = 'end_date';
  $handler->display->display_options['filters']['end_date']['value']['value'] = '+1 day';
  $handler->display->display_options['filters']['end_date']['value']['type'] = 'offset';
  $handler->display->display_options['filters']['end_date']['group'] = 1;
  $handler->display->display_options['filters']['end_date']['expose']['operator'] = FALSE;
  /* Filter criterion: Page Tracking: Page */
  $handler->display->display_options['filters']['pagePath']['id'] = 'pagePath';
  $handler->display->display_options['filters']['pagePath']['table'] = 'google_analytics';
  $handler->display->display_options['filters']['pagePath']['field'] = 'pagePath';
  $handler->display->display_options['filters']['pagePath']['operator'] = 'regular_expression';
  $handler->display->display_options['filters']['pagePath']['value'] = 'video\\/.+|article\\/.+';
  $handler->display->display_options['block_caching'] = '-1';

  /* Display: top viewed videos */
  $handler = $view->new_display('block', 'top viewed videos', 'block_1');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '8';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Google Analytics: Start date of report */
  $handler->display->display_options['filters']['start_date']['id'] = 'start_date';
  $handler->display->display_options['filters']['start_date']['table'] = 'google_analytics';
  $handler->display->display_options['filters']['start_date']['field'] = 'start_date';
  $handler->display->display_options['filters']['start_date']['value']['value'] = '-31 day';
  $handler->display->display_options['filters']['start_date']['value']['type'] = 'offset';
  $handler->display->display_options['filters']['start_date']['group'] = 1;
  $handler->display->display_options['filters']['start_date']['expose']['operator'] = FALSE;
  /* Filter criterion: Google Analytics: End date of report */
  $handler->display->display_options['filters']['end_date']['id'] = 'end_date';
  $handler->display->display_options['filters']['end_date']['table'] = 'google_analytics';
  $handler->display->display_options['filters']['end_date']['field'] = 'end_date';
  $handler->display->display_options['filters']['end_date']['value']['value'] = '+1 day';
  $handler->display->display_options['filters']['end_date']['value']['type'] = 'offset';
  $handler->display->display_options['filters']['end_date']['group'] = 1;
  $handler->display->display_options['filters']['end_date']['expose']['operator'] = FALSE;
  /* Filter criterion: Page Tracking: Page */
  $handler->display->display_options['filters']['pagePath']['id'] = 'pagePath';
  $handler->display->display_options['filters']['pagePath']['table'] = 'google_analytics';
  $handler->display->display_options['filters']['pagePath']['field'] = 'pagePath';
  $handler->display->display_options['filters']['pagePath']['operator'] = 'regular_expression';
  $handler->display->display_options['filters']['pagePath']['value'] = 'video/.+';
  $handler->display->display_options['filters']['pagePath']['expose']['operator_id'] = 'pagePath_op';
  $handler->display->display_options['filters']['pagePath']['expose']['label'] = 'Page';
  $handler->display->display_options['filters']['pagePath']['expose']['operator'] = 'pagePath_op';
  $handler->display->display_options['filters']['pagePath']['expose']['identifier'] = 'pagePath';
  $handler->display->display_options['filters']['pagePath']['expose']['required'] = 0;
  $handler->display->display_options['filters']['pagePath']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['block_caching'] = '-1';

  /* Display: top viewed opinions */
  $handler = $view->new_display('block', 'top viewed opinions', 'block_2');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '4';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['block_caching'] = '-1';

  /* Display: top viewed videos mobile */
  $handler = $view->new_display('block', 'top viewed videos mobile', 'block_3');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Google Analytics: Start date of report */
  $handler->display->display_options['filters']['start_date']['id'] = 'start_date';
  $handler->display->display_options['filters']['start_date']['table'] = 'google_analytics';
  $handler->display->display_options['filters']['start_date']['field'] = 'start_date';
  $handler->display->display_options['filters']['start_date']['value']['value'] = '-31 day';
  $handler->display->display_options['filters']['start_date']['value']['type'] = 'offset';
  $handler->display->display_options['filters']['start_date']['group'] = 1;
  $handler->display->display_options['filters']['start_date']['expose']['operator'] = FALSE;
  /* Filter criterion: Google Analytics: End date of report */
  $handler->display->display_options['filters']['end_date']['id'] = 'end_date';
  $handler->display->display_options['filters']['end_date']['table'] = 'google_analytics';
  $handler->display->display_options['filters']['end_date']['field'] = 'end_date';
  $handler->display->display_options['filters']['end_date']['value']['value'] = '+1 day';
  $handler->display->display_options['filters']['end_date']['value']['type'] = 'offset';
  $handler->display->display_options['filters']['end_date']['group'] = 1;
  $handler->display->display_options['filters']['end_date']['expose']['operator'] = FALSE;
  /* Filter criterion: Page Tracking: Page */
  $handler->display->display_options['filters']['pagePath']['id'] = 'pagePath';
  $handler->display->display_options['filters']['pagePath']['table'] = 'google_analytics';
  $handler->display->display_options['filters']['pagePath']['field'] = 'pagePath';
  $handler->display->display_options['filters']['pagePath']['operator'] = 'regular_expression';
  $handler->display->display_options['filters']['pagePath']['value'] = 'video/.+';
  $handler->display->display_options['filters']['pagePath']['expose']['operator_id'] = 'pagePath_op';
  $handler->display->display_options['filters']['pagePath']['expose']['label'] = 'Page';
  $handler->display->display_options['filters']['pagePath']['expose']['operator'] = 'pagePath_op';
  $handler->display->display_options['filters']['pagePath']['expose']['identifier'] = 'pagePath';
  $handler->display->display_options['filters']['pagePath']['expose']['required'] = 0;
  $handler->display->display_options['filters']['pagePath']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['block_caching'] = '-1';
  $translatables['top_viewed_articles_videos'] = array(
    t('Master'),
    t('עוד'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('.'),
    t(','),
    t('Page'),
    t('top viewed articles & videos'),
    t('top viewed videos'),
    t('top viewed opinions'),
    t('top viewed videos mobile'),
  );
  $export['top_viewed_articles_videos'] = $view;

  return $export;
}
