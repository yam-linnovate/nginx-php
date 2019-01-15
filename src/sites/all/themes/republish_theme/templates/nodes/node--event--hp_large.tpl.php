<?php
$label = isset($content['field_event_label']['#items'][0]['value']) ? $content['field_event_label']['#items'][0]['value'] : '';
$link = $content['field_event_link'][0]['#element']['url'];
?>
<div class="large-event" >
  <div class="top">
    <div class="event-img-wrapper">
      <a href="<?php print $link; ?>">
        <?php print render($content['field_event_image']);?>
        <?php if($label):?>
          <span class="label <?php print $label;?>"></span>
        <?php endif;?>
      </a>
      <?php if($is_mobile || $is_tablet): ?>
        <?php print render($content['field_event_link']);?>
      <?php endif; ?>
    </div>
    <div class="title"><a href="<?php print $link; ?>"><?php print $title;?></a></div>
    <div class="lecturer <?php print $lecturer_num;?>">
      <div class="lecturer-img"><?php print $lecturer_img;?></div>
      <div class="lecturer-name"><?php print $lecturer_name;?></div>
      <div class="lecturer-desc"> <?php print $lecturer_desc;?></div>
    </div>
    <div class="date">
      <span class="date-icon"></span>
      <?php print render($content['field_event_date_text']);?>
      <?php print render($content['field_event_date']);?>
    </div>
    <?php if(!$is_mobile && !$is_tablet): ?>
      <?php print render($content['field_event_link']);?>
    <?php endif; ?>
  </div>
  <div class="bottom">
    <hr>
    <span class="location-icon"></span>
    <?php print render($content['field_event_location']);?>
    <span class="date-icon"></span>
    <?php print render($content['field_event_date_text']);?>
    <?php print render($content['field_event_date']);?>
  </div>
</div>


