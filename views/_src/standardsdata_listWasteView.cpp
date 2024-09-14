#include <QtCore>
#include <TreeFrogView>
#include "standardsdata.h" 
#include "standardsdatawaste.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT standardsdata_listWasteView : public TActionView
{
  Q_OBJECT
public:
  standardsdata_listWasteView() : TActionView() { }
  QString toString();
};

QString standardsdata_listWasteView::toString()
{
  responsebody.reserve(9081);
  responsebody += QStringLiteral("<!DOCTYPE html>\n");
      responsebody += QStringLiteral("<html>\n<head>\n  <meta charset=\"UTF-8\">\n  <html lang=\"de\">\n\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QStringLiteral("</title>\n\n  <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, user-scalable=yes\">\n  <link rel=\"icon\" href=\"/favicon.ico\">\n\n  <script>\n    function doLocal()\n    {\n        console.log(\"this is local\");\n\n        let l_footer = document.getElementById(\"itisFooter\");\n        l_footer.message = '<a href=\"/stdsystem/license\" title=\"license\">Lizenzen</a>&nbsp;<a href=\"/stdsystem/imprint\" title=\"Imprint\">Impressum</a>';\n\n        //let l_menu = document.getElementById(\"itisMenu\"); \n        //l_menu.message = \"");
  responsebody += THttpUtility::htmlEscape(controller()->name());
  responsebody += QStringLiteral("\";\n        \n        let counter = \"");
  tehex(counter);
  responsebody += QStringLiteral("\";\n        if(counter > 50)\n        {\n			document.getElementById(\"redmsg\").innerHTML = `${counter} Bausteine gefunden`; \n		}\n		else\n		{\n			document.getElementById(\"greenmsg\").innerHTML = `${counter} Bausteine gefunden`; \n		}\n    }\n	\n	function setLanguage(lang)\n	{\n		if(lang == \"0\")\n		{lang = \"de\";}\n		else{lang = \"en\";}\n		document.cookie = \"lang=\" + lang + \";\" + \";path=/\";\n		location.reload();\n	}\n	\n	function open_show(id) \n	{\n		window.open(\"/standardsdata/showWaste/\" + id);\n	}\n\n	function open_qedit(id) \n	{\n		window.open(\"/standardsdata/save/\" + id);\n	}\n\n	function open_edit(id) \n	{\n		window.open(\"/standardsdata/editor_upd/\" + id);\n	}\n\n	function convertUTCDateToLocalDate(date, id) \n	{\n		//var d = convertUTCDateToLocalDate(new Date(\"2020-09-13T10:49:02.174\"));\n		var newDate = new Date(date.getTime()+date.getTimezoneOffset()*60*1000);\n\n		var offset = date.getTimezoneOffset() / 60;\n		var hours = date.getHours();\n\n		newDate.setHours(hours - offset);\n		\n		var mm = newDate.getMonth() + 1;\n		var dd = newDate.getDate();\n		var yy = newDate.getFullYear();\n		var hh = newDate.getHours();\n		var m = newDate.getMinutes();\n\n		if(mm < 10)\n		{\n			mm = \"0\" + mm;\n		}\n		if(dd < 10)\n		{\n			dd = \"0\" + dd;\n		}\n		if(hh < 10)\n		{\n			hh = \"0\" + hh;\n		}\n		if(m < 10)\n		{\n			m = \"0\" + m;\n		}\n		let datestr = yy + \"-\" + mm + \"-\" + dd + \" \" + hh + \":\" + m;\n	\n		document.getElementById(id).innerHTML = datestr;   \n	}\n	\n	function doRecover(id)\n	{\n		fetch(\"/StandardsData/doRecover/\" + id)\n		  .then(data => data.json())\n		  .then((json) => \n		  {\n			if(json[0].ERROR === \"0\")\n			{\n				document.getElementById(\"greenmsg\").innerHTML = `<b>Baustein wieder hergestellt.</b><br/>Data-ID:<a href=\"/standardsdata/show/${json[0].last_data_id}\" title=\"show\">${json[0].last_data_id}</a><br/>Meta-ID: ${json[0].last_meta_id}`;\n				doPopUp(`<p style=\"color: green\"><b>Baustein wieder hergestellt.</b><br/>Data-ID: ${json[0].last_data_id}<br/>Meta-ID: ${json[0].last_meta_id}</p>`);\n			}\n			else\n			{\n				document.getElementById(\"redmsg\").innerHTML = \"<b>Baustein <u>nicht</u> wieder hergestellt.</b><br/>\" + json[0].ERROR + \" \" + json[0].errMsg ;\n				doPopUp(`<p style=\"color: red\"><b>Baustein <u>nicht</u> wieder hergestellt.</b><br/>${json[0].ERROR}<br/>${json[0].errMsg}</p>`);\n			}\n		  })\n		  .catch((error) => { document.getElementById(\"redmsg\").innerHTML = \"Fehler: \" + error + data; });\n	}\n	\n	function doPopUp(msg)\n	{\n		const mgsTxt = document.getElementById(\"msg\");\n		mgsTxt.innerHTML = msg;		\n		const test = document.getElementById(\"test\");\n		test.setAttribute(\"style\", \"display: block;\");\n		\n		window.location.href='#body';\n	}\n  </script>\n\n  <script type=\"module\" src=\"/js/itis_init.js\" /></script>\n  <link rel=\"stylesheet\" href=\"/css/w3.css\">  \n  \n  <link href=\"/css/tabulator/tabulator.min.css\" rel=\"stylesheet\">\n  <script type=\"text/javascript\" src=\"/js/tabulator/tabulator.min.js\"></script>\n		<script src=\"/js/tabulator/tblsort.js\"></script>\n		<style>\n			table.sortable th:not(.sorttable_sorted):not(.sorttable_sorted_reverse):not(.sorttable_nosort):after { content: \" \\25B4\\25BE\" }\n			table, th, td { border: 1px solid #bbb; text-align: left; }\n			th { background-color: #ddd; }\n		</style>\n</head>\n\n<body class=\"w3-container w3-margin\" id=\"body\">\n\n  <itis-menu id=\"itisMenu\" message=\"\"></itis-menu>\n\n  <div class=\"w3-container w3-light-blue\">\n    <h2 id=\"portaltitle\">ITIS-API::Admin-Portal</h2>\n  </div>\n\n  <itis-menusub id=\"itisMenuSub\" message=\"");
  responsebody += THttpUtility::htmlEscape(controller()->name());
  responsebody += QStringLiteral("\"></itis-menusub>\n\n<h3 id=\"pagetitle\"><page-title message=\"\">");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QStringLiteral("</page-title></h3>\n<div id=\"pagedesc\"><page-desc message=\"\">Ungefilterte Auflistung <u>aller</u> gel&ouml;schten Vorgaben Bausteine.</u></page-desc></div>\n\n<p style=\"color: red\"><span id=\"redmsg\">");
  techoex(red_msg);
  responsebody += QStringLiteral(" ");
  tehex(error);
  responsebody += QStringLiteral("</span></p><p style=\"color: green\"><span id=\"greenmsg\">");
  techoex(green_msg);
  responsebody += QStringLiteral(" ");
  tehex(notice);
  responsebody += QStringLiteral("</span></p>\n\n<div id=\"test\" style=\"display: none;\" class=\"w3-modal\">\n    <div class=\"w3-modal-content\">\n      <div class=\"w3-container\">\n        <span onclick=\"document.getElementById('test').style.display='none'\" class=\"w3-button w3-display-topright\">&times;</span>\n        <span id=\"msg\"></span>\n      </div>\n    </div>\n  </div>\n</div>\n\n<main>\n<div id=\"pagecontent\"><page-content message=\"\"></page-content></div>\n\n<table class=\"w3-table-all w3-hoverable sortable\" id=\"myTable\">\n  <tr class=\"w3-text-grey\">\n    <th>gel&ouml;scht am</th>\n    <th>Lfdnr</th>\n    <th>Spec Title</th>\n    <th>Spec Desc</th>\n    <th>Spec Version</th>\n    <th>Spec Release</th>\n    <th>Obj Sname</th>\n    <th>Ac Classes</th>\n    <th>Pc Classes</th>\n    <th>Cat Class</th>\n    <th>Country</th>\n    <th>Lang</th>\n    <th style=\"width:150px;\">Wiederherstellung</th>\n  </tr>\n");
  tfetch(QList<StandardsDataWaste>, standardsDataWasteList);
  for (const auto &i : standardsDataWasteList) {
  responsebody += QStringLiteral("  <tr>\n    <td id=\"");
  responsebody += THttpUtility::htmlEscape(i.id());
  responsebody += QStringLiteral("\"><script>convertUTCDateToLocalDate(new Date(\"");
  responsebody += THttpUtility::htmlEscape(i.changedOn());
  responsebody += QStringLiteral("\"), \"");
  responsebody += THttpUtility::htmlEscape(i.id());
  responsebody += QStringLiteral("\")</script></td>\n    <td>");
  responsebody += THttpUtility::htmlEscape(i.lfdnr());
  responsebody += QStringLiteral("</td>\n    <td>");
  responsebody += THttpUtility::htmlEscape(i.specTitle());
  responsebody += QStringLiteral("</td>\n    <td>");
  responsebody += THttpUtility::htmlEscape(i.specDesc());
  responsebody += QStringLiteral("</td>\n    <td>");
  responsebody += THttpUtility::htmlEscape(i.specVersion());
  responsebody += QStringLiteral("</td>\n    <td>");
  responsebody += THttpUtility::htmlEscape(i.specRelease());
  responsebody += QStringLiteral("</td>\n    <td>");
  responsebody += THttpUtility::htmlEscape(i.objSname());
  responsebody += QStringLiteral("</td>\n    <td>");
  responsebody += THttpUtility::htmlEscape(i.acClasses());
  responsebody += QStringLiteral("</td>\n    <td>");
  responsebody += THttpUtility::htmlEscape(i.pcClasses());
  responsebody += QStringLiteral("</td>\n    <td>");
  responsebody += THttpUtility::htmlEscape(i.catClass());
  responsebody += QStringLiteral("</td>\n    <td>");
  responsebody += THttpUtility::htmlEscape(i.country());
  responsebody += QStringLiteral("</td>\n    <td>");
  responsebody += THttpUtility::htmlEscape(i.lang());
  responsebody += QStringLiteral("</td>\n    <td>\n	  <a style=\"background: none;\" href=\"javascript:void(0)\" onclick=\"open_show('");
  responsebody += THttpUtility::htmlEscape(i.id());
  responsebody += QStringLiteral("')\" title=\"final delete\"><img src=\"/Icons/trash.svg\"></a>&nbsp;&nbsp;&nbsp;\n	  <a style=\"background: none;\" href=\"javascript:void(0)\" onclick=\"open_show('");
  responsebody += THttpUtility::htmlEscape(i.id());
  responsebody += QStringLiteral("')\" title=\"Show Details\"><img src=\"/Icons/eyeglasses.svg\"></a>&nbsp;&nbsp;&nbsp;\n      <img src=\"/Icons/box-arrow-left.svg\" onclick=\"doRecover('");
  responsebody += THttpUtility::htmlEscape(i.id());
  responsebody += QStringLiteral("')\" title=\"do recovery\">\n    </td>\n  </tr>\n");
  };
  responsebody += QStringLiteral("</table>\n\n</main>\n<itis-footer id=\"itisFooter\" message=\"\"></itis-footer>\n  \n</body>\n</html>\n");

  return responsebody;
}

T_DEFINE_VIEW(standardsdata_listWasteView)

#include "standardsdata_listWasteView.moc"
