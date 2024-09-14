#ifndef OBJECTSOBJECT_H
#define OBJECTSOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT ObjectsObject : public TSqlObject, public QSharedData
{
public:
    int id {0};
    QString obj_sname;
    QString obj_lname_de;
    QString desc_de;
    QString obj_lname_en;
    QString desc_en;
    int sort {0};
    int active {0};
    QString groups;

    enum PropertyIndex {
        Id = 0,
        ObjSname,
        ObjLnameDe,
        DescDe,
        ObjLnameEn,
        DescEn,
        Sort,
        Active,
        Groups,
    };

    int primaryKeyIndex() const override { return Id; }
    int autoValueIndex() const override { return Id; }
    QString tableName() const override { return QStringLiteral("objects"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int id READ getid WRITE setid)
    T_DEFINE_PROPERTY(int, id)
    Q_PROPERTY(QString obj_sname READ getobj_sname WRITE setobj_sname)
    T_DEFINE_PROPERTY(QString, obj_sname)
    Q_PROPERTY(QString obj_lname_de READ getobj_lname_de WRITE setobj_lname_de)
    T_DEFINE_PROPERTY(QString, obj_lname_de)
    Q_PROPERTY(QString desc_de READ getdesc_de WRITE setdesc_de)
    T_DEFINE_PROPERTY(QString, desc_de)
    Q_PROPERTY(QString obj_lname_en READ getobj_lname_en WRITE setobj_lname_en)
    T_DEFINE_PROPERTY(QString, obj_lname_en)
    Q_PROPERTY(QString desc_en READ getdesc_en WRITE setdesc_en)
    T_DEFINE_PROPERTY(QString, desc_en)
    Q_PROPERTY(int sort READ getsort WRITE setsort)
    T_DEFINE_PROPERTY(int, sort)
    Q_PROPERTY(int active READ getactive WRITE setactive)
    T_DEFINE_PROPERTY(int, active)
    Q_PROPERTY(QString groups READ getgroups WRITE setgroups)
    T_DEFINE_PROPERTY(QString, groups)
};

#endif // OBJECTSOBJECT_H
