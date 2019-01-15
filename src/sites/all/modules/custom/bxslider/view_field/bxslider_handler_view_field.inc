<?php

/**
 * @ingroup views_field_handlers
 */
class bxslider_handler_view_field extends views_handler_field {
  function query() {  }

  function option_definition() {
    $options = parent::option_definition();
    $options['bxslide_field'] = array('default' => '');
    $options['bxslider_popup'] = array('default' => '');
    $options['bxslider_settings'] =  array('default' => '');
    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    $fields = array('bxslide_field' => t('<None>'));

    foreach ($this->view->display_handler->get_handlers('field') as $field => $handler) {
      if ($field == $this->options['id']) 
          break;
      $fields[$field] = $handler->definition['title'];
    }

    $form['bxslide_field'] = array(
      '#type' => 'select',
      '#title' => t('Trigger field'),
      '#description' => t('Select the field that should be turned into the trigger for the lightbox.  Only fields that appear before this one in the field list may be used.'),
      '#options' => $fields,
      '#default_value' => $this->options['bxslide_field'],
      '#weight' => -12,
    );

    $form['bxslider_popup'] = array(
      '#type' => 'textarea',
      '#title' => t('Popup'),
      '#description' => t('Combine tokens from the "Replacement patterns" below and html to create what the lightbox popup_bxslider will become.'),
      '#default_value' => $this->options['bxslider_popup'],
      '#weight' => -11,
    );

    $form['bxslider_settings'] = _bxslider_form($this->options['bxslider_settings']);
    unset($form['alter']['text']);
    unset($form['alter']['path']);
    unset($form['alter']['prefix']);
    unset($form['alter']['suffix']);
    unset($form['alter']['text']['#process']);
  }

  function render($values) {
    if (!empty($this->options['bxslide_field'])) {
      $bxslider_popup = $this->options['bxslider_popup'];
      $tokens = $this->get_render_tokens($this->options['alter']);
      $bxslider_popup = strtr($bxslider_popup, $tokens);
      //$bxslider_popup = filter_xss_admin($bxslider_popup);

      $src = drupal_get_path('module', 'bxslider') . '/images/ping.gif';
      $bxslider_popup = str_replace("src", "src='{$src}' data-src", $bxslider_popup);
      $bxslider_popup = str_replace("iframe", "noiframe", $bxslider_popup);

      $element[] = array(
        '#theme' => 'bxslider_view_field',
        '#items' => $tokens["[{$this->options['bxslide_field']}]"],
        '#popup' => $bxslider_popup,
        '#settings' => $this->options['bxslider_settings'],
        '#field_id' => $this->view->name.'_'.$this->view->current_display.'_'.$this->options['id'],
      );
    return $element;
    }
    else {
      return;
    }
  }
}


