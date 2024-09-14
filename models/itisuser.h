#ifndef ITISUSER_H
#define ITISUSER_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractUser>
#include <TAbstractModel>

class TModelObject;
class ItisUserObject;
class QJsonArray;


class T_MODEL_EXPORT ItisUser : public TAbstractUser, public TAbstractModel
{
public:
    ItisUser();
    ItisUser(const ItisUser &other);
    ItisUser(const ItisUserObject &object);
    ~ItisUser();

    int id() const;
    QString username() const;
    void setUsername(const QString &username);
    QString firstname() const;
    void setFirstname(const QString &firstname);
    QString surname() const;
    void setSurname(const QString &surname);
    QString email() const;
    void setEmail(const QString &email);
    QString company() const;
    void setCompany(const QString &company);
    QString userTimezone() const;
    void setUserTimezone(const QString &userTimezone);
    QString groupname() const;
    void setGroupname(const QString &groupname);
    QString groups() const;
    void setGroups(const QString &groups);
    QByteArray password() const;
    void setPassword(const QByteArray &password);
    QDateTime lastLogin() const;
    void setLastLogin(const QDateTime &lastLogin);
    QDateTime loginTime() const;
    void setLoginTime(const QDateTime &loginTime);
    QDateTime loggedOut() const;
    void setLoggedOut(const QDateTime &loggedOut);
    QDateTime pwdChangedTime() const;
    void setPwdChangedTime(const QDateTime &pwdChangedTime);
    int pwdChangeForce() const;
    void setPwdChangeForce(int pwdChangeForce);
    int active() const;
    void setActive(int active);
    QString identityKey() const { return username(); }
    ItisUser &operator=(const ItisUser &other);

    bool create() { return TAbstractModel::create(); }
    bool update() { return TAbstractModel::update(); }
    bool save()   { return TAbstractModel::save(); }
    bool remove() { return TAbstractModel::remove(); }

    static bool isInGroup(const QString &usergroups, const QString &group);
    static bool isInGroups(const QString &usergroups, const QString &groups);
    static QString sqlGroups(QString strGroups);
    static QString sqlGroups(QString strGroups, QString crud);

    static ItisUser authenticate(const QString &username, const QString &password);
    static ItisUser create(const QString &username, const QString &firstname, const QString &surname, const QString &email, const QString &company, const QString &userTimezone, const QString &groupname, const QString &groups, const QString &password, const QDateTime &lastLogin, const QDateTime &loginTime, const QDateTime &loggedOut, const QDateTime &pwdChangedTime, int pwdChangeForce, int active);
    static ItisUser create(const QVariantMap &values);
    static ItisUser get(int id);
    static int count();
    static QList<ItisUser> getAll();
    static QJsonArray getAllJson();

    static ItisUser getByIdentityKey(const QString &username);

    static QJsonArray setUserPwd(const QString &username, const QString pwd);
    static QJsonArray setUserNewsCfg(const QString &username, const QString &newsletter);
    static QString getUserNewsCfg(const QString &username);

private:
    QSharedDataPointer<ItisUserObject> d;

    TModelObject *modelData();
    const TModelObject *modelData() const;
    friend QDataStream &operator<<(QDataStream &ds, const ItisUser &model);
    friend QDataStream &operator>>(QDataStream &ds, ItisUser &model);
};

Q_DECLARE_METATYPE(ItisUser)
Q_DECLARE_METATYPE(QList<ItisUser>)

#endif // ITISUSER_H
