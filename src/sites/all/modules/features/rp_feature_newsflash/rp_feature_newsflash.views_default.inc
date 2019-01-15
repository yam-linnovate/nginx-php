<?php
/**
 * @file
 * rp_feature_newsflash.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function rp_feature_newsflash_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'newsflash';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'newsflash';
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
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'bxslider';
  $handler->display->display_options['style_options']['settings'] = array(
    'general' => array(
      'mode' => 'horizontal',
      'speed' => '500',
      'slideMargin' => '0',
      'startSlide' => '0',
      'randomStart' => 0,
      'infiniteLoop' => 1,
      'hideControlOnEnd' => 1,
      'captions' => 0,
      'ticker' => 0,
      'tickerHover' => 0,
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
      'preventDefaultSwipeY' => 0,
      'color_caption' => '80, 80, 80, 0.75',
    ),
    'controlsfieldset' => array(
      'controls' => 1,
      'nextText' => 'Next',
      'prevText' => 'Prev',
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
      'pause' => '4000',
      'autoStart' => 0,
      'auto' => 0,
      'autoHover' => 0,
      'autoDelay' => '0',
      'autoDirection' => 'next',
    ),
    'carousel' => array(
      'minSlides' => '1',
      'maxSlides' => '1',
      'moveSlides' => '0',
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
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = '';
  $handler->display->display_options['fields']['created']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['created']['alter']['text'] = '([created])';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'h:m';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Field: Content: תוכן */
  $handler->display->display_options['fields']['field_newsflash']['id'] = 'field_newsflash';
  $handler->display->display_options['fields']['field_newsflash']['table'] = 'field_data_field_newsflash';
  $handler->display->display_options['fields']['field_newsflash']['field'] = 'field_newsflash';
  $handler->display->display_options['fields']['field_newsflash']['label'] = '';
  $handler->display->display_options['fields']['field_newsflash']['alter']['max_length'] = '65';
  $handler->display->display_options['fields']['field_newsflash']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['field_newsflash']['element_label_colon'] = FALSE;
  /* Field: Content: תוכן */
  $handler->display->display_options['fields']['field_newsflash_1']['id'] = 'field_newsflash_1';
  $handler->display->display_options['fields']['field_newsflash_1']['table'] = 'field_data_field_newsflash';
  $handler->display->display_options['fields']['field_newsflash_1']['field'] = 'field_newsflash';
  $handler->display->display_options['fields']['field_newsflash_1']['label'] = '';
  $handler->display->display_options['fields']['field_newsflash_1']['element_label_colon'] = FALSE;
  /* Field: Content: יחידה */
  $handler->display->display_options['fields']['field_unit']['id'] = 'field_unit';
  $handler->display->display_options['fields']['field_unit']['table'] = 'field_data_field_unit';
  $handler->display->display_options['fields']['field_unit']['field'] = 'field_unit';
  $handler->display->display_options['fields']['field_unit']['label'] = '';
  $handler->display->display_options['fields']['field_unit']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_unit']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_unit']['delta_offset'] = '0';
  /* Field: Content: סיווג */
  $handler->display->display_options['fields']['field_cassification']['id'] = 'field_cassification';
  $handler->display->display_options['fields']['field_cassification']['table'] = 'field_data_field_cassification';
  $handler->display->display_options['fields']['field_cassification']['field'] = 'field_cassification';
  $handler->display->display_options['fields']['field_cassification']['label'] = '';
  $handler->display->display_options['fields']['field_cassification']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_cassification']['element_label_colon'] = FALSE;
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
  /* Filter criterion: Content: להסיר מפרסום מתאריך  (field_newsflash_datetime) */
  $handler->display->display_options['filters']['field_newsflash_datetime_value']['id'] = 'field_newsflash_datetime_value';
  $handler->display->display_options['filters']['field_newsflash_datetime_value']['table'] = 'field_data_field_newsflash_datetime';
  $handler->display->display_options['filters']['field_newsflash_datetime_value']['field'] = 'field_newsflash_datetime_value';
  $handler->display->display_options['filters']['field_newsflash_datetime_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_newsflash_datetime_value']['default_date'] = 'now';
  /* Filter criterion: Content: הצג בלוח מבזקי חדשות (field_show_newsflash) */
  $handler->display->display_options['filters']['field_show_newsflash_value']['id'] = 'field_show_newsflash_value';
  $handler->display->display_options['filters']['field_show_newsflash_value']['table'] = 'field_data_field_show_newsflash';
  $handler->display->display_options['filters']['field_show_newsflash_value']['field'] = 'field_show_newsflash_value';
  $handler->display->display_options['filters']['field_show_newsflash_value']['value'] = array(
    1 => '1',
  );

  /* Display: Content pane */
  $handler = $view->new_display('panel_pane', 'Content pane', 'panel_pane_1');
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
    'newsflash' => 'newsflash',
  );
  /* Filter criterion: Content: להסיר מפרסום מתאריך  (field_newsflash_datetime) */
  $handler->display->display_options['filters']['field_newsflash_datetime_value']['id'] = 'field_newsflash_datetime_value';
  $handler->display->display_options['filters']['field_newsflash_datetime_value']['table'] = 'field_data_field_newsflash_datetime';
  $handler->display->display_options['filters']['field_newsflash_datetime_value']['field'] = 'field_newsflash_datetime_value';
  $handler->display->display_options['filters']['field_newsflash_datetime_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_newsflash_datetime_value']['default_date'] = 'now';
  /* Filter criterion: Content: הצג בלוח מבזקי חדשות (field_show_newsflash) */
  $handler->display->display_options['filters']['field_show_newsflash_value']['id'] = 'field_show_newsflash_value';
  $handler->display->display_options['filters']['field_show_newsflash_value']['table'] = 'field_data_field_show_newsflash';
  $handler->display->display_options['filters']['field_show_newsflash_value']['field'] = 'field_show_newsflash_value';
  $handler->display->display_options['filters']['field_show_newsflash_value']['value'] = array(
    1 => '1',
  );
  /* Filter criterion: Content: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
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
    'newsflash' => 'newsflash',
  );
  /* Filter criterion: Content: להסיר מפרסום מתאריך  (field_newsflash_datetime) */
  $handler->display->display_options['filters']['field_newsflash_datetime_value']['id'] = 'field_newsflash_datetime_value';
  $handler->display->display_options['filters']['field_newsflash_datetime_value']['table'] = 'field_data_field_newsflash_datetime';
  $handler->display->display_options['filters']['field_newsflash_datetime_value']['field'] = 'field_newsflash_datetime_value';
  $handler->display->display_options['filters']['field_newsflash_datetime_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_newsflash_datetime_value']['default_date'] = 'now';
  /* Filter criterion: Content: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
  );
  /* Filter criterion: Content: הצג בלוח מבזקי חדשות בצד (field_show_newsflash_sidebar) */
  $handler->display->display_options['filters']['field_show_newsflash_sidebar_value']['id'] = 'field_show_newsflash_sidebar_value';
  $handler->display->display_options['filters']['field_show_newsflash_sidebar_value']['table'] = 'field_data_field_show_newsflash_sidebar';
  $handler->display->display_options['filters']['field_show_newsflash_sidebar_value']['field'] = 'field_show_newsflash_sidebar_value';
  $handler->display->display_options['filters']['field_show_newsflash_sidebar_value']['value'] = array(
    1 => '1',
  );
  $translatables['newsflash'] = array(
    t('Master'),
    t('עוד'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('([created])'),
    t('Content pane'),
    t('more'),
    t('View panes'),
    t('Block'),
  );
  $export['newsflash'] = $view;

  return $export;
}
