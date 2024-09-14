#include <QtCore>
#include <TreeFrogView>
#include "stdsystem.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT stdsystem_showView : public TActionView
{
  Q_OBJECT
public:
  stdsystem_showView() : TActionView() { }
  QString toString();
};

QString stdsystem_showView::toString()
{
  responsebody.reserve(1818);
  responsebody += QStringLiteral("<!DOCTYPE html>\n");
    tfetch(StdSystem, stdSystem);
  responsebody += QStringLiteral("<html>\n<head>\n  <meta charset=\"UTF-8\">\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QStringLiteral("</title>\n</head>\n<body>\n\n<p id=\"redmsg\" style=\"color: red\">");
  techoex(red_msg);
  tehex(error);
  responsebody += QStringLiteral("</p><p id=\"greenmsg\" style=\"color: green\">");
  techoex(green_msg);
  tehex(notice);
  responsebody += QStringLiteral("</p>\n\n<h1>Showing Std System</h1>\n<dt>ID</dt><dd>");
  responsebody += THttpUtility::htmlEscape(stdSystem.id());
  responsebody += QStringLiteral("</dd><br />\n<dt>Std Type</dt><dd>");
  responsebody += THttpUtility::htmlEscape(stdSystem.stdType());
  responsebody += QStringLiteral("</dd><br />\n<dt>Std Attr</dt><dd>");
  responsebody += THttpUtility::htmlEscape(stdSystem.stdAttr());
  responsebody += QStringLiteral("</dd><br />\n<dt>Std Val</dt><dd>");
  responsebody += THttpUtility::htmlEscape(stdSystem.stdVal());
  responsebody += QStringLiteral("</dd><br />\n<dt>Std Flag</dt><dd>");
  responsebody += THttpUtility::htmlEscape(stdSystem.stdFlag());
  responsebody += QStringLiteral("</dd><br />\n<dt>Sort</dt><dd>");
  responsebody += THttpUtility::htmlEscape(stdSystem.sort());
  responsebody += QStringLiteral("</dd><br />\n<dt>Active</dt><dd>");
  responsebody += THttpUtility::htmlEscape(stdSystem.active());
  responsebody += QStringLiteral("</dd><br />\n\n");
  responsebody += QVariant(linkTo("Edit", urla("save", stdSystem.id()))).toString();
  responsebody += QStringLiteral(" |\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QStringLiteral("\n\n</body>\n</html>\n");

  return responsebody;
}

T_DEFINE_VIEW(stdsystem_showView)

#include "stdsystem_showView.moc"
