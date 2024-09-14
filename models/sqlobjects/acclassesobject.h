#ifndef ACCLASSESOBJECT_H
#define ACCLASSESOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT AcClassesObject : public TSqlObject, public QSharedData
{
public:
    int id {0};
    QString obj_sname;
    int ac_class {0};
    QString class_type;
    int active {0};

    enum PropertyIndex {
        Id = 0,
        ObjSname,
        AcClass,
        ClassType,
        Active,
    };

    int primaryKeyIndex() const override { return Id; }
    int autoValueIndex() const override { return Id; }
    QString tableName() const override { return QStringLiteral("ac_classes"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int id READ getid WRITE setid)
    T_DEFINE_PROPERTY(int, id)
    Q_PROPERTY(QString obj_sname READ getobj_sname WRITE setobj_sname)
    T_DEFINE_PROPERTY(QString, obj_sname)
    Q_PROPERTY(int ac_class READ getac_class WRITE setac_class)
    T_DEFINE_PROPERTY(int, ac_class)
    Q_PROPERTY(QString class_type READ getclass_type WRITE setclass_type)
    T_DEFINE_PROPERTY(QString, class_type)
    Q_PROPERTY(int active READ getactive WRITE setactive)
    T_DEFINE_PROPERTY(int, active)
};

#endif // ACCLASSESOBJECT_H
