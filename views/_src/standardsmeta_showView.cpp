#include <QtCore>
#include <TreeFrogView>
#include "standardsmeta.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT standardsmeta_showView : public TActionView
{
  Q_OBJECT
public:
  standardsmeta_showView() : TActionView() { }
  QString toString();
};

QString standardsmeta_showView::toString()
{
  responsebody.reserve(2669);
  responsebody += QStringLiteral("<!DOCTYPE html>\n");
    tfetch(StandardsMeta, standardsMeta);
  responsebody += QStringLiteral("<html>\n<head>\n  <meta charset=\"UTF-8\">\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QStringLiteral("</title>\n</head>\n<body>\n\n<p id=\"redmsg\" style=\"color: red\">");
  techoex(red_msg);
  tehex(error);
  responsebody += QStringLiteral("</p><p id=\"greenmsg\" style=\"color: green\">");
  techoex(green_msg);
  tehex(notice);
  responsebody += QStringLiteral("</p>\n\n<h1>Showing Standards Meta</h1>\n<dt>ID</dt><dd>");
  responsebody += THttpUtility::htmlEscape(standardsMeta.id());
  responsebody += QStringLiteral("</dd><br />\n<dt>Spec Data ID</dt><dd>");
  responsebody += THttpUtility::htmlEscape(standardsMeta.specDataId());
  responsebody += QStringLiteral("</dd><br />\n<dt>Spec Created</dt><dd>");
  responsebody += THttpUtility::htmlEscape(standardsMeta.specCreated());
  responsebody += QStringLiteral("</dd><br />\n<dt>Spec Last Modified</dt><dd>");
  responsebody += THttpUtility::htmlEscape(standardsMeta.specLastModified());
  responsebody += QStringLiteral("</dd><br />\n<dt>Spec Valid Start</dt><dd>");
  responsebody += THttpUtility::htmlEscape(standardsMeta.specValidStart());
  responsebody += QStringLiteral("</dd><br />\n<dt>Spec Valid End</dt><dd>");
  responsebody += THttpUtility::htmlEscape(standardsMeta.specValidEnd());
  responsebody += QStringLiteral("</dd><br />\n<dt>Last Editor</dt><dd>");
  responsebody += THttpUtility::htmlEscape(standardsMeta.lastEditor());
  responsebody += QStringLiteral("</dd><br />\n<dt>G Legacy</dt><dd>");
  responsebody += THttpUtility::htmlEscape(standardsMeta.gLegacy());
  responsebody += QStringLiteral("</dd><br />\n<dt>Responsibility</dt><dd>");
  responsebody += THttpUtility::htmlEscape(standardsMeta.responsibility());
  responsebody += QStringLiteral("</dd><br />\n<dt>Spec Comment</dt><dd>");
  responsebody += THttpUtility::htmlEscape(standardsMeta.specComment());
  responsebody += QStringLiteral("</dd><br />\n<dt>Spec Marker</dt><dd>");
  responsebody += THttpUtility::htmlEscape(standardsMeta.specMarker());
  responsebody += QStringLiteral("</dd><br />\n<dt>Groups</dt><dd>");
  responsebody += THttpUtility::htmlEscape(standardsMeta.groups());
  responsebody += QStringLiteral("</dd><br />\n\n");
  responsebody += QVariant(linkTo("Edit", urla("save", standardsMeta.id()))).toString();
  responsebody += QStringLiteral(" |\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QStringLiteral("\n\n</body>\n</html>\n");

  return responsebody;
}

T_DEFINE_VIEW(standardsmeta_showView)

#include "standardsmeta_showView.moc"
