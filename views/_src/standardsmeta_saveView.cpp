#include <QtCore>
#include <TreeFrogView>
#include "standardsmeta.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT standardsmeta_saveView : public TActionView
{
  Q_OBJECT
public:
  standardsmeta_saveView() : TActionView() { }
  QString toString();
};

QString standardsmeta_saveView::toString()
{
  responsebody.reserve(3928);
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
  responsebody += QStringLiteral("</p>\n\n<h1>Editing Standards Meta</h1>\n\n");
  responsebody += QVariant(formTag(urla("save", standardsMeta["id"]), Tf::Post)).toString();
  responsebody += QStringLiteral("\n  <p>\n    <label>ID<br /><input type=\"text\" name=\"standardsMeta[id]\" value=\"");
  responsebody += THttpUtility::htmlEscape(standardsMeta["id"]);
  responsebody += QStringLiteral("\" readonly=\"readonly\" /></label>\n  </p>\n  <p>\n    <label>Spec Data ID<br /><input type=\"text\" name=\"standardsMeta[specDataId]\" value=\"");
  responsebody += THttpUtility::htmlEscape(standardsMeta["specDataId"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Spec Created<br /><input type=\"text\" name=\"standardsMeta[specCreated]\" value=\"");
  responsebody += THttpUtility::htmlEscape(standardsMeta["specCreated"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Spec Last Modified<br /><input type=\"text\" name=\"standardsMeta[specLastModified]\" value=\"");
  responsebody += THttpUtility::htmlEscape(standardsMeta["specLastModified"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Spec Valid Start<br /><input type=\"text\" name=\"standardsMeta[specValidStart]\" value=\"");
  responsebody += THttpUtility::htmlEscape(standardsMeta["specValidStart"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Spec Valid End<br /><input type=\"text\" name=\"standardsMeta[specValidEnd]\" value=\"");
  responsebody += THttpUtility::htmlEscape(standardsMeta["specValidEnd"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Last Editor<br /><input type=\"text\" name=\"standardsMeta[lastEditor]\" value=\"");
  responsebody += THttpUtility::htmlEscape(standardsMeta["lastEditor"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>G Legacy<br /><input type=\"text\" name=\"standardsMeta[gLegacy]\" value=\"");
  responsebody += THttpUtility::htmlEscape(standardsMeta["gLegacy"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Responsibility<br /><input type=\"text\" name=\"standardsMeta[responsibility]\" value=\"");
  responsebody += THttpUtility::htmlEscape(standardsMeta["responsibility"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Spec Comment<br /><input type=\"text\" name=\"standardsMeta[specComment]\" value=\"");
  responsebody += THttpUtility::htmlEscape(standardsMeta["specComment"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Spec Marker<br /><input type=\"text\" name=\"standardsMeta[specMarker]\" value=\"");
  responsebody += THttpUtility::htmlEscape(standardsMeta["specMarker"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Groups<br /><input type=\"text\" name=\"standardsMeta[groups]\" value=\"");
  responsebody += THttpUtility::htmlEscape(standardsMeta["groups"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <input type=\"submit\" value=\"Save\" />\n  </p>\n</form>\n\n");
  responsebody += QVariant(linkTo("Show", urla("show", standardsMeta["id"]))).toString();
  responsebody += QStringLiteral(" |\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QStringLiteral("\n</body>\n</html>\n");

  return responsebody;
}

T_DEFINE_VIEW(standardsmeta_saveView)

#include "standardsmeta_saveView.moc"
