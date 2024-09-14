#include <QtCore>
#include <TreeFrogView>
#include "applicationhelper.h"

class T_VIEW_EXPORT standardsdata_checkLfdnrCatView : public TActionView
{
  Q_OBJECT
public:
  standardsdata_checkLfdnrCatView() : TActionView() { }
  QString toString();
};

QString standardsdata_checkLfdnrCatView::toString()
{
  responsebody.reserve(5223);
  responsebody += QStringLiteral("<!DOCTYPE html>\n<html>\n<head>\n  <meta charset=\"UTF-8\">\n  <html lang=\"de\">\n\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QStringLiteral("</title>\n\n  <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, user-scalable=yes\">\n  \n  <link rel=\"icon\" type=\"image/svg+xml\" href=\"/favicon.svg\">\n  <link rel=\"alternate icon\" href=\"/favicon.ico\">\n  <link rel=\"mask-icon\" href=\"/favicon.svg\" color=\"#b2b2b2\">\n\n  <script>\n    function doLocal()\n    {\n        console.log(\"this is local\");\n\n        let l_footer = document.getElementById(\"itisFooter\");\n        l_footer.message = '<a href=\"/stdsystem/license\" title=\"licenses\">Lizenzen</a>&nbsp;<a href=\"/stdsystem/imprint\" title=\"Imprint\">Impressum</a>';\n\n        //let l_menu = document.getElementById(\"itisMenu\"); \n        //l_menu.message = \"");
  responsebody += THttpUtility::htmlEscape(controller()->name());
  responsebody += QStringLiteral("\";\n        \n		var ageMutator = function(value, data, type, params, component)\n		{\n			//change age value into boolean, true if over the provided legal age\n			//var erg = \"<a href=\\\"/ObjSpecs/show/\" + value + \"\\\"><span class=\\\"w3-text-blue\\\">Bearbeitung</span></a>\";   \n			var erg = '<a href=\"javascript:void(0)\" onclick=\"open_objlist()\" class=\"w3-btn w3-light-grey\" title=\"Obj Spec-Liste\" style=\"background: none;\" ><img src=\"/Icons/justify.svg\"></a>&nbsp;&nbsp;&nbsp;'; \n			erg += '<a href=\"javascript:void(0)\" onclick=\"open_win(' + value + ')\" title=\"Show\" style=\"background: none;\" ><img src=\"/Icons/eyeglasses.svg\"></a>&nbsp;&nbsp;&nbsp;';   \n			erg += \"<a href=\\\"/standardsdata/save/\" + value + \"\\\" title=\\\"Q-Edit\\\" style=\\\"background: none;\\\" ><img src=\\\"/Icons/pencil.svg\\\"></a>&nbsp;&nbsp;&nbsp;\";\n			erg += \"<a href=\\\"/standardsdata/editor_upd/\" + value + \"\\\" title=\\\"Edit\\\" style=\\\"background: none;\\\" ><img src=\\\"/Icons/textarea-t.svg\\\"></a>&nbsp;&nbsp;&nbsp;\";   \n			erg += \"<a href=\\\"/standardsdata/show/\" + value + \"\\\" title=\\\"Remove\\\" style=\\\"background: none;\\\" ><img src=\\\"/Icons/trash.svg\\\"></a>\";\n\n			return erg;\n		}\n								\n		var table = new Tabulator(\"#example-table\", \n		{\n			layout:\"fitColumns\",\n			responsiveLayout:\"collapse\",\n			placeholder:\"keine Daten\",\n			columns:[\n				{title:\"Title\", field:\"spec_title\", sorter:\"string\", width:300},\n				{title:\"Object\", field:\"obj_sname\", sorter:\"string\"},\n				{title:\"Country\", field:\"country\", sorter:\"string\"},\n				{title:\"Lang\", field:\"lang\", sorter:\"string\"},\n				{title:\"lfdnr\", field:\"lfdnr\", sorter:\"number\"},\n				{title:\"Cat\", field:\"cat_class\", sorter:\"string\"},\n				{title:\"Baustein\", field:\"id\", formatter:\"html\", mutatorData:ageMutator, mutatorDataParams:{legalAge:18}},\n			],\n			htmlOutputConfig:{\n				formatCells:false, \n			},\n		});\n\n		table.setData(\"/standardsdata/getCheckLfdnrCat\");\n	}    \n\n	function open_win(id) \n	{\n		window.open(\"/standardsdata/show/\" + id);\n	}\n\n	function open_objlist() \n	{\n		window.open(\"/standardsdata/list_all\");\n	}\n\n\n	function setLanguage(lang)\n	{\n		if(lang == \"0\")\n		{lang = \"de\";}\n		else{lang = \"en\";}\n		document.cookie = \"lang=\" + lang + \";\" + \";path=/\";\n		location.reload();\n	}\n  </script>\n\n  <script type=\"module\" src=\"/js/itis_init.js\" /></script>\n  <link rel=\"stylesheet\" href=\"/css/w3.css\">  \n  <link rel=\"stylesheet\" href=\"/css/custom.css\">  \n  \n	<link href=\"/css/tabulator/tabulator.min.css\" rel=\"stylesheet\">\n    <script type=\"text/javascript\" src=\"/js/tabulator/tabulator.min.js\"></script>\n\n</head>\n\n<body class=\"w3-container w3-margin\" id=\"body\">\n\n  <itis-menu id=\"itisMenu\" message=\"\"></itis-menu>\n\n  <div class=\"w3-container w3-light-blue\">\n    <h2 id=\"portaltitle\">ITIS-API::Admin-Portal</h2>\n  </div>\n\n  <itis-menusub id=\"itisMenuSub\" message=\"");
  responsebody += THttpUtility::htmlEscape(controller()->name());
  responsebody += QStringLiteral("\"></itis-menusub>\n\n<h3 id=\"pagetitle\"><page-title message=\"\">");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QStringLiteral("</page-title></h3>\n\n<div id=\"pagedesc\"><page-desc message=\"\">\n<p>Auflistung <u>aller</u> Bausteine mit Unstimmigkeiten (fehlende lfndr bzw. fehlende deutsche/englische Baustein-Version).</p>\n</page-desc></div>\n\n<p id=\"redmsg\" style=\"color: red\">");
  techoex(red_msg);
  tehex(error);
  responsebody += QStringLiteral("</p><p id=\"greenmsg\" style=\"color: green\">");
  techoex(green_msg);
  tehex(notice);
  responsebody += QStringLiteral("</p>\n\n<main>\n	<p>unstimmige Bausteine: ");
  techoex(countCheckLfdnrCat);
  responsebody += QStringLiteral("</p>\n<div id=\"pagecontent\"><page-content message=\"\"></page-content></div>\n\n<div id=\"example-table\"></div>\n\n</main>\n<itis-footer id=\"itisFooter\" message=\"\"></itis-footer>\n  \n</body>\n</html>\n");

  return responsebody;
}

T_DEFINE_VIEW(standardsdata_checkLfdnrCatView)

#include "standardsdata_checkLfdnrCatView.moc"
