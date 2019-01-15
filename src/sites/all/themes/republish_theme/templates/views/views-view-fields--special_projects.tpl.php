<?php

/**
 * @file
 * Default simple view template to all the fields as a row.
 *
 * - $view: The view in use.
 * - $fields: an array of $field objects. Each one contains:
 *   - $field->content: The output of the field.
 *   - $field->raw: The raw data for the field, if it exists. This is NOT output safe.
 *   - $field->class: The safe class id to use.
 *   - $field->handler: The Views field handler object controlling this field. Do not use
 *     var_export to dump this object, as it can't handle the recursion.
 *   - $field->inline: Whether or not the field should be inline.
 *   - $field->inline_html: either div or span based on the above flag.
 *   - $field->wrapper_prefix: A complete wrapper containing the inline_html to use.
 *   - $field->wrapper_suffix: The closing tag for the wrapper.
 *   - $field->separator: an optional separator that may appear before a field.
 *   - $field->label: The wrap label text to use.
 *   - $field->label_html: The full HTML of the label to use including
 *     configured element type.
 * - $row: The raw result object from the query, with all data it fetched.
 *
 * @ingroup views_templates
 */
?>
<?php foreach ($fields as $id => $field): ?>
  <?php if (!empty($field->separator)): ?>
    <?php print $field->separator; ?>
  <?php endif; ?>
<?php endforeach; ?>
    <div class="wrap-slider">
      <a href= "<?php print $row->field_field_link[0]['raw']['url'] ?>">
        <div class="image-slider">
           <?php print $fields['field_image_s_project']->content; ?>
        </div>
      </a>
      <?php
      $video = $row->field_field_video[0]['raw']['value'];
      if($video){
          $icon = '<a class="wrap-icon" href="'. $row->field_field_link[0]['raw']['url'] . ' ">' ;
          $icon .= ' <div class="video icon"><span class="icon"></span></div>';
          $icon .= '</a>';
          print $icon;
      }
      ?>
    <a href="<?php print $row->field_field_link[0]['raw']['url']; ?>">
        <div class="shaddow">
            <div class="text-wrapper">
              <?php print $fields['title_1']->content; ?>
                <div class="second-title"><?php print $fields['field_second_title']->content; ?></div>
            </div>
        </div>
        <div class="background"></div>
    </a>
    </div>



