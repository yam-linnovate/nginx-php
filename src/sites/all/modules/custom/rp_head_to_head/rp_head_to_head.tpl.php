
<div id="<?php print $head_to_head_nid; ?>" class="rp-head-to-head-main-wrapper">
	<a href="/<?php print $head_to_head_path; ?>">
	<div class="top-section">
		<img src="/<?php print drupal_get_path('theme', variable_get('theme_default', NULL));?>/images/head_to_head.jpg">
	</div>
	
		<div class="main-section">
			<div class="positive-section">
				<div class="box-wrapper">
					<div class="pic-perc-wrapper">
						<img src="<?php print $positive_opinion_writer_img; ?>">
						<div class="ticker">
							<script type="positive">
			             	
				               <div class="number"> 
				               {{results}}
				               </div>
				               
			        		</script> 
		        		</div>
	        		</div>
					<div class="text-wrapper">
						<div class="writer-name"><?php print $positive_opinion_writer_name; ?></div>
						<div class="opinion-title"><?php print $positive_opinion_title; ?></div>
						<div class="click-wrapper">
							<input type="button" value="הכנסו והצביעו >> ">
						</div>
					</div>
				</div>
			</div>

			
			<div class="subject-section">
				<div class="box-wrapper">
					<img class="subject-img" src="<?php print $head_to_head_img; ?>">
					<div class="subject-title-wrapper">
						<div class="subject-title"><?php print $head_to_head_title; ?></div>
					</div>
				</div>					
			</div>


			<div class="negative-section">
				<div class="box-wrapper">
					<div class="pic-perc-wrapper">				
						<img  src="<?php print $negative_opinion_writer_img; ?>">
						<div class="ticker">
							<script type="negative">
			             	
				               <div class="number"> 
				               {{results}}
				               </div>	             
			        		</script>
		        		</div> 	
	    			</div> 					
					<div class="text-wrapper">
						<div class="writer-name"><?php print $negative_opinion_writer_name; ?></div>
						<div class="opinion-title"><?php print $negative_opinion_title; ?></div>
						<div class="click-wrapper">
							<input type="button" value="הכנסו והצביעו >> ">
						</div>
					</div>					
				</div>
			</div>		
		</div>
	</a>
</div>

