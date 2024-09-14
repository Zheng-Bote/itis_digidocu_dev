#include <QtCore>
#include <TreeFrogView>
#include "releasemgmt.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT releasemgmt_indexView : public TActionView
{
  Q_OBJECT
public:
  releasemgmt_indexView() : TActionView() { }
  QString toString();
};

QString releasemgmt_indexView::toString()
{
  responsebody.reserve(4951);
  responsebody += QStringLiteral("<!DOCTYPE html>\n");
    responsebody += QStringLiteral("<html>\n<head>\n  <meta charset=\"UTF-8\">\n  <html lang=\"de\">\n\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QStringLiteral("</title>\n\n  <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, user-scalable=yes\">\n  <link rel=\"icon\" href=\"/favicon.ico\">\n\n  <script>\n    function doLocal()\n    {\n        console.log(\"this is local\");\n\n        let l_footer = document.getElementById(\"itisFooter\");\n        l_footer.message = '<a href=\"/stdsystem/license\" title=\"license\">Lizenzen</a>&nbsp;<a href=\"/stdsystem/imprint\" title=\"Imprint\">Impressum</a>';\n\n        //let l_menu = document.getElementById(\"itisMenu\"); \n        //l_menu.message = \"");
  responsebody += THttpUtility::htmlEscape(controller()->name());
  responsebody += QStringLiteral("\";\n    }\n\n	function setLanguage(lang)\n	{\n		if(lang == \"0\")\n		{lang = \"de\";}\n		else{lang = \"en\";}\n		document.cookie = \"lang=\" + lang + \";\" + \";path=/\";\n		location.reload();\n	}\n	\n	function open_show(id) \n	{\n		window.open(\"/releasemgmt/show/\" + id);\n	}\n\n	function open_qedit(id) \n	{\n		window.open(\"/releasemgmt/save/\" + id);\n	}\n\n	function open_edit(id) \n	{\n		window.open(\"/releasemgmt/save/\" + id);\n	}\n\n  </script>\n\n  <script type=\"module\" src=\"/js/itis_init.js\" /></script>\n  <link rel=\"stylesheet\" href=\"/css/w3.css\">  \n  <link rel=\"stylesheet\" href=\"/css/custom.css\">\n   \n</head>\n\n<body class=\"w3-container w3-margin\" id=\"body\">\n\n  <itis-menu id=\"itisMenu\" message=\"\"></itis-menu>\n\n  <div class=\"w3-container w3-light-blue\">\n    <h2 id=\"portaltitle\">ITIS-API::Admin-Portal</h2>\n  </div>\n\n  <itis-menusub id=\"itisMenuSub\" message=\"");
  responsebody += THttpUtility::htmlEscape(controller()->name());
  responsebody += QStringLiteral("\"></itis-menusub>\n\n<h3><page-title id=\"pagetitle\" message=\"\">");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QStringLiteral("</page-title></h3>\n<page-desc id=\"pagedesc\" message=\"\"></page-desc>\n\n<span style=\"color: red\">\n	<span  id=\"redmsg\">");
  techoex(red_msg);
  responsebody += QStringLiteral("</span>&nbsp;<span>");
  tehex(error);
  responsebody += QStringLiteral("</span>\n</span>\n<span style=\"color: green\">\n	<span id=\"greenmsg\">");
  techoex(green_msg);
  responsebody += QStringLiteral("</span>&nbsp;<span>");
  tehex(notice);
  responsebody += tr("</span>\n</span>\n\n<main>\n<page-content id=\"pagecontent\" message=\"\">\n<article>\n	<h4>Lifecycle und Release-Zyklen</h4>\n	<section>\n		<h5>Bausteine- und Dokumenten- Lifecycle</h5>\n		<p>Einzelne Bausteine als auch Vorgabedokumente- und Anhänge haben einen Release-Status</p>\n		<ul>\n			<li><b>draft</b><br>Bausteine im Erstellungs- und Modifizierungsprozess</li>\n			<li><b>pre-release</b><br>Bausteine im fortgeschrittenen Reifegrad werden innerhalb eines Vorgabedokumentes bzw. Anhangs auf den Status pre-released angehoben.</li>\n				<ul>\n					<li><b>pre-release review</b><br>Vorgabedokument bzw. Anhang wurde zum Review vorgelegt</li>\n				</ul>\n			<li><b>released</b><br>Vorgabedokument bzw. Anhang wurde nach der erfolgreichen Review-Abnahme und Freigabe veröffentlicht.</li>\n			<li><b>expired</b><br>das Vorgabedokument bzw. Anhang wurde aus der Veröffentlichung zurückgezogen, ggf. durch eine neuere Version abgelöst.</li>\n		</ul>\n	</section>\n	<section>\n		<h5>Release-Zyklus</h5>\n		<p>Die Abkürzung CI/CD hat unterschiedliche Bedeutungen.</p>\n		<ul>\n			<li><b>„CI“: Continuous Integration</b>\n				<br/>Build-Artefakte werden in einem versionskontrollierten Artefakt-Repository abgelegt.\n				<br>&rArr; hier: Der Automatisierungsprozess für Baustein-Admins. Bei Anhebung eines Bausteins von \"draft\" auf \"pre-release\" werden diese gegengeprüft (review) und im Repository \"released\" zusammengeführt.\n			</li>\n			<li><b>„CD“: Continuous Delivery</b>\n				<br/>Build-Artefakte oder Gesamt-Paket werden ausgeliefert.\n				<br>&rArr; hier: Das Repository \"released\" wird öffentlich zugänglich (Online-Version HTML sowie PDF download) sowie zur weiteren Verbreitung bereitgestellt.\n			</li>\n			<li><b>„CD (CDD)\": Continuous Deployment</b>\n				<br/>Optional, nicht immer erforderlich. Nach dem CD eines Gesamt-Paketes erfolgt die Installation bzw. Austausch der Produktiv-Umgebung. \n				<br>&rArr; hier: die automatische Verteilung in angeschlossene Systeme wie z.B. Group DMS (Archivierung) sowie halbautomatische Verteilung ins B2B-Partnerportal. Bei BMW derzeit nicht vorgesehen.\n			</li>\n		</ul>\n	</section>\n</article>\n</page-content>\n\n<br />\n\n</main>\n<itis-footer id=\"itisFooter\" message=\"\"></itis-footer>\n  \n</body>\n</html>\n\n");

  return responsebody;
}

T_DEFINE_VIEW(releasemgmt_indexView)

#include "releasemgmt_indexView.moc"
