#include <QtCore>
#include <TreeFrogView>
#include "glossar.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT glossar_saveView : public TActionView
{
  Q_OBJECT
public:
  glossar_saveView() : TActionView() { }
  QString toString();
};

QString glossar_saveView::toString()
{
  responsebody.reserve(6731);
  responsebody += QStringLiteral("<!DOCTYPE html>\n");
    tfetch(QVariantMap, glossar);
  responsebody += QStringLiteral("<html>\n<head>\n  <meta charset=\"UTF-8\">\n  <html lang=\"de\">\n\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QStringLiteral("</title>\n\n  <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, user-scalable=yes\">\n  <link rel=\"icon\" href=\"/favicon.ico\">\n\n  <script>\n    function doLocal()\n    {\n        console.log(\"this is local\");\n\n        let l_footer = document.getElementById(\"itisFooter\");\n        l_footer.message = '<a href=\"/stdsystem/license\" title=\"licenses\">Lizenzen</a>&nbsp;<a href=\"/stdsystem/imprint\" title=\"Imprint\">Impressum</a>';\n\n        //let l_menu = document.getElementById(\"itisMenu\"); \n        //l_menu.message = \"");
  responsebody += THttpUtility::htmlEscape(controller()->name());
  responsebody += QStringLiteral("\";\n    }\n\n	function setLanguage(lang)\n	{\n		if(lang == \"0\")\n		{lang = \"de\";}\n		else{lang = \"en\";}\n		document.cookie = \"lang=\" + lang + \";\" + \";path=/\";\n		location.reload();\n	}\n	\n  </script>\n\n  <script type=\"module\" src=\"/js/itis_init.js\" /></script>\n  \n  <link rel=\"stylesheet\" href=\"/css/w3.css\">  \n  <link rel=\"stylesheet\" href=\"/css/custom.css\">  \n\n<style>\n	.set-width { width: 250px;	border-radius: 5px;}\n</style>\n\n</head>\n\n<body class=\"w3-container w3-margin\" id=\"body\">\n\n  <itis-menu id=\"itisMenu\" message=\"\"></itis-menu>\n\n  <div class=\"w3-container w3-light-blue\">\n    <h2 id=\"portaltitle\">ITIS-API::Admin-Portal</h2>\n  </div>\n\n  <itis-menusub id=\"itisMenuSub\" message=\"");
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
  responsebody += QVariant(linkTo("Remove", urla("remove", glossar["id"]), Tf::Post, "confirm('Are you sure?')")).toString();
  responsebody += QStringLiteral("</span>\n&nbsp;&nbsp;&nbsp;\n<a href=\"/glossar/show/");
  responsebody += THttpUtility::htmlEscape(glossar["id"]);
  responsebody += QStringLiteral("\" class=\"w3-btn w3-light-grey\"><img src=\"/Icons/eyeglasses.svg\">&nbsp;Anzeige</a>\n<a href=\"/glossar/list_all\" class=\"w3-btn w3-light-grey\">&laquo;&nbsp;zur&uuml;ck</a>\n\n<section> \n");
  responsebody += QVariant(formTag(urla("save", glossar["id"]), Tf::Post)).toString();
  responsebody += QStringLiteral("\n<div class=\"w3-row-padding\">\n  <div class=\"w3-half\">\n    <label class=\"w3-opacity\">ID<br /><input type=\"text\" class=\"w3-input w3-border w3-round set-width\" name=\"glossar[id]\" value=\"");
  responsebody += THttpUtility::htmlEscape(glossar["id"]);
  responsebody += QStringLiteral("\" readonly=\"readonly\" /></label>\n  </div>\n  <div class=\"w3-half\">\n    <label class=\"w3-opacity\">Acronym<br /><input type=\"text\" class=\"w3-input w3-border w3-round\" name=\"glossar[acronym]\" value=\"");
  responsebody += THttpUtility::htmlEscape(glossar["acronym"]);
  responsebody += QStringLiteral("\" /></label>\n  </div>\n\n  <div class=\"w3-half\" style=\"padding-top: 1rem;\">\n    <label class=\"w3-opacity\">Term De<br /><input type=\"text\" class=\"w3-input w3-border w3-round\" name=\"glossar[termDe]\" value=\"");
  responsebody += THttpUtility::htmlEscape(glossar["termDe"]);
  responsebody += QStringLiteral("\" /></label>\n  </div>\n  <div class=\"w3-half\" style=\"padding-top: 1rem;\">\n    <label class=\"w3-opacity\">Term En<br /><input type=\"text\" class=\"w3-input w3-border w3-round\" name=\"glossar[termEn]\" value=\"");
  responsebody += THttpUtility::htmlEscape(glossar["termEn"]);
  responsebody += QStringLiteral("\" /></label>\n  </div>\n\n  <div class=\"w3-half\" style=\"padding-top: 1rem;\">\n    <label class=\"w3-opacity\">Desc De<br /><input type=\"text\" class=\"w3-input w3-border w3-round\" name=\"glossar[descDe]\" value=\"");
  responsebody += THttpUtility::htmlEscape(glossar["descDe"]);
  responsebody += QStringLiteral("\" /></label>\n  </div>\n\n  <div class=\"w3-half\" style=\"padding-top: 1rem; padding-bottom: 1rem;\">\n    <label class=\"w3-opacity\">Desc En<br /><input type=\"text\" class=\"w3-input w3-border w3-round\" name=\"glossar[descEn]\" value=\"");
  responsebody += THttpUtility::htmlEscape(glossar["descEn"]);
  responsebody += QStringLiteral("\" /></label>\n  </div>\n<!--  <p>\n    <label>Sort<br /><input type=\"text\" class=\"w3-input set-width\"  name=\"glossar[sort]\" value=\"");
  responsebody += THttpUtility::htmlEscape(glossar["sort"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n-->\n  <p>\n    <label class=\"w3-opacity\">Active<br /><input type=\"text\" class=\"w3-input w3-border w3-round set-width\" name=\"glossar[active]\" value=\"");
  responsebody += THttpUtility::htmlEscape(glossar["active"]);
  responsebody += QStringLiteral("\" pattern=\"[0-1]{1}\" title=\"nicht aktiv: 0 , aktiv: 1\" /></label>\n  </p>\n  <p>\n    <input type=\"submit\" value=\"Save &raquo;\" />\n  </p>\n  </div>\n</form>\n</section> \n<br>\n<span class=\"w3-btn w3-red\" style=\"border-radius: 0px 0px 0px 0.5em\"><img src=\"/Icons/trash.svg\">&nbsp;");
  responsebody += QVariant(linkTo("Remove", urla("remove", glossar["id"]), Tf::Post, "confirm('Are you sure?')")).toString();
  responsebody += QStringLiteral("</span>\n&nbsp;&nbsp;&nbsp;\n<a href=\"/glossar/show/");
  responsebody += THttpUtility::htmlEscape(glossar["id"]);
  responsebody += QStringLiteral("\" class=\"w3-btn w3-light-grey\"><img src=\"/Icons/eyeglasses.svg\">&nbsp;Anzeige</a>\n<a href=\"/glossar/list_all\" class=\"w3-btn w3-light-grey\">&laquo;&nbsp;zur&uuml;ck</a>\n\n</main>\n\n<itis-footer id=\"itisFooter\" message=\"\"></itis-footer>\n</body>\n</html>\n\n");

  return responsebody;
}

T_DEFINE_VIEW(glossar_saveView)

#include "glossar_saveView.moc"
