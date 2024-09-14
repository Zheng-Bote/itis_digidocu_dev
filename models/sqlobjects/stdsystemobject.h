#ifndef STDSYSTEMOBJECT_H
#define STDSYSTEMOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT StdSystemObject : public TSqlObject, public QSharedData
{
public:
    int id {0};
    QString std_type;
    QString std_attr;
    QString std_val;
    QString std_flag;
    int sort {0};
    int active {0};

    enum PropertyIndex {
        Id = 0,
        StdType,
        StdAttr,
        StdVal,
        StdFlag,
        Sort,
        Active,
    };

    int primaryKeyIndex() const override { return Id; }
    int autoValueIndex() const override { return Id; }
    QString tableName() const override { return QStringLiteral("std_system"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int id READ getid WRITE setid)
    T_DEFINE_PROPERTY(int, id)
    Q_PROPERTY(QString std_type READ getstd_type WRITE setstd_type)
    T_DEFINE_PROPERTY(QString, std_type)
    Q_PROPERTY(QString std_attr READ getstd_attr WRITE setstd_attr)
    T_DEFINE_PROPERTY(QString, std_attr)
    Q_PROPERTY(QString std_val READ getstd_val WRITE setstd_val)
    T_DEFINE_PROPERTY(QString, std_val)
    Q_PROPERTY(QString std_flag READ getstd_flag WRITE setstd_flag)
    T_DEFINE_PROPERTY(QString, std_flag)
    Q_PROPERTY(int sort READ getsort WRITE setsort)
    T_DEFINE_PROPERTY(int, sort)
    Q_PROPERTY(int active READ getactive WRITE setactive)
    T_DEFINE_PROPERTY(int, active)
};

#endif // STDSYSTEMOBJECT_H
