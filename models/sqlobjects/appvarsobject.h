#ifndef APPVARSOBJECT_H
#define APPVARSOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT AppVarsObject : public TSqlObject, public QSharedData
{
public:
    int id {0};
    QString std_type;
    QString std_attr;
    QString std_val_de;
    QString std_val_en;
    int active {0};

    enum PropertyIndex {
        Id = 0,
        StdType,
        StdAttr,
        StdValDe,
        StdValEn,
        Active,
    };

    int primaryKeyIndex() const override { return Id; }
    int autoValueIndex() const override { return Id; }
    QString tableName() const override { return QStringLiteral("app_vars"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int id READ getid WRITE setid)
    T_DEFINE_PROPERTY(int, id)
    Q_PROPERTY(QString std_type READ getstd_type WRITE setstd_type)
    T_DEFINE_PROPERTY(QString, std_type)
    Q_PROPERTY(QString std_attr READ getstd_attr WRITE setstd_attr)
    T_DEFINE_PROPERTY(QString, std_attr)
    Q_PROPERTY(QString std_val_de READ getstd_val_de WRITE setstd_val_de)
    T_DEFINE_PROPERTY(QString, std_val_de)
    Q_PROPERTY(QString std_val_en READ getstd_val_en WRITE setstd_val_en)
    T_DEFINE_PROPERTY(QString, std_val_en)
    Q_PROPERTY(int active READ getactive WRITE setactive)
    T_DEFINE_PROPERTY(int, active)
};

#endif // APPVARSOBJECT_H
