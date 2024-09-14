#include <QtCore>
#include <TreeFrogView>
#include "releasemgmt.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT releasemgmt_list_pdfView : public TActionView
{
  Q_OBJECT
public:
  releasemgmt_list_pdfView() : TActionView() { }
  QString toString();
};

QString releasemgmt_list_pdfView::toString()
{
  responsebody.reserve(4767);
  responsebody += QStringLiteral("<!DOCTYPE html>\n");
    responsebody += QStringLiteral("<html>\n<head>\n  <meta charset=\"UTF-8\">\n  <html lang=\"de\">\n\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QStringLiteral("</title>\n\n  <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, user-scalable=yes\">\n  <link rel=\"icon\" href=\"/favicon.ico\">\n\n  <script>\n    function doLocal()\n    {\n        console.log(\"this is local\");\n\n        let l_footer = document.getElementById(\"itisFooter\");\n        l_footer.message = '<a href=\"/stdsystem/license\" title=\"license\">Lizenzen</a>&nbsp;<a href=\"/stdsystem/imprint\" title=\"Imprint\">Impressum</a>';\n\n		var ageMutator = function(value, data, type, params, component)\n		{\n			//change age value into boolean, true if over the provided legal age\n			//var erg = \"<a href=\\\"/ObjSpecs/show/\" + value + \"\\\"><span class=\\\"w3-text-blue\\\">Bearbeitung</span></a>\";   \n			var erg = '<a href=\"javascript:void(0)\" onclick=\"open_objlist()\" class=\"w3-btn w3-light-grey\" title=\"Obj Spec-Liste\" style=\"background: none;\" ><img src=\"/Icons/justify.svg\"></a>&nbsp;&nbsp;&nbsp;'; \n			erg += '<a href=\"javascript:void(0)\" onclick=\"open_win(' + value + ')\" title=\"Show\" style=\"background: none;\" ><img src=\"/Icons/eyeglasses.svg\"></a>&nbsp;&nbsp;&nbsp;';   \n			erg += \"<a href=\\\"/standardsdata/save/\" + value + \"\\\" title=\\\"Q-Edit\\\" style=\\\"background: none;\\\" ><img src=\\\"/Icons/pencil.svg\\\"></a>&nbsp;&nbsp;&nbsp;\";\n			erg += \"<a href=\\\"/standardsdata/editor_upd/\" + value + \"\\\" title=\\\"Edit\\\" style=\\\"background: none;\\\" ><img src=\\\"/Icons/textarea-t.svg\\\"></a>&nbsp;&nbsp;&nbsp;\";   \n			erg += \"<a href=\\\"/standardsdata/show/\" + value + \"\\\" title=\\\"Remove\\\" style=\\\"background: none;\\\" ><img src=\\\"/Icons/trash.svg\\\"></a>\";\n\n			return erg;\n		}\n								\n		var anneTable = new Tabulator(\"#annex-table\", \n		{\n			layout:\"fitColumns\",\n			responsiveLayout:\"collapse\",\n			placeholder:\"keine Daten\",\n			columns:[\n				{title:\"uri\", field:\"uri\", sorter:\"string\", width:300},\n				{title:\"name\", field:\"sname\", sorter:\"string\"},\n				{title:\"size\", field:\"size\", sorter:\"number\"},\n				{title:\"Baustein\", field:\"name\", formatter:\"html\", mutatorData:ageMutator, mutatorDataParams:{legalAge:18}},\n			],\n			htmlOutputConfig:{\n				formatCells:false, \n			},\n		});\n\n		anneTable.setData(\"/releasemgmt/getAnnexCdPDFs\");\n\n    }\n\n	function setLanguage(lang)\n	{\n		if(lang == \"0\")\n		{lang = \"de\";}\n		else{lang = \"en\";}\n		document.cookie = \"lang=\" + lang + \";\" + \";path=/\";\n		location.reload();\n	}\n\n  </script>\n\n  <script type=\"module\" src=\"/js/itis_init.js\" /></script>\n  <link rel=\"stylesheet\" href=\"/css/w3.css\">  \n  <link rel=\"stylesheet\" href=\"/css/custom.css\">\n  \n	<link href=\"/css/tabulator/tabulator.min.css\" rel=\"stylesheet\">\n    <script type=\"text/javascript\" src=\"/js/tabulator/tabulator.min.js\"></script>\n		\n	<script type=\"text/javascript\" src=\"/js/releasemgmt/list_pdf.js\"></script>\n</head>\n\n<body class=\"w3-container w3-margin\" id=\"body\">\n\n  <itis-menu id=\"itisMenu\" message=\"\"></itis-menu>\n\n  <div class=\"w3-container w3-light-blue\">\n    <h2 id=\"portaltitle\">ITIS-API::Admin-Portal</h2>\n  </div>\n\n  <itis-menusub id=\"itisMenuSub\" message=\"");
  responsebody += THttpUtility::htmlEscape(controller()->name());
  responsebody += QStringLiteral("\"></itis-menusub>\n\n<h3 id=\"pagetitle\"><page-title message=\"\">");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += tr("</page-title></h3>\n<div id=\"pagedesc\"><page-desc message=\"\">Auflistung der veröffentlichten Vorgaben (pdf, docx, odt).</u></page-desc></div>\n\n<span style=\"color: red;\">\n	<span  id=\"redmsg\">");
  techoex(red_msg);
  responsebody += QStringLiteral("</span>&nbsp;<span>");
  tehex(error);
  responsebody += QStringLiteral("</span>\n</span>\n<span style=\"color: green;\">\n	<span id=\"greenmsg\">");
  techoex(green_msg);
  responsebody += QStringLiteral("</span>&nbsp;<span>");
  tehex(notice);
  responsebody += tr("</span>\n</span>\n\n<main>\n<div id=\"pagecontent\"><page-content message=\"\"></page-content></div>\n\n<br />\n<section>\n	<h3>Vorgaben</h3>\n		<div id=\"std-table\"></div>\n</section>\n<section>\n	<h3>Anhänge</h3>\n		<div id=\"annex-table\"></div>\n\n</main>\n\n<script>\n	getStdCdPDFs();\n	getAnnexCdPDFs();\n</script>\n\n<itis-footer id=\"itisFooter\" message=\"\"></itis-footer>\n  \n</body>\n</html>\n");

  return responsebody;
}

T_DEFINE_VIEW(releasemgmt_list_pdfView)

#include "releasemgmt_list_pdfView.moc"
