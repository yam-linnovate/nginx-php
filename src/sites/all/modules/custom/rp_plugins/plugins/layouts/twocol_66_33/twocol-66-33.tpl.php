<div class="panel-display panel-twocol-66-33 clear-block" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>
  <div class="content-indent" id="main">
    <div class="panel-panel unit header">
      <div class="inside">
        <?php print $content['header']; ?>
      </div>
    </div>
    <div class="panel-panel unit content">
      <div class="panel-panel unit main-right">
        <div class="inside">
          <div class="background"></div>
          <?php print $content['main_right']; ?>
        </div>
      </div>
      <div class="panel-panel unit main-left">
        <div class="inside">
          <?php print $content['main_left']; ?>
        </div>
      </div>
    <div>
  </div>
</div>
