#include <QtCore>
#include <TreeFrogView>
#include "itisuser.h" 
#include "itisgroups.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT account_saveView : public TActionView
{
  Q_OBJECT
public:
  account_saveView() : TActionView() { }
  QString toString();
};

QString account_saveView::toString()
{
  responsebody.reserve(7697);
  responsebody += QStringLiteral("<!DOCTYPE html>\n");
      tfetch(QVariantMap, user);
  responsebody += QStringLiteral("<html>\n<head>\n  <meta charset=\"UTF-8\">\n  <html lang=\"de\">\n\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QStringLiteral("</title>\n\n  <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, user-scalable=yes\">\n  <link rel=\"icon\" href=\"/favicon.ico\">\n\n  <script>\n    function doLocal()\n    {\n        console.log(\"this is local\");\n\n        let l_footer = document.getElementById(\"itisFooter\");\n        l_footer.message = '<a href=\"/stdsystem/license\" title=\"licenses\">Lizenzen</a>&nbsp;<a href=\"/stdsystem/imprint\" title=\"Imprint\">Impressum</a>';\n\n        //let l_menu = document.getElementById(\"itisMenu\"); \n        //l_menu.message = \"");
  responsebody += THttpUtility::htmlEscape(controller()->name());
  responsebody += QStringLiteral("\";\n    }\n\n	function setLanguage(lang)\n	{\n		if(lang == \"0\")\n		{lang = \"de\";}\n		else{lang = \"en\";}\n		document.cookie = \"lang=\" + lang + \";\" + \";path=/\";\n		location.reload();\n	}\n	\n  </script>\n\n  <script type=\"module\" src=\"/js/itis_init.js\" /></script>\n  \n  <link rel=\"stylesheet\" href=\"/css/w3.css\">  \n  <link rel=\"stylesheet\" href=\"/css/custom.css\">  \n\n</head>\n\n<body class=\"w3-container w3-margin\" id=\"body\">\n\n  <itis-menu id=\"itisMenu\" message=\"\"></itis-menu>\n\n  <div class=\"w3-container w3-light-blue\">\n    <h2 id=\"portaltitle\">ITIS-API::Admin-Portal</h2>\n  </div>\n\n  <itis-menusub id=\"itisMenuSub\" message=\"");
  responsebody += THttpUtility::htmlEscape(controller()->name());
  responsebody += QStringLiteral("\"></itis-menusub>\n\n<h3 id=\"pagetitle\"><page-title message=\"\">");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QStringLiteral("</page-title></h3>\n<div id=\"pagedesc\"><page-desc message=\"\"></page-desc></div>\n\n<p id=\"redmsg\" style=\"color: red\">");
  techoex(red_msg);
  tehex(error);
  responsebody += QStringLiteral("</p><p id=\"greenmsg\" style=\"color: green\">");
  techoex(green_msg);
  tehex(notice);
  responsebody += QStringLiteral("</p>\n\n	<span id=\"ingroups\" hidden>");
  tfetch(QList<ItisGroups>, itisGroupsList);
  responsebody += QStringLiteral("		");
  for (const auto &i : itisGroupsList) {
  responsebody += THttpUtility::htmlEscape(i.groupname());
  responsebody += QStringLiteral(",");
  };
  responsebody += QStringLiteral("	</span>\n\n<main>\n	<section>\n		<div class=\"w3-cell-row\">\n		  <div class=\"w3-container w3-cell\" onclick=\"myFunction('allgroups')\">\n			  <h4>available Groups &nbsp; <img id=\"icongrp\" src=\"/Icons/chevron-double-down.svg\"/></h4>\n			<p id=\"allgroups\" class=\"w3-hide\"></p>\n		  </div>\n		  <div class=\"w3-container w3-cell\" onclick=\"myFunction('rights')\">\n			  <h4>rights &nbsp; <img id=\"iconcrud\" src=\"/Icons/chevron-double-down.svg\"/></h4>\n			<p id=\"rights\" class=\"w3-hide\"><b>c</b>reate <b>r</b>ead <b>u</b>pdate <b>d</b>elete<br/>{crud}</p>\n		  </div>\n		</div>\n	</section>\n</main>\n\n<main>\n    \n<div id=\"pagecontent\"><page-content message=\"\"></page-content></div>	\n\n<a href=\"/account/show/");
  responsebody += THttpUtility::htmlEscape(user["id"]);
  responsebody += QStringLiteral("\" class=\"w3-btn w3-light-grey\"><img src=\"/Icons/eyeglasses.svg\">&nbsp;Anzeige</a>\n<a href=\"/account/list_all\" class=\"w3-btn w3-light-grey\">&laquo;&nbsp;zur&uuml;ck</a>\n\n");
  responsebody += QVariant(formTag(urla("save", user["id"]), Tf::Post)).toString();
  responsebody += QStringLiteral("\n  <p>\n    <label>username<br /><input class=\"w3-input\" name=\"user[username]\" value=\"");
  responsebody += THttpUtility::htmlEscape(user["username"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>firstname<br /><input class=\"w3-input\" name=\"user[firstname]\" value=\"");
  responsebody += THttpUtility::htmlEscape(user["firstname"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>surname<br /><input class=\"w3-input\" name=\"user[surname]\" value=\"");
  responsebody += THttpUtility::htmlEscape(user["surname"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>email<br /><input class=\"w3-input\" name=\"user[email]\" value=\"");
  responsebody += THttpUtility::htmlEscape(user["email"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>company<br /><input class=\"w3-input\" name=\"user[company]\" value=\"");
  responsebody += THttpUtility::htmlEscape(user["company"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>user_timezone<br /><input class=\"w3-input\" name=\"user[userTimezone]\" value=\"");
  responsebody += THttpUtility::htmlEscape(user["userTimezone"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>groupname<br /><input class=\"w3-input\" name=\"user[groupname]\" value=\"");
  responsebody += THttpUtility::htmlEscape(user["groupname"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Groups<br /><input class=\"w3-input\" name=\"user[groups]\" value=\"");
  responsebody += THttpUtility::htmlEscape(user["groups"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>password<br /><input class=\"w3-input\" name=\"user[password]\" value=\"");
  responsebody += THttpUtility::htmlEscape(user["password"]);
  responsebody += QStringLiteral("\" readonly /></label>\n  </p>\n    <p>\n    <label>force change Pwd<br /><input type=\"text\" class=\"w3-input\" name=\"user[pwdChangeForce]\" value=\"");
  responsebody += THttpUtility::htmlEscape(user["pwdChangeForce"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n    <p>\n    <label>Active<br /><input type=\"text\" class=\"w3-input\" name=\"user[active]\" value=\"");
  responsebody += THttpUtility::htmlEscape(user["active"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <input type=\"submit\" value=\"speichern &raquo;\" />\n  </p>\n</form>\n\n<br>\n\n<a href=\"/account/show/");
  responsebody += THttpUtility::htmlEscape(user["id"]);
  responsebody += QStringLiteral("\" class=\"w3-btn w3-light-grey\"><img src=\"/Icons/eyeglasses.svg\">&nbsp;Anzeige</a>\n<a href=\"/account/list_all\" class=\"w3-btn w3-light-grey\">&laquo;&nbsp;zur&uuml;ck</a>\n\n</main>\n\n<itis-footer id=\"itisFooter\" message=\"\"></itis-footer>\n\n<script>\n	const ingroups = document.getElementById('ingroups').innerHTML;\n	const allgroups = document.getElementById('allgroups');\n	let erg = ingroups.trim();\n	erg = erg.replace(/,$/, \"\");\n	allgroups.innerHTML = `{${erg}}`;\n</script>\n<script>\nfunction myFunction(id) \n{\n  const x = document.getElementById(id);\n  const icongrp = document.getElementById('icongrp');\n  const iconcrud = document.getElementById('iconcrud');\n  \n  if (x.className.indexOf(\"w3-show\") == -1) \n  {\n    x.className += \" w3-show\";\n    if(id == 'allgroups')\n    {\n		icongrp.setAttribute(\"src\", \"/Icons/chevron-double-up.svg\");\n	}\n	else if(id == 'rights')\n	{\n		iconcrud.setAttribute(\"src\", \"/Icons/chevron-double-up.svg\");\n	}\n  } \n  else \n  {\n    x.className = x.className.replace(\" w3-show\", \"\");\n    if(id == 'allgroups')\n    {\n		icongrp.setAttribute(\"src\", \"/Icons/chevron-double-down.svg\");\n	}\n	else if(id == 'rights')\n	{\n		iconcrud.setAttribute(\"src\", \"/Icons/chevron-double-down.svg\");\n	}\n  }\n}\n</script>\n\n</body>\n</html>\n\n");

  return responsebody;
}

T_DEFINE_VIEW(account_saveView)

#include "account_saveView.moc"
