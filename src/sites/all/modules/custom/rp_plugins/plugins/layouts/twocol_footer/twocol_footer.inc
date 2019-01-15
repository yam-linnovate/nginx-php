<?php

$plugin = array(
  'title' => t('Two Columns 2/3 + 1/3 + footer'),
  'category' => t('Republish layouts'),
  'icon' => 'twocol_footer.png',
  'theme' => 'twocol-footer',
  'css' => 'twocol_footer.css',
  'regions' => array(
    'header' => t('Header'),
    'main_right' => t('Main-Right'),
    'main_left' => t('Main-Left'),
    'footer' => t('Footer'),
  ),
);