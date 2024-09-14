#include <QtCore>
#include <TreeFrogView>
#include "standardsdata.h" 
#include "standardsmeta.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT standardsdata_showStdElectronView : public TActionView
{
  Q_OBJECT
public:
  standardsdata_showStdElectronView() : TActionView() { }
  QString toString();
};

QString standardsdata_showStdElectronView::toString()
{
  responsebody.reserve(7996);
  responsebody += QStringLiteral("<!DOCTYPE html>\n");
      responsebody += QStringLiteral("\n");
  tfetch(StandardsData, standardsData);
  tfetch(StandardsMeta, standardsMeta);
  responsebody += QStringLiteral("\n<html>\n<head>\n  <meta charset=\"UTF-8\">\n  <html lang=\"de\">\n\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QStringLiteral("</title>\n\n  <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, user-scalable=yes\">\n\n  <link rel=\"icon\" type=\"image/svg+xml\" href=\"/favicon.svg\">\n  <link rel=\"alternate icon\" href=\"/favicon.ico\">\n  <link rel=\"mask-icon\" href=\"/favicon.svg\" color=\"#b2b2b2\">\n\n  <script>\n	let nav = document.createElement(\"nav\");\n    let inhaltv = document.createElement(\"ol\");\n	nav.appendChild(inhaltv);\n            \n    function doLocal()\n    {\n        console.log(\"this is local\");\n\n		// load defaults\n        getObjects(");
  techoex(jsonObjects);
  responsebody += QStringLiteral(");\n        getCategories(");
  techoex(jsonCategories);
  responsebody += QStringLiteral(");\n        getjsonExistCountries(");
  techoex(jsonExistCountries);
  responsebody += QStringLiteral(");\n        getLanguages(");
  techoex(jsonLanguages);
  responsebody += QStringLiteral(");\n        getReleaseTypes(");
  techoex(jsonReleaseTypes);
  responsebody += QStringLiteral(");\n        \n        document.getElementById(\"releases\").selectedIndex = \"0\";\n        document.getElementById(\"releases\").options[2].disabled = true;\n        document.getElementById(\"releases\").options[3].disabled = true;\n	}\n\n	function setLanguage(lang)\n	{\n		if(lang == \"0\")	{lang = \"de\";}\n		else {lang = \"en\";}\n		document.cookie = \"lang=\" + lang + \";\" + \";path=/\";\n		location.reload();\n	}\n	\n  </script>\n\n  <script type=\"module\" src=\"/js/itis_init.js\" /></script>\n  <link rel=\"stylesheet\" href=\"/css/w3.css\">  \n  <link rel=\"stylesheet\" href=\"/css/custom.css\">\n \n  <script src=\"/js/standards/showstdElectron.js\" /></script>\n  <script src=\"/js/glossar-data/GlossarData.js\" /></script>\n\n</head>\n\n<body class=\"w3-container w3-margin\" id=\"body\">\n\n<div class=\"noprint\">\n\n<h3 id=\"pagetitle\"><page-title message=\"\">Vorgabedokument der BMW Group</page-title></h3>\n	<div id=\"pagedesc\"><page-desc message=\"\"><p>Semi-Finale Anzeige einer Vorgabe.</p></page-desc></div>\n\n<p id=\"redmsg\" style=\"color: red\">");
  techoex(red_msg);
  tehex(error);
  responsebody += QStringLiteral("</p><p id=\"greenmsg\" style=\"color: green\">");
  techoex(green_msg);
  tehex(notice);
  responsebody += QStringLiteral("</p>\n\n<div id=\"test\" style=\"display: none;\" class=\"w3-modal\">\n    <div class=\"w3-modal-content\">\n      <div class=\"w3-container\">\n        <span onclick=\"document.getElementById('test').style.display='none'\" class=\"w3-button w3-display-topright\">&times;</span>\n        <span id=\"msg\"></span>\n      </div>\n    </div>\n  </div>\n</div>\n\n<dialog id=\"dialog\">\n	<form>\n		Kommentar zu \"<label id=\"spec_title\"></label>&nbsp;<label id=\"spec_version\"></label>\"</br>\n		<input type=\"hidden\" id=\"spec_id\" value=\"\"/>\n		\n		<textarea id=\"user_comment\" class=\"editor\" rows=\"8\" cols=\"50\"></textarea>\n	</form>\n    <button id=\"savecomment\">speichern &raquo;</button>&nbsp;&nbsp;<button id=\"close-dialog\">abbrechen</button>\n</dialog>\n\n<main>\n<div id=\"pagecontent\"><page-content message=\"\"></page-content></div>\n\n    <form id=\"searchform\">\n        <section>\n            <div class=\"w3-cell-row\">\n                <fieldset><legend>Objekt-Attribute</legend>\n                    <div class=\"w3-container w3-cell\">\n                        <label for=\"obj_name\">Objekt:&nbsp;</label><br><select name=\"obj_name\" id=\"obj_name\"><option value=\"0\" selected>Objekt-Auswahl</option></select>\n                        <br>\n                    </div>\n                    <div class=\"w3-container w3-cell\">\n                        <label for=\"obj_name\">Availability Class:&nbsp;</label><br>\n                            <select name=\"ac_classes\" id=\"ac_classes\"></select>\n                        <br>\n                    </div>\n                    <div class=\"w3-container w3-cell\">\n                        <label for=\"lang\">Protection Class:&nbsp;</label><br>\n                            <select name=\"pc_classes\" id=\"pc_classes\"></select>\n                        <br>\n                    </div>\n                    <div class=\"w3-container w3-cell\">\n                        <label for=\"cat\">Kategorie:&nbsp;</label><br><select name=\"cat\" id=\"cat\"></select>\n                        <br>\n                    </div>\n                    <div class=\"w3-container w3-cell\">\n                        <span class=\"w3-tooltip\">\n                            <label for=\"countries\">Land:&nbsp;</label><br><select id=\"countries\" name=\"countries\"></select>\n                        <span style=\"position:absolute;left:0;bottom:18px\" class=\"w3-text w3-tag\">WW = World Wide</span>\n                        <br>\n                    </div>\n                    <div class=\"w3-container w3-cell\">\n                        <label for=\"lang\">Sprache:&nbsp;</label><br><select name=\"lang\" id=\"lang\"></select>\n                        <br>\n                    </div>\n                </fieldset>\n            </div>\n            <div class=\"w3-cell-row\">\n                <fieldset><legend>Release</legend>\n                    <div class=\"w3-container w3-cell\">\n                        <label for=\"releases\">Release:&nbsp;</label><br><select name=\"releases\" id=\"releases\"></select>\n                        <br>\n                    </div>\n                    <div class=\"w3-container w3-cell\">\n                        <br>\n                        <span class=\"w3-tooltip\">\n                            <label for=\"spec_active\"><input type=\"checkbox\" name=\"spec_active\" id=\"spec_active\" checked />&nbsp;aktive Bausteine</label>\n                        <span style=\"position:absolute;left:0;bottom:18px\" class=\"w3-text w3-tag\">nur de-/aktive Bausteine</span>\n                        <br>\n                    </div>\n                    <div class=\"w3-container w3-cell\">\n                        <br>\n                        <span class=\"w3-tooltip\">\n                            <label for=\"spec_complete\"><input type=\"checkbox\" name=\"spec_complete\" id=\"spec_complete\">&nbsp;komplette Vorgaben</label>\n                        <span style=\"position:absolute;left:0;bottom:18px\" class=\"w3-text w3-tag\">alle Objekt-spezifische Bausteine</span>\n                        <br>\n                    </div>\n                </fieldset>\n            </div>\n\n        </section>\n    </form>\n   \n    <p>\n		<input class=\"noprint\" type=\"submit\" value=\"suche &raquo;\" onClick=\"getlLstStds()\" style=\"margin-left: 10px;\">\n		<a id=\"btnprint\" style=\"margin-right: 10px; display: none;\" href=\"javascript:window.print()\" class=\"w3-btn w3-light-grey w3-right noprint\"><img src=\"/Icons/printer.svg\"> &nbsp;Vorgabe drucken</a>\n	</p>\n\n</div>\n    <div class=\"printarea\" id=\"listErg\"></div>\n\n<br>\n\n</main>\n\n<script>\n	// document.getElementById(\"show-modal-dialog\").addEventListener(\"click\", () => { document.getElementById(\"dialog\").showModal(); });\n	document.getElementById(\"close-dialog\").addEventListener(\"click\", () => { document.getElementById(\"user_comment\").value = \"\"; document.getElementById(\"dialog\").close(); document.getElementById(\"greenmsg\").innerHTML = \"\";});\n	document.getElementById(\"savecomment\").addEventListener(\"click\", () => { sendComment(); });\n</script>\n<link rel=\"stylesheet\" href=\"/css/print.css\" type=\"text/css\" media=\"print\" />\n  \n</body>\n</html>\n");

  return responsebody;
}

T_DEFINE_VIEW(standardsdata_showStdElectronView)

#include "standardsdata_showStdElectronView.moc"
