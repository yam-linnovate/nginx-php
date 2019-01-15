(function ($) {

    Drupal.behaviors.special_projects = {
        attach: function (context, settings) {
          var not_panelModalContent = ($('#modalContent').length == 0) ? true : false;
          var not_panels_edit = ($('.panels-ipe-editing').length == 0) ? true : false;
          if(not_panelModalContent && not_panels_edit && !$('div.special-projects-wrapper.slick-initialized.slick-slider').length && $('.pane-special-project > .pane-content').length != 0 ){
          var selector = '.view-special-projects .view-content';
          $(selector).slick({
            rtl:true,
            slidesToShow: 5,
            slidesToScroll: 1,
            responsive: [
              {
                breakpoint: 1815,
                settings: {
                  slidesToShow: 5,
                  slidesToScroll: 1,
                  infinite: true,
                  dots: true
                }
              },
              {
                breakpoint: 1150,
                settings: {
                  slidesToShow: 3,
                  slidesToScroll: 1,
                  infinite: true,
                  dots: true
                }
              },
              {
                breakpoint: 768,
                settings: {
                  slidesToShow: 1,
                  slidesToScroll: 1
                }
              }
              // You can unslick at a given breakpoint now by adding:
              // settings: "unslick"
              // instead of a settings object
            ]
          });
         }
                         
     }

    }
})(jQuery);
