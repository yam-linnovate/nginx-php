<div class="panel-display panel-twocol-25-75 clear-block" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>
  <div class="content-indent">
      <div >
          <div class="panel-panel unit header">
              <div class="inside" id="main">
                  <?php print $content['header']; ?>
              </div>
          </div>
      </div>
      <div id="main">
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
      </div>
      <div class="panel-panel unit banner-main">
          <div class="inside">
              <?php print $content['banner_main']; ?>
          </div>
      </div>
      <div id="main">
          <div class="panel-panel unit sub-right">
              <div class="inside">
                  <?php print $content['sub_right']; ?>
              </div>
          </div>
          <div class="panel-panel unit sub-left">
              <div class="inside">
                  <?php print $content['sub_left']; ?>
              </div>
          </div>
      </div>
  </div>
</div>
