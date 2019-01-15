/*
 * #############################################
 * ##### Sasson - Advanced Drupal Theming. #####
 * #############################################
 *
 *           Starterkit main script.
 */

(function($) {

//   Drupal.behaviors.CommentsCount = {
//     attach: function (context, settings) {
//   		if($('.comments.link .count').length){
//   			$.get('https://graph.facebook.com/v2.4', 
//   				{ 
// 					fields: 'share{comment_count}',
// 			 		id: location.origin + location.pathname 
// 		 		}
// 				,function( data ) {
// 					$('.comments.link .count').text(data.share.comment_count);
// 					$('.comments.link .count').show();
// 			  	}
// 		  	);
//   		}
//     }
//   };

	Drupal.behaviors.SearchInput = {
	    attach: function (context, settings) {

	    	$('.wrap-main-menu .search-icon').click(function() {
		      $('.wrap-second-menu .pane-rp-search-form-simple').toggleClass('open');
		    });
	    }
	};

	Drupal.behaviors.SelectToList = {
	    attach: function (context, settings) {

	    	$(document).ready(function() {
				$('.form-select').each(function (index, element) {
			        $(this).parent()
			            .after()
			            .append("<div class='scrollableList'><div class='selectedOption'></div><ul></ul></div>");

			        $(element).each(function (idx, elm) {
			            $('option', elm).each(function (id, el) {
			                $('.scrollableList ul:last').append('<li value="' + el.value + '">' + el.text + '</li>');
			            });
			            $('.scrollableList ul').hide();
			            // $('.makeMeUl').children('div.selectedOption').text("נושא הפניה");
			        });
                    $('.views-exposed-widget, .webform-component-select').each(function() {
                        var selectText = $(this).find('label').text();
                        $(this).find('.scrollableList:last').children('div.selectedOption').text(selectText);
                    });
			    });

			    $('.selectedOption').on('click', function () {
			        $(this).next('ul').slideToggle(200);
			        $('.selectedOption').not(this).next('ul').hide();
			    });

			    $('.scrollableList ul li').on('click', function () {
			        var selectedLI = $(this).text();
                    var selectedValue = $(this).attr('value');
			        $(this).parent().prev('.selectedOption').text(selectedLI);
			        $(this).parent('ul').hide();
                    $('.form-select').val(selectedValue);
                    $('.form-select').change();
			    });

			    $('.scrollableList').show();
			   // $('.form-select').hide();
			});
	    }
	};

    Drupal.behaviors.FrontPageSlick = {
        attach: function (context, settings) {

            var not_panelModalContent_i = ($('#modalContent').length == 0) ? true : false;
            var not_panels_edit_i = ($('.panels-ipe-editing').length == 0) ? true : false;
            if (not_panelModalContent_i && not_panels_edit_i  && $('.pane-hp-opinions > .pane-content').length != 0) {

                $('.pane-hp-opinions .view-display-id-block .view-content').slick({
                    dots: true,
                    slidesToShow: 4,
                    slidesToScroll: 4,
                    autoplay: false,
                    rtl: true,
                    infinite: true,
                });
            }
        }
    };

    Drupal.behaviors.FrontPageImageSlick = {
        attach: function (context, settings) {

            var not_panelModalContent_i = ($('#modalContent').length == 0) ? true : false;
            var not_panels_edit_i = ($('.panels-ipe-editing').length == 0) ? true : false;
            if (not_panelModalContent_i && not_panels_edit_i  && $('.pane-hp-image > .pane-content').length != 0) {
              var lang = document.documentElement.lang;
               if(lang == "he"){
                lang = true;
               }
               else{
                lang = false;
               }
                // Slick slider for prev/next thumbnails images
                $('.view-hp-image.view-display-id-block .view-content').slick({
                    dots: false,
                    slidesToShow: 1,
                    autoplay: false,
                    rtl: lang,
                    prevArrow: '<div class="slick-prev"><div class="prev-arrow"><img src="sites/all/themes/republish_theme/images/prev-arrow.png" /></div><div class="prev-text"></div></div>',
                    nextArrow: '<div class="slick-next"><div class="next-arrow"><img src="sites/all/themes/republish_theme/images/next-arrow.png" /></div><div class="next-text"></div></div>',
                });
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

                function get_prev_slick_img() {
                    // For prev img
                    var prev_slick_img = $('.view-hp-image.view-display-id-block .slick-current').prev('.view-hp-image.view-display-id-block .slick-slide').find('img').attr('src');
                    $('.view-hp-image.view-display-id-block .prev-slick-img img').attr('src', prev_slick_img);
                    $('.view-hp-image.view-display-id-block .prev-slick-img').css('background-image', 'url(' + prev_slick_img + ')');
                    // For next img
                    var prev_next_slick_img = $('.view-hp-image.view-display-id-block .slick-current').next('.view-hp-image.view-display-id-block .slick-slide').find('img').attr('src');
                    $('.view-hp-image.view-display-id-block .next-slick-img img').attr('src', prev_next_slick_img);
                    $('.view-hp-image.view-display-id-block .next-slick-img').css('background-image', 'url(' + prev_next_slick_img + ')');
                }

                function get_next_slick_img() {
                    // For next img
                    var next_slick_img = $('.view-hp-image.view-display-id-block .slick-current').next('.view-hp-image.view-display-id-block .slick-slide').find('img').attr('src');
                    $('.view-hp-image.view-display-id-block .next-slick-img img').attr('src', next_slick_img);
                    $('.view-hp-image.view-display-id-block .next-slick-img').css('background-image', 'url(' + next_slick_img + ')');
                    // For prev img
                    var next_prev_slick_img = $('.slick-current').prev('.view-hp-image.view-display-id-block .slick-slide').find('img').attr('src');
                    $('.view-hp-image.view-display-id-block .prev-slick-img img').attr('src', next_prev_slick_img);
                    $('.view-hp-image.view-display-id-block .prev-slick-img').css('background-image', 'url(' + next_prev_slick_img + ')');
                }

            }


        }
    };

    Drupal.behaviors.social_node = {
        attach: function (context, settings) {
            var wrapButton = $('#share-wrapper-on-node');
            window.onscroll = function(el) {stickEl()};
            function stickEl() {
            if(wrapButton[0]){
                var sticky = wrapButton[0].offsetTop ;                
                    if (window.pageYOffset > sticky) {
                        wrapButton.addClass("sticky");
                    } else {
                        wrapButton.removeClass("sticky");
                    }
                }
            }
        }
    };

    Drupal.behaviors.jobs_category = {
        attach: function (context, settings) {
            var not_panelModalContent_i = ($('#modalContent').length == 0) ? true : false;
            var not_panels_edit_i = ($('.panels-ipe-editing').length == 0) ? true : false;
            if (not_panelModalContent_i && not_panels_edit_i  && $('.category-container.mobile .rows-container').length != 0) {
                var selector = '.category-container.mobile .rows-container';
                $(selector).slick({
                    rtl: true,
                    slidesToShow: 1,
                    slidesToScroll: 1,
                });
            }
        }
    };

    Drupal.behaviors.hide_empty_panes = {
        attach: function (context, settings) {
            var empty_pane = $('.panels-ipe-empty-pane');
            empty_pane.parent().hide();
        }
    };

    // Drupal.behaviors.upcoming_events_vertical_slider = {
    //     attach: function (context, settings) {
    //         var sectionToMove = $('.pane-upcoming-events-flash .view-content');
    //         sectionToMove.find('.views-row').clone().appendTo(sectionToMove);
    //         var height = sectionToMove.height();
    //         $('.pane-upcoming-events-flash .view-id-events').css('height', height);
    //     }
    // };

    Drupal.behaviors.active_area = {
        attach: function (context, settings) {
           $('.area').click(function(){
            $('.active-area').removeClass('active-area');
            $(this).addClass('active-area');
            $('.active_description').removeClass('active_description');
            var index = $(this).attr('index');
            $('.description').find('[index='+ index +']').addClass('active_description');
           });
        }
    };

})(jQuery);
