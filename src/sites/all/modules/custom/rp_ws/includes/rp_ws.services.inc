<?php


function rp_ws_services_resource(){
	$api = array(
		'page_content' => array(
		  	'operations' => array(
		    	'retrieve' => array(
		      		'help' => 'Retrieves page content.',
		      		'file' => array(
		        		'type' => 'inc',
		        		'module' => 'rp_ws',
		        		'name' => 'includes/rp_ws.services',
		      		),
		      		'callback' => 'page_content_retrieve',
		      		'access callback' => 'user_access',
		      		'access arguments' => array('access content'),
		      		'access arguments append' => FALSE,
		      		'args' => array(
		        		array(
		          			'name' => 'page',
		          			'type' => 'string',
		          			'description' => 'Function to perform',
		          			'source' => array(
		            			'path' => '0'
		          			),
		          			'optional' => TRUE,
		          			'default' => '0',
		        		),
		      		),
		    	),
	      	),
		),
		'full_node' => array(
		  	'operations' => array(
		    	'retrieve' => array(
		      		'help' => 'Retrieves full node content.',
		      		'file' => array(
		        		'type' => 'inc',
		        		'module' => 'rp_ws',
		        		'name' => 'includes/rp_ws.services',
		      		),
		      		'callback' => 'full_node_retrieve',
		      		'access callback' => 'user_access',
		      		'access arguments' => array('access content'),
		      		'access arguments append' => FALSE,
		      		'args' => array(
		        		array(
		          			'name' => 'node',
		          			'type' => 'string',
		          			'description' => 'Function to perform',
		          			'source' => array(
		            			'path' => '0'
		          			),
		          			'optional' => TRUE,
		          			'default' => '0',
		        		),
		      		),
		    	),
	      	),
		),
		'menu' => array(
		  	'operations' => array(
		    	'retrieve' => array(
		      		'help' => 'Retrieves mobile menu.',
		      		'file' => array(
		        		'type' => 'inc',
		        		'module' => 'rp_ws',
		        		'name' => 'includes/rp_ws.services',
		      		),
		      		'callback' => 'menu_retrieve',
		      		'access callback' => 'user_access',
		      		'access arguments' => array('access content'),
		      		'access arguments append' => FALSE,
		      		'args' => array(
		        		array(
		          			'name' => 'menu',
		          			'type' => 'string',
		          			'description' => 'Function to perform',
		          			'source' => array(
		            			'path' => '0'
		          			),
		          			'optional' => TRUE,
		        		),
		      		),
		    	),
	      	),
		),
		'route' => array(
		  	'operations' => array(
		    	'retrieve' => array(
		      		'help' => 'Get route by path.',
		      		'file' => array(
		        		'type' => 'inc',
		        		'module' => 'rp_ws',
		        		'name' => 'includes/rp_ws.services',
		      		),
		      		'callback' => 'route_retrieve',
		      		'access callback' => 'user_access',
		      		'access arguments' => array('access content'),
		      		'access arguments append' => FALSE,
		      		'args' => array(
		        		array(
		          			'name' => 'path',
		          			'type' => 'string',
		          			'description' => 'Function to perform',
		          			'source' => array(
		            			'path' => '0'
		          			),
		          			'optional' => TRUE,
		        		),
		      		),
		    	),
	      	),
		),
  	);

	return $api;
}

function page_content_retrieve($page) {
    module_load_include('inc', 'ctools', 'includes/content');
    $result = db_select('page_manager_handlers', 'h')
  		->fields('d', array('did'))
		->condition('path',  $page, '=');
 	$result->join('page_manager_pages', 'p', 'h.subtask = p.name');     
 	$result->join('panels_display', 'd', 'h.name = d.storage_id'); 
 	$result->fields('p', array('name'));
  	$result = $result->execute()->fetchAll();
	if(!isset($result[0]->did))
		return 'no page found';
	$data = array();
	$id = $result[0]->did;
	ctools_include('plugins', 'panels');
	$display = panels_load_display($id);
    $panels = $display->panels;

    $data = $display->panels;


    foreach ($data as $key => $region){
        foreach ( $region as $item => $pid){
            $data[$key][$item] = $display->content[$pid];
            $pane = $display->content[$pid];
            $pane->configuration['api'] = true;
            $content = ctools_content_render($pane->type, $pane->subtype, $pane->configuration, array(), $display->args, $display->context);
            foreach ($content as $index => $nid){
                if ($index == 'node_id'){
                    $pane->configuration['node_id'] = $content->node_id;
                }
                if ($index == 'term_id'){
                    $pane->configuration['term_id'] = $content->term_id;
                }
            }
        }
    }
    $nids = array();
    $tids = array();
    foreach ($display->content as $item => &$pane){
        $pane->configuration['api'] = true;
        $content = ctools_content_render($pane->type, $pane->subtype, $pane->configuration, array(), $display->args, $display->context);
        foreach ($content as $index => $nid){
            if ($index == 'node_id'){
                $pane->configuration['node_id'] = $content->node_id;
                $nid_new = $content->node_id;
                array_push($nids, $nid_new);
            }
            if ($index == 'term_id'){
                $pane->configuration['term_id'] = $content->term_id;
                $tid_new = $content->term_id;
                array_push($tids, $tid_new);
            }
        }
    }
    $uniq_ids = sort_node($nids);
    $arr_entity = open_node($uniq_ids);
    $data = json_decode(json_encode($data), true);
    foreach ($data as $key => $region){
        foreach ( $region as $item => $pane){
            if (isset($data[$key][$item]['configuration']['node_id']) && is_array($data[$key][$item]['configuration']['node_id'])){
                foreach ($data[$key][$item]['configuration']['node_id'] as $i => $node_id){
                    $data[$key][$item]['configuration']['node_id'][$i] = $arr_entity[$node_id] ;
                }
            }
        }
    }


/*
    $nodes = sort_node($display->content);
    //$obj_nodes = open_node($nodes);
    foreach ( $panels as $key => $panel_region){
        foreach ($panel_region as $index => $pane_state){
            $data[$key][$pane_state] = $display->content[$pane_state];
        }
        if($display->content[$pane_state]->type == 'most_viewed_articles'){
            $data_conf = most_viewed_articles_build_html($params = array('time' => time()), $api = true);
            $data[$key][$pane_state]['configuration'] = $data_conf;
        }
        if($display->content[$pane_state]->type == 'most_viewed_opinions'){
            $data_conf = most_viewed_opinions_build_html($params = array('time' => time()), $api = true);
            $data[$key][$pane_state]['configuration'] = $data_conf;
        }
        if($display->content[$pane_state]->type == 'most_viewed_videos'){
            $data_conf = most_viewed_videos_build_html($params = array('time' => time()), $api = true);
            $data[$key][$pane_state]['configuration'] = $data_conf;
        }

    }

*/
    return $data;
}

function sort_node($arr){
    $uniq_id = array();
    foreach ($arr as $index => $value) {
        foreach ($value as $item => $id){
            if (!in_array($id, $uniq_id)) {
                $uniq_id[$id] = $id;
            }
        }
    }
    return $uniq_id;
}
function open_node($nodes){
    global $base_url;
    foreach ($nodes as $item => $node_id){
        if (is_numeric($node_id)){
            $node = node_load($node_id);
            if(isset($node->nid)){
                $obj = _fields_data($node, 'node');
                $nodes[$item] = $obj;
                $nid = $node->nid;
                $path = 'node/' . (int) $nid;
                $alias = drupal_get_path_alias($path);
                $nodes[$item]->path = $base_url . '/' . $path;
                $nodes[$item]->url = $base_url . '/' . $alias;
            }
            $nodes[$item] = json_decode(json_encode($nodes[$item]), true);
        }
    }
    $nodes = json_decode(json_encode($nodes), true);
    return $nodes;
}

function full_node_retrieve($node) {
	$node = node_load($node);
	if(isset($node->nid)){
		$data = _fields_data($node, 'node');
	}
	return $data;
}

function route_retrieve($path) {
	$path = str_replace('^' , '/', $path);
	$route = route_by_path($path);
	return array('route' => $route);
}

function menu_retrieve($menu_name) {
	$data = array();
	$menu = menu_load_links($menu_name);
	foreach ($menu as $key => $item) {
		if($item['link_path'] == '<front>')
	   		$item['link_path'] = variable_get('site_frontpage', '');
	   	$row = array(
			'link' => $item['link_path'],
			'title' => $item['link_title'],
			'route' => ''
		);
		$row['route'] = route_by_path($item['link_path']);
		$data[] = $row;
	}
	return $data;
}

function route_by_path($path){
	$route = '';
	$source = drupal_lookup_path('source', $path);
	$path = $source ? $source : $path;
	$menu_item = menu_get_item($path);		
	if(isset($menu_item['page_callback'])){
		switch($menu_item['page_callback']){
			case 'taxonomy_term_page':
			case 'page_manager_term_view_page':
				$term = menu_get_object('taxonomy_term', 2, $path);
				$route = isset($term->tid) ? '/api/taxonomy_term/' . $term->tid : '';
				break;
				break;
			case 'node_page_default':
			case 'page_manager_node_view_page':
				$node = menu_get_object('node', 1, $path);
				$route = isset($node->nid) ? '/api/node/' . $node->nid : '';
				break;
			case 'page_manager_page_execute':
				$route = '/api/page_content/' . $path;
				break;
		}
	}
	return $route;
}
