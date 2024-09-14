#include <QtCore>
#include <TreeFrogView>
#include "releaseannex.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT releasemgmt_saveannexView : public TActionView
{
  Q_OBJECT
public:
  releasemgmt_saveannexView() : TActionView() { }
  QString toString();
};

QString releasemgmt_saveannexView::toString()
{
  responsebody.reserve(7638);
  responsebody += QStringLiteral("<!DOCTYPE html>\n");
    tfetch(QVariantMap, releaseAnnex);
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
  responsebody += QStringLiteral("</p>\n\n<main>\n<div id=\"pagecontent\"><page-content message=\"\"></page-content></div>\n\n<a href=\"javascript:window.close();\" class=\"w3-btn w3-light-grey\" style=\"border-radius: 0.5em 0px 0px 0px;\"><img src=\"/Icons/justify.svg\">&nbsp;zur&uuml;ck</a>\n<br/><br>\n\n");
  responsebody += QVariant(formTag(urla("saveAnnex", releaseAnnex["id"]), Tf::Post)).toString();
  responsebody += QStringLiteral("\n  <p>\n    <label>ID<br /><input class=\"w3-input\" type=\"text\" name=\"releaseAnnex[id]\" value=\"");
  responsebody += THttpUtility::htmlEscape(releaseAnnex["id"]);
  responsebody += QStringLiteral("\" readonly=\"readonly\" /></label>\n  </p>\n  <p>\n    <label>Lfdnr<br /><input class=\"w3-input\" type=\"text\" name=\"releaseAnnex[lfdnr]\" value=\"");
  responsebody += THttpUtility::htmlEscape(releaseAnnex["lfdnr"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Spec Title<br /><input class=\"w3-input\" type=\"text\" name=\"releaseAnnex[specTitle]\" value=\"");
  responsebody += THttpUtility::htmlEscape(releaseAnnex["specTitle"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n\n  <p>\n    <label>Spec Desc<br /><input class=\"w3-input\" type=\"text\" name=\"releaseAnnex[specDesc]\" value=\"");
  responsebody += THttpUtility::htmlEscape(releaseAnnex["specDesc"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Spec Version<br /><input class=\"w3-input\" type=\"text\" name=\"releaseAnnex[specVersion]\" value=\"");
  responsebody += THttpUtility::htmlEscape(releaseAnnex["specVersion"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Spec Release<br /><input class=\"w3-input\" type=\"text\" name=\"releaseAnnex[specRelease]\" value=\"");
  responsebody += THttpUtility::htmlEscape(releaseAnnex["specRelease"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Obj Sname<br /><input class=\"w3-input\" type=\"text\" name=\"releaseAnnex[objSname]\" value=\"");
  responsebody += THttpUtility::htmlEscape(releaseAnnex["objSname"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Ac Classes<br /><input class=\"w3-input\" type=\"text\" name=\"releaseAnnex[acClasses]\" value=\"");
  responsebody += THttpUtility::htmlEscape(releaseAnnex["acClass"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Pc Classes<br /><input class=\"w3-input\" type=\"text\" name=\"releaseAnnex[pcClasses]\" value=\"");
  responsebody += THttpUtility::htmlEscape(releaseAnnex["pcClass"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Cat Class<br /><input class=\"w3-input\" type=\"text\" name=\"releaseAnnex[catClass]\" value=\"");
  responsebody += THttpUtility::htmlEscape(releaseAnnex["catClass"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Country<br /><input class=\"w3-input\" type=\"text\" name=\"releaseAnnex[country]\" value=\"");
  responsebody += THttpUtility::htmlEscape(releaseAnnex["country"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Lang<br /><input class=\"w3-input\" type=\"text\" name=\"releaseAnnex[lang]\" value=\"");
  responsebody += THttpUtility::htmlEscape(releaseAnnex["lang"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n<!--\n  <p>\n    <label>Spec Content<br /><input class=\"w3-input\" type=\"text\" name=\"releaseAnnex[specContent]\" value=\"");
  responsebody += THttpUtility::htmlEscape(releaseAnnex["specContent"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n\n  <p>\n    <label>Spec Active<br /><input class=\"w3-input\" type=\"text\" name=\"releaseAnnex[specActive]\" value=\"");
  responsebody += THttpUtility::htmlEscape(releaseAnnex["specActive"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <input id=\"dosave\" type=\"submit\" value=\"speichern &raquo;\"/>\n  </p>\n</form>\n-->\n\n  <br/>\n  <h4>Daten Quellcode</h4>\n  <p>\n    <label>Spec Content Source Code</label><br /><article><textarea name=\"releaseAnnex[specContent]\" style=\"width:100%; height:350px;\">");
  responsebody += THttpUtility::htmlEscape(releaseAnnex["specContent"]);
  responsebody += QStringLiteral("</textarea></article>\n  </p>\n  <p>\n    <input type=\"submit\" value=\"speichern &raquo;\"/>\n  </p>\n</form>\n\n<br>\n<a href=\"javascript:window.close();\" class=\"w3-btn w3-light-grey\"><img src=\"/Icons/justify.svg\">&nbsp;zur&uuml;ck</a>\n\n<br/><br/>\n<h4>Daten Anzeige</h4>\n<p><label>Spec Content View</label><br><article><section>");
  responsebody += QVariant(releaseAnnex["specContent"]).toString();
  responsebody += QStringLiteral("</section></article></p>\n\n<br>\n<a href=\"javascript:window.close();\" class=\"w3-btn w3-light-grey\" style=\"border-radius: 0px 0px 0px 0.5em\"><img src=\"/Icons/justify.svg\">&nbsp;zur&uuml;ck</a>\n<input type=\"submit\" value=\"speichern &raquo;\" onClick=\"doSave()\"/>\n\n</main>\n\n<script>\nfunction doSave()\n{\n	document.getElementById(\"dosave\").click();\n}\n</script>\n\n<itis-footer id=\"itisFooter\" message=\"\"></itis-footer>\n  \n</body>\n</html>\n");

  return responsebody;
}

T_DEFINE_VIEW(releasemgmt_saveannexView)

#include "releasemgmt_saveannexView.moc"
