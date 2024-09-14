#ifndef OBJECTS_H
#define OBJECTS_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class ObjectsObject;
class QJsonArray;


class T_MODEL_EXPORT Objects : public TAbstractModel
{
public:
    Objects();
    Objects(const Objects &other);
    Objects(const ObjectsObject &object);
    ~Objects();

    int id() const;
    QString objSname() const;
    void setObjSname(const QString &objSname);
    QString objLnameDe() const;
    void setObjLnameDe(const QString &objLnameDe);
    QString descDe() const;
    void setDescDe(const QString &descDe);
    QString objLnameEn() const;
    void setObjLnameEn(const QString &objLnameEn);
    QString descEn() const;
    void setDescEn(const QString &descEn);
    int sort() const;
    void setSort(int sort);
    int active() const;
    void setActive(int active);
    QString groups() const;
    void setGroups(const QString &groups);
    Objects &operator=(const Objects &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static Objects create(const QString &objSname, const QString &objLnameDe, const QString &descDe, const QString &objLnameEn, const QString &descEn, int sort, int active, const QString &groups);
    static Objects create(const QVariantMap &values);
    static Objects get(int id);
    static int count();
    static QList<Objects> getAll();
    static QJsonArray getAllJson();
    static QJsonArray getAllJson(const QString &active);
    static QJsonArray getAllJson(const QString &active, const QString strGroups);

private:
    QSharedDataPointer<ObjectsObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const Objects &model);
    friend QDataStream &operator>>(QDataStream &ds, Objects &model);
};

Q_DECLARE_METATYPE(Objects)
Q_DECLARE_METATYPE(QList<Objects>)

#endif // OBJECTS_H
