#include <QtCore>
#include <TreeFrogView>
#include "releasemgmt.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT releasemgmt_createView : public TActionView
{
  Q_OBJECT
public:
  releasemgmt_createView() : TActionView() { }
  QString toString();
};

QString releasemgmt_createView::toString()
{
  responsebody.reserve(7136);
  responsebody += QStringLiteral("<!DOCTYPE html>\n");
    tfetch(QVariantMap, releaseMgmt);
  responsebody += QStringLiteral("<html>\n<head>\n  <meta charset=\"UTF-8\">\n  <html lang=\"de\">\n\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QStringLiteral("</title>\n\n  <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, user-scalable=yes\">\n  <link rel=\"icon\" href=\"/favicon.ico\">\n\n  <script>\n    function doLocal()\n    {\n        console.log(\"this is local\");\n\n        let l_footer = document.getElementById(\"itisFooter\");\n        l_footer.message = '<a href=\"/stdsystem/license\" title=\"license\">Lizenzen</a>&nbsp;<a href=\"/stdsystem/imprint\" title=\"Imprint\">Impressum</a>';\n    }\n\n	function setLanguage(lang)\n	{\n		if(lang == \"0\")\n		{lang = \"de\";}\n		else{lang = \"en\";}\n		document.cookie = \"lang=\" + lang + \";\" + \";path=/\";\n		location.reload();\n	}\n	\n	function open_show(id) \n	{\n		window.open(\"/releasemgmt/show/\" + id);\n	}\n\n	function open_qedit(id) \n	{\n		window.open(\"/releasemgmt/save/\" + id);\n	}\n\n	function open_edit(id) \n	{\n		window.open(\"/releasemgmt/save/\" + id);\n	}\n\n  </script>\n\n  <script type=\"module\" src=\"/js/itis_init.js\" /></script>\n  <link rel=\"stylesheet\" href=\"/css/w3.css\">  \n  <link rel=\"stylesheet\" href=\"/css/custom.css\">\n   \n</head>\n\n<body class=\"w3-container w3-margin\" id=\"body\">\n\n  <itis-menu id=\"itisMenu\" message=\"\"></itis-menu>\n\n  <div class=\"w3-container w3-light-blue\">\n    <h2 id=\"portaltitle\">ITIS-API::Admin-Portal</h2>\n  </div>\n\n  <itis-menusub id=\"itisMenuSub\" message=\"");
  responsebody += THttpUtility::htmlEscape(controller()->name());
  responsebody += QStringLiteral("\"></itis-menusub>\n\n<h3><page-title id=\"pagetitle\" message=\"\">");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QStringLiteral("</page-title></h3>\n<page-desc id=\"pagedesc\" message=\"\"></page-desc>\n\n<span style=\"color: red\">\n	<span  id=\"redmsg\">");
  techoex(red_msg);
  responsebody += QStringLiteral("</span>&nbsp;<span>");
  tehex(error);
  responsebody += QStringLiteral("</span>\n</span>\n<span style=\"color: green\">\n	<span id=\"greenmsg\">");
  techoex(green_msg);
  responsebody += QStringLiteral("</span>&nbsp;<span>");
  tehex(notice);
  responsebody += QStringLiteral("</span>\n</span>\n\n<main>\n<div id=\"pagecontent\"><page-content message=\"\"></page-content></div>	\n\n<section> \n\n");
  responsebody += QVariant(formTag(urla("create"), Tf::Post)).toString();
  responsebody += QStringLiteral("\n  <p>\n    <label>Obj Sname<br /><input name=\"releaseMgmt[objSname]\" value=\"");
  responsebody += THttpUtility::htmlEscape(releaseMgmt["objSname"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Spec Version<br /><input name=\"releaseMgmt[specVersion]\" value=\"");
  responsebody += THttpUtility::htmlEscape(releaseMgmt["specVersion"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Ac Classes<br /><input name=\"releaseMgmt[acClasses]\" value=\"");
  responsebody += THttpUtility::htmlEscape(releaseMgmt["acClasses"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Pc Classes<br /><input name=\"releaseMgmt[pcClasses]\" value=\"");
  responsebody += THttpUtility::htmlEscape(releaseMgmt["pcClasses"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Cat Class<br /><input name=\"releaseMgmt[catClass]\" value=\"");
  responsebody += THttpUtility::htmlEscape(releaseMgmt["catClass"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Country<br /><input name=\"releaseMgmt[country]\" value=\"");
  responsebody += THttpUtility::htmlEscape(releaseMgmt["country"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Lang<br /><input name=\"releaseMgmt[lang]\" value=\"");
  responsebody += THttpUtility::htmlEscape(releaseMgmt["lang"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Doc Type<br /><input name=\"releaseMgmt[docType]\" value=\"");
  responsebody += THttpUtility::htmlEscape(releaseMgmt["docType"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Rel Requester<br /><input name=\"releaseMgmt[relRequester]\" value=\"");
  responsebody += THttpUtility::htmlEscape(releaseMgmt["relRequester"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Relrequest Date<br /><input name=\"releaseMgmt[relrequestDate]\" value=\"");
  responsebody += THttpUtility::htmlEscape(releaseMgmt["relrequestDate"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Rel Creator<br /><input name=\"releaseMgmt[relCreator]\" value=\"");
  responsebody += THttpUtility::htmlEscape(releaseMgmt["relCreator"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Relcreator Decisdate<br /><input name=\"releaseMgmt[relcreatorDecisdate]\" value=\"");
  responsebody += THttpUtility::htmlEscape(releaseMgmt["relcreatorDecisdate"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Rel Inspector<br /><input name=\"releaseMgmt[relInspector]\" value=\"");
  responsebody += THttpUtility::htmlEscape(releaseMgmt["relInspector"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Relinspect Decisdate<br /><input name=\"releaseMgmt[relinspectDecisdate]\" value=\"");
  responsebody += THttpUtility::htmlEscape(releaseMgmt["relinspectDecisdate"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Rel Approver<br /><input name=\"releaseMgmt[relApprover]\" value=\"");
  responsebody += THttpUtility::htmlEscape(releaseMgmt["relApprover"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Relapprov Decisdate<br /><input name=\"releaseMgmt[relapprovDecisdate]\" value=\"");
  responsebody += THttpUtility::htmlEscape(releaseMgmt["relapprovDecisdate"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Ci Date<br /><input name=\"releaseMgmt[ciDate]\" value=\"");
  responsebody += THttpUtility::htmlEscape(releaseMgmt["ciDate"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Cd Date<br /><input name=\"releaseMgmt[cdDate]\" value=\"");
  responsebody += THttpUtility::htmlEscape(releaseMgmt["cdDate"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Cdd Date<br /><input name=\"releaseMgmt[cddDate]\" value=\"");
  responsebody += THttpUtility::htmlEscape(releaseMgmt["cddDate"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <input type=\"submit\" value=\"Create &raquo;\" />\n  </p>\n</form>\n\n</section>\n<br/>\n<a href=\"/releasemgmt/list_all\" class=\"w3-btn w3-light-grey\">&laquo;&nbsp;zur&uuml;ck</a>\n\n</main>\n\n<itis-footer id=\"itisFooter\" message=\"\"></itis-footer>\n</body>\n</html>\n\n");

  return responsebody;
}

T_DEFINE_VIEW(releasemgmt_createView)

#include "releasemgmt_createView.moc"
