<div class="image-pane" id="image-pane">
    <?php
    $file = file_load($data['#content']['image']);
    $uri = $file->uri;
    $url = file_create_url($uri);
    if ($data['#content']['img_style'] == '0'): ?>
        <?php print theme('image', array( 'path' => $uri, 'alt' => $data['#content']['alt'])); ?>
    <?php else:?>
        <?php print theme('image_style', array('style_name' => $data['#content']['img_style'], 'path' => $uri, 'alt' => $data['#content']['alt'])); ?>
    <?php endif; ?>
    
</div>