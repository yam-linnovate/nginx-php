(function($) {
  Drupal.behaviors.rp_smart_banner = {
    attach: function(context, settings) {

      if ($('#smart-banner-wrapper').length) {

        function get_data(os, data) {
          if(os == 'ios') {
            if(data.contents.indexOf('<figcaption class="we-rating-count star-rating__count">') != -1) {
              var info = data.contents.split('<figcaption class="we-rating-count star-rating__count">')[1].split('Ratings')[0];
              info = info.replace(',','');
            }
          } else {
            info = '';
          }
          return info;
        }

        function queries(os, queryurl, buttonurl) {
          var link = '/smart_banner/' + os + '/' + Math.floor(Date.now() / 1000);
          $.ajax({
            url: link,
            type: 'GET',
            dataType: 'json',
            data: {
               
            },
            success: function(res) {
              if (res.success == true) {
                if(res.data == 'expired') {
                  $.getJSON(queryurl, function(data) {
                    info = get_data(os, data);
                    if(info) {
                      var rating = info.split(' ')[0];
                      var downloads = info.split(' ')[1];
                      $('.smart-banner-rating .rating').css('width', (rating * 2 * 10) + '%');
                      $('.smart-banner-downloads').html('(' + downloads + ')');
                      $('.pane-rp-smart-banner').addClass('show');
                      $('.smart-banner-button a').attr('href', buttonurl);
                      var paramsLink = '/smart_banner_set_' + os + '_info/' + info;
                      $.ajax({
                        url: paramsLink,
                        type: 'GET',
                        dataType: 'json',
                        data: {
                           
                        },
                        success: function(res) {},
                        error: function(res) {}
                      });
                    } else {
                      $('.pane-rp-smart-banner').addClass('show');
                      $('.smart-banner-statistics').addClass('hide');
                      $('.smart-banner-button a').attr('href', buttonurl);
                    }
                    
                  });
                } else {
                  var rating = res.data.split(' ')[0];
                  var downloads = res.data.split(' ')[1];
                  $('.smart-banner-rating .rating').css('width', (rating * 2 * 10) + '%');
                  $('.smart-banner-downloads').html('('+ downloads + ')');
                  $('.pane-rp-smart-banner').addClass('show');
                  $('.smart-banner-button a').attr('href', buttonurl);
                }
              }
            },
            error: function(res) {}
          });
        }
        
        if(window.navigator.userAgent.indexOf('Mac OS') != -1) {
          queries('ios', 'http://anyorigin.com/go?url=https%3A//itunes.apple.com/app/id1413832071&callback=?', 'https://itunes.apple.com/app/id1413832071');
        } else if(window.navigator.userAgent.indexOf('Android') != -1) {
          $('.pane-rp-smart-banner').html('');
        } else {
          $('#smart-banner-wrapper').html('');
        }

        $('.smart-banner-close').on('click', function() {
          $('.pane-rp-smart-banner').removeClass('show');
        });
        
      }
    }
  };
})(jQuery);
