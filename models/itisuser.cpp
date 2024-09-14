#include <TreeFrogModel>
#include "itisuser.h"
#include "sqlobjects/itisuserobject.h"

ItisUser::ItisUser() :
    TAbstractUser(),
    TAbstractModel(),
    d(new ItisUserObject())
{
    // set the initial parameters
}

ItisUser::ItisUser(const ItisUser &other) :
    TAbstractUser(),
    TAbstractModel(),
    d(other.d)
{ }

ItisUser::ItisUser(const ItisUserObject &object) :
    TAbstractUser(),
    TAbstractModel(),
    d(new ItisUserObject(object))
{ }


ItisUser::~ItisUser()
{
    // If the reference count becomes 0,
    // the shared data object 'ItisUserObject' is deleted.
}

// #####

QJsonArray ItisUser::setUserNewsCfg(const QString &username, const QString &newsletter)
{
    TSqlQuery query;
    QString msg;
    QJsonObject jsonObj;
    QJsonArray jsonArray;

    query.prepare("UPDATE public.itis_user SET newsletter=(:news) WHERE username=(:username)");
    query.bindValue(":news", newsletter);
    query.bindValue(":username",username);

    if(!query.exec())
    {
        msg = query.lastError().text();
        jsonObj["ERROR"] = "1";
        jsonObj["errMsg"] = msg;
        tError("setUserPwd " + msg.toUtf8());
    }
    else
    {
        jsonObj["ERROR"] = "0";
        jsonObj["errMsg"] = "Newsletter config modified";
    }

    jsonArray.append(jsonObj);
    return jsonArray;
}

QString ItisUser::getUserNewsCfg(const QString &username)
{
    TSqlQuery query;

    query.prepare("SELECT newsletter FROM public.itis_user WHERE username=(:username)");
    query.bindValue(":username",username);
    query.exec();
    query.next();

    return query.value(0).toString();
}

QJsonArray ItisUser::setUserPwd(const QString &username, const QString pwd)
{
    TSqlQuery query;
    QString msg;
    QJsonObject jsonObj;
    QJsonArray jsonArray;

    tInfo("setUserPwd " + username.toUtf8());
    QByteArray hash = QCryptographicHash::hash(pwd.toLocal8Bit(), QCryptographicHash::Sha256);

    query.prepare("UPDATE public.itis_user SET password=(:pwd), pwd_changed_time=(:pwd_changed_time), pwd_change_force = 0 WHERE username=(:username)");
    query.bindValue(":pwd", hash);
    query.bindValue(":pwd_changed_time",QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss"));
    query.bindValue(":username",username);

    if(!query.exec())
    {
        msg = query.lastError().text();
        jsonObj["ERROR"] = "1";
        jsonObj["errMsg"] = msg;
        tError("setUserPwd " + msg.toUtf8());
    }
    else
    {
        jsonObj["ERROR"] = "0";
        jsonObj["errMsg"] = "Passwort aktualisiert";
    }

    jsonArray.append(jsonObj);
    return jsonArray;
}

QString ItisUser::sqlGroups(QString strGroups, QString crud)
{
    strGroups.replace("{", "");
    strGroups.replace("}", "");
    QStringList groups = strGroups.split(",");

    QString andStr;

    int i = 0;
    do
    {
        if(i == 0)
        {
            andStr.append("(array_to_string(groups, ',') like '%" + groups[i] + ":%" + crud + "%'");
        }
        else
        {
            andStr.append(" OR array_to_string(groups, ',') like '%" + groups[i] + ":%" + crud + "%'");
        }
        i++;
    }while(i < groups.size());
    andStr.append(")");

    return andStr;
}

QString ItisUser::sqlGroups(QString strGroups)
{
    strGroups.replace("{", "");
    strGroups.replace("}", "");
    QStringList groups = strGroups.split(",");

    QString andStr;

    int i = 0;
    do
    {
        if(i == 0)
        {
            andStr.append("('" + groups[i] + "' = ANY (groups)");
        }
        else
        {
            andStr.append(" OR '" + groups[i] + "' = ANY (groups)");
        }
        i++;
    }while(i < groups.size());
    andStr.append(")");

    return andStr;
}

/*!
 * \brief ItisUser::isInGroup
 * \param userGroups
 * \param group
 * \return bool
 * Description: ckecks if the given group is included in groups
 * Example: bool isgroupmember = ItisUser::isInGroup(user.groups(), group);
 * Example: bool groupmember = ItisUser::isInGroup("{ALL,BMW,Portal-Admin}", "VW");
 */
bool ItisUser::isInGroup(const QString &userGroups, const QString &group)
{
    QString user_groups = userGroups;
    user_groups.replace("{", "").replace("}", "");
    QStringList groups = user_groups.split(",");

    //auto conti = TActionController::name(); auto con = TActionController::activeAction();

    return groups.contains(group, Qt::CaseInsensitive);
}

bool ItisUser::isInGroups(const QString &userGroups, const QString &groups)
{
    QString user_groups = userGroups;
    user_groups.replace("{", "").replace("}", "");
    QStringList usergroups = user_groups.split(",");

    QString right_groups = groups;
    right_groups.replace("{", "").replace("}", "");
    QStringList rightgroups = right_groups.split(",");

    for(int i = 0; i < rightgroups.size(); i++)
    {
        return usergroups.contains(rightgroups[i], Qt::CaseInsensitive);
    }
    return false;
}

ItisUser ItisUser::getByIdentityKey(const QString &username)
{
    TSqlORMapper<ItisUserObject> mapper;
    TCriteria cri(ItisUserObject::Username, username);
    return ItisUser(mapper.findFirst(cri));
}

int ItisUser::id() const
{
    return d->id;
}

QString ItisUser::username() const
{
    return d->username;
}

void ItisUser::setUsername(const QString &username)
{
    d->username = username;
}

QString ItisUser::firstname() const
{
    return d->firstname;
}

void ItisUser::setFirstname(const QString &firstname)
{
    d->firstname = firstname;
}

QString ItisUser::surname() const
{
    return d->surname;
}

void ItisUser::setSurname(const QString &surname)
{
    d->surname = surname;
}

QString ItisUser::email() const
{
    return d->email;
}

void ItisUser::setEmail(const QString &email)
{
    d->email = email;
}

QString ItisUser::company() const
{
    return d->company;
}

void ItisUser::setCompany(const QString &company)
{
    d->company = company;
}

QString ItisUser::userTimezone() const
{
    return d->user_timezone;
}

void ItisUser::setUserTimezone(const QString &userTimezone)
{
    d->user_timezone = userTimezone;
}

QString ItisUser::groupname() const
{
    return d->groupname;
}

void ItisUser::setGroupname(const QString &groupname)
{
    d->groupname = groupname;
}

QString ItisUser::groups() const
{
    return d->groups;
}

void ItisUser::setGroups(const QString &groups)
{
    d->groups = groups;
}

QByteArray ItisUser::password() const
{
    return d->password;
}

void ItisUser::setPassword(const QByteArray &password)
{
    d->password = password;
}

QDateTime ItisUser::lastLogin() const
{
    return d->last_login;
}

void ItisUser::setLastLogin(const QDateTime &lastLogin)
{
    d->last_login = lastLogin;
}

QDateTime ItisUser::loginTime() const
{
    return d->login_time;
}

void ItisUser::setLoginTime(const QDateTime &loginTime)
{
    TSqlQuery query;

    query.prepare("SELECT login_time from itis_user where username=(:user)");
    query.bindValue(":user",d->username);

    query.exec();
    query.next();
    QString last_login = query.value(0).toString();

    query.prepare("UPDATE itis_user SET last_login=(:lastlogin), login_time=(:logintime) WHERE username=(:user)");
    query.bindValue(":lastlogin", last_login);
    query.bindValue(":user", d->username);
    query.bindValue(":logintime", loginTime);

    query.exec();

    d->login_time = loginTime;
}

QDateTime ItisUser::loggedOut() const
{
    return d->logged_out;
}

void ItisUser::setLoggedOut(const QDateTime &loggedOut)
{
    TSqlQuery query;

    query.prepare("UPDATE itis_user SET logged_out=(:outime) WHERE username=(:user)");
    query.bindValue(":outime", QDateTime::currentDateTime());
    query.bindValue(":user", d->username);

    query.exec();

    d->logged_out = loggedOut;
}

QDateTime ItisUser::pwdChangedTime() const
{
    return d->pwd_changed_time;
}

void ItisUser::setPwdChangedTime(const QDateTime &pwdChangedTime)
{
    d->pwd_changed_time = pwdChangedTime;
}

int ItisUser::pwdChangeForce() const
{
    return d->pwd_change_force;
}

void ItisUser::setPwdChangeForce(int pwdChangeForce)
{
    d->pwd_change_force = pwdChangeForce;
}

int ItisUser::active() const
{
    return d->active;
}

void ItisUser::setActive(int active)
{
    d->active = active;
}

ItisUser &ItisUser::operator=(const ItisUser &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

ItisUser ItisUser::authenticate(const QString &username, const QString &password)
{
    if (username.isEmpty() || password.isEmpty())
        return ItisUser();

    TSqlORMapper<ItisUserObject> mapper;
    ItisUserObject obj = mapper.findFirst(TCriteria(ItisUserObject::Username, username));
    if (obj.isNull() || obj.password != password) {
        obj.clear();
    }
    return ItisUser(obj);
}

ItisUser ItisUser::create(const QString &username, const QString &firstname, const QString &surname, const QString &email, const QString &company, const QString &userTimezone, const QString &groupname, const QString &groups, const QString &pwd, const QDateTime &lastLogin, const QDateTime &loginTime, const QDateTime &loggedOut, const QDateTime &pwdChangedTime, int pwdChangeForce, int active)
{
    QByteArray hash = QCryptographicHash::hash(pwd.toLocal8Bit(), QCryptographicHash::Sha256);

    ItisUserObject obj;
    obj.username = username;
    obj.firstname = firstname;
    obj.surname = surname;
    obj.email = email;
    obj.company = company;
    obj.user_timezone = userTimezone;
    obj.groupname = groupname;
    obj.groups = groups;
    obj.password = hash;
    obj.last_login = lastLogin;
    obj.login_time = loginTime;
    obj.logged_out = loggedOut;
    obj.pwd_changed_time = pwdChangedTime;
    obj.pwd_change_force = pwdChangeForce;
    obj.active = active;
    if (!obj.create()) {
        return ItisUser();
    }
    return ItisUser(obj);
}

ItisUser ItisUser::create(const QVariantMap &values)
{
    QString pwd = values.value("password").toString();
    QByteArray hash = QCryptographicHash::hash(pwd.toLocal8Bit(), QCryptographicHash::Sha256);

    ItisUser model;
    model.setProperties(values);

    model.setPassword(hash);

    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

ItisUser ItisUser::get(int id)
{
    TSqlORMapper<ItisUserObject> mapper;
    return ItisUser(mapper.findByPrimaryKey(id));
}

int ItisUser::count()
{
    TSqlORMapper<ItisUserObject> mapper;
    return mapper.findCount();
}

QList<ItisUser> ItisUser::getAll()
{
    return tfGetModelListByCriteria<ItisUser, ItisUserObject>();
}

QJsonArray ItisUser::getAllJson()
{
    QJsonArray array;
    TSqlORMapper<ItisUserObject> mapper;

    if (mapper.find() > 0) {
        for (TSqlORMapperIterator<ItisUserObject> i(mapper); i.hasNext(); ) {
            array.append(QJsonValue(QJsonObject::fromVariantMap(ItisUser(i.next()).toVariantMap())));
        }
    }
    return array;
}

TModelObject *ItisUser::modelData()
{
    return d.data();
}

const TModelObject *ItisUser::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const ItisUser &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, ItisUser &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(ItisUser)
