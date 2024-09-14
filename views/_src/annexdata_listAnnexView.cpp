#include <QtCore>
#include <TreeFrogView>
#include "standardsdata.h" 
#include "standardsmeta.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT annexdata_listAnnexView : public TActionView
{
  Q_OBJECT
public:
  annexdata_listAnnexView() : TActionView() { }
  QString toString();
};

QString annexdata_listAnnexView::toString()
{
  responsebody.reserve(7241);
  responsebody += QStringLiteral("<!DOCTYPE html>\n");
      tfetch(StandardsData, standardsData);
  tfetch(StandardsMeta, standardsMeta);
  responsebody += QStringLiteral("<html>\n<head>\n  <meta charset=\"UTF-8\">\n  <html lang=\"de\">\n\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QStringLiteral("</title>\n\n  <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, user-scalable=yes\">\n\n  <link rel=\"icon\" type=\"image/svg+xml\" href=\"/favicon.svg\">\n  <link rel=\"alternate icon\" href=\"/favicon.ico\">\n  <link rel=\"mask-icon\" href=\"/favicon.svg\" color=\"#b2b2b2\">\n\n  <script>\n    function doLocal()\n    {\n        console.log(\"this is local\");\n\n        let l_footer = document.getElementById(\"itisFooter\");\n        l_footer.message = '<a href=\"/stdsystem/license\" title=\"licenses\">Lizenzen</a>&nbsp;<a href=\"/stdsystem/imprint\" title=\"Impressum\">Imprint</a>';\n\n		// load defaults\n        getObjects(");
  techoex(jsonObjects);
  responsebody += QStringLiteral(");\n        getCategories(");
  techoex(jsonCategories);
  responsebody += QStringLiteral(");\n        getjsonExistCountries(");
  techoex(jsonExistCountries);
  responsebody += QStringLiteral(");\n        getLanguages(");
  techoex(jsonLanguages);
  responsebody += QStringLiteral(");\n        getReleaseTypes(");
  techoex(jsonReleaseTypes);
  responsebody += QStringLiteral(");\n        \n        document.getElementById(\"releases\").selectedIndex = \"0\";\n        document.getElementById(\"releases\").options[2].disabled = true;\n        document.getElementById(\"releases\").options[3].disabled = true;\n	}\n\n	function setLanguage(lang)\n	{\n		if(lang == \"0\")	{lang = \"de\";}\n		else {lang = \"en\";}\n		document.cookie = \"lang=\" + lang + \";\" + \";path=/\";\n		location.reload();\n	}\n	\n  </script>\n\n  <script type=\"module\" src=\"/js/itis_init.js\" /></script>\n  <link rel=\"stylesheet\" href=\"/css/w3.css\">  \n  <link rel=\"stylesheet\" href=\"/css/custom.css\">\n \n  <script src=\"/js/annex/listannex.js\" /></script>\n\n</head>\n\n<body class=\"w3-container w3-margin\" id=\"body\">\n\n  <itis-menu id=\"itisMenu\" message=\"\"></itis-menu>\n\n  <div class=\"w3-container w3-light-blue\">\n    <h2 id=\"portaltitle\">ITIS-API::Admin-Portal</h2>\n  </div>\n\n  <itis-menusub id=\"itisMenuSub\" message=\"");
  responsebody += THttpUtility::htmlEscape(controller()->name());
  responsebody += QStringLiteral("\"></itis-menusub>\n\n<h3 id=\"pagetitle\"><page-title message=\"\">");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QStringLiteral("</page-title></h3>\n	<div id=\"pagedesc\"><page-desc message=\"\"><p>Auflistung <b>aller</b> Bausteine eines Anhangs, <b>ohne</b> Filterung.</p></page-desc></div>\n\n<p id=\"redmsg\" style=\"color: red\">");
  techoex(red_msg);
  tehex(error);
  responsebody += QStringLiteral("</p><p id=\"greenmsg\" style=\"color: green\">");
  techoex(green_msg);
  tehex(notice);
  responsebody += QStringLiteral("</p>\n\n<div id=\"test\" style=\"display: none;\" class=\"w3-modal\">\n    <div class=\"w3-modal-content\">\n      <div class=\"w3-container\">\n        <span onclick=\"document.getElementById('test').style.display='none'\" class=\"w3-button w3-display-topright\">&times;</span>\n        <span id=\"msg\"></span>\n      </div>\n    </div>\n  </div>\n</div>\n\n\n<main>\n<div id=\"pagecontent\"><page-content message=\"\"></page-content></div>\n\n    <form id=\"searchform\">\n        <section>\n            <div class=\"w3-cell-row\">\n                <fieldset><legend>Objekt-Attribute</legend>\n                    <div class=\"w3-container w3-cell\">\n                        <label for=\"obj_name\">Objekt:&nbsp;</label><br><select name=\"obj_name\" id=\"obj_name\"><option value=\"0\" selected>Objekt-Auswahl</option></select>\n                        <br>\n                    </div>\n                    <div class=\"w3-container w3-cell\">\n                        <label for=\"obj_name\">Availability Class:&nbsp;</label><br>\n                            <select name=\"ac_classes\" id=\"ac_classes\"></select>\n                        <br>\n                    </div>\n                    <div class=\"w3-container w3-cell\">\n                        <label for=\"lang\">Protection Class:&nbsp;</label><br>\n                            <select name=\"pc_classes\" id=\"pc_classes\"></select>\n                        <br>\n                    </div>\n                    <div class=\"w3-container w3-cell\">\n                        <label for=\"cat\">Kategorie:&nbsp;</label><br><select name=\"cat\" id=\"cat\"></select>\n                        <br>\n                    </div>\n                    <div class=\"w3-container w3-cell\">\n                        <span class=\"w3-tooltip\">\n                            <label for=\"countries\">Land:&nbsp;</label><br><select id=\"countries\" name=\"countries\"></select>\n                        <span style=\"position:absolute;left:0;bottom:18px\" class=\"w3-text w3-tag\">WW = World Wide</span>\n                        <br>\n                    </div>\n                    <div class=\"w3-container w3-cell\">\n                        <label for=\"lang\">Sprache:&nbsp;</label><br><select name=\"lang\" id=\"lang\"></select>\n                        <br>\n                    </div>\n                </fieldset>\n            </div>\n            <div class=\"w3-cell-row\">\n                <fieldset><legend>Release</legend>\n                    <div class=\"w3-container w3-cell\">\n                        <label for=\"releases\">Release:&nbsp;</label><br><select name=\"releases\" id=\"releases\"></select>\n                        <br>\n                    </div>\n                    <div class=\"w3-container w3-cell\">\n                        <br>\n                        <span class=\"w3-tooltip\">\n                            <label for=\"spec_active\"><input type=\"checkbox\" name=\"spec_active\" id=\"spec_active\" checked />&nbsp;aktive Bausteine</label>\n                        <span style=\"position:absolute;left:0;bottom:18px\" class=\"w3-text w3-tag\">nur de-/aktive Bausteine</span>\n                        <br>\n                    </div>\n                    <div class=\"w3-container w3-cell\">\n                        <br>\n                        <span class=\"w3-tooltip\">\n                            <label for=\"spec_complete\"><input type=\"checkbox\" name=\"spec_complete\" id=\"spec_complete\">&nbsp;komplette Vorgaben</label>\n                        <span style=\"position:absolute;left:0;bottom:18px\" class=\"w3-text w3-tag\">alle Objekt-spezifische Bausteine</span>\n                        <br>\n                    </div>\n                </fieldset>\n            </div>\n\n        </section>\n    </form>\n   \n    <p><input type=\"submit\" value=\"suche &raquo;\" onClick=\"getlListAnnex()\" style=\"margin-left: 10px;\"></p>\n    \n    <div id=\"listErg\"></div>\n\n<br>\n\n</main>\n\n<itis-footer id=\"itisFooter\" message=\"\"></itis-footer>\n  \n</body>\n</html>\n");

  return responsebody;
}

T_DEFINE_VIEW(annexdata_listAnnexView)

#include "annexdata_listAnnexView.moc"
