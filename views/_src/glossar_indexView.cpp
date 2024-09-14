#include <QtCore>
#include <TreeFrogView>
#include "glossar.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT glossar_indexView : public TActionView
{
  Q_OBJECT
public:
  glossar_indexView() : TActionView() { }
  QString toString();
};

QString glossar_indexView::toString()
{
  responsebody.reserve(4735);
  responsebody += QStringLiteral("<!DOCTYPE html>\n");
    responsebody += QStringLiteral("<html>\n<head>\n  <meta charset=\"UTF-8\">\n  <html lang=\"de\">\n\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QStringLiteral("</title>\n\n  <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, user-scalable=yes\">\n  <link rel=\"icon\" href=\"/favicon.ico\">\n\n  <script>\n    function doLocal()\n    {\n        console.log(\"this is local\");\n\n        let l_footer = document.getElementById(\"itisFooter\");\n        l_footer.message = '<a href=\"/stdsystem/license\" title=\"license\">Lizenzen</a>&nbsp;<a href=\"/stdsystem/imprint\" title=\"Imprint\">Impressum</a>';\n\n        //let l_menu = document.getElementById(\"itisMenu\"); \n        //l_menu.message = \"");
  responsebody += THttpUtility::htmlEscape(controller()->name());
  responsebody += QStringLiteral("\";\n    }\n\n	function setLanguage(lang)\n	{\n		if(lang == \"0\")\n		{lang = \"de\";}\n		else{lang = \"en\";}\n		document.cookie = \"lang=\" + lang + \";\" + \";path=/\";\n		location.reload();\n	}\n	\n	function open_show(id) \n	{\n		window.open(\"/glossar/show/\" + id);\n	}\n\n	function open_qedit(id) \n	{\n		window.open(\"/glossar/save/\" + id);\n	}\n\n	function open_edit(id) \n	{\n		window.open(\"/glossar/save/\" + id);\n	}\n\n  </script>\n\n  <script type=\"module\" src=\"/js/itis_init.js\" /></script>\n  <link rel=\"stylesheet\" href=\"/css/w3.css\">  \n  <link rel=\"stylesheet\" href=\"/css/custom.css\">\n    \n  <link href=\"/css/tabulator/tabulator.min.css\" rel=\"stylesheet\">\n  <script type=\"text/javascript\" src=\"/js/tabulator/tabulator.min.js\"></script>\n		<script src=\"/js/tabulator/tblsort.js\"></script>\n		<style>\n			table.sortable th:not(.sorttable_sorted):not(.sorttable_sorted_reverse):not(.sorttable_nosort):after { content: \" \\25B4\\25BE\" }\n			table, th, td { border: 1px solid #bbb; text-align: left; }\n			th { background-color: #ddd; }\n		</style>\n</head>\n\n<body class=\"w3-container w3-margin\" id=\"body\">\n\n  <itis-menu id=\"itisMenu\" message=\"\"></itis-menu>\n\n  <div class=\"w3-container w3-light-blue\">\n    <h2 id=\"portaltitle\">ITIS-API::Admin-Portal</h2>\n  </div>\n\n  <itis-menusub id=\"itisMenuSub\" message=\"");
  responsebody += THttpUtility::htmlEscape(controller()->name());
  responsebody += QStringLiteral("\"></itis-menusub>\n\n<h3 id=\"pagetitle\"><page-title message=\"\">");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QStringLiteral("</page-title></h3>\n<div id=\"pagedesc\"><page-desc message=\"\"></page-desc></div>\n\n<p id=\"redmsg\" style=\"color: red\">");
  techoex(red_msg);
  tehex(error);
  responsebody += QStringLiteral("</p><p id=\"greenmsg\" style=\"color: green\">");
  techoex(green_msg);
  tehex(notice);
  responsebody += QStringLiteral("</p>\n\n<main>\n<annex-data id=\"annexdata\"></annex-data>\n<article>\n    <p>Eintr&auml;ge: ");
  tehex(glossar_count);
  responsebody += QStringLiteral("</p>\n    <p>deutsch: ");
  tehex(de_terms);
  responsebody += QStringLiteral("</p>\n    <p>englisch: ");
  tehex(en_terms);
  responsebody += QStringLiteral("</p>\n</article>    \n<div id=\"pagecontent\"><page-content message=\"\"></page-content></div>	\n\n<br />\n<table class=\"w3-table-all w3-hoverable sortable\" id=\"myTable\">\n  <tr class=\"w3-text-grey\">\n    <th>Acronym</th>\n    <th>Term De</th>\n    <th>Term En</th>\n    <th>Desc De</th>\n    <th>Desc En</th>\n    <!-- <th>Sort</th> -->\n    <th>Active</th>\n  </tr>\n");
  tfetch(QList<Glossar>, glossarList);
  for (const auto &i : glossarList) {
  responsebody += QStringLiteral("  <tr>\n    <td>");
  responsebody += THttpUtility::htmlEscape(i.acronym());
  responsebody += QStringLiteral("</td>\n    <td>");
  responsebody += THttpUtility::htmlEscape(i.termDe());
  responsebody += QStringLiteral("</td>\n    <td>");
  responsebody += THttpUtility::htmlEscape(i.termEn());
  responsebody += QStringLiteral("</td>\n    <td>");
  responsebody += THttpUtility::htmlEscape(i.descDe());
  responsebody += QStringLiteral("</td>\n    <td>");
  responsebody += THttpUtility::htmlEscape(i.descEn());
  responsebody += QStringLiteral("</td>\n    <!-- <td>");
  responsebody += THttpUtility::htmlEscape(i.sort());
  responsebody += QStringLiteral("</td> -->\n    <td>");
  responsebody += THttpUtility::htmlEscape(i.active());
  responsebody += QStringLiteral("</td>\n  </tr>\n");
  };
  responsebody += QStringLiteral("</table>\n\n</main>\n\n<itis-footer id=\"itisFooter\" message=\"\"></itis-footer>\n  \n</body>\n</html>\n\n");

  return responsebody;
}

T_DEFINE_VIEW(glossar_indexView)

#include "glossar_indexView.moc"
