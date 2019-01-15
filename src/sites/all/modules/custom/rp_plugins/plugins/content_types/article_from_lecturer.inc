<?php
/**
 * Plugin info
 */
$plugin = array(
  'title' => t('Articles from lecturer'),
  'single' => TRUE,
  'category' => array(t('Lecturer Page'), -9),
);

/**
 * Run-time rendering of the body of the block.
 */
function rp_plugins_article_from_lecturer_content_type_render($subtype, $conf, $args, $context) {
  $output = '';
  if($conf['title'])
      $output .= '<h2 class="pane-title">' . t($conf['title']) . '</h2>';
  $writer_term = taxonomy_term_load($args[0]);
  if ($writer_term->field_id_writer){
      $writer_tid = $writer_term->field_id_writer['und'][0]['tid'];
  }else{
      $writer_tid = '';
  }

  if ($writer_tid){
      $view = views_get_view('lecturer_participate_of_evant');
      //$view->setArguments($writer_tid);
      $view->set_display('page');
      if(!empty($args[0])){
          $view->set_arguments(array($writer_tid));
      }
      $view->execute();
      if (!empty($view->result)) {
          $output .= $view->preview();
      }else{
          $output .= t("no result article from this lecturer");
      }
  }else{
      $output .= t("this lecturer no write article ");
  }

  if(isset($conf['api'])){
        $content = new stdClass();
        return $content;
    }


    $block = new stdClass();
  $block->title = '';
  $block->content = $output;

  return $block;
}

function rp_plugins_article_from_lecturer_content_type_edit_form($form, &$form_state) {

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

function rp_plugins_article_from_lecturer_content_type_edit_form_submit($form, &$form_state){
    $form_state['conf']['title'] = $form_state['values']['title'];
}