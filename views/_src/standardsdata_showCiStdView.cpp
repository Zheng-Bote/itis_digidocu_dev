#include <QtCore>
#include <TreeFrogView>
#include "standardsdata.h" 
#include "standardsmeta.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT standardsdata_showCiStdView : public TActionView
{
  Q_OBJECT
public:
  standardsdata_showCiStdView() : TActionView() { }
  QString toString();
};

QString standardsdata_showCiStdView::toString()
{
  responsebody.reserve(14753);
  responsebody += QStringLiteral("<!DOCTYPE html>\n");
      responsebody += QStringLiteral("\n");
  tfetch(StandardsData, standardsData);
  tfetch(StandardsMeta, standardsMeta);
  responsebody += QStringLiteral("\n<html>\n<head>\n  <meta charset=\"UTF-8\">\n  <html lang=\"de\">\n\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QStringLiteral("</title>\n\n  <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, user-scalable=yes\">\n\n  <link rel=\"icon\" type=\"image/svg+xml\" href=\"/favicon.svg\">\n  <link rel=\"alternate icon\" href=\"/favicon.ico\">\n  <link rel=\"mask-icon\" href=\"/favicon.svg\" color=\"#b2b2b2\">\n  \n  <link rel=\"preload\" href=\"/fonts/Inter-Regular.woff2\" as=\"font\" type=\"font/woff2\" crossorigin />\n\n  <script>\n	let nav = document.createElement(\"nav\");\n    let inhaltv = document.createElement(\"ol\");\n	nav.appendChild(inhaltv);\n            \n    function doLocal()\n    {\n        console.log(\"this is local\");\n\n        let l_footer = document.getElementById(\"itisFooter\");\n        l_footer.message = '<a href=\"/stdsystem/license\" title=\"licenses\">Lizenzen</a>&nbsp;<a href=\"/stdsystem/imprint\" title=\"Impressum\">Imprint</a>';\n\n		// load defaults\n        getCategories(");
  techoex(jsonCategories);
  responsebody += QStringLiteral(");\n	}\n\n	function setLanguage(lang)\n	{\n		if(lang == \"0\")	{lang = \"de\";}\n		else {lang = \"en\";}\n		document.cookie = \"lang=\" + lang + \";\" + \";path=/\";\n		location.reload();\n	}\n	\n  </script>\n\n  <script type=\"module\" src=\"/js/itis_init.js\" /></script>\n  <link rel=\"stylesheet\" href=\"/css/w3.css\" media=\"screen\">  \n  <link rel=\"stylesheet\" href=\"/css/custom.css\" media=\"screen\">  \n \n  <script src=\"/js/standards/showcistd.js\" /></script>\n  <script src=\"/js/objects-data/ObjectsData.js\" /></script>\n  <script src=\"/js/glossar-data/GlossarData.js\" /></script>\n  <script src=\"/js/standards-toc/StandardsToc.js\" /></script>\n  <script src=\"/js/struct-data/StructData.js\" /></script>\n  <script src=\"/js/i18n.min.js\" /></script>\n\n<style>\nimg {\n	max-width: 100%;\n    height: auto;\n}\n</style>\n</head>\n\n<body class=\"w3-container w3-margin\" id=\"body\">\n\n<div class=\"noprint\">\n  <itis-menu id=\"itisMenu\" message=\"\"></itis-menu>\n\n  <div class=\"w3-container w3-light-blue\">\n    <h2 id=\"portaltitle\">ITIS-API::Admin-Portal</h2>\n  </div>\n\n  <itis-menusub id=\"itisMenuSub\" message=\"");
  responsebody += THttpUtility::htmlEscape(controller()->name());
  responsebody += QStringLiteral("\"></itis-menusub>\n\n<h3 id=\"pagetitle\"><page-title message=\"\">");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QStringLiteral("</page-title></h3>\n	<div id=\"pagedesc\"><page-desc message=\"\"><p>Release Review einer Vorgabe.</p></page-desc></div>\n\n\n<span id=\"spinner\" class=\"loader\" style=\"display: none; margin: auto; color: Dodgerblue;\" align=\"center\"></span>\n\n\n<span style=\"color: red\">\n	<span  id=\"redmsg\">");
  techoex(red_msg);
  responsebody += QStringLiteral("</span>&nbsp;<span id=\"rederror\">");
  tehex(error);
  responsebody += QStringLiteral("</span>\n</span>\n<span style=\"color: green\">\n	<span id=\"greenmsg\">");
  techoex(green_msg);
  responsebody += QStringLiteral("</span>&nbsp;<span id=\"greennotice\">");
  tehex(notice);
  responsebody += QStringLiteral("</span>\n</span>\n<span id=\"prerel\" style=\"visibility: hidden\">\n	<span id=\"prelMsg\"></span>&nbsp;<span id=\"prelCount\">0</span>\n</span>\n\n<div id=\"test\" style=\"display: none;\" class=\"w3-modal\">\n    <div class=\"w3-modal-content\">\n      <div class=\"w3-container\">\n        <span onclick=\"document.getElementById('test').style.display='none'\" class=\"w3-button w3-display-topright\">&times;</span>\n        <span id=\"msg\"></span>\n      </div>\n    </div>\n  </div>\n</div>\n\n<dialog id=\"dialog\">\n	<form>\n		Kommentar zu \"<label id=\"spec_title\"></label>&nbsp;<label id=\"spec_version\"></label>\"</br>\n		<input type=\"hidden\" id=\"spec_id\" value=\"\"/>\n		\n		<textarea id=\"user_comment\" class=\"editor\" rows=\"8\" cols=\"50\"></textarea>\n	</form>\n    <button id=\"savecomment\">speichern &raquo;</button>&nbsp;&nbsp;<button id=\"close-dialog\">abbrechen</button>\n</dialog>\n\n<main>\n<div id=\"pagecontent\"><page-content message=\"\"></page-content></div>\n\n    <form id=\"searchform\">\n        <section>\n            <div class=\"w3-cell-row\">\n                <fieldset><legend>Objekt-Attribute</legend>\n                    <div class=\"w3-container w3-cell\">\n                        <label for=\"obj_name\">Objekt:&nbsp;</label><br><input type=\"text\" name=\"obj_name\" id=\"obj_name\" value=\"");
  techoex(obj_sname);
  responsebody += QStringLiteral("\" readonly>\n                        <br>\n                    </div>\n                    <div class=\"w3-container w3-cell\">\n                        <label for=\"obj_name\">AC Class:&nbsp;</label><br>\n                            <input type=\"text\" name=\"ac_classes\" id=\"ac_classes\" value=\"");
  techoex(ac_class);
  responsebody += QStringLiteral("\" size=\"4\" readonly>\n                        <br>\n                    </div>\n                    <div class=\"w3-container w3-cell\">\n                        <label for=\"lang\">PC Class:&nbsp;</label><br>\n                            <input type=\"text\" name=\"pc_classes\" id=\"pc_classes\" value=\"");
  techoex(pc_class);
  responsebody += QStringLiteral("\" size=\"4\" readonly>\n                        <br>\n                    </div>\n                    <div class=\"w3-container w3-cell\">\n                       <label for=\"cat\">Kategorie:&nbsp;</label><br><select name=\"cat\" id=\"cat\" disabled=\"true\"></select>\n                        <br>\n                    </div>\n                    <div class=\"w3-container w3-cell\">\n                            <label for=\"countries\">Land:&nbsp;</label><br><input type=\"text\" id=\"countries\" name=\"countries\" value=\"");
  techoex(country);
  responsebody += QStringLiteral("\" size=\"4\" readonly>\n                        <br>\n                    </div>\n                    <div class=\"w3-container w3-cell\">\n                        <label for=\"lang\">Sprache:&nbsp;</label><br><input type=\"text\" name=\"lang\" id=\"lang\" value=\"");
  techoex(lang);
  responsebody += QStringLiteral("\" size=\"4\" readonly>\n                        <br>\n                    </div>\n                </fieldset>\n            </div>\n            <div class=\"w3-cell-row\">\n                <fieldset><legend>Release</legend>\n                    <div class=\"w3-container w3-cell\">\n                        <label for=\"releases\">Release Status:&nbsp;</label><br><input type=\"text\" name=\"releases\" id=\"releases\" value=\"");
  techoex(spec_release);
  responsebody += QStringLiteral("\" readonly>\n                        <br>\n                    </div>\n                    <div class=\"w3-container w3-cell\">\n                        <label for=\"release_id\">Release-ID:&nbsp;</label><br><input type=\"text\" name=\"release_id\" id=\"release_id\" value=\"");
  techoex(release_id);
  responsebody += tr("\" size=\"4\" readonly>\n                        <br>\n                    </div>\n                    <div class=\"w3-container w3-cell\">\n                        <br>\n                            <label for=\"spec_active\"><input type=\"checkbox\" name=\"spec_active\" id=\"spec_active\" disabled=\"disabled\" checked=\"checked\">&nbsp;aktive Bausteine</label>\n                        <br>\n                    </div>\n                    <div class=\"w3-container w3-cell\">\n                        <br>\n                            <label for=\"spec_complete\"><input type=\"checkbox\" name=\"spec_complete\" id=\"spec_complete\" disabled=\"disabled\" checked=\"checked\">&nbsp;komplette Vorgaben</label>\n                        <br>\n                    </div>\n                </fieldset>\n            </div>\n\n        </section>\n    </form>\n   \n    <p>\n		<input class=\"noprint w3-btn w3-light-grey\" type=\"submit\" value=\"suche &raquo;\" onClick=\"getlLstStds()\" style=\"margin-left: 10px;\" id=\"sucheBtn\" >\n		<!-- <a id=\"btnpdf\" style=\"margin-right: 10px;\" href=\"javascript:writeFile()\" class=\"noprint w3-btn w3-light-grey w3-right\"><img class=\"noprint\" src=\"/Icons/pdf.svg\" style=\"width: 20px; height: auto;\"> &nbsp;Vorgabe als PDF</a> -->\n		<button id=\"btnpdf\" onClick=\"writeFile()\" style=\"margin-right: 10px;\" class=\"noprint w3-btn w3-light-grey w3-right\"><img id=\"imgpdf\" class=\"noprint\" src=\"/Icons/pdf.svg\" style=\"width: 20px; height: auto;\"> &nbsp;Vorgabe als PDF</button>\n		<a id=\"btnprint\" style=\"margin-right: 10px; display: none;\" href=\"javascript:doPrint()\" class=\"noprint w3-btn w3-light-grey w3-right\"><img class=\"noprint\" src=\"/Icons/printer.svg\"> &nbsp;Vorgabe drucken</a>\n		<button id=\"prelDoBtn\" style=\"visibility: hidden; margin-right: 2px;\" class=\"noprint w3-btn w3-light-grey w3-right\" onClick=\"doprelDoBtn()\"> &uarr; Pre-Release</button>\n	</p>\n\n</div>\n    <div class=\"printarea\" id=\"listErg\"></div>\n\n<br>\n\n</main>\n\n<dialog id=\"list_txtcomments\" style=\"border-color: grey;\">\n	<label>Kommentare zum Baustein</label></br>\n	<data-content id=\"content_list_txtcomments\"></data-content>\n    <button id=\"close_list_txtcomments\">schließen</button>\n</dialog>\n\n<script>\n	// document.getElementById(\"show-modal-dialog\").addEventListener(\"click\", () => { document.getElementById(\"dialog\").showModal(); });\n	document.getElementById(\"close-dialog\").addEventListener(\"click\", () => { document.getElementById(\"user_comment\").value = \"\"; document.getElementById(\"dialog\").close(); document.getElementById(\"greenmsg\").innerHTML = \"\";});\n	document.getElementById(\"savecomment\").addEventListener(\"click\", () => { sendComment(); });\n	document.getElementById(\"close_list_txtcomments\").addEventListener(\"click\", () => { document.getElementById(\"list_txtcomments\").close(); });\n		\n	function doPrint()\n	{\n		document.getElementById('btnprint').style.display = 'none';  \n\n/*\n		let sel = document.createElement(\"div\");\n		sel.setAttribute('class', 'divHeader');\n		sel.innerHTML = '<span><img src=\"/bmw-mini_logo.png\" alt=\"BMW Logo\"></span>';\n		document.getElementById('listErg').appendChild(sel);\n*/		\n		const D = new Date();\n		let mm = D.getMonth() + 1;\n		let dd = D.getDate();\n		const YYYY = D.getFullYear();\n		if(mm < 10)\n		{\n			mm = \"0\" + mm;\n		}\n		if(dd < 10)\n		{\n			dd = \"0\" + dd;\n		}\n		const DATESTRING = YYYY + \"-\" + mm + \"-\" + dd;\n		\n		let el = document.createElement(\"h10\");\n		el.setAttribute('class', 'divFooter');\n		el.innerHTML = DATESTRING + ': ' + translate(\"not for production\");\n		document.getElementById('listErg').appendChild(el);\n		\n		window.print();	\n	}\n	\ncounter = 5;\nfunction setCount()\n{\ncounter = counter - 1;\n	let btnpdf = document.getElementById(\"btnpdf\");\n	//btnpdf.innerHTML = \"gleich: \" + counter;\n}\n\nfunction dowriteFile()\n{\n	document.getElementById(\"spinner\").style.display = \"block\";\n	//counter = 5;\n	let btnpdf = document.getElementById(\"btnpdf\");\n	let myVar = setInterval(setCount, 1000);\n	content = document.getElementById('listErg').innerHTML;\n	setTimeout(() => {clearInterval(myVar); doWriteFile();}, 5000);\n}\n	function writeFile()\n	{\n		let content = document.getElementById('listErg').innerHTML;\nconsole.log(content.length);\n		document.getElementById(\"spinner\").style.display = \"block\";\n		document.getElementById('btnpdf').disabled = true; \n		let doctitle = document.getElementById(\"obj_name\").value;\n		let docrelease = document.getElementById(\"releases\").value;\n		let lenkinfo = document.getElementById(\"idlenkinfo\").innerText;\n				\n		document.getElementById('greenmsg').innerHTML = '';\n		document.getElementById('greennotice').innerText = '';\n		document.getElementById('redmsg').innerHTML = '';\n		document.getElementById('rederror').innerText = '';\n\n		if(docrelease == \"pre-released\")\n		{\n			docrelease = \"pre-release\";\n		}\n\n//console.log(content.length / 1000);\nlet contentSize = content.length;\n\n		data = new URLSearchParams([[\"docsize\", contentSize], [\"doctype\", \"standard\"], [\"docrelease\", docrelease], [\"doctitle\", doctitle], [\"lenkinfo\", lenkinfo], [\"doccontent\", content]]);\n			\n		//fetch(\"/releasemgmt/writeFile\",\n		fetch(\"https://itisnode.hitchhiker.tech/daten-verschickt\", \n		{\n			body: data,\n			method: \"post\"\n		})\n		.then(data => data.json())\n		.then((json) => \n		{\n		if(json.ERROR === \"0\")\n		{\n			/*console.log(\"0: \" + json.errMsg); */\n			console.log(\"0: \" + json.Msg);\n			document.getElementById('greenmsg').innerHTML = `OK: ${json.Msg}` + '. Siehe <a href=\"/releasemgmt/listAllStdCi\" alt=\"Release-Mgmt => CI Standards\">Release-Mgmt => CI Standards</a>';\n			document.getElementById('greennotice').innerText = '';\n			document.getElementById('imgpdf').style.backgroundColor = \"lightgreen\";\n			document.getElementById('btnpdf').disabled = false; \n			document.getElementById(\"spinner\").style.display = \"none\";\n		}\n		else\n		{\n			console.log(\"else: \" + json.errMsg);\n			console.log(\"else: \" + json.Msg);\n			document.getElementById('redmsg').innerHTML = 'PDF wurde nicht generiert.';\n			document.getElementById('rederror').innerText = json.errMsg + \" \" + json.Msg;\n			document.getElementById('imgpdf').style.backgroundColor = \"red\";\n			document.getElementById(\"spinner\").style.display = \"none\";\n		}\n	  })\n	  .catch((error) => { \n		  console.log(\"Fehler: \" + error + data); \n		  document.getElementById('imgpdf').style.backgroundColor = \"red\";\n		  document.getElementById(\"spinner\").style.display = \"none\";\n		});\n	//document.getElementById(\"btnpdf\").innerHTML = \"Anhang als PDF\";\n\n	}\n</script>\n\n<script src=\"/js/lenkinfo-data/LenkInfo.js\"></script>\n<script src=\"/js/annexlist-data/AnnexlistData.js\"></script>\n\n<link rel=\"stylesheet\" href=\"/css/ci_print.css\" type=\"text/css\" media=\"print\" />\n\n<script>\n	// autostart\n	const queryString = document.documentURI;\n	let str = queryString.match(/show/);\n\n     if(str)\n     {\n		setTimeout(() => { \n			document.getElementById('sucheBtn').click();\n		}, 1000);\n	 }\n</script>\n\n<itis-footer class=\"noprint\" id=\"itisFooter\" message=\"\"></itis-footer>\n  \n</body>\n</html>\n");

  return responsebody;
}

T_DEFINE_VIEW(standardsdata_showCiStdView)

#include "standardsdata_showCiStdView.moc"
