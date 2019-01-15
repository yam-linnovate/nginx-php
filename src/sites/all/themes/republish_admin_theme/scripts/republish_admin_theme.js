/*
 * ##### Sasson - advanced drupal theming. #####
 *
 * SITENAME scripts.
 *
 */

;(function ($) {
  Drupal.behaviors.addRequiredInputJS = {
    attach: function (context) {
      if ($('input.alt-required').length) {
        var formRequired = '<span class="form-required" title="This field is required.">*</span>'
        if (!$('input.alt-required').parent().hasClass('js-required-added')) {
          $('input.alt-required').siblings('label').append(formRequired)
          $('input.alt-required').parent().addClass('js-required-added')
        }
      }
    }
  }

  Drupal.behaviors.maxlength_warning = {
    attach: function (context, settings) {
        $('.form-item .counter').addClass('messages warning');
    }
};
})(jQuery)
