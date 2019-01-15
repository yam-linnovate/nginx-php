<?php

/**
 * @file
 * Contains the views ticker style plugin.
 */

/**
 * Style plugin to render each item in an ordered or unordered list.
 *
 * @ingroup views_style_plugins
 */
class bxslider_views_plugin_style extends views_plugin_style_list {
  function option_definition() {
	$options = parent::option_definition();
        $options['settings'] =  array('default' => '');
	return $options;
  }

  function options_form(&$form, &$form_state) {
	parent::options_form($form, $form_state);
        $form['settings'] = _bxslider_form($this->options['settings']);
  }
}

