<?php
/**
 * Plugin info
 */
$plugin = array(
  'title' => t('Writers Box'),
  'single' => TRUE,
  'category' => array(t('Opinion Page'), -9),
);

/**
 * Run-time rendering of the body of the block.
 */
function rp_plugins_writers_box_content_type_render($subtype, $conf, $args, $context) {
  $output = '<h2 class="pane-title">' . t('המומחים') . '</h2><div class="writers">';
  $voc = taxonomy_vocabulary_machine_name_load('writer');
  $tree = taxonomy_get_tree($voc->vid);
  $content = new stdClass();
  foreach ($tree as $key => $term) {
    $index = $key + 1;
    $content->term_id[$index] = $term->tid;
    $writer = taxonomy_term_load($term->tid);
    if ($writer->field_opinion_drawing){
        $image = theme('image_style', array('style_name'=> 'writer_120x120', 'alt' => $field_images->field_image['und'][0]['alt'], 'path' => $writer->field_opinion_drawing[LANGUAGE_NONE][0]['uri']));
    } else {
        $image = '';
    }
    $output .= '<div class="item"><a href="/search?writer=' . $term->tid . '"><div class="writer-img">' . $image . '</div><div class="writer-name">' . $term->name . '</div></a></div>';
  }
  //store_pane_content('writers_box', $content);
  $output .= '</div>';

  if(isset($conf['api'])){
        return $content;
    }

    $block = new stdClass();
  $block->title = '';
  $block->content = $output;

  return $block;
}