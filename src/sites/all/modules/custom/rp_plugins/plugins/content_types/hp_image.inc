<?php
/**
 * Plugin info
 */
$plugin = array(
  'title' => t('Hp Image'),
  'single' => TRUE,
  'category' => array(t('Front Page'), -9),
);

/**
 * Run-time rendering of the body of the block.
 */
function rp_plugins_hp_image_content_type_render($subtype, $conf, $args, $context) {
    $content = new stdClass();
    $output = '';
    $nid = 0;
    $result = db_query("SELECT nid FROM {node} WHERE type = :type AND status = 1 ORDER BY created DESC LIMIT 1", array(':type' => 'hp_image'));
  foreach ($result as $record) {
    $output = '<h2 class="pane-title">' . t('תמונת מצב') . '</h2>';
    $nid = $record->nid;
    $node = node_load($nid);
    if($node) {
      $node = node_view($node, 'default');
      $output .= render($node);
    }
  }
  //store_pane_content('hp_image', array('nid_1'=>$nid));
    $content->node_id[1] = $nid;
  if(isset($conf['api'])){
        return $content;
    }


    $block = new stdClass();
  $block->title = '';
  $block->content = $output;

  return $block;
}