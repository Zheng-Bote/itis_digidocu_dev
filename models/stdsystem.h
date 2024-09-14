#ifndef STDSYSTEM_H
#define STDSYSTEM_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class StdSystemObject;
class QJsonArray;


class T_MODEL_EXPORT StdSystem : public TAbstractModel
{
public:
    StdSystem();
    StdSystem(const StdSystem &other);
    StdSystem(const StdSystemObject &object);
    ~StdSystem();

    int id() const;
    QString stdType() const;
    void setStdType(const QString &stdType);
    QString stdAttr() const;
    void setStdAttr(const QString &stdAttr);
    QString stdVal() const;
    void setStdVal(const QString &stdVal);
    QString stdFlag() const;
    void setStdFlag(const QString &stdFlag);
    int sort() const;
    void setSort(int sort);
    int active() const;
    void setActive(int active);
    StdSystem &operator=(const StdSystem &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static StdSystem create(const QString &stdType, const QString &stdAttr, const QString &stdVal, const QString &stdFlag, int sort, int active);
    static StdSystem create(const QVariantMap &values);
    static StdSystem get(int id);
    static int count();

    static QList<StdSystem> getAll();
    static QJsonArray getAllJson();
    static QJsonArray getAllJson(const QString &active, const QString &std_type);

    static QString convertDate(QDate buildtime);

    static QString getAppVersion();

private:
    QSharedDataPointer<StdSystemObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const StdSystem &model);
    friend QDataStream &operator>>(QDataStream &ds, StdSystem &model);
};

Q_DECLARE_METATYPE(StdSystem)
Q_DECLARE_METATYPE(QList<StdSystem>)

#endif // STDSYSTEM_H
