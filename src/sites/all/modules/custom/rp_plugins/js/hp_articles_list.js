(function ($) {

    Drupal.behaviors.rpGeneric_lobby = {
        attach: function (context, settings) {
            var index = 0;
            var formArticles = 'rp-plugins-hp-articles-list-content-type-edit-form';

            var formID = $('form.ctools-use-modal-processed');
            if (formID.length > 0) {
                var stringID = formID.get(0).id;
                if (stringID.indexOf(formArticles) > -1) {
                    formID.attr("id", formArticles);
                }
            }
            formArticles = '#' + formArticles;
            var forms = formArticles;
            var formsAll = formArticles;        

            $(forms).find('.item .form-item-choose').each(function () {
                var val = $(this).find('input').val();
                if (val == '0') {
                    $(this).parents('.item').hide()
                }
            });

            $(forms).find('.add-item').click(function () {
                //index++;
                index = $(forms).find('.item:visible').length;
                var item = $(forms).find('.item').eq(index);
                $(item).show();

                $(forms).find('.item .form-item-choose input').eq(index).val("1");
            });
            $(forms).find('.remove-item').click(function () {
                var i = $(".remove-item").index(this);
                $(this).parents('.item').hide();
                $(this).parent().find('.form-item-choose input').val("0");
                $(this).parent().find('.form-item-nid input').val("");
            });

        }
    }
})(jQuery);
