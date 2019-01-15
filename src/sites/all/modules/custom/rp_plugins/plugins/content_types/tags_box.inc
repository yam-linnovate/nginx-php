<?php
/**
 * Plugin info
 */
$plugin = array(
  'title' => t('Tags Box'),
  'single' => TRUE,
  'category' => array(t('Front Page'), -9),
);

/**
 * Run-time rendering of the body of the block.
 */
function rp_plugins_tags_box_content_type_render($subtype, $conf, $args, $context) {
  $output = '<h2 class="pane-title">' . t('תגיות') . '</h2><div class="tags">';
  $voc = taxonomy_vocabulary_machine_name_load('tags');
  $tree = taxonomy_get_tree($voc->vid);
  $content = new stdClass();
  foreach ($tree as $key => $term) {
    $index = $key + 1;
    $content->term_id[$index] = $term->tid;
    $output .= '<div class="item"><a href="/search?tag=' . $term->tid . '">' . $term->name . '</a></div>';
  }
  //store_pane_content('tags_box', $content);
  $output .= '</div>';

  if(isset($conf['api'])){
        return $content;
    }

    $block = new stdClass();
  $block->title = '';
  $block->content = $output;

  return $block;
}