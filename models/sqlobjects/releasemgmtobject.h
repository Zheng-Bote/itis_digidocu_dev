#ifndef RELEASEMGMTOBJECT_H
#define RELEASEMGMTOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT ReleaseMgmtObject : public TSqlObject, public QSharedData
{
public:
    int id {0};
    QString obj_sname;
    QString spec_version;
    QString ac_classes;
    QString pc_classes;
    QString cat_class;
    QString country;
    QString lang;
    QString doc_type;
    QString rel_requester;
    QDateTime relrequest_date;
    QString rel_creator;
    QDateTime relcreator_decisdate;
    QString rel_inspector;
    QDateTime relinspect_decisdate;
    QString rel_approver;
    QDateTime relapprov_decisdate;
    QDateTime ci_date;
    QDateTime cd_date;
    QDateTime cdd_date;

    enum PropertyIndex {
        Id = 0,
        ObjSname,
        SpecVersion,
        AcClasses,
        PcClasses,
        CatClass,
        Country,
        Lang,
        DocType,
        RelRequester,
        RelrequestDate,
        RelCreator,
        RelcreatorDecisdate,
        RelInspector,
        RelinspectDecisdate,
        RelApprover,
        RelapprovDecisdate,
        CiDate,
        CdDate,
        CddDate,
    };

    int primaryKeyIndex() const override { return Id; }
    int autoValueIndex() const override { return Id; }
    QString tableName() const override { return QStringLiteral("release_mgmt"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int id READ getid WRITE setid)
    T_DEFINE_PROPERTY(int, id)
    Q_PROPERTY(QString obj_sname READ getobj_sname WRITE setobj_sname)
    T_DEFINE_PROPERTY(QString, obj_sname)
    Q_PROPERTY(QString spec_version READ getspec_version WRITE setspec_version)
    T_DEFINE_PROPERTY(QString, spec_version)
    Q_PROPERTY(QString ac_classes READ getac_classes WRITE setac_classes)
    T_DEFINE_PROPERTY(QString, ac_classes)
    Q_PROPERTY(QString pc_classes READ getpc_classes WRITE setpc_classes)
    T_DEFINE_PROPERTY(QString, pc_classes)
    Q_PROPERTY(QString cat_class READ getcat_class WRITE setcat_class)
    T_DEFINE_PROPERTY(QString, cat_class)
    Q_PROPERTY(QString country READ getcountry WRITE setcountry)
    T_DEFINE_PROPERTY(QString, country)
    Q_PROPERTY(QString lang READ getlang WRITE setlang)
    T_DEFINE_PROPERTY(QString, lang)
    Q_PROPERTY(QString doc_type READ getdoc_type WRITE setdoc_type)
    T_DEFINE_PROPERTY(QString, doc_type)
    Q_PROPERTY(QString rel_requester READ getrel_requester WRITE setrel_requester)
    T_DEFINE_PROPERTY(QString, rel_requester)
    Q_PROPERTY(QDateTime relrequest_date READ getrelrequest_date WRITE setrelrequest_date)
    T_DEFINE_PROPERTY(QDateTime, relrequest_date)
    Q_PROPERTY(QString rel_creator READ getrel_creator WRITE setrel_creator)
    T_DEFINE_PROPERTY(QString, rel_creator)
    Q_PROPERTY(QDateTime relcreator_decisdate READ getrelcreator_decisdate WRITE setrelcreator_decisdate)
    T_DEFINE_PROPERTY(QDateTime, relcreator_decisdate)
    Q_PROPERTY(QString rel_inspector READ getrel_inspector WRITE setrel_inspector)
    T_DEFINE_PROPERTY(QString, rel_inspector)
    Q_PROPERTY(QDateTime relinspect_decisdate READ getrelinspect_decisdate WRITE setrelinspect_decisdate)
    T_DEFINE_PROPERTY(QDateTime, relinspect_decisdate)
    Q_PROPERTY(QString rel_approver READ getrel_approver WRITE setrel_approver)
    T_DEFINE_PROPERTY(QString, rel_approver)
    Q_PROPERTY(QDateTime relapprov_decisdate READ getrelapprov_decisdate WRITE setrelapprov_decisdate)
    T_DEFINE_PROPERTY(QDateTime, relapprov_decisdate)
    Q_PROPERTY(QDateTime ci_date READ getci_date WRITE setci_date)
    T_DEFINE_PROPERTY(QDateTime, ci_date)
    Q_PROPERTY(QDateTime cd_date READ getcd_date WRITE setcd_date)
    T_DEFINE_PROPERTY(QDateTime, cd_date)
    Q_PROPERTY(QDateTime cdd_date READ getcdd_date WRITE setcdd_date)
    T_DEFINE_PROPERTY(QDateTime, cdd_date)
};

#endif // RELEASEMGMTOBJECT_H
