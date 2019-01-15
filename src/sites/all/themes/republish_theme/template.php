<?php

function republish_theme_preprocess_html(&$vars){
  drupal_add_js(libraries_get_path('slick') . '/slick/slick.min.js', 'file');
  drupal_add_css(libraries_get_path('slick') . '/slick/slick.css', 'file');
  drupal_add_css(libraries_get_path('slick') . '/slick/slick-theme.css', 'file');
  
  drupal_add_css(drupal_get_path('theme', 'republish_theme') . '/stylesheets/republish_theme.css', array('group' => 'republish_theme', 'preprocess' => TRUE));
  
  if ($vars['user']) {
    foreach ($vars['user']->roles as $role) {
      $vars['classes_array'][] = 'role-' . drupal_html_class($role);
    }
  }
  if ($panel_page = panels_get_current_page_display()) {
    // Set body class for the name of the panel page layout.
    $vars['classes_array'][] = 'panel-layout-' . str_replace('_', '-', $panel_page->layout);
  }
    //drupal_add_js(drupal_get_path('theme', 'republish_theme') . '/scripts/active-trail.js', 'file');
}

function republish_theme_preprocess_page(&$vars) {
  global $theme_path;
  global $base_url;
  $detect = mobile_detect_get_object();
  $is_mobile = $detect->isMobile();
  $is_tablet = $detect->isTablet();
  // Main menu
  $main_menu_tree = menu_tree_all_data('main-menu');
  $main_menu_expanded = menu_tree_output($main_menu_tree);
  $vars['main_menu_expanded'] = $main_menu_expanded;
  
  // Mini panels as "regions"
  $mini_panels = array(
    'header' => 'header',
    'sub_menu' => 'sub_menu',
    'footer' => 'footer',
    'sub_footer' => 'sub_footer',
  );

  if($vars['theme_hook_suggestions'][0] == 'page__not_found' && $is_mobile || $is_tablet ) {
    $mini_panels = array(
      'header' => 'header',
      'sub_menu' => 'sub_menu',
    );
  }
  
  foreach ($mini_panels as $name => $mini_panel) {
    $block = panels_mini_load($mini_panel);
    $vars[$name] = $block;
  }
  
}

function republish_theme_preprocess_node(&$vars) {
  $node = $vars['node'];
  global $base_url, $theme_path,$language;
  
  $social = '<div class="share-wrapper" id="share-wrapper-on-node" >';
  $comments = '<a href="#comment-form"> <div class="comments link"><span class="count">'.$vars['node']->comment_count.'</span></div></a>';
  $like = '<a><div class="like link"></div></a>';
  if(isset($vars['node']->field_like)) {
    $field_like = field_view_field('node', $vars['node'], 'field_like','full');
    $like = '<a> <div class="like link">'.render($field_like).'</div></a>';
  }
  $url = url('node/' . $vars['node']->nid, array('absolute' => TRUE));
  $mail = '<a href="mailto:?subject='.htmlspecialchars($vars['node']->title).'&amp;body='.t('Hello%2C %0D%0A I read something that might interest you on the site Onet %0D%0A ').$url.'"> <div class="mail link"></div></a>';
  $print = '<div id="print_node" class="print link"></div>';
  if(module_exists('area_print')) {
      $options = array(
        'target_id' => 'panels-ipe-regionid-main_right',
        'button_id' => 'print_node',
        'value' => ' ',
        'type' => 'link',
        // 'custom_css' => drupal_get_path('theme','republish_theme').'/sass/partials/plugins/print.scss',
        );
        $print = '<div id="print_node" class="print link">'.area_print_form($options).'</div>';
    }
  $pdf = '<a href="/node/'.$vars['node']->nid.'/pdf"> <div class="pdf link"></div></a>';
  // $facebook = '';
  // $twitter = '';
  // $whatsapp = '';
  // $my_favorite = '';
  // if (module_exists('service_links')) {
  //   $twitter = service_links_render_some('twitter', $vars['node']);
  //   $facebook = service_links_render_some('facebook', $vars['node']);
  //   $whatsapp = service_links_render_some('whatsapp', $vars['node']);
  //   $my_favorite = service_links_render_some('my_favorite', $vars['node']);
    
  //   $facebook = '<div class="facebook link">' . $facebook['service-links-facebook'] . '</div>';
  //   $twitter = '<div class="twitter link">' . $twitter['service-links-twitter'] . '</div>';
  //   $whatsapp = '<div class="whatsapp link">' . $whatsapp['service-links-whatsapp'] . '</div>';
  //   $my_favorite = '<div class="my-favorite link">' . $my_favorite['service-links-my-favorite'] . '</div>';   
  // }
  $detect = mobile_detect_get_object();
  $is_mobile = $detect->isMobile();
  $is_tablet = $detect->isTablet();
  if ($is_mobile || $is_tablet) {
     $social .= '<div class="social-wrapper">'. $comments . $like . '</div>';
  }
  else {
     $social .= '<div class="social-wrapper">'. $comments . $like . $mail . $pdf. $print .'</div>';
  }
  $social .='</div>';
  $vars['content']['social_bottom'] = array(
    '#type' => 'markup',
    '#markup' => '<div class="bottom-social">' . $social . '</div>',
    '#weight' => 10,
  );

  if(($vars['type'] == 'video' && $vars['is_mobile']) || ($vars['type'] == 'video' && $vars['is_tablet'])) {
    $writer = '';
    $about_the_writer = '';
    if(isset($vars['field_writer'][0]['taxonomy_term'])) {
      $field_writer = $vars['field_writer'][0]['taxonomy_term'];
      $writer = '<div class="writer">';
      $writer_img = theme('image_style', array('style_name' => 'writer_200x200', 'alt' => $field_writer->field_drawing['und'][0]['alt'], 'path' => $field_writer->field_drawing['und'][0]['uri']));
      $writer .= '<div class="writer-img"><a href="/search?writer=' . $field_writer->tid . '">' . $writer_img . '</a></div>';
      // $writer .= '</div>';
      // $writer .= '<div class="writer-desc-wrap">';
      $writer .= '<div class="writer-name">' . t('From') . ' <a href="/search?writer=' . $field_writer->tid . '"><span>' . $field_writer->name . '</span></a></div>';
      $writer .= '<div class="writer-desc"> - ' . $field_writer->description . '</div>';
      $writer .= '</div>';
      $about_the_writer = '<div class="about-the-writer">';
      $about_the_writer .= '<div class="about-the-writer-header">' . t('About the writer') . '</div>';
      $about_the_writer .= '<div class="about-the-writer-content">';
      $about_the_writer .= '<div class="writer-img"><a href="/search?writer=' . $field_writer->tid . '">' . $writer_img . '</a></div>';
      $about_the_writer .= '<div class="writer-info">';
      $about_the_writer .= '<div class="writer-name"><a href="/search?writer=' . $field_writer->tid . '">'. $field_writer->name . '</a></div>';
      $about_the_writer .= '<div class="writer-desc">' . strip_tags($field_writer->description) . '</div>';
      $about_the_writer .= '</div> </div> </div>';
    }
    $vars['writer'] = $writer;
    $vars['about_the_writer'] = $about_the_writer;
  }


  if ($vars['view_mode'] == 'hp_large_article') {
    $vars['theme_hook_suggestions'][] = 'node__article__hp_large';
    //$vars['theme_hook_suggestions'][] = 'node__' . $node->type . '__hp_large';
  }
  if ($vars['view_mode'] == 'hp_midi_article') {
    $vars['theme_hook_suggestions'][] = 'node__article__hp_medium';
  }
  if ($vars['view_mode'] == 'hp_small_article') {
    $vars['theme_hook_suggestions'][] = 'node__article__hp_small';
  }
  if ($vars['view_mode'] == 'hp_video_large') {
    $vars['theme_hook_suggestions'][] = 'node__video__large';
  }
  if ($vars['view_mode'] == 'head_to_head') {
    $vars['theme_hook_suggestions'][] = 'node__' . $node->type . '__head_to_head';
  }
  
  $link_to_node = drupal_get_path_alias('node/' . $vars['node']->nid);
  $vars['link_to_node'] = $link_to_node;

if($vars['type'] == 'article' || $vars['type'] == 'daily_component') {
  // *******start header content*************
  $extra_details = '<div class="extra_details">';
  $separator = '<span class="separator">|</span>';
  $writer = '';
  $compatible_with = '';
  $tested = '';
  $cassification = '';
  $confirmed = '';
  $reference = '';
  $reading_time = '';
  $units = '';
  $writer_img = '';
  $field_article_type = isset($vars['node']->field_article_type[LANGUAGE_NONE]) ? $vars['node']->field_article_type[LANGUAGE_NONE][0]['value']:'';
    if(isset($vars['node']->field_writer[LANGUAGE_NONE])) {
    $writer = '<div class="details">';
    $field_writer = $vars['node']->field_writer[LANGUAGE_NONE][0]['taxonomy_term'];
    if($field_article_type == 'opinion' && isset($field_writer->field_drawing[LANGUAGE_NONE])) {
      $writer_img = theme('image_style', array('style_name' => 'writer_200x200', 'alt' => $field_writer->field_drawing[LANGUAGE_NONE][0]['alt'], 'path' => $field_writer->field_drawing['und'][0]['uri']));
      $writer .= '<div class="writer-img"><a href="/search?writer=' . $field_writer->tid . '">' . $writer_img . '</a></div>';
    }
    $writer .= '<span>' . t('wrote') . ':</span><span class="details-value">';
    $writer .= $field_writer->name;
    $writer .= '</span>';
    $writer .= '</div>';
  }
   if(isset($vars['node']->field_extra_details[LANGUAGE_NONE])) {
    foreach ($vars['node']->field_extra_details[LANGUAGE_NONE] as $value) {
      $item_extra_details = field_collection_item_load($value['value']);
      if(!empty($item_extra_details->field_compatible_with[LANGUAGE_NONE][0]['taxonomy_term'])) {
        $compatible_with .=$separator;
        $compatible_with .= '<div class="details"><span>' . t('compatible with') . ':</span><span class="details-value">';
        $compatible_with .= $item_extra_details->field_compatible_with[LANGUAGE_NONE][0]['taxonomy_term']->name;
        $compatible_with .= '</span></div>';
      }
      if(!empty($item_extra_details->field_tested[LANGUAGE_NONE][0]['taxonomy_term'])) {
        $tested .= $separator;
        $tested .= '<div class="details"><span>' . t('tested') . ':</span><span class="details-value">';
        $tested .= $item_extra_details->field_tested[LANGUAGE_NONE][0]['taxonomy_term']->name;
        $tested .= '</span></div>';
      }
      if(!empty($item_extra_details->field_confirmed[LANGUAGE_NONE][0]['taxonomy_term'])) {
        $confirmed .=$separator;
        $confirmed .= '<div class="details"><span>' . t('confirmed') . ':</span><span class="details-value">';
        $confirmed .= $item_extra_details->field_confirmed[LANGUAGE_NONE][0]['taxonomy_term']->name;
        $confirmed .= '</span></div>';
      }
      if(!empty($item_extra_details->field_reference[LANGUAGE_NONE][0]['value'])) {
        $reference .= $separator;
        $reference .= '<div class="details"><span>' . t('reference') . ':</span><span class="details-value">';
        $reference .= $item_extra_details->field_reference[LANGUAGE_NONE][0]['value'];
        $reference .= '</span></div>';
      }
      if(isset($item_extra_details->field_reading_time[LANGUAGE_NONE][0]['value'])) {
        $reading_time = '<div class="details"><span>'. t('reading time') .':</span><span class="details-value">';
        $reading_time .= $item_extra_details->field_reading_time[LANGUAGE_NONE][0]['value'];
        $reading_time .= '</span></div>';
      }
    }
  }
  $extra_details .= $writer . $compatible_with . $tested .$confirmed;
  $extra_details .= '</div>';
  
  $fields_about_node = '<div class="fields_about_node">';
  if(isset($vars['node']->field_unit[LANGUAGE_NONE])) {
    $units = '<div class="wrapper-units">';
    foreach ($vars['node']->field_unit[LANGUAGE_NONE] as $value) {
      if($value['tid']){
        $term = taxonomy_term_load($value['tid']);
        $field_icon = field_get_items('taxonomy_term', $term, 'field_icon');
        if ($field_icon) {
          $unit = field_view_value('taxonomy_term', $term, 'field_icon', $field_icon[0], array('type' => 'image'));
          $units .= '<div class="unit-icon">' . render($unit) . '<span class="tooltip-unit">'. $term->name .'</span></div>';
        }
      }
    }
    $units .= '</div>';
  }
  if(isset($vars['node']->field_cassification[LANGUAGE_NONE])) {
    $cassification = '<div class="details cassification"><span>' . t('cassification') . ':</span><span class="details-value">';
    $term = taxonomy_term_load($vars['node']->field_cassification[LANGUAGE_NONE][0]['tid']);
    if($term)
      $cassification .= $term->name;
    $cassification .= '</span></div>';
  }
  $date = $separator . '<div class="details"><span>'. t('date:') .'</span><span class="details-value">' .date('d.m.y' ,$vars['node']->created) . '</span></div>';
  $fields_about_node .= '<div class="one_fields_group">'.$units . $cassification . $reference . '</div><div class="one_fields_group time_and_date">' .$reading_time .$date .'</div>';
  $fields_about_node .= '</div>';
  $writer_statement = '';
  if($field_article_type == 'opinion' && $vars['node']->field_writer_statement[LANGUAGE_NONE]) {
    $writer_statement = '<span class="writer_statement">' . $vars['node']->field_writer_statement[LANGUAGE_NONE]['0']['value'] . '</span>';
  }
  $header_content = '<div class="above-img">';
  $header_content .= $writer_statement;
  $header_content .= '<div class="header-content">';
  $header_content .= '<h1>' . $vars['node']->title . '</h1>';
  $header_content .= $vars['content']['social_bottom']['#markup'];
  $header_content .= '</div>';
  $header_content .= $extra_details;
  $header_content .= '<hr>';
  $header_content .= '<div class="sub-header-area">';
  $header_content .= '<div>'.$fields_about_node.'</div>';
  $header_content .= '</div>';
  $header_content .= '</div>';
  $vars['header_content'] = $header_content;
  // *******end header content*************/

//*******start footer content***********/
  $files = '';
    if(isset($vars['node']->field_attached_files[LANGUAGE_NONE])) {
      foreach ($vars['node']->field_attached_files[LANGUAGE_NONE] as $value) {
        $item_attached_files = field_collection_item_load($value['value']);
        if(!empty($item_attached_files->field_file) && !empty($item_attached_files->field_file_type)) {
          //$files .= '<div class="row-attached-file file-type-'.$item_attached_files->field_file_type[LANGUAGE_NONE][0]['value'].'">';
          $files .= '<div class="row-attached-file">';
          $files .= '<img src="/'.drupal_get_path('theme','republish_theme'). '/images/icon_'.$item_attached_files->field_file_type[LANGUAGE_NONE][0]['value'] .'.png"/>';
          $file_kb = round(($item_attached_files->field_file[LANGUAGE_NONE][0]['filesize'] / 1024), 0);
          $file_view = field_view_field('field_collection_item',$item_attached_files, 'field_file');
          $files .= '<div class="file_wrapper">'.render($file_view).'<span class="size-file">' . $file_kb .t(' kb'). '</span></div>';
          //$files .= '<span>' . $file_kb .t(' ק"ב'). '</span>';
          $files .= '</div>';
        }
      }
    }
    $attached_files = '';
    if($files) {
      $attached_files .= '<div class="attached-files">';
      $attached_files .= '<span class="attached-files-title">' . t('attached files') . ':</span>';
      $attached_files .= $files;
      $attached_files .= '</div>';
    }
    $comments_panel = drupal_get_form("comment_node_article_form", (object)array('nid' => $vars['node']->nid));
    $tags = field_view_field('node',$vars['node'],'field_tags');
    $about_the_writer = '';
    if($field_article_type == 'opinion') {
      $about_the_writer = '<div class="about-the-writer">';
      $about_the_writer .= '<div class="writer-img"><a href="/search?writer=' . $field_writer->tid . '">' . $writer_img . '</a></div>';
      $about_the_writer .= '<div class="writer-info">';
      $about_the_writer .= '<div class="writer-name"><a href="/search?writer=' . $field_writer->tid . '">'. $field_writer->name . '</a><span> - '.t('Description wrote').'</span></div>';
      $about_the_writer .= '<div class="writer-desc">' . strip_tags($field_writer->description) . '</div>';
      $about_the_writer .= '</div> </div>';
    }
    $footer_content = '<div class="footer-content">';
    // $footer_content .= '<div>'.render($comments_panel).'</div>';
    $footer_content .= $attached_files;
    $footer_content .= $about_the_writer;
    $footer_content .= '<div>' . render($tags). '</div>';
    $footer_content .= '</div>';
    $vars['footer_content'] = $footer_content;
  //*********end footer content*************/
  }
  
  if($vars['type'] == 'daily_component'){
    $areas = '<div class="content_area">';
      $areas .= '<div class= "areas">';
      foreach ($vars['node']->field_area[LANGUAGE_NONE] as $key=>$value) {
        $item_area = field_collection_item_load($value['value']);
        $term_name = $item_area->field_area_name[LANGUAGE_NONE][0]['taxonomy_term'];
        $active_class = $key == 0 ? 'active-area':'';
        $areas .= '<div class="area ' . $active_class.'" index=' . $key .'>';
        $areas .= '<div class="area_image">' . theme('image_style', array('style_name'=>'area_354x195','path' =>$term_name->field_image_area[LANGUAGE_NONE][0]['uri'])) . '</div>';
        $areas .= '<div class="area_name"><span>' . $term_name->name . '</span></div>';
        $areas .= '</div>';      
      }
      $areas .= '</div>';
      $areas .= '<div class="description">';
      foreach ($vars['node']->field_area[LANGUAGE_NONE] as $key=>$value) {
        $item_area = field_collection_item_load($value['value']);
        if(isset($item_area->field_area_description[LANGUAGE_NONE][0]['value'])) {
          $active_class = $key == 0 ? 'active_description':'';
          $areas .= '<div class="area_description '. $active_class .'" index=' . $key . '><span>' .  $item_area->field_area_description[LANGUAGE_NONE][0]['value'] . '</span></div>';
        }
      }
      $areas .= '</div>';
    $areas .= '</div>';
    $vars['areas'] = $areas;
  }
  

  if($vars['type'] == 'event'){
      if($vars['node']->field_event_writer){
          $field_lecturer = $vars['node']->field_event_writer[LANGUAGE_NONE];
          $size_field_lecturer = sizeof($field_lecturer);
          if($size_field_lecturer == 1){
              $vars['lecturer_num'] = 'one';
              $vars['lecturer_img'] = theme('image_style', array('style_name' => 'writer_200x200', 'path' => $field_lecturer[0]['entity']->field_lecturer_image[LANGUAGE_NONE][0]['uri']));
              $vars['lecturer_name'] = $field_lecturer[0]['entity']->name;
              $vars['lecturer_desc'] = isset($vars['node']->field_event_writer_title[LANGUAGE_NONE][0]['value'])? $vars['node']->field_event_writer_title[LANGUAGE_NONE][0]['value'] : '';
          }else{
              $vars['lecturer_num'] = 'two';
              $vars['lecturer_img'] = theme('image_style', array('style_name' => 'writer_120x120', 'path' => $field_lecturer[0]['entity']->field_lecturer_image[LANGUAGE_NONE][0]['uri'])) . theme('image_style', array('style_name' => 'writer_120x120', 'path' => $field_lecturer[1]['entity']->field_lecturer_image[LANGUAGE_NONE][0]['uri']));
              $vars['lecturer_name'] = $field_lecturer[0]['entity']->name  .t(' together ') . $field_lecturer[1]['entity']->name;
              $vars['lecturer_desc'] = isset($vars['node']->field_event_writer_title[LANGUAGE_NONE][0]['value'])? $vars['node']->field_event_writer_title[LANGUAGE_NONE][0]['value'] : '';

          }
      }else {
          $vars['lecturer_num'] = '';
          $vars['lecturer_img'] = '';
          $vars['lecturer_name'] = '';
          $vars['lecturer_desc'] = '';
      }
  }

}

function republish_theme_preprocess_breadcrumb(&$variables) {
  $title = menu_get_active_trail();
  if(isset($title[1]['path'])) {
    if($title[1]['path'] == 'segel' || $title[1]['path'] == 'jobs' || $title[1]['path'] == 'video' || $title[1]['path'] == 'nadlan-tv' || $title[1]['path'] == 'search' || $title[1]['path'] == 'law-tax' || $title[1]['path'] == 'opinions-Lobby' || $title[1]['path'] == 'contact-us') {
      $panel = panels_get_current_page_display();
      $variables['breadcrumb'][1] = t($panel->title);
    }
  }
  if(isset($title[1]['router_path'])) {
    if($title[1]['router_path'] == 'nadlan_tv') {
      $panel = panels_get_current_page_display();
      $variables['breadcrumb'][1] = t($panel->title);
    }
  }
  if($variables['breadcrumb'] && count($variables['breadcrumb']) > 1) {
    $node = menu_get_object();
    if ($node && $node->type == 'article' && isset($node->field_section[LANGUAGE_NONE][0]['tid'])) {
      $section_title = taxonomy_term_load($node->field_section[LANGUAGE_NONE][0]['tid']);
        $term_path = entity_uri('taxonomy_term', $section_title);
        $term_link = l($section_title->name, $term_path['path']);
        $last_breadrun_item = array_pop($variables['breadcrumb']);
        $variables['breadcrumb'][] = $term_link;
        array_push($variables['breadcrumb'],$last_breadrun_item);
    }
  }
}

function target($fragment) {
  // Create a DOM object.
  $html_obj = new simple_html_dom();

  // Load HTML from a string.
  $html_obj->load($fragment);

  // Remove all plain text fragments.
  // foreach ($html_obj->find('a') as $id ) {
  //   $refText = $id->href;
  //   if (!url_is_external($refText)) {
  //     $id->target = "_self";
  //   } elseif(url_is_external($refText)) {
  //     //$id->target = "_blank";
  //   }
  // }

  // Display the results.
  print $html_obj;
            
  // Release resources to avoid memory leak in some versions.
  $html_obj->clear(); 
  unset($html_obj);
}

function republish_theme_checkbox($variables) {
  $element = $variables['element'];
  $element['#attributes']['type'] = 'checkbox';
  element_set_attributes($element, array('id', 'name', '#return_value' => 'value'));

  $element['#checked'] = 1;
  // Unchecked checkbox has #value of integer 0.
  if (!empty($element['#checked'])) {
    $element['#attributes']['checked'] = 'checked';

  }
  _form_set_class($element, array('form-checkbox'));

  if($element['#id'] == "edit-submitted-approve-1") {
    return '<input' . drupal_attributes($element['#attributes']) . ' /><span class="checkmark"></span>';
  } else {
    return '<input' . drupal_attributes($element['#attributes']) . ' />';
  }
  
}

function republish_theme_views_pre_render(&$view) {
  if ($view->name=='jobs_view') {
    $detect = mobile_detect_get_object();
    $is_mobile = $detect->isMobile();
    $is_tablet = $detect->isTablet();
    if($is_mobile || $is_tablet) {
      $view->display_handler->options['css_class'] = 'mobile';
    }
    foreach($view->result as $r => $result) {
      $categories[$r] = $result->taxonomy_term_data_name;
    }
    $categories_name = array_unique($categories);
    foreach($categories_name as $c => $category_name) {
      $iterator = 0;
      foreach($view->result as $r => $result) {
        if($result->taxonomy_term_data_name == $category_name) {
          if($iterator < 3) {
            $result_new[$r] = $result;
          }
          $iterator += 1;
        }
      }
    }
    $view->result = $result_new;
  }
}
