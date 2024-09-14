#include <QtCore>
#include <TreeFrogView>
#include "standardsmeta.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT standardsmeta_createView : public TActionView
{
  Q_OBJECT
public:
  standardsmeta_createView() : TActionView() { }
  QString toString();
};

QString standardsmeta_createView::toString()
{
  responsebody.reserve(3393);
  responsebody += QStringLiteral("<!DOCTYPE html>\n");
    tfetch(QVariantMap, standardsMeta);
  responsebody += QStringLiteral("<html>\n<head>\n  <meta charset=\"UTF-8\">\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QStringLiteral("</title>\n</head>\n<body>\n\n<p id=\"redmsg\" style=\"color: red\">");
  techoex(red_msg);
  tehex(error);
  responsebody += QStringLiteral("</p><p id=\"greenmsg\" style=\"color: green\">");
  techoex(green_msg);
  tehex(notice);
  responsebody += QStringLiteral("</p>\n\n<h1>New Standards Meta</h1>\n\n");
  responsebody += QVariant(formTag(urla("create"), Tf::Post)).toString();
  responsebody += QStringLiteral("\n  <p>\n    <label>Spec Data ID<br /><input name=\"standardsMeta[specDataId]\" value=\"");
  responsebody += THttpUtility::htmlEscape(standardsMeta["specDataId"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Spec Created<br /><input name=\"standardsMeta[specCreated]\" value=\"");
  responsebody += THttpUtility::htmlEscape(standardsMeta["specCreated"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Spec Last Modified<br /><input name=\"standardsMeta[specLastModified]\" value=\"");
  responsebody += THttpUtility::htmlEscape(standardsMeta["specLastModified"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Spec Valid Start<br /><input name=\"standardsMeta[specValidStart]\" value=\"");
  responsebody += THttpUtility::htmlEscape(standardsMeta["specValidStart"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Spec Valid End<br /><input name=\"standardsMeta[specValidEnd]\" value=\"");
  responsebody += THttpUtility::htmlEscape(standardsMeta["specValidEnd"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Last Editor<br /><input name=\"standardsMeta[lastEditor]\" value=\"");
  responsebody += THttpUtility::htmlEscape(standardsMeta["lastEditor"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>G Legacy<br /><input name=\"standardsMeta[gLegacy]\" value=\"");
  responsebody += THttpUtility::htmlEscape(standardsMeta["gLegacy"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Responsibility<br /><input name=\"standardsMeta[responsibility]\" value=\"");
  responsebody += THttpUtility::htmlEscape(standardsMeta["responsibility"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Spec Comment<br /><input name=\"standardsMeta[specComment]\" value=\"");
  responsebody += THttpUtility::htmlEscape(standardsMeta["specComment"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Spec Marker<br /><input name=\"standardsMeta[specMarker]\" value=\"");
  responsebody += THttpUtility::htmlEscape(standardsMeta["specMarker"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Groups<br /><input name=\"standardsMeta[groups]\" value=\"");
  responsebody += THttpUtility::htmlEscape(standardsMeta["groups"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <input type=\"submit\" value=\"Create\" />\n  </p>\n</form>\n\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QStringLiteral("\n\n</body>\n</html>\n");

  return responsebody;
}

T_DEFINE_VIEW(standardsmeta_createView)

#include "standardsmeta_createView.moc"
