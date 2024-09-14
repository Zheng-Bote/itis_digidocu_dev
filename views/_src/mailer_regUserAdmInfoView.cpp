#include <QtCore>
#include <TreeFrogView>
#include "applicationhelper.h"

class T_VIEW_EXPORT mailer_regUserAdmInfoView : public TActionView
{
  Q_OBJECT
public:
  mailer_regUserAdmInfoView() : TActionView() { }
  QString toString();
};

QString mailer_regUserAdmInfoView::toString()
{
  responsebody.reserve(313);
  responsebody += QStringLiteral("Subject: ITIS Account\nTo: zheng.bote@googlemail.com\nFrom: zheng.bote@googlemail.com\n\nHello,\nan User Registration request for you: ");
  techoex(username);
  responsebody += QStringLiteral(" for itis.hitchhiker.tech has been created.\nHave a nice day,\nZHENG Robert\n  \n");

  return responsebody;
}

T_DEFINE_VIEW(mailer_regUserAdmInfoView)

#include "mailer_regUserAdmInfoView.moc"
