<?php

/**
 * Implementation of hook_views_data()
 */
function bxslider_views_data() {
  $data['BxSlider']['table']['group'] = t('BxSlider');
  $data['BxSlider']['table']['join'] = array( '#global' => array(), );
  $data['BxSlider']['BxSlider'] = array(
    'group' => t('BxSlider'),
    'field' => array(
      'title' => t('BxSlider: Field - trigger'),
      'help' => t('BxSlider'),
      'handler' => 'bxslider_handler_view_field',
  ),);
  return $data;
}


/**
 * Implementation of hook_views_handlers() to register all of the basic handlers
 * views uses.
 */
function bxslider_views_handlers() {
  return array(
    'info' => array( 'path' => drupal_get_path('module', 'bxslider'), ),
    'handlers' => array('view_field/bxslider_handler_view_field' => array( 'parent' => 'views_handler_field_list',),),
  );
}

function template_preprocess_bxslider_view_field(&$variables) {
  _template_preprocess_bxslider($variables,$variables['settings'], 'view_field', $variables['field_id']);
}

