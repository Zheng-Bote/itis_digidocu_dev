#include <QtCore>
#include <TreeFrogView>
#include "standardsdatacomments.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT standardsdatacomments_saveView : public TActionView
{
  Q_OBJECT
public:
  standardsdatacomments_saveView() : TActionView() { }
  QString toString();
};

QString standardsdatacomments_saveView::toString()
{
  responsebody.reserve(5493);
  responsebody += QStringLiteral("<!DOCTYPE html>\n");
    tfetch(QVariantMap, standardsDataComments);
  responsebody += QStringLiteral("<html>\n<head>\n  <meta charset=\"UTF-8\">\n  <html lang=\"de\">\n\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QStringLiteral("</title>\n\n  <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, user-scalable=yes\">\n  <link rel=\"icon\" href=\"/favicon.ico\">\n\n  <script>\n    function doLocal()\n    {\n        console.log(\"this is local\");\n\n        let l_footer = document.getElementById(\"itisFooter\");\n        l_footer.message = '<a href=\"/stdsystem/license\" title=\"licenses\">Lizenzen</a>&nbsp;<a href=\"/stdsystem/imprint\" title=\"Imprint\">Impressum</a>';\n\n        //let l_menu = document.getElementById(\"itisMenu\"); \n        //l_menu.message = \"");
  responsebody += THttpUtility::htmlEscape(controller()->name());
  responsebody += QStringLiteral("\";\n    }\n\n	function setLanguage(lang)\n	{\n		if(lang == \"0\")\n		{lang = \"de\";}\n		else{lang = \"en\";}\n		document.cookie = \"lang=\" + lang + \";\" + \";path=/\";\n		location.reload();\n	}\n	\n  </script>\n\n  <script type=\"module\" src=\"/js/itis_init.js\" /></script>\n  \n  <link rel=\"stylesheet\" href=\"/css/w3.css\">  \n  <link rel=\"stylesheet\" href=\"/css/custom.css\">  \n\n</head>\n\n<body class=\"w3-container w3-margin\" id=\"body\">\n\n  <itis-menu id=\"itisMenu\" message=\"\"></itis-menu>\n\n  <div class=\"w3-container w3-light-blue\">\n    <h2 id=\"portaltitle\">ITIS-API::Admin-Portal</h2>\n  </div>\n\n  <itis-menusub id=\"itisMenuSub\" message=\"");
  responsebody += THttpUtility::htmlEscape(controller()->name());
  responsebody += QStringLiteral("\"></itis-menusub>\n\n<h3 id=\"pagetitle\"><page-title message=\"\">");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QStringLiteral("</page-title></h3>\n<div id=\"pagedesc\"><page-desc message=\"\"></page-desc></div>\n\n<p style=\"color: red\"><span id=\"redmsg\">");
  techoex(red_msg);
  responsebody += QStringLiteral("</span> ");
  tehex(error);
  responsebody += QStringLiteral("</p><p style=\"color: green\"><span id=\"greenmsg\">");
  techoex(green_msg);
  responsebody += QStringLiteral("</span> ");
  tehex(notice);
  responsebody += QStringLiteral("</p>\n\n<main>\n    \n<div id=\"pagecontent\"><page-content message=\"\"></page-content></div>	\n\n\n<a href=\"/standardsDataComments/show/");
  responsebody += THttpUtility::htmlEscape(standardsDataComments["id"]);
  responsebody += QStringLiteral("\" class=\"w3-btn w3-light-grey\"><img src=\"/Icons/eyeglasses.svg\">&nbsp;Anzeige</a>\n<a href=\"/standardsDataComments/list_all\" class=\"w3-btn w3-light-grey\">&laquo;&nbsp;zur&uuml;ck</a>\n\n");
  responsebody += QVariant(formTag(urla("save", standardsDataComments["id"]), Tf::Post)).toString();
  responsebody += QStringLiteral("\n<div class=\"w3-container\" style=\"max-width: 50%;\">\n  <p>\n    <label>ID<br /><input type=\"text\" class=\"w3-input\" name=\"standardsDataComments[id]\" value=\"");
  responsebody += THttpUtility::htmlEscape(standardsDataComments["id"]);
  responsebody += QStringLiteral("\" readonly=\"readonly\" /></label>\n  </p>\n  <p>\n    <label>Comment Created<br /><input type=\"text\" class=\"w3-input\" name=\"standardsDataComments[commentCreated]\" value=\"");
  responsebody += THttpUtility::htmlEscape(standardsDataComments["commentCreated"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Spec ID<br /><input type=\"text\" class=\"w3-input\" name=\"standardsDataComments[specId]\" value=\"");
  responsebody += THttpUtility::htmlEscape(standardsDataComments["specId"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Spec Title<br /><input type=\"text\" class=\"w3-input\" name=\"standardsDataComments[specTitle]\" value=\"");
  responsebody += THttpUtility::htmlEscape(standardsDataComments["specTitle"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Spec Version<br /><input type=\"text\" class=\"w3-input\" name=\"standardsDataComments[specVersion]\" value=\"");
  responsebody += THttpUtility::htmlEscape(standardsDataComments["specVersion"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>User Comment<br /><input type=\"text\" class=\"w3-input\" name=\"standardsDataComments[userComment]\" value=\"");
  responsebody += THttpUtility::htmlEscape(standardsDataComments["userComment"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Username<br /><input type=\"text\" class=\"w3-input\" name=\"standardsDataComments[username]\" value=\"");
  responsebody += THttpUtility::htmlEscape(standardsDataComments["username"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <input type=\"submit\" value=\"speichern &raquo;\" />\n  </p>\n</div>\n</form>\n\n<br>\n\n<a href=\"/standardsDataComments/show/");
  responsebody += THttpUtility::htmlEscape(standardsDataComments["id"]);
  responsebody += QStringLiteral("\" class=\"w3-btn w3-light-grey\"><img src=\"/Icons/eyeglasses.svg\">&nbsp;Anzeige</a>\n<a href=\"/standardsDataComments/list_all\" class=\"w3-btn w3-light-grey\">&laquo;&nbsp;zur&uuml;ck</a>\n\n</main>\n\n<itis-footer id=\"itisFooter\" message=\"\"></itis-footer>\n</body>\n</html>\n\n");

  return responsebody;
}

T_DEFINE_VIEW(standardsdatacomments_saveView)

#include "standardsdatacomments_saveView.moc"
