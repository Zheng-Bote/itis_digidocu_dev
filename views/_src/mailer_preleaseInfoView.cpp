#include <QtCore>
#include <TreeFrogView>
#include "applicationhelper.h"

class T_VIEW_EXPORT mailer_preleaseInfoView : public TActionView
{
  Q_OBJECT
public:
  mailer_preleaseInfoView() : TActionView() { }
  QString toString();
};

QString mailer_preleaseInfoView::toString()
{
  responsebody.reserve(360);
  responsebody += QStringLiteral("Subject: ITIS Pre-Release\nTo: zheng.bote@googlemail.com\nFrom: zheng.bote@googlemail.com\n\nHello,\n");
  techoex(username);
  responsebody += QStringLiteral(" has sent a pre-release request with id: ");
  techoex(id);
  responsebody += QStringLiteral("\nPlease check and review asap.\nHave a nice day,\nZHENG Robert\n \n");

  return responsebody;
}

T_DEFINE_VIEW(mailer_preleaseInfoView)

#include "mailer_preleaseInfoView.moc"
