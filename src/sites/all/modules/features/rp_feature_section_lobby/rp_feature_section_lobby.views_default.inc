<?php
/**
 * @file
 * rp_feature_section_lobby.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function rp_feature_section_lobby_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'section_lobby';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'section lobby';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'section lobby';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'עוד';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '4';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Content: תמונות (field_images) */
  $handler->display->display_options['relationships']['field_images_value']['id'] = 'field_images_value';
  $handler->display->display_options['relationships']['field_images_value']['table'] = 'field_data_field_images';
  $handler->display->display_options['relationships']['field_images_value']['field'] = 'field_images_value';
  $handler->display->display_options['relationships']['field_images_value']['delta'] = '-1';
  /* Relationship: Content: מאת (field_writer) */
  $handler->display->display_options['relationships']['field_writer_tid']['id'] = 'field_writer_tid';
  $handler->display->display_options['relationships']['field_writer_tid']['table'] = 'field_data_field_writer';
  $handler->display->display_options['relationships']['field_writer_tid']['field'] = 'field_writer_tid';
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  /* Field: Content: כותרת ראשית עמוד ראשי */
  $handler->display->display_options['fields']['field_front_page_title']['id'] = 'field_front_page_title';
  $handler->display->display_options['fields']['field_front_page_title']['table'] = 'field_data_field_front_page_title';
  $handler->display->display_options['fields']['field_front_page_title']['field'] = 'field_front_page_title';
  $handler->display->display_options['fields']['field_front_page_title']['label'] = '';
  $handler->display->display_options['fields']['field_front_page_title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_front_page_title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_front_page_title']['alter']['path'] = '[path]';
  $handler->display->display_options['fields']['field_front_page_title']['element_label_colon'] = FALSE;
  /* Field: Field collection item: תמונה */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['relationship'] = 'field_images_value';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_image']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_image']['alter']['path'] = '[path]';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => '245x140',
    'image_link' => '',
  );
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'field_writer_tid';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_taxonomy'] = TRUE;
  /* Field: Content: כותרת משנית עמוד ראשי */
  $handler->display->display_options['fields']['field_front_page_intro']['id'] = 'field_front_page_intro';
  $handler->display->display_options['fields']['field_front_page_intro']['table'] = 'field_data_field_front_page_intro';
  $handler->display->display_options['fields']['field_front_page_intro']['field'] = 'field_front_page_intro';
  $handler->display->display_options['fields']['field_front_page_intro']['label'] = '';
  $handler->display->display_options['fields']['field_front_page_intro']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_front_page_intro']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_front_page_intro']['alter']['path'] = '[path]';
  $handler->display->display_options['fields']['field_front_page_intro']['element_label_colon'] = FALSE;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = '';
  $handler->display->display_options['fields']['created']['exclude'] = TRUE;
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'd.m.y';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['type']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['type']['alter']['text'] = '<div class="[type] icon"><span class="icon"></span></div>';
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['type']['machine_name'] = TRUE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="article-image">
  <div class="image">[field_image]</div>
  [type]
</div>
<div class="article-content">
  <div class="title">[field_front_page_title]</div>
  <div class="intro">[field_front_page_intro]</div>
  <div class="name">[name]</div>
  <div class="created">[created]</div>
</div>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Updated date */
  $handler->display->display_options['sorts']['changed']['id'] = 'changed';
  $handler->display->display_options['sorts']['changed']['table'] = 'node';
  $handler->display->display_options['sorts']['changed']['field'] = 'changed';
  $handler->display->display_options['sorts']['changed']['order'] = 'DESC';
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
  $handler->display->display_options['arguments']['nid']['break_phrase'] = TRUE;
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
    'video' => 'video',
    'article' => 'article',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'infinite_scroll';
  $handler->display->display_options['pager']['options']['manual_load'] = 1;
  $handler->display->display_options['pager']['options']['text'] = 'הצג עוד';
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
  /* Field: Content: כותרת ראשית עמוד ראשי */
  $handler->display->display_options['fields']['field_front_page_title']['id'] = 'field_front_page_title';
  $handler->display->display_options['fields']['field_front_page_title']['table'] = 'field_data_field_front_page_title';
  $handler->display->display_options['fields']['field_front_page_title']['field'] = 'field_front_page_title';
  $handler->display->display_options['fields']['field_front_page_title']['label'] = '';
  $handler->display->display_options['fields']['field_front_page_title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_front_page_title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_front_page_title']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['field_front_page_title']['element_label_colon'] = FALSE;
  /* Field: Field collection item: תמונה */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['relationship'] = 'field_images_value';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_image']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_image']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => '245x140',
    'image_link' => '',
  );
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'field_writer_tid';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_taxonomy'] = TRUE;
  /* Field: Content: כותרת משנית עמוד ראשי */
  $handler->display->display_options['fields']['field_front_page_intro']['id'] = 'field_front_page_intro';
  $handler->display->display_options['fields']['field_front_page_intro']['table'] = 'field_data_field_front_page_intro';
  $handler->display->display_options['fields']['field_front_page_intro']['field'] = 'field_front_page_intro';
  $handler->display->display_options['fields']['field_front_page_intro']['label'] = '';
  $handler->display->display_options['fields']['field_front_page_intro']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_front_page_intro']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_front_page_intro']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['field_front_page_intro']['element_label_colon'] = FALSE;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = '';
  $handler->display->display_options['fields']['created']['exclude'] = TRUE;
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'd.m.y';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['type']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['type']['alter']['text'] = '<div class="[type] icon"><span class="icon"></span></div>';
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['type']['machine_name'] = TRUE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="article-image">
  <div class="image">[field_image]</div>
  [type]
</div>
<div class="article-content">
  <div class="title">[field_front_page_title]</div>
  <div class="intro">[field_front_page_intro]</div>
  <div class="name">[name]</div>
  <div class="created">[created]</div>
<!---  <div class="lobby-view-more">[view_node]</div> -->
</div>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: קטגוריה (field_section) */
  $handler->display->display_options['arguments']['field_section_tid']['id'] = 'field_section_tid';
  $handler->display->display_options['arguments']['field_section_tid']['table'] = 'field_data_field_section';
  $handler->display->display_options['arguments']['field_section_tid']['field'] = 'field_section_tid';
  $handler->display->display_options['arguments']['field_section_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_section_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_section_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_section_tid']['summary_options']['items_per_page'] = '25';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_2');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '4';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: תמונות (field_images) */
  $handler->display->display_options['relationships']['field_images_value']['id'] = 'field_images_value';
  $handler->display->display_options['relationships']['field_images_value']['table'] = 'field_data_field_images';
  $handler->display->display_options['relationships']['field_images_value']['field'] = 'field_images_value';
  $handler->display->display_options['relationships']['field_images_value']['delta'] = '-1';
  /* Relationship: Content: מאת (field_writer) */
  $handler->display->display_options['relationships']['field_writer_tid']['id'] = 'field_writer_tid';
  $handler->display->display_options['relationships']['field_writer_tid']['table'] = 'field_data_field_writer';
  $handler->display->display_options['relationships']['field_writer_tid']['field'] = 'field_writer_tid';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Field collection item: תמונה */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['relationship'] = 'field_images_value';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_image']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => '245x140',
    'image_link' => '',
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
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'field_writer_tid';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_taxonomy'] = TRUE;
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
  $handler->display->display_options['arguments']['nid']['break_phrase'] = TRUE;
  $handler->display->display_options['arguments']['nid']['not'] = TRUE;
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
  );
  $translatables['section_lobby'] = array(
    t('Master'),
    t('section lobby'),
    t('עוד'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('field collection item from field_images'),
    t('term from field_writer'),
    t('<div class="[type] icon"><span class="icon"></span></div>'),
    t('<div class="article-image">
  <div class="image">[field_image]</div>
  [type]
</div>
<div class="article-content">
  <div class="title">[field_front_page_title]</div>
  <div class="intro">[field_front_page_intro]</div>
  <div class="name">[name]</div>
  <div class="created">[created]</div>
</div>'),
    t('All'),
    t('Block'),
    t('הצג עוד'),
    t('<div class="article-image">
  <div class="image">[field_image]</div>
  [type]
</div>
<div class="article-content">
  <div class="title">[field_front_page_title]</div>
  <div class="intro">[field_front_page_intro]</div>
  <div class="name">[name]</div>
  <div class="created">[created]</div>
<!---  <div class="lobby-view-more">[view_node]</div> -->
</div>'),
  );
  $export['section_lobby'] = $view;

  return $export;
}
