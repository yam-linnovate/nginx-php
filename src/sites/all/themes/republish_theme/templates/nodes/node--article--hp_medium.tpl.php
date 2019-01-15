<div class="medium-article" >
      <div class="medium-article-top">
            <a href="<?php print $link_to_node;?>"><?php print render($content['field_images']);?></a>
            <div class="<?php print $node->type;?> icon"><span class="icon"></span></div>
            <div class="section"><?php print render($content['field_section']);?></div>
      </div>
    <div class="medium-article-bottom">
        <a href="<?php print $link_to_node;?>"><?php print render($content['field_front_page_title']);?></a>
        <div class="writer"><?php print render($content['field_writer']);?></div>
        <div class="delimiter">|</div>
        <div class="created"><?php print date('d.m.y' ,$node->created);?></div>
    </div>
</div>


