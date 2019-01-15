(function($) {
    Drupal.behaviors.rp_head_to_head = {
        attach: function(context, settings) {

            function disablePollButton() {
                $('.poll-wrapper').addClass('clicked');
                // $('.poll-wrapper').css('pointer-events', 'none');
                $('.poll-img').css('opacity', '0.5');
                $('.poll-img').css('cursor', 'default');
                $('.panel-col-first .poll-button').css('background', 'rgba(215, 9, 25, 0.45)');
                $('.panel-col-last .poll-button').css('background', 'rgba(3, 81, 120, 0.55)');
                $('.poll-button').css('cursor', 'default');

            }
            //head-to-head node

            if ($('body').hasClass('node-type-head-to-head')) {

                //remove button
                var nid = document.URL.split('/').pop();
                $('.panel-col-last .poll-img img').attr('src', '/sites/all/themes/republish_theme/images/blue_like.png');
                $('.panel-col-first .poll-img img').attr('src', '/sites/all/themes/republish_theme/images/red_like.png');
                if (getCookie('polled_' + nid) != null) {
                    disablePollButton();
                }
                // else {
                //     $.ajax({
                //         url: "/head-to-head/ip",
                //         type: 'GET',
                //         data: {
                //             nid: nid,
                //             ts: new Date().getTime(),
                //         },
                //         success: function(res) {
                //             //res: true-was found, false-wasn't found
                //             if (res.polled) {
                //                 disablePollButton();
                //                 setCookie('polled_' + nid, true);

                //             }

                //         },
                //         error: function(res) {}
                //     });

                // }
            }

            $.fn.center = function() {
                var widthItem = this.css('width');
                widthItem = widthItem.substring(0, widthItem.length - 2);
                this.css("position", "absolute");
                if ($('body').width() < widthItem)
                    this.css("width", $('body').width());
                this.css("top", window.pageYOffset);
                this.css("z-index", 10);
                return this;
            }


            //home page

            $(document).ready(function() {
                if (document.URL.split('/')[3] == 'home' || document.URL.split('/')[3] == '') {

                    //notification
                    var show = getCookie('pushPoll');

                    if (show != null) {
                        AlertThanks();
                        deleteCookie('pushPoll');
                        var id = $('.rp-head-to-head-main-wrapper').attr('id');
                        if ($(window).width() < 700)
                            $(window).scrollTop($('#' + id).offset().top - 100);    
                        else $(window).scrollTop($('#' + id).offset().top);

                    }


                }
            });


            //the pane request
            $('.rp-head-to-head-main-wrapper').each(function(index) {

                var pane = $(this);

                //ticker
                var nid = pane.attr('id');
                $.ajax({
                    url: "/head-to-head/get-polls",
                    type: 'GET',
                    data: {
                        nid: nid,
                        ts: new Date().getTime(),
                    },
                    success: function(res) {
                        //var polled = res.polled;
                        var polled = getCookie('polled_' + nid);
                        var dataPositive = new Number(res.positive);
                        var dataNegative = new Number(res.negative);
                        var total = dataPositive + dataNegative;
                        if (total !== 0 && polled) {

                            var percentPositive = Math.round(dataPositive / total * 100);
                            var percentNegative = Math.round(dataNegative / total * 100);

                            percentNegative = {
                                results: percentNegative
                            };
                            percentPositive = {
                                results: percentPositive
                            };
                            var htmlPositive = Mustache.render($('script[type=positive]').html(), percentPositive);
                            var htmlNegative = Mustache.render($('script[type=negative]').html(), percentNegative);

                        } else {
                            var htmlNegative = '<div class="text-wrapper-ticker"><div class="text">נגד</div></div>';
                            var htmlPositive = '<div class="text-wrapper-ticker"><div class="text">בעד</div></div>';

                        }


                        pane.find('.positive-section .ticker').html(htmlPositive);
                        pane.find('.negative-section .ticker').html(htmlNegative);


                    },
                    error: function(res) {
                        var htmlNegative = '<div class="text-wrapper-ticker"><div class="text">נגד</div></div>';
                        var htmlPositive = '<div class="text-wrapper-ticker"><div class="text">בעד</div></div>';
                        pane.find('.positive-section .ticker').html(htmlPositive);
                        pane.find('.negative-section .ticker').html(htmlNegative);
                    }
                });
            });

            //button click-poll

            $('.poll-wrapper').click(function() {

                if (!$(this).hasClass('clicked')) {
                    var poll = $(this).parents('.pane-entity-field').attr('class').indexOf('negative') > -1 ? 0 : 1;
                    var nid = document.URL.split('/').pop();
                    $.ajax({
                        url: "/head-to-head/poll",
                        type: 'POST',
                        data: {
                            nid: nid,
                            //1-positive , 0-negative
                            poll: poll,
                        },
                        success: function(res) {
                            console.log(res);
                            setCookie('pushPoll', true);
                            setCookie('polled_' + nid, true);
                            document.location.href = '/';
                        },
                        error: function(res) {}
                    });
                }

            });


            $(window).scroll(function() {
                $(".push_newsflash_wrapper").css("top", window.pageYOffset);
            });

            function getCookie(c_name) {
                var c_value = document.cookie;
                var c_start = c_value.indexOf(" " + c_name + "=");
                if (c_start == -1) {
                    c_start = c_value.indexOf(c_name + "=");
                }
                if (c_start == -1) {
                    c_value = null;
                } else {
                    c_start = c_value.indexOf("=", c_start) + 1;
                    var c_end = c_value.indexOf(";", c_start);
                    if (c_end == -1) {
                        c_end = c_value.length;
                    }
                    c_value = unescape(c_value.substring(c_start, c_end));
                }
                return c_value;
            }

            function setCookie(c_name, value) {
                var c_value = escape(value);
                var expiration_date = new Date();
                expiration_date.setFullYear(expiration_date.getFullYear() + 1);
                document.cookie = c_name + "=" + c_value + ";path=/; expires=" + expiration_date.toUTCString();
            }

            function deleteCookie(c_name) {
                document.cookie = encodeURIComponent(c_name) + "=deleted; expires=" + new Date(0).toUTCString();
            }



            function AlertThanks() {
                deleteCookie('pushPoll');
                var close = '<div class=top><div class=close>X</div></div>';
                var titleBig = '<div class="title">' + Drupal.t('תודה על הצבעתך') + '</div>';
                var title = '<div class=content>' + 'title' + '</div>';
                var inner = '<div class=push_newsflash_inner>' + titleBig + '</div>';
                var text = '<div class=push_newsflash_wrapper> ' + close + inner + '</div>';
                $(text).appendTo('body');
                $('.push_newsflash_wrapper').center();
                $(document).bind('scroll');
            }


            $(".push_newsflash_wrapper .close").live("click", function() {
                $('.push_newsflash_wrapper').remove();
            });

            $(".push_newsflash_wrapper").live("click", function() {
                $('.push_newsflash_wrapper').remove();
            });
            $("body").click(function() {
                $('.push_newsflash_wrapper').remove();
            });



            function userAgentString() {
                if (navigator.userAgent.match(/Android/i))
                    return 'Android';
                if (navigator.userAgent.match(/BlackBerry/i))
                    return 'BlackBerry';
                if (navigator.userAgent.match(/iPhone/i))
                    return 'iPhone';
                if (navigator.userAgent.match(/iPad|iPod/i))
                    return 'iPad|iPod';
                if (navigator.userAgent.match(/Windows Phone/i))
                    return 'Windows Phone';
                else
                    return 'Desktop';

            };




            function add0Prefix(num) {
                if (num < 10)
                    return '0' + num;
                else return num;
            }


            function sendData() {
                var currentTime = new Date();
                var toEncrypte = '' + currentTime.getFullYear() + add0Prefix(currentTime.getMonth()) + add0Prefix(currentTime.getDate()) + add0Prefix(currentTime.getHours()) + add0Prefix(currentTime.getMinutes());

                var token = SHA1(toEncrypte);
                console.log(token);
            }


            /**
             *  Secure Hash Algorithm (SHA1)
             *  http://www.webtoolkit.info/
             **/
            function SHA1(msg) {
                function rotate_left(n, s) {
                    var t4 = (n << s) | (n >>> (32 - s));
                    return t4;
                };

                function lsb_hex(val) {
                    var str = "";
                    var i;
                    var vh;
                    var vl;
                    for (i = 0; i <= 6; i += 2) {
                        vh = (val >>> (i * 4 + 4)) & 0x0f;
                        vl = (val >>> (i * 4)) & 0x0f;
                        str += vh.toString(16) + vl.toString(16);
                    }
                    return str;
                };

                function cvt_hex(val) {
                    var str = "";
                    var i;
                    var v;
                    for (i = 7; i >= 0; i--) {
                        v = (val >>> (i * 4)) & 0x0f;
                        str += v.toString(16);
                    }
                    return str;
                };

                function Utf8Encode(string) {
                    string = string.replace(/\r\n/g, "\n");
                    var utftext = "";
                    for (var n = 0; n < string.length; n++) {
                        var c = string.charCodeAt(n);
                        if (c < 128) {
                            utftext += String.fromCharCode(c);
                        } else if ((c > 127) && (c < 2048)) {
                            utftext += String.fromCharCode((c >> 6) | 192);
                            utftext += String.fromCharCode((c & 63) | 128);
                        } else {
                            utftext += String.fromCharCode((c >> 12) | 224);
                            utftext += String.fromCharCode(((c >> 6) & 63) | 128);
                            utftext += String.fromCharCode((c & 63) | 128);
                        }
                    }
                    return utftext;
                };
                var blockstart;
                var i, j;
                var W = new Array(80);
                var H0 = 0x67452301;
                var H1 = 0xEFCDAB89;
                var H2 = 0x98BADCFE;
                var H3 = 0x10325476;
                var H4 = 0xC3D2E1F0;
                var A, B, C, D, E;
                var temp;
                msg = Utf8Encode(msg);
                var msg_len = msg.length;
                var word_array = new Array();
                for (i = 0; i < msg_len - 3; i += 4) {
                    j = msg.charCodeAt(i) << 24 | msg.charCodeAt(i + 1) << 16 |
                        msg.charCodeAt(i + 2) << 8 | msg.charCodeAt(i + 3);
                    word_array.push(j);
                }
                switch (msg_len % 4) {
                    case 0:
                        i = 0x080000000;
                        break;
                    case 1:
                        i = msg.charCodeAt(msg_len - 1) << 24 | 0x0800000;
                        break;
                    case 2:
                        i = msg.charCodeAt(msg_len - 2) << 24 | msg.charCodeAt(msg_len - 1) << 16 | 0x08000;
                        break;
                    case 3:
                        i = msg.charCodeAt(msg_len - 3) << 24 | msg.charCodeAt(msg_len - 2) << 16 | msg.charCodeAt(msg_len - 1) << 8 | 0x80;
                        break;
                }
                word_array.push(i);
                while ((word_array.length % 16) != 14) word_array.push(0);
                word_array.push(msg_len >>> 29);
                word_array.push((msg_len << 3) & 0x0ffffffff);
                for (blockstart = 0; blockstart < word_array.length; blockstart += 16) {
                    for (i = 0; i < 16; i++) W[i] = word_array[blockstart + i];
                    for (i = 16; i <= 79; i++) W[i] = rotate_left(W[i - 3] ^ W[i - 8] ^ W[i - 14] ^ W[i - 16], 1);
                    A = H0;
                    B = H1;
                    C = H2;
                    D = H3;
                    E = H4;
                    for (i = 0; i <= 19; i++) {
                        temp = (rotate_left(A, 5) + ((B & C) | (~B & D)) + E + W[i] + 0x5A827999) & 0x0ffffffff;
                        E = D;
                        D = C;
                        C = rotate_left(B, 30);
                        B = A;
                        A = temp;
                    }
                    for (i = 20; i <= 39; i++) {
                        temp = (rotate_left(A, 5) + (B ^ C ^ D) + E + W[i] + 0x6ED9EBA1) & 0x0ffffffff;
                        E = D;
                        D = C;
                        C = rotate_left(B, 30);
                        B = A;
                        A = temp;
                    }
                    for (i = 40; i <= 59; i++) {
                        temp = (rotate_left(A, 5) + ((B & C) | (B & D) | (C & D)) + E + W[i] + 0x8F1BBCDC) & 0x0ffffffff;
                        E = D;
                        D = C;
                        C = rotate_left(B, 30);
                        B = A;
                        A = temp;
                    }
                    for (i = 60; i <= 79; i++) {
                        temp = (rotate_left(A, 5) + (B ^ C ^ D) + E + W[i] + 0xCA62C1D6) & 0x0ffffffff;
                        E = D;
                        D = C;
                        C = rotate_left(B, 30);
                        B = A;
                        A = temp;
                    }
                    H0 = (H0 + A) & 0x0ffffffff;
                    H1 = (H1 + B) & 0x0ffffffff;
                    H2 = (H2 + C) & 0x0ffffffff;
                    H3 = (H3 + D) & 0x0ffffffff;
                    H4 = (H4 + E) & 0x0ffffffff;
                }
                var temp = cvt_hex(H0) + cvt_hex(H1) + cvt_hex(H2) + cvt_hex(H3) + cvt_hex(H4);

                return temp.toLowerCase();
            }
        }
    }

})(jQuery);
