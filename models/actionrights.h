#ifndef ACTIONRIGHTS_H
#define ACTIONRIGHTS_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class ActionRightsObject;
class QJsonArray;


class T_MODEL_EXPORT ActionRights : public TAbstractModel
{
public:
    ActionRights();
    ActionRights(const ActionRights &other);
    ActionRights(const ActionRightsObject &object);
    ~ActionRights();

    int id() const;
    QString uri() const;
    void setUri(const QString &uri);
    QString groups() const;
    void setGroups(const QString &groups);
    QString rights() const;
    void setRights(const QString &rights);
    int active() const;
    void setActive(int active);
    ActionRights &operator=(const ActionRights &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static ActionRights create(const QString &uri, const QString &groups, const QString &rights, int active);
    static ActionRights create(const QVariantMap &values);
    static ActionRights get(int id);
    static int count();
    static QList<ActionRights> getAll();
    static QJsonArray getAllJson();
    static bool isInGroups(const QString &usergroups, const QString &crud, const QString &uri);

private:
    QSharedDataPointer<ActionRightsObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const ActionRights &model);
    friend QDataStream &operator>>(QDataStream &ds, ActionRights &model);
};

Q_DECLARE_METATYPE(ActionRights)
Q_DECLARE_METATYPE(QList<ActionRights>)

#endif // ACTIONRIGHTS_H
