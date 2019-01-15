/* 
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

if (!Array.prototype.indexOf)
{
  Array.prototype.indexOf = function(elt /*, from*/)
  {
    var len = this.length >>> 0;

    var from = Number(arguments[1]) || 0;
    from = (from < 0)
         ? Math.ceil(from)
         : Math.floor(from);
    if (from < 0)
      from += len;

    for (; from < len; from++)
    {
      if (from in this &&
          this[from] === elt)
        return from;
    }
    return -1;
  };
}

//----------Ajax call for image : get the number of reads and add one-------
function setReadsforimage(newIndex, oldIndex, viewClass, isPopup)  {
if(isRender()){
    var cssClass = '.'+viewClass.toString();
    var list ;
    if(jQuery(cssClass).find('.auto-bxlider').length == 0 || isPopup == 'true' ) { 
    if(isPopup == 'true')
       list = jQuery('.bxslider-popup').find('.bxslider-popup-row');
    else     
       list = jQuery(cssClass).find('.bxslider .field-item');
    oldIndex = oldIndex+1;
    newIndex = newIndex+1; 
    var nidCurrent = jQuery(list[oldIndex]).find('.key').attr('nid');
    var fidCurrent = jQuery(list[oldIndex]).find('.key').attr('fid');     
    if(jQuery(cssClass).find('.bxslider-auto').length == 0 || isPopup == 'true') {
          jQuery.ajax({    
          url: '/rpcounter/Viewed',
          type: 'GET',
          dataType: 'jsonp',
          data:  {
            fid : fidCurrent,        
            nid : nidCurrent,
          },
          success: function(res) {
             
          },
          error: function(res) {
          }
        });
     } 
    }    
}
   }


function getReadsforallImages(viewClass,index,isPopup)  {
  if(isRender()){     

  var list, nid, fids = [];
  if (viewClass == 'page-weekly-images') {
      list = jQuery('.page-weekly-images').find('.views-row');
  }
  else {
      var cssClass = '.'+viewClass.toString();
      if(isPopup == 'true') 
          list = jQuery('.bxslider-popup').find('.bxslider-popup-row');
       else   
         list = jQuery(cssClass).find('.bxslider .field-item');
       }
   jQuery(list).each(function(index,img) {
          jQuery(img).find('.img-reads').addClass('inactive');
          var fid = jQuery(img).find('.key').attr('fid'); 
          if (fids.indexOf(fid) == -1) 
              fids.push(fid);
   });
    var data = {"fids":fids};
    jQuery.ajax({
     type: "POST",
     url: "/rpcounter/getViewed",
     data: data,
     success: function (data) {
        for(var reads in data.reads) {
            if (data.reads[reads] >= 10) {
            list = jQuery('.key[fid='+reads+']');
            list.each(function(index,img) {
                jQuery(img).parent().removeClass('inactive');  
                jQuery(img).text(data.reads[reads]);
        });
        }
     }
     },
     dataType: 'json'
   });
  }
 }

//--------------------------------------------------  

function isRender(){
  var not_panelModalContent = (jQuery('#modalContent').length == 0) ? true : false;
  var not_panels_edit = (jQuery('#panels-ipe-edit-control-form').length == 0) ? true : false;

  if(not_panelModalContent && not_panels_edit){
  	return true;
  	//return false;
  }else{
  	return false;
  }
}

//-----------------------------------------------------

jQuery(document).ready(function() {
  if (jQuery('.page-weekly-images').length != 0) {
      getReadsforallImages('page-weekly-images');
  }
});
