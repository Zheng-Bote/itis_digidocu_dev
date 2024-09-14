#include <QtCore>
#include <TreeFrogView>
#include "releasemgmt.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT releasemgmt_showView : public TActionView
{
  Q_OBJECT
public:
  releasemgmt_showView() : TActionView() { }
  QString toString();
};

QString releasemgmt_showView::toString()
{
  responsebody.reserve(19253);
  responsebody += QStringLiteral("<!DOCTYPE html>\n");
    tfetch(ReleaseMgmt, releaseMgmt);
  responsebody += QStringLiteral("<html>\n<head>\n  <meta charset=\"UTF-8\">\n  <html lang=\"de\">\n\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QStringLiteral("</title>\n\n  <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, user-scalable=yes\">\n  \n  <link rel=\"icon\" type=\"image/svg+xml\" href=\"/favicon.svg\">\n  <link rel=\"alternate icon\" href=\"/favicon.ico\">\n  <link rel=\"mask-icon\" href=\"/favicon.svg\" color=\"#b2b2b2\">\n  \n    <link rel=\"preload\" href=\"/fonts/Inter-Regular.woff2\" as=\"font\" type=\"font/woff2\" crossorigin />\n\n  <script>\n    function doLocal()\n    {\n        console.log(\"this is local\");\n\n        let l_footer = document.getElementById(\"itisFooter\");\n        l_footer.message = '<a href=\"/stdsystem/license\" title=\"licenses\">Lizenzen</a>&nbsp;<a href=\"/stdsystem/imprint\" title=\"Imprint\">Impressum</a>';\n        \n		let doctype = \"");
  responsebody += THttpUtility::htmlEscape(releaseMgmt.docType());
  responsebody += QStringLiteral("\";\n		let formid = document.getElementById(\"formid\");\n		if(doctype === \"annex\")\n		{\n			formid.setAttribute(\"action\", \"/annexdata/showCiAnnex\");\n		}\n		else\n		{\n			formid.setAttribute(\"action\", \"/standardsdata/showCiStd\");\n		}\n		\n		convertUTCDateToLocalDate('relrequestDate', \"");
  responsebody += THttpUtility::htmlEscape(releaseMgmt.relrequestDate());
  responsebody += QStringLiteral("\");\n		convertUTCDateToLocalDate('relcreatorDecisdate', \"");
  responsebody += THttpUtility::htmlEscape(releaseMgmt.relcreatorDecisdate());
  responsebody += QStringLiteral("\");\n		convertUTCDateToLocalDate('relinspectDecisdate', \"");
  responsebody += THttpUtility::htmlEscape(releaseMgmt.relinspectDecisdate());
  responsebody += QStringLiteral("\");\n		convertUTCDateToLocalDate('relapprovDecisdate', \"");
  responsebody += THttpUtility::htmlEscape(releaseMgmt.relapprovDecisdate());
  responsebody += QStringLiteral("\");\n		convertUTCDateToLocalDate('ciDate', \"");
  responsebody += THttpUtility::htmlEscape(releaseMgmt.ciDate());
  responsebody += QStringLiteral("\");\n		convertUTCDateToLocalDate('cdDate', \"");
  responsebody += THttpUtility::htmlEscape(releaseMgmt.cdDate());
  responsebody += QStringLiteral("\");\n		convertUTCDateToLocalDate('cddDate', \"");
  responsebody += THttpUtility::htmlEscape(releaseMgmt.cddDate());
  responsebody += QStringLiteral("\");\n		\n		getLenkStatus();\n    }\n\n	function setLanguage(lang)\n	{\n		if(lang == \"0\")\n		{lang = \"de\";}\n		else{lang = \"en\";}\n		document.cookie = \"lang=\" + lang + \";\" + \";path=/\";\n		location.reload();\n	}\n\n	function convertUTCDateToLocalDate(id, datetime) \n	{\n		if(! datetime)\n		{\n			return;\n		}\n		//var date = new Date(datetime);\n		var newDate = new Date(datetime);\n		\n		/* var newDate = new Date(date.getTime()+date.getTimezoneOffset()*60*1000);\n\n		var offset = date.getTimezoneOffset() / 60;\n		var hours = date.getHours();\n\n		newDate.setHours(hours - offset);\n		*/\n		var mm = newDate.getMonth() + 1;\n		var dd = newDate.getDate();\n		var yy = newDate.getFullYear();\n		var hh = newDate.getHours();\n		var m = newDate.getMinutes();\n\n		if(mm < 10)\n		{\n			mm = \"0\" + mm;\n		}\n		if(dd < 10)\n		{\n			dd = \"0\" + dd;\n		}\n\n		let datestr = yy + \"-\" + mm + \"-\" + dd;\n		\n		if(id) {\n			document.getElementById(id).value = datestr;\n		}\n		else {\n			return datestr;\n		}   \n	}\n\n	async function getLenkStatus() {\n	  // GET request using fetch with async/await\n	  let pdata = new URLSearchParams([[\"spec_obj\", \"");
  responsebody += THttpUtility::htmlEscape(releaseMgmt.objSname());
  responsebody += QStringLiteral("\"], [\"ac_class\", \"");
  responsebody += THttpUtility::htmlEscape(releaseMgmt.acClasses());
  responsebody += QStringLiteral("\"], [\"pc_class\", \"");
  responsebody += THttpUtility::htmlEscape(releaseMgmt.pcClasses());
  responsebody += QStringLiteral("\"], [\"country\", \"");
  responsebody += THttpUtility::htmlEscape(releaseMgmt.country());
  responsebody += QStringLiteral("\"], [\"lang\", \"");
  responsebody += THttpUtility::htmlEscape(releaseMgmt.lang());
  responsebody += QStringLiteral("\"]]);\n	  const response = await fetch(\"/lenkinfo/getJson\",\n	  {\n		body: pdata,\n		method: \"post\"\n	  });\n	  const data = await response.json();\n	  let dlength = data.length;\n	  // console.log('getLenkStatus: ' + data[dlength -1].lenk_status);\n		if(dlength > 0)\n		{\n			check3Btns(data[dlength -1].lenk_status);\n		}\n		else\n		{\n			check3Btns('pre-release');\n		}\n	}\n\n	function check3Btns(status)\n	{\n		document.getElementById('rel_status').value = status;\n		switch(status) {\n			case 'draft': {\n				document.getElementById('prereleaseBtn').disabled = true; \n				document.getElementById('showreleasedBtn').disabled = true; \n				document.getElementById('releasedBtn').disabled = true;\n				//console.log('check3Btns: ' + status);\n				break;\n			}\n			case 'pre-release': {\n				document.getElementById('prereleaseBtn').disabled = false;\n				document.getElementById('prereleasePrintBtn').disabled = false; \n				document.getElementById('showreleasedBtn').disabled = true; \n				document.getElementById('releasedBtn').disabled = true;\n				//console.log('check3Btns: ' + status);\n				break;\n			}\n			case 'pre-release review': {\n				document.getElementById('prereleaseBtn').disabled = false; \n				document.getElementById('showreleasedBtn').disabled = true; \n				document.getElementById('releasedBtn').disabled = true;\n				//console.log('check3Btns: ' + status);\n				break;\n			}\n			case 'released': {\n				document.getElementById('prereleaseBtn').disabled = true; \n				document.getElementById('showreleasedBtn').disabled = false; \n				document.getElementById('releasedBtn').disabled = false;\n				//console.log('check3Btns: ' + status);\n				break;\n			}\n			case 'expired': {\n				document.getElementById('prereleaseBtn').disabled = true; \n				document.getElementById('showreleasedBtn').disabled = true; \n				document.getElementById('releasedBtn').disabled = true;\n				//console.log('check3Btns: ' + status);\n				break;\n			}\n			default: {\n				document.getElementById('prereleaseBtn').disabled = false; \n				document.getElementById('showreleasedBtn').disabled = true; \n				document.getElementById('releasedBtn').disabled = true;\n				//console.log('check3Btns DEFAULT: ' + status);\n			}\n		}	\n   }\n   	\n  </script>\n\n  <script type=\"module\" src=\"/js/itis_init.js\" /></script>\n  \n  <link rel=\"stylesheet\" href=\"/css/w3.css\">  \n  <link rel=\"stylesheet\" href=\"/css/custom.css\">  \n \n	<style>\n		.set-width { width: 33%; min-width: 100px; border-radius: 5px;}\n		.w3-half, .w3-third { margin-bottom: 1rem; }\n	</style>\n\n</head>\n\n<body class=\"w3-container w3-margin\" id=\"body\">\n\n  <itis-menu id=\"itisMenu\" message=\"\"></itis-menu>\n\n  <div class=\"w3-container w3-light-blue\">\n    <h2 id=\"portaltitle\">ITIS-API::Admin-Portal</h2>\n  </div>\n\n  <itis-menusub id=\"itisMenuSub\" message=\"");
  responsebody += THttpUtility::htmlEscape(controller()->name());
  responsebody += QStringLiteral("\"></itis-menusub>\n\n<h3 id=\"pagetitle\"><page-title message=\"\">");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QStringLiteral("</page-title></h3>\n<div id=\"pagedesc\"><page-desc message=\"\"></page-desc></div>\n\n<span style=\"color: red\">\n	<span  id=\"redmsg\">");
  techoex(red_msg);
  responsebody += QStringLiteral("</span>&nbsp;<span>");
  tehex(error);
  responsebody += QStringLiteral("</span>\n</span>\n<span style=\"color: green\">\n	<span id=\"greenmsg\">");
  techoex(green_msg);
  responsebody += QStringLiteral("</span>&nbsp;<span>");
  tehex(notice);
  responsebody += QStringLiteral("</span>\n</span>\n\n<main>\n<div id=\"pagecontent\"><page-content message=\"\"></page-content></div>\n\n<span class=\"w3-btn w3-red w3-wide\" style=\"border-radius: 0.5em 0px 0px 0px;\"><img src=\"/Icons/trash.svg\">&nbsp;");
  responsebody += QVariant(linkTo("Remove", urla("remove", releaseMgmt.id()), Tf::Post, "confirm('Are you sure?')")).toString();
  responsebody += QStringLiteral("</span>\n&nbsp;&nbsp;&nbsp;\n<a href=\"/releasemgmt/save/");
  responsebody += THttpUtility::htmlEscape(releaseMgmt.id());
  responsebody += QStringLiteral("\" class=\"w3-btn w3-light-grey\"><img src=\"/Icons/pencil.svg\">&nbsp;Q-Edit</a>\n<a href=\"javascript:window.close();\" class=\"w3-btn w3-light-grey\"><img src=\"/Icons/justify.svg\">&nbsp;zur&uuml;ck</a>\n<a href=\"javascript:void(0)\" class=\"w3-btn w3-light-grey\" onclick=\"open_show()\" title=\"Show Annex\"><img src=\"/Icons/eyeglasses.svg\"></a>\n<br>\n\n<section>\n	\n<form id=\"formid\" class=\"w3-container\" action=\"/annexdata/showCiAnnex\" method=\"post\">\n<input type=text\" name=\"spec_release\" value=\"pre-released\" hidden>\n<input type=text\" name=\"getStdType\" value=\"show\" hidden>\n \n<div class=\"w3-row-padding\"> \n	\n  <div class=\"w3-half\">\n    <label class=\"w3-opacity\">ID<br /><input type=\"text\" class=\"w3-input w3-border w3-round set-width\" name=\"release_id\" value=\"");
  responsebody += THttpUtility::htmlEscape(releaseMgmt.id());
  responsebody += QStringLiteral("\" readonly></label>\n  </div>\n  <div class=\"w3-half\">\n	  <label class=\"w3-opacity\">Release Status<br /><input type=\"text\" class=\"w3-input w3-border w3-round set-width\" name=\"rel_status\" id=\"rel_status\" value=\"\" readonly></label>\n  </div>\n  <div class=\"w3-half\">\n    <label class=\"w3-opacity\">Objekt Name<br /><input type=\"text\" class=\"w3-input w3-border w3-round\" name=\"obj_sname\" value=\"");
  responsebody += THttpUtility::htmlEscape(releaseMgmt.objSname());
  responsebody += QStringLiteral("\" readonly></label>\n  </div>\n  <div class=\"w3-half\">\n    <label class=\"w3-opacity\">Release Version<br /><input class=\"w3-input\" type=\"text\" value=\"");
  responsebody += THttpUtility::htmlEscape(releaseMgmt.specVersion());
  responsebody += QStringLiteral("\" readonly></label>\n  </div>\n  <p>&nbsp;</p>\n  <div class=\"w3-half\">\n    <label class=\"w3-opacity\">AC Class<br /><input type=\"text\" class=\"w3-input w3-border w3-round\" name=\"ac_class\" value=\"");
  responsebody += THttpUtility::htmlEscape(releaseMgmt.acClasses());
  responsebody += QStringLiteral("\" readonly></label>\n  </div>\n  <div class=\"w3-half\">\n    <label class=\"w3-opacity\">PC Class<br /><input type=\"text\" class=\"w3-input w3-border w3-round\" name=\"pc_class\" value=\"");
  responsebody += THttpUtility::htmlEscape(releaseMgmt.pcClasses());
  responsebody += QStringLiteral("\" readonly></label>\n  </div>\n  <div class=\"w3-half\">\n    <label class=\"w3-opacity\">Cat Class<br><input class=\"w3-input\" type=\"text\" value=\"");
  responsebody += THttpUtility::htmlEscape(releaseMgmt.catClass());
  responsebody += QStringLiteral("\" readonly></label>\n  </div>\n  <div class=\"w3-half\">\n    <label class=\"w3-opacity\">Lang<br /><input type=\"text\" class=\"w3-input w3-border w3-round\" name=\"country\" value=\"");
  responsebody += THttpUtility::htmlEscape(releaseMgmt.country());
  responsebody += QStringLiteral("\" readonly></label>\n  </div>\n  <div class=\"w3-half\">\n    <label class=\"w3-opacity\">Sprache<br /><input type=\"text\" class=\"w3-input w3-border w3-round\" name=\"lang\" value=\"");
  responsebody += THttpUtility::htmlEscape(releaseMgmt.lang());
  responsebody += QStringLiteral("\" readonly></label>\n  </div>\n  <div class=\"w3-half\">\n    <label class=\"w3-opacity\">Dokument Typ<br /><input type=\"text\" class=\"w3-input w3-border w3-round\" name=\"\" value=\"");
  responsebody += THttpUtility::htmlEscape(releaseMgmt.docType());
  responsebody += QStringLiteral("\" readonly></label>\n  </div>\n  <div class=\"w3-half\">\n    <label class=\"w3-opacity\">Release Requester<br /><input type=\"text\" class=\"w3-input w3-border w3-round\" name=\"\" value=\"");
  responsebody += THttpUtility::htmlEscape(releaseMgmt.relRequester());
  responsebody += QStringLiteral("\" readonly></label>\n  </div>\n  <div class=\"w3-half\">\n    <label class=\"w3-opacity\">Release Request Date<br /><input type=\"text\" class=\"w3-input w3-border w3-round\" name=\"\" id=\"relrequestDate\" value=\"");
  responsebody += THttpUtility::htmlEscape(releaseMgmt.relrequestDate());
  responsebody += QStringLiteral("\" readonly></label>\n  </div>\n  <div class=\"w3-half\">\n    <label class=\"w3-opacity\">Release Ersteller<br /><input type=\"text\" class=\"w3-input w3-border w3-round\" name=\"\" value=\"");
  responsebody += THttpUtility::htmlEscape(releaseMgmt.relCreator());
  responsebody += QStringLiteral("\" readonly></label>\n  </div>\n  <div class=\"w3-half\">\n    <label class=\"w3-opacity\">Release Ersteller Datum<br /><input type=\"text\" class=\"w3-input w3-border w3-round\" name=\"\" id=\"relcreatorDecisdate\" value=\"");
  responsebody += THttpUtility::htmlEscape(releaseMgmt.relcreatorDecisdate());
  responsebody += tr("\" readonly></label>\n  </div>\n  <div class=\"w3-half\">\n    <label class=\"w3-opacity\">Release Prüfer<br /><input type=\"text\" class=\"w3-input w3-border w3-round\" name=\"\" value=\"");
  responsebody += THttpUtility::htmlEscape(releaseMgmt.relInspector());
  responsebody += tr("\" readonly></label>\n  </div>\n  <div class=\"w3-half\">\n    <label class=\"w3-opacity\">Release Prüfer Datum<br /><input type=\"text\" class=\"w3-input w3-border w3-round\" name=\"\" id=\"relinspectDecisdate\" value=\"");
  responsebody += THttpUtility::htmlEscape(releaseMgmt.relinspectDecisdate());
  responsebody += QStringLiteral("\" readonly></label>\n  </div>\n  <div class=\"w3-half\">\n    <label class=\"w3-opacity\">Release Freigeber<br /><input type=\"text\" class=\"w3-input w3-border w3-round\" name=\"\" value=\"");
  responsebody += THttpUtility::htmlEscape(releaseMgmt.relApprover());
  responsebody += QStringLiteral("\" readonly></label>\n  </div>\n  <div class=\"w3-half\">\n    <label class=\"w3-opacity\">Release Freigeber Datum<br /><input type=\"text\" class=\"w3-input w3-border w3-round\" name=\"\" id=\"relapprovDecisdate\" value=\"");
  responsebody += THttpUtility::htmlEscape(releaseMgmt.relapprovDecisdate());
  responsebody += QStringLiteral("\" readonly></label>\n  </div>\n  <div class=\"w3-third\">\n    <label class=\"w3-opacity\">CI Date<br /><input type=\"text\" class=\"w3-input w3-border w3-round\" name=\"\" id=\"ciDate\" value=\"");
  responsebody += THttpUtility::htmlEscape(releaseMgmt.ciDate());
  responsebody += QStringLiteral("\" readonly></label>\n  </div>\n  <div class=\"w3-third\">\n    <label class=\"w3-opacity\">CD Date<br /><input type=\"text\" class=\"w3-input w3-border w3-round\" name=\"\" id=\"cdDate\" value=\"");
  responsebody += THttpUtility::htmlEscape(releaseMgmt.cdDate());
  responsebody += QStringLiteral("\" readonly></label>\n  </div>\n  <div class=\"w3-third\">\n    <label class=\"w3-opacity\">CDD Date<br /><input type=\"text\" class=\"w3-input w3-border w3-round\" name=\"\" id=\"cddDate\" value=\"");
  responsebody += THttpUtility::htmlEscape(releaseMgmt.cddDate());
  responsebody += QStringLiteral("\" readonly></label>\n  </div>\n\n<input type=\"submit\" id=\"prerelease\" value=\"Pre-Release anschauen &raquo;\" style=\"display:none;\">\n<button id=\"prereleaseBtn\" class=\"w3-btn w3-light-grey w3-border\" onClick=\"showIt('pre-release')\" disabled = true > &uarr; show Pre-Release</button>\n\n<input type=\"submit\" id=\"prereleaseprint\" value=\"Pre-Release drucken &raquo;\" style=\"display:none;\">\n<button id=\"prereleasePrintBtn\" class=\"w3-btn w3-light-grey w3-border\" onClick=\"showIt('pre-release', true)\" disabled = true > &uarr; print Pre-Release</button>\n\n<input type=\"submit\" id=\"showreleased\" value=\"Release anschauen &raquo;\" style=\"display:none;\">\n<button id=\"showreleasedBtn\" class=\"w3-btn w3-light-grey w3-border\" onClick=\"showIt('showreleased')\" disabled = true > &uarr; show Released</button>\n\n<input type=\"submit\" id=\"printreleased\" value=\"Release drucken &raquo;\" style=\"display:none;\">\n<button id=\"releasedBtn\" class=\"w3-btn w3-light-grey w3-border\" onClick=\"showIt('printreleased')\" disabled = true > &uarr; print Released</button>\n\n</div>\n</form>\n\n</section> \n\n\n<br>\n<span class=\"w3-btn w3-red\" style=\"border-radius: 0px 0px 0px 0.5em\"><img src=\"/Icons/trash.svg\">&nbsp;");
  responsebody += QVariant(linkTo("Remove", urla("remove", releaseMgmt.id()), Tf::Post, "confirm('Are you sure?')")).toString();
  responsebody += QStringLiteral("</span>\n&nbsp;&nbsp;&nbsp;\n<a href=\"/releasemgmt/save/");
  responsebody += THttpUtility::htmlEscape(releaseMgmt.id());
  responsebody += QStringLiteral("\" class=\"w3-btn w3-light-grey\"><img src=\"/Icons/pencil.svg\">&nbsp;Q-Edit</a>\n<a href=\"javascript:window.close();\" class=\"w3-btn w3-light-grey\"><img src=\"/Icons/justify.svg\">&nbsp;zur&uuml;ck</a>\n\n</main>\n\n<script>\nfunction showIt(releaseType, print)\n{\n		let doctype = \"");
  responsebody += THttpUtility::htmlEscape(releaseMgmt.docType());
  responsebody += QStringLiteral("\";\n		if(doctype === 'annex')\n		{\n			if(releaseType === \"pre-release\" && print === true )\n			{\n				let form = document.getElementById(\"formid\");\n				form.setAttribute(\"action\", \"/annexdata/printCiAnnex?show\");\n				document.getElementById(\"prereleaseprint\").click();\n				return;\n			}\n			if(releaseType === \"pre-release\")\n			{\n				let form = document.getElementById(\"formid\");\n				form.setAttribute(\"action\", \"/annexdata/showCiAnnex?show\");\n				document.getElementById(\"prerelease\").click();\n			}\n			if(releaseType === \"showreleased\")\n			{\n				let form = document.getElementById(\"formid\");\n				form.setAttribute(\"action\", \"/releasemgmt/showCdAnnex?show\");\n				document.getElementById(\"showreleased\").click();\n			}\n			if(releaseType === \"printreleased\")\n			{\n				let form = document.getElementById(\"formid\");\n				form.setAttribute(\"action\", \"/releasemgmt/printCdAnnex?show\");\n				document.getElementById(\"printreleased\").click();\n			}\n		}\n		if(doctype === 'standard')\n		{\n			if(releaseType === \"pre-release\")\n			{\n				let form = document.getElementById(\"formid\");\n				form.setAttribute(\"action\", \"/standardsdata/showCiStd?show\");\n				document.getElementById(\"prerelease\").click();\n			}\n			if(releaseType === \"showreleased\")\n			{\n				let form = document.getElementById(\"formid\");\n				form.setAttribute(\"action\", \"/releasemgmt/showCdStd?show\");\n				document.getElementById(\"showreleased\").click();\n			}\n			if(releaseType === \"printreleased\")\n			{\n				let form = document.getElementById(\"formid\");\n				form.setAttribute(\"action\", \"/releasemgmt/printCdStd?show\");\n				document.getElementById(\"printreleased\").click();\n			}\n		}\n}\n\n</script>\n\n<itis-footer id=\"itisFooter\" message=\"\"></itis-footer>\n  \n</body>\n</html>\n");

  return responsebody;
}

T_DEFINE_VIEW(releasemgmt_showView)

#include "releasemgmt_showView.moc"
