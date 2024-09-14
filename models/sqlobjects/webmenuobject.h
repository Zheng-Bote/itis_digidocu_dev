#ifndef WEBMENUOBJECT_H
#define WEBMENUOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT WebmenuObject : public TSqlObject, public QSharedData
{
public:
    int id {0};
    int mnu_id {0};
    int mnu_sub_id {0};
    QString name_de;
    QString desc_de;
    QString name_en;
    QString desc_en;
    QString mnu_uri;
    QString groups;
    QString mnu_item;
    int sort {0};
    int active {0};

    enum PropertyIndex {
        Id = 0,
        MnuId,
        MnuSubId,
        NameDe,
        DescDe,
        NameEn,
        DescEn,
        MnuUri,
        Groups,
        MnuItem,
        Sort,
        Active,
    };

    int primaryKeyIndex() const override { return Id; }
    int autoValueIndex() const override { return Id; }
    QString tableName() const override { return QStringLiteral("webmenu"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int id READ getid WRITE setid)
    T_DEFINE_PROPERTY(int, id)
    Q_PROPERTY(int mnu_id READ getmnu_id WRITE setmnu_id)
    T_DEFINE_PROPERTY(int, mnu_id)
    Q_PROPERTY(int mnu_sub_id READ getmnu_sub_id WRITE setmnu_sub_id)
    T_DEFINE_PROPERTY(int, mnu_sub_id)
    Q_PROPERTY(QString name_de READ getname_de WRITE setname_de)
    T_DEFINE_PROPERTY(QString, name_de)
    Q_PROPERTY(QString desc_de READ getdesc_de WRITE setdesc_de)
    T_DEFINE_PROPERTY(QString, desc_de)
    Q_PROPERTY(QString name_en READ getname_en WRITE setname_en)
    T_DEFINE_PROPERTY(QString, name_en)
    Q_PROPERTY(QString desc_en READ getdesc_en WRITE setdesc_en)
    T_DEFINE_PROPERTY(QString, desc_en)
    Q_PROPERTY(QString mnu_uri READ getmnu_uri WRITE setmnu_uri)
    T_DEFINE_PROPERTY(QString, mnu_uri)
    Q_PROPERTY(QString groups READ getgroups WRITE setgroups)
    T_DEFINE_PROPERTY(QString, groups)
    Q_PROPERTY(QString mnu_item READ getmnu_item WRITE setmnu_item)
    T_DEFINE_PROPERTY(QString, mnu_item)
    Q_PROPERTY(int sort READ getsort WRITE setsort)
    T_DEFINE_PROPERTY(int, sort)
    Q_PROPERTY(int active READ getactive WRITE setactive)
    T_DEFINE_PROPERTY(int, active)
};

#endif // WEBMENUOBJECT_H
