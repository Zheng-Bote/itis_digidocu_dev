#include <QtCore>
#include <TreeFrogView>
#include "stdsystem.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT stdsystem_createView : public TActionView
{
  Q_OBJECT
public:
  stdsystem_createView() : TActionView() { }
  QString toString();
};

QString stdsystem_createView::toString()
{
  responsebody.reserve(2136);
  responsebody += QStringLiteral("<!DOCTYPE html>\n");
    tfetch(QVariantMap, stdSystem);
  responsebody += QStringLiteral("<html>\n<head>\n  <meta charset=\"UTF-8\">\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QStringLiteral("</title>\n</head>\n<body>\n\n<p id=\"redmsg\" style=\"color: red\">");
  techoex(red_msg);
  tehex(error);
  responsebody += QStringLiteral("</p><p id=\"greenmsg\" style=\"color: green\">");
  techoex(green_msg);
  tehex(notice);
  responsebody += QStringLiteral("</p>\n\n<h1>New Std System</h1>\n\n");
  responsebody += QVariant(formTag(urla("create"), Tf::Post)).toString();
  responsebody += QStringLiteral("\n  <p>\n    <label>Std Type<br /><input name=\"stdSystem[stdType]\" value=\"");
  responsebody += THttpUtility::htmlEscape(stdSystem["stdType"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Std Attr<br /><input name=\"stdSystem[stdAttr]\" value=\"");
  responsebody += THttpUtility::htmlEscape(stdSystem["stdAttr"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Std Val<br /><input name=\"stdSystem[stdVal]\" value=\"");
  responsebody += THttpUtility::htmlEscape(stdSystem["stdVal"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Std Flag<br /><input name=\"stdSystem[stdFlag]\" value=\"");
  responsebody += THttpUtility::htmlEscape(stdSystem["stdFlag"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Sort<br /><input name=\"stdSystem[sort]\" value=\"");
  responsebody += THttpUtility::htmlEscape(stdSystem["sort"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Active<br /><input name=\"stdSystem[active]\" value=\"");
  responsebody += THttpUtility::htmlEscape(stdSystem["active"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <input type=\"submit\" value=\"Create\" />\n  </p>\n</form>\n\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QStringLiteral("\n\n</body>\n</html>\n");

  return responsebody;
}

T_DEFINE_VIEW(stdsystem_createView)

#include "stdsystem_createView.moc"
