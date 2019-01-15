<?php


function bxslider_views_plugins() { 
  $plugins['style']['bxslider'] = array( 
    'title' => t('BxSlider'),
    'help' => t('Displays content on a BxSlider'),
    'handler' => 'bxslider_views_plugin_style', 
    'uses options' => TRUE,
    'uses row plugin' => TRUE,
    'uses grouping' => TRUE,
    'uses row class' => TRUE,
    'type' => 'normal',
    'parent' => 'list',
    'path' => drupal_get_path('module', 'bxslider').'/view_format',
    'theme' => 'bxslider_view',
    'theme path' => drupal_get_path('module', 'bxslider').'/view_format',
  ); 
  return $plugins;
}

function template_preprocess_bxslider_view(&$variables) {
//dpm($variables);
   $id = $variables['view']->name.'_'.$variables['view']->current_display;
   _template_preprocess_bxslider($variables, $variables['options']['settings'],'view_format',$id);
}


