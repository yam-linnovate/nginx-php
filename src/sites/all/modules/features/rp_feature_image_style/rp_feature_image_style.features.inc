<?php
/**
 * @file
 * rp_feature_image_style.features.inc
 */

/**
 * Implements hook_image_default_styles().
 */
function rp_feature_image_style_image_default_styles() {
  $styles = array();

  // Exported image style: 1300x735.
  $styles['1300x735'] = array(
    'label' => '1300X735',
    'effects' => array(
      24 => array(
        'name' => 'imagefield_focus_scale_and_crop',
        'data' => array(
          'width' => 1300,
          'height' => 735,
          'strength' => 'high',
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: 160x90.
  $styles['160x90'] = array(
    'label' => '160X90',
    'effects' => array(
      16 => array(
        'name' => 'imagefield_focus_scale_and_crop',
        'data' => array(
          'width' => 160,
          'height' => 90,
          'strength' => 'high',
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: 215x120.
  $styles['215x120'] = array(
    'label' => '215X120',
    'effects' => array(
      17 => array(
        'name' => 'imagefield_focus_scale_and_crop',
        'data' => array(
          'width' => 215,
          'height' => 120,
          'strength' => 'high',
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: 245x140.
  $styles['245x140'] = array(
    'label' => '245X140',
    'effects' => array(
      41 => array(
        'name' => 'imagefield_focus_scale_and_crop',
        'data' => array(
          'width' => 245,
          'height' => 140,
          'strength' => 'high',
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: 265x100.
  $styles['265x100'] = array(
    'label' => '265x100',
    'effects' => array(
      37 => array(
        'name' => 'imagefield_focus_scale_and_crop',
        'data' => array(
          'width' => 265,
          'height' => 100,
          'strength' => 'high',
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: 265x345.
  $styles['265x345'] = array(
    'label' => '265X345',
    'effects' => array(
      18 => array(
        'name' => 'imagefield_focus_scale_and_crop',
        'data' => array(
          'width' => 265,
          'height' => 345,
          'strength' => 'high',
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: 275x155.
  $styles['275x155'] = array(
    'label' => '275X155',
    'effects' => array(
      26 => array(
        'name' => 'imagefield_focus_scale_and_crop',
        'data' => array(
          'width' => 275,
          'height' => 155,
          'strength' => 'high',
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: 300x170.
  $styles['300x170'] = array(
    'label' => '300X170',
    'effects' => array(
      27 => array(
        'name' => 'imagefield_focus_scale_and_crop',
        'data' => array(
          'width' => 300,
          'height' => 170,
          'strength' => 'high',
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: 345x195.
  $styles['345x195'] = array(
    'label' => '345X195',
    'effects' => array(
      30 => array(
        'name' => 'imagefield_focus_scale_and_crop',
        'data' => array(
          'width' => 345,
          'height' => 195,
          'strength' => 'high',
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: 410x230.
  $styles['410x230'] = array(
    'label' => '410X230',
    'effects' => array(
      31 => array(
        'name' => 'imagefield_focus_scale_and_crop',
        'data' => array(
          'width' => 410,
          'height' => 230,
          'strength' => 'high',
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: 460x260.
  $styles['460x260'] = array(
    'label' => '460X260',
    'effects' => array(
      40 => array(
        'name' => 'imagefield_focus_scale_and_crop',
        'data' => array(
          'width' => 460,
          'height' => 260,
          'strength' => 'high',
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: 490x275.
  $styles['490x275'] = array(
    'label' => '490x275',
    'effects' => array(
      32 => array(
        'name' => 'imagefield_focus_scale_and_crop',
        'data' => array(
          'width' => 490,
          'height' => 275,
          'strength' => 'high',
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: 700x400.
  $styles['700x400'] = array(
    'label' => '700X400',
    'effects' => array(
      36 => array(
        'name' => 'imagefield_focus_scale_and_crop',
        'data' => array(
          'width' => 700,
          'height' => 400,
          'strength' => 'high',
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: 740x415.
  $styles['740x415'] = array(
    'label' => '740X415',
    'effects' => array(
      33 => array(
        'name' => 'imagefield_focus_scale_and_crop',
        'data' => array(
          'width' => 740,
          'height' => 415,
          'strength' => 'high',
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: 890x550.
  $styles['890x550'] = array(
    'label' => '890X550',
    'effects' => array(
      39 => array(
        'name' => 'imagefield_focus_scale_and_crop',
        'data' => array(
          'width' => 890,
          'height' => 550,
          'strength' => 'high',
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: 900x480.
  $styles['900x480'] = array(
    'label' => '900X480',
    'effects' => array(
      34 => array(
        'name' => 'imagefield_focus_scale_and_crop',
        'data' => array(
          'width' => 900,
          'height' => 480,
          'strength' => 'high',
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: special_projects_slider.
  $styles['special_projects_slider'] = array(
    'label' => 'special projects slider',
    'effects' => array(
      16 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 230,
          'height' => 260,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: writer_120x120.
  $styles['writer_120x120'] = array(
    'label' => 'writer_120X120',
    'effects' => array(
      35 => array(
        'name' => 'imagefield_focus_scale_and_crop',
        'data' => array(
          'width' => 120,
          'height' => 120,
          'strength' => 'high',
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: writer_250x250.
  $styles['writer_250x250'] = array(
    'label' => 'writer_250X250',
    'effects' => array(
      16 => array(
        'name' => 'imagefield_focus_scale_and_crop',
        'data' => array(
          'width' => 250,
          'height' => 250,
          'strength' => 'high',
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}
