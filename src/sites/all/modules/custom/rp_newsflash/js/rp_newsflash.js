(function($) {
  Drupal.behaviors.rp_newsflash = {
    attach: function(context, settings) {


      var not_panelModalContent = ($('#modalContent').length == 0) ? true : false;
      var not_panels_edit = ($('.panels-ipe-editing').length == 0) ? true : false;

      if (!not_panelModalContent || !not_panels_edit) {
            return;
      }
      

      if ($('.pane-newsflash-wrapper').length) {
       // $('.top-third').find('.pane-rp-newsflash-pane').addClass('vertical');
        var link = '/newsflash_html?time=' + Date.now();
        $('.pane-newsflash-wrapper').each(function(){
          $(this).innerHTML = '';
        });
        $.ajax({
          url: link,
          type: 'POST',
          dataType: 'json',
          data: {
          },
          success: function(res) {
            if (res.success == true) {
              $('.pane-newsflash-wrapper')[0].innerHTML = res.data; 
              $('.pane-newsflash-wrapper')[1].innerHTML = res.data;              
              $(this).find('.pane-title').hide();

              try{ window.bxSliderElements["pane-newsflash-wrapper"].destroySlider(); }catch(e){ }
            //  var bxmode = 'horizontal';
             // if($('.top-third .pane-rp-newsflash-pane').find('vertical')){
                // bxmode = 'vertical';
            //  }
            //  else{
             //   bxmode = 'horizontal';
             // }
              window.bxSliderElements["pane-newsflash-wrapper"] = $('.top-third .pane-newsflash-wrapper .view-content').bxSlider({
                mode: 'vertical',
              //  adaptiveHeight: 1,
                auto: 0,
                stopAutoOnClick: 0,
               // autoDirection: "prev",
                controls: 0,
                hideControlOnEnd: 1,
                moveSlides: 1,
                pager: 0,
              //  prevText: "Next",
                speed: 1000,
                ticker: 1,
                tickerHover: 1,
                useCSS: 0,
                startingSlide: 0
              });

              window.bxSliderElements["pane-newsflash-wrapper"] = $('.header .pane-newsflash-wrapper .bxslider-view').bxSlider({
                  adaptiveHeight: 1,
                  auto: 0,
                  stopAutoOnClick: 0,
                  autoDirection: "prev",
                  controls: 0,
                  hideControlOnEnd: 1,
                  moveSlides: 1,
                  pager: 0,
                  prevText: "Next",
                  speed: 1000,
                  ticker: 1,
                  tickerHover: 1,
                  useCSS: 0,
                  startingSlide: 0
               });
              
              $('.pane-newsflash-wrapper .bxslider').addClass('loading-js');
            } else {
              $('.pane-newsflash-wrapper').each(function(){
                $(this).innerHTML = Drupal.t('There is no data.');
              });
            }
          },
          error: function(res) {
            $('.pane-newsflash-wrapper').each(function(){
              $(this).innerHTML = Drupal.t('There is no data.');
            });
          }
        });
      }
      // setTimeout(function(){ 

      //   $('.view-newsflash .field-item').bPopup({
      //      modalClose: false,
      //      opacity: 0.6,
      //      positionStyle: 'fixed' //'fixed' or 'absolute'
      //    });
      // }, 3000);

 
    }
  };
})(jQuery);