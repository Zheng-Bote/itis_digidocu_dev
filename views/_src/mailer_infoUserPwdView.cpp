#include <QtCore>
#include <TreeFrogView>
#include "applicationhelper.h"

class T_VIEW_EXPORT mailer_infoUserPwdView : public TActionView
{
  Q_OBJECT
public:
  mailer_infoUserPwdView() : TActionView() { }
  QString toString();
};

QString mailer_infoUserPwdView::toString()
{
  responsebody.reserve(320);
  responsebody += QStringLiteral("Subject: ITIS Account\nTo: ");
  techoex(username);
  responsebody += QStringLiteral("\nFrom: zheng.bote@googlemail.com\n\nHello,\nyour password has been changed.\nIf you have not made this change, please report this security breach immediately.\nHave a nice day,\nZHENG Robert\n \n");

  return responsebody;
}

T_DEFINE_VIEW(mailer_infoUserPwdView)

#include "mailer_infoUserPwdView.moc"
