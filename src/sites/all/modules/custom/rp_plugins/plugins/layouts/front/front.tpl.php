<div class="panel-display panel-front clear-block" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>
  <div class="content-full-width">
    <div class="panel-panel unit banner">
      <div class="inside">
        <?php print $content['banner']; ?>
      </div>
    </div>
  </div>
  <div class="content-indent"  id="main">
    <div class="panel-panel unit header">
      <div class="inside">
        <?php print $content['header']; ?>
      </div>
    </div>
    <div class="top-content-front">
      <div class="panel-panel unit top-second">
        <div class="inside">
          <?php print $content['top_second']; ?>
        </div>
      </div>
      <div class="panel-panel unit top-third">
        <div class="inside">
          <?php print $content['top_third']; ?>
        </div>
      </div>
    </div>
    <div class="top-content-front">
      <div class="panel-panel unit top-right">
        <div class="inside">
          <?php print $content['top_right']; ?>
        </div>
      </div>
      <div class="panel-panel unit top-left">
        <div class="inside">
          <?php print $content['top_left']; ?>
        </div>
      </div>
    </div>
    <div class="panel-panel unit middle-left">
      <div class="inside">
        <?php print $content['middle_left']; ?>
      </div>
    </div>
    <div class="panel-panel unit middle-right">
      <div class="inside">
        <?php print $content['middle_right']; ?>
      </div>
    </div>
    <div class="panel-panel unit middle">
      <div class="inside">
        <?php print $content['middle']; ?>
      </div>
    </div>
    <div class="top-content-front">
      <div class="panel-panel unit middle-first">
        <div class="inside">
          <?php print $content['middle_first']; ?>
        </div>
      </div>
      <div class="panel-panel unit middle-second">
        <div class="inside">
          <?php print $content['middle_second']; ?>
        </div>
      </div>
    </div>
    <div class="panel-panel unit bottom">
      <div class="inside">
        <?php print $content['bottom']; ?>
      </div>
    </div>
  </div>
  <div class="content-full-width">
    <div class="panel-panel unit footer">
      <div class="inside">
        <?php print $content['footer']; ?>
      </div>
    </div>
  </div>
</div>
