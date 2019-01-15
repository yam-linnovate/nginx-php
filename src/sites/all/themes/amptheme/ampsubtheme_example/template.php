<?php

/**
 * Preprocess all templates.
 */
function ampsubtheme_example_preprocess(&$vars, $hook) {
  $vars['ampsubtheme_path_file'] = DRUPAL_ROOT . '/' . drupal_get_path('theme', 'ampsubtheme_example');
}

function ampsubtheme_target($fragment) {
  // Create a DOM object.
  $html_obj = new simple_html_dom();

  // Load HTML from a string.
  $html_obj->load($fragment);

  // Remove all plain text fragments.
  foreach ($html_obj->find('a') as $id ) {
    $refText = $id->href;
    if (!url_is_external($refText)) {
      $id->target = "_self";
    } elseif(url_is_external($refText)) {
      $id->target = "_blank";
    }
  }

  foreach ($html_obj->find('img') as $id ) {
    $id->class = 'contain';
    $id->tag = 'amp-img';
    if(!$id->width || !$id->height) {
      if($id->style) {
        $size = explode(';', $id->style);
        $width = trim(str_replace('px', '', explode(':', $size[0])[1]));
        $height = trim(str_replace('px', '', explode(':',$size[1])[1]));
        $id->width = $width;
        $id->height = $height;
      } else if(!$id->style) {
        $id->width = '100';
        $id->height = '100';
      }
    }
    $id->layout = 'responsive';
  }

  foreach ($html_obj->find('iframe') as $id ) {
    $id->tag = 'amp-iframe';
    $id->allowtransparency = null;
  }

  foreach ($html_obj->find('form') as $id ) {
    $id->{'action-xhr'} = $id->action;
    $id->action = null;
  }

  foreach ($html_obj->find('script') as $id ) {
    $id->innertext = '';
    $id->tag = null;
  }

  // Display the results.
  print $html_obj;
            
  // Release resources to avoid memory leak in some versions.
  $html_obj->clear(); 
  unset($html_obj);
}

function ampsubtheme_example_preprocess_field(&$variables) {
  if($variables['element']['#field_name'] == 'field_images') {
    $size = reset($variables['items'][0]['entity']['field_collection_item']);
    $uri = explode('public://', $size['field_image']['#items'][0]['uri'])[1];
    $width = $size['field_image']['#items'][0]['width'];
    $height = $size['field_image']['#items'][0]['height'];
    $GLOBALS['image_size_array'][$uri] = array(
      'width' => $width,
      'height' => $height
    );
  } else if($variables['element']['#field_name'] == 'field_image') {
    $uri = explode('public://', $variables['items'][0]['#item']['uri'])[1];
    $width = $variables['items'][0]['#item']['width'];
    $height = $variables['items'][0]['#item']['height'];
    $GLOBALS['image_size_array'][$uri] = array(
      'width' => $width,
      'height' => $height
    );
  }
}

function ampsubtheme_example_preprocess_image(&$variables) {
  if(strpos($variables['path'], '?')) {
    $path = explode('?', $variables['path'])[0];
  }
  if(strpos($variables['path'], 'public/')) {
    $path = explode('public/', $path)[1];
  }
  if(isset($path) && isset($GLOBALS['image_size_array']) ) {
    $path = urldecode($path);
    if(isset($GLOBALS['image_size_array'][$path]['width'])) {
      $variables['width'] = $GLOBALS['image_size_array'][$path]['width'];
    } else {
      $variables['width'] = 100;
    }
    if(isset($GLOBALS['image_size_array'][$path]['height'])) {
      $variables['height'] = $GLOBALS['image_size_array'][$path]['height'];
    } else {
      $variables['height'] = 100;
    }
  }
}