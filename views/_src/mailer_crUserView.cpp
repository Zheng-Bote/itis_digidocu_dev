#include <QtCore>
#include <TreeFrogView>
#include "applicationhelper.h"

class T_VIEW_EXPORT mailer_crUserView : public TActionView
{
  Q_OBJECT
public:
  mailer_crUserView() : TActionView() { }
  QString toString();
};

QString mailer_crUserView::toString()
{
  responsebody.reserve(380);
  responsebody += QStringLiteral("Subject: ITIS Account\nTo: ");
  techoex(username);
  responsebody += QStringLiteral("\nFrom: zheng.bote@googlemail.com\n\nHello,\nyour account ");
  techoex(username);
  responsebody += QStringLiteral(" for itis.hitchhiker.tech has been created.\nAn additional eMail with your password will coming soon.\nHave a nice day,\nZHENG Robert\n  \n");

  return responsebody;
}

T_DEFINE_VIEW(mailer_crUserView)

#include "mailer_crUserView.moc"
