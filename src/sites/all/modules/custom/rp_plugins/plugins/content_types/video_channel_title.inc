<?php
/**
 * Plugin info
 */
$plugin = array(
  'title' => t('Video Channel Title'),
  'single' => TRUE,
  'category' => array(t('Video Page'), -9),
);

/**
 * Run-time rendering of the body of the block.
 */
function rp_plugins_video_channel_title_content_type_render($subtype, $conf, $args, $context) {
  $output = '<h1 class="pane-title">' . t('נדל"ן') .'<span>' . t('TV') . '</span>' . '</h1>';

  if(isset($conf['api'])){
        $content = new stdClass();
        return $content;
    }

    $block = new stdClass();
  $block->title = '';
  $block->content = $output;

  return $block;
}