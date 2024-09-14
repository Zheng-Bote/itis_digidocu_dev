#ifndef ACCLASSES_H
#define ACCLASSES_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class AcClassesObject;
class QJsonArray;


class T_MODEL_EXPORT AcClasses : public TAbstractModel
{
public:
    AcClasses();
    AcClasses(const AcClasses &other);
    AcClasses(const AcClassesObject &object);
    ~AcClasses();

    int id() const;
    QString objSname() const;
    void setObjSname(const QString &objSname);
    int acClass() const;
    void setAcClass(int acClass);
    QString classType() const;
    void setClassType(const QString &classType);
    int active() const;
    void setActive(int active);
    AcClasses &operator=(const AcClasses &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static AcClasses create(const QString &objSname, int acClass, const QString &classType, int active);
    static AcClasses create(const QVariantMap &values);
    static AcClasses get(int id);
    static int count();

    static QList<AcClasses> getAll();
    static QJsonArray getAllJson();
    static QJsonArray getAcClassesJson();
    static QJsonArray getObjAcJson(QString &obj, int &active);

private:
    QSharedDataPointer<AcClassesObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const AcClasses &model);
    friend QDataStream &operator>>(QDataStream &ds, AcClasses &model);
};

Q_DECLARE_METATYPE(AcClasses)
Q_DECLARE_METATYPE(QList<AcClasses>)

#endif // ACCLASSES_H
