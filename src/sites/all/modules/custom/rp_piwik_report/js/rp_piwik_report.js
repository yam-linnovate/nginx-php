(function($) {
  Drupal.behaviors.rp_piwik_report = {
    attach: function(context, settings) {

      var index = 0;
      var formArticles = 'rp-piwik-report-most-viewed-articles-content-type-edit-form';

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
              $(this).parents('.item').hide();
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

      $('#edit-group').hide();
      $('.add-item').hide();

      $('input[name=show_most_viewed_articles]').click(function(){
        if($('input[name=show_most_viewed_articles]').attr('checked')){
          $('#edit-group').hide();
          $('.add-item').hide();
          $('.select-piwik').show();
        }
        else{
          $('#edit-group').show();
          $('.add-item').show();
          $('.select-piwik').hide();
        }
        
      });

      var not_panelModalContent_i = ($('#modalContent').length == 0) ? true : false;
      var not_panels_edit_i = ($('.panels-ipe-editing').length == 0) ? true : false;
      if (not_panelModalContent_i && not_panels_edit_i  && $('.pane-most-viewed-articles > .pane-content').length != 0) {
          $('.pane-most-viewed-articles .wapper-article').slick({
            dots: false,
            slidesToShow: 3,
            autoplay: false,
            rtl: false,
            prevArrow: '<div class="slick-prev"><div class="prev-arrow"><img src="sites/all/themes/republish_theme/images/prev-arrow.png" /></div><div class="prev-slick-img">&nbsp;</div><div class="prev-text"></div></div>',
            nextArrow: '<div class="slick-next"><div class="next-arrow"><img src="sites/all/themes/republish_theme/images/next-arrow.png" /></div><div class="next-slick-img">&nbsp;</div><div class="next-text"></div></div>',
          });
        }
      }
  };
})(jQuery);
 