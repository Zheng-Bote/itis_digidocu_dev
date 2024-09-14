#include "informationmailer.h"


void InformationMailer::preleaseInfo(const QString &username, const QString &id)
{
    texport(username);
    texport(id);
    deliver("preleaseInfo");
}


void InformationMailer::send()
{
    QString to = "zb_bamboo@live.de";
    texport(to);
    deliver("mail");   // ← mail.erb Mail sent by template
}

void InformationMailer::crUser(const QString &username)
{
    texport(username);
    deliver("crUser");
}

void InformationMailer::crUserPwd(const QString &username, const QString &userpwd)
{
    texport(username);
    texport(userpwd);
    deliver("crUserPwd");
}

void InformationMailer::infoUserPwd(const QString &username)
{
    texport(username);
    deliver("infoUserPwd");
}

void InformationMailer::regUserAdmInfo(const QString &username)
{
    texport(username);
    deliver("regUserAdmInfo");
}
