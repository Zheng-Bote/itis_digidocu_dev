#ifndef ITISGROUPSOBJECT_H
#define ITISGROUPSOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT ItisGroupsObject : public TSqlObject, public QSharedData
{
public:
    int id {0};
    QString groupname;
    QString groupdesc;
    int active {0};

    enum PropertyIndex {
        Id = 0,
        Groupname,
        Groupdesc,
        Active,
    };

    int primaryKeyIndex() const override { return Id; }
    int autoValueIndex() const override { return Id; }
    QString tableName() const override { return QStringLiteral("itis_groups"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int id READ getid WRITE setid)
    T_DEFINE_PROPERTY(int, id)
    Q_PROPERTY(QString groupname READ getgroupname WRITE setgroupname)
    T_DEFINE_PROPERTY(QString, groupname)
    Q_PROPERTY(QString groupdesc READ getgroupdesc WRITE setgroupdesc)
    T_DEFINE_PROPERTY(QString, groupdesc)
    Q_PROPERTY(int active READ getactive WRITE setactive)
    T_DEFINE_PROPERTY(int, active)
};

#endif // ITISGROUPSOBJECT_H
