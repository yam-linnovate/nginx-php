
<ul class="<?php print $classes; ?>"<?php print $attributes; ?>>
    <?php foreach ($items as $delta => $item): ?>
      <li class="field-item <?php print $delta % 2 ? 'odd' : 'even'; ?>"><?php print render($item); ?></li>
    <?php endforeach; ?>
</ul>
