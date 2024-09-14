#include <QtCore>
#include <TreeFrogView>
#include "appvars.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT appvars_createView : public TActionView
{
  Q_OBJECT
public:
  appvars_createView() : TActionView() { }
  QString toString();
};

QString appvars_createView::toString()
{
  responsebody.reserve(3937);
  responsebody += QStringLiteral("<!DOCTYPE html>\n");
    tfetch(QVariantMap, appVars);
  tfetch(QVariantMap, objects);
  responsebody += QStringLiteral("<html>\n<head>\n  <meta charset=\"UTF-8\">\n  <html lang=\"de\">\n\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QStringLiteral("</title>\n\n  <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, user-scalable=yes\">\n  <link rel=\"icon\" href=\"/favicon.ico\">\n\n  <script>\n    function doLocal()\n    {\n        console.log(\"this is local\");\n\n        let l_footer = document.getElementById(\"itisFooter\");\n        l_footer.message = '<a href=\"/stdsystem/license\" title=\"licenses\">Lizenzen</a>&nbsp;<a href=\"/stdsystem/imprint\" title=\"Imprint\">Impressum</a>';\n\n        //let l_menu = document.getElementById(\"itisMenu\"); \n        //l_menu.message = \"");
  responsebody += THttpUtility::htmlEscape(controller()->name());
  responsebody += QStringLiteral("\";\n    }\n\n	function setLanguage(lang)\n	{\n		if(lang == \"0\")\n		{lang = \"de\";}\n		else{lang = \"en\";}\n		document.cookie = \"lang=\" + lang + \";\" + \";path=/\";\n		location.reload();\n	}\n	\n  </script>\n\n  <script type=\"module\" src=\"/js/itis_init.js\" /></script>\n  \n  <link rel=\"stylesheet\" href=\"/css/w3.css\">  \n  <link rel=\"stylesheet\" href=\"/css/custom.css\">  \n\n</head>\n\n<body class=\"w3-container w3-margin\" id=\"body\">\n\n  <itis-menu id=\"itisMenu\" message=\"\"></itis-menu>\n\n  <div class=\"w3-container w3-light-blue\">\n    <h2 id=\"portaltitle\">ITIS-API::Admin-Portal</h2>\n  </div>\n\n  <itis-menusub id=\"itisMenuSub\" message=\"");
  responsebody += THttpUtility::htmlEscape(controller()->name());
  responsebody += QStringLiteral("\"></itis-menusub>\n\n<h3 id=\"pagetitle\"><page-title message=\"\">");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QStringLiteral("</page-title></h3>\n<div id=\"pagedesc\"><page-desc message=\"\"></page-desc></div>\n\n<p id=\"redmsg\" style=\"color: red\">");
  techoex(red_msg);
  tehex(error);
  responsebody += QStringLiteral("</p><p id=\"greenmsg\" style=\"color: green\">");
  techoex(green_msg);
  tehex(notice);
  responsebody += QStringLiteral("</p>\n\n<main>\n    \n<div id=\"pagecontent\"><page-content message=\"\"></page-content></div>	\n\n");
  responsebody += QVariant(formTag(urla("create"), Tf::Post)).toString();
  responsebody += QStringLiteral("\n  <p>\n    <label>Std Type<br /><input class=\"w3-input\" name=\"appVars[stdType]\" value=\"");
  responsebody += THttpUtility::htmlEscape(appVars["stdType"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Std Attr<br /><input class=\"w3-input\" name=\"appVars[stdAttr]\" value=\"");
  responsebody += THttpUtility::htmlEscape(appVars["stdAttr"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Std Val De<br /><input class=\"w3-input\" name=\"appVars[stdValDe]\" value=\"");
  responsebody += THttpUtility::htmlEscape(appVars["stdValDe"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Std Val En<br /><input class=\"w3-input\" name=\"appVars[stdValEn]\" value=\"");
  responsebody += THttpUtility::htmlEscape(appVars["stdValEn"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Active<br /><input class=\"w3-input\" name=\"appVars[active]\" value=\"");
  responsebody += THttpUtility::htmlEscape(appVars["active"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <input type=\"submit\" value=\"Create &raquo;\" />\n  </p>\n</form>\n\n<br/>\n\n<a href=\"/appVars/list_all\" class=\"w3-btn w3-light-grey\">&laquo;&nbsp;zur&uuml;ck</a>\n\n</main>\n\n<itis-footer id=\"itisFooter\" message=\"\"></itis-footer>\n</body>\n</html>\n\n");

  return responsebody;
}

T_DEFINE_VIEW(appvars_createView)

#include "appvars_createView.moc"
