#include <QtCore>
#include <TreeFrogView>
#include "standardsdata.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT standardsdata_saveView : public TActionView
{
  Q_OBJECT
public:
  standardsdata_saveView() : TActionView() { }
  QString toString();
};

QString standardsdata_saveView::toString()
{
  responsebody.reserve(8679);
  responsebody += QStringLiteral("<!DOCTYPE html>\n");
    tfetch(QVariantMap, standardsData);
  responsebody += QStringLiteral("<html>\n<head>\n  <meta charset=\"UTF-8\">\n  <html lang=\"de\">\n\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QStringLiteral("</title>\n\n  <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, user-scalable=yes\">\n  \n  <link rel=\"icon\" type=\"image/svg+xml\" href=\"/favicon.svg\">\n  <link rel=\"alternate icon\" href=\"/favicon.ico\">\n  <link rel=\"mask-icon\" href=\"/favicon.svg\" color=\"#b2b2b2\">\n\n  <script>\n    function doLocal()\n    {\n        console.log(\"this is local\");\n\n        let l_footer = document.getElementById(\"itisFooter\");\n        l_footer.message = '<a href=\"/stdsystem/license\" title=\"licenses\">Lizenzen</a>&nbsp;<a href=\"/stdsystem/imprint\" title=\"Imprint\">Impressum</a>';\n\n        //let l_menu = document.getElementById(\"itisMenu\"); \n        //l_menu.message = \"");
  responsebody += THttpUtility::htmlEscape(controller()->name());
  responsebody += QStringLiteral("\";\n    }\n\n	function setLanguage(lang)\n	{\n		if(lang == \"0\")\n		{lang = \"de\";}\n		else{lang = \"en\";}\n		document.cookie = \"lang=\" + lang + \";\" + \";path=/\";\n		location.reload();\n	}\n  </script>\n\n  <script type=\"module\" src=\"/js/itis_init.js\" /></script>\n  <link rel=\"stylesheet\" href=\"/css/w3.css\">  \n  <link rel=\"stylesheet\" href=\"/css/custom.css\">  \n\n</head>\n\n<body class=\"w3-container w3-margin\" id=\"body\">\n\n  <itis-menu id=\"itisMenu\" message=\"\"></itis-menu>\n\n  <div class=\"w3-container w3-light-blue\">\n    <h2 id=\"portaltitle\">ITIS-API::Admin-Portal</h2>\n  </div>\n\n  <itis-menusub id=\"itisMenuSub\" message=\"");
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
  responsebody += QVariant(linkTo("Remove", urla("remove", standardsData["id"]), Tf::Post, "confirm('Are you sure?')")).toString();
  responsebody += QStringLiteral("</span>\n&nbsp;&nbsp;&nbsp;\n<a href=\"/standardsdata/editor_upd/");
  responsebody += THttpUtility::htmlEscape(standardsData["id"]);
  responsebody += QStringLiteral("\" class=\"w3-btn w3-light-grey\"><img src=\"/Icons/textarea-t.svg\">&nbsp;Editor</a>\n<a href=\"/standardsdata/list_all\" class=\"w3-btn w3-light-grey\"><img src=\"/Icons/justify.svg\">&nbsp;zur&uuml;ck</a>\n<br/><br>\n\n");
  responsebody += QVariant(formTag(urla("save", standardsData["id"]), Tf::Post, 'class="w3-container"')).toString();
  responsebody += QStringLiteral("\n<h4>Attribute</h4>\n  <p>\n    <label>ID<br /><input class=\"w3-input\" type=\"text\" name=\"standardsData[id]\" value=\"");
  responsebody += THttpUtility::htmlEscape(standardsData["id"]);
  responsebody += QStringLiteral("\" readonly=\"readonly\" /></label>\n  </p>\n  <p>\n    <label>Lfdnr<br /><input class=\"w3-input\" type=\"text\" name=\"standardsData[lfdnr]\" value=\"");
  responsebody += THttpUtility::htmlEscape(standardsData["lfdnr"]);
  responsebody += QStringLiteral("\" readonly /></label>\n  </p>\n  <p>\n    <label>Spec Title<br /><input class=\"w3-input\" type=\"text\" name=\"standardsData[specTitle]\" value=\"");
  responsebody += THttpUtility::htmlEscape(standardsData["specTitle"]);
  responsebody += QStringLiteral("\" readonly /></label>\n  </p>\n<!--  \n  <p>\n    <label>Spec Desc<br /><input class=\"w3-input\" type=\"text\" name=\"standardsData[specDesc]\" value=\"");
  responsebody += THttpUtility::htmlEscape(standardsData["specDesc"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Spec Version<br /><input class=\"w3-input\" type=\"text\" name=\"standardsData[specVersion]\" value=\"");
  responsebody += THttpUtility::htmlEscape(standardsData["specVersion"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Spec Release<br /><input class=\"w3-input\" type=\"text\" name=\"standardsData[specRelease]\" value=\"");
  responsebody += THttpUtility::htmlEscape(standardsData["specRelease"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Obj Sname<br /><input class=\"w3-input\" type=\"text\" name=\"standardsData[objSname]\" value=\"");
  responsebody += THttpUtility::htmlEscape(standardsData["objSname"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Ac Classes<br /><input class=\"w3-input\" type=\"text\" name=\"standardsData[acClasses]\" value=\"");
  responsebody += THttpUtility::htmlEscape(standardsData["acClasses"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Pc Classes<br /><input class=\"w3-input\" type=\"text\" name=\"standardsData[pcClasses]\" value=\"");
  responsebody += THttpUtility::htmlEscape(standardsData["pcClasses"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Cat Class<br /><input class=\"w3-input\" type=\"text\" name=\"standardsData[catClass]\" value=\"");
  responsebody += THttpUtility::htmlEscape(standardsData["catClass"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Country<br /><input class=\"w3-input\" type=\"text\" name=\"standardsData[country]\" value=\"");
  responsebody += THttpUtility::htmlEscape(standardsData["country"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Lang<br /><input class=\"w3-input\" type=\"text\" name=\"standardsData[lang]\" value=\"");
  responsebody += THttpUtility::htmlEscape(standardsData["lang"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Spec Active<br /><input class=\"w3-input\" type=\"text\" name=\"standardsData[specActive]\" value=\"");
  responsebody += THttpUtility::htmlEscape(standardsData["specActive"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n-->\n  <br/>\n  <h4>Daten Quellcode</h4>\n  <p>\n    <label>Spec Content Source Code</label><br /><article><textarea name=\"standardsData[specContent]\" style=\"width:100%; height:350px;\">");
  responsebody += THttpUtility::htmlEscape(standardsData["specContent"]);
  responsebody += QStringLiteral("</textarea></article>\n  </p>\n  <p>\n    <input type=\"submit\" value=\"speichern &raquo;\"/>\n  </p>\n</form>\n\n<br>\n<span class=\"w3-btn w3-red\"><img src=\"/Icons/trash.svg\">&nbsp;");
  responsebody += QVariant(linkTo("Remove", urla("remove", standardsData["id"]), Tf::Post, "confirm('Are you sure?')")).toString();
  responsebody += QStringLiteral("</span>\n&nbsp;&nbsp;&nbsp;\n<a href=\"/standardsdata/editor_upd/");
  responsebody += THttpUtility::htmlEscape(standardsData["id"]);
  responsebody += QStringLiteral("\" class=\"w3-btn w3-light-grey\"><img src=\"/Icons/textarea-t.svg\">&nbsp;Editor</a>\n<a href=\"/standardsdata/list_all\" class=\"w3-btn w3-light-grey\"><img src=\"/Icons/justify.svg\">&nbsp;zur&uuml;ck</a>\n\n<br/><br/>\n<h4>Daten Anzeige</h4>\n<p><label>Spec Content View</label><br><article><section>");
  responsebody += QVariant(standardsData["specContent"]).toString();
  responsebody += QStringLiteral("</section></article></p>\n\n<br>\n<span class=\"w3-btn w3-red\" style=\"border-radius: 0px 0px 0px 0.5em\"><img src=\"/Icons/trash.svg\">&nbsp;");
  responsebody += QVariant(linkTo("Remove", urla("remove", standardsData["id"]), Tf::Post, "confirm('Are you sure?')")).toString();
  responsebody += QStringLiteral("</span>\n&nbsp;&nbsp;&nbsp;\n<a href=\"/standardsdata/editor_upd/");
  responsebody += THttpUtility::htmlEscape(standardsData["id"]);
  responsebody += QStringLiteral("\" class=\"w3-btn w3-light-grey\"><img src=\"/Icons/textarea-t.svg\">&nbsp;Editor</a>\n<a href=\"/standardsdata/list_all\" class=\"w3-btn w3-light-grey\"><img src=\"/Icons/justify.svg\">&nbsp;zur&uuml;ck</a>\n\n\n</main>\n<itis-footer id=\"itisFooter\" message=\"\"></itis-footer>\n  \n</body>\n</html>\n");

  return responsebody;
}

T_DEFINE_VIEW(standardsdata_saveView)

#include "standardsdata_saveView.moc"
