#include <QtCore>
#include <TreeFrogView>
#include "itisnews.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT itisnews_createView : public TActionView
{
  Q_OBJECT
public:
  itisnews_createView() : TActionView() { }
  QString toString();
};

QString itisnews_createView::toString()
{
  responsebody.reserve(7498);
  responsebody += QStringLiteral("<!DOCTYPE html>\n");
    tfetch(QVariantMap, itisNews);
  responsebody += QStringLiteral("<html>\n<head>\n  <meta charset=\"UTF-8\">\n  <html lang=\"de\">\n\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QStringLiteral("</title>\n\n  <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, user-scalable=yes\">\n  <link rel=\"icon\" href=\"/favicon.ico\">\n\n  <script>\n    function doLocal()\n    {\n        console.log(\"this is local\");\n\n        let l_footer = document.getElementById(\"itisFooter\");\n        l_footer.message = '<a href=\"/stdsystem/license\" title=\"licenses\">Lizenzen</a>&nbsp;<a href=\"/stdsystem/imprint\" title=\"Imprint\">Impressum</a>';\n\n		setNewsDate();\n	}\n\n	function setNewsDate()\n	{\n		var d = new Date();\n		var mm = d.getMonth() + 1;\n		var dd = d.getDate();\n		var yy = d.getFullYear();\n		var hh = d.getHours();\n		var m = d.getMinutes();\n\n		if(mm < 10)\n		{\n			mm = \"0\" + mm;\n		}\n		if(dd < 10)\n		{\n			dd = \"0\" + dd;\n		}\n		if(hh < 10)\n		{\n			hh = \"0\" + hh;\n		}\n		if(m < 10)\n		{\n			m = \"0\" + m;\n		}\n		let datestr = yy + \"-\" + mm + \"-\" + dd + \" \" + hh + \":\" + m;\n		\n		document.getElementById(\"createDate\").value = datestr;\n		document.getElementById(\"startDate\").value = datestr;\n		document.getElementById(\"endDate\").value = datestr;\n	}\n\n	function setLanguage(lang)\n	{\n		if(lang == \"0\")\n		{lang = \"de\";}\n		else{lang = \"en\";}\n		document.cookie = \"lang=\" + lang + \";\" + \";path=/\";\n		location.reload();\n	}\n	\n  </script>\n\n  <script type=\"module\" src=\"/js/itis_init.js\" /></script>\n  \n  <link rel=\"stylesheet\" href=\"/css/w3.css\">  \n  <link rel=\"stylesheet\" href=\"/css/custom.css\">  \n\n</head>\n\n<body class=\"w3-container w3-margin\" id=\"body\">\n\n  <itis-menu id=\"itisMenu\" message=\"\"></itis-menu>\n\n  <div class=\"w3-container w3-light-blue\">\n    <h2 id=\"portaltitle\">ITIS-API::Admin-Portal</h2>\n  </div>\n\n  <itis-menusub id=\"itisMenuSub\" message=\"");
  responsebody += THttpUtility::htmlEscape(controller()->name());
  responsebody += QStringLiteral("\"></itis-menusub>\n\n<h3 id=\"pagetitle\"><page-title message=\"\">");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QStringLiteral("</page-title></h3>\n<div id=\"pagedesc\"><page-desc message=\"\"></page-desc></div>\n\n<p id=\"redmsg\" style=\"color: red\">");
  techoex(red_msg);
  tehex(error);
  responsebody += QStringLiteral("</p><p id=\"greenmsg\" style=\"color: green\">");
  techoex(green_msg);
  tehex(notice);
  responsebody += QStringLiteral("</p>\n\n<main>\n    \n<div id=\"pagecontent\"><page-content message=\"\"></page-content></div>	\n\n");
  responsebody += QVariant(formTag(urla("create"), Tf::Post)).toString();
  responsebody += QStringLiteral("\n  <p>\n    <label>News Type <small>(admin, standards, products)</small><br /><input type=\"text\" pattern=\"^(admin)|(standards)|(products)$\" title=\"admin, standards, products\" class=\"w3-input\" name=\"itisNews[newsType]\" value=\"");
  responsebody += THttpUtility::htmlEscape(itisNews["newsType"]);
  responsebody += QStringLiteral("\" required /></label>\n  </p>\n  <p>\n    <label>News Type Sub <small>(new, pending, closed, changed, deprecated, security, patched)</small><br /><input type=\"text\" pattern=\"^(new)|(pending)|(closed)|(changed)|(deprecated)|(security)|(patched)$\" title=\"new, pending, closed, changed, deprecated, security, patched\" class=\"w3-input\" name=\"itisNews[newsTypeSub]\" value=\"");
  responsebody += THttpUtility::htmlEscape(itisNews["newsTypeSub"]);
  responsebody += QStringLiteral("\" required /></label>\n  </p>\n  <p>\n    <label>News Title De<br /><input type=\"text\" minlength=\"2\" maxlength=\"25\" class=\"w3-input\" name=\"itisNews[newsTitleDe]\" value=\"");
  responsebody += THttpUtility::htmlEscape(itisNews["newsTitleDe"]);
  responsebody += QStringLiteral("\" required /></label>\n  </p>\n  <p>\n    <label>News Title En<br /><input type=\"text\" minlength=\"2\" maxlength=\"25\" class=\"w3-input\" name=\"itisNews[newsTitleEn]\" value=\"");
  responsebody += THttpUtility::htmlEscape(itisNews["newsTitleEn"]);
  responsebody += QStringLiteral("\" required /></label>\n  </p>\n  <p>\n    <label>News Desc De<br /><input type=\"text\" minlength=\"10\" maxlength=\"50\" class=\"w3-input\" name=\"itisNews[newsDescDe]\" value=\"");
  responsebody += THttpUtility::htmlEscape(itisNews["newsDescDe"]);
  responsebody += QStringLiteral("\" required /></label>\n  </p>\n  <p>\n    <label>News Desc En<br /><input type=\"text\" minlength=\"10\" maxlength=\"50\" class=\"w3-input\" name=\"itisNews[newsDescEn]\" value=\"");
  responsebody += THttpUtility::htmlEscape(itisNews["newsDescEn"]);
  responsebody += QStringLiteral("\" required /></label>\n  </p>\n  <p>\n    <label>News Text De<br /><input type=\"text\" minlength=\"10\" maxlength=\"255\" class=\"w3-input\" name=\"itisNews[newsTextDe]\" value=\"");
  responsebody += THttpUtility::htmlEscape(itisNews["newsTextDe"]);
  responsebody += QStringLiteral("\" required /></label>\n  </p>\n  <p>\n    <label>News Text En<br /><input type=\"text\" minlength=\"10\" maxlength=\"255\" class=\"w3-input\" name=\"itisNews[newsTextEn]\" value=\"");
  responsebody += THttpUtility::htmlEscape(itisNews["newsTextEn"]);
  responsebody += QStringLiteral("\" required /></label>\n  </p>\n  <p>\n    <label>News Prio <small>(low, medium, high, critical)</small><br /><input type=\"text\" pattern=\"^(low)|(medium)|(high)|(critical)$\" title=\"low, medium, high, critical\" class=\"w3-input\" name=\"itisNews[newsPrio]\" value=\"");
  responsebody += THttpUtility::htmlEscape(itisNews["newsPrio"]);
  responsebody += QStringLiteral("\" required /></label>\n  </p>\n  <p>\n    <label>Author<br /><input class=\"w3-input\" name=\"itisNews[author]\" value=\"");
  tehex(usermail);
  responsebody += QStringLiteral("\" readonly /></label>\n  </p>\n  <p>\n    <label>News Created<br /><input class=\"w3-input\" name=\"itisNews[newsCreated]\" id=\"createDate\" value=\"");
  responsebody += THttpUtility::htmlEscape(itisNews["newsCreated"]);
  responsebody += QStringLiteral("\" readonly /></label>\n  </p>\n  <p>\n    <label>News Valid Start<br /><input type=\"text\" pattern=\"^(20)([0-9]{2})-([0|1]{1})([0-2]{1})-([0-3]{1})([0-9]{1})\\s([0-2]{1})([0-9]{1}):([0-5]{1})([0-9]{1})$\" title=\"YYYY-MM-DD hh:mm\" class=\"w3-input\" name=\"itisNews[newsValidStart]\" id=\"startDate\" value=\"");
  responsebody += THttpUtility::htmlEscape(itisNews["newsValidStart"]);
  responsebody += QStringLiteral("\" required /></label>\n  </p>\n  <p>\n    <label>News Valid End<br /><input type=\"text\" pattern=\"^(20)([0-9]{2})-([0|1]{1})([0-2]{1})-([0-3]{1})([0-9]{1})\\s([0-2]{1})([0-9]{1}):([0-5]{1})([0-9]{1})$\" title=\"YYYY-MM-DD hh:mm\" class=\"w3-input\" name=\"itisNews[newsValidEnd]\" id=\"endDate\" value=\"");
  responsebody += THttpUtility::htmlEscape(itisNews["newsValidEnd"]);
  responsebody += QStringLiteral("\" required /></label>\n  </p>\n  <p>\n  <p>\n    <input type=\"submit\" value=\"Create &raquo;\" />\n  </p>\n</form>\n\n<br/>\n\n<a href=\"/itisNews/list_all\" class=\"w3-btn w3-light-grey\">&laquo;&nbsp;zur&uuml;ck</a>\n\n</main>\n\n<itis-footer id=\"itisFooter\" message=\"\"></itis-footer>\n</body>\n</html>\n\n");

  return responsebody;
}

T_DEFINE_VIEW(itisnews_createView)

#include "itisnews_createView.moc"
