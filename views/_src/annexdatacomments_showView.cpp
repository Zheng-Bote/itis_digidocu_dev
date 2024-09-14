#include <QtCore>
#include <TreeFrogView>
#include "annexdatacomments.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT annexdatacomments_showView : public TActionView
{
  Q_OBJECT
public:
  annexdatacomments_showView() : TActionView() { }
  QString toString();
};

QString annexdatacomments_showView::toString()
{
  responsebody.reserve(7554);
  responsebody += QStringLiteral("<!DOCTYPE html>\n");
    tfetch(AnnexDataComments, annexDataComments);
  responsebody += QStringLiteral("<html>\n<head>\n  <meta charset=\"UTF-8\">\n  <html lang=\"de\">\n\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QStringLiteral("</title>\n\n  <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, user-scalable=yes\">\n  <link rel=\"icon\" href=\"/favicon.ico\">\n\n  <script>\n    function doLocal()\n    {\n        console.log(\"this is local\");\n\n        let l_footer = document.getElementById(\"itisFooter\");\n        l_footer.message = '<a href=\"/stdsystem/license\" title=\"licenses\">Lizenzen</a>&nbsp;<a href=\"/stdsystem/imprint\" title=\"Imprint\">Impressum</a>';\n\n        //let l_menu = document.getElementById(\"itisMenu\"); \n        //l_menu.message = \"");
  responsebody += THttpUtility::htmlEscape(controller()->name());
  responsebody += QStringLiteral("\";\n    }\n\n	function setLanguage(lang)\n	{\n		if(lang == \"0\")\n		{lang = \"de\";}\n		else{lang = \"en\";}\n		document.cookie = \"lang=\" + lang + \";\" + \";path=/\";\n		location.reload();\n	}\n\n	function convertUTCDateToLocalDate(date, id) \n	{\n		//var d = convertUTCDateToLocalDate(new Date(\"2020-09-13T10:49:02.174\"));\n		var newDate = new Date(date.getTime()+date.getTimezoneOffset()*60*1000);\n\n		var offset = date.getTimezoneOffset() / 60;\n		var hours = date.getHours();\n\n		newDate.setHours(hours - offset);\n		\n		var mm = newDate.getMonth() + 1;\n		var dd = newDate.getDate();\n		var yy = newDate.getFullYear();\n		var hh = newDate.getHours();\n		var m = newDate.getMinutes();\n\n		if(mm < 10)\n		{\n			mm = \"0\" + mm;\n		}\n		if(dd < 10)\n		{\n			dd = \"0\" + dd;\n		}\n		if(hh < 10)\n		{\n			hh = \"0\" + hh;\n		}\n		if(m < 10)\n		{\n			m = \"0\" + m;\n		}\n		let datestr = yy + \"-\" + mm + \"-\" + dd + \" \" + hh + \":\" + m;\n	\n		document.getElementById(id).value = datestr;   \n	}\n	\n  </script>\n\n  <script type=\"module\" src=\"/js/itis_init.js\" /></script>\n  \n  <link rel=\"stylesheet\" href=\"/css/w3.css\">  \n  <link rel=\"stylesheet\" href=\"/css/custom.css\">  \n\n</head>\n\n<body class=\"w3-container w3-margin\" id=\"body\">\n\n  <itis-menu id=\"itisMenu\" message=\"\"></itis-menu>\n\n  <div class=\"w3-container w3-light-blue\">\n    <h2 id=\"portaltitle\">ITIS-API::Admin-Portal</h2>\n  </div>\n\n  <itis-menusub id=\"itisMenuSub\" message=\"");
  responsebody += THttpUtility::htmlEscape(controller()->name());
  responsebody += QStringLiteral("\"></itis-menusub>\n\n<h3 id=\"pagetitle\"><page-title message=\"\">");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QStringLiteral("</page-title></h3>\n<div id=\"pagedesc\"><page-desc message=\"\"></page-desc></div>\n\n<p style=\"color: red\"><span id=\"redmsg\">");
  techoex(red_msg);
  responsebody += QStringLiteral("</span> ");
  tehex(error);
  responsebody += QStringLiteral("</p><p style=\"color: green\"><span id=\"greenmsg\">");
  techoex(green_msg);
  responsebody += QStringLiteral("</span> ");
  tehex(notice);
  responsebody += QStringLiteral("</p>\n\n<main>\n    \n<div id=\"pagecontent\"><page-content message=\"\"></page-content></div>	\n\n<span class=\"w3-btn w3-red w3-wide\" style=\"border-radius: 0.5em 0px 0px 0px;\"><img src=\"/Icons/trash.svg\">&nbsp;");
  responsebody += QVariant(linkTo("Remove", urla("remove", annexDataComments.id()), Tf::Post, "confirm('Are you sure?')")).toString();
  responsebody += QStringLiteral("</span>\n&nbsp;&nbsp;&nbsp;\n<a href=\"/annexDataComments/save/");
  responsebody += THttpUtility::htmlEscape(annexDataComments.id());
  responsebody += QStringLiteral("\" class=\"w3-btn w3-light-grey\"><img src=\"/Icons/pencil.svg\">&nbsp;Q-Edit</a>\n<a href=\"/annexDataComments/list_all\" class=\"w3-btn w3-light-grey\"><img src=\"/Icons/justify.svg\">&nbsp;zur&uuml;ck</a>\n<br>\n\n<section>\n<div class=\"w3-row-padding\">\n  <div class=\"w3-half\">\n    <label class=\"w3-opacity\">ID<br /><input type=\"text\" class=\"w3-input w3-border w3-round\" name=\"objects.id\" value=\"");
  responsebody += THttpUtility::htmlEscape(annexDataComments.id());
  responsebody += QStringLiteral("\" readonly=\"readonly\" /></label>\n  </div>\n  <div class=\"w3-half\">\n	  <label class=\"w3-opacity\">commentCreated<br /><input class=\"w3-input w3-border w3-round\" name=\"user[username]\" value=\"\" id=\"");
  responsebody += THttpUtility::htmlEscape(annexDataComments.id());
  responsebody += QStringLiteral("\" readonly /></label>\n    <!-- <label class=\"w3-opacity\">commentCreated<br /><input class=\"w3-input w3-border w3-round\" name=\"user[username]\" value=\"");
  responsebody += THttpUtility::htmlEscape(annexDataComments.commentCreated());
  responsebody += QStringLiteral("\" readonly /></label> -->\n  </div>\n  <div class=\"w3-half\" style=\"padding-top: 1rem;\">\n    <label class=\"w3-opacity\">specId<br /><input class=\"w3-input w3-border w3-round\" name=\"user[firstname]\" value=\"");
  responsebody += THttpUtility::htmlEscape(annexDataComments.specId());
  responsebody += QStringLiteral("\" readonly /></label>\n  </div>\n <div class=\"w3-half\" style=\"padding-top: 1rem;\">\n    <label class=\"w3-opacity\">specTitle<br /><input class=\"w3-input w3-border w3-round\" name=\"user[surname]\" value=\"");
  responsebody += THttpUtility::htmlEscape(annexDataComments.specTitle());
  responsebody += QStringLiteral("\" readonly /></label>\n  </div>\n  <div class=\"w3-half\" style=\"padding-top: 1rem;\">\n    <label class=\"w3-opacity\">specVersion<br /><input class=\"w3-input w3-border w3-round\" name=\"user[email]\" value=\"");
  responsebody += THttpUtility::htmlEscape(annexDataComments.specVersion());
  responsebody += QStringLiteral("\" readonly /></label>\n  </div>\n  <div class=\"w3-half\" style=\"padding-top: 1rem; padding-bottom: 1rem;\">\n    <label class=\"w3-opacity\">username<br /><input class=\"w3-input w3-border w3-round\" name=\"user[user_timezone]\" value=\"");
  responsebody += THttpUtility::htmlEscape(annexDataComments.username());
  responsebody += QStringLiteral("\" readonly /></label>\n  </div>\n\n  <p><label class=\"w3-opacity\">User Comment</label><br><article><section>");
  responsebody += QVariant(annexDataComments.userComment()).toString();
  responsebody += QStringLiteral("</section></article></p>\n</div>\n</section>\n\n<br>\n<span class=\"w3-btn w3-red\" style=\"border-radius: 0px 0px 0px 0.5em\"><img src=\"/Icons/trash.svg\">&nbsp;");
  responsebody += QVariant(linkTo("Remove", urla("remove", annexDataComments.id()), Tf::Post, "confirm('Are you sure?')")).toString();
  responsebody += QStringLiteral("</span>\n&nbsp;&nbsp;&nbsp;\n<a href=\"/annexDataComments/save/");
  responsebody += THttpUtility::htmlEscape(annexDataComments.id());
  responsebody += QStringLiteral("\" class=\"w3-btn w3-light-grey\"><img src=\"/Icons/pencil.svg\">&nbsp;Q-Edit</a>\n<a href=\"/annexDataComments/list_all\" class=\"w3-btn w3-light-grey\">&laquo;&nbsp;zur&uuml;ck</a>\n\n</main>\n<script>convertUTCDateToLocalDate(new Date(\"");
  responsebody += THttpUtility::htmlEscape(annexDataComments.commentCreated());
  responsebody += QStringLiteral("\"), \"");
  responsebody += THttpUtility::htmlEscape(annexDataComments.id());
  responsebody += QStringLiteral("\")</script>\n<itis-footer id=\"itisFooter\" message=\"\"></itis-footer>\n</body>\n</html>\n\n");

  return responsebody;
}

T_DEFINE_VIEW(annexdatacomments_showView)

#include "annexdatacomments_showView.moc"
