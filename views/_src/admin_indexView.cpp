#include <QtCore>
#include <TreeFrogView>
#include "applicationhelper.h"

class T_VIEW_EXPORT admin_indexView : public TActionView
{
  Q_OBJECT
public:
  admin_indexView() : TActionView() { }
  QString toString();
};

QString admin_indexView::toString()
{
  responsebody.reserve(5570);
  responsebody += QStringLiteral("<!DOCTYPE html>\n\n<html>\n<head>\n  <meta charset=\"UTF-8\">\n  <html lang=\"de\">\n\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QStringLiteral("</title>\n\n  <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, user-scalable=yes\">\n\n  <link rel=\"icon\" type=\"image/svg+xml\" href=\"/favicon.svg\">\n  <link rel=\"alternate icon\" href=\"/favicon.ico\">\n  <link rel=\"mask-icon\" href=\"/favicon.svg\" color=\"#b2b2b2\">\n\n  <script>\n    function doLocal()\n    {\n        console.log(\"this is local\");\n\n        let l_footer = document.getElementById(\"itisFooter\");\n        l_footer.message = '<a href=\"/stdsystem/license\" title=\"licenses\">Lizenzen</a>&nbsp;<a href=\"/stdsystem/imprint\" title=\"Impressum\">Imprint</a>';\n        \n        document.getElementById(\"lastLogin\").innerHTML = convertUTCDateToLocalDate(new Date(\"");
  techoex(lastLogin);
  responsebody += QStringLiteral("\"));\n        document.getElementById(\"lastLogout\").innerHTML = convertUTCDateToLocalDate(new Date(\"");
  techoex(lastLogout);
  responsebody += QStringLiteral("\"));\n        document.getElementById(\"lastPwdChangeTime\").innerHTML = convertUTCDateToLocalDate(new Date(\"");
  techoex(lastPwdChangeTime);
  responsebody += QStringLiteral("\"));\n        \n        getLastLogin(\"");
  techoex(lastLogin);
  responsebody += QStringLiteral("\");      \n        getlastLogout(\"");
  techoex(lastLogout);
  responsebody += QStringLiteral("\");\n        getlastPwdChangeTime(\"");
  techoex(lastPwdChangeTime);
  responsebody += QStringLiteral("\");  \n        \n    }\n\n	function setLanguage(lang)\n	{\n		if(lang == \"0\")\n		{lang = \"de\";}\n		else{lang = \"en\";}\n		document.cookie = \"lang=\" + lang + \";\" + \";path=/\";\n		location.reload();\n	}\n\n	function convertUTCDateToLocalDate(date) \n	{\n		//var d = convertUTCDateToLocalDate(new Date(\"2020-09-13T10:49:02.174\"));\n		var newDate = new Date(date.getTime()+date.getTimezoneOffset()*60*1000);\n\n		var offset = date.getTimezoneOffset() / 60;\n		var hours = date.getHours();\n\n		newDate.setHours(hours - offset);\n		\n		var mm = newDate.getMonth() + 1;\n		var dd = newDate.getDate();\n		var yy = newDate.getFullYear();\n		var hh = newDate.getHours();\n		var m = newDate.getMinutes();\n\n		if(mm < 10)\n		{\n			mm = \"0\" + mm;\n		}\n		if(dd < 10)\n		{\n			dd = \"0\" + dd;\n		}\n		if(hh < 10)\n		{\n			hh = \"0\" + hh;\n		}\n		if(m < 10)\n		{\n			m = \"0\" + m;\n		}\n		let datestr = yy + \"-\" + mm + \"-\" + dd + \" \" + hh + \":\" + m;\n		return datestr;\n		\n		//return newDate;   \n	}\n\n	function formatUtcDate(date)\n	{\n		var newDate = new Date(date);\n		var mm = newDate.getMonth() + 1;\n		var dd = newDate.getDate();\n		var yy = newDate.getFullYear();\n		var hh = newDate.getHours();\n		var m = newDate.getMinutes();\n\n		if(mm < 10)\n		{\n			mm = \"0\" + mm;\n		}\n		if(dd < 10)\n		{\n			dd = \"0\" + dd;\n		}\n		if(hh < 10)\n		{\n			hh = \"0\" + hh;\n		}\n		if(m < 10)\n		{\n			m = \"0\" + m;\n		}\n		let datestr = yy + \"-\" + mm + \"-\" + dd + \" \" + hh + \":\" + m;\n		return datestr;	\n	}	\n  </script>\n\n  <script type=\"module\" src=\"/js/itis_init.js\" /></script>\n  <script src=\"/js/admin.js\" /></script>\n  <link rel=\"stylesheet\" href=\"/css/w3.css\">  \n  <link rel=\"stylesheet\" href=\"/css/custom.css\">  \n\n</head>\n\n<body class=\"w3-container w3-margin\" id=\"body\">\n\n  <itis-menu id=\"itisMenu\" message=\"\"></itis-menu>\n\n  <div class=\"w3-container w3-light-blue\">\n    <h2 id=\"portaltitle\">ITIS-API::Admin-Portal</h2>\n  </div>\n\n  <itis-menusub id=\"itisMenuSub\" message=\"");
  responsebody += THttpUtility::htmlEscape(controller()->name());
  responsebody += QStringLiteral("\"></itis-menusub>\n\n<h3 id=\"pagetitle\"><page-title message=\"\">");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QStringLiteral("</page-title></h3>\n<div id=\"pagedesc\"><page-desc message=\"\"></page-desc></div>\n\n<p><img class=\"w3-yellow\" src=\"/Icons/exclamation-square.svg\">&nbsp; Admin-&Auml;nderungen &uuml;ber Formular-Eingaben werden mit Benutzername und Datum im System gespeichert.</p>\n\n<p id=\"redmsg\" style=\"color: red\">");
  techoex(red_msg);
  tehex(error);
  responsebody += QStringLiteral("</p><p id=\"greenmsg\" style=\"color: green\">");
  techoex(green_msg);
  tehex(notice);
  responsebody += QStringLiteral("</p>\n\n<main>\n	\n<article>\n	<section id =\"userSalut\">\n		<h4>Hallo <span id=\"firstname\">");
  techoex(uFname);
  responsebody += QStringLiteral("</span></h4>\n		<p>&rArr; der letzte Log-In erfolgte am <span id=\"lastLogin\"></span> Uhr <small>(<span id=\"lastLoginUtc\">");
  techoex(lastLogin);
  responsebody += QStringLiteral("</span> UTC)</small></p>\n		<p>&rArr; der letzte Log-Out erfolgte am <span id=\"lastLogout\"></span> Uhr <small>(<span id=\"lastLogoutUtc\">");
  techoex(lastLogout);
  responsebody += QStringLiteral("</span> UTC)</small></p>\n		<p>&rArr; die letzte Passwort-&Auml;nderung erfolgte am <span id=\"lastPwdChangeTime\"></span> Uhr <small>(<span id=\"lastPwdChangeTimeUtc\">");
  techoex(lastPwdChangeTime);
  responsebody += QStringLiteral("</span> UTC)</small></p>\n	</section>\n<div id=\"pagecontent\"><page-content message=\"\"></page-content></div>	\n</article> \n\n</main>\n<itis-footer id=\"itisFooter\" message=\"\"></itis-footer>\n  \n</body>\n</html>\n");

  return responsebody;
}

T_DEFINE_VIEW(admin_indexView)

#include "admin_indexView.moc"
