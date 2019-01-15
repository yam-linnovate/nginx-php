<?php
/**
 * @file
 * rp_feature_daily_component.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function rp_feature_daily_component_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view__panel_context_91287373-9079-4068-867a-9cb18cb09f0c';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 4;
  $handler->conf = array(
    'title' => 'daily component',
    'no_blocks' => 0,
    'pipeline' => 'ipe',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => '',
    'access' => array(
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'twocol_66_33';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'header' => NULL,
      'main_right' => NULL,
      'main_left' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '3de0799a-6166-4726-b458-4d656a32dd51';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'node_view__panel_context_91287373-9079-4068-867a-9cb18cb09f0c';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-d9a8277c-3eff-4baa-918c-8196a6b49dbd';
  $pane->panel = 'header';
  $pane->type = 'page_breadcrumb';
  $pane->subtype = 'page_breadcrumb';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'd9a8277c-3eff-4baa-918c-8196a6b49dbd';
  $display->content['new-d9a8277c-3eff-4baa-918c-8196a6b49dbd'] = $pane;
  $display->panels['header'][0] = 'new-d9a8277c-3eff-4baa-918c-8196a6b49dbd';
  $pane = new stdClass();
  $pane->pid = 'new-9908df7c-31aa-4abb-bc68-09efd6301e77';
  $pane->panel = 'main_left';
  $pane->type = 'hp_articles_sidebar';
  $pane->subtype = 'hp_articles_sidebar';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'pid' => 'new',
    'title' => 'סיכום היומי המודיעיני ',
    'design' => 'default',
    'link' => '<front>',
    'link_title' => 'כתבות נוספות',
    'group' => array(
      0 => array(
        'choose' => '1',
        'weight' => 0,
        'nid' => '362',
      ),
      1 => array(
        'choose' => '0',
        'weight' => 1,
        'nid' => '',
      ),
      2 => array(
        'choose' => '0',
        'weight' => 2,
        'nid' => '',
      ),
      3 => array(
        'choose' => '0',
        'weight' => 3,
        'nid' => '',
      ),
      4 => array(
        'choose' => '0',
        'weight' => 4,
        'nid' => '',
      ),
      5 => array(
        'choose' => '0',
        'weight' => 5,
        'nid' => '',
      ),
      6 => array(
        'choose' => '0',
        'weight' => 6,
        'nid' => '',
      ),
      7 => array(
        'choose' => '0',
        'weight' => 7,
        'nid' => '',
      ),
      8 => array(
        'choose' => '0',
        'weight' => 8,
        'nid' => '',
      ),
      9 => array(
        'choose' => '0',
        'weight' => 9,
        'nid' => '',
      ),
      10 => array(
        'choose' => '0',
        'weight' => 10,
        'nid' => '',
      ),
      11 => array(
        'choose' => '0',
        'weight' => 11,
        'nid' => '',
      ),
      12 => array(
        'choose' => '0',
        'weight' => 12,
        'nid' => '',
      ),
      13 => array(
        'choose' => '0',
        'weight' => 13,
        'nid' => '',
      ),
      14 => array(
        'choose' => '0',
        'weight' => 14,
        'nid' => '',
      ),
      15 => array(
        'choose' => '0',
        'weight' => 15,
        'nid' => '',
      ),
      16 => array(
        'choose' => '0',
        'weight' => 16,
        'nid' => '',
      ),
      17 => array(
        'choose' => '0',
        'weight' => 17,
        'nid' => '',
      ),
      18 => array(
        'choose' => '0',
        'weight' => 18,
        'nid' => '',
      ),
      19 => array(
        'choose' => '0',
        'weight' => 19,
        'nid' => '',
      ),
      20 => array(
        'choose' => '0',
        'weight' => 20,
        'nid' => '',
      ),
      21 => array(
        'choose' => '0',
        'weight' => 21,
        'nid' => '',
      ),
      22 => array(
        'choose' => '0',
        'weight' => 22,
        'nid' => '',
      ),
      23 => array(
        'choose' => '0',
        'weight' => 23,
        'nid' => '',
      ),
      24 => array(
        'choose' => '0',
        'weight' => 24,
        'nid' => '',
      ),
      25 => array(
        'choose' => '0',
        'weight' => 25,
        'nid' => '',
      ),
      26 => array(
        'choose' => '0',
        'weight' => 26,
        'nid' => '',
      ),
      27 => array(
        'choose' => '0',
        'weight' => 27,
        'nid' => '',
      ),
      28 => array(
        'choose' => '0',
        'weight' => 28,
        'nid' => '',
      ),
      29 => array(
        'choose' => '0',
        'weight' => 29,
        'nid' => '',
      ),
    ),
    'node_id' => array(
      0 => '362',
    ),
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '9908df7c-31aa-4abb-bc68-09efd6301e77';
  $display->content['new-9908df7c-31aa-4abb-bc68-09efd6301e77'] = $pane;
  $display->panels['main_left'][0] = 'new-9908df7c-31aa-4abb-bc68-09efd6301e77';
  $pane = new stdClass();
  $pane->pid = 'new-0c1334fe-b621-483b-8fdd-c98216805dc3';
  $pane->panel = 'main_right';
  $pane->type = 'node_content';
  $pane->subtype = 'node_content';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'links' => 1,
    'no_extras' => 1,
    'override_title' => 1,
    'override_title_text' => '',
    'identifier' => '',
    'link' => 0,
    'leave_node_title' => 1,
    'build_mode' => 'full',
    'context' => 'argument_entity_id:node_1',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '0c1334fe-b621-483b-8fdd-c98216805dc3';
  $display->content['new-0c1334fe-b621-483b-8fdd-c98216805dc3'] = $pane;
  $display->panels['main_right'][0] = 'new-0c1334fe-b621-483b-8fdd-c98216805dc3';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view__panel_context_91287373-9079-4068-867a-9cb18cb09f0c'] = $handler;

  return $export;
}
