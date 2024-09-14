#include <QtCore>
#include <TreeFrogView>
#include "applicationhelper.h"

class T_VIEW_EXPORT admin_showGalleryView : public TActionView
{
  Q_OBJECT
public:
  admin_showGalleryView() : TActionView() { }
  QString toString();
};

QString admin_showGalleryView::toString()
{
  responsebody.reserve(7134);
  responsebody += QStringLiteral("<!DOCTYPE html>\n\n<html>\n<head>\n  <meta charset=\"UTF-8\">\n  <html lang=\"de\">\n\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QStringLiteral("</title>\n\n  <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, user-scalable=yes\">\n\n  <link rel=\"icon\" type=\"image/svg+xml\" href=\"/favicon.svg\">\n  <link rel=\"alternate icon\" href=\"/favicon.ico\">\n  <link rel=\"mask-icon\" href=\"/favicon.svg\" color=\"#b2b2b2\">\n\n  <script>\n    function doLocal()\n    {\n        console.log(\"this is local\");\n\n        let l_footer = document.getElementById(\"itisFooter\");\n        l_footer.message = '<a href=\"/stdsystem/license\" title=\"licenses\">Lizenzen</a>&nbsp;<a href=\"/stdsystem/imprint\" title=\"Impressum\">Imprint</a>';\n        \n        setGalleryImgs(");
  techoex(jsonArray);
  responsebody += tr(");  \n    }\n\n	function setLanguage(lang)\n	{\n		if(lang == \"0\")\n		{lang = \"de\";}\n		else{lang = \"en\";}\n		document.cookie = \"lang=\" + lang + \";\" + \";path=/\";\n		location.reload();\n	}\n\n	function setGalleryImgs(Obj)\n	{\n		let imgPlace = document.getElementById('Images');\n		let ulcont = document.createElement('ul');\n		ulcont.setAttribute('class', 'card-wrapper');\n		\n		let counter = 0;\n		\n        for (i in Obj) \n        {\n			let id = \"img_\" + counter;\n			let idclip = \"img_\" + counter + \"_clip\";\n			let i_li = document.createElement('li');\n			i_li.setAttribute('class', 'card');\n			i_li.innerHTML = `<img id=\"${id}\" class=\"imggal\" src=\"${Obj[i].img}\" alt=\"URI: <mark>${Obj[i].img}</mark>\" onClick=\"showPic(${id})\" loading=\"lazy\" decoding=\"async\"><h3>${Obj[i].name}</h3><p><small>Bild-Grö&szlig;e: ${Obj[i].size}kB</small><br><input class=\"w3-input\" type=\"text\" value=\"${Obj[i].img}\" id=\"${idclip}\"><br><button onclick=\"copyUri(${idclip})\">Copy URI</button></p>`;\n			ulcont.appendChild(i_li);\n			counter++;\n		}\n		imgPlace.appendChild(ulcont);		\n	}\n  </script>\n\n  <link rel=\"stylesheet\" href=\"/css/w3.css\">  \n  <link rel=\"stylesheet\" href=\"/css/custom.css\">  \n\n  <script type=\"module\" src=\"/js/itis_init.js\" /></script>\n\n	<style>\n   .card {\n      background-color: #fff;\n      border-radius: 0.5rem;\n      box-shadow: 0.05rem 0.1rem 0.3rem -0.03rem rgba(0, 0, 0, 0.45);\n      padding-bottom: 1rem;\n    }\n\n    .card > :last-child {\n      margin-bottom: 0;\n    }\n\n    .card h3 {\n      margin-top: 1rem;\n      font-size: 1.25rem;\n    }\n\n    img.imggal {\n      border-radius: 0.5rem 0.5rem 0 0;\n      max-width: 100%;\n      height: auto;\n      \n        display: block;\n		margin-left: auto;\n		margin-right: auto;\n		padding-top: 1rem;\n    }\n\n    img.imggal ~ * {\n      margin-left: 1rem;\n      margin-right: 1rem;\n    }\n\n    .card-wrapper {\n    list-style: none;\n    padding: 0;\n    margin: 0;\n    display: grid;\n    grid-template-columns: repeat(auto-fit, minmax(30ch, 1fr));\n    grid-gap: 1.5rem;\n  }\n \n /* ### */\n .modal {\n  display: none; /* Hidden by default */\n  position: fixed; /* Stay in place */\n  z-index: 1; /* Sit on top */\n  padding-top: 100px; /* Location of the box */\n  left: 0;\n  top: 0;\n  width: 100%; /* Full width */\n  height: 100%; /* Full height */\n  overflow: auto; /* Enable scroll if needed */\n  \n  background-color: rgb(0,0,0); /* Fallback color */\n  background-color: rgba(0,0,0,0.9); /* Black w/ opacity */\n}\n\n/* Modal Content (image) */\n.modal-content {\n  margin: auto;\n  display: block;\n  \n  /* width: 80%;\n  max-width: 700px; */\n  max-width: 100%;\n}\n\n/* Caption of Modal Image */\n#caption {\n  margin: auto;\n  display: block;\n  width: 80%;\n  max-width: 700px;\n  text-align: center;\n  color: #ccc;\n  padding: 10px 0;\n  height: 150px;\n}\n\n/* Add Animation */\n.modal-content, #caption {  \n  -webkit-animation-name: zoom;\n  -webkit-animation-duration: 0.6s;\n  animation-name: zoom;\n  animation-duration: 0.6s;\n}\n\n@-webkit-keyframes zoom {\n  from {-webkit-transform:scale(0)} \n  to {-webkit-transform:scale(1)}\n}\n\n@keyframes zoom {\n  from {transform:scale(0)} \n  to {transform:scale(1)}\n}\n\n/* The Close Button */\n.close {\n  position: absolute;\n  top: 15px;\n  right: 35px;\n  color: #f1f1f1;\n  font-size: 40px;\n  font-weight: bold;\n  transition: 0.3s;\n}\n\n.close:hover,\n.close:focus {\n  color: #bbb;\n  text-decoration: none;\n  cursor: pointer;\n}\n\n/* 100% Image Width on Smaller Screens */\n@media only screen and (max-width: 700px){\n  .modal-content {\n    width: 100%;\n  }\n} \n	</style> \n</head>\n\n<body class=\"w3-container w3-margin\" id=\"body\">\n\n  <itis-menu id=\"itisMenu\" message=\"\"></itis-menu>\n\n  <div class=\"w3-container w3-light-blue\">\n    <h2 id=\"portaltitle\">ITIS-API::Admin-Portal</h2>\n  </div>\n\n  <itis-menusub id=\"itisMenuSub\" message=\"");
  responsebody += THttpUtility::htmlEscape(controller()->name());
  responsebody += QStringLiteral("\"></itis-menusub>\n\n<h3 id=\"pagetitle\"><page-title message=\"\">");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += tr("</page-title></h3>\n	<div id=\"pagedesc\"><page-desc message=\"\"><p>Alle Bilder und Photos der Vorgaben und Anhänge.</p><p>&rArr; Bild anklicken für Ansicht in Originalgröße,<br>&rArr; Button anklicken um die URL des Bildes in den Zwischenspeicher zu laden (um z.B. im Baustein-Editor über Bild-URL mittels STRG+V einzufügen).</p></page-desc></div>\n\n<p style=\"color: red\"><span  id=\"redmsg\">");
  techoex(red_msg);
  responsebody += QStringLiteral("</span> ");
  tehex(error);
  responsebody += QStringLiteral("</p><p style=\"color: green\"><span id=\"greenmsg\">");
  techoex(green_msg);
  responsebody += QStringLiteral("</span> ");
  tehex(notice);
  responsebody += tr("</p>\n\n<main>\n	<div id=\"pagecontent\"><page-content message=\"\"></page-content></div>\n\n	<article>\n\n			<div id=\"Images\"></div>\n\n	</article> \n\n<!-- The Modal -->\n<div id=\"myModal\" class=\"modal\">\n  <span class=\"close\">&times;</span>\n  <img class=\"modal-content\" id=\"img01\">\n  <div id=\"caption\"></div>\n</div>\n\n<script>\n	function showPic(id)\n	{\n		var modal = document.getElementById(\"myModal\");\n		var img = document.getElementById(id);\n		var modalImg = document.getElementById(\"img01\");\n		var captionText = document.getElementById(\"caption\");\n\n		modal.style.display = \"block\";\n		modalImg.src = id.src;\n		captionText.innerHTML = id.alt;\n\n		var span = document.getElementsByClassName(\"close\")[0];\n		span.onclick = function() { \n		  modal.style.display = \"none\";\n		}\n	}\n	\n	function copyUri(id)\n	{\n		console.log(\"id: \" + id);\n		id.select();\n		id.setSelectionRange(0, 99999); /* For mobile devices */\n		document.execCommand(\"copy\");\n\n		alert(\"das Bild kann nun per STRG+V eingefügt werden:\\n \" + id.value);\n	}\n</script>\n\n\n</main>\n<itis-footer id=\"itisFooter\" message=\"\"></itis-footer>\n  \n</body>\n</html>\n");

  return responsebody;
}

T_DEFINE_VIEW(admin_showGalleryView)

#include "admin_showGalleryView.moc"
