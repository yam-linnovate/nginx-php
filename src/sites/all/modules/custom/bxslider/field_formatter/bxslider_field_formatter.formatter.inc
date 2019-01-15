<?php

// ------------------------------ info / settings_form / settings_summary  -------------------------------------- //

// Implements hook_field_formatter_info().

function bxslider_field_formatter_info() {
  $formatters = _bxslider_field_formatter_info();
  $formatters['_bxslider']['settings']['view_mode'] = array( 'view_mode' => 'full');
  return $formatters;
}

// Implements hook_field_formatter_settings_form().

function bxslider_field_formatter_settings_form($field, $instance, $view_mode, $form, &$form_state) {
  $display = $instance['display'][$view_mode];
  $settings = $display['settings'];
  $element = _bxslider_form($settings); 

  if($instance['widget']['module'] == 'field_collection'){
    $entity_type = entity_get_info('field_collection_item');
    $options = array();
    foreach ($entity_type['view modes'] as $mode => $info) {
       $options[$mode] = $info['label'];
    }

    $element['view_mode'] = array(
    '#type' => 'select',
    '#title' => t('View mode'),
    '#options' => $options,
    '#default_value' => $settings['view_mode'],
    '#description' => t('Select the view mode'),
    );
  }
  return $element;
}

// Implements hook_field_formatter_settings_summary().

function bxslider_field_formatter_settings_summary($field, $instance, $view_mode) {
  return t('settings');
}

// ------------------------------ info / settings_form / settings_summary  -------------------------------------- //

// Implements hook_field_formatter_view().

function bxslider_field_formatter_view($entity_type, $entity, $field, $instance, $langcode, $items, $display) {
  $settings = $display['settings'];
  $elements = array();
  if ($field['type'] == 'image') {
    foreach ($items as $delta => $item) {
      $items[$delta] = (array) $item;
    }
  }
  elseif (module_exists('field_collection') && $field['type'] == 'field_collection') { 
    $view_mode = !empty($display['settings']['view_mode']) ? $display['settings']['view_mode'] : 'full';
    foreach ($items as $delta => $item) {
      if ($field_collection = field_collection_field_get_entity($item)) {
        $items[$delta] = $field_collection->view($view_mode);
      }
    }
  }

  $elements = array(
    '#theme' => 'bxslider_field_formatter',
    '#items' => $items,
    '#settings' => $settings,
    '#field_id' => $instance['bundle'].'_'.$instance['field_id'],
  );

  return $elements;
}

// Implements template_preprocess().

function template_preprocess_bxslider_field_formatter(&$variables) {
  _template_preprocess_bxslider($variables,$variables['settings'],'field_formatter',$variables['field_id']);
}


