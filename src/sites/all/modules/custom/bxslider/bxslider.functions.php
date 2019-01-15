<?php

/**
 *
 */
function _bxslider_field_formatter_info() {
  // Set our default options.
 $formatters = array(
    '_bxslider' => array(
      'label'       => t('bxslider'),
      'field types' => array('image','field_collection'),
      'settings'    => array(
      'general' => array(
        'mode' => 'horizontal',
        'speed' => 500,
        'slideMargin' => 0,
        'startSlide' => 0,
        'randomStart' => FALSE,
        'infiniteLoop' => TRUE,
        'hideControlOnEnd' => TRUE,
        'captions' => FALSE,
        'useCSS' => FALSE,
        'disable_standard_css' => FALSE,
        'align_image' => 'left',
        'align_caption' => 'left',
        'ticker' => FALSE,
        'tickerHover' => FALSE,
        'adaptiveHeight' => TRUE,
        'adaptiveHeightSpeed' => 500,
        'video' => FALSE,
        'touchEnabled' => TRUE,
        'preloadImages' => 'visible',
        'swipeThreshold' => 50,
        'oneToOneTouch' => TRUE,
        'preventDefaultSwipeX' => TRUE,
        'preventDefaultSwipeY' => FALSE,
        'color_caption' => "80, 80, 80, 0.75",
      ),
      'controlsfieldset' => array(
        'startText' => 'Start',
        'stopText' => 'Stop',
        'nextText' => 'Next',
        'prevText' => 'Prev',
        'autoControls' => FALSE,
        'autoControlsCombine' => FALSE,
        'controls' => TRUE,
      ),
      'pagerfieldset' => array(
        'pager' => FALSE,
        'pagerType' => 'short',
        'pagerShortSeparator' => ' / ',
      ),
      'autofieldset' => array(
        'autoStart' => FALSE,
        'pause' => 4000,
        'auto' => FALSE,
        'autoHover' => FALSE,
        'autoDelay' => 0,
        'autoDirection' => 'next',
      ),
      'carousel' => array(
        'minSlides' => 1,
        'maxSlides' => 1,
        'slideWidth' => 0,
        'moveSlides' => 0,
      ),
      'callback' => array(
        'onSliderLoad' => NULL,
        'onSlideBefore' => NULL,
        'onSlideAfter' => NULL,
        'onSlideNext' => NULL,
        'onSlidePrev' => NULL,
      ),
      ),
    ),
  );
  return $formatters;
}

/**
 *
 */
function _bxslider_form($settings = NULL) {
  $element['general'] = array(
    '#type' => 'fieldset',
    '#title' => t('General'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $element['controlsfieldset'] = array(
    '#type' => 'fieldset',
    '#title' => t('Controls'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $element['pagerfieldset'] = array(
    '#type' => 'fieldset',
    '#title' => t('Pager'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $element['autofieldset'] = array(
    '#type' => 'fieldset',
    '#title' => t('Auto'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $element['carousel'] = array(
    '#type' => 'fieldset',
    '#title' => t('Carousel'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $element['callback'] = array(
    '#type' => 'fieldset',
    '#title' => t('Callbacks'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  // FORM
  $element['general']['mode'] = array(
    '#type' => 'select',
    '#title' => t('Mode'),
    '#description' => t('Type of transition between slides'),
    '#default_value' => isset($settings['general']['mode']) ? $settings['general']['mode'] : 'horizontal',
    '#options' => array(
      'horizontal' => 'horizontal',
      'vertical' => 'vertical',
      'fade' => 'fade',
    ),
  );
  $element['general']['speed'] = array(
    '#type' => 'textfield',
    '#title' => t('Speed'),
    '#description' => t('Slide transition duration (in ms)'),
    '#default_value' => isset($settings['general']['speed']) ? $settings['general']['speed'] : 500,
  );
  $element['general']['slideMargin'] = array(
    '#type' => 'textfield',
    '#title' => t('Slide margin'),
    '#description' => t('Margin between each slide.'),
    '#default_value' => isset($settings['general']['slideMargin']) ? $settings['general']['slideMargin'] : 0,
  );
  $element['general']['startSlide'] = array(
    '#type' => 'textfield',
    '#title' => t('Start slide'),
    '#description' => t('Starting slide index (zero-based)'),
    '#default_value' => isset($settings['general']['startSlide']) ? $settings['general']['startSlide'] : 0,
  );
  $element['general']['randomStart'] = array(
    '#type' => 'checkbox',
    '#title' => t('Random start'),
    '#description' => t('Start slider on a random slide'),
    '#default_value' => isset($settings['general']['randomStart']) ? $settings['general']['randomStart'] : FALSE,
  );
  $element['general']['infiniteLoop'] = array(
    '#type' => 'checkbox',
    '#title' => t('Inifinite loop'),
    '#description' => t('If true, clicking "Next" while on the last slide will transition to the first slide and vice-versa'),
    '#default_value' => isset($settings['general']['infiniteLoop']) ? $settings['general']['infiniteLoop'] : TRUE,
  );
  $element['general']['hideControlOnEnd'] = array(
    '#type' => 'checkbox',
    '#title' => t('Hide controls on end ?'),
    '#description' => t('If true, "Next" control will be hidden on last slide and vice-versa
Note: Only used when infiniteLoop: false'),
    '#default_value' => isset($settings['general']['hideControlOnEnd']) ? $settings['general']['hideControlOnEnd'] : TRUE,
  );
  $element['general']['captions'] = array(
    '#type' => 'checkbox',
    '#title' => t('Captions'),
    '#description' => t('Include image captions. Captions are derived from the image\'s title attribute'),
    '#default_value' => isset($settings['general']['captions']) ? $settings['general']['captions'] : FALSE,
  );
  $element['general']['ticker'] = array(
    '#type' => 'checkbox',
    '#title' => t('Ticker mode'),
    '#description' => t('Use slider in ticker mode (similar to a news ticker)'),
    '#default_value' => isset($settings['general']['ticker']) ? $settings['general']['ticker'] : FALSE,
  );
  $element['general']['tickerHover'] = array(
    '#type' => 'checkbox',
    '#title' => t('Ticker hover'),
    '#description' => t('Ticker will pause when mouse hovers over slider. Note: this functionality does NOT work if using CSS transitions!'),
    '#default_value' => isset($settings['general']['tickerHover']) ? $settings['general']['tickerHover'] : FALSE,
  );
  $element['general']['adaptiveHeight'] = array(
    '#type' => 'checkbox',
    '#title' => t('Adaptive height'),
    '#description' => t('Dynamically adjust slider height based on each slide\'s height'),
    '#default_value' => isset($settings['general']['adaptiveHeight']) ? $settings['general']['adaptiveHeight'] : TRUE,
  );
  $element['general']['adaptiveHeightSpeed'] = array(
    '#type' => 'textfield',
    '#title' => t('Adaptive height speed'),
    '#description' => t('Slide height transition duration (in ms). Note: only used if adaptiveHeight: true'),
    '#default_value' => isset($settings['general']['adaptiveHeightSpeed']) ? $settings['general']['adaptiveHeightSpeed'] : 500,
  );
  $element['general']['video'] = array(
    '#type' => 'checkbox',
    '#title' => t('Video'),
    '#description' => t('If any slides contain video, set this to true. Also, include plugins/jquery.fitvids.js
See http://fitvidsjs.com/ for more info'),
    '#default_value' => isset($settings['general']['video']) ? $settings['general']['video'] : FALSE,
  );
  $element['general']['touchEnabled'] = array(
    '#type' => 'checkbox',
    '#title' => t('Touch enabled'),
    '#description' => t('If true, slider will allow touch swipe transitions'),
    '#default_value' => isset($settings['general']['touchEnabled']) ? $settings['general']['touchEnabled'] : TRUE,
  );
  $element['general']['preloadImages'] = array(
    '#type' => 'select',
    '#title' => t('Preload all images?'),
    '#description' => t('If all, preloads all images before starting the slider. If visible, preloads only images in the initially visible slides before starting the slider (tip: use visible if all slides are identical dimensions)'),
    '#default_value' => isset($settings['general']['preloadImages']) ? $settings['general']['preloadImages'] : 'visisble',
    '#options' => array(
      'visible' => 'visible',
      'all' => 'all',
    ),
  );
  $element['general']['disable_standard_css'] = array(
    '#type' => 'checkbox',
    '#title' => t('Use own CSS ?'),
    '#description' => t('Do you want to use the standard css or include your own ?'),
    '#default_value' => isset($settings['general']['disable_standard_css']) ? $settings['general']['disable_standard_css'] : FALSE,
  );
  $element['general']['useCSS'] = array(
    '#type' => 'checkbox',
    '#title' => t('Use CSS transitions'),
    '#description' => t('Use hardware-accelerated CSS transitions.  Fallback is jQuery.animate()'),
    '#default_value' => isset($settings['general']['useCSS']) ? $settings['general']['useCSS'] : FALSE,
  );
  $element['general']['align_image'] = array(
    '#type' => 'select',
    '#title' => t('Alignment Image'),
    '#description' => t('Do you want to align the image?'),
    '#options' => array(
      'left' => 'left',
      'center' => 'center',
      'right' => 'right',
    ),
    '#default_value' => isset($settings['general']['align_image']) ? $settings['general']['align_image'] : 'left',
  );
  $element['general']['align_caption'] = array(
    '#type' => 'select',
    '#title' => t('Alignment caption'),
    '#description' => t('Do you want to align the caption?'),
    '#options' => array(
      'left' => 'left',
      'center' => 'center',
      'right' => 'right',
    ),
    '#default_value' => isset($settings['general']['align_caption']) ? $settings['general']['align_caption'] : 'left',
  );
  $element['general']['swipeThreshold'] = array(
    '#type' => 'textfield',
    '#title' => t('Swipe treshold default: 50'),
    '#description' => t('Amount of pixels a touch swipe needs to exceed in order to execute a slide transition. Note: only used if touchEnabled: tru.'),
    '#default_value' => isset($settings['general']['swipeThreshold']) ? $settings['general']['swipeThreshold'] : 50,
  );
  $element['general']['oneToOneTouch'] = array(
    '#type' => 'checkbox',
    '#title' => t('One to One touch'),
    '#description' => t('If true, non-fade slides follow the finger as it swipes'),
    '#default_value' => isset($settings['general']['oneToOneTouch']) ? $settings['general']['oneToOneTouch'] : TRUE,
  );
  $element['general']['preventDefaultSwipeX'] = array(
    '#type' => 'checkbox',
    '#title' => t('Prevent swipe X'),
    '#description' => t(' If true, touch screen will not move along the x-axis as the finger swipes'),
    '#default_value' => isset($settings['general']['preventDefaultSwipeX']) ? $settings['general']['preventDefaultSwipeX'] : TRUE,
  );
  $element['general']['preventDefaultSwipeY'] = array(
    '#type' => 'checkbox',
    '#title' => t('Prevent swipe Y'),
    '#description' => t(' If true, touch screen will not move along the y-axis as the finger swipes'),
    '#default_value' => isset($settings['general']['preventDefaultSwipeY']) ? $settings['general']['preventDefaultSwipeY'] : FALSE,
  );
  // Colors.
  $element['general']['color_caption'] = array(
    '#type' => 'textfield',
    '#title' => t('Color caption'),
    '#description' => t('Please provide me an correct CSS3.0 rgba color code: This consists of 4 numbers separated with an "," '),
    '#default_value' => isset($settings['general']['color_caption']) ? $settings['general']['color_caption'] : "80, 80, 80, 0.75",
  );
  // PAGER
  $element['pagerfieldset']['pager'] = array(
    '#type' => 'checkbox',
    '#title' => t('Pager'),
    '#description' => t('If true, a pager will be added'),
    '#default_value' => isset($settings['pagerfieldset']['pager']) ? $settings['pagerfieldset']['pager'] : FALSE,
  );
  $element['pagerfieldset']['pagerType'] = array(
    '#type' => 'select',
    '#title' => t('Pager type'),
    '#description' => t("If 'full', a pager link will be generated for each slide. If 'short', a x / y pager will be used (ex. 1 / 5)"),
    '#default_value' => isset($settings['pagerfieldset']['pagerType']) ? $settings['pagerfieldset']['pagerType'] : 'full',
    '#options' => array(
      'full' => 'full',
      'short' => 'short',
    ),
  );
  $element['pagerfieldset']['pagerShortSeparator'] = array(
    '#type' => 'textfield',
    '#title' => t('Pager short separator'),
    '#description' => t('If pagerType: short, pager will use this value as the separating character: default /'),
    '#default_value' => isset($settings['pagerfieldset']['pagerShortSeparator']) ? $settings['pagerfieldset']['pagerShortSeparator'] : ' / ',
  );
  // CONTROLS
  $element['controlsfieldset']['controls'] = array(
    '#type' => 'checkbox',
    '#title' => t('Controls'),
    '#description' => t('If true, "Next" / "Prev" controls will be added'),
    '#default_value' => isset($settings['controlsfieldset']['controls']) ? $settings['controlsfieldset']['controls'] : TRUE,
  );
  $element['controlsfieldset']['nextText'] = array(
    '#type' => 'textfield',
    '#title' => t('Next Text'),
    '#description' => t('Text to be used for the "Next" control'),
    '#default_value' => isset($settings['controlsfieldset']['nextText']) ? $settings['controlsfieldset']['nextText'] : 'Next',
  );
  $element['controlsfieldset']['prevText'] = array(
    '#type' => 'textfield',
    '#title' => t('Previous Text'),
    '#description' => t('Text to be used for the "Prev" control'),
    '#default_value' => isset($settings['controlsfieldset']['prevText']) ? $settings['controlsfieldset']['nextText'] : 'Prev',
  );
  $element['controlsfieldset']['startText'] = array(
    '#type' => 'textfield',
    '#title' => t('Start Text'),
    '#description' => t('Text to be used for the "Start" control'),
    '#default_value' => isset($settings['controlsfieldset']['startText']) ? $settings['controlsfieldset']['startText'] : 'Start',
  );
  $element['controlsfieldset']['stopText'] = array(
    '#type' => 'textfield',
    '#title' => t('Stop Text'),
    '#description' => t('Text to be used for the "Stop" control'),
    '#default_value' => isset($settings['controlsfieldset']['stopText']) ? $settings['controlsfieldset']['stopText'] : 'Stop',
  );
  $element['controlsfieldset']['autoControls'] = array(
    '#type' => 'checkbox',
    '#title' => t('Auto controls'),
    '#description' => t('If true, "Start" / "Stop" controls will be added'),
    '#default_value' => isset($settings['controlsfieldset']['autoControls']) ? $settings['controlsfieldset']['autoControls'] : FALSE,
  );
  $element['controlsfieldset']['autoControlsCombine'] = array(
    '#type' => 'checkbox',
    '#title' => t('Auto controls combine'),
    '#description' => t('When slideshow is playing only "Stop" control is displayed and vice-versa'),
    '#default_value' => isset($settings['controlsfieldset']['autoControlsCombine']) ? $settings['controlsfieldset']['autoControlsCombine'] : FALSE,
  );
  // AUTO
  $element['autofieldset']['pause'] = array(
    '#type' => 'textfield',
    '#title' => t('Pause'),
    '#description' => t('The amount of time (in ms) between each auto transition'),
    '#default_value' => isset($settings['autofieldset']['pause']) ? $settings['autofieldset']['pause'] : 4000,
  );
  $element['autofieldset']['autoStart'] = array(
    '#type' => 'checkbox',
    '#title' => t('Auto Start'),
    '#description' => t('If checked, then the slide show will begin rotating after the specified time below.'),
    '#default_value' => isset($settings['autofieldset']['autoStart']) ? $settings['autofieldset']['autoStart'] :  FALSE,
  );
  $element['autofieldset']['auto'] = array(
    '#type' => 'checkbox',
    '#title' => t('Auto'),
    '#description' => t('Slides will automatically transition'),
    '#default_value' => isset($settings['autofieldset']['auto']) ? $settings['autofieldset']['auto'] : FALSE,
  );
  $element['autofieldset']['autoHover'] = array(
    '#type' => 'checkbox',
    '#title' => t('Auto hover'),
    '#description' => t('Auto show will pause when mouse hovers over slider'),
    '#default_value' => isset($settings['autofieldset']['autoHover']) ? $settings['autofieldset']['autoHover'] : FALSE,
  );
  $element['autofieldset']['autoDelay'] = array(
    '#type' => 'textfield',
    '#title' => t('Auto delay'),
    '#description' => t('The direction of auto show slide transitions'),
    '#default_value' => isset($settings['autofieldset']['autoDelay']) ? $settings['autofieldset']['autoDelay'] : 0,
  );
  $element['autofieldset']['autoDirection'] = array(
    '#type' => 'select',
    '#options' => array(
      'next' => 'next',
      'prev' => 'prev',
    ),
    '#title' => t('Auto direction'),
    '#description' => t('The direction of auto show slide transitions'),
    '#default_value' => isset($settings['autofieldset']['autoDirection']) ? $settings['autofieldset']['autoDirection'] : 'next',
  );
  // CAROUSEL
  $element['carousel']['minSlides'] = array(
    '#type' => 'textfield',
    '#title' => t('Minimum amount of slides'),
    '#description' => t('The minimum number of slides to be shown. Slides will be sized down if carousel becomes smaller than the original size..'),
    '#default_value' => isset($settings['carousel']['minSlides']) ? $settings['carousel']['minSlides'] : 1,
  );
  $element['carousel']['maxSlides'] = array(
    '#type' => 'textfield',
    '#title' => t('Maximum slides'),
    '#description' => t('The maximum number of slides to be shown. Slides will be sized up if carousel becomes larger than the original size.'),
    '#default_value' => isset($settings['carousel']['maxSlides']) ? $settings['carousel']['maxSlides'] : 1,
  );
  $element['carousel']['moveSlides'] = array(
    '#type' => 'textfield',
    '#title' => t('Move slides'),
    '#description' => t('The number of slides to move on transition. This value must be >= minSlides, and <= maxSlides. If zero (default), the number of fully-visible slides will be used.'),
    '#default_value' => isset($settings['carousel']['moveSlides']) ? $settings['carousel']['moveSlides']: 0,
  );
  $element['carousel']['slideWidth'] = array(
    '#type' => 'textfield',
    '#title' => t('Slide width'),
    '#description' => t('The width of each slide. This setting is required for all horizontal carousels! default 0'),
    '#default_value' => isset($settings['carousel']['slideWidth']) ? $settings['carousel']['slideWidth'] : 0,
  );
  // Callbacks.bxSliderInitialize($(this));
  $element['callback']['information'] = array(
    '#markup' => t('If you enter javascript below it will be used in the appropriate functions. Be sure to enter javascript !'),
  );
  $element['callback']['onSliderLoad'] = array(
    '#type' => 'textarea',
    '#title' => t('onSliderLoad'),
    '#description' => t('Executes immediately after the slider is fully loaded: You can utilize the parameter "currentIndex"'),
    '#default_value' => isset($settings['callback']['onSliderLoad']) ? $settings['callback']['onSliderLoad'] : NULL,
  );
  $element['callback']['onSlideBefore'] = array(
    '#type' => 'textarea',
    '#title' => t('onSlideBefore'),
    '#description' => t('Executes immediately before each slide transition.: You can utilize the parameter "$slideElement, oldIndex, newIndex"'),
    '#default_value' => isset($settings['callback']['onSlideBefore']) ? $settings['callback']['onSlideBefore'] : NULL,
  );
  $element['callback']['onSlideAfter'] = array(
    '#type' => 'textarea',
    '#title' => t('onSlideAfter'),
    '#description' => t('Executes immediately after each slide transition. Function verticalargument is the current slide element (when transition completes).: You can utilize the parameter "$slideElement, oldIndex, newIndex"'),
    '#default_value' => isset($settings['callback']['onSlideAfter']) ? $settings['callback']['onSlideAfter'] : NULL,
  );
  $element['callback']['onSlideNext'] = array(
    '#type' => 'textarea',
    '#title' => t('onSlideNext'),
    '#description' => t('Executes immediately before each "Next" slide transition. Function argument is the target (next) slide element.: You can utilize the parameter "$slideElement, oldIndex, newIndex"'),
    '#default_value' => isset($settings['callback']['onSlideNext']) ? $settings['callback']['onSlideNext'] : NULL,
  );
  $element['callback']['onSlidePrev'] = array(
    '#type' => 'textarea',
    '#title' => t('onSlidePrev'),
    '#description' => t('Executes immediately before each "Prev" slide transition. Function argument is the target (prev) slide element.: You can utilize the parameter "$slideElement, oldIndex, newIndex"'),
    '#default_value' => isset($settings['callback']['onSlidePrev']) ? $settings['callback']['onSlidePrev'] : NULL,
  );
  return $element;
}

function _bxslider_set_extra_css($general_settings) {
  $align_image = isset($general_settings['align_image']) ? $general_settings['align_image'] : NULL;
  $color_caption = isset($general_settings['color_caption']) ? $general_settings['color_caption'] : NULL;
  $align_caption = isset($general_settings['align_caption']) ? $general_settings['align_caption'] : NULL;;
  // Overlay bug fix.
  $selector_overlay = ".views-slideshow-bxslider .bx-wrapper .bx-controls-direction a";
  drupal_add_css($selector_overlay . ' { z-index:499; }', 'inline');

  $selector = ".views-slideshow-bxslider li img";
  switch($align_image) {
    case 'center':
      drupal_add_css($selector . ' { margin-left:auto; margin-right:auto; }', 'inline');
      break;
    case 'right':
      drupal_add_css($selector . ' { margin-left:auto; }', 'inline');
      break;
    default:
      drupal_add_css($selector . ' { margin-right:auto; }', 'inline');
  }
  // Caption alignment.
  $selector_caption_alignment = ".filed-bxslider .bx-caption";
  if (!empty($align_caption)) {
    switch($align_caption) {
      case 'center':
        drupal_add_css($selector_caption_alignment . ' { text-align: center; }', 'inline');
        break;
      case 'right':
        drupal_add_css($selector_caption_alignment . ' { text-align: right; }', 'inline');
        break;
      default:
        // Nothing.
    }
  }
  // Second part color caption overruling.
  $selector_caption = ".field-bxslider .bx-wrapper .bx-caption";
  if (!empty($color_caption)) {
    drupal_add_css($selector_caption . ' { background: rgba(' . $color_caption . ') }', 'inline');
  }
}

/*
 * Helper function to build and pass BxSlider settings to Drupal.
 */
function _bxslider_add_js($options, $id) {
  // Make an correct id.
  $id = str_replace('-', '_', $id);

  // Import variables.
  extract($options);
  $bxslider_path = _bxslider_library_path();

  // Load Bxslider.
  drupal_add_js($bxslider_path, array('group' => JS_LIBRARY));
  if (!$general['disable_standard_css']) {
    drupal_add_css(libraries_get_path('bxslider') . '/jquery.bxslider.css');
  }

  // Process Bxslider settings.
  // Load bxslider settings.
  $bx_slider_js = <<<BXSLIDERJS
    bxSliderInitialize_$id = {
BXSLIDERJS;
  // Index.
  $bx_slider_js .= "startSlide: index,";
  // Content.
  $bx_slider_js .= _bxslider_theme_get_admin_js(
    $autofieldset, $general, $carousel, $pagerfieldset, $controlsfieldset);
  // Callbacks.
  if (!empty($callback['onSliderLoad'])) {
    $bx_slider_js .= "onSliderLoad: function(currentIndex){" . filter_xss($callback['onSliderLoad']) . "},";
  }
  if (!empty($callback['onSlideBefore'])) {
    $bx_slider_js .=
      "onSlideBefore: function(slideElement, oldIndex, newIndex){" . filter_xss($callback['onSlideBefore']) . "},";
  }
  if (!empty($callback['onSlideAfter'])) {
    $bx_slider_js .=
      "onSlideAfter: function(slideElement, oldIndex, newIndex){" . filter_xss($callback['onSlideAfter']) . "},";
  }
  if (!empty($callback['onSlideNext'])) {
    $bx_slider_js .=
      "onSlideNext: function(slideElement, oldIndex, newIndex){" . filter_xss($callback['onSlideNext']) . "},";
  }
  if (!empty($callback['onSlidePrev'])) {
    $bx_slider_js .=
      "onSlidePrev: function(slideElement, oldIndex, newIndex){" . filter_xss($callback['onSlidePrev']) . "}";
  }
  $bx_slider_js .= <<<ENDBXSLIDERJS
    };
ENDBXSLIDERJS;

  drupal_add_js(array('bxSlider' => array($id => json_encode($bx_slider_js))), 'setting');

}

function _bxslider_theme_get_admin_js($autofieldset,
                                                      $general,
                                                      $carousel,
                                                      $pagerfieldset,
                                                      $controlsfieldset
                                                      ) {
   $_bx_slider_js = "";
  if($general["mode"] != 'horizontal') $_bx_slider_js.= "mode: '{$general["mode"]}',";
  if($general["speed"] != 500) $_bx_slider_js.= "speed: {$general["speed"]},";
  if($general["slideMargin"] != 0) $_bx_slider_js.= "slideMargin: {$general["slideMargin"]},";
  if($general["startSlide"] != 0) $_bx_slider_js.= "startSlide: {$general["startSlide"]},";
  if($general["randomStart"] != false) $_bx_slider_js.= "randomStart: {$general["randomStart"]},";
  if($general["infiniteLoop"] != true) $_bx_slider_js.= "infiniteLoop: {$general["infiniteLoop"]},";
  if($general["hideControlOnEnd"] != false) $_bx_slider_js.= "hideControlOnEnd: {$general["hideControlOnEnd"]},";
  if($general["captions"] != false) $_bx_slider_js.= "captions: {$general["captions"]},";
  if($pagerfieldset["pager"] != true) $_bx_slider_js.= "pager: {$pagerfieldset['pager']},";
  if($pagerfieldset["pagerType"] != 'full') $_bx_slider_js.= "pagerType: '{$pagerfieldset["pagerType"]}',";
  if($controlsfieldset["controls"] != true) $_bx_slider_js.= "controls: {$controlsfieldset["controls"]},";
  if($autofieldset["auto"] != false) $_bx_slider_js.= "auto: {$autofieldset["auto"]},";
  if($autofieldset["pause"] != 4000) $_bx_slider_js.= "pause: {$autofieldset["pause"]},";
  if($carousel["minSlides"] != 1) $_bx_slider_js.= "minSlides: {$carousel["minSlides"]},";
  if($carousel["maxSlides"] != 1) $_bx_slider_js.= "maxSlides: {$carousel["maxSlides"]},";
  if($general["ticker"] != false) $_bx_slider_js.= "ticker: {$general["ticker"]},";
  if($general["tickerHover"] != false) $_bx_slider_js.= "tickerHover: {$general["tickerHover"]},";
  if($general["adaptiveHeight"] != false) $_bx_slider_js.= "adaptiveHeight: {$general["adaptiveHeight"]},";
  if($general["adaptiveHeightSpeed"] != 500) $_bx_slider_js.= "adaptiveHeightSpeed: {$general["adaptiveHeightSpeed"]},";
  if($general["video"] != false) $_bx_slider_js.= "video: {$general["video"]},";
  if($general["touchEnabled"] != true) $_bx_slider_js.= "touchEnabled: {$general["touchEnabled"]},";
  if($general["preloadImages"] != 'visible') $_bx_slider_js.= "preloadImages: '{$general["preloadImages"]}',";
  if($general["swipeThreshold"] != 50) $_bx_slider_js.= "swipeThreshold: {$general["swipeThreshold"]},";
  if($general["oneToOneTouch"] != true) $_bx_slider_js.= "oneToOneTouch: {$general["oneToOneTouch"]},";
  if($general["preventDefaultSwipeX"] != true) $_bx_slider_js.= "preventDefaultSwipeX: {$general["preventDefaultSwipeX"]},";
  if($general["preventDefaultSwipeY"] != false) $_bx_slider_js.= "preventDefaultSwipeY: {$general["preventDefaultSwipeY"]},";
  if($pagerfieldset["pagerShortSeparator"] != ' / ') $_bx_slider_js.= "pagerShortSeparator: '{$pagerfieldset["pagerShortSeparator"]}',";
  if($controlsfieldset["nextText"] != 'Next') $_bx_slider_js.= "nextText: '{$controlsfieldset["nextText"]}',";
  if($controlsfieldset["prevText"] != 'Prev') $_bx_slider_js.= "prevText: '{$controlsfieldset["prevText"]}',";
  if($controlsfieldset["startText"] != 'Start') $_bx_slider_js.= "startText: '{$controlsfieldset["startText"]}',";
  if($controlsfieldset["stopText"] != 'Stop') $_bx_slider_js.= "stopText: '{$controlsfieldset["stopText"]}',";
  if($controlsfieldset["autoControls"] != false) $_bx_slider_js.= "autoControls: {$controlsfieldset["autoControls"]},";
  if($controlsfieldset["autoControlsCombine"] != false) $_bx_slider_js.= "autoControlsCombine: {$controlsfieldset["autoControlsCombine"]},";
  if($autofieldset["autoHover"] != false) $_bx_slider_js.= "autoHover: {$autofieldset["autoHover"]},";
  if($autofieldset["autoDelay"] != 0) $_bx_slider_js.= "autoDelay: {$autofieldset["autoDelay"]},";
  if($carousel["moveSlides"] != 1) $_bx_slider_js.= "moveSlides: {$carousel["moveSlides"]},";
  if($carousel["slideWidth"] != 0) $_bx_slider_js.= "slideWidth: {$carousel["slideWidth"]},";
  if($general["useCSS"] != true) $_bx_slider_js.= "useCSS: {$general["useCSS"]},";
  if($autofieldset["autoDirection"] != 'next') $_bx_slider_js.= "autoDirection: '{$autofieldset["autoDirection"]}',";

  return filter_xss(trim($_bx_slider_js));
}


function _template_preprocess_bxslider(&$variables, $settings, $type ,$id = NULL) {
  $bxslider_id = !empty($id) ? $type.'_'.$id : $type;
  $rand = rand(1, 100);
  $bxslider_id = $bxslider_id.'_'.$rand;
  //_bxslider_set_extra_css($settings['general']);
  _bxslider_add_js($settings, $bxslider_id);

  $variables['classes_array'][] = 'bxslider';
  //$variables['classes_array'][] = 'bxslider-'.$type;
  $variables['attributes_array']['bxslider-id'] = $bxslider_id;
}

/**
 * Gets the path to the Bxslider library.
 */
function _bxslider_library_path() {
  //$library_path = libraries_get_path('bxslider');
  $library_path = drupal_get_path('module', 'bxslider') . '/custom-jquery-bxslider-js';
  if (!empty($library_path)) {
    $files = glob($library_path . '/jquery.bxslider.min.js');
    if (!$bxslider_path = array_shift($files)) { return $bxslider_path; }
    else {
      $files = glob($library_path . '/jquery.bxslider.js');
      if ($bxslider_path = array_shift($files)) { return $bxslider_path; }
    }
  }
  return FALSE;
}
