<div class="block-jobs-home">
    <?php if($data['#content']['title']): ?>
        <a href="<?php print $data['#content']['link'] ?>">
            <div class="pane-title">
                <?php print t($data['#content']['title']) ?>
                <span class="view-more" ><?php print t($data['#content']['link_title'])?> </span>
            </div>
        </a>
    <?php endif; ?>

    <?php $num = 0; ?>
    <?php foreach ($data['#content']['result'] as $item => $value) :?>
        <?php if($num < ($data['#count'] - 1)): ?>
            <div class="view-jobs-block" >
        <?php else: ?>
            <div class="view-jobs-block last" >
        <?php endif; ?>
            <?php if (isset($value->field_field_company[0])): ?>
                <div class="company"><?php print $value->field_field_company[0]['rendered']['#title'] ?></div>
            <?php endif; ?>
            <?php if (isset($value->node_title)): ?>
                <div class="job-title">
                    <?php if (isset($value->field_field_ref_to_article[0])):?>
                    <?php
                    $nid = $value->field_field_ref_to_article[0]['raw']['target_id'];
                    $url = url("node/$nid"); ?>
                    <a href="<?php print $url?>">
                        <?php endif; ?>
                        <h3><?php print $value->node_title ?></h3>
                    </a>
                    <div class="region">
                        <?php if(isset($data['#content']['result'][0]->field_field_region_in_israel[0]['rendered']['#title'])): ?>
                            <?php print $data['#content']['result'][0]->field_field_region_in_israel[0]['rendered']['#title']; ?>
                        <?php endif; ?>
                    </div>
                </div>
            <?php endif; ?>
            <?php if (isset($value->field_field_location[0])): ?>
                <div class="jobs-location">
                    <p>
                        <?php print $value->field_field_location[0]['raw']['safe_value'] ?>
                    </p>
                </div>
            <?php endif; ?>
        </div>
        <?php $num++; ?>
    <?php endforeach; ?>
    <?php if(isset($data['#content']['mobile_link_title'])): ?>
        <div class="jobs-view-more">
            <a href="<?php print $data['#content']['link'] ?>">
                <span class="view-more" ><?php print t($data['#content']['mobile_link_title'])?> </span>
            </a>
        </div>
    <?php endif; ?>

</div>