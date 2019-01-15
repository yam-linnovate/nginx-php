<div class="contact-us">
    <?php if(isset($data['#content']['title']['value'])):?>
        <h2> <?php print($data['#content']['title']['value']) ?></h2>
    <?php endif; ?>
    <div class="main-content">
        <div class="call wrap-icon">
            <div class="icon call"></div>
            <div class="field call">
                <?php if(isset($data['#content']['call']['value'])):?>
                    <p> <?php print_r($data['#content']['call']['value']) ?></p>
                <?php endif; ?>
            </div>
        </div>
        <div class="fax wrap-icon">
            <div class="icon fax"></div>
            <div class="field fax">
                <?php if(isset($data['#content']['fax']['value'])):?>
                    <p> <?php print $data['#content']['fax']['value'] ?></p>
                <?php endif; ?>
            </div>
        </div>
        <div class="email wrap-icon">
            <div class="icon email"></div>
            <div class="field email">
                <?php if(isset($data['#content']['email']['value'])):?>
                    <p> <?php print $data['#content']['email']['value'] ?></p>
                <?php endif; ?>
            </div>
        </div>
        <div class="address wrap-icon">
            <div class="icon address"></div>
            <div class="field address">
                <?php if(isset($data['#content']['address']['value'])):?>
                    <p> <?php print $data['#content']['address']['value'] ?></p>
                <?php endif; ?>
            </div>
        </div>

    </div>
</div>