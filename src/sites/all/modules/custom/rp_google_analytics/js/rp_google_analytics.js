(function($) {
  Drupal.behaviors.rp_google_analytics = {
    attach: function(context, settings) {

      if ($('#most-viewed-articles-wrapper').length) {
        var link = '/most_viewed_articles?time=' + Math.floor(Date.now() / 1000);
        $('#most-viewed-articles-wrapper')[0].innerHTML = '';
        $.ajax({
          url: link,
          type: 'GET',
          dataType: 'json',
          data: {
             
          },
          success: function(res) {
            if (res.success == true)
              $('#most-viewed-articles-wrapper')[0].innerHTML = res.data;
          },
          error: function(res) {}
        });
      }

      if ($('#most-viewed-opinions-wrapper').length) {
        var link = '/most_viewed_opinions?time=' + Math.floor(Date.now() / 1000);
        var pid = $('#most-viewed-opinions-wrapper').parent().get(0).id;
        $('#most-viewed-opinions-wrapper')[0].innerHTML = '';
        $.ajax({
          url: link,
          type: 'GET',
          dataType: 'json',
          data: {},
          success: function(res) {
            if (res.success == true)
              $('#most-viewed-opinions-wrapper')[0].innerHTML = res.data;
          },
          error: function(res) {}
        });
      }

      if ($('#most-viewed-videos-wrapper').length) {
        var link = '/most_viewed_videos?time=' + Math.floor(Date.now() / 1000);
        $('#most-viewed-videos-wrapper')[0].innerHTML = '';
        $.ajax({
          url: link,
          type: 'GET',
          dataType: 'json',
          data: {},
          success: function(res) {
            if (res.success == true)
              $('#most-viewed-videos-wrapper')[0].innerHTML = res.data;
          },
          error: function(res) {}
        });
      }

    }
  };
})(jQuery);
