#ifndef LENKINFOOBJECT_H
#define LENKINFOOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT LenkinfoObject : public TSqlObject, public QSharedData
{
public:
    int id {0};
    QString spec_obj;
    QString spec_title;
    int ac_class {0};
    int pc_class {0};
    QString country;
    QString lang;
    QString lenk_version;
    QString lenk_status;
    QDateTime lenk_valid_startdate;
    QString lenk_departments;
    QString lenk_content;
    QString lenk_creator;
    QDateTime lenk_creator_date;
    QString lenk_auditor;
    QDateTime lenk_auditor_date;
    QString lenk_approver;
    QDateTime lenk_approver_date;

    enum PropertyIndex {
        Id = 0,
        SpecObj,
        SpecTitle,
        AcClass,
        PcClass,
        Country,
        Lang,
        LenkVersion,
        LenkStatus,
        LenkValidStartdate,
        LenkDepartments,
        LenkContent,
        LenkCreator,
        LenkCreatorDate,
        LenkAuditor,
        LenkAuditorDate,
        LenkApprover,
        LenkApproverDate,
    };

    int primaryKeyIndex() const override { return Id; }
    int autoValueIndex() const override { return Id; }
    QString tableName() const override { return QStringLiteral("lenkinfo"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int id READ getid WRITE setid)
    T_DEFINE_PROPERTY(int, id)
    Q_PROPERTY(QString spec_obj READ getspec_obj WRITE setspec_obj)
    T_DEFINE_PROPERTY(QString, spec_obj)
    Q_PROPERTY(QString spec_title READ getspec_title WRITE setspec_title)
    T_DEFINE_PROPERTY(QString, spec_title)
    Q_PROPERTY(int ac_class READ getac_class WRITE setac_class)
    T_DEFINE_PROPERTY(int, ac_class)
    Q_PROPERTY(int pc_class READ getpc_class WRITE setpc_class)
    T_DEFINE_PROPERTY(int, pc_class)
    Q_PROPERTY(QString country READ getcountry WRITE setcountry)
    T_DEFINE_PROPERTY(QString, country)
    Q_PROPERTY(QString lang READ getlang WRITE setlang)
    T_DEFINE_PROPERTY(QString, lang)
    Q_PROPERTY(QString lenk_version READ getlenk_version WRITE setlenk_version)
    T_DEFINE_PROPERTY(QString, lenk_version)
    Q_PROPERTY(QString lenk_status READ getlenk_status WRITE setlenk_status)
    T_DEFINE_PROPERTY(QString, lenk_status)
    Q_PROPERTY(QDateTime lenk_valid_startdate READ getlenk_valid_startdate WRITE setlenk_valid_startdate)
    T_DEFINE_PROPERTY(QDateTime, lenk_valid_startdate)
    Q_PROPERTY(QString lenk_departments READ getlenk_departments WRITE setlenk_departments)
    T_DEFINE_PROPERTY(QString, lenk_departments)
    Q_PROPERTY(QString lenk_content READ getlenk_content WRITE setlenk_content)
    T_DEFINE_PROPERTY(QString, lenk_content)
    Q_PROPERTY(QString lenk_creator READ getlenk_creator WRITE setlenk_creator)
    T_DEFINE_PROPERTY(QString, lenk_creator)
    Q_PROPERTY(QDateTime lenk_creator_date READ getlenk_creator_date WRITE setlenk_creator_date)
    T_DEFINE_PROPERTY(QDateTime, lenk_creator_date)
    Q_PROPERTY(QString lenk_auditor READ getlenk_auditor WRITE setlenk_auditor)
    T_DEFINE_PROPERTY(QString, lenk_auditor)
    Q_PROPERTY(QDateTime lenk_auditor_date READ getlenk_auditor_date WRITE setlenk_auditor_date)
    T_DEFINE_PROPERTY(QDateTime, lenk_auditor_date)
    Q_PROPERTY(QString lenk_approver READ getlenk_approver WRITE setlenk_approver)
    T_DEFINE_PROPERTY(QString, lenk_approver)
    Q_PROPERTY(QDateTime lenk_approver_date READ getlenk_approver_date WRITE setlenk_approver_date)
    T_DEFINE_PROPERTY(QDateTime, lenk_approver_date)
};

#endif // LENKINFOOBJECT_H
