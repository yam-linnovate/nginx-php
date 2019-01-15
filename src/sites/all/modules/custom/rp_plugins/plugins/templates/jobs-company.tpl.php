<div class="jobs-container">
    <?php global $base_url ?>
    <div class="companies-header">
        <h2>
            <?php if (isset($data['#content']['title']) ): ?>
                <?php print $data['#content']['title'] ; ?>
            <?php endif; ?>
        </h2>
        <?php if (isset($data['#view_all']) ): ?>
            <?php print $data['#view_all'] ; ?>
        <?php endif; ?>
    </div>
    <div class="views-companys <?php if(isset($data['#mobile'])){ print $data['#mobile']; } ?>">
        <?php foreach ($data['#content']['term'] as $item => $value) :?>
        <div class="view-company row-<?php print $item ?>" >
            <div class="img-company">
                <?php if (isset($value->field_company_img[LANGUAGE_NONE])): ?>
                    <?php $img = theme('image_style', array('style_name' => '245x140', 'path' => $value->field_company_img[LANGUAGE_NONE][0]['uri']));?>
                    <a href="<?php print 'taxonomy/term/' . $value->tid ?>">
                        <?php print $img ?>
                    </a>
                <?php endif; ?>
            </div>
            <div class="company-left">
                <div class="company-name">
                    <?php if (isset($value->name)):?>
                        <h3>
                            <?php print $value->name; ?>
                        </h3>
                    <?php endif; ?>
                </div>
                <div class="center-company">
                    <div class="company-kind-of-bussiness">
                        <?php if (isset($value->field_kind_of_bussiness[LANGUAGE_NONE])):?>
                            <?php
                            $field_kind_of_bussiness = field_info_field('field_kind_of_bussiness');
                            $field_kind_of_bussiness_values= list_allowed_values($field_kind_of_bussiness);
                            $field_kind_of_bussiness_select = $value->field_kind_of_bussiness[LANGUAGE_NONE][0]['value'];
                            $field_kind_of_bussiness_value = $field_kind_of_bussiness_values[$field_kind_of_bussiness_select];
                            ?>
                            <?php print $field_kind_of_bussiness_value; ?>
                        <?php endif; ?>
                    </div>
                    <div class="company-employee">
                        <?php if (isset($value->field_num_of_employees[LANGUAGE_NONE])):?>
                            <?php print $value->field_num_of_employees[LANGUAGE_NONE][0]['safe_value']; ?>
                        <?php endif; ?>
                    </div>
                </div>
                <div class="company-location">
                    <?php if (isset($value->field_location[LANGUAGE_NONE])):?>
                        <?php print $value->field_location[LANGUAGE_NONE][0]['safe_value']; ?>
                    <?php endif; ?>
                </div>
            </div>

        </div>
        <?php endforeach; ?>
    </div>

</div>