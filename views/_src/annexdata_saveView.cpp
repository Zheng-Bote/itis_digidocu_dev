#include <QtCore>
#include <TreeFrogView>
#include "annexdata.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT annexdata_saveView : public TActionView
{
  Q_OBJECT
public:
  annexdata_saveView() : TActionView() { }
  QString toString();
};

QString annexdata_saveView::toString()
{
  responsebody.reserve(8770);
  responsebody += QStringLiteral("<!DOCTYPE html>\n");
    tfetch(QVariantMap, annexData);
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
  responsebody += QVariant(linkTo("Remove", urla("remove", annexData["id"]), Tf::Post, "confirm('Are you sure?')")).toString();
  responsebody += QStringLiteral("</span>\n&nbsp;&nbsp;&nbsp;\n<a href=\"/AnnexData/editor_upd/");
  responsebody += THttpUtility::htmlEscape(annexData["id"]);
  responsebody += QStringLiteral("\" class=\"w3-btn w3-light-grey\"><img src=\"/Icons/textarea-t.svg\">&nbsp;Editor</a>\n<a href=\"/AnnexData/list_all\" class=\"w3-btn w3-light-grey\"><img src=\"/Icons/justify.svg\">&nbsp;zur&uuml;ck</a>\n<br/><br>\n\n");
  responsebody += QVariant(formTag(urla("save", annexData["id"]), Tf::Post)).toString();
  responsebody += QStringLiteral("\n  <p>\n    <label>ID<br /><input class=\"w3-input\" type=\"text\" name=\"annexData[id]\" value=\"");
  responsebody += THttpUtility::htmlEscape(annexData["id"]);
  responsebody += QStringLiteral("\" readonly=\"readonly\" /></label>\n  </p>\n  <p>\n    <label>Lfdnr<br /><input class=\"w3-input\" type=\"text\" name=\"annexData[lfdnr]\" value=\"");
  responsebody += THttpUtility::htmlEscape(annexData["lfdnr"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Spec Title<br /><input class=\"w3-input\" type=\"text\" name=\"annexData[specTitle]\" value=\"");
  responsebody += THttpUtility::htmlEscape(annexData["specTitle"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n<!--\n  <p>\n    <label>Spec Desc<br /><input class=\"w3-input\" type=\"text\" name=\"annexData[specDesc]\" value=\"");
  responsebody += THttpUtility::htmlEscape(annexData["specDesc"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Spec Version<br /><input class=\"w3-input\" type=\"text\" name=\"annexData[specVersion]\" value=\"");
  responsebody += THttpUtility::htmlEscape(annexData["specVersion"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Spec Release<br /><input class=\"w3-input\" type=\"text\" name=\"annexData[specRelease]\" value=\"");
  responsebody += THttpUtility::htmlEscape(annexData["specRelease"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Obj Sname<br /><input class=\"w3-input\" type=\"text\" name=\"annexData[objSname]\" value=\"");
  responsebody += THttpUtility::htmlEscape(annexData["objSname"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Ac Classes<br /><input class=\"w3-input\" type=\"text\" name=\"annexData[acClasses]\" value=\"");
  responsebody += THttpUtility::htmlEscape(annexData["acClasses"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Pc Classes<br /><input class=\"w3-input\" type=\"text\" name=\"annexData[pcClasses]\" value=\"");
  responsebody += THttpUtility::htmlEscape(annexData["pcClasses"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Cat Class<br /><input class=\"w3-input\" type=\"text\" name=\"annexData[catClass]\" value=\"");
  responsebody += THttpUtility::htmlEscape(annexData["catClass"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Country<br /><input class=\"w3-input\" type=\"text\" name=\"annexData[country]\" value=\"");
  responsebody += THttpUtility::htmlEscape(annexData["country"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Lang<br /><input class=\"w3-input\" type=\"text\" name=\"annexData[lang]\" value=\"");
  responsebody += THttpUtility::htmlEscape(annexData["lang"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Spec Content<br /><input class=\"w3-input\" type=\"text\" name=\"annexData[specContent]\" value=\"");
  responsebody += THttpUtility::htmlEscape(annexData["specContent"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Spec Active<br /><input class=\"w3-input\" type=\"text\" name=\"annexData[specActive]\" value=\"");
  responsebody += THttpUtility::htmlEscape(annexData["specActive"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <input type=\"submit\" value=\"Save\" />\n  </p>\n</form>\n-->\n\n  <br/>\n  <h4>Daten Quellcode</h4>\n  <p>\n    <label>Spec Content Source Code</label><br /><article><textarea name=\"annexData[specContent]\" style=\"width:100%; height:350px;\">");
  responsebody += THttpUtility::htmlEscape(annexData["specContent"]);
  responsebody += QStringLiteral("</textarea></article>\n  </p>\n  <p>\n    <input type=\"submit\" value=\"speichern &raquo;\"/>\n  </p>\n</form>\n\n<br>\n<span class=\"w3-btn w3-red\"><img src=\"/Icons/trash.svg\">&nbsp;");
  responsebody += QVariant(linkTo("Remove", urla("remove", annexData["id"]), Tf::Post, "confirm('Are you sure?')")).toString();
  responsebody += QStringLiteral("</span>\n&nbsp;&nbsp;&nbsp;\n<a href=\"/standardsdata/editor_upd/");
  responsebody += THttpUtility::htmlEscape(annexData["id"]);
  responsebody += QStringLiteral("\" class=\"w3-btn w3-light-grey\"><img src=\"/Icons/textarea-t.svg\">&nbsp;Editor</a>\n<a href=\"/standardsdata/list_all\" class=\"w3-btn w3-light-grey\"><img src=\"/Icons/justify.svg\">&nbsp;zur&uuml;ck</a>\n\n<br/><br/>\n<h4>Daten Anzeige</h4>\n<p><label>Spec Content View</label><br><article><section>");
  responsebody += QVariant(annexData["specContent"]).toString();
  responsebody += QStringLiteral("</section></article></p>\n\n<br>\n<span class=\"w3-btn w3-red\" style=\"border-radius: 0px 0px 0px 0.5em\"><img src=\"/Icons/trash.svg\">&nbsp;");
  responsebody += QVariant(linkTo("Remove", urla("remove", annexData["id"]), Tf::Post, "confirm('Are you sure?')")).toString();
  responsebody += QStringLiteral("</span>\n&nbsp;&nbsp;&nbsp;\n<a href=\"/AnnexData/editor_upd/");
  responsebody += THttpUtility::htmlEscape(annexData["id"]);
  responsebody += QStringLiteral("\" class=\"w3-btn w3-light-grey\"><img src=\"/Icons/textarea-t.svg\">&nbsp;Editor</a>\n<a href=\"/AnnexData/list_all\" class=\"w3-btn w3-light-grey\"><img src=\"/Icons/justify.svg\">&nbsp;zur&uuml;ck</a>\n\n\n</main>\n<itis-footer id=\"itisFooter\" message=\"\"></itis-footer>\n  \n</body>\n</html>\n");

  return responsebody;
}

T_DEFINE_VIEW(annexdata_saveView)

#include "annexdata_saveView.moc"
