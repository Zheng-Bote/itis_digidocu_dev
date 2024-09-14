#ifndef APPVARS_H
#define APPVARS_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class AppVarsObject;
class QJsonArray;


class T_MODEL_EXPORT AppVars : public TAbstractModel
{
public:
    AppVars();
    AppVars(const AppVars &other);
    AppVars(const AppVarsObject &object);
    ~AppVars();

    int id() const;
    QString stdType() const;
    void setStdType(const QString &stdType);
    QString stdAttr() const;
    void setStdAttr(const QString &stdAttr);
    QString stdValDe() const;
    void setStdValDe(const QString &stdValDe);
    QString stdValEn() const;
    void setStdValEn(const QString &stdValEn);
    int active() const;
    void setActive(int active);
    AppVars &operator=(const AppVars &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static AppVars create(const QString &stdType, const QString &stdAttr, const QString &stdValDe, const QString &stdValEn, int active);
    static AppVars create(const QVariantMap &values);
    static AppVars get(int id);
    static int count();
    static QList<AppVars> getAll();
    static QJsonArray getAllJson();

private:
    QSharedDataPointer<AppVarsObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const AppVars &model);
    friend QDataStream &operator>>(QDataStream &ds, AppVars &model);
};

Q_DECLARE_METATYPE(AppVars)
Q_DECLARE_METATYPE(QList<AppVars>)

#endif // APPVARS_H
