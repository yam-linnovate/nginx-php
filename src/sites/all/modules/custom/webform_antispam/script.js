//webform spam hide cheker
(function ($) {
  Drupal.behaviors.webformAntispam = {
    attach: function (context, settings) {
      var cheker = $('.webform-component--checker input');
        cheker.each(function () {
          var token = $(this).parent().parent().find('input[name="form_build_id"]').val();
          console.dir(token);
          $(this).val(token+'4z1');
      });
    }
  }
})(jQuery);
