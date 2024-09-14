#include <QtCore>
#include <TreeFrogView>
#include "lenkinfo.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT lenkinfo_list_allView : public TActionView
{
  Q_OBJECT
public:
  lenkinfo_list_allView() : TActionView() { }
  QString toString();
};

QString lenkinfo_list_allView::toString()
{
  responsebody.reserve(8014);
  responsebody += QStringLiteral("<!DOCTYPE html>\n");
    responsebody += QStringLiteral("<html>\n<head>\n  <meta charset=\"UTF-8\">\n  <html lang=\"de\">\n\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QStringLiteral("</title>\n\n  <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, user-scalable=yes\">\n  <link rel=\"icon\" href=\"/favicon.ico\">\n  \n  <link rel=\"preload\" href=\"/fonts/Inter-Regular.woff2\" as=\"font\" type=\"font/woff2\" crossorigin />\n\n  <script>\n    function doLocal()\n    {\n        console.log(\"this is local\");\n\n        let l_footer = document.getElementById(\"itisFooter\");\n        l_footer.message = '<a href=\"/stdsystem/license\" title=\"license\">Lizenzen</a>&nbsp;<a href=\"/stdsystem/imprint\" title=\"Imprint\">Impressum</a>';\n\n        //let l_menu = document.getElementById(\"itisMenu\"); \n        //l_menu.message = \"");
  responsebody += THttpUtility::htmlEscape(controller()->name());
  responsebody += QStringLiteral("\";\n    }\n\n	function setLanguage(lang)\n	{\n		if(lang == \"0\")\n		{lang = \"de\";}\n		else{lang = \"en\";}\n		document.cookie = \"lang=\" + lang + \";\" + \";path=/\";\n		location.reload();\n	}\n	\n	function open_show(id) \n	{\n		window.open(\"/lenkinfo/show/\" + id);\n	}\n\n	function open_qedit(id) \n	{\n		window.open(\"/lenkinfo/save/\" + id);\n	}\n\n	function open_edit(id) \n	{\n		window.open(\"/lenkinfo/editor_upd/\" + id);\n	}\n\n\n  </script>\n\n  <script type=\"module\" src=\"/js/itis_init.js\" /></script>\n  <script src=\"/js/utc-data/UtcData.js\"></script>\n  <script src=\"/js/kommabr-data/KommaBrData.js\"></script>\n  \n  <link rel=\"stylesheet\" href=\"/css/w3.css\">  \n  <link rel=\"stylesheet\" href=\"/css/custom.css\">\n    \n  <link href=\"/css/tabulator/tabulator.min.css\" rel=\"stylesheet\">\n  <script type=\"text/javascript\" src=\"/js/tabulator/tabulator.min.js\"></script>\n		<script src=\"/js/tabulator/tblsort.js\"></script>\n		<style>\n			table.sortable th:not(.sorttable_sorted):not(.sorttable_sorted_reverse):not(.sorttable_nosort):after { content: \" \\25B4\\25BE\" }\n			table, th, td { border: 1px solid #bbb; text-align: left; }\n			th { background-color: #ddd; }\n		</style>\n</head>\n\n<body class=\"w3-container w3-margin\" id=\"body\">\n\n  <itis-menu id=\"itisMenu\" message=\"\"></itis-menu>\n\n  <div class=\"w3-container w3-light-blue\">\n    <h2 id=\"portaltitle\">ITIS-API::Admin-Portal</h2>\n  </div>\n\n  <itis-menusub id=\"itisMenuSub\" message=\"");
  responsebody += THttpUtility::htmlEscape(controller()->name());
  responsebody += QStringLiteral("\"></itis-menusub>\n\n<h3 id=\"pagetitle\"><page-title message=\"\">");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QStringLiteral("</page-title></h3>\n<div id=\"pagedesc\"><page-desc message=\"\">Ungefilterte Auflistung <u>aller</u> Bausteine.</u></page-desc></div>\n\n<span style=\"color: red;\">\n	<span  id=\"redmsg\">");
  techoex(red_msg);
  responsebody += QStringLiteral("</span>&nbsp;<span>");
  tehex(error);
  responsebody += QStringLiteral("</span>\n</span>\n<span style=\"color: green;\">\n	<span id=\"greenmsg\">");
  techoex(green_msg);
  responsebody += QStringLiteral("</span>&nbsp;<span>");
  tehex(notice);
  responsebody += QStringLiteral("</span>\n</span>\n\n<main>\n<div id=\"pagecontent\"><page-content message=\"\"></page-content></div>\n\n<br />\n<table class=\"w3-table-all w3-hoverable sortable\" id=\"myTable\">\n  <tr class=\"w3-text-grey\">\n    <th>ID</th>\n    <th>Spec Obj</th>\n    <th style=\"width:100px;\">Spec Title</th>\n    <th>Ac Class</th>\n    <th>Pc Class</th>\n    <th>Country</th>\n    <th>Lang</th>\n    <th>Lenk Version</th>\n    <th>Lenk Status</th>\n    <th>Lenk Valid Startdate</th>\n    <!-- <th>Lenk Departments</th> -->\n    <th style=\"width:180px;\">Lenk Content</th>\n    <!-- <th>Lenk Creator</th> -->\n    <!-- <th>Lenk Creator Date</th> -->\n    <!-- <th>Lenk Auditor</th> -->\n    <!-- <th>Lenk Auditor Date</th> -->\n    <!-- <th>Lenk Approver</th> -->\n    <!-- <th>Lenk Approver Date</th> -->\n    <th style=\"width:160px;\">Baustein</th>\n  </tr>\n");
  tfetch(QList<Lenkinfo>, lenkinfoList);
  for (const auto &i : lenkinfoList) {
  responsebody += QStringLiteral("  <tr>\n    <td>");
  responsebody += THttpUtility::htmlEscape(i.id());
  responsebody += QStringLiteral("</td>\n    <td>");
  responsebody += THttpUtility::htmlEscape(i.specObj());
  responsebody += QStringLiteral("</td>\n    <td>");
  responsebody += THttpUtility::htmlEscape(i.specTitle());
  responsebody += QStringLiteral("</td>\n    <td>");
  responsebody += THttpUtility::htmlEscape(i.acClass());
  responsebody += QStringLiteral("</td>\n    <td>");
  responsebody += THttpUtility::htmlEscape(i.pcClass());
  responsebody += QStringLiteral("</td>\n    <td>");
  responsebody += THttpUtility::htmlEscape(i.country());
  responsebody += QStringLiteral("</td>\n    <td>");
  responsebody += THttpUtility::htmlEscape(i.lang());
  responsebody += QStringLiteral("</td>\n    <td>");
  responsebody += THttpUtility::htmlEscape(i.lenkVersion());
  responsebody += QStringLiteral("</td>\n    <td>");
  responsebody += THttpUtility::htmlEscape(i.lenkStatus());
  responsebody += QStringLiteral("</td>\n    <td><data-utc id=\"datautc\" utctime=\"");
  responsebody += THttpUtility::htmlEscape(i.lenkValidStartdate());
  responsebody += QStringLiteral("\"></data-utc></td>\n    <!-- <td>");
  responsebody += THttpUtility::htmlEscape(i.lenkDepartments());
  responsebody += QStringLiteral("</td> -->\n    <td><data-kommabr txtdata=\"");
  responsebody += THttpUtility::htmlEscape(i.lenkContent());
  responsebody += QStringLiteral("\"></data-kommabr></td>\n    <!-- <td><data-kommabr txtdata=\"");
  responsebody += THttpUtility::htmlEscape(i.lenkCreator());
  responsebody += QStringLiteral("\"></data-kommabr></td> -->\n    <!-- <td><data-utc id=\"datautc\" utctime=\"");
  responsebody += THttpUtility::htmlEscape(i.lenkCreatorDate());
  responsebody += QStringLiteral("\"></data-utc></td> -->\n    <!-- <td><data-kommabr txtdata=\"");
  responsebody += THttpUtility::htmlEscape(i.lenkAuditor());
  responsebody += QStringLiteral("\"></data-kommabr></td> -->\n    <!-- <td><data-utc id=\"datautc\" utctime=\"");
  responsebody += THttpUtility::htmlEscape(i.lenkAuditorDate());
  responsebody += QStringLiteral("\"></data-utc></td> -->\n    <!-- <td><data-kommabr txtdata=\"");
  responsebody += THttpUtility::htmlEscape(i.lenkApprover());
  responsebody += QStringLiteral("\"></data-kommabr></td> -->\n    <!-- <td><data-utc id=\"datautc\" utctime=\"");
  responsebody += THttpUtility::htmlEscape(i.lenkApproverDate());
  responsebody += QStringLiteral("\"></data-utc></td> -->\n    <td>\n      <a style=\"background: none;\" href=\"javascript:void(0)\" onclick=\"open_show('");
  responsebody += THttpUtility::htmlEscape(i.id());
  responsebody += QStringLiteral("')\" title=\"Show Details\"><img src=\"/Icons/eyeglasses.svg\"></a>\n	  <a style=\"background: none;\" href=\"javascript:void(0)\" onclick=\"open_qedit('");
  responsebody += THttpUtility::htmlEscape(i.id());
  responsebody += QStringLiteral("')\" title=\"Q-Edit\"><img src=\"/Icons/pencil.svg\"></a>\n      <a style=\"background: none;\" href=\"javascript:void(0)\" onclick=\"open_edit('");
  responsebody += THttpUtility::htmlEscape(i.id());
  responsebody += QStringLiteral("')\" title=\"Edit\"><img src=\"/Icons/textarea-t.svg\"></a>  \n	  <a style=\"background: none;\" href=\"javascript:void(0)\" onclick=\"open_show('");
  responsebody += THttpUtility::htmlEscape(i.id());
  responsebody += QStringLiteral("')\" title=\"Remove\"><img src=\"/Icons/trash.svg\"></a>\n    </td>\n  </tr>\n");
  };
  responsebody += QStringLiteral("</table>\n\n</main>\n<itis-footer id=\"itisFooter\" message=\"\"></itis-footer>\n  \n</body>\n</html>\n\n");

  return responsebody;
}

T_DEFINE_VIEW(lenkinfo_list_allView)

#include "lenkinfo_list_allView.moc"
