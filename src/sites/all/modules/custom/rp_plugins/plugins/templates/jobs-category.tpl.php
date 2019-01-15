<div class="content-indent" id="main">
    <?php global $base_url ?>
    <h2>
        <?php if (isset($data['#content']['title']) ): ?>
            <?php if (isset($data['#content']['term']) && $data['#content']['term'] == 'jobs_category') :?>
                <?php print $data['#content']['title'] ." ". $data['#content']['result'][0]->field_field_category[0]['rendered']['#title']; ?>
            <?php else:?>
                <?php print $data['#content']['title'] ." ". $data['#content']['result'][0]->field_field_company[0]['rendered']['#title']; ?>
            <?php endif; ?>
        <?php endif; ?>
    </h2>
    <div class="all-jobs-on-category">
        <?php if ($data['#content']['is_page_term']): ?>
            <a href="<?php print $data['#content']['result'][0]->field_field_category[0]['rendered']['#href'] ?>">
                <?php print t(' all jobs in section')  ?>
            </a>
        <?php else: ?>
            <a href="<?php print $base_url . '/jobs' ?>">
                <?php print t('to jobs page')  ?>
            </a>
        <?php endif; ?>
    </div>
    <div class="views">
        <?php foreach ($data['#content']['result'] as $item => $value) :?>
        <div class="view-jobs" >
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
            </div>
            <?php endif; ?>
            <?php if (isset($value->field_field_jobs_size[0])): ?>
                <div class="job-size"><?php print $value->field_field_jobs_size[0]['rendered']['#markup'] ?></div>
            <?php endif; ?>
            <?php if (isset($value->field_field_experience[0])): ?>
                <div class="job-exprience"><?php print $value->field_field_experience[0]['raw']['value'] ?></div>
            <?php endif; ?>
        </div>
        <?php endforeach; ?>
    </div>

</div>