#include <QtCore>
#include <TreeFrogView>
#include "applicationhelper.h"

class T_VIEW_EXPORT mailer_mailView : public TActionView
{
  Q_OBJECT
public:
  mailer_mailView() : TActionView() { }
  QString toString();
};

QString mailer_mailView::toString()
{
  responsebody.reserve(179);
  responsebody += QStringLiteral("Subject: Test Mail\nTo: ");
  techoex(to);
  responsebody += QStringLiteral("\nFrom: zheng.bote@googlemail.com\n\nHi,\nThis is a test mail.\n");

  return responsebody;
}

T_DEFINE_VIEW(mailer_mailView)

#include "mailer_mailView.moc"
