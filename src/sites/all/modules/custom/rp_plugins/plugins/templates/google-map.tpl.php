<iframe
        width="100%"
        <?php if (isset($data['#content']['height'])):?>
            height=<?php print $data['#content']['height']?>"
        <?php else :?>
            height="450"
        <?php endif; ?>
        frameborder="0" style="border:0"
        src="https://www.google.com/maps/embed/v1/place?key=<?php print $data['#content']['api_key']?>
        <?php if ($data['#content']['place']):?>
            &q=<?php print $data['#content']['place']?>
        <?php endif; ?>
        <?php if ($data['#content']['zoom']):?>
            &zoom=<?php print $data['#content']['zoom']?>"
        <?php endif; ?>
        allowfullscreen>
</iframe>