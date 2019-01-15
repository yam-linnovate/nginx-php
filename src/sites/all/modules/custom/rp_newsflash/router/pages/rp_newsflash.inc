<?php
/**
 * Page callback 
 */

function rp_newsflash_build_html($subtype, $conf, $args, $context)  {
    $block = 'block_1';
    $output .= $conf['title'];
    $output .= '<div class="newsflash-wrapper">';
    if($conf['vertical'] == 'vertical'){
        $block = 'block_1';
    }
    else{
        $block = 'panel_pane_1';
    }
    $output .= views_embed_view('newsflash', $block);

    return  drupal_json_output(array('success' => true, 'data'=> $output));
}