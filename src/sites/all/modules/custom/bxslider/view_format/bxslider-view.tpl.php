
<?php foreach ($rows as $delta => $row): ?>

	<?php if ($delta == 0) : ?>
		<ul class="<?php print $classes; ?>" <?php print $attributes; ?>>
	<?php endif; ?>

	<li class="field-item <?php print ($delta % 2 ? 'odd' : 'even'); print ($delta == 0 ? ' field-item-first': ''); ?>">
		<?php if (!empty($title)) : ?>
			<h3 class="title"><?php print $title; ?></h3>
		<?php endif; ?>

		<?php print $row; ?>
	</li>

<?php endforeach; ?>

<?php // added </ul> by drupal ?>
