#include <QtCore>
#include <TreeFrogView>
#include "annexdata.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT annexdata_createView : public TActionView
{
  Q_OBJECT
public:
  annexdata_createView() : TActionView() { }
  QString toString();
};

QString annexdata_createView::toString()
{
  responsebody.reserve(3621);
  responsebody += QStringLiteral("<!DOCTYPE html>\n");
    tfetch(QVariantMap, annexData);
  responsebody += QStringLiteral("<html>\n<head>\n  <meta charset=\"UTF-8\">\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QStringLiteral("</title>\n</head>\n<body>\n\n<p id=\"redmsg\" style=\"color: red\">");
  techoex(red_msg);
  tehex(error);
  responsebody += QStringLiteral("</p><p id=\"greenmsg\" style=\"color: green\">");
  techoex(green_msg);
  tehex(notice);
  responsebody += QStringLiteral("</p>\n\n<h1>New Annex Data</h1>\n\n");
  responsebody += QVariant(formTag(urla("create"), Tf::Post)).toString();
  responsebody += QStringLiteral("\n  <p>\n    <label>Lfdnr<br /><input name=\"annexData[lfdnr]\" value=\"");
  responsebody += THttpUtility::htmlEscape(annexData["lfdnr"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Spec Title<br /><input name=\"annexData[specTitle]\" value=\"");
  responsebody += THttpUtility::htmlEscape(annexData["specTitle"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Spec Desc<br /><input name=\"annexData[specDesc]\" value=\"");
  responsebody += THttpUtility::htmlEscape(annexData["specDesc"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Spec Version<br /><input name=\"annexData[specVersion]\" value=\"");
  responsebody += THttpUtility::htmlEscape(annexData["specVersion"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Spec Release<br /><input name=\"annexData[specRelease]\" value=\"");
  responsebody += THttpUtility::htmlEscape(annexData["specRelease"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Obj Sname<br /><input name=\"annexData[objSname]\" value=\"");
  responsebody += THttpUtility::htmlEscape(annexData["objSname"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Ac Classes<br /><input name=\"annexData[acClasses]\" value=\"");
  responsebody += THttpUtility::htmlEscape(annexData["acClasses"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Pc Classes<br /><input name=\"annexData[pcClasses]\" value=\"");
  responsebody += THttpUtility::htmlEscape(annexData["pcClasses"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Cat Class<br /><input name=\"annexData[catClass]\" value=\"");
  responsebody += THttpUtility::htmlEscape(annexData["catClass"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Country<br /><input name=\"annexData[country]\" value=\"");
  responsebody += THttpUtility::htmlEscape(annexData["country"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Lang<br /><input name=\"annexData[lang]\" value=\"");
  responsebody += THttpUtility::htmlEscape(annexData["lang"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Spec Content<br /><input name=\"annexData[specContent]\" value=\"");
  responsebody += THttpUtility::htmlEscape(annexData["specContent"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Spec Active<br /><input name=\"annexData[specActive]\" value=\"");
  responsebody += THttpUtility::htmlEscape(annexData["specActive"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <input type=\"submit\" value=\"Create\" />\n  </p>\n</form>\n\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QStringLiteral("\n\n</body>\n</html>\n");

  return responsebody;
}

T_DEFINE_VIEW(annexdata_createView)

#include "annexdata_createView.moc"
