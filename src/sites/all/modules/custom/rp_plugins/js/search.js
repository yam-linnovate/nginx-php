// super duper speedy search filter!!
// working with jQuery quicksearch this script toggles to visual state
// of the buttons within 3 categories and a show all button
// then populates the quicksearch field with the appropriate tag to trigger the search
// Paul Evans, PEDesign, Oct 2009

(function ($) {
  $(document).ready(function () {
    // activate quicksearch
    $('.views-field-field-rank-academy').quicksearch({
      position: 'before',
      attached: '#srp',
      labelText: '',
      hideElement: 'parent',
      formId:'filterer',
      loaderImg:'/sites/all/themes/bakewellpools/images/ui/spinner.gif',
      labelText: 'DEV ONLY',
      /*onAfter: function() {checkResults($('#freetext').val())},*/
      randomElement: 'freetext'
    });
    // set the click function for the buttons
    $('.filter').click(function() {
        $(this).addClass('selected');
        $(this).siblings().removeClass('selected');
        var newFilters = '';
        var newFilters = $(this).attr('tag');
        if (newFilters == '') {
          $('#all-option').addClass('selected');
        }
        if (newFilters == 'all'){
          newFilters = '';
        }
        $('#freetext').val(newFilters);

        $('#freetext').keydown();

    });
  });




/*
function checkResults(term) {
  var results = 0;
  if ( term != "" ) {
    term = term.slice(0, -1);
    var aTerm = term.split(' ');
    $('#search-feedback').hide();
    var matches = 0;

    $('.searchtags').each( function() {
      var tags = $(this).html();
      var termFound = 0;
      for ( i=0; i < aTerm.length; i++ ) {
        if (tags.indexOf(aTerm[i]) > -1) {
          termFound = termFound+1;
        }
      }
      if (termFound == aTerm.length) {
        results = 1;
        matches = matches+1;
      }
    });
    if (results == 1) {
      $('#search-feedback').html('There are ' + matches + ' pools matching your search');
    } else {
      $('#search-feedback').html('Sorry, there are no pools matching this combination');
    }
  } else {
    $('#search-feedback').html('All pools are listed below');
  }
  $('#search-feedback').fadeIn();
}
*/

})(jQuery);