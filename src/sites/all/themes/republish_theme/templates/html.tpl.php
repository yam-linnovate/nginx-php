<?php
/**
 * @file
 * Default theme implementation to display the basic html structure of a single
 * Drupal page.
 *
 * Variables:
 * - $css: An array of CSS files for the current page.
 * - $language: (object) The language the site is being displayed in.
 *   $language->language contains its textual representation.
 *   $language->dir contains the language direction. It will either be 'ltr' or 'rtl'.
 * - $rdf_namespaces: All the RDF namespace prefixes used in the HTML document.
 * - $grddl_profile: A GRDDL profile allowing agents to extract the RDF data.
 * - $head_title: A modified version of the page title, for use in the TITLE tag.
 * - $head: Markup for the HEAD section (including meta tags, keyword tags, and
 *   so on).
 * - $styles: Style tags necessary to import all CSS files for the page.
 * - $scripts: Script tags necessary to load the JavaScript files and settings
 *   for the page.
 * - $page_top: Initial markup from any modules that have altered the
 *   page. This variable should always be output first, before all other dynamic
 *   content.
 * - $page: The rendered page content.
 * - $page_bottom: Final closing markup from any modules that have altered the
 *   page. This variable should always be output last, after all other dynamic
 *   content.
 * - $classes String of classes that can be used to style contextually through
 *   CSS.
 *
 * @see template_preprocess()
 * @see template_preprocess_html()
 * @see template_process()
 */
?>
<?php print $doctype; ?>
<?php print $html; ?>
<head<?php print $rdf->profile; ?>>

  <?php print $head; ?>

  <title><?php print $head_title; ?></title>
  
  <?php print $styles; ?>
  <?php print $scripts; ?>
  
  <?php // Eenable HTML5 elements in IE ?>
  <?php print $html5shiv; ?>

  <!-- Google Tag Manager -->
  <script>(function(w,d,s,l,i){w[l]=w[l]||[];w[l].push({'gtm.start':
  new Date().getTime(),event:'gtm.js'});var f=d.getElementsByTagName(s)[0],
  j=d.createElement(s),dl=l!='dataLayer'?'&l='+l:'';j.async=true;j.src=
  'https://www.googletagmanager.com/gtm.js?id='+i+dl;f.parentNode.insertBefore(j,f);
  })(window,document,'script','dataLayer','GTM-P59LWQZ');</script>
  <!-- End Google Tag Manager -->

  <script type='text/javascript'>var _atsc_paq = _atsc_paq || [];
  _atsc_paq.push(['atTrackPageView']);
  _atsc_paq.push(['atEnableLinkTracking']);(function () {_atsc_paq.push(['setCookieDomain', 'atsc.activetrail.com']);
  _atsc_paq.push(['atSetSiteId', 'dd389543-682f-4606-ba34-445927859622']);
  _atsc_paq.push(['setUserId', '_atscid']);
  _atsc_paq.push(['atSetTrackerUrl', '//atsc.activetrail.com/api/Track']);
  _atsc_paq.push(['addListener', document]);
  _atsc_paq.push(['addListenerIdle', document]);
  _atsc_paq.push(['addListenerScrollTo', document]);
  _atsc_paq.push(['addListenerCloseTab', document]);
  var atsc_d = document, atsc_g = atsc_d.createElement('script'), atsc_s = atsc_d.getElementsByTagName('script')[0]; atsc_g.type = 'text/javascript'; atsc_g.type = 'text/javascript';atsc_g.async = true; atsc_g.defer = true; atsc_g.src = '//atsc.activetrail.com/Scripts/Atsc.js'; atsc_s.parentNode.insertBefore(atsc_g, atsc_s);})();</script>

  <!-- Hotjar Tracking Code for https://www.nadlancenter.co.il -->
  <script>
      (function(h,o,t,j,a,r){
          h.hj=h.hj||function(){(h.hj.q=h.hj.q||[]).push(arguments)};
          h._hjSettings={hjid:1071466,hjsv:6};
          a=o.getElementsByTagName('head')[0];
          r=o.createElement('script');r.async=1;
          r.src=t+h._hjSettings.hjid+j+h._hjSettings.hjsv;
          a.appendChild(r);
      })(window,document,'https://static.hotjar.com/c/hotjar-','.js?sv=');
  </script>


  <meta name="google-site-verification" content="Bc4ZLkLpERhOOAyQUB3qHlYoNditeIIlSOhwFbB0EJQ" />
</head>
<body class="<?php print $classes; ?>" <?php print $attributes;?>>
  
  <?php // Prompt IE users to install Chrome Frame ?>
  <?php print $prompt_cf; ?>

  <?php target($page_top); ?>
  <?php target($page); ?>
  <?php target($page_bottom); ?>

  <!-- Google Tag Manager (noscript) -->
  <noscript><iframe src="https://www.googletagmanager.com/ns.html?id=GTM-P59LWQZ"
  height="0" width="0" style="display:none;visibility:hidden"></iframe></noscript>
  <!-- End Google Tag Manager (noscript) -->
  <script>
  (function(b,c,e,f,g){f=b.createElement(c),g=b.getElementsByTagName(c)[0],f.async=1,f.src='https://www.overlayBI.com/snippet/'+e+'.js',g.parentNode.insertBefore(f,g)})(document,'script','86570817');
  </script>

</body>
</html>
