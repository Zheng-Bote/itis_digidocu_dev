#include <QtCore>
#include <TreeFrogView>
#include "applicationhelper.h"

class T_VIEW_EXPORT mailer_crUserPwdView : public TActionView
{
  Q_OBJECT
public:
  mailer_crUserPwdView() : TActionView() { }
  QString toString();
};

QString mailer_crUserPwdView::toString()
{
  responsebody.reserve(346);
  responsebody += QStringLiteral("Subject: ITIS Account\nTo: ");
  techoex(username);
  responsebody += QStringLiteral("\nFrom: zheng.bote@googlemail.com\n\nHello,\nyour initial password (key sensitive): ");
  techoex(userpwd);
  responsebody += QStringLiteral("\nPlease change your initial password asap.\nHave a nice day,\nZHENG Robert\n \n");

  return responsebody;
}

T_DEFINE_VIEW(mailer_crUserPwdView)

#include "mailer_crUserPwdView.moc"
