#include <QtCore>
#include <TreeFrogView>
#include "releasemgmt.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT releasemgmt_listAllAnnexCdView : public TActionView
{
  Q_OBJECT
public:
  releasemgmt_listAllAnnexCdView() : TActionView() { }
  QString toString();
};

QString releasemgmt_listAllAnnexCdView::toString()
{
  responsebody.reserve(6314);
  responsebody += QStringLiteral("<!DOCTYPE html>\n");
    responsebody += QStringLiteral("<html>\n<head>\n  <meta charset=\"UTF-8\">\n  <html lang=\"de\">\n\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QStringLiteral("</title>\n\n  <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, user-scalable=yes\">\n  <link rel=\"icon\" href=\"/favicon.ico\">\n\n  <script>\n    function doLocal()\n    {\n        console.log(\"this is local\");\n\n        let l_footer = document.getElementById(\"itisFooter\");\n        l_footer.message = '<a href=\"/stdsystem/license\" title=\"license\">Lizenzen</a>&nbsp;<a href=\"/stdsystem/imprint\" title=\"Imprint\">Impressum</a>';\n        \n        var ageMutator = function(value, data, type, params, component)\n		{\n			//change age value into boolean, true if over the provided legal age\n			//var erg = \"<a href=\\\"/ObjSpecs/show/\" + value + \"\\\"><span class=\\\"w3-text-blue\\\">Bearbeitung</span></a>\";   \n			var erg = '<a href=\"/ReleaseMgmt/show/' + value + '\" title=\"Show\" style=\"background: none;\" ><img src=\"/Icons/eyeglasses.svg\"></a>&nbsp;&nbsp;&nbsp;';   \n			erg += '<a href=\"/ReleaseMgmt/save/' + value + '\" title=\"Q-Edit\" style=\"background: none;\" ><img src=\"/Icons/pencil.svg\"></a>';\n\n			return erg;\n		}\n								\n		var table = new Tabulator(\"#example-table\", \n		{\n			layout:\"fitColumns\",\n			responsiveLayout:\"collapse\",\n			placeholder:\"keine Daten\",\n			columns:[\n				{title:\"Object\", field:\"obj_sname\", sorter:\"string\", width:300},\n				{title:\"Country\", field:\"country\", sorter:\"string\"},\n				{title:\"Lang\", field:\"lang\", sorter:\"string\"},\n				{title:\"AC\", field:\"ac_classes\", sorter:\"string\"},\n				{title:\"PC\", field:\"pc_classes\", sorter:\"string\"},\n				{title:\"Version\", field:\"spec_version\", sorter:\"string\"},\n				{title:\"CD Date\", field:\"cd_date\", sorter:\"string\"},\n				{title:\"Baustein\", field:\"id\", formatter:\"html\", width:100, mutatorData:ageMutator, mutatorDataParams:{legalAge:18}},\n			],\n			htmlOutputConfig:{\n				formatCells:false, \n			},\n		});\n\n		table.setData(\"/ReleaseMgmt/list_allAnnexCd\");\n		\n		getAnnexCdPDFs();\n    }\n\n	function setLanguage(lang)\n	{\n		if(lang == \"0\")\n		{lang = \"de\";}\n		else{lang = \"en\";}\n		document.cookie = \"lang=\" + lang + \";\" + \";path=/\";\n		location.reload();\n	}\n	\n	function open_show(id) \n	{\n		window.open(\"/releasemgmt/show/\" + id);\n	}\n\n	function open_qedit(id) \n	{\n		window.open(\"/releasemgmt/save/\" + id);\n	}\n\nfunction getAnnexCdPDFs()\n{\n	let place = document.getElementById('annex');\n			\n	fetch(\"/releasemgmt/getAnnexCdPDFs\").then(function (response) \n    {\n        return response.json();\n    }).then(function (json) \n    {\n        var Obj = json;	\n        if(Obj.length < 1)\n        {\n			return;\n		}\n		let table = document.createElement(\"table\");\n		table.setAttribute(\"class\", \"w3-table-all w3-hoverable sortable\");\n		\n		let tr = document.createElement(\"tr\");\n		tr.setAttribute(\"class\", \"w3-text-grey\");\n\n		let th = document.createElement(\"th\");\n		th.innerHTML = \"Name\";\n		tr.appendChild(th);\n		th = document.createElement(\"th\");\n		th.innerHTML = \"zuletzt aktualisiert\";\n		tr.appendChild(th);\n		th = document.createElement(\"th\");\n		th.innerHTML = \"download\";\n		tr.appendChild(th);\n		table.appendChild(tr);\n        for (i in Obj) \n        {\n			let tr = document.createElement('tr');\n			\n			let name = document.createElement('td');\n			name.innerHTML = Obj[i].name;\n			tr.appendChild(name);\n			\n			let modified = document.createElement('td');\n			modified.innerHTML = Obj[i].last_modified;\n			tr.appendChild(modified);\n			\n			let download = document.createElement('td');\n			download.innerHTML = `<a href=\"${Obj[i].uri}\" alt=\"\" download>${Obj[i].name} (${Obj[i].size}kB)</a>`;\n			tr.appendChild(download);\n\n			table.appendChild(tr);\n        }\n        place.appendChild(table);\n    });\n} \n	\n  </script>\n\n  <script type=\"module\" src=\"/js/itis_init.js\" /></script>\n  <link rel=\"stylesheet\" href=\"/css/w3.css\">  \n  <link rel=\"stylesheet\" href=\"/css/custom.css\">\n  \n  <link href=\"/css/tabulator/tabulator.min.css\" rel=\"stylesheet\">\n  <script type=\"text/javascript\" src=\"/js/tabulator/tabulator.min.js\"></script>\n		<script src=\"/js/tabulator/tblsort.js\"></script>\n		<style>\n			table.sortable th:not(.sorttable_sorted):not(.sorttable_sorted_reverse):not(.sorttable_nosort):after { content: \" \\25B4\\25BE\" }\n			table, th, td { border: 1px solid #bbb; text-align: left; }\n			th { background-color: #ddd; }\n		</style>\n		\n	<script src=\"/js/utc-data/UtcData.js\"></script>\n</head>\n\n<body class=\"w3-container w3-margin\" id=\"body\">\n\n  <itis-menu id=\"itisMenu\" message=\"\"></itis-menu>\n\n  <div class=\"w3-container w3-light-blue\">\n    <h2 id=\"portaltitle\">ITIS-API::Admin-Portal</h2>\n  </div>\n\n  <itis-menusub id=\"itisMenuSub\" message=\"");
  responsebody += THttpUtility::htmlEscape(controller()->name());
  responsebody += QStringLiteral("\"></itis-menusub>\n\n<h3 id=\"pagetitle\"><page-title message=\"\">");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QStringLiteral("</page-title></h3>\n<div id=\"pagedesc\"><page-desc message=\"\">Auflistung <u>aller</u> Annex Releases (CD).</u></page-desc></div>\n\n<span style=\"color: red\">\n	<span  id=\"redmsg\">");
  techoex(red_msg);
  responsebody += QStringLiteral("</span>&nbsp;<span>");
  tehex(error);
  responsebody += QStringLiteral("</span>\n</span>\n<span style=\"color: green\">\n	<span id=\"greenmsg\">");
  techoex(green_msg);
  responsebody += QStringLiteral("</span>&nbsp;<span>");
  tehex(notice);
  responsebody += tr("</span>\n</span>\n\n<main>\n<div id=\"pagecontent\"><page-content message=\"\"></page-content></div>\n\n<br />\n\n<section>\n	<h4>Annex CD</h4>\n	<div id=\"example-table\"></div>\n</section>\n\n<section>\n	<h4>Anhänge CD PDF's</h4>\n		<span id=\"annex\"></span>\n</section>\n\n</main>\n<itis-footer id=\"itisFooter\" message=\"\"></itis-footer>\n  \n</body>\n</html>\n");

  return responsebody;
}

T_DEFINE_VIEW(releasemgmt_listAllAnnexCdView)

#include "releasemgmt_listAllAnnexCdView.moc"
