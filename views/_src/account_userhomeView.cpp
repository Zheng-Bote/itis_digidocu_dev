#include <QtCore>
#include <TreeFrogView>
#include "applicationhelper.h"

class T_VIEW_EXPORT account_userhomeView : public TActionView
{
  Q_OBJECT
public:
  account_userhomeView() : TActionView() { }
  QString toString();
};

QString account_userhomeView::toString()
{
  responsebody.reserve(9029);
  responsebody += QStringLiteral("<!DOCTYPE html>\n\n<html>\n<head>\n  <meta charset=\"UTF-8\">\n  <html lang=\"de\">\n\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QStringLiteral("</title>\n\n  <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, user-scalable=yes\">\n\n  <link rel=\"icon\" type=\"image/svg+xml\" href=\"/favicon.svg\">\n  <link rel=\"alternate icon\" href=\"/favicon.ico\">\n  <link rel=\"mask-icon\" href=\"/favicon.svg\" color=\"#b2b2b2\">\n\n  <script>\n    function doLocal()\n    {\n        console.log(\"this is local\");\n\n        let l_footer = document.getElementById(\"itisFooter\");\n        l_footer.message = '<a href=\"/stdsystem/license\" title=\"licenses\">Lizenzen</a>&nbsp;<a href=\"/stdsystem/imprint\" title=\"Impressum\">Imprint</a>';\n        \n        document.getElementById(\"lastLogin\").innerHTML = convertUTCDateToLocalDate(new Date(\"");
  techoex(lastLogin);
  responsebody += QStringLiteral("\"));\n        document.getElementById(\"lastLogout\").innerHTML = convertUTCDateToLocalDate(new Date(\"");
  techoex(lastLogout);
  responsebody += QStringLiteral("\"));\n        document.getElementById(\"lastPwdChangeTime\").innerHTML = convertUTCDateToLocalDate(new Date(\"");
  techoex(lastPwdChangeTime);
  responsebody += QStringLiteral("\"));        \n        \n        const user = {username: \"");
  techoex(username);
  responsebody += QStringLiteral("\", firstname: \"");
  techoex(firstname);
  responsebody += QStringLiteral("\", surname: \"");
  techoex(surname);
  responsebody += QStringLiteral("\", email: \"");
  techoex(email);
  responsebody += QStringLiteral("\", company: \"");
  techoex(company);
  responsebody += QStringLiteral("\", lastLogin: \"");
  techoex(lastLogin);
  responsebody += QStringLiteral("\", lastLogout: \"");
  techoex(lastLogout);
  responsebody += QStringLiteral("\", lastPwdChangeTime: \"");
  techoex(lastPwdChangeTime);
  responsebody += QStringLiteral("\", usertimezone: \"");
  techoex(usertimezone);
  responsebody += QStringLiteral("\", groupname: \"");
  techoex(groupname);
  responsebody += QStringLiteral("\", groups: \"");
  techoex(groups);
  responsebody += QStringLiteral("\", newsletter: \"");
  techoex(newsletter);
  responsebody += QStringLiteral("\"};\n        setUserData(user);\n        \n        browserCheck();\n    }\n\n	function setLanguage(lang)\n	{\n		if(lang == \"0\")\n		{lang = \"de\";}\n		else{lang = \"en\";}\n		document.cookie = \"lang=\" + lang + \";\" + \";path=/\";\n		location.reload();\n	}\n\n	function convertUTCDateToLocalDate(date) \n	{\n		//var d = convertUTCDateToLocalDate(new Date(\"2020-09-13T10:49:02.174\"));\n		var newDate = new Date(date.getTime()+date.getTimezoneOffset()*60*1000);\n\n		var offset = date.getTimezoneOffset() / 60;\n		var hours = date.getHours();\n\n		newDate.setHours(hours - offset);\n		\n		var mm = newDate.getMonth() + 1;\n		var dd = newDate.getDate();\n		var yy = newDate.getFullYear();\n		var hh = newDate.getHours();\n		var m = newDate.getMinutes();\n\n		if(mm < 10)\n		{\n			mm = \"0\" + mm;\n		}\n		if(dd < 10)\n		{\n			dd = \"0\" + dd;\n		}\n		if(hh < 10)\n		{\n			hh = \"0\" + hh;\n		}\n		if(m < 10)\n		{\n			m = \"0\" + m;\n		}\n		let datestr = yy + \"-\" + mm + \"-\" + dd + \" \" + hh + \":\" + m;\n		return datestr;\n		\n		//return newDate;   \n	}\n\n	function formatUtcDate(date)\n	{\n		var newDate = new Date(date);\n		var mm = newDate.getMonth() + 1;\n		var dd = newDate.getDate();\n		var yy = newDate.getFullYear();\n		var hh = newDate.getHours();\n		var m = newDate.getMinutes();\n\n		if(mm < 10)\n		{\n			mm = \"0\" + mm;\n		}\n		if(dd < 10)\n		{\n			dd = \"0\" + dd;\n		}\n		if(hh < 10)\n		{\n			hh = \"0\" + hh;\n		}\n		if(m < 10)\n		{\n			m = \"0\" + m;\n		}\n		let datestr = yy + \"-\" + mm + \"-\" + dd + \" \" + hh + \":\" + m;\n		return datestr;	\n	}	\n	\n	function browserCheck() \n	{\n		const BrowserName = navigator.appName;\n		const BrowserAlias = navigator.appCodeName;\n		const BrowserVersion = navigator.appVersion;\n		const BrowserAgent = navigator.userAgent;\n		//document.getElementById(\"browser\").innerHTML = `Browser: ${BrowserName} Alias: ${BrowserAlias} Agent: ${BrowserAgent} Version: ${BrowserVersion}`;\n		const browser = `${BrowserName} ${BrowserAlias} ${BrowserAgent} ${BrowserVersion}`;\n		let result = browser.match(/chrome/ig);\n		if(! result)\n		{\n			document.getElementById('redmsg').innerHTML = `<b>Es wird ein Chrome (Chromium) Browser gr&ouml;&szlig;er v36 ben&ouml;tigt.</b><br/>Sie nutzen scheinbar etwas anderes:<br/> ${browser}<br/><b>Die Funktionalit&auml;t dieser Website kann mit Ihrem Browser leider nicht gew&auml;hrleistet werden.</b>.`;\n		}\n	}\n  </script>\n\n  <script type=\"module\" src=\"/js/itis_init.js\" /></script>\n  <script src=\"/js/account/userhome.js\" /></script>\n  <link rel=\"stylesheet\" href=\"/css/w3.css\">  \n  <link rel=\"stylesheet\" href=\"/css/custom.css\">  \n\n</head>\n\n<body class=\"w3-container w3-margin\" id=\"body\">\n\n  <itis-menu id=\"itisMenu\" message=\"\"></itis-menu>\n\n  <div class=\"w3-container w3-light-blue\">\n    <h2 id=\"portaltitle\">ITIS-API::Admin-Portal</h2>\n  </div>\n\n  <itis-menusub id=\"itisMenuSub\" message=\"");
  responsebody += THttpUtility::htmlEscape(controller()->name());
  responsebody += QStringLiteral("\"></itis-menusub>\n\n<h3 id=\"pagetitle\"><page-title message=\"\">");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QStringLiteral("</page-title></h3>\n<div id=\"pagedesc\"><page-desc message=\"\"></page-desc></div>\n\n<p id=\"redmsg\" style=\"color: red\">");
  techoex(red_msg);
  tehex(error);
  responsebody += QStringLiteral("</p><p id=\"greenmsg\" style=\"color: green\">");
  techoex(green_msg);
  tehex(notice);
  responsebody += QStringLiteral("</p>\n\n<div id=\"pup\" style=\"display: none;\" class=\"w3-modal\">\n    <div class=\"w3-modal-content\">\n      <div class=\"w3-container\">\n        <span onclick=\"document.getElementById('pup').style.display='none'\" class=\"w3-button w3-display-topright\">&times;</span>\n        <span id=\"msg\"></span>\n      </div>\n    </div>\n  </div>\n</div>\n\n<main>\n	\n<article>\n	<section id =\"userSalut\">\n		<h4>Hallo <span id=\"firstname\">");
  techoex(firstname);
  responsebody += QStringLiteral("</span></h4>\n		<p>&rArr; der letzte Log-In erfolgte am <span id=\"lastLogin\"></span> Uhr <small>(<span id=\"lastLoginUtc\">");
  techoex(lastLogin);
  responsebody += QStringLiteral("</span> UTC)</small></p>\n		<p>&rArr; der letzte Log-Out erfolgte am <span id=\"lastLogout\"></span> Uhr <small>(<span id=\"lastLogoutUtc\">");
  techoex(lastLogout);
  responsebody += QStringLiteral("</span> UTC)</small></p>\n		<p>&rArr; die letzte Passwort-&Auml;nderung erfolgte am <span id=\"lastPwdChangeTime\"></span> Uhr <small>(<span id=\"lastPwdChangeTimeUtc\">");
  techoex(lastPwdChangeTime);
  responsebody += QStringLiteral("</span> UTC)</small></p>\n	<b>");
  techoex(pwdToChangeIn);
  responsebody += QStringLiteral("</b>\n		<p id=\"browser\"></p>\n	</section>\n	\n	<section id = \"userData\">\n		\n		<div class=\"w3-card-4\">\n						<div class=\"w3-container\">\n			<img src=\"/images/robot-head.svg\" alt=\"Alps\" style=\"width:20%;float:right;\">\n\n				<p>username: <span id=\"username\">");
  techoex(username);
  responsebody += QStringLiteral("</span></p>\n				<p>firstname: ");
  techoex(firstname);
  responsebody += QStringLiteral("</p>\n				<p>surname: ");
  techoex(surname);
  responsebody += QStringLiteral("</p>\n				<p>email: ");
  techoex(email);
  responsebody += QStringLiteral("</p>\n				<p>company: ");
  techoex(company);
  responsebody += QStringLiteral("</p>\n				<p>usertimezone: ");
  techoex(usertimezone);
  responsebody += QStringLiteral("</p>\n				<p>groupname: ");
  techoex(groupname);
  responsebody += QStringLiteral("</p>\n				<p>groups: ");
  techoex(groups);
  responsebody += QStringLiteral("</p>\n				<p>\n				  <p><b><u>Newsletter:</u></b></p>\n				  <input type=\"radio\" id=\"news_de\" name=\"news\" value=\"de\" onchange=\"setUserNewsletter(this, '");
  techoex(username);
  responsebody += QStringLiteral("')\">\n				  <label for=\"news_de\">deutsch</label><br>\n				  <input type=\"radio\" id=\"news_en\" name=\"news\" value=\"en\" onchange=\"setUserNewsletter(this, '");
  techoex(username);
  responsebody += QStringLiteral("')\">\n				  <label for=\"news_en\">englisch</label><br>\n				  <input type=\"radio\" id=\"news_no\" name=\"news\" value=\"no\" onchange=\"setUserNewsletter(this, '");
  techoex(username);
  responsebody += QStringLiteral("')\">\n				  <label for=\"news_no\">keinen</label>\n				</p>\n			</div>\n		</div>\n	</section>\n<div id=\"pagecontent\"><page-content message=\"\"></page-content></div>	\n</article> \n\n</main>\n<itis-footer id=\"itisFooter\" message=\"\"></itis-footer>\n  \n</body>\n</html>\n");

  return responsebody;
}

T_DEFINE_VIEW(account_userhomeView)

#include "account_userhomeView.moc"
