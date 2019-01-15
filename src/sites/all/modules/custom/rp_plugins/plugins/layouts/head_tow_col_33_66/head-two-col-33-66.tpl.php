<div class="panel-display panel-head-two-col-33-66 clear-block" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>
    <div class="content-indent">
        <div >
            <div class="panel-panel unit header">
                <div class="inside" id="main-full-width">
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
        <div class="panel-panel unit footer">
            <div class="inside">
                <?php print $content['footer']; ?>
            </div>
        </div>
    </div>
</div>
