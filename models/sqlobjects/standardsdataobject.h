#ifndef STANDARDSDATAOBJECT_H
#define STANDARDSDATAOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT StandardsDataObject : public TSqlObject, public QSharedData
{
public:
    int id {0};
    QString lfdnr;
    QString spec_title;
    QString spec_desc;
    QString spec_version;
    QString spec_release;
    QString obj_sname;
    QString ac_classes;
    QString pc_classes;
    QString cat_class;
    QString country;
    QString lang;
    QByteArray spec_content;
    int spec_active {0};

    enum PropertyIndex {
        Id = 0,
        Lfdnr,
        SpecTitle,
        SpecDesc,
        SpecVersion,
        SpecRelease,
        ObjSname,
        AcClasses,
        PcClasses,
        CatClass,
        Country,
        Lang,
        SpecContent,
        SpecActive,
    };

    int primaryKeyIndex() const override { return Id; }
    int autoValueIndex() const override { return Id; }
    QString tableName() const override { return QStringLiteral("standards_data"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int id READ getid WRITE setid)
    T_DEFINE_PROPERTY(int, id)
    Q_PROPERTY(QString lfdnr READ getlfdnr WRITE setlfdnr)
    T_DEFINE_PROPERTY(QString, lfdnr)
    Q_PROPERTY(QString spec_title READ getspec_title WRITE setspec_title)
    T_DEFINE_PROPERTY(QString, spec_title)
    Q_PROPERTY(QString spec_desc READ getspec_desc WRITE setspec_desc)
    T_DEFINE_PROPERTY(QString, spec_desc)
    Q_PROPERTY(QString spec_version READ getspec_version WRITE setspec_version)
    T_DEFINE_PROPERTY(QString, spec_version)
    Q_PROPERTY(QString spec_release READ getspec_release WRITE setspec_release)
    T_DEFINE_PROPERTY(QString, spec_release)
    Q_PROPERTY(QString obj_sname READ getobj_sname WRITE setobj_sname)
    T_DEFINE_PROPERTY(QString, obj_sname)
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
    Q_PROPERTY(QByteArray spec_content READ getspec_content WRITE setspec_content)
    T_DEFINE_PROPERTY(QByteArray, spec_content)
    Q_PROPERTY(int spec_active READ getspec_active WRITE setspec_active)
    T_DEFINE_PROPERTY(int, spec_active)
};

#endif // STANDARDSDATAOBJECT_H
