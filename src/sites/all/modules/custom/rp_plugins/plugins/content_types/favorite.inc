<?php
/**
 * Plugin info
 */
$plugin = array(
    'title' => t('Favorite'),
    'single' => TRUE,
    'category' => array(t('Front Page'), -9),
);

function rp_plugins_favorite_content_type_render($subtype, $conf, $args, $context) {
    $output = '';
    global $base_url;
    $my_favorite = service_links_render_some('my_favorite');
    $my_favorite = '<div class="my-favorite link">' . $my_favorite['service-links-my-favorite'] . '</div>';
    $output .= $my_favorite;


      if(isset($conf['api'])){
        $content = new stdClass();
        return $content;
    }


    $block = new stdClass();
    $block->title = '';
    $block->content = $output;

    return $block;

}

