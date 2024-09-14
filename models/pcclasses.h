#ifndef PCCLASSES_H
#define PCCLASSES_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class PcClassesObject;
class QJsonArray;


class T_MODEL_EXPORT PcClasses : public TAbstractModel
{
public:
    PcClasses();
    PcClasses(const PcClasses &other);
    PcClasses(const PcClassesObject &object);
    ~PcClasses();

    int id() const;
    QString objSname() const;
    void setObjSname(const QString &objSname);
    int pcClass() const;
    void setPcClass(int pcClass);
    QString classType() const;
    void setClassType(const QString &classType);
    int active() const;
    void setActive(int active);
    PcClasses &operator=(const PcClasses &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static PcClasses create(const QString &objSname, int pcClass, const QString &classType, int active);
    static PcClasses create(const QVariantMap &values);
    static PcClasses get(int id);
    static int count();

    static QList<PcClasses> getAll();
    static QJsonArray getAllJson();
    static QJsonArray getPcClassesJson();
    static QJsonArray getObjPcJson(QString &obj, int &active);

private:
    QSharedDataPointer<PcClassesObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const PcClasses &model);
    friend QDataStream &operator>>(QDataStream &ds, PcClasses &model);
};

Q_DECLARE_METATYPE(PcClasses)
Q_DECLARE_METATYPE(QList<PcClasses>)

#endif // PCCLASSES_H
