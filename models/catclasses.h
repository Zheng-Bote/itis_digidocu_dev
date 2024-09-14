#ifndef CATCLASSES_H
#define CATCLASSES_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class CatClassesObject;
class QJsonArray;


class T_MODEL_EXPORT CatClasses : public TAbstractModel
{
public:
    CatClasses();
    CatClasses(const CatClasses &other);
    CatClasses(const CatClassesObject &object);
    ~CatClasses();

    int id() const;
    QString catLnameDe() const;
    void setCatLnameDe(const QString &catLnameDe);
    QString catSnameDe() const;
    void setCatSnameDe(const QString &catSnameDe);
    QString descDe() const;
    void setDescDe(const QString &descDe);
    QString catLnameEn() const;
    void setCatLnameEn(const QString &catLnameEn);
    QString catSnameEn() const;
    void setCatSnameEn(const QString &catSnameEn);
    QString descEn() const;
    void setDescEn(const QString &descEn);
    QString classType() const;
    void setClassType(const QString &classType);
    QString groups() const;
    void setGroups(const QString &groups);
    int sort() const;
    void setSort(int sort);
    int active() const;
    void setActive(int active);
    CatClasses &operator=(const CatClasses &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static CatClasses create(const QString &catLnameDe, const QString &catSnameDe, const QString &descDe, const QString &catLnameEn, const QString &catSnameEn, const QString &descEn, const QString &classType, const QString &groups, int sort, int active);
    static CatClasses create(const QVariantMap &values);
    static CatClasses get(int id);
    static int count();

    static QList<CatClasses> getAll();
    static QJsonArray getAllJson();
    static QJsonArray getAllJson(const QString &active, const QString &class_type);
    static QJsonArray getAllJson(const QString &active, const QString &class_type, const QString strGroups);

private:
    QSharedDataPointer<CatClassesObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const CatClasses &model);
    friend QDataStream &operator>>(QDataStream &ds, CatClasses &model);
};

Q_DECLARE_METATYPE(CatClasses)
Q_DECLARE_METATYPE(QList<CatClasses>)

#endif // CATCLASSES_H
