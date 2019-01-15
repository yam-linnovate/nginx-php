(function ($) {

    Drupal.behaviors.rp_section_lobby = {
        attach: function (context, settings) {
            var adminForm = '#rp-section-lobby-form';
            $(adminForm).find('.remove-item').click(function () {
                var i = $(".remove-item").index(this);
                $(this).parents('.two-col').hide();
                $(this).parent().find('.form-item-choose input').val("0");

            });

            $(adminForm).find('.two-col .form-item-choose').hide();
            $(adminForm).find('.two-col .form-item-choose').each(function () {
                var val = $(this).find('input').val();
                if (val == '0') {
                    $(this).parents('.two-col').hide()
                }
            });

        }
    }
})(jQuery);