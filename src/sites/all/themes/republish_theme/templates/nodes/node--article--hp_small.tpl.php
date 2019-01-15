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

<?php if($variables['is_front']): ?>
  <div class="small-article" >
    <div class="small-article-right">
      <?php if($is_mobile || $is_tablet): ?>
        <div class="section"><?php print render($content['field_section']);?></div>
      <?php endif; ?>
      <a href="<?php print $link_to_node;?>" class="title"><?php print render($content['field_front_page_title']);?></a>        
      <a href="<?php print $link_to_node;?>" class="fp-intro"><div class="fp-intro-wrapper" ><?php print render($content['field_front_page_intro']);?></div></a>
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
        </span>
      </div>   
    </div>
    <div class="small-article-left">
      <a href="<?php print $link_to_node;?>"><?php print render($content['field_images']);?></a>
      <div class="<?php isset($node->field_article_type['und'])? print $node->field_article_type['und'][0]['value']:print '';?> icon"></div>     
      <?php if(!$is_mobile && !$is_tablet): ?>
      <?php endif; ?>
    </div>
    <hr>  
  </div>
<?php endif; ?>

<?php if(!$variables['is_front']): ?>
  <?php if($content['field_section']['#bundle'] == 'article'): ?>
    <div class="small-article" >
      <div class="small-article-right">
        <?php if($is_mobile || $is_tablet): ?>
          <div class="section"><?php print render($content['field_section']);?></div>
        <?php endif; ?>
        <a href="<?php print $link_to_node;?>" class="title"><?php print render($content['field_front_page_title']);?></a>        
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
      <div class="small-article-left">
        <a href="<?php print $link_to_node;?>"><?php print render($content['field_images']);?></a>
        <div class="<?php print $node->type;?> icon"><span class="icon"></span></div>     
        <?php if(!$is_mobile && !$is_tablet && $content['field_section']['#bundle'] !== 'video'): ?>
        <?php endif; ?>
      </div>
      <hr>  
    </div>
  <?php endif; ?> 

  <?php if($content['field_section']['#bundle'] == 'video'): ?>
    <div class="small-article" >
      <div class="small-article-right">
        <a href="<?php print $link_to_node;?>" class="title"><?php print render($content['field_front_page_title']);?></a>        
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
      <div class="small-article-left">
        <a href="<?php print $link_to_node;?>"><?php print render($content['field_images']);?></a>
        <div class="<?php print $node->type;?> icon"><span class="icon"></span></div>     
        <?php if(!$is_mobile && !$is_tablet && $content['field_section']['#bundle'] !== 'video'): ?>
        <?php endif; ?>
      </div>
      <hr>
    </div>
  <?php endif; ?>
<?php endif; ?>

