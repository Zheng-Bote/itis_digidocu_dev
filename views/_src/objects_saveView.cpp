#include <QtCore>
#include <TreeFrogView>
#include "objects.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT objects_saveView : public TActionView
{
  Q_OBJECT
public:
  objects_saveView() : TActionView() { }
  QString toString();
};

QString objects_saveView::toString()
{
  responsebody.reserve(6098);
  responsebody += QStringLiteral("<!DOCTYPE html>\n");
    tfetch(QVariantMap, objects);
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
  responsebody += QStringLiteral("</p>\n\n<main>\n    \n<div id=\"pagecontent\"><page-content message=\"\"></page-content></div>	\n\n<span class=\"w3-btn w3-red w3-wide\" style=\"border-radius: 0.5em 0px 0px 0px;\"><img src=\"/Icons/trash.svg\">&nbsp;");
  responsebody += QVariant(linkTo("Remove", urla("remove", objects["id"]), Tf::Post, "confirm('Are you sure?')")).toString();
  responsebody += QStringLiteral("</span>\n&nbsp;&nbsp;&nbsp;\n<a href=\"/objects/show/");
  responsebody += THttpUtility::htmlEscape(objects["id"]);
  responsebody += QStringLiteral("\" class=\"w3-btn w3-light-grey\"><img src=\"/Icons/eyeglasses.svg\">&nbsp;Anzeige</a>\n<a href=\"/objects/list_all\" class=\"w3-btn w3-light-grey\">&laquo;&nbsp;zur&uuml;ck</a>\n\n");
  responsebody += QVariant(formTag(urla("save", objects["id"]), Tf::Post)).toString();
  responsebody += QStringLiteral("\n<div class=\"w3-container\" style=\"max-width: 50%;\">\n  <p>\n    <label>ID<br /><input type=\"text\" class=\"w3-input\" name=\"objects[id]\" value=\"");
  responsebody += THttpUtility::htmlEscape(objects["id"]);
  responsebody += QStringLiteral("\" readonly=\"readonly\" /></label>\n  </p>\n  <p>\n    <label>Obj Sname<br /><input type=\"text\" class=\"w3-input\" name=\"objects[objSname]\" value=\"");
  responsebody += THttpUtility::htmlEscape(objects["objSname"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Obj Lname De<br /><input type=\"text\" class=\"w3-input\" name=\"objects[objLnameDe]\" value=\"");
  responsebody += THttpUtility::htmlEscape(objects["objLnameDe"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Desc De<br /><input type=\"text\" class=\"w3-input\" name=\"objects[descDe]\" value=\"");
  responsebody += THttpUtility::htmlEscape(objects["descDe"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Obj Lname En<br /><input type=\"text\" class=\"w3-input\" name=\"objects[objLnameEn]\" value=\"");
  responsebody += THttpUtility::htmlEscape(objects["objLnameEn"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Desc En<br /><input type=\"text\" class=\"w3-input\" name=\"objects[descEn]\" value=\"");
  responsebody += THttpUtility::htmlEscape(objects["descEn"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Sort<br /><input type=\"text\" class=\"w3-input\" name=\"objects[sort]\" value=\"");
  responsebody += THttpUtility::htmlEscape(objects["sort"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Active<br /><input type=\"text\" class=\"w3-input\" name=\"objects[active]\" value=\"");
  responsebody += THttpUtility::htmlEscape(objects["active"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Groups<br /><input type=\"text\" class=\"w3-input\" name=\"objects[groups]\" value=\"");
  responsebody += THttpUtility::htmlEscape(objects["groups"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <input type=\"submit\" value=\"speichern &raquo;\"/>\n  </p>\n</div>\n</form>\n\n<br>\n<span class=\"w3-btn w3-red\" style=\"border-radius: 0px 0px 0px 0.5em\"><img src=\"/Icons/trash.svg\">&nbsp;");
  responsebody += QVariant(linkTo("Remove", urla("remove", objects["id"]), Tf::Post, "confirm('Are you sure?')")).toString();
  responsebody += QStringLiteral("</span>\n&nbsp;&nbsp;&nbsp;\n<a href=\"/objects/show/");
  responsebody += THttpUtility::htmlEscape(objects["id"]);
  responsebody += QStringLiteral("\" class=\"w3-btn w3-light-grey\"><img src=\"/Icons/eyeglasses.svg\">&nbsp;Anzeige</a>\n<a href=\"/objects/list_all\" class=\"w3-btn w3-light-grey\">&laquo;&nbsp;zur&uuml;ck</a>\n\n</main>\n\n<itis-footer id=\"itisFooter\" message=\"\"></itis-footer>\n</body>\n</html>\n");

  return responsebody;
}

T_DEFINE_VIEW(objects_saveView)

#include "objects_saveView.moc"
