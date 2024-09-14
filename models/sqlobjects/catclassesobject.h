#ifndef CATCLASSESOBJECT_H
#define CATCLASSESOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT CatClassesObject : public TSqlObject, public QSharedData
{
public:
    int id {0};
    QString cat_lname_de;
    QString cat_sname_de;
    QString desc_de;
    QString cat_lname_en;
    QString cat_sname_en;
    QString desc_en;
    QString class_type;
    QString groups;
    int sort {0};
    int active {0};

    enum PropertyIndex {
        Id = 0,
        CatLnameDe,
        CatSnameDe,
        DescDe,
        CatLnameEn,
        CatSnameEn,
        DescEn,
        ClassType,
        Groups,
        Sort,
        Active,
    };

    int primaryKeyIndex() const override { return Id; }
    int autoValueIndex() const override { return Id; }
    QString tableName() const override { return QStringLiteral("cat_classes"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int id READ getid WRITE setid)
    T_DEFINE_PROPERTY(int, id)
    Q_PROPERTY(QString cat_lname_de READ getcat_lname_de WRITE setcat_lname_de)
    T_DEFINE_PROPERTY(QString, cat_lname_de)
    Q_PROPERTY(QString cat_sname_de READ getcat_sname_de WRITE setcat_sname_de)
    T_DEFINE_PROPERTY(QString, cat_sname_de)
    Q_PROPERTY(QString desc_de READ getdesc_de WRITE setdesc_de)
    T_DEFINE_PROPERTY(QString, desc_de)
    Q_PROPERTY(QString cat_lname_en READ getcat_lname_en WRITE setcat_lname_en)
    T_DEFINE_PROPERTY(QString, cat_lname_en)
    Q_PROPERTY(QString cat_sname_en READ getcat_sname_en WRITE setcat_sname_en)
    T_DEFINE_PROPERTY(QString, cat_sname_en)
    Q_PROPERTY(QString desc_en READ getdesc_en WRITE setdesc_en)
    T_DEFINE_PROPERTY(QString, desc_en)
    Q_PROPERTY(QString class_type READ getclass_type WRITE setclass_type)
    T_DEFINE_PROPERTY(QString, class_type)
    Q_PROPERTY(QString groups READ getgroups WRITE setgroups)
    T_DEFINE_PROPERTY(QString, groups)
    Q_PROPERTY(int sort READ getsort WRITE setsort)
    T_DEFINE_PROPERTY(int, sort)
    Q_PROPERTY(int active READ getactive WRITE setactive)
    T_DEFINE_PROPERTY(int, active)
};

#endif // CATCLASSESOBJECT_H
