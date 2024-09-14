#include <QtCore>
#include <TreeFrogView>
#include "stdsystem.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT stdsystem_saveView : public TActionView
{
  Q_OBJECT
public:
  stdsystem_saveView() : TActionView() { }
  QString toString();
};

QString stdsystem_saveView::toString()
{
  responsebody.reserve(2585);
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
  responsebody += QStringLiteral("</p>\n\n<h1>Editing Std System</h1>\n\n");
  responsebody += QVariant(formTag(urla("save", stdSystem["id"]), Tf::Post)).toString();
  responsebody += QStringLiteral("\n  <p>\n    <label>ID<br /><input type=\"text\" name=\"stdSystem[id]\" value=\"");
  responsebody += THttpUtility::htmlEscape(stdSystem["id"]);
  responsebody += QStringLiteral("\" readonly=\"readonly\" /></label>\n  </p>\n  <p>\n    <label>Std Type<br /><input type=\"text\" name=\"stdSystem[stdType]\" value=\"");
  responsebody += THttpUtility::htmlEscape(stdSystem["stdType"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Std Attr<br /><input type=\"text\" name=\"stdSystem[stdAttr]\" value=\"");
  responsebody += THttpUtility::htmlEscape(stdSystem["stdAttr"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Std Val<br /><input type=\"text\" name=\"stdSystem[stdVal]\" value=\"");
  responsebody += THttpUtility::htmlEscape(stdSystem["stdVal"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Std Flag<br /><input type=\"text\" name=\"stdSystem[stdFlag]\" value=\"");
  responsebody += THttpUtility::htmlEscape(stdSystem["stdFlag"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Sort<br /><input type=\"text\" name=\"stdSystem[sort]\" value=\"");
  responsebody += THttpUtility::htmlEscape(stdSystem["sort"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Active<br /><input type=\"text\" name=\"stdSystem[active]\" value=\"");
  responsebody += THttpUtility::htmlEscape(stdSystem["active"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <input type=\"submit\" value=\"Save\" />\n  </p>\n</form>\n\n");
  responsebody += QVariant(linkTo("Show", urla("show", stdSystem["id"]))).toString();
  responsebody += QStringLiteral(" |\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QStringLiteral("\n</body>\n</html>\n");

  return responsebody;
}

T_DEFINE_VIEW(stdsystem_saveView)

#include "stdsystem_saveView.moc"
