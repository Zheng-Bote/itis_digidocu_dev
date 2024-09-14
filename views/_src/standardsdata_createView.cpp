#include <QtCore>
#include <TreeFrogView>
#include "standardsdata.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT standardsdata_createView : public TActionView
{
  Q_OBJECT
public:
  standardsdata_createView() : TActionView() { }
  QString toString();
};

QString standardsdata_createView::toString()
{
  responsebody.reserve(3733);
  responsebody += QStringLiteral("<!DOCTYPE html>\n");
    tfetch(QVariantMap, standardsData);
  responsebody += QStringLiteral("<html>\n<head>\n  <meta charset=\"UTF-8\">\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QStringLiteral("</title>\n</head>\n<body>\n\n<p id=\"redmsg\" style=\"color: red\">");
  techoex(red_msg);
  tehex(error);
  responsebody += QStringLiteral("</p><p id=\"greenmsg\" style=\"color: green\">");
  techoex(green_msg);
  tehex(notice);
  responsebody += QStringLiteral("</p>\n\n<h1>New Standards Data</h1>\n\n");
  responsebody += QVariant(formTag(urla("create"), Tf::Post)).toString();
  responsebody += QStringLiteral("\n  <p>\n    <label>Lfdnr<br /><input name=\"standardsData[lfdnr]\" value=\"");
  responsebody += THttpUtility::htmlEscape(standardsData["lfdnr"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Spec Title<br /><input name=\"standardsData[specTitle]\" value=\"");
  responsebody += THttpUtility::htmlEscape(standardsData["specTitle"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Spec Desc<br /><input name=\"standardsData[specDesc]\" value=\"");
  responsebody += THttpUtility::htmlEscape(standardsData["specDesc"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Spec Version<br /><input name=\"standardsData[specVersion]\" value=\"");
  responsebody += THttpUtility::htmlEscape(standardsData["specVersion"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Spec Release<br /><input name=\"standardsData[specRelease]\" value=\"");
  responsebody += THttpUtility::htmlEscape(standardsData["specRelease"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Obj Sname<br /><input name=\"standardsData[objSname]\" value=\"");
  responsebody += THttpUtility::htmlEscape(standardsData["objSname"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Ac Classes<br /><input name=\"standardsData[acClasses]\" value=\"");
  responsebody += THttpUtility::htmlEscape(standardsData["acClasses"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Pc Classes<br /><input name=\"standardsData[pcClasses]\" value=\"");
  responsebody += THttpUtility::htmlEscape(standardsData["pcClasses"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Cat Class<br /><input name=\"standardsData[catClass]\" value=\"");
  responsebody += THttpUtility::htmlEscape(standardsData["catClass"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Country<br /><input name=\"standardsData[country]\" value=\"");
  responsebody += THttpUtility::htmlEscape(standardsData["country"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Lang<br /><input name=\"standardsData[lang]\" value=\"");
  responsebody += THttpUtility::htmlEscape(standardsData["lang"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Spec Content<br /><input name=\"standardsData[specContent]\" value=\"");
  responsebody += THttpUtility::htmlEscape(standardsData["specContent"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Spec Active<br /><input name=\"standardsData[specActive]\" value=\"");
  responsebody += THttpUtility::htmlEscape(standardsData["specActive"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <input type=\"submit\" value=\"Create\" />\n  </p>\n</form>\n\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QStringLiteral("\n\n</body>\n</html>\n");

  return responsebody;
}

T_DEFINE_VIEW(standardsdata_createView)

#include "standardsdata_createView.moc"
