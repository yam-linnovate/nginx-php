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
        <div class="delimiter">|</div>
        <div class="writer"><?php print render($content['field_writer']);?></div>
        <div class="intro">
        	<a href="<?php print $link_to_node;?>" class="main-intro"><?php print render($content['field_main_intro']);?></a>
        	<a href="<?php print $link_to_node;?>" class="fp-intro"><?php print render($content['field_front_page_intro']);?></a>
        </div>
        <hr>
    </div>  
</div>      


