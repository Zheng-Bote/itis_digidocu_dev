#ifndef ITISGROUPS_H
#define ITISGROUPS_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class ItisGroupsObject;
class QJsonArray;


class T_MODEL_EXPORT ItisGroups : public TAbstractModel
{
public:
    ItisGroups();
    ItisGroups(const ItisGroups &other);
    ItisGroups(const ItisGroupsObject &object);
    ~ItisGroups();

    int id() const;
    QString groupname() const;
    void setGroupname(const QString &groupname);
    QString groupdesc() const;
    void setGroupdesc(const QString &groupdesc);
    int active() const;
    void setActive(int active);
    ItisGroups &operator=(const ItisGroups &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static ItisGroups create(const QString &groupname, const QString &groupdesc, int active);
    static ItisGroups create(const QVariantMap &values);
    static ItisGroups get(int id);
    static int count();
    static QList<ItisGroups> getAll();
    static QJsonArray getAllJson();

private:
    QSharedDataPointer<ItisGroupsObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const ItisGroups &model);
    friend QDataStream &operator>>(QDataStream &ds, ItisGroups &model);
};

Q_DECLARE_METATYPE(ItisGroups)
Q_DECLARE_METATYPE(QList<ItisGroups>)

#endif // ITISGROUPS_H
