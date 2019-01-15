<?php 
 $unit='';
 $cassification='';
      if(isset($node->field_unit['und'][0]['tid'])){
        $term_unit = taxonomy_term_load($node->field_unit['und'][0]['tid']);
        $unit = $term_unit->name;
      } 

      if(isset($node->field_cassification['und'][0]['tid'])){
        $term_cassification = taxonomy_term_load($node->field_cassification['und'][0]['tid']);
        $cassification = $term_cassification->name;
      }
?>

<?php if(!$is_mobile && !$is_tablet): ?>
<div class="large-article" >
  <div class="large-article-top">
    <a href="<?php print $link_to_node;?>"><?php print render($content['field_images']);?></a>
    <?php if(isset($node->field_article_type['und']) && $node->field_article_type['und'][0]['value'] == 'video'){?>
      <div class="video icon"></div>
    <?php } ?>
  </div>
    <div class="large-article-bottom">
      <div class="intro">
        <h1>
        	<a href="<?php print $link_to_node;?>" class="main-intro"><?php print render($content['field_front_page_title']['#object']->field_front_page_title['und'][0]['value']);?></a>
        </h1>
      </div>
      <a href="<?php print $link_to_node;?>" class="fp-intro"><?php print render($content['field_front_page_intro']);?></a>
      <div class="details">
            <?php if($unit){ ?>
            <span class="unit">Unit: 
              <span><?php print $unit; ?></span>
            </span>
            <span class="separator">|</span>          
            <?php } ?>
            <?php if($cassification){ ?>
            <span class="cassification">Classification: 
              <span><?php print $cassification; ?></span>
            </span>
            <span class="separator">|</span>
            <?php } ?>
            <span class="created">
              <span><?php print date('d.m.y' ,$node->created); ?></span>
            <span>
      </div> 
  </div>  
</div>
<?php endif; ?>

<?php if($is_mobile || $is_tablet): ?>
  <div class="large-article" >
    <div class="large-article-top">
      <a href="<?php print $link_to_node;?>"><?php print render($content['field_images']);?></a>
      <div class="titles">
          <a href="<?php print $link_to_node;?>" class="pre-title"><?php print render($content['field_pre_title']);?></a>
          <a href="<?php print $link_to_node;?>" class="title"><?php print render($content['field_front_page_title']);?></a>
      </div>
    </div>
    <div class="large-article-bottom">
      <div class="section"><?php print render($content['field_section']);?></div>
      <div class="intro">
        <a href="<?php print $link_to_node;?>" class="main-intro"><?php print render($content['field_main_intro']);?></a>
        <a href="<?php print $link_to_node;?>" class="fp-intro"><?php print render($content['field_front_page_intro']);?></a>
        <div class="details">
            <?php if($unit){ ?>
            <span class="unit">Unit: <?php print $unit; ?></span><span class="separator">|</span>          
            <?php } ?>
            <?php if($cassification){ ?>
            <span class="cassification">Classification: <?php print $cassification; ?></span><span class="separator">|</span>
            <?php } ?>
            <span class="created"><?php print date('d.m.y' ,$node->created); ?></span>
          </div> 
      </div>
      <hr>
    </div>  
  </div>   
<?php endif; ?>
