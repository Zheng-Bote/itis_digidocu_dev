#include <QtCore>
#include <TreeFrogView>
#include "lenkinfo.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT lenkinfo_showView : public TActionView
{
  Q_OBJECT
public:
  lenkinfo_showView() : TActionView() { }
  QString toString();
};

QString lenkinfo_showView::toString()
{
  responsebody.reserve(11277);
  responsebody += QStringLiteral("<!DOCTYPE html>\n");
    tfetch(Lenkinfo, lenkinfo);
  responsebody += QStringLiteral("<html>\n<head>\n  <meta charset=\"UTF-8\">\n  <html lang=\"de\">\n\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QStringLiteral("</title>\n\n  <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, user-scalable=yes\">\n  <link rel=\"icon\" href=\"/favicon.ico\">\n  \n  <link rel=\"preload\" href=\"/fonts/Inter-Regular.woff2\" as=\"font\" type=\"font/woff2\" crossorigin />\n\n  <script>\n    function doLocal()\n    {\n        console.log(\"this is local\");\n\n        let l_footer = document.getElementById(\"itisFooter\");\n        l_footer.message = '<a href=\"/stdsystem/license\" title=\"licenses\">Lizenzen</a>&nbsp;<a href=\"/stdsystem/imprint\" title=\"Imprint\">Impressum</a>';\n\n        //let l_menu = document.getElementById(\"itisMenu\"); \n        //l_menu.message = \"");
  responsebody += THttpUtility::htmlEscape(controller()->name());
  responsebody += QStringLiteral("\";\n    }\n\n	function setLanguage(lang)\n	{\n		if(lang == \"0\")\n		{lang = \"de\";}\n		else{lang = \"en\";}\n		document.cookie = \"lang=\" + lang + \";\" + \";path=/\";\n		location.reload();\n	}\n\n	function convertUTCDateToLocalDate(id, datetime) \n	{\n		if(! datetime)\n		{\n			return;\n		}\n		//var date = new Date(datetime);\n		var newDate = new Date(datetime);\n		\n		/* var newDate = new Date(date.getTime()+date.getTimezoneOffset()*60*1000);\n\n		var offset = date.getTimezoneOffset() / 60;\n		var hours = date.getHours();\n\n		newDate.setHours(hours - offset);\n		*/\n		var mm = newDate.getMonth() + 1;\n		var dd = newDate.getDate();\n		var yy = newDate.getFullYear();\n		var hh = newDate.getHours();\n		var m = newDate.getMinutes();\n\n		if(mm < 10)\n		{\n			mm = \"0\" + mm;\n		}\n		if(dd < 10)\n		{\n			dd = \"0\" + dd;\n		}\n\n		let datestr = yy + \"-\" + mm + \"-\" + dd;\n		\n		if(id) {\n			document.getElementById(id).value = datestr;\n		}\n		else {\n			return datestr;\n		}   \n	}	\n  </script>\n\n  <script type=\"module\" src=\"/js/itis_init.js\" /></script>\n  \n  <link rel=\"stylesheet\" href=\"/css/w3.css\">  \n  <link rel=\"stylesheet\" href=\"/css/custom.css\">  \n\n<style>\n	.set-width { width: 250px;	border-radius: 5px;}\n	.w3-half, .w3-third { margin-bottom: 1rem; }\n	</style>\n\n</head>\n\n<body class=\"w3-container w3-margin\" id=\"body\">\n\n  <itis-menu id=\"itisMenu\" message=\"\"></itis-menu>\n\n  <div class=\"w3-container w3-light-blue\">\n    <h2 id=\"portaltitle\">ITIS-API::Admin-Portal</h2>\n  </div>\n\n  <itis-menusub id=\"itisMenuSub\" message=\"");
  responsebody += THttpUtility::htmlEscape(controller()->name());
  responsebody += QStringLiteral("\"></itis-menusub>\n\n<h3 id=\"pagetitle\"><page-title message=\"\">");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QStringLiteral("</page-title></h3>\n<div id=\"pagedesc\"><page-desc message=\"\"></page-desc></div>\n\n<span style=\"color: red;\">\n	<span  id=\"redmsg\">");
  techoex(red_msg);
  responsebody += QStringLiteral("</span>&nbsp;<span>");
  tehex(error);
  responsebody += QStringLiteral("</span>\n</span>\n<span style=\"color: green;\">\n	<span id=\"greenmsg\">");
  techoex(green_msg);
  responsebody += QStringLiteral("</span>&nbsp;<span>");
  tehex(notice);
  responsebody += QStringLiteral("</span>\n</span>\n\n<main>\n    \n<div id=\"pagecontent\"><page-content message=\"\"></page-content></div>	\n\n<span class=\"w3-btn w3-red w3-wide\" style=\"border-radius: 0.5em 0px 0px 0px;\"><img src=\"/Icons/trash.svg\">&nbsp;");
  responsebody += QVariant(linkTo("Remove", urla("remove", lenkinfo.id()), Tf::Post, "confirm('Are you sure?')")).toString();
  responsebody += QStringLiteral("</span>\n&nbsp;&nbsp;&nbsp;\n<a href=\"/lenkinfo/save/");
  responsebody += THttpUtility::htmlEscape(lenkinfo.id());
  responsebody += QStringLiteral("\" class=\"w3-btn w3-light-grey\"><img src=\"/Icons/pencil.svg\">&nbsp;Q-Edit</a>\n<a href=\"/lenkinfo/list_all\" class=\"w3-btn w3-light-grey\"><img src=\"/Icons/justify.svg\">&nbsp;zur&uuml;ck</a>\n<br>\n\n<section>\n<div class=\"w3-row-padding\">\n	<p>\n    <label class=\"w3-opacity\">ID<br /><input type=\"text\" class=\"w3-input w3-border w3-round set-width\" name=\"\" value=\"");
  responsebody += THttpUtility::htmlEscape(lenkinfo.id());
  responsebody += QStringLiteral("\" readonly /></label>\n	</p>\n  \n  <div class=\"w3-half\">\n    <label class=\"w3-opacity\">Spec Obj<br /><input type=\"text\" class=\"w3-input w3-border w3-round\" name=\"appVars[id]\" value=\"");
  responsebody += THttpUtility::htmlEscape(lenkinfo.specObj());
  responsebody += QStringLiteral("\" readonly /></label>\n  </div>\n  <div class=\"w3-half\">\n    <label class=\"w3-opacity\">Spec Title<br /><input type=\"text\" class=\"w3-input w3-border w3-round\" name=\"appVars[id]\" value=\"");
  responsebody += THttpUtility::htmlEscape(lenkinfo.specTitle());
  responsebody += QStringLiteral("\" readonly /></label>\n  </div>\n  <div class=\"w3-half\">\n    <label class=\"w3-opacity\">Ac Class<br /><input type=\"text\" class=\"w3-input w3-border w3-round\" name=\"appVars[id]\" value=\"");
  responsebody += THttpUtility::htmlEscape(lenkinfo.acClass());
  responsebody += QStringLiteral("\" readonly /></label>\n  </div>\n  <div class=\"w3-half\">\n    <label class=\"w3-opacity\">Pc Class<br /><input type=\"text\" class=\"w3-input w3-border w3-round\" name=\"appVars[id]\" value=\"");
  responsebody += THttpUtility::htmlEscape(lenkinfo.pcClass());
  responsebody += QStringLiteral("\" readonly /></label>\n  </div>\n  <div class=\"w3-half\">\n    <label class=\"w3-opacity\">Country<br /><input type=\"text\" class=\"w3-input w3-border w3-round\" name=\"appVars[id]\" value=\"");
  responsebody += THttpUtility::htmlEscape(lenkinfo.country());
  responsebody += QStringLiteral("\" readonly /></label>\n  </div>\n  <div class=\"w3-half\">\n    <label class=\"w3-opacity\">Lang<br /><input type=\"text\" class=\"w3-input w3-border w3-round\" name=\"appVars[id]\" value=\"");
  responsebody += THttpUtility::htmlEscape(lenkinfo.lang());
  responsebody += QStringLiteral("\" readonly /></label>\n  </div>\n  <div class=\"w3-half\">\n    <label class=\"w3-opacity\">Lenk Version<br /><input type=\"text\" class=\"w3-input w3-border w3-round\" name=\"appVars[id]\" value=\"");
  responsebody += THttpUtility::htmlEscape(lenkinfo.lenkVersion());
  responsebody += QStringLiteral("\" readonly /></label>\n  </div>\n  <div class=\"w3-half\">\n    <label class=\"w3-opacity\">Lenk Status<br /><input type=\"text\" class=\"w3-input w3-border w3-round\" name=\"appVars[id]\" value=\"");
  responsebody += THttpUtility::htmlEscape(lenkinfo.lenkStatus());
  responsebody += QStringLiteral("\" readonly /></label>\n  </div>\n  <div class=\"w3-half\">\n    <label class=\"w3-opacity\">Lenk Valid Startdate<br /><input type=\"text\" class=\"w3-input w3-border w3-round\" name=\"appVars[id]\" id=\"lenkValidStartdate\" value=\"");
  responsebody += THttpUtility::htmlEscape(lenkinfo.lenkValidStartdate());
  responsebody += QStringLiteral("\" readonly /></label>\n  </div>\n  <div class=\"w3-half\">\n    <label class=\"w3-opacity\">Lenk Departments<br /><input type=\"text\" class=\"w3-input w3-border w3-round\" name=\"appVars[id]\" value=\"");
  responsebody += THttpUtility::htmlEscape(lenkinfo.lenkDepartments());
  responsebody += QStringLiteral("\" readonly /></label>\n  </div>\n  <p>\n    <label class=\"w3-opacity\">Lenk Content<br /><input type=\"text\" class=\"w3-input w3-border w3-round\" name=\"appVars[id]\" value=\"");
  responsebody += THttpUtility::htmlEscape(lenkinfo.lenkContent());
  responsebody += QStringLiteral("\" readonly /></label>\n  </p>\n  <div class=\"w3-half\">\n    <label class=\"w3-opacity\">Lenk Creator<br /><input type=\"text\" class=\"w3-input w3-border w3-round\" name=\"appVars[id]\" value=\"");
  responsebody += THttpUtility::htmlEscape(lenkinfo.lenkCreator());
  responsebody += QStringLiteral("\" readonly /></label>\n  </div>\n  <div class=\"w3-half\">\n    <label class=\"w3-opacity\">Lenk Creator Date<br /><input type=\"text\" class=\"w3-input w3-border w3-round\" name=\"appVars[id]\" id=\"lenkCreatorDate\" value=\"");
  responsebody += THttpUtility::htmlEscape(lenkinfo.lenkCreatorDate());
  responsebody += QStringLiteral("\" readonly /></label>\n  </div>\n  <div class=\"w3-half\">\n    <label class=\"w3-opacity\">Lenk Auditor<br /><input type=\"text\" class=\"w3-input w3-border w3-round\" name=\"appVars[id]\" value=\"");
  responsebody += THttpUtility::htmlEscape(lenkinfo.lenkAuditor());
  responsebody += QStringLiteral("\" readonly /></label>\n  </div>\n  <div class=\"w3-half\">\n    <label class=\"w3-opacity\">Lenk Auditor Date<br /><input type=\"text\" class=\"w3-input w3-border w3-round\" name=\"appVars[id]\" id=\"lenkAuditorDate\" value=\"");
  responsebody += THttpUtility::htmlEscape(lenkinfo.lenkAuditorDate());
  responsebody += QStringLiteral("\" readonly /></label>\n  </div>\n  <div class=\"w3-half\">\n    <label class=\"w3-opacity\">Lenk Approver<br /><input type=\"text\" class=\"w3-input w3-border w3-round\" name=\"appVars[id]\" value=\"");
  responsebody += THttpUtility::htmlEscape(lenkinfo.lenkApprover());
  responsebody += QStringLiteral("\" readonly /></label>\n  </div>\n  <div class=\"w3-half\">\n    <label class=\"w3-opacity\">Lenk Approver Date<br /><input type=\"text\" class=\"w3-input w3-border w3-round\" name=\"appVars[id]\" id=\"lenkApproverDate\" value=\"");
  responsebody += THttpUtility::htmlEscape(lenkinfo.lenkApproverDate());
  responsebody += QStringLiteral("\" readonly /></label>\n  </div>\n</section>\n\n<br>\n<span class=\"w3-btn w3-red\" style=\"border-radius: 0px 0px 0px 0.5em\"><img src=\"/Icons/trash.svg\">&nbsp;");
  responsebody += QVariant(linkTo("Remove", urla("remove", lenkinfo.id()), Tf::Post, "confirm('Are you sure?')")).toString();
  responsebody += QStringLiteral("</span>\n&nbsp;&nbsp;&nbsp;\n<a href=\"/lenkinfo/save/");
  responsebody += THttpUtility::htmlEscape(lenkinfo.id());
  responsebody += QStringLiteral("\" class=\"w3-btn w3-light-grey\"><img src=\"/Icons/pencil.svg\">&nbsp;Q-Edit</a>\n<a href=\"/lenkinfo/list_all\" class=\"w3-btn w3-light-grey\"><img src=\"/Icons/justify.svg\">&nbsp;zur&uuml;ck</a>\n\n\n</main>\n\n<script>\n	convertUTCDateToLocalDate(\"lenkValidStartdate\",\"");
  responsebody += THttpUtility::htmlEscape(lenkinfo.lenkValidStartdate());
  responsebody += QStringLiteral("\"); \n    convertUTCDateToLocalDate(\"lenkCreatorDate\", \"");
  responsebody += THttpUtility::htmlEscape(lenkinfo.lenkCreatorDate());
  responsebody += QStringLiteral("\"); \n    convertUTCDateToLocalDate(\"lenkAuditorDate\", \"");
  responsebody += THttpUtility::htmlEscape(lenkinfo.lenkAuditorDate());
  responsebody += QStringLiteral("\"); \n    convertUTCDateToLocalDate(\"lenkApproverDate\", \"");
  responsebody += THttpUtility::htmlEscape(lenkinfo.lenkApproverDate());
  responsebody += QStringLiteral("\"); \n</script>\n\n\n<itis-footer id=\"itisFooter\" message=\"\"></itis-footer>\n</body>\n</html>\n");

  return responsebody;
}

T_DEFINE_VIEW(lenkinfo_showView)

#include "lenkinfo_showView.moc"
