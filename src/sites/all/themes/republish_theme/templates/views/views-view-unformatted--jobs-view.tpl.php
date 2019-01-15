<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */

?>
<div class="category-container <?php print $view->display_handler->options['css_class']; ?>">
  <?php if (!empty($title)): ?>
    <div class="jobs-category-header"><?php print $title; ?></div>
  <?php endif; ?>
  <div class="rows-container">
    <?php foreach ($rows as $id => $row): ?>
      <div<?php if ($classes_array[$id]): ?> class="<?php print $classes_array[$id]; ?>"<?php endif; ?>>
        <?php print $row; ?>
      </div>
    <?php endforeach; ?>
  </div>
</div>