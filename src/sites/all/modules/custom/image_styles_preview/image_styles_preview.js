
(function($) {
  
  var columns = 4;
  var container = $("#block-system-main");
  var itemWidth;
  var containerColumn = container.width() / columns;
  
  
  $(window).load( function() {

    // $('img', container).each(function() {
    //   itemWidth = Math.max($(this).width(), Math.floor($(this).width() / containerColumn) * containerColumn);
    //   $(this).width(itemWidth);
    // });
    
    // Sort them
    $('a.img-link', container).sort( function(a,b) {
      return $(a).height() - $(b).height();
    }).appendTo(container);
    
    // Masonry
    // container.masonry({
    //   itemSelector : "a.img-link",
    //   isRTL: true,
    //   columnWidth: function( containerWidth ) {
    //     return containerWidth / columns;
    //   }
    // });
  });


})(jQuery);
