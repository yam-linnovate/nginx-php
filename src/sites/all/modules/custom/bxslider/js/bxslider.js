(function ($) {

  // Categories:
  // -----------
  // - BxSlider Render
  //
  // - Event:  bxslider-click-popup
  //
  // - Fixings


  ///////////////////////////////////////////////////////////////////////////////////////////////////
  //// -----------------------------------  BxSlider Render ------------------------------------ ////
  ///////////////////////////////////////////////////////////////////////////////////////////////////

  // Index:
  // 
  // - object:  window.bxSliderElements
  //
  // - $.fn:    $.fn.BxSliderRender
  //
  // - function-Loading: Drupal.behaviors.BxSliderReload
  //
  // - function-render:  function bxslider_render(selector,index){}
  //
  // - function-fix:  function isRenderBxSlider(_this,media_query){}


  window.bxSliderElements = {};

  //// ---------------------------   $.fn.BxSliderRender   ---------------------------- ////

  $.fn.BxSliderRender = function () {
    $(this).each(function (e) {
      var  el = $(this);
      setTimeout(function () {

        if(isRenderBxSlider(el) == 'render' ){
          bxslider_render(el, 0);
          el.addClass('bxSlider-processed bxSlider-processed-'+ el.attr('bxslider-id'));
          el.addClass('loading-js');
        }else if(isRenderBxSlider(el) == 'reload'){
          bxslider_render(el, 0);
        }

      },300);
    });
  };

  //// -----------------------------------   Load   ------------------------------- ////

  Drupal.behaviors.BxSliderReload = {
    attach: function (context, settings) {

      $(document).ready(function(){
          var not_panelModalContent = ($('#modalContent').length == 0) ? true : false;
          var not_panels_edit = ($('.panels-ipe-editing').length == 0) ? true : false;

          if (not_panelModalContent && not_panels_edit) {
              $('.bxslider-field-formatter, .bxslider-view').BxSliderRender();
          }


      });

    }
  };

  //// ---------------------------------   render   ------------------------------ ////

  function bxslider_render(selector,index){
     try{

      var bxslider_id = $(selector).attr('bxslider-id');

      var settingsBxSlider = Drupal.settings.bxSlider[bxslider_id];

      var obj_settings_bxSlider = eval('{' + eval('{' + settingsBxSlider + '}') + '}');

      obj_settings_bxSlider['startSlide'] = index;

      if(obj_settings_bxSlider['auto'] == 1)
        $(selector).addClass('auto-bxlider');

      try{ window.bxSliderElements[bxslider_id].destroySlider(); }catch(e){ }

      window.bxSliderElements[bxslider_id] = $(selector).bxSlider(obj_settings_bxSlider);

    }
    catch(e){ 
      console.log($(selector).attr('bxslider-id') + ': ' + e); 
    }

  }

  //// ---------------------------   if Render BxSlider   ----------------------- ////

  function isRenderBxSlider(_this,media_query){

    var visible = true; //$(_this).is(":visible");

    var lengthMore1 = ($(_this).find('li').length > 1 || $(_this).hasClass('bxslider-popup-wrapper')) ? true : false;

    var not_panelModalContent = ($('#modalContent').length == 0) ? true : false;

    var not_panels_edit = ($('#panels-ipe-edit-control-form').length == 0) ? true : false;

    var media_query = ($(window).width() > media_query || media_query == undefined );

    var processed = $(_this).hasClass('bxSlider-processed');

    if(visible && lengthMore1 && media_query){
      if(!processed) {
        return 'render';
      }  
      else if(not_panels_edit && not_panelModalContent && processed) {
        return 'reload';
      }
    } else {
      return '';
    }

  }



  ///////////////////////////////////////////////////////////////////////////////////////////////////
  //// ---------------------------  Event:  bxslider-click-popup    ---------------------------- ////
  ///////////////////////////////////////////////////////////////////////////////////////////////////

  // Index:
  //
  // - Event: Click
  //
  // - function: Create Popup-box
  //
  // - function: Display Popup


  //// -----------------------------------  Event: Click  ------------------------------- ////

  $(document).ready(function(){
    $('.bxslider-popup-wrapper').click(function (e) {

      // get: Parent bxslider
      var bxsliderParent = $(this).parents('.view-content');

      // get: id
      var field_id = $(this).find('.bxslider-popup-row').attr('bxslider-id');
      var parent_is_bxslider = bxsliderParent.find('.bxslider-view').hasClass('bxSlider-processed') ? true : false;

      // get: index
      var index = 0;
       if(parent_is_bxslider) {
        index = $(bxsliderParent.find('li:not(.bxslider-popup-row)')).index($(this).parents('li'));
      }
      if(parent_is_bxslider && bxsliderParent.find('.bxslider>li.bx-clone').length >= 1) {
        index--;
      }
       if(!parent_is_bxslider) {
        index = $(bxsliderParent.find('.views-row')).index($(this).parents('.views-row'));
      }
 
      if( isRenderBxSlider($(this),600) == 'render' ){
        if(!bxsliderParent.hasClass('bxSlider-processed-'+field_id)){
          // add class '.processed'
          bxsliderParent.addClass('bxSlider-processed-'+ field_id);

          // get: fields
          var popup_fields = '';
          if(parent_is_bxslider)
             popup_fields = bxsliderParent.find('.bxslider>li:not(.bx-clone)').clone();
          else
             popup_fields = bxsliderParent.find('.views-row').clone();
          var popup_box = bxSliderCreatePopupBox( popup_fields.find('.bxslider-popup-row'), field_id );

          $('body').append(popup_box);

        }

        // Render
        bxSliderDisplayPopup('[bxslider-popup-id='+field_id+']');
        bxslider_render($('[bxslider-popup-id='+field_id+'] .bxslider'), index);

      }

    });

    $('.bx-controls-direction a').live('click',function (e) {
       $(this).parents('.bx-wrapper').find('.bxSlider-processed').removeClass('auto-bxlider');
    });
    $('.bx-controls-direction a').live('mouseover',function (e) {
       $(this).parents('.bx-wrapper').find('.bxSlider-processed').removeClass('auto-bxlider');
       $(this).parents('.bx-wrapper').find('.bxSlider-processed').addClass('auto');
    });
    $('.bx-controls-direction a').live('mouseout',function (e) {
       $(this).parents('.bx-wrapper').find('.auto').addClass('auto-bxlider');
    });
     
  });
  
  //// ---------------------------------  Create: Popup-box ------------------------------- ////

  function bxSliderCreatePopupBox(popup_fields,id){
     
     popup_fields.find('.fb-like').each(function() {
       var htmlPop = $(this).html().replace('noiframe','iframe').replace('/noiframe','/iframe').replace('noiframe-fb-like','iframe-fb-like');
       $(this)[0].innerHTML = htmlPop;
     });

     var popup_imgaes = popup_fields.find('img[data-src],iframe[data-src]');
     $(popup_imgaes).each(function () {
       $(this).attr('src',$(this).attr('data-src'));
       $(this).css({'width': '100%'});
     });

      //popup_fields.css({'width': '100px'});
     var popup_box = $('<div class="bxslider-popup" bxslider-popup-id="'+ id +'">');
     popup_box.css({'margin':'auto','left':'0px','right':'0px'});

     popup_box.append('<div class="inside"><div class="content">');
     popup_box.find('.content').append('<div class="popup-top">');

     popup_box.find('.popup-top').append('<div class="bPopup-close">X</div>');
     popup_box.find('.popup-top').append('<div class="popup-title"></div>');
     popup_box.find('.popup-title').append(popup_fields.find('.title')[0]);
     
     popup_box.find('.content').append('<ul class="bxslider '+id+'" bxslider-id='+id+'>');
     popup_box.find('ul').css({'margin': '0', 'float': 'left'});
     popup_box.find('ul').append(popup_fields);

     return popup_box;
  }

  //// -----------------------------------  Display Popup  ------------------------------- ////

  function bxSliderDisplayPopup(selector){

    var width = ($(window).width() > 1100) ? '950px' : '85%' ;

    var scrollTop = $(window).scrollTop() + 40;

    $(selector).css({'width': width });

    $("body").addClass('display-lightbox');

    $(selector).bPopup({
      closeClass:'bPopup-close', modalClose: true, opacity: 1,
      follow: [false, false], position: [,scrollTop], positionStyle: 'absolute',
      fadeSpeed: 'slow', followSpeed: 1500, modalColor: 'rgba(0, 0, 0, 0.6)',
      onClose: function() { $("body").removeClass('display-lightbox'); }
    });

  }


  ///////////////////////////////////////////////////////////////////////////////////////////////////
  //// -------------------------------------  Fixings    --------------------------------------- ////
  ///////////////////////////////////////////////////////////////////////////////////////////////////

  // Index:
  //
  // - Loading
  //
  // - function render
  //
  // - Resize


  //// -------------------------------------  Load -------------------------------- ////

  $(document).ready(function(){
    fixItemsToRight();
  });

  //// -----------------------------------  function ------------------------------ ////

  function fixItemsToRight(){
    $('.view-video-strip .bx-wrapper').each(function (e) {
        var itemWidth = $('ul.bxslider > li:first-child',this).outerWidth( true );
        var marginLeft = itemWidth - $('.bx-viewport',this).width() % itemWidth - 22; 
        $('ul.bxslider',this).css({ 'margin-left' : (marginLeft) * (-1) });
    });
    $('.pane-rp-list-bxslider .bx-wrapper').each(function (e) {
        var itemWidth = $('ul.list-bx > li:first-child',this).outerWidth( true );
        var marginLeft = itemWidth - $('.bx-viewport',this).width() % itemWidth - 22; 
        $('ul.list-bx',this).css({ 'margin-left' : (marginLeft) * (-1) });
    });
  }

  //// ------------------------------------  Resize ------------------------------ ////

  var headWidth = $(window).width();
  // This only delayes the execution to prevent CPU overhead.
  var jsmq_delayedExec = (function() {
    var timers = {};
    return function (callback, ms, uniqueId) {

      if (!uniqueId)  uniqueId = "Don't call this twice without a uniqueId";
      if (timers[uniqueId])  clearTimeout (timers[uniqueId]);
      timers[uniqueId] = setTimeout(callback, ms);

    };
  })();

  // Trigger on page load and when window is resized.
  $(window).resize(function () {
    jsmq_delayedExec(function(){
      if ($(window).width() != headWidth) {

       headWidth = $(window).width();
      fixItemsToRight();
 
     }
    }, 400, "mq");
  });


})(jQuery);

