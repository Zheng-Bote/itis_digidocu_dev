#include <QtCore>
#include <TreeFrogView>
#include "annexmeta.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT annexmeta_createView : public TActionView
{
  Q_OBJECT
public:
  annexmeta_createView() : TActionView() { }
  QString toString();
};

QString annexmeta_createView::toString()
{
  responsebody.reserve(3297);
  responsebody += QStringLiteral("<!DOCTYPE html>\n");
    tfetch(QVariantMap, annexMeta);
  responsebody += QStringLiteral("<html>\n<head>\n  <meta charset=\"UTF-8\">\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QStringLiteral("</title>\n</head>\n<body>\n\n<p id=\"redmsg\" style=\"color: red\">");
  techoex(red_msg);
  tehex(error);
  responsebody += QStringLiteral("</p><p id=\"greenmsg\" style=\"color: green\">");
  techoex(green_msg);
  tehex(notice);
  responsebody += QStringLiteral("</p>\n\n<h1>New Annex Meta</h1>\n\n");
  responsebody += QVariant(formTag(urla("create"), Tf::Post)).toString();
  responsebody += QStringLiteral("\n  <p>\n    <label>Spec Data ID<br /><input name=\"annexMeta[specDataId]\" value=\"");
  responsebody += THttpUtility::htmlEscape(annexMeta["specDataId"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Spec Created<br /><input name=\"annexMeta[specCreated]\" value=\"");
  responsebody += THttpUtility::htmlEscape(annexMeta["specCreated"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Spec Last Modified<br /><input name=\"annexMeta[specLastModified]\" value=\"");
  responsebody += THttpUtility::htmlEscape(annexMeta["specLastModified"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Spec Valid Start<br /><input name=\"annexMeta[specValidStart]\" value=\"");
  responsebody += THttpUtility::htmlEscape(annexMeta["specValidStart"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Spec Valid End<br /><input name=\"annexMeta[specValidEnd]\" value=\"");
  responsebody += THttpUtility::htmlEscape(annexMeta["specValidEnd"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Last Editor<br /><input name=\"annexMeta[lastEditor]\" value=\"");
  responsebody += THttpUtility::htmlEscape(annexMeta["lastEditor"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>G Legacy<br /><input name=\"annexMeta[gLegacy]\" value=\"");
  responsebody += THttpUtility::htmlEscape(annexMeta["gLegacy"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Responsibility<br /><input name=\"annexMeta[responsibility]\" value=\"");
  responsebody += THttpUtility::htmlEscape(annexMeta["responsibility"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Spec Comment<br /><input name=\"annexMeta[specComment]\" value=\"");
  responsebody += THttpUtility::htmlEscape(annexMeta["specComment"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Spec Marker<br /><input name=\"annexMeta[specMarker]\" value=\"");
  responsebody += THttpUtility::htmlEscape(annexMeta["specMarker"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Groups<br /><input name=\"annexMeta[groups]\" value=\"");
  responsebody += THttpUtility::htmlEscape(annexMeta["groups"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <input type=\"submit\" value=\"Create\" />\n  </p>\n</form>\n\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QStringLiteral("\n\n</body>\n</html>\n");

  return responsebody;
}

T_DEFINE_VIEW(annexmeta_createView)

#include "annexmeta_createView.moc"
