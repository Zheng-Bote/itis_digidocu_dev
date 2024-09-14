#include <QtCore>
#include <TreeFrogView>
#include "annexmeta.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT annexmeta_showView : public TActionView
{
  Q_OBJECT
public:
  annexmeta_showView() : TActionView() { }
  QString toString();
};

QString annexmeta_showView::toString()
{
  responsebody.reserve(2606);
  responsebody += QStringLiteral("<!DOCTYPE html>\n");
    tfetch(AnnexMeta, annexMeta);
  responsebody += QStringLiteral("<html>\n<head>\n  <meta charset=\"UTF-8\">\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QStringLiteral("</title>\n</head>\n<body>\n	\n<p id=\"redmsg\" style=\"color: red\">");
  techoex(red_msg);
  tehex(error);
  responsebody += QStringLiteral("</p><p id=\"greenmsg\" style=\"color: green\">");
  techoex(green_msg);
  tehex(notice);
  responsebody += QStringLiteral("</p>\n\n<h1>Showing Annex Meta</h1>\n<dt>ID</dt><dd>");
  responsebody += THttpUtility::htmlEscape(annexMeta.id());
  responsebody += QStringLiteral("</dd><br />\n<dt>Spec Data ID</dt><dd>");
  responsebody += THttpUtility::htmlEscape(annexMeta.specDataId());
  responsebody += QStringLiteral("</dd><br />\n<dt>Spec Created</dt><dd>");
  responsebody += THttpUtility::htmlEscape(annexMeta.specCreated());
  responsebody += QStringLiteral("</dd><br />\n<dt>Spec Last Modified</dt><dd>");
  responsebody += THttpUtility::htmlEscape(annexMeta.specLastModified());
  responsebody += QStringLiteral("</dd><br />\n<dt>Spec Valid Start</dt><dd>");
  responsebody += THttpUtility::htmlEscape(annexMeta.specValidStart());
  responsebody += QStringLiteral("</dd><br />\n<dt>Spec Valid End</dt><dd>");
  responsebody += THttpUtility::htmlEscape(annexMeta.specValidEnd());
  responsebody += QStringLiteral("</dd><br />\n<dt>Last Editor</dt><dd>");
  responsebody += THttpUtility::htmlEscape(annexMeta.lastEditor());
  responsebody += QStringLiteral("</dd><br />\n<dt>G Legacy</dt><dd>");
  responsebody += THttpUtility::htmlEscape(annexMeta.gLegacy());
  responsebody += QStringLiteral("</dd><br />\n<dt>Responsibility</dt><dd>");
  responsebody += THttpUtility::htmlEscape(annexMeta.responsibility());
  responsebody += QStringLiteral("</dd><br />\n<dt>Spec Comment</dt><dd>");
  responsebody += THttpUtility::htmlEscape(annexMeta.specComment());
  responsebody += QStringLiteral("</dd><br />\n<dt>Spec Marker</dt><dd>");
  responsebody += THttpUtility::htmlEscape(annexMeta.specMarker());
  responsebody += QStringLiteral("</dd><br />\n<dt>Groups</dt><dd>");
  responsebody += THttpUtility::htmlEscape(annexMeta.groups());
  responsebody += QStringLiteral("</dd><br />\n\n");
  responsebody += QVariant(linkTo("Edit", urla("save", annexMeta.id()))).toString();
  responsebody += QStringLiteral(" |\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QStringLiteral("\n\n</body>\n</html>\n");

  return responsebody;
}

T_DEFINE_VIEW(annexmeta_showView)

#include "annexmeta_showView.moc"
