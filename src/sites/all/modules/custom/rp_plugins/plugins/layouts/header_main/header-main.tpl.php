<div class="panel-display panel-header-main clear-block" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>
    <div class="content-indent">
        <div >
            <div class="panel-panel unit header">
                <div class="inside">
                  <?php print $content['header']; ?>
                </div>
            </div>
        </div>
        <div id="main">
            <div class="panel-panel unit main">
                <div class="inside">
                  <?php print $content['main']; ?>
                </div>
            </div>
        </div>
    </div>
</div>
