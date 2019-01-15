(function ($) {
  Drupal.behaviors.ws_fsb = {
    scriptadded: false,

    attach: function (context, settings) {
      $('.service-links-facebook', context).click(function (e) {
        var w = 636;
        var h = 420;
        var dualScreenLeft = window.screenLeft != undefined ? window.screenLeft : screen.left;
        var dualScreenTop = window.screenTop != undefined ? window.screenTop : screen.top;
        width = window.innerWidth ? window.innerWidth : document.documentElement.clientWidth ? document.documentElement.clientWidth : screen.width;
        height = window.innerHeight ? window.innerHeight : document.documentElement.clientHeight ? document.documentElement.clientHeight : screen.height;

        var leftPosition = ((width / 2) - (w / 2)) + dualScreenLeft;
        var topPosition = ((height / 2) - (h / 2)) + dualScreenTop;

        var windowFeatures = "status=no,height=" + h + ",width=" + w + ", resizable=yes, left=" + leftPosition + ",top=" + topPosition + ", screenX=" + leftPosition + ",screenY=" + topPosition + ",chrome=yes , toolbar=no,menubar=no,scrollbars=no,location=no,directories=no";
        u=location.href;
        var win = window.open("http://www.facebook.com/sharer.php?u="+encodeURIComponent(u)+"&t=","sharer", windowFeatures);
        win.moveTo(leftPosition, topPosition);
        return false;

    });
    }
  }
})(jQuery);
