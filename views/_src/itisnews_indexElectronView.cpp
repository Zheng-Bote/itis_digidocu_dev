#include <QtCore>
#include <TreeFrogView>
#include "itisnews.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT itisnews_indexElectronView : public TActionView
{
  Q_OBJECT
public:
  itisnews_indexElectronView() : TActionView() { }
  QString toString();
};

QString itisnews_indexElectronView::toString()
{
  responsebody.reserve(2211);
  responsebody += QStringLiteral("<!DOCTYPE html>\n");
    responsebody += QStringLiteral("<html>\n<head>\n  <meta charset=\"UTF-8\">\n  <html lang=\"de\">\n\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QStringLiteral("</title>\n\n  <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, user-scalable=yes\">\n  <link rel=\"icon\" href=\"/favicon.ico\">\n\n  <script>\n    function doLocal()\n    {\n        console.log(\"this is local\");\n\n        let prio = getPrioColors();\n        document.getElementById(\"prio_legend\").innerHTML = '<small>Legende:&nbsp;' + prio.low + '&nbsp;' + prio.medium + '&nbsp;' + prio.high + '&nbsp;' + prio.critical + '</small>';   \n    }\n\n	function setLanguage(lang)\n	{\n		if(lang == \"0\")\n		{lang = \"de\";}\n		else{lang = \"en\";}\n		document.cookie = \"lang=\" + lang + \";\" + \";path=/\";\n		location.reload();\n	}\n	\n  </script>\n\n  <script type=\"module\" src=\"/js/itis_init.js\" /></script>\n  <script src=\"/js/itisnews/itisnews.js\" /></script>\n  \n  <link rel=\"stylesheet\" href=\"/css/w3.css\">  \n  <link rel=\"stylesheet\" href=\"/css/custom.css\">  \n\n</head>\n\n<body class=\"w3-container w3-margin\" id=\"body\">\n\n<h3 id=\"pagetitle\"><page-title message=\"\">IT-IS Standards News</page-title></h3>\n<div id=\"pagedesc\"><page-desc message=\"\"></page-desc></div>\n\n<p id=\"redmsg\" style=\"color: red\">");
  techoex(red_msg);
  tehex(error);
  responsebody += QStringLiteral("</p><p id=\"greenmsg\" style=\"color: green\">");
  techoex(green_msg);
  tehex(notice);
  responsebody += QStringLiteral("</p>\n\n<main>\n<annex-data id=\"annexdata\"></annex-data>\n<div id=\"pagecontent\"><page-content message=\"\"></page-content></div>	\n\n	<div id=\"prio_legend\"></div>\n\n	<div class=\"w3-panel w3-light-grey\" style=\"border-radius: 0px 0px 0.5em 0.5em;\">\n		<h4>IT-IS Standards News</h4>\n			<ol id=\"news_std\"></ol>\n	</div>\n\n	<div class=\"w3-panel w3-light-grey\" style=\"border-radius: 0px 0px 0.5em 0.5em;\">\n		<h4>IT-IS Product News</h4>\n			<ol id=\"news_products\"></ol>\n	</div>\n	 \n</main>\n \n</body>\n</html>\n");

  return responsebody;
}

T_DEFINE_VIEW(itisnews_indexElectronView)

#include "itisnews_indexElectronView.moc"
