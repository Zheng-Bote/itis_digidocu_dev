#ifndef INFORMATIONMAILER_H
#define INFORMATIONMAILER_H

#include <TActionMailer>


class InformationMailer : public TActionMailer
{
public:
    InformationMailer() { }
    void send();
    void crUser(const QString &username);
    void crUserPwd(const QString &username, const QString &userpwd);
    void infoUserPwd(const QString &username);
    void regUserAdmInfo(const QString &username);

    void preleaseInfo(const QString &username, const QString &id);
};

#endif // INFORMATIONMAILER_H
