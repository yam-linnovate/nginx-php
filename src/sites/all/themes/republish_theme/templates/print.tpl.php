<?php
global $language;
$direction = $language->direction == '1' ? 'rtl' : 'ltr';
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" lang="<?php print $language->language; ?>" xml:lang="<?php print $language->language; ?>">
  <head>
      <?php print $head; ?>
      <title><?php print $node->title; ?></title>
      <?php print $scripts; ?>
      <?php print $sendtoprinter; ?>
      <?php print $robots_meta; ?>
      <?php print $css; ?>
    <?php print '<link rel="stylesheet" type="text/css" href="/sites/all/themes/republish_theme/stylesheets/republish_theme.css" />';  ?>
  </head>
  <body dir="<?php print $direction;?>">
			<div class="print-content"><?php print $content; ?></div>
		</div>
  </body>
</html>