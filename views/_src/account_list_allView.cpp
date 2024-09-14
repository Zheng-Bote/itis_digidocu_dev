#include <QtCore>
#include <TreeFrogView>
#include "itisuser.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT account_list_allView : public TActionView
{
  Q_OBJECT
public:
  account_list_allView() : TActionView() { }
  QString toString();
};

QString account_list_allView::toString()
{
  responsebody.reserve(7051);
  responsebody += QStringLiteral("<!DOCTYPE html>\n");
    responsebody += QStringLiteral("<html>\n<head>\n  <meta charset=\"UTF-8\">\n  <html lang=\"de\">\n\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QStringLiteral("</title>\n\n  <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, user-scalable=yes\">\n  <link rel=\"icon\" href=\"/favicon.ico\">\n\n  <script>\n    function doLocal()\n    {\n        console.log(\"this is local\");\n\n        let l_footer = document.getElementById(\"itisFooter\");\n        l_footer.message = '<a href=\"/stdsystem/license\" title=\"license\">Lizenzen</a>&nbsp;<a href=\"/stdsystem/imprint\" title=\"Imprint\">Impressum</a>';\n\n        //let l_menu = document.getElementById(\"itisMenu\"); \n        //l_menu.message = \"");
  responsebody += THttpUtility::htmlEscape(controller()->name());
  responsebody += QStringLiteral("\";\n    }\n\n	function setLanguage(lang)\n	{\n		if(lang == \"0\")\n		{lang = \"de\";}\n		else{lang = \"en\";}\n		document.cookie = \"lang=\" + lang + \";\" + \";path=/\";\n		location.reload();\n	}\n	\n	function open_show(id) \n	{\n		window.open(\"/account/show/\" + id);\n	}\n\n	function open_qedit(id) \n	{\n		window.open(\"/account/save/\" + id);\n	}\n\n	function open_edit(id) \n	{\n		window.open(\"/account/save/\" + id);\n	}\n\n	function convertUTCDateToLocalDate(date, id) \n	{\n		//var d = convertUTCDateToLocalDate(new Date(\"2020-09-13T10:49:02.174\"));\n		var newDate = new Date(date.getTime()+date.getTimezoneOffset()*60*1000);\n\n		var offset = date.getTimezoneOffset() / 60;\n		var hours = date.getHours();\n\n		newDate.setHours(hours - offset);\n		\n		var mm = newDate.getMonth() + 1;\n		var dd = newDate.getDate();\n		var yy = newDate.getFullYear();\n		var hh = newDate.getHours();\n		var m = newDate.getMinutes();\n\n		if(mm < 10)\n		{\n			mm = \"0\" + mm;\n		}\n		if(dd < 10)\n		{\n			dd = \"0\" + dd;\n		}\n		if(hh < 10)\n		{\n			hh = \"0\" + hh;\n		}\n		if(m < 10)\n		{\n			m = \"0\" + m;\n		}\n		let datestr = yy + \"-\" + mm + \"-\" + dd + \" \" + hh + \":\" + m;\n	\n		document.getElementById(id).innerHTML = datestr;   \n	}\n  </script>\n\n  <script type=\"module\" src=\"/js/itis_init.js\" /></script>\n  <link rel=\"stylesheet\" href=\"/css/w3.css\">  \n  <link rel=\"stylesheet\" href=\"/css/custom.css\">\n    \n  <link href=\"/css/tabulator/tabulator.min.css\" rel=\"stylesheet\">\n  <script type=\"text/javascript\" src=\"/js/tabulator/tabulator.min.js\"></script>\n		<script src=\"/js/tabulator/tblsort.js\"></script>\n		<style>\n			table.sortable th:not(.sorttable_sorted):not(.sorttable_sorted_reverse):not(.sorttable_nosort):after { content: \" \\25B4\\25BE\" }\n			table, th, td { border: 1px solid #bbb; text-align: left; }\n			th { background-color: #ddd; }\n		</style>\n</head>\n\n<body class=\"w3-container w3-margin\" id=\"body\">\n\n  <itis-menu id=\"itisMenu\" message=\"\"></itis-menu>\n\n  <div class=\"w3-container w3-light-blue\">\n    <h2 id=\"portaltitle\">ITIS-API::Admin-Portal</h2>\n  </div>\n\n  <itis-menusub id=\"itisMenuSub\" message=\"");
  responsebody += THttpUtility::htmlEscape(controller()->name());
  responsebody += QStringLiteral("\"></itis-menusub>\n\n<h3 id=\"pagetitle\"><page-title message=\"\">");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QStringLiteral("</page-title></h3>\n<div id=\"pagedesc\"><page-desc message=\"\"></page-desc></div>\n\n<p id=\"redmsg\" style=\"color: red\">");
  techoex(red_msg);
  tehex(error);
  responsebody += QStringLiteral("</p><p id=\"greenmsg\" style=\"color: green\">");
  techoex(green_msg);
  tehex(notice);
  responsebody += QStringLiteral("</p>\n\n<main>\n<div id=\"pagecontent\"><page-content message=\"\"></page-content></div>\n\n<br />\n<table class=\"w3-table-all w3-hoverable sortable\" id=\"myTable\">\n  <tr class=\"w3-text-grey\">\n    <th>ID</th>\n    <th>username</th>\n    <th>firstname</th>\n    <th>surname</th>\n    <th>eMail</th>\n    <th>Company</th>\n    <th>Timezone</th>\n    <th>groupname</th>\n    <th>groups</th>\n    <th>last login</th>\n    <th>login time</th>\n    <th>logged out</th>\n    <th>pwd changed time</th>\n    <th>pwd change force</th>\n    <th>Active</th>\n    <th style=\"width:120px;\">Baustein</th>\n  </tr>\n");
  tfetch(QList<ItisUser>, itisUserList);
  for (const auto &i : itisUserList) {
  responsebody += QStringLiteral("  <tr>\n    <td>");
  responsebody += THttpUtility::htmlEscape(i.id());
  responsebody += QStringLiteral("</td>\n    <td>");
  responsebody += THttpUtility::htmlEscape(i.username());
  responsebody += QStringLiteral("</td>\n    <td>");
  responsebody += THttpUtility::htmlEscape(i.firstname());
  responsebody += QStringLiteral("</td>\n    <td>");
  responsebody += THttpUtility::htmlEscape(i.surname());
  responsebody += QStringLiteral("</td>\n    <td>");
  responsebody += THttpUtility::htmlEscape(i.email());
  responsebody += QStringLiteral("</td>\n    <td>");
  responsebody += THttpUtility::htmlEscape(i.company());
  responsebody += QStringLiteral("</td>\n    <td>");
  responsebody += THttpUtility::htmlEscape(i.userTimezone());
  responsebody += QStringLiteral("</td>\n    <td>");
  responsebody += THttpUtility::htmlEscape(i.groupname());
  responsebody += QStringLiteral("</td>\n    <td>");
  responsebody += THttpUtility::htmlEscape(i.groups());
  responsebody += QStringLiteral("</td>\n    <td>");
  responsebody += THttpUtility::htmlEscape(i.lastLogin());
  responsebody += QStringLiteral("</td>\n    <td>");
  responsebody += THttpUtility::htmlEscape(i.loginTime());
  responsebody += QStringLiteral("</td>\n    <td>");
  responsebody += THttpUtility::htmlEscape(i.loggedOut());
  responsebody += QStringLiteral("</td>\n    <td>");
  responsebody += THttpUtility::htmlEscape(i.pwdChangedTime());
  responsebody += QStringLiteral("</td>\n    <td>");
  responsebody += THttpUtility::htmlEscape(i.pwdChangeForce());
  responsebody += QStringLiteral("</td>\n    <td>");
  responsebody += THttpUtility::htmlEscape(i.active());
  responsebody += QStringLiteral("</td>\n    <td>\n      <a href=\"javascript:void(0)\" onclick=\"open_show('");
  responsebody += THttpUtility::htmlEscape(i.id());
  responsebody += QStringLiteral("')\" title=\"Show Details\"><img src=\"/Icons/eyeglasses.svg\"></a>&nbsp;&nbsp;&nbsp;\n	  <a href=\"javascript:void(0)\" onclick=\"open_qedit('");
  responsebody += THttpUtility::htmlEscape(i.id());
  responsebody += QStringLiteral("')\" title=\"Q-Edit\"><img src=\"/Icons/pencil.svg\"></a>&nbsp;&nbsp;&nbsp;\n	  <a href=\"javascript:void(0)\" onclick=\"open_show('");
  responsebody += THttpUtility::htmlEscape(i.id());
  responsebody += QStringLiteral("')\" title=\"Remove\"><img src=\"/Icons/trash.svg\"></a>\n    </td>\n  </tr>\n");
  };
  responsebody += QStringLiteral("</table>\n\n</main>\n<itis-footer id=\"itisFooter\" message=\"\"></itis-footer>\n  \n</body>\n</html>\n");

  return responsebody;
}

T_DEFINE_VIEW(account_list_allView)

#include "account_list_allView.moc"
