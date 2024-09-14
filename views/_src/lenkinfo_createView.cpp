#include <QtCore>
#include <TreeFrogView>
#include "lenkinfo.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT lenkinfo_createView : public TActionView
{
  Q_OBJECT
public:
  lenkinfo_createView() : TActionView() { }
  QString toString();
};

QString lenkinfo_createView::toString()
{
  responsebody.reserve(8770);
  responsebody += QStringLiteral("<!DOCTYPE html>\n");
    tfetch(QVariantMap, lenkinfo);
  responsebody += QStringLiteral("<html>\n<head>\n  <meta charset=\"UTF-8\">\n  <html lang=\"de\">\n\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QStringLiteral("</title>\n\n  <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, user-scalable=yes\">\n  <link rel=\"icon\" href=\"/favicon.ico\">\n  \n  <link rel=\"preload\" href=\"/fonts/Inter-Regular.woff2\" as=\"font\" type=\"font/woff2\" crossorigin />\n\n  <script>\n    function doLocal()\n    {\n        console.log(\"this is local\");\n\n        let l_footer = document.getElementById(\"itisFooter\");\n        l_footer.message = '<a href=\"/stdsystem/license\" title=\"licenses\">Lizenzen</a>&nbsp;<a href=\"/stdsystem/imprint\" title=\"Imprint\">Impressum</a>';\n\n        //let l_menu = document.getElementById(\"itisMenu\"); \n        //l_menu.message = \"");
  responsebody += THttpUtility::htmlEscape(controller()->name());
  responsebody += QStringLiteral("\";\n    }\n\n	function setLanguage(lang)\n	{\n		if(lang == \"0\")\n		{lang = \"de\";}\n		else{lang = \"en\";}\n		document.cookie = \"lang=\" + lang + \";\" + \";path=/\";\n		location.reload();\n	}\n\n  </script>\n\n  <script type=\"module\" src=\"/js/itis_init.js\" /></script>\n  \n  <link rel=\"stylesheet\" href=\"/css/w3.css\">  \n  <link rel=\"stylesheet\" href=\"/css/custom.css\">  \n\n<style>\n	.set-width { max-width: 250px;	border-radius: 5px;}\n	.w3-half, .w3-third { margin-bottom: 1rem; }\n</style>\n\n</head>\n\n<body class=\"w3-container w3-margin\" id=\"body\">\n\n  <itis-menu id=\"itisMenu\" message=\"\"></itis-menu>\n\n  <div class=\"w3-container w3-light-blue\">\n    <h2 id=\"portaltitle\">ITIS-API::Admin-Portal</h2>\n  </div>\n\n  <itis-menusub id=\"itisMenuSub\" message=\"");
  responsebody += THttpUtility::htmlEscape(controller()->name());
  responsebody += QStringLiteral("\"></itis-menusub>\n\n<h3 id=\"pagetitle\"><page-title message=\"\">");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QStringLiteral("</page-title></h3>\n<div id=\"pagedesc\"><page-desc message=\"\"></page-desc></div>\n\n<span style=\"color: red;\">\n	<span  id=\"redmsg\">");
  techoex(red_msg);
  responsebody += QStringLiteral("</span>&nbsp;<span>");
  tehex(error);
  responsebody += QStringLiteral("</span>\n</span>\n<span style=\"color: green;\">\n	<span id=\"greenmsg\">");
  techoex(green_msg);
  responsebody += QStringLiteral("</span>&nbsp;<span>");
  tehex(notice);
  responsebody += QStringLiteral("</span>\n</span>\n\n<main>\n    \n<div id=\"pagecontent\"><page-content message=\"\"></page-content></div>	\n\n<section> \n");
  responsebody += QVariant(formTag(urla("create"), Tf::Post)).toString();
  responsebody += QStringLiteral("\n<div class=\"w3-row-padding\">\n  <div class=\"w3-half\">\n    <label class=\"w3-opacity\">Spec Obj<br /><input class=\"w3-input w3-border w3-round set-width\" name=\"lenkinfo[specObj]\" value=\"");
  responsebody += THttpUtility::htmlEscape(lenkinfo["specObj"]);
  responsebody += QStringLiteral("\" /></label>\n  </div>\n  <div class=\"w3-half\">\n    <label class=\"w3-opacity\">Spec Title<br /><input class=\"w3-input w3-border w3-round\" name=\"lenkinfo[specTitle]\" value=\"");
  responsebody += THttpUtility::htmlEscape(lenkinfo["specTitle"]);
  responsebody += QStringLiteral("\" /></label>\n  </div>\n  <div class=\"w3-half\">\n    <label class=\"w3-opacity\">AC Class <small>(1-4)</small><br /><input class=\"w3-input w3-border w3-round\" name=\"lenkinfo[acClass]\" value=\"");
  responsebody += THttpUtility::htmlEscape(lenkinfo["acClass"]);
  responsebody += QStringLiteral("\" /></label>\n  </div>\n  <div class=\"w3-half\">\n    <label class=\"w3-opacity\">PC Class <small>(1-4)</small><br /><input class=\"w3-input w3-border w3-round\" name=\"lenkinfo[pcClass]\" value=\"");
  responsebody += THttpUtility::htmlEscape(lenkinfo["pcClass"]);
  responsebody += QStringLiteral("\" /></label>\n  </div>\n  <div class=\"w3-half\">\n    <label class=\"w3-opacity\">Country <small>(WW | DE | EN ...)</small><br /><input class=\"w3-input w3-border w3-round\" name=\"lenkinfo[country]\" value=\"");
  responsebody += THttpUtility::htmlEscape(lenkinfo["country"]);
  responsebody += QStringLiteral("\" /></label>\n  </div>\n  <div class=\"w3-half\">\n    <label class=\"w3-opacity\">Lang <small>(de_DE | en_GB)</small><br /><input class=\"w3-input w3-border w3-round\" name=\"lenkinfo[lang]\" value=\"");
  responsebody += THttpUtility::htmlEscape(lenkinfo["lang"]);
  responsebody += QStringLiteral("\" /></label>\n  </div>\n  <div class=\"w3-half\">\n    <label class=\"w3-opacity\">Lenk Version <small>(00.00.00)</small><br /><input class=\"w3-input w3-border w3-round\" name=\"lenkinfo[lenkVersion]\" value=\"");
  responsebody += THttpUtility::htmlEscape(lenkinfo["lenkVersion"]);
  responsebody += QStringLiteral("\" /></label>\n  </div>\n  <div class=\"w3-half\">\n    <label class=\"w3-opacity\">Lenk Status <small>(draft | pre-released | released | expired)</small><br /><input class=\"w3-input w3-border w3-round\" name=\"lenkinfo[lenkStatus]\" value=\"");
  responsebody += THttpUtility::htmlEscape(lenkinfo["lenkStatus"]);
  responsebody += QStringLiteral("\" /></label>\n  </div>\n  <div class=\"w3-half\">\n    <label class=\"w3-opacity\">Lenk Valid Startdate <small>(dd.mm.yyyy)</small><br /><input type=\"date\" class=\"w3-input w3-border w3-round\" name=\"lenkinfo[lenkValidStartdate]\" value=\"");
  responsebody += THttpUtility::htmlEscape(lenkinfo["lenkValidStartdate"]);
  responsebody += QStringLiteral("\" /></label>\n  </div>\n  <div class=\"w3-half\">\n    <label class=\"w3-opacity\">Lenk Departments <small>(FG-84*, FG-85*, FG-86*, ...)</small><br /><input class=\"w3-input w3-border w3-round\" name=\"lenkinfo[lenkDepartments]\" value=\"");
  responsebody += THttpUtility::htmlEscape(lenkinfo["lenkDepartments"]);
  responsebody += QStringLiteral("\" /></label>\n  </div>\n  <p>\n    <label class=\"w3-opacity\">Lenk Content<br /><input class=\"w3-input w3-border w3-round\" name=\"lenkinfo[lenkContent]\" value=\"");
  responsebody += THttpUtility::htmlEscape(lenkinfo["lenkContent"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <div class=\"w3-half\">\n    <label class=\"w3-opacity\">Lenk Creator <small>(Name, Department)</small><br /><input class=\"w3-input w3-border w3-round\" name=\"lenkinfo[lenkCreator]\" value=\"");
  responsebody += THttpUtility::htmlEscape(lenkinfo["lenkCreator"]);
  responsebody += QStringLiteral("\" /></label>\n  </div>\n  <div class=\"w3-half\">\n    <label class=\"w3-opacity\">Lenk Creator Date <small>(dd.mm.yyyy)</small><br /><input type=\"date\" class=\"w3-input w3-border w3-round\" name=\"lenkinfo[lenkCreatorDate]\" value=\"");
  responsebody += THttpUtility::htmlEscape(lenkinfo["lenkCreatorDate"]);
  responsebody += QStringLiteral("\" /></label>\n  </div>\n  <div class=\"w3-half\">\n    <label class=\"w3-opacity\">Lenk Auditor <small>(Name, Department)</small><br /><input class=\"w3-input w3-border w3-round\" name=\"lenkinfo[lenkAuditor]\" value=\"");
  responsebody += THttpUtility::htmlEscape(lenkinfo["lenkAuditor"]);
  responsebody += QStringLiteral("\" /></label>\n  </div>\n  <div class=\"w3-half\">\n    <label class=\"w3-opacity\">Lenk Auditor Date <small>(dd.mm.yyyy)</small><br /><input type=\"date\" class=\"w3-input w3-border w3-round\" name=\"lenkinfo[lenkAuditorDate]\" value=\"");
  responsebody += THttpUtility::htmlEscape(lenkinfo["lenkAuditorDate"]);
  responsebody += QStringLiteral("\" /></label>\n  </div>\n  <div class=\"w3-half\">\n    <label class=\"w3-opacity\">Lenk Approver <small>(Name, Department)</small><br /><input class=\"w3-input w3-border w3-round\" name=\"lenkinfo[lenkApprover]\" value=\"");
  responsebody += THttpUtility::htmlEscape(lenkinfo["lenkApprover"]);
  responsebody += QStringLiteral("\" /></label>\n  </div>\n  <div class=\"w3-half\">\n    <label class=\"w3-opacity\">Lenk Approver Date <small>(dd.mm.yyyy)</small><br /><input type=\"date\" class=\"w3-input w3-border w3-round\" name=\"lenkinfo[lenkApproverDate]\" value=\"");
  responsebody += THttpUtility::htmlEscape(lenkinfo["lenkApproverDate"]);
  responsebody += QStringLiteral("\" /></label>\n  </div>\n  <p>&nbsp;</p>\n  <p>\n    <input type=\"submit\" value=\"Create &raquo;\" />\n  </p>\n</div>\n</form>\n\n</section>\n<br/>\n<a href=\"/lenkinfo/list_all\" class=\"w3-btn w3-light-grey\">&laquo;&nbsp;zur&uuml;ck</a>\n\n</main>\n\n<itis-footer id=\"itisFooter\" message=\"\"></itis-footer>\n</body>\n</html>\n");

  return responsebody;
}

T_DEFINE_VIEW(lenkinfo_createView)

#include "lenkinfo_createView.moc"
