<?php
/**
 * Plugin info
 */
$plugin = array(
  'title' => t('sub menu on footer '),
  'single' => TRUE,
  'category' => array(t('footer'), -9),
);

function rp_plugins_sub_menu_on_footer_content_type_render($subtype, $conf, $args, $context) {
  $output = '';

  if($conf['title']){
    $output .= '<h2 class="pane-title">' . t($conf['title']). '</h2>';
  }

  $tree = menu_tree_all_data($conf['menu']);
  $ren = menu_tree_output($tree);

  $output.= "<div class='sub-menu-content'>";
  $output.= drupal_render($ren);
  $output.= "</div>";

  if(isset($conf['api'])){
        $content = new stdClass();
        return $content;
    }


    $block = new stdClass();
  $block->title = '';
  $block->content = $output;

  return $block;
}

function rp_plugins_sub_menu_on_footer_content_type_edit_form($form, &$form_state) {

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
  $menus = menu_get_menus($all = TRUE);
  $form['menu'] = array(
    '#type' => 'select',
    '#title' => t('Menu'),
    '#options' => $menus,
    '#default_value' => !empty($conf['menu']) ? $conf['menu'] : '',
  );
  return $form;
}

function rp_plugins_sub_menu_on_footer_content_type_edit_form_submit($form, &$form_state) {
  $list = array();
  $form_state['conf']['title'] = $form_state['values']['title'];
  $form_state['conf']['menu'] = $form_state['values']['menu'];
}
