<?php
/**
 * @file
 * rp_feature_event.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function rp_feature_event_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'event_panel';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'event_panel';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'event_panel';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'עוד';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
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
  /* Filter criterion: Content: הצג בפאנל ארועים (field_show_pane_event) */
  $handler->display->display_options['filters']['field_show_pane_event_value']['id'] = 'field_show_pane_event_value';
  $handler->display->display_options['filters']['field_show_pane_event_value']['table'] = 'field_data_field_show_pane_event';
  $handler->display->display_options['filters']['field_show_pane_event_value']['field'] = 'field_show_pane_event_value';
  $handler->display->display_options['filters']['field_show_pane_event_value']['value'] = array(
    1 => '1',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $translatables['event_panel'] = array(
    t('Master'),
    t('event_panel'),
    t('עוד'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Block'),
    t('more'),
  );
  $export['event_panel'] = $view;

  $view = new view();
  $view->name = 'events';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'events';
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
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'איתחול';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'bxslider';
  $handler->display->display_options['style_options']['settings'] = array(
    'general' => array(
      'mode' => 'vertical',
      'speed' => '500',
      'slideMargin' => '0',
      'startSlide' => '0',
      'randomStart' => 0,
      'infiniteLoop' => 1,
      'hideControlOnEnd' => 1,
      'captions' => 0,
      'ticker' => 1,
      'tickerHover' => 1,
      'adaptiveHeight' => 1,
      'adaptiveHeightSpeed' => '500',
      'video' => 0,
      'touchEnabled' => 1,
      'preloadImages' => 'visible',
      'disable_standard_css' => 0,
      'useCSS' => 0,
      'align_image' => 'left',
      'align_caption' => 'left',
      'swipeThreshold' => '50',
      'oneToOneTouch' => 1,
      'preventDefaultSwipeX' => 1,
      'preventDefaultSwipeY' => 1,
      'color_caption' => '80, 80, 80, 0.75',
    ),
    'controlsfieldset' => array(
      'controls' => 0,
      'nextText' => 'Next',
      'prevText' => 'Next',
      'startText' => 'Start',
      'stopText' => 'Stop',
      'autoControls' => 0,
      'autoControlsCombine' => 0,
    ),
    'pagerfieldset' => array(
      'pager' => 0,
      'pagerType' => 'full',
      'pagerShortSeparator' => ' / ',
    ),
    'autofieldset' => array(
      'pause' => '0',
      'autoStart' => 1,
      'auto' => 1,
      'autoHover' => 1,
      'autoDelay' => '0',
      'autoDirection' => 'next',
    ),
    'carousel' => array(
      'minSlides' => '5',
      'maxSlides' => '5',
      'moveSlides' => '5',
      'slideWidth' => '0',
    ),
    'callback' => array(
      'onSliderLoad' => '',
      'onSlideBefore' => '',
      'onSlideAfter' => '',
      'onSlideNext' => '',
      'onSlidePrev' => '',
    ),
  );
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = '';
  $handler->display->display_options['fields']['created']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['created']['alter']['text'] = '[created]  |  ';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'h:m';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Field: Content: תוכן */
  $handler->display->display_options['fields']['field_newsflash']['id'] = 'field_newsflash';
  $handler->display->display_options['fields']['field_newsflash']['table'] = 'field_data_field_newsflash';
  $handler->display->display_options['fields']['field_newsflash']['field'] = 'field_newsflash';
  $handler->display->display_options['fields']['field_newsflash']['label'] = '';
  $handler->display->display_options['fields']['field_newsflash']['alter']['path'] = '[field_newsflash_link]';
  $handler->display->display_options['fields']['field_newsflash']['alter']['max_length'] = '65';
  $handler->display->display_options['fields']['field_newsflash']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['field_newsflash']['element_label_colon'] = FALSE;
  /* Field: Content: תוכן */
  $handler->display->display_options['fields']['field_newsflash_1']['id'] = 'field_newsflash_1';
  $handler->display->display_options['fields']['field_newsflash_1']['table'] = 'field_data_field_newsflash';
  $handler->display->display_options['fields']['field_newsflash_1']['field'] = 'field_newsflash';
  $handler->display->display_options['fields']['field_newsflash_1']['label'] = '';
  $handler->display->display_options['fields']['field_newsflash_1']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: תאריך (field_event_date) */
  $handler->display->display_options['sorts']['field_event_date_value']['id'] = 'field_event_date_value';
  $handler->display->display_options['sorts']['field_event_date_value']['table'] = 'field_data_field_event_date';
  $handler->display->display_options['sorts']['field_event_date_value']['field'] = 'field_event_date_value';
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
    'newsflash' => 'newsflash',
  );
  /* Filter criterion: Content: הצג בלוח מבזקי חדשות בצד (field_show_newsflash_sidebar) */
  $handler->display->display_options['filters']['field_show_newsflash_sidebar_value']['id'] = 'field_show_newsflash_sidebar_value';
  $handler->display->display_options['filters']['field_show_newsflash_sidebar_value']['table'] = 'field_data_field_show_newsflash_sidebar';
  $handler->display->display_options['filters']['field_show_newsflash_sidebar_value']['field'] = 'field_show_newsflash_sidebar_value';
  $handler->display->display_options['filters']['field_show_newsflash_sidebar_value']['value'] = array(
    1 => '1',
  );
  /* Filter criterion: Content: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
  );

  /* Display: בלוק */
  $handler = $view->new_display('block', 'בלוק', 'block_1');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;

  /* Display: Content pane */
  $handler = $view->new_display('panel_pane', 'Content pane', 'panel_pane_1');
  $translatables['events'] = array(
    t('Master'),
    t('עוד'),
    t('Apply'),
    t('איתחול'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('[created]  |  '),
    t('בלוק'),
    t('more'),
    t('Content pane'),
    t('View panes'),
  );
  $export['events'] = $view;

  return $export;
}
