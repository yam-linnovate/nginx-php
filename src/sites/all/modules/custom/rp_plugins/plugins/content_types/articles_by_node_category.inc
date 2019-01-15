<?php
/**
 * Plugin info
 */
$plugin = array(
  'title' => t('Top 3 Articles by current node Category'),
  'single' => TRUE,
  'category' => array(t('Article Page'), -9),
);

/**
 * Run-time rendering of the body of the block.
 */
function rp_plugins_articles_by_node_category_content_type_render($subtype, $conf, $args, $context) {
    $node = menu_get_object();
    $category = $node->field_section[LANGUAGE_NONE][0]['tid'];
    $output = views_embed_view('articles', 'block_1', $category, $node->nid);

  if(isset($conf['api'])){
        $content = new stdClass();
        return $content;
    }


    $block = new stdClass();
    $block->title = '';
    $block->content = $output;

    return $block;
}