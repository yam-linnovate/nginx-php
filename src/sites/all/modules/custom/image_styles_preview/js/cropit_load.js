/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

(function ($) {
    Drupal.behaviors.focus_image = {
        attach: function (context, settings) {
            var image_f = '<div class="image-editor">';
            image_f += '<div class="cropit-image-preview-container"><div class="cropit-image-preview"></div></div><div class="image-size-label">Resize image</div><input type="range" class="cropit-image-zoom-input"><input type="hidden" name="image-data" class="hidden-image-data" /></div >';

            $('#image-styles-preview-render-styles-try').before(image_f);

            var location_img = $(location).attr('search');
            location_img = location_img.substr(7);
            location_img = location_img.substring(9, location_img.length);
            //location_img = location_img.split('articles');

            var pic_path = 'public://' + location_img; //the orginal image after the crop
            var pic_path = pic_path.replace('public://', 'sites/default/files/');
            pic_path = $(location).attr('origin') + '/' + pic_path;

            var p = pic_path.lastIndexOf('.');
            var result = pic_path.substring(p + 1);
            $('[name=hidden_image_type]').val(result);

            $('.image-editor').cropit({
                //quality: .9,
                originalSize: true,
                exportZoom: 1,
                imageBackground: 0,
                //imageBackgroundBorderWidth: 100,
                width: parseInt($('#edit-select-image-style :selected').val().split('x')[0]),
                height: parseInt($('#edit-select-image-style :selected').val().split('x')[1]),
                imageState: {
                    src: pic_path,
                },
            });
            //click on save
            $('#edit-select-image-style').on('click', function () {
                var val_select = $('#edit-select-image-style').val();
                var WH = val_select;

                $('.image-editor').cropit({
                    quality: .9,
                    originalSize: true,
                    exportZoom: 1,
                    //imageBackground: !0,
                    imageBackgroundBorderWidth: 100,
                    imageState: {
                        src: pic_path,
                    },
                });
                $('.image-editor').cropit('previewSize', {width: WH.split('x')[0], height: WH.split('x')[1]});
            });


            $('#edit-image-submit').click(function () {
                if ($('[name=hidden_image_type]').val() == 'jpg') {
                    $('[name=hidden_image_type]').val('jpeg');
                }
                var imageData = $('.image-editor').cropit('export', {
                    type: 'image/' + $('[name=hidden_image_type]').val(),
                    // quality: .9,
                    // originalSize: true,
                });
                $('[name=hidden_load_image]').val(imageData);
            });
        }
    };
})(jQuery);