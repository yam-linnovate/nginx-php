<?php global $base_url; ?>
<div class="panel-display panel-head clear-block" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>
    <div class="wrap-header" id="header">
        <div class="inner-header">
            <div class="sticky">
                <div class="wrap-logo">
                  <?php if ($content['logo']): ?>
                    <?php print $content['logo']; ?>
                  <?php endif; ?>
                </div>
            </div>
            <input id="hamburger" type="checkbox" name="hamburger">
            <label for="hamburger" class="main-hamburger">
                <span class="hamburger"></span>
            </label>
            <div class="wrap-mobile-menu">
                <div id="header-mobile-row">
                    <div id="header-mobile-row-inner">
                      <?php if ($content['mobile_menu']): ?>
                          <nav id="mobile-menu" role="navigation">
                              <div id="mobile-menu-inner">
                                <?php print $content['mobile_menu'] ?>
                              </div>
                          </nav> <!-- /#mobile-menu -->
                      <?php endif; ?>
                    </div>
                </div>
            </div>
            <div class="menus-wrapper">
              <div class="wrap-main-menu">
                  <?php if ($content['favorite']): ?>
                      <div id="favorite"><?php print $content['favorite']; ?></div>
                  <?php endif; ?>
                  <?php if ($content['main_menu']): ?>
                      <nav id="main-menu" role="navigation">
                          <div id="main-menu-inner">
                            <?php print $content['main_menu']; ?>
                          </div>
                          <div style="display: none" class="wrap-mega-menu">
                              <ul class="mega-menu">
                                  <li>
                                    <?php print t('more') ; ?>
                                      <div class="wrap-icon-menu">
                                          <div class="icon-menu"></div>
                                          <div class="icon-menu"></div>
                                          <div class="icon-menu"></div>
                                      </div>
                                      <div class="main-mega-menu">
                                        <div class="mega-menu-container">
                                          <?php print $content['mega_menu']; ?>
                                          <div class="sub-mega-menu">
                                            <?php print $content['sub_mega_menu']; ?>
                                          </div>
                                        </div>
                                      </div>
                                  </li>
                              </ul>
                          </div>
                      </nav><!-- /#main-menu -->
                  <?php endif; ?>

            </div>
            <div class="wrap-second-menu">
                <div id="header-second-row">
                    <div id="header-second-row-inner">
                        <?php if ($content['sub_menu']): ?>
                            <nav id="secondary-menu" role="navigation">
                                <div id="sub-menu-inner">
                                    <?php print $content['sub_menu'] ?>
                                    <?php print $content['buttons'] ?>
                                </div>
                            </nav> <!-- /#secondary-menu -->
                        <?php endif; ?>
                    </div>
                </div>
              </div>
            </div>
        </div>
    </div>
</div>
