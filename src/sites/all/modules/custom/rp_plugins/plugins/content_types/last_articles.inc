<?php
/**
 * Plugin info
 */
$plugin = array(
  'title' => t('Last 5 Articles'),
  'single' => TRUE,
  'category' => array(t('Article Page'), -9),
);

/**
 * Run-time rendering of the body of the block.
 */
function rp_plugins_last_articles_content_type_render($subtype, $conf, $args, $context) {
    $output = '';
    $node = menu_get_object();
    $content = new stdClass();

    if(isset($conf['title'])){
        $detect = mobile_detect_get_object();
        $is_mobile = $detect->isMobile();
        $is_tablet = $detect->isTablet();
        if($is_mobile || $is_tablet) {
            $output .= '<h2 class="pane-title">' . t($conf['title']) . '</h2>';
        }
    }
    if ($node){
        $category = $node->field_section[LANGUAGE_NONE][0]['tid'];
        $articles_by_cat_view = views_get_view_result('articles', 'block_1', $category, $node->nid);
        $nids = array($node->nid);
        foreach ($articles_by_cat_view as $key => $value) {
            $nids[] = $value->nid;
        }
        $nids = implode(',', $nids);
        $output_block = views_embed_view('articles', 'block_2', $nids);
        $output .= $output_block;
        foreach ($articles_by_cat_view as $key => $value) {
            $index = $key + 1;
            $content->node_id[$index] = $value->nid;
        }

        //store_pane_content('last_articles', $content);
    } else {
        $articles_by_cat_view = views_get_view_result('articles', 'block_1');
        foreach ($articles_by_cat_view as $key => $value) {
            $nids[] = $value->nid;
        }
        $nids = implode(',', $nids);
        $output_block = views_embed_view('articles', 'block_2', $nids);
        $output .= $output_block;
        foreach ($articles_by_cat_view as $key => $value) {
            $index = $key + 1;
            $content->node_id[$index] = $value->nid;
        }
        //store_pane_content('last_articles', $content);
    }

  if(isset($conf['api'])){
        return $content;
    }


    $block = new stdClass();
    $block->title = '';
    $block->content = $output;

    return $block;
}

function rp_plugins_last_articles_content_type_edit_form($form, &$form_state) {

  unset($form['override_title']);
  unset($form['override_title_text']);
  unset($form['override_title_markup']);
  unset($form['override_title_heading']);
  
  $conf = $form_state['conf'];
  $form['title'] = array(
    '#type' => 'textfield',
    '#title' => t('Title'),
    '#maxlength' => 512,
    '#default_value' => !empty($conf['title']) ? $conf['title'] : '',
  );
  return $form;
}

function rp_plugins_last_articles_content_type_edit_form_submit($form, &$form_state){
    $form_state['conf']['pid'] = $form_state['pane']->pid;
    $form_state['conf']['title'] = $form_state['values']['title'];     
}