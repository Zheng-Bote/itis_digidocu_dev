#include <QtCore>
#include <TreeFrogView>
#include "standardsdata.h" 
#include "standardsdatawaste.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT standardsdata_showWasteView : public TActionView
{
  Q_OBJECT
public:
  standardsdata_showWasteView() : TActionView() { }
  QString toString();
};

QString standardsdata_showWasteView::toString()
{
  responsebody.reserve(6712);
  responsebody += QStringLiteral("<!DOCTYPE html>\n");
      tfetch(StandardsDataWaste, standardsDataWaste);
  responsebody += QStringLiteral("<html>\n<head>\n  <meta charset=\"UTF-8\">\n  <html lang=\"de\">\n\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QStringLiteral("</title>\n\n  <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, user-scalable=yes\">\n  \n  <link rel=\"icon\" type=\"image/svg+xml\" href=\"/favicon.svg\">\n  <link rel=\"alternate icon\" href=\"/favicon.ico\">\n  <link rel=\"mask-icon\" href=\"/favicon.svg\" color=\"#b2b2b2\">\n\n  <script>\n    function doLocal()\n    {\n        console.log(\"this is local\");\n\n        let l_footer = document.getElementById(\"itisFooter\");\n        l_footer.message = '<a href=\"/stdsystem/license\" title=\"licenses\">Lizenzen</a>&nbsp;<a href=\"/stdsystem/imprint\" title=\"Imprint\">Impressum</a>';\n\n        //let l_menu = document.getElementById(\"itisMenu\"); \n        //l_menu.message = \"");
  responsebody += THttpUtility::htmlEscape(controller()->name());
  responsebody += QStringLiteral("\";\n    }\n\n	function setLanguage(lang)\n	{\n		if(lang == \"0\")\n		{lang = \"de\";}\n		else{lang = \"en\";}\n		document.cookie = \"lang=\" + lang + \";\" + \";path=/\";\n		location.reload();\n	}\n  </script>\n\n  <script type=\"module\" src=\"/js/itis_init.js\" /></script>\n  <link rel=\"stylesheet\" href=\"/css/w3.css\">  \n  <link rel=\"stylesheet\" href=\"/css/custom.css\">  \n \n</head>\n\n<body class=\"w3-container w3-margin\" id=\"body\">\n\n  <itis-menu id=\"itisMenu\" message=\"\"></itis-menu>\n\n  <div class=\"w3-container w3-light-blue\">\n    <h2 id=\"portaltitle\">ITIS-API::Admin-Portal</h2>\n  </div>\n\n  <itis-menusub id=\"itisMenuSub\" message=\"");
  responsebody += THttpUtility::htmlEscape(controller()->name());
  responsebody += QStringLiteral("\"></itis-menusub>\n\n<h3 id=\"pagetitle\"><page-title message=\"\">");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QStringLiteral("</page-title></h3>\n<div id=\"pagedesc\"><page-desc message=\"\"></page-desc></div>\n\n<p id=\"redmsg\" style=\"color: red\">");
  techoex(red_msg);
  tehex(error);
  responsebody += QStringLiteral("</p><p id=\"greenmsg\" style=\"color: green\">");
  techoex(green_msg);
  tehex(notice);
  responsebody += QStringLiteral("</p>\n\n<main>\n<div id=\"pagecontent\"><page-content message=\"\"></page-content></div>\n\n<span class=\"w3-btn w3-red w3-wide\" style=\"border-radius: 0.5em 0px 0px 0px;\"><img src=\"/Icons/trash.svg\">&nbsp;");
  responsebody += QVariant(linkTo("Remove", urla("removeWaste", standardsDataWaste.id()), Tf::Post, "confirm('Are you sure?')")).toString();
  responsebody += QStringLiteral("</span>\n&nbsp;&nbsp;&nbsp;\n<a href=\"/standardsdata/listWaste\" class=\"w3-btn w3-light-grey\"><img src=\"/Icons/justify.svg\">&nbsp;zur&uuml;ck</a>\n<br>\n\n<form class=\"w3-container\">\n<p><label>ID</label><input class=\"w3-input\" type=\"text\" value=\"");
  responsebody += THttpUtility::htmlEscape(standardsDataWaste.id());
  responsebody += QStringLiteral("\" readonly></p>\n<p><label>Lfdnr</label><input class=\"w3-input\" type=\"text\" value=\"");
  responsebody += THttpUtility::htmlEscape(standardsDataWaste.lfdnr());
  responsebody += QStringLiteral("\" readonly></p>\n<p><label>Spec Title</label><input class=\"w3-input\" type=\"text\" value=\"");
  responsebody += THttpUtility::htmlEscape(standardsDataWaste.specTitle());
  responsebody += QStringLiteral("\" readonly></p>\n\n<p><label>Spec Desc</label><input class=\"w3-input\" type=\"text\" value=\"");
  responsebody += THttpUtility::htmlEscape(standardsDataWaste.specDesc());
  responsebody += QStringLiteral("\" readonly></p>\n<p><label>Spec Version</label><input class=\"w3-input\" type=\"text\" value=\"");
  responsebody += THttpUtility::htmlEscape(standardsDataWaste.specVersion());
  responsebody += QStringLiteral("\" readonly></p>\n<p><label>Spec Release</label><input class=\"w3-input\" type=\"text\" value=\"");
  responsebody += THttpUtility::htmlEscape(standardsDataWaste.specRelease());
  responsebody += QStringLiteral("\" readonly></p>\n<p><label>Obj Sname</label><input class=\"w3-input\" type=\"text\" value=\"");
  responsebody += THttpUtility::htmlEscape(standardsDataWaste.objSname());
  responsebody += QStringLiteral("\" readonly></p>\n<p><label>Ac Classes</label><input class=\"w3-input\" type=\"text\" value=\"");
  responsebody += THttpUtility::htmlEscape(standardsDataWaste.acClasses());
  responsebody += QStringLiteral("\" readonly></p>\n<p><label>Pc Classes</label><input class=\"w3-input\" type=\"text\" value=\"");
  responsebody += THttpUtility::htmlEscape(standardsDataWaste.pcClasses());
  responsebody += QStringLiteral("\" readonly></p>\n<p><label>Cat Class</label><input class=\"w3-input\" type=\"text\" value=\"");
  responsebody += THttpUtility::htmlEscape(standardsDataWaste.catClass());
  responsebody += QStringLiteral("\" readonly></p>\n<p><label>Country</label><input class=\"w3-input\" type=\"text\" value=\"");
  responsebody += THttpUtility::htmlEscape(standardsDataWaste.country());
  responsebody += QStringLiteral("\" readonly></p>\n<p><label>Lang</label><input class=\"w3-input\" type=\"text\" value=\"");
  responsebody += THttpUtility::htmlEscape(standardsDataWaste.lang());
  responsebody += QStringLiteral("\" readonly></p>\n<p><label>Spec Active</label><input class=\"w3-input\" type=\"text\" value=\"");
  responsebody += THttpUtility::htmlEscape(standardsDataWaste.specActive());
  responsebody += QStringLiteral("\" readonly></p>\n\n<br/>\n\n<article>\n	<h4>Daten Anzeige</h4>\n	<p><label><b>Spec Content</b></label><br>\n	<section>");
  responsebody += QVariant(standardsDataWaste.specContent()).toString();
  responsebody += QStringLiteral("</section></p>\n	<p><label><b>Spec Source</b></label></p>\n	<section>");
  responsebody += THttpUtility::htmlEscape(standardsDataWaste.specContent());
  responsebody += QStringLiteral("</section>\n</article>\n</form>\n\n<br>\n<span class=\"w3-btn w3-red\" style=\"border-radius: 0px 0px 0px 0.5em\"><img src=\"/Icons/trash.svg\">&nbsp;");
  responsebody += QVariant(linkTo("Remove", urla("removeWaste", standardsDataWaste.id()), Tf::Post, "confirm('Are you sure?')")).toString();
  responsebody += QStringLiteral("</span>\n&nbsp;&nbsp;&nbsp;\n<a href=\"/standardsdata/list_all\" class=\"w3-btn w3-light-grey\"><img src=\"/Icons/justify.svg\">&nbsp;zur&uuml;ck</a>\n\n</main>\n<itis-footer id=\"itisFooter\" message=\"\"></itis-footer>\n  \n</body>\n</html>\n");

  return responsebody;
}

T_DEFINE_VIEW(standardsdata_showWasteView)

#include "standardsdata_showWasteView.moc"
