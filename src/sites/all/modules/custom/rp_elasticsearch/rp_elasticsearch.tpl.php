<script type="template">
  {{#data}}
  <div class="views-row views-row">
    <div class="node"> 
      
      <div class="field-content field-image field-collection-item-field-images">
    <a href="{{url}}">
                {{#image}}<img src="{{image}}" alt="{{field_images:field_image:alt}}">{{/image}}
                {{^image}}<img src="<?php print base_path() . drupal_get_path('theme', $GLOBALS['theme']) . '/images/placeholder_125x125.png' ?>">{{/image}}
                <div class="{{type}} icon"><span class="icon"></span></div>
    </a>
                </div>
                <div class="content-text">
        <div class="field title"><a href="{{url}}">{{field_front_page_title}}</a></div>          
        <div class="field intro"><a href="{{url}}">{{field_front_page_intro}}</a></div>          
        <div class="details">
              <span class="unit><a href="{{url}}"><span class="ttl"> Unit: </span> {{field_unit:name}} </span></a><span class="separator">|</span>
              <span class="cassification"><span class="ttl">Classification: </span> {{field_cassification:name}} </span><span class="separator">|</span>
              <span class="created">{{created}}</span> 
        </div>
      </div>
    </div>
  </div>
  {{/data}} 
</script>


<div class="loader"></div>
<div class="rendered" style="display:none;">
<div class="search-wrapper">
    <div class="search-list">
        <div class="wrapper-domain-list wrapper-article">
	   <div class="domain-list article-list"></div> 
           <div class="search-pager" domain="article"></div>  
         </div>
        <div class="wrapper-domain-list wrapper-opinion" style="display:none;">
	   <div class="domain-list opinion-list"></div> 
           <div class="search-pager" domain="opinion"></div>  
         </div>
      </div>  
  </div> 
</div> 

<div class="show-more-results-btn">
<!-- <form action="/action_page.php"> -->
  <input type="number" name="offset" id="offset" value="1"/>
  <button type="button" id="show_more_results" >Show More</button>
</div>
<!-- </form> -->

    


