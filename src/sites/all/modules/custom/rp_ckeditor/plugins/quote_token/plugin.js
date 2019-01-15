CKEDITOR.plugins.add('quote_token', {
  init: function(editor) {
    editor.addCommand('quote_token_command', {
      exec: function(editor) {
        editor.insertHtml('[quote]');
      }
    });
    editor.ui.addButton('quote_token', {
      label: 'Insert Quote Token here',
      command: 'quote_token_command',
      icon: this.path + 'images/icon.jpg'
    });
  }
});
