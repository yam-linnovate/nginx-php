(function ($) {
  Drupal.behaviors.jobs_company = {
    attach: function (context, settings) {
      var selector = '.views-companys.mobile';
      $(selector).slick({
        rtl:true,
        slidesToShow: 1,
        slidesToScroll: 1,
      });
    }
  }
})(jQuery);
