<div class="large-article" >
    <a href="<?php print $link_to_node;?>"><?php print render($content['field_images']);?></a>
    <div class="<?php print $node->type;?> icon"><span class="icon"></span></div>
    <div class="section"><?php print render($content['field_section']);?></div>
  	<a href="<?php print $link_to_node;?>"><?php print render($content['field_front_page_title']);?></a>
  	<a href="<?php print $link_to_node;?>"><?php print render($content['field_front_page_intro']);?></a>
  	<div class="created"><?php print date('d.m.y' ,$node->created);?></div>     
</div>