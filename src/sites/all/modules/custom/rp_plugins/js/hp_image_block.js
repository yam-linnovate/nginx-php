(function ($) {
    Drupal.behaviors.hp_image_block = {
        attach: function (context, settings) {
            var not_panelModalContent_i = ($('#modalContent').length == 0) ? true : false;
            var not_panels_edit_i = ($('.panels-ipe-editing').length == 0) ? true : false;
            if (not_panelModalContent_i && not_panels_edit_i  && $('.pane-hp-image-block > .pane-content').length != 0) {



                // Slick slider for prev/next thumbnails images
                $('.view-hp-image.view-display-id-block .view-content').slick({
                    dots: false,
                    slidesToShow: 1,
                    autoplay: false,
                    rtl: true,
                    prevArrow: '<div class="slick-prev"><div class="prev-arrow"><img src="sites/all/themes/republish_theme/images/prev-arrow.png" /></div><div class="prev-slick-img">&nbsp;</div><div class="prev-text">תמונה הבאה</div></div>',
                    nextArrow: '<div class="slick-next"><div class="next-arrow"><img src="sites/all/themes/republish_theme/images/next-arrow.png" /></div><div class="next-slick-img">&nbsp;</div><div class="next-text">תמונה קודמת</div></div>',
                });
                function get_prev_slick_img() {
                    // For prev img
                    var prev_slick_img = $('.slick-current').prev('.slick-slide').find('img').attr('src');
                    $('.prev-slick-img img').attr('src', prev_slick_img);
                    $('.prev-slick-img').css('background-image', 'url(' + prev_slick_img + ')');
                    // For next img
                    var prev_next_slick_img = $('.slick-current').next('.slick-slide').find('img').attr('src');
                    $('.next-slick-img img').attr('src', prev_next_slick_img);
                    $('.next-slick-img').css('background-image', 'url(' + prev_next_slick_img + ')');
                }

                function get_next_slick_img() {
                    // For next img
                    var next_slick_img = $('.slick-current').next('.slick-slide').find('img').attr('src');
                    $('.next-slick-img img').attr('src', next_slick_img);
                    $('.next-slick-img').css('background-image', 'url(' + next_slick_img + ')');
                    // For prev img
                    var next_prev_slick_img = $('.slick-current').prev('.slick-slide').find('img').attr('src');
                    $('.prev-slick-img img').attr('src', next_prev_slick_img);
                    $('.prev-slick-img').css('background-image', 'url(' + next_prev_slick_img + ')');
                }

                setTimeout(function () {
                    get_prev_slick_img();
                    get_next_slick_img();
                }, 500);

                $('.view-hp-image.view-display-id-block .view-content').on('click', '.slick-prev', function () {
                    get_prev_slick_img();
                });
                $('.view-hp-image.view-display-id-block .view-content').on('click', '.slick-next', function () {
                    get_next_slick_img();
                });
                $('.view-hp-image.view-display-id-block .view-content').on('swipe', function (event, slick, direction) {
                    if (direction == 'left') {
                        get_prev_slick_img();
                    }
                    else {
                        get_next_slick_img();
                    }
                });


            }


        }
    };

})(jQuery);
