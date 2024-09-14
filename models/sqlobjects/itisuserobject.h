#ifndef ITISUSEROBJECT_H
#define ITISUSEROBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT ItisUserObject : public TSqlObject, public QSharedData
{
public:
    int id {0};
    QString username;
    QString firstname;
    QString surname;
    QString email;
    QString company;
    QString user_timezone;
    QString groupname;
    QString groups;
    QByteArray password;
    QDateTime last_login;
    QDateTime login_time;
    QDateTime logged_out;
    QDateTime pwd_changed_time;
    int pwd_change_force {0};
    int active {0};

    enum PropertyIndex {
        Id = 0,
        Username,
        Firstname,
        Surname,
        Email,
        Company,
        UserTimezone,
        Groupname,
        Groups,
        Password,
        LastLogin,
        LoginTime,
        LoggedOut,
        PwdChangedTime,
        PwdChangeForce,
        Active,
    };

    int primaryKeyIndex() const override { return Id; }
    int autoValueIndex() const override { return Id; }
    QString tableName() const override { return QStringLiteral("itis_user"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int id READ getid WRITE setid)
    T_DEFINE_PROPERTY(int, id)
    Q_PROPERTY(QString username READ getusername WRITE setusername)
    T_DEFINE_PROPERTY(QString, username)
    Q_PROPERTY(QString firstname READ getfirstname WRITE setfirstname)
    T_DEFINE_PROPERTY(QString, firstname)
    Q_PROPERTY(QString surname READ getsurname WRITE setsurname)
    T_DEFINE_PROPERTY(QString, surname)
    Q_PROPERTY(QString email READ getemail WRITE setemail)
    T_DEFINE_PROPERTY(QString, email)
    Q_PROPERTY(QString company READ getcompany WRITE setcompany)
    T_DEFINE_PROPERTY(QString, company)
    Q_PROPERTY(QString user_timezone READ getuser_timezone WRITE setuser_timezone)
    T_DEFINE_PROPERTY(QString, user_timezone)
    Q_PROPERTY(QString groupname READ getgroupname WRITE setgroupname)
    T_DEFINE_PROPERTY(QString, groupname)
    Q_PROPERTY(QString groups READ getgroups WRITE setgroups)
    T_DEFINE_PROPERTY(QString, groups)
    Q_PROPERTY(QByteArray password READ getpassword WRITE setpassword)
    T_DEFINE_PROPERTY(QByteArray, password)
    Q_PROPERTY(QDateTime last_login READ getlast_login WRITE setlast_login)
    T_DEFINE_PROPERTY(QDateTime, last_login)
    Q_PROPERTY(QDateTime login_time READ getlogin_time WRITE setlogin_time)
    T_DEFINE_PROPERTY(QDateTime, login_time)
    Q_PROPERTY(QDateTime logged_out READ getlogged_out WRITE setlogged_out)
    T_DEFINE_PROPERTY(QDateTime, logged_out)
    Q_PROPERTY(QDateTime pwd_changed_time READ getpwd_changed_time WRITE setpwd_changed_time)
    T_DEFINE_PROPERTY(QDateTime, pwd_changed_time)
    Q_PROPERTY(int pwd_change_force READ getpwd_change_force WRITE setpwd_change_force)
    T_DEFINE_PROPERTY(int, pwd_change_force)
    Q_PROPERTY(int active READ getactive WRITE setactive)
    T_DEFINE_PROPERTY(int, active)
};

#endif // ITISUSEROBJECT_H
