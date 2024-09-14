#ifndef ACTIONRIGHTSOBJECT_H
#define ACTIONRIGHTSOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT ActionRightsObject : public TSqlObject, public QSharedData
{
public:
    int id {0};
    QString uri;
    QString groups;
    QString rights;
    int active {0};

    enum PropertyIndex {
        Id = 0,
        Uri,
        Groups,
        Rights,
        Active,
    };

    int primaryKeyIndex() const override { return Id; }
    int autoValueIndex() const override { return Id; }
    QString tableName() const override { return QStringLiteral("action_rights"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int id READ getid WRITE setid)
    T_DEFINE_PROPERTY(int, id)
    Q_PROPERTY(QString uri READ geturi WRITE seturi)
    T_DEFINE_PROPERTY(QString, uri)
    Q_PROPERTY(QString groups READ getgroups WRITE setgroups)
    T_DEFINE_PROPERTY(QString, groups)
    Q_PROPERTY(QString rights READ getrights WRITE setrights)
    T_DEFINE_PROPERTY(QString, rights)
    Q_PROPERTY(int active READ getactive WRITE setactive)
    T_DEFINE_PROPERTY(int, active)
};

#endif // ACTIONRIGHTSOBJECT_H
