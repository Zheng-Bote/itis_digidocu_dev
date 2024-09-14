#include <QtCore>
#include <TreeFrogView>
#include "releasemgmt.h" 
#include "releaseannex.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT releasemgmt_printCdAnnexView : public TActionView
{
  Q_OBJECT
public:
  releasemgmt_printCdAnnexView() : TActionView() { }
  QString toString();
};

QString releasemgmt_printCdAnnexView::toString()
{
  responsebody.reserve(12281);
  responsebody += QStringLiteral("<!DOCTYPE html>\n");
      responsebody += QStringLiteral("\n\n<html>\n<head>\n  <meta charset=\"UTF-8\">\n  <html lang=\"de\">\n\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QStringLiteral("</title>\n\n  <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, user-scalable=yes\">\n\n  <link rel=\"icon\" type=\"image/svg+xml\" href=\"/favicon.svg\">\n  <link rel=\"alternate icon\" href=\"/favicon.ico\">\n  <link rel=\"mask-icon\" href=\"/favicon.svg\" color=\"#b2b2b2\">\n  \n  <link rel=\"preload\" href=\"/fonts/Inter-Regular.woff2\" as=\"font\" type=\"font/woff2\" crossorigin />\n\n  <script>\n	  \n    function doLocal()\n    {\n        console.log(\"this is local\");\n        \n        getCategories(");
  techoex(jsonCategories);
  responsebody += QStringLiteral(");\n\n        let l_footer = document.getElementById(\"itisFooter\");\n        l_footer.message = '<a href=\"/stdsystem/license\" title=\"licenses\">Lizenzen</a>&nbsp;<a href=\"/stdsystem/imprint\" title=\"Impressum\">Imprint</a>';\n	}\n\n\n	function setLanguage(lang)\n	{\n		if(lang == \"0\")	{lang = \"de\";}\n		else {lang = \"en\";}\n		document.cookie = \"lang=\" + lang + \";\" + \";path=/\";\n		location.reload();\n	}\n	\n	function open_show(id) \n	{\n		window.open(\"/annexdata/show/\" + id);\n	}\n\n	function open_qedit(id) \n	{\n		window.open(\"/annexdata/save/\" + id);\n	}\n\n	function open_edit(id) \n	{\n		window.open(\"/annexdata/editor_upd/\" + id);\n	}	\n	\n  </script>\n\n  <script type=\"module\" src=\"/js/itis_init.js\" /></script>\n  <!-- <link rel=\"stylesheet\" href=\"/css/tbl_print.css\" media=\"all\"> -->\n  <!-- <link rel=\"stylesheet\" href=\"/css/annexRel.css\" media=\"all\">  -->\n  <!-- <link rel=\"stylesheet\" href=\"/css/w3.css\" media=\"screen\">  \n  <!-- <link rel=\"stylesheet\" href=\"/css/custom.css\" media=\"screen\"> -->\n  \n  <link rel=\"stylesheet\" href=\"/css/annexRel.css\" type=\"text/css\" media=\"ALL\" />\n \n  <script src=\"/js/annex/printcdannex.js\" /></script>\n  <script src=\"/js/glossar-data/GlossarData.js\" /></script>\n  <script src=\"/js/annex-toc/cdAnnexToc.js\" /></script>\n  <script src=\"/js/struct-data/StructData.js\" /></script>\n  <script src=\"/js/i18n.min.js\" /></script>\n\n</head>\n\n<body class=\"w3-container w3-margin\" id=\"body\">\n<div class=\"noprint\" style=\"display: none;\">\n<div class=\"noprint\">\n	\n  <itis-menu id=\"itisMenu\" message=\"\"></itis-menu>\n\n  <div class=\"w3-container w3-light-blue\">\n    <h2 id=\"portaltitle\">ITIS-API::Admin-Portal</h2>\n  </div>\n\n  <itis-menusub id=\"itisMenuSub\" message=\"");
  responsebody += THttpUtility::htmlEscape(controller()->name());
  responsebody += QStringLiteral("\"></itis-menusub>\n\n<h3 id=\"pagetitle\"><page-title message=\"\">");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QStringLiteral("</page-title></h3>\n	<div id=\"pagedesc\"><page-desc message=\"\"><p>Release Review eines Anhangs.</p></page-desc></div>\n\n<span style=\"color: red\">\n	<span  id=\"redmsg\">");
  techoex(red_msg);
  responsebody += QStringLiteral("</span>&nbsp;<span id=\"rederror\">");
  tehex(error);
  responsebody += QStringLiteral("</span>\n</span>\n<span style=\"color: green\">\n	<span id=\"greenmsg\">");
  techoex(green_msg);
  responsebody += QStringLiteral("</span>&nbsp;<span id=\"greennotice\">");
  tehex(notice);
  responsebody += QStringLiteral("</span>\n</span>\n<span id=\"prerel\" style=\"visibility: hidden\">\n	<span id=\"prelMsg\"></span>&nbsp;<span id=\"prelCount\">0</span>\n</span>\n\n<div id=\"test\" style=\"display: none;\" class=\"w3-modal\">\n    <div class=\"w3-modal-content\">\n      <div class=\"w3-container\">\n        <span onclick=\"document.getElementById('test').style.display='none'\" class=\"w3-btn w3-display-topright\">&times;</span>\n        <span id=\"msg\"></span>\n      </div>\n    </div>\n  </div>\n</div>\n\n<dialog id=\"dialog\">\n	<form>\n		Kommentar zu \"<label id=\"spec_title\"></label>&nbsp;<label id=\"spec_version\"></label>\"</br>\n		<input type=\"hidden\" id=\"spec_id\" value=\"\"/>\n		\n		<textarea id=\"user_comment\" class=\"editor\" rows=\"8\" cols=\"50\"></textarea>\n	</form>\n    <button id=\"savecomment\">speichern &raquo;</button>&nbsp;&nbsp;<button id=\"close-dialog\">abbrechen</button>\n</dialog>\n\n<main>\n<div id=\"pagecontent\"><page-content message=\"\"></page-content></div>\n\n    <form id=\"searchform\">\n        <section>\n            <div class=\"w3-cell-row\">\n                <fieldset><legend>Objekt-Attribute</legend>\n                    <div class=\"w3-container w3-cell\">\n                        <label for=\"obj_name\">Objekt:&nbsp;</label><br><input type=\"text\" name=\"obj_name\" id=\"obj_name\" value=\"");
  techoex(obj_sname);
  responsebody += QStringLiteral("\" readonly>\n                        <br>\n                    </div>\n                    <div class=\"w3-container w3-cell\">\n                        <label for=\"obj_name\">Availability Class:&nbsp;</label><br>\n                            <input type=\"text\" name=\"ac_classes\" id=\"ac_classes\" value=\"");
  techoex(ac_class);
  responsebody += QStringLiteral("\" size=\"4\" readonly>\n                        <br>\n                    </div>\n                    <div class=\"w3-container w3-cell\">\n                        <label for=\"lang\">Protection Class:&nbsp;</label><br>\n                            <input type=\"text\" name=\"pc_classes\" id=\"pc_classes\" value=\"");
  techoex(pc_class);
  responsebody += QStringLiteral("\" size=\"4\" readonly>\n                        <br>\n                    </div>\n                    <div class=\"w3-container w3-cell\">\n                       <label for=\"cat\">Kategorie:&nbsp;</label><br><select name=\"cat\" id=\"cat\" disabled=\"true\"></select>\n                        <br>\n                    </div>\n                    <div class=\"w3-container w3-cell\">\n                            <label for=\"countries\">Land:&nbsp;</label><br><input type=\"text\" id=\"countries\" name=\"countries\" value=\"");
  techoex(country);
  responsebody += QStringLiteral("\" size=\"4\" readonly>\n                        <br>\n                    </div>\n                    <div class=\"w3-container w3-cell\">\n                        <label for=\"lang\">Sprache:&nbsp;</label><br><input type=\"text\" name=\"lang\" id=\"lang\" value=\"");
  techoex(lang);
  responsebody += QStringLiteral("\" size=\"4\" readonly>\n                        <br>\n                    </div>\n                </fieldset>\n            </div>\n            <div class=\"w3-cell-row\">\n                <fieldset><legend>Release</legend>\n                    <div class=\"w3-container w3-cell\">\n                        <label for=\"releases\">Release:&nbsp;</label><br><input type=\"text\" name=\"releases\" id=\"releases\" value=\"");
  techoex(spec_release);
  responsebody += QStringLiteral("\" readonly>\n                        <br>\n                    </div>\n                    <div class=\"w3-container w3-cell\">\n                        <label for=\"release_id\">Release-ID:&nbsp;</label><br><input type=\"text\" name=\"release_id\" id=\"release_id\" value=\"");
  techoex(release_id);
  responsebody += tr("\" size=\"4\" readonly>\n                        <br>\n                    </div>\n                    <div class=\"w3-container w3-cell\">\n                        <br>\n                            <label for=\"spec_active\"><input type=\"checkbox\" name=\"spec_active\" id=\"spec_active\" disabled=\"disabled\" checked=\"checked\">&nbsp;aktive Bausteine</label>\n                        <br>\n                    </div>\n                    <div class=\"w3-container w3-cell\">\n                        <br>\n                            <label for=\"spec_complete\"><input type=\"checkbox\" name=\"spec_complete\" id=\"spec_complete\" disabled=\"disabled\" checked=\"checked\">&nbsp;komplette Vorgaben</label>\n                        <br>\n                    </div>\n                </fieldset>\n            </div>\n\n        </section>\n    </form>\n   \n    <p>\n		<input class=\"noprint w3-btn w3-light-grey\" type=\"submit\" value=\"suche &raquo;\" onClick=\"getlListAnnex()\" style=\"margin-left: 10px;\" id=\"sucheBtn\">\n		<button id=\"prelDoBtn\" style=\"visibility: hidden; margin-right: 2px;\" class=\"noprint w3-btn w3-light-grey w3-right\" onClick=\"doprelDoBtn()\"> &uarr; Release</button>\n	</p>\n</div>\n    <div class=\"printarea\">\n		<a id=\"btnprint\" style=\"margin-right: 10px;\" href=\"javascript:doPrint()\" class=\"w3-btn w3-light-grey w3-right\"><img src=\"/Icons/printer.svg\" style=\"width: 12px; height: auto;\"> &nbsp;Vorgabe drucken</a>\n		<div id=\"listErg\"></div>\n	</div>\n\n<br>\n\n</main>\n\n<dialog id=\"list_txtcomments\" style=\"border-color: grey;\">\n	<label>Kommentare zum Baustein</label></br>\n	<data-content id=\"content_list_txtcomments\"></data-content>\n    <button id=\"close_list_txtcomments\">schließen</button>\n</dialog>\n\n<script>\n	// document.getElementById(\"show-modal-dialog\").addEventListener(\"click\", () => { document.getElementById(\"dialog\").showModal(); });\n	document.getElementById(\"close-dialog\").addEventListener(\"click\", () => { document.getElementById(\"user_comment\").value = \"\"; document.getElementById(\"dialog\").close(); document.getElementById(\"greenmsg\").innerHTML = \"\";});\n	document.getElementById(\"savecomment\").addEventListener(\"click\", () => { sendComment(); });\n	document.getElementById(\"close_list_txtcomments\").addEventListener(\"click\", () => { document.getElementById(\"list_txtcomments\").close(); });\n	function doPrint()\n	{\n		document.getElementById('btnprint').style.display = 'none';  \n\n/*	\n		const D = new Date();\n		let mm = D.getMonth() + 1;\n		let dd = D.getDate();\n		const YYYY = D.getFullYear();\n		if(mm < 10)\n		{\n			mm = \"0\" + mm;\n		}\n		if(dd < 10)\n		{\n			dd = \"0\" + dd;\n		}\n		const DATESTRING = YYYY + \"-\" + mm + \"-\" + dd;\n		\n		let el = document.createElement(\"h10\");\n		el.setAttribute('class', 'divFooter');\n		el.innerHTML = DATESTRING + ': ' + translate(\"not for production\");\n		document.getElementById('listErg').appendChild(el);\n*/		\n		window.print();	\n	}\n</script>\n\n<!-- <link rel=\"stylesheet\" href=\"/css/print.css\" type=\"text/css\" media=\"print\" /> -->\n\n<!-- <itis-footer class=\"noprint\" id=\"itisFooter\" message=\"\"></itis-footer> -->\n\n</div>\n\n\n          <div class=\"page\"><div class=\"printarea\" id=\"listErg\"></div></div>\n\n<script>\n	setTimeout(() => { getlListAnnex(); }, 2000);\n	//setTimeout(() => { getlListAnnex(); setTimeout(() => { saveFile();}, 2000);}, 2000);\n	\n	//doPrintAnnex(\"");
  techoex(obj_sname);
  responsebody += QStringLiteral("\", \"");
  techoex(ac_class);
  responsebody += QStringLiteral("\", \"");
  techoex(pc_class);
  responsebody += QStringLiteral("\", \"");
  techoex(country);
  responsebody += QStringLiteral("\", \"");
  techoex(lang);
  responsebody += QStringLiteral("\", \"");
  techoex(spec_release);
  responsebody += QStringLiteral("\", \"");
  techoex(release_id);
  responsebody += QStringLiteral("\");\n	\n// setTimeout(() => { const textArea = document.getElementById(\"listErg\").innerHTML;  downloadToFile(textArea.value, './my-new-file.txt', 'text/plain');  alert(\"Done\");  }, 2000);\n\nfunction saveFile()\n{\nlet input = document.getElementById('listErg').innerHTML;\nvar text = input,\n    blob = new Blob([text], { type: 'text/plain' }),\n    anchor = document.createElement('a');\n\nanchor.download = \"hello.html\";\nanchor.href = (window.webkitURL || window.URL).createObjectURL(blob);\nanchor.dataset.downloadurl = ['text/plain', anchor.download, anchor.href].join(':');\nanchor.click();\n}\n\n</script>\n\n<script>\n	// autostart\n	const queryString = document.documentURI;\n	let str = queryString.match(/show/);\n	console.info(\"uri :\" + queryString);\n\n     if(str)\n     {\n		document.getElementById('sucheBtn').click();\n	 }\n</script>\n\n</body>\n</html>\n");

  return responsebody;
}

T_DEFINE_VIEW(releasemgmt_printCdAnnexView)

#include "releasemgmt_printCdAnnexView.moc"
