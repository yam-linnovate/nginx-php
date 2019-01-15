<?php
/**
 * @file
 * rp_feature_search.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function rp_feature_search_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "elasticsearch_connector" && $api == "elasticsearch_connector_defaults") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_default_search_api_index().
 */
function rp_feature_search_default_search_api_index() {
  $items = array();
  $items['elasticsearch_index'] = entity_import('search_api_index', '{
    "name" : "elasticsearch index",
    "machine_name" : "elasticsearch_index",
    "description" : null,
    "server" : "elasticsearch_server",
    "item_type" : "node",
    "options" : {
      "datasource" : { "bundles" : [ "opinion", "video", "article" ] },
      "index_directly" : 1,
      "cron_limit" : "50",
      "index_name" : { "index" : "republish", "cluster_id" : "elasticsearch_server" },
      "collect_index_statistics" : 0,
      "log_only_not_found" : 0,
      "index_statistics_num_of_shards" : "1",
      "index_statistics_num_of_replicas" : "0",
      "fields" : {
        "body:value" : { "type" : "text" },
        "created" : { "type" : "date" },
        "field_front_page_intro" : { "type" : "text" },
        "field_front_page_title" : { "type" : "text" },
        "field_images:field_image:alt" : { "type" : "text" },
        "field_images:field_image:file:fid" : { "type" : "integer" },
        "field_main_intro" : { "type" : "text" },
        "field_pre_title" : { "type" : "text" },
        "field_section:name" : { "type" : "text" },
        "field_section:tid" : { "type" : "integer" },
        "field_tags:name" : { "type" : "list\\u003Ctext\\u003E" },
        "field_tags:tid" : { "type" : "list\\u003Cinteger\\u003E" },
        "field_writer:name" : { "type" : "text" },
        "field_writer:tid" : { "type" : "integer" },
        "nid" : { "type" : "integer" },
        "search_api_language" : { "type" : "string" },
        "title" : { "type" : "text" },
        "type" : { "type" : "string" },
        "url" : { "type" : "uri" }
      },
      "data_alter_callbacks" : {
        "search_api_alter_bundle_filter" : {
          "status" : 1,
          "weight" : "-10",
          "settings" : {
            "default" : "0",
            "bundles" : { "opinion" : "opinion", "video" : "video", "article" : "article" }
          }
        },
        "search_api_metatag_alter_callback" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_aggregation" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_viewed_entity" : { "status" : 0, "weight" : "0", "settings" : { "mode" : "full" } },
        "search_api_alter_add_hierarchy" : { "status" : 0, "weight" : "0", "settings" : { "fields" : [] } },
        "search_api_alter_language_control" : {
          "status" : 0,
          "weight" : "0",
          "settings" : { "lang_field" : "", "languages" : [] }
        },
        "search_api_alter_node_access" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_node_status" : { "status" : 1, "weight" : "0", "settings" : [] }
      },
      "processors" : {
        "search_api_case_ignore" : {
          "status" : 0,
          "weight" : "0",
          "settings" : { "fields" : {
              "title" : true,
              "field_front_page_title" : true,
              "field_pre_title" : true,
              "field_intro" : true,
              "field_main_intro" : true,
              "field_front_page_intro" : true
            }
          }
        },
        "search_api_html_filter" : {
          "status" : 0,
          "weight" : "10",
          "settings" : {
            "fields" : {
              "title" : true,
              "field_front_page_title" : true,
              "field_pre_title" : true,
              "field_intro" : true,
              "field_main_intro" : true,
              "field_front_page_intro" : true
            },
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_tokenizer" : {
          "status" : 0,
          "weight" : "20",
          "settings" : {
            "fields" : {
              "title" : true,
              "field_front_page_title" : true,
              "field_pre_title" : true,
              "field_intro" : true,
              "field_main_intro" : true,
              "field_front_page_intro" : true
            },
            "spaces" : "[^[:alnum:]]",
            "ignorable" : "[\\u0027]"
          }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "30",
          "settings" : {
            "fields" : {
              "title" : true,
              "field_front_page_title" : true,
              "field_pre_title" : true,
              "field_intro" : true,
              "field_main_intro" : true,
              "field_front_page_intro" : true
            },
            "file" : "",
            "stopwords" : "but\\r\\ndid\\r\\nthe this that those\\r\\netc"
          }
        },
        "search_api_elasticsearch_highlighting" : {
          "status" : 0,
          "weight" : "35",
          "settings" : {
            "prefix" : "\\u003Cstrong\\u003E",
            "suffix" : "\\u003C\\/strong\\u003E",
            "excerpt" : 1,
            "excerpt_length" : "256",
            "excerpt_fragments" : "3",
            "concatenator" : "...",
            "highlight" : "always"
          }
        },
        "search_api_elasticsearch_prefix_search" : {
          "status" : 0,
          "weight" : "35",
          "settings" : { "fields" : {
              "title" : true,
              "field_front_page_title" : true,
              "field_pre_title" : true,
              "field_intro" : true,
              "field_main_intro" : true,
              "field_front_page_intro" : true
            }
          }
        },
        "search_api_porter_stemmer" : {
          "status" : 0,
          "weight" : "35",
          "settings" : {
            "fields" : {
              "title" : true,
              "field_front_page_title" : true,
              "field_pre_title" : true,
              "field_intro" : true,
              "field_main_intro" : true,
              "field_front_page_intro" : true,
              "body:value" : true,
              "field_writer:name" : true,
              "field_section:name" : true,
              "field_tags:name" : true,
              "field_images:field_image:alt" : true
            },
            "exceptions" : "texan=texa"
          }
        },
        "search_api_highlighting" : {
          "status" : 0,
          "weight" : "35",
          "settings" : {
            "prefix" : "\\u003Cstrong\\u003E",
            "suffix" : "\\u003C\\/strong\\u003E",
            "excerpt" : 1,
            "excerpt_length" : "256",
            "exclude_fields" : [],
            "highlight" : "always",
            "highlight_partial" : 0
          }
        }
      }
    },
    "enabled" : "1",
    "read_only" : "0",
    "rdf_mapping" : []
  }');
  return $items;
}

/**
 * Implements hook_default_search_api_server().
 */
function rp_feature_search_default_search_api_server() {
  $items = array();
  $items['elasticsearch_server'] = entity_import('search_api_server', '{
    "name" : "elasticsearch server",
    "machine_name" : "elasticsearch_server",
    "description" : "",
    "class" : "search_api_elasticsearch_connector",
    "options" : { "cluster" : "", "facet_limit" : 10 },
    "enabled" : "1",
    "rdf_mapping" : []
  }');
  return $items;
}
