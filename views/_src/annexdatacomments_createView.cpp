#include <QtCore>
#include <TreeFrogView>
#include "annexdatacomments.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT annexdatacomments_createView : public TActionView
{
  Q_OBJECT
public:
  annexdatacomments_createView() : TActionView() { }
  QString toString();
};

QString annexdatacomments_createView::toString()
{
  responsebody.reserve(5573);
  responsebody += QStringLiteral("<!DOCTYPE html>\n");
    tfetch(QVariantMap, annexDataComments);
  responsebody += QStringLiteral("<html>\n<head>\n  <meta charset=\"UTF-8\">\n  <html lang=\"de\">\n\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QStringLiteral("</title>\n\n  <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, user-scalable=yes\">\n  <link rel=\"icon\" href=\"/favicon.ico\">\n\n  <script>\n    function doLocal()\n    {\n        console.log(\"this is local\");\n\n        let l_footer = document.getElementById(\"itisFooter\");\n        l_footer.message = '<a href=\"/stdsystem/license\" title=\"licenses\">Lizenzen</a>&nbsp;<a href=\"/stdsystem/imprint\" title=\"Imprint\">Impressum</a>';\n\n        //let l_menu = document.getElementById(\"itisMenu\"); \n        //l_menu.message = \"");
  responsebody += THttpUtility::htmlEscape(controller()->name());
  responsebody += QStringLiteral("\";\n		setNewsDate();\n	}\n\n	function setNewsDate()\n	{\n		var d = new Date();\n		var mm = d.getMonth() + 1;\n		var dd = d.getDate();\n		var yy = d.getFullYear();\n		var hh = d.getHours();\n		var m = d.getMinutes();\n\n		if(mm < 10)\n		{\n			mm = \"0\" + mm;\n		}\n		if(dd < 10)\n		{\n			dd = \"0\" + dd;\n		}\n		if(hh < 10)\n		{\n			hh = \"0\" + hh;\n		}\n		if(m < 10)\n		{\n			m = \"0\" + m;\n		}\n		let datestr = yy + \"-\" + mm + \"-\" + dd + \" \" + hh + \":\" + m;\n		\n		document.getElementById(\"createDate\").value = datestr;\n	}\n\n	function setLanguage(lang)\n	{\n		if(lang == \"0\")\n		{lang = \"de\";}\n		else{lang = \"en\";}\n		document.cookie = \"lang=\" + lang + \";\" + \";path=/\";\n		location.reload();\n	}\n	\n  </script>\n\n  <script type=\"module\" src=\"/js/itis_init.js\" /></script>\n  \n  <link rel=\"stylesheet\" href=\"/css/w3.css\">  \n  <link rel=\"stylesheet\" href=\"/css/custom.css\">  \n\n</head>\n\n<body class=\"w3-container w3-margin\" id=\"body\">\n\n  <itis-menu id=\"itisMenu\" message=\"\"></itis-menu>\n\n  <div class=\"w3-container w3-light-blue\">\n    <h2 id=\"portaltitle\">ITIS-API::Admin-Portal</h2>\n  </div>\n\n  <itis-menusub id=\"itisMenuSub\" message=\"");
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
  responsebody += QStringLiteral("</p>\n\n<main>\n    \n<div id=\"pagecontent\"><page-content message=\"\"></page-content></div>\n\n<section>\n");
  responsebody += QVariant(formTag(urla("create"), Tf::Post)).toString();
  responsebody += QStringLiteral("\n<div class=\"w3-row-padding\">\n	<div class=\"w3-half\">\n		<label class=\"w3-opacity\">Comment Created<br /><input class=\"w3-input w3-border w3-round\" name=\"annexDataComments[commentCreated]\" value=\"\" id=\"createDate\" readonly /></label>\n	</div>\n	<div class=\"w3-half\">\n		<label class=\"w3-opacity\">Spec ID<br /><input class=\"w3-input w3-border w3-round\" name=\"annexDataComments[specId]\" value=\"");
  responsebody += THttpUtility::htmlEscape(annexDataComments["specId"]);
  responsebody += QStringLiteral("\" /></label>\n	</div>\n	<div class=\"w3-half\" style=\"padding-top: 1rem;\">\n		<label class=\"w3-opacity\">Spec Title<br /><input class=\"w3-input w3-border w3-round\" name=\"annexDataComments[specTitle]\" value=\"");
  responsebody += THttpUtility::htmlEscape(annexDataComments["specTitle"]);
  responsebody += QStringLiteral("\" /></label>\n	</div>\n	<div class=\"w3-half\" style=\"padding-top: 1rem;\">\n		<label class=\"w3-opacity\">Spec Version<br /><input class=\"w3-input w3-border w3-round\" name=\"annexDataComments[specVersion]\" value=\"");
  responsebody += THttpUtility::htmlEscape(annexDataComments["specVersion"]);
  responsebody += QStringLiteral("\" /></label>\n  </div>\n  <div class=\"w3-half\" style=\"padding-top: 1rem;\">\n		<label class=\"w3-opacity\">User Comment<br /><input class=\"w3-input w3-border w3-round\" name=\"annexDataComments[userComment]\" value=\"");
  responsebody += THttpUtility::htmlEscape(annexDataComments["userComment"]);
  responsebody += QStringLiteral("\" /></label>\n  </div>\n  <div class=\"w3-half\" style=\"padding-top: 1rem; padding-bottom: 1rem;\">\n		<label class=\"w3-opacity\">Username<br /><input class=\"w3-input w3-border w3-round\" name=\"annexDataComments[username]\" value=\"");
  techoex(usermail);
  responsebody += QStringLiteral("\" readonly /></label>\n </div>\n  <p>\n    <input type=\"submit\" value=\"Create &raquo;\" />\n  </p>\n</form>\n</section>\n\n<br/>\n<a href=\"/annexDataComments/show/");
  responsebody += THttpUtility::htmlEscape(annexDataComments["id"]);
  responsebody += QStringLiteral("\" class=\"w3-btn w3-light-grey\"><img src=\"/Icons/eyeglasses.svg\">&nbsp;Anzeige</a>\n<a href=\"/annexDataComments/list_all\" class=\"w3-btn w3-light-grey\">&laquo;&nbsp;zur&uuml;ck</a>\n\n</main>\n\n<itis-footer id=\"itisFooter\" message=\"\"></itis-footer>\n</body>\n</html>\n");

  return responsebody;
}

T_DEFINE_VIEW(annexdatacomments_createView)

#include "annexdatacomments_createView.moc"
