#include <QtCore>
#include <TreeFrogView>
#include "releasemgmt.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT releasemgmt_list_allView : public TActionView
{
  Q_OBJECT
public:
  releasemgmt_list_allView() : TActionView() { }
  QString toString();
};

QString releasemgmt_list_allView::toString()
{
  responsebody.reserve(7455);
  responsebody += QStringLiteral("<!DOCTYPE html>\n");
    responsebody += QStringLiteral("<html>\n<head>\n  <meta charset=\"UTF-8\">\n  <html lang=\"de\">\n\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QStringLiteral("</title>\n\n  <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, user-scalable=yes\">\n  <link rel=\"icon\" href=\"/favicon.ico\">\n\n  <script>\n    function doLocal()\n    {\n        console.log(\"this is local\");\n\n        let l_footer = document.getElementById(\"itisFooter\");\n        l_footer.message = '<a href=\"/stdsystem/license\" title=\"license\">Lizenzen</a>&nbsp;<a href=\"/stdsystem/imprint\" title=\"Imprint\">Impressum</a>';\n    }\n\n	function setLanguage(lang)\n	{\n		if(lang == \"0\")\n		{lang = \"de\";}\n		else{lang = \"en\";}\n		document.cookie = \"lang=\" + lang + \";\" + \";path=/\";\n		location.reload();\n	}\n	\n	function open_show(id) \n	{\n		window.open(\"/releasemgmt/show/\" + id);\n	}\n\n	function open_qedit(id) \n	{\n		window.open(\"/releasemgmt/save/\" + id);\n	}\n	\n  </script>\n\n  <script type=\"module\" src=\"/js/itis_init.js\" /></script>\n  <link rel=\"stylesheet\" href=\"/css/w3.css\">  \n  <link rel=\"stylesheet\" href=\"/css/custom.css\">\n  \n  <link href=\"/css/tabulator/tabulator.min.css\" rel=\"stylesheet\">\n  <script type=\"text/javascript\" src=\"/js/tabulator/tabulator.min.js\"></script>\n		<script src=\"/js/tabulator/tblsort.js\"></script>\n		<style>\n			table.sortable th:not(.sorttable_sorted):not(.sorttable_sorted_reverse):not(.sorttable_nosort):after { content: \" \\25B4\\25BE\" }\n			table, th, td { border: 1px solid #bbb; text-align: left; }\n			th { background-color: #ddd; }\n		</style>\n		\n	<script src=\"/js/utc-data/UtcData.js\"></script>\n</head>\n\n<body class=\"w3-container w3-margin\" id=\"body\">\n\n  <itis-menu id=\"itisMenu\" message=\"\"></itis-menu>\n\n  <div class=\"w3-container w3-light-blue\">\n    <h2 id=\"portaltitle\">ITIS-API::Admin-Portal</h2>\n  </div>\n\n  <itis-menusub id=\"itisMenuSub\" message=\"");
  responsebody += THttpUtility::htmlEscape(controller()->name());
  responsebody += QStringLiteral("\"></itis-menusub>\n\n<h3 id=\"pagetitle\"><page-title message=\"\">");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QStringLiteral("</page-title></h3>\n<div id=\"pagedesc\"><page-desc message=\"\">Ungefilterte Auflistung <u>aller</u> Bausteine.</u></page-desc></div>\n\n<span style=\"color: red\">\n	<span  id=\"redmsg\">");
  techoex(red_msg);
  responsebody += QStringLiteral("</span>&nbsp;<span>");
  tehex(error);
  responsebody += QStringLiteral("</span>\n</span>\n<span style=\"color: green\">\n	<span id=\"greenmsg\">");
  techoex(green_msg);
  responsebody += QStringLiteral("</span>&nbsp;<span>");
  tehex(notice);
  responsebody += QStringLiteral("</span>\n</span>\n\n<main>\n<div id=\"pagecontent\"><page-content message=\"\"></page-content></div>\n\n<br />\n<table class=\"w3-table-all w3-hoverable sortable\" id=\"myTable\">\n  <tr class=\"w3-text-grey\">\n    <th>ID</th>\n    <th>Obj Sname</th>\n    <!-- <th>Spec Version</th> -->\n    <th>AC</th>\n    <th>PC</th>\n    <!-- <th>Cat Class</th> -->\n    <th>Country</th>\n    <th>Lang</th>\n    <!-- <th>Doc Type</th> -->\n    <!-- <th>Rel Requester</th> -->\n    <!-- <th>Relrequest Date</th> -->\n    <th>Rel Creator</th>\n    <th>Relcreator Decisdate</th>\n    <th>Rel Inspector</th>\n    <th>Relinspect Decisdate</th>\n    <th>Rel Approver</th>\n    <th>Relapprov Decisdate</th>\n    <th>CI Date</th>\n    <th>CD Date</th>\n    <th>CDD Date</th>\n    <th style=\"width:150px;\">Baustein</th>\n  </tr>\n");
  tfetch(QList<ReleaseMgmt>, releaseMgmtList);
  for (const auto &i : releaseMgmtList) {
  responsebody += QStringLiteral("  <tr>\n    <td>");
  responsebody += THttpUtility::htmlEscape(i.id());
  responsebody += QStringLiteral("</td>\n    <td>");
  responsebody += THttpUtility::htmlEscape(i.objSname());
  responsebody += QStringLiteral("</td>\n    <!-- <td>");
  responsebody += THttpUtility::htmlEscape(i.specVersion());
  responsebody += QStringLiteral("</td> -->\n    <td>");
  responsebody += THttpUtility::htmlEscape(i.acClasses());
  responsebody += QStringLiteral("</td>\n    <td>");
  responsebody += THttpUtility::htmlEscape(i.pcClasses());
  responsebody += QStringLiteral("</td>\n    <!-- <td>");
  responsebody += THttpUtility::htmlEscape(i.catClass());
  responsebody += QStringLiteral("</td> -->\n    <td>");
  responsebody += THttpUtility::htmlEscape(i.country());
  responsebody += QStringLiteral("</td>\n    <td>");
  responsebody += THttpUtility::htmlEscape(i.lang());
  responsebody += QStringLiteral("</td>\n    <!-- <td>");
  responsebody += THttpUtility::htmlEscape(i.docType());
  responsebody += QStringLiteral("</td> -->\n    <!-- <td>");
  responsebody += THttpUtility::htmlEscape(i.relRequester());
  responsebody += QStringLiteral("</td> -->\n    <!-- <td id=\"relrequestDate\"><script>convertUTCDateToLocalDate(new Date(\"");
  responsebody += THttpUtility::htmlEscape(i.relrequestDate());
  responsebody += QStringLiteral("\"), \"relrequestDate\")</script></td> -->\n    <td>");
  responsebody += THttpUtility::htmlEscape(i.relCreator());
  responsebody += QStringLiteral("</td>\n    <td><data-utc utctime=\"");
  responsebody += THttpUtility::htmlEscape(i.relcreatorDecisdate());
  responsebody += QStringLiteral("\"></data-utc></td>\n    <td>");
  responsebody += THttpUtility::htmlEscape(i.relInspector());
  responsebody += QStringLiteral("</td>\n    <td><data-utc utctime=\"");
  responsebody += THttpUtility::htmlEscape(i.relinspectDecisdate());
  responsebody += QStringLiteral("\"></data-utc></td>\n    <td>");
  responsebody += THttpUtility::htmlEscape(i.relApprover());
  responsebody += QStringLiteral("</td>\n    <td><data-utc utctime=\"");
  responsebody += THttpUtility::htmlEscape(i.relapprovDecisdate());
  responsebody += QStringLiteral("\"></data-utc></td>\n    <td><data-utc utctime=\"");
  responsebody += THttpUtility::htmlEscape(i.ciDate());
  responsebody += QStringLiteral("\"></data-utc></td>\n    <td><data-utc utctime=\"");
  responsebody += THttpUtility::htmlEscape(i.cdDate());
  responsebody += QStringLiteral("\"></data-utc></td>\n    <td><data-utc utctime=\"");
  responsebody += THttpUtility::htmlEscape(i.cddDate());
  responsebody += QStringLiteral("\"></data-utc></td>\n    <td>\n      <a href=\"javascript:void(0)\" onclick=\"open_show('");
  responsebody += THttpUtility::htmlEscape(i.id());
  responsebody += QStringLiteral("')\" title=\"Show Details\" style=\"background: none;\"><img src=\"/Icons/eyeglasses.svg\"></a>&nbsp;&nbsp;&nbsp;\n	  <a href=\"javascript:void(0)\" onclick=\"open_qedit('");
  responsebody += THttpUtility::htmlEscape(i.id());
  responsebody += QStringLiteral("')\" title=\"Q-Edit\" style=\"background: none;\"><img src=\"/Icons/pencil.svg\"></a>&nbsp;&nbsp;&nbsp;\n	  <a href=\"javascript:void(0)\" onclick=\"open_show('");
  responsebody += THttpUtility::htmlEscape(i.id());
  responsebody += QStringLiteral("')\" title=\"Remove\" style=\"background: none;\"><img src=\"/Icons/trash.svg\"></a>\n    </td>\n  </tr>\n");
  };
  responsebody += QStringLiteral("</table>\n\n</main>\n<itis-footer id=\"itisFooter\" message=\"\"></itis-footer>\n  \n</body>\n</html>\n");

  return responsebody;
}

T_DEFINE_VIEW(releasemgmt_list_allView)

#include "releasemgmt_list_allView.moc"
