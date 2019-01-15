(function($) {
 

    Drupal.behaviors.rpElasticsearch = {
        attach: function(context, settings) {
            //add attribute multiple to select2
            $(".form-select").attr('multiple','multiple');
            //add lable to custom select2
            $("#edit-tag").before("<span class='select-placeholder'>Tags</span>");
            $("#edit-unit").before("<span class='select-placeholder'>Unit</span>");
            $("#edit-cassifications").before("<span class='select-placeholder'>Cassifications</span>");
            $("#edit-articles-type").before("<span class='select-placeholder'>Article-type</span>");
            $("#edit-attached-files").before("<span class='select-placeholder'>Attached files</span>");
            $('.select-placeholder').click(function(){
               $(this).parent('.form-item ').find('.select2-selection__rendered').click();
            });

            //reset select list
            $('select#edit-unit').val(0).select2();
            $('select#edit-cassifications').val(0).select2();
            $('select#edit-tag').val(0).select2();
            $('select#edit-attached-files').val(0).select2();
            $('select#edit-articles-type').val(0).select2();

            $("#edit-unit").select2({
                closeOnSelect : false,
                placeholder : false,
                allowHtml: true,
                allowClear: true,
                multiple: true,
                tags: true 
           });

           $("#edit-attached-files").select2({
                closeOnSelect : false,
                placeholder : false,
                allowHtml: true,
                allowClear: true,
                multiple: true,
                tags: true 
           });

           $("#edit-articles-type").select2({
                closeOnSelect : false,
                placeholder : false,
                allowHtml: true,
                allowClear: true,
                multiple: true,
                tags: true 
            });

           
           $("#edit-cassifications").select2({
                closeOnSelect : false,
                placeholder : false,
                allowHtml: true,
                allowClear: true,
                multiple: true,
                tags: true 
            });

            $("#edit-tag").select2({
                closeOnSelect : false,
                placeholder : false,
                allowHtml: true,
                allowClear: true,
                multiple: true,
                tags: true 
           });

            var word = '';
            word = getParameterByName("key");
            if (word)
                $('#edit-key').attr('value', word);

            var tag = '';
            tag = getParameterByName("tag");
            if (tag)
                $('#edit-tag').attr('value', tag);

            var cassification = '';
            cassification = getParameterByName("cassification");
            if (cassification)
                $('#edit-cassifications').attr('value', cassification);     

            var unit = '';
            unit = getParameterByName("unit");
            if (unit)
                $('#edit-unit').attr('value', unit);    

            var article_type = '';
            article_type = getParameterByName("article_type");
            if (article_type)
                $('#edit-articles-type input').attr('value', article_type);    

            var attached_files = '';
            attached_files = getParameterByName("attached_files");
            if (attached_files)
                $('#edit-attached-files input').attr('value', attached_files);      
                
            var start = '';
            start = getParameterByName("satrt");
            if (start)
                $('#edit-start-date input').attr('value', start);

            var end = '';
            end = getParameterByName("end");
            if (end)
                $('#edit-end-date input').attr('value', end);
            
            //count the show result    
            var offset = 1;
            $('#show_more_results').click(function(){
                $("#offset").val() + 1;
                var val = $("#offset").val();
                var num = 0; 
                if ( !isNaN(val) )
                    num= parseInt(val) + 1;
                    $("#offset").attr('value', num);
                    offset = $('#offset').attr('value');
                    doSearch();
            });
            
            doSearch();

            $('.rp_search_form_submit').click(function(e){
            	e.preventDefault();
            	word = $('#edit-key').attr('value');
                tag = $('#edit-tag').attr('value');
                cassification = $('#edit-cassifications').attr('value');
                unit = $('#edit-unit').attr('value');
                article_type = $('#edit-articles-type').attr('value');
                attached_files = $('#edit-attached-files').attr('value');
                start = $('#edit-start-date input').val()
                start = start.replace(/ /g, "/");
                end = $('#edit-end-date input').val()
                end = end.replace(/ /g, "/");
                offset = $('#offset').attr('value');
            	doSearch();

            });

            
        
            function doSearch() {
                $.ajax({
                    url: '/rp_elasticsearch/json',
                    type: 'GET',
                    dataType: 'json',
                    data: {
                        key: word,
                        tag: tag,
                        cassification:cassification,
                        unit:unit,
                        article_type,article_type,
                        attached_files:attached_files,
                        start: start,
                        end: end,
                        offset: offset
                    },
                    success: function(res) {
                    	var html = Mustache.render($('script[type=template]').html(), res);
                    	$('.domain-list.article-list').html(html);
                        $('.total-results').text(res.total);
                    	$('.loader').hide();
                        $('.rendered').show();
                    },
                    error: function(res) {
                    	$('.loader').hide();
                        $('.no-results').html(Drupal.t('An error has occurred!'));
                    }
                })
            }

            function getParameterByName(name) {
                name = name.replace(/[\[]/, "\\\[").replace(/[\]]/, "\\\]");
                var regex = new RegExp("[\\?&]" + name + "=([^&#]*)"),
                    results = regex.exec(location.search);
                return results == null ? "" : decodeURIComponent(results[1].replace(/\+/g, " "));
            }
        }
    };
})(jQuery);