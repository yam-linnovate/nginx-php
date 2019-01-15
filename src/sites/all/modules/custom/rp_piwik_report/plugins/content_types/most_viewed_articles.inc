<?php
/**
 * Plugin info
 */
$plugin = array(
  'title' => t('Most Viewed Articles from piwik'),
  'single' => TRUE,
  'category' => array(t('Front Page'), -9),
);
define('NUM_ITEM_PIWIK_GROUP', 9);
/**
 * Run-time rendering of the body of the block.
 */
function rp_piwik_report_most_viewed_articles_content_type_render($subtype, $conf, $args, $context) {

	drupal_add_js(drupal_get_path('module', 'rp_piwik_report') . '/js/rp_piwik_report.js');

  	$output = '';
    if($conf['title'])
			$output .= '<h2 class="pane-title">' . t($conf['title']) ;

		if($conf['link'] && $conf['link_title']){
			$output .= '<a class="view-more" href="' . $conf['link'] . '">' . t($conf['link_title']) . '</a></h2>';
			}

		
		if($conf['show_most_viewed_articles']){
			if($conf['url'])
				$url =$conf['url'];
			if($conf['filter_limit'])
				$filter_limit = $conf['filter_limit'];	
			if($conf['token_auth'])
		  	$token_auth = $conf['token_auth'];		

			$piwik_list = array(
				'url' => $url,
				'filter_limit' => $filter_limit,
				'token_auth' => $token_auth,
			);

			variable_set('piwik_list',$piwik_list);	

			if(variable_get('piwik_content')){
				$output .='<div class="wapper-article">'; 
				$content = variable_get('piwik_content');

				foreach( $content as $url ){
					$url_from_piwik = $url['url'];
					$path = preg_replace('/\//','',parse_url($url_from_piwik,PHP_URL_PATH),1);
					$org_path = drupal_lookup_path("source", $path);
					$node = menu_get_object("node", 1, $org_path);
					if(isset($node->nid)){
						$nid = $node->nid;
						$node = node_load($nid);
						$output .= rp_piwik_report_build_html($node);
					}		
				} 
				$output .='</div>'; 
			}
		}
		else{
			foreach ($conf['node_id'] as $key => $value) {
				$index = $key + 1;
				$content->node_id[$index] = $value;
				$node = node_load($value);
				if($node) {
					$node_type = $node->type;
		
					if(isset($node->field_hp_image_picture)){
						$field_image = $node->field_hp_image_picture;
					 $field_image_url = file_create_url($field_image[LANGUAGE_NONE][0]['uri']);
					 $field_image = '<img src="' . $field_image_url .'"/>';
					}
					if($node->field_images[LANGUAGE_NONE][0]['value']) {
							$field_image = field_collection_item_load($node->field_images[LANGUAGE_NONE][0]['value']);
							$field_image = $field_image->view('hp_large_video');
							$field_image = render($field_image);
					}
				
					$field_title = $node->title;
					$link_to_node = '/' . drupal_get_path_alias('node/' . $node->nid);

					$output .= '<div class="article" >
													<a href="' . $link_to_node . '">' . $field_image . '</a>
													<div class="' . $node_type . ' icon"><span class="icon"></span></div>
													<a href="' . $link_to_node . '" class="title">' . $field_title . '</a>      
										</div>';
				}
			}
		}

		$block = new stdClass();
    $block->title = '';
		$block->content = $output;
    return $block;
}

function rp_piwik_report_build_html($node){
	$output = "";
	$link_to_node = '/' . drupal_get_path_alias('node/' . $node->nid,'en');
	$field_images = field_collection_item_load($node->field_images[LANGUAGE_NONE][0]['value']);
	
	if($field_images && $link_to_node){
		$output .= '<div class="single-article">';
		$output .= '<div class="article-img"><a href="' . $link_to_node . '">';
		$output .= theme('image_style', array('style_name' => '265x100', 'alt' => $field_images->field_image['und'][0]['alt'], 'path' => $field_images->field_image['und'][0]['uri']));
		$output .= '</a></div>';
	}
	$output .= '<div class="title"><a href="' . $link_to_node . '">' . $node->title . '</a></div></div>';

	return 	$output;
}


function rp_piwik_report_most_viewed_articles_content_type_edit_form($form, &$form_state) {

	drupal_add_js(drupal_get_path('module', 'rp_piwik_report') . '/js/rp_piwik_report.js');

	unset($form['override_title']);
	unset($form['override_title_text']);
	unset($form['override_title_markup']);
	unset($form['override_title_heading']);

	$conf = $form_state['conf'];

	$form['show_most_viewed_articles'] = array(
		'#type' => 'checkbox',
		'#title' => t('Show most viewed articles from piwik'),
		'#maxlength' => 512,
		'#default_value' => !empty($conf['show_most_viewed_articles']) ? $conf['show_most_viewed_articles'] : '',
	);

	$form['title'] = array(
		'#type' => 'textfield',
		'#title' => t('Title'),
		'#maxlength' => 512,
		'#default_value' => !empty($conf['title']) ? $conf['title'] : '',
	);

  $form['link'] = array(
    '#type' => 'textfield',
    '#title' => t('Link to view more'),
    '#maxlength' => 512,
    '#default_value' => !empty($conf['link']) ? $conf['link'] : '',
  );
  $form['link_title'] = array(
    '#type' => 'textfield',
    '#title' => t('Link title'),
    '#maxlength' => 512,
    '#default_value' => !empty($conf['link_title']) ? $conf['link_title'] : '',
  );

	$form['piwik_group'] = array(
    '#type' => 'fieldset',
    '#prefix' => '<div class="select-piwik">',
    '#suffix' => '</div>',
  );

	$form['piwik_group']['url'] = array(
		'#type' => 'textfield',
		'#title' => t('Url'),
		'#maxlength' => 512,
		'#default_value' => !empty($conf['url']) ? $conf['url'] : '',
	);
	$form['piwik_group']['filter_limit'] = array(
		'#type' => 'textfield',
		'#title' => t('Filter Limit'),
		'#maxlength' => 512,
		'#default_value' => !empty($conf['filter_limit']) ? $conf['filter_limit'] : '',
	);
	$form['piwik_group']['token_auth'] = array(
		'#type' => 'textfield',
		'#title' => t('Token Auth'),
		'#maxlength' => 512,
		'#default_value' => !empty($conf['token_auth']) ? $conf['token_auth'] : '',
	);
	//if choose most article
	$form['group'] = array(
    '#type' => 'fieldset',
    '#prefix' => '<div class="sortable">',
    '#suffix' => '</div>',
  );
  for ($i = 0; $i < NUM_ITEM_PIWIK_GROUP; $i++) {
    $form['group'][$i] = array(
      '#type' => 'fieldset',
      '#prefix' => '<div class="item">',
      '#suffix' => '</div>',
    );
    $form['group'][$i]['weight-' . $i] = array(
      '#prefix' => '<div class="form-item-weight" style="display:none">',
      '#suffix' => '</div>',
      '#type' => 'textfield',
      '#default_value' => isset($conf['group'][$i]['weight']) ? $conf['group'][$i]['weight'] : $i,
    );
    $form['group'][$i]['choose-' . $i] = array(
      '#prefix' => '<div class="form-item-choose" style="display:none">',
      '#suffix' => '</div>',
      '#type' => 'textfield',
      '#maxlength' => 1,
      '#default_value' => rp_piwik_report_most_viewed_articles_list_choose($conf, $i),
    );
    $form['group'][$i]['nid-' . $i] = array(
      '#prefix' => '<div class="form-item-nid">',
      '#suffix' => '</div>',
      '#type' => 'textfield',
      '#title' => t('Article ID'),
      '#maxlength' => 100,
      '#autocomplete_path' => 'ctools/autocomplete/node',
      '#default_value' => !empty($conf['group'][$i]['nid']) ? $conf['group'][$i]['nid'] : '',
    );
    $form['group'][$i]['remove'] = array(      
      '#markup' => '<input type="button" value="' . t('Remove Article') . '"/>',
      '#prefix' => '<div class="remove-item">',
      '#suffix' => '</div>',
    );
  }

  $form['add-item'] = array(
    '#markup' => '<input type="button" value="' . t('Add Article') . '"/>',
    '#prefix' => '<div class="add-item">',
    '#suffix' => '</div>',
  );

	return $form;
}

function rp_piwik_report_most_viewed_articles_content_type_edit_form_submit($form, &$form_state){
		$form_state['conf']['pid'] = $form_state['pane']->pid;
		$form_state['conf']['title'] = $form_state['values']['title'];   
		$form_state['conf']['link'] = $form_state['values']['link'];    
		$form_state['conf']['link_title'] = $form_state['values']['link_title']; 
		$form_state['conf']['url'] = $form_state['values']['url']; 
		$form_state['conf']['filter_limit'] = $form_state['values']['filter_limit']; 
		$form_state['conf']['token_auth'] = $form_state['values']['token_auth'];
		$form_state['conf']['show_most_viewed_articles'] = $form_state['values']['show_most_viewed_articles'];
		for ($i = 0; $i < NUM_ITEM_PIWIK_GROUP; $i++) {
			$form_state['conf']['group'][$i]['choose'] = $form_state['values']['choose-' . $i];
			$form_state['conf']['group'][$i]['weight'] = intval($form_state['values']['weight-' . $i]);
			$form_state['conf']['group'][$i]['nid'] = $form_state['values']['nid-' . $i];
			if($form_state['values']['nid-' . $i] != '')
				$list[] = $form_state['values']['nid-' . $i];
		}
		$form_state['conf']['node_id'] = $list;
}

function rp_piwik_report_most_viewed_articles_content_type_edit_form_validate(&$form, &$form_state) {
  for ($i = 0; $i < NUM_ITEM_PIWIK_GROUP; $i++) {
    $node = rp_piwik_report_most_viewed_articles_list_autocomplete($form_state['values']['nid-' . $i]);
    if ($node) {
      $form_state['values']['nid-' . $i] = $node->nid;
    }
    if ($form_state['values']['nid-' . $i] == '')
      $form_state['values']['nid-' . $i] = ''; 
    if (( !node_access('view', $node)) && $form_state['values']['nid-' . $i] != '') {
      form_error($form['group'][$i]['nid-' . $i], t('Invalid node'));
    }
  }
}

function rp_piwik_report_most_viewed_articles_list_autocomplete($nid) {
  $preg_matches = array();
  $match = preg_match('/\[id: (\d+)\]/', $nid, $preg_matches);
  if (!$match) {
    $match = preg_match('/^id: (\d+)/', $nid, $preg_matches);
  }

  if ($match) {
    $nid = $preg_matches[1];
  }
  if (is_numeric($nid)) {
    $node = db_query('SELECT nid, status, type FROM {node} WHERE nid = :nid', array(':nid' => $nid))->fetchObject();
  }
  else {
    $node = db_query('SELECT nid, status, type FROM {node} WHERE LOWER(title) = LOWER(:title)', array(':title' => $nid))->fetchObject();
  }
  return $node;
}

function rp_piwik_report_most_viewed_articles_list_choose($conf, $i) {
  $choose = isset($conf['group']) ? $conf['group'][$i]['choose'] : null;
  if (isset($choose))
    return $choose;
  if ($i == 0)
    return 1;
  else {
    return 0;
  }
}
