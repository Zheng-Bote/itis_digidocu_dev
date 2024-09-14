#ifndef GLOSSAR_H
#define GLOSSAR_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class GlossarObject;
class QJsonArray;


class T_MODEL_EXPORT Glossar : public TAbstractModel
{
public:
    Glossar();
    Glossar(const Glossar &other);
    Glossar(const GlossarObject &object);
    ~Glossar();

    int id() const;
    QString acronym() const;
    void setAcronym(const QString &acronym);
    QString termDe() const;
    void setTermDe(const QString &termDe);
    QString termEn() const;
    void setTermEn(const QString &termEn);
    QString descDe() const;
    void setDescDe(const QString &descDe);
    QString descEn() const;
    void setDescEn(const QString &descEn);
    int sort() const;
    void setSort(int sort);
    int active() const;
    void setActive(int active);
    Glossar &operator=(const Glossar &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static Glossar create(const QString &acronym, const QString &termDe, const QString &termEn, const QString &descDe, const QString &descEn, int sort, int active);
    static Glossar create(const QVariantMap &values);
    static Glossar get(int id);
    static int count();
    static QList<Glossar> getAll();
    static QJsonArray getAllJson();
    static QJsonArray getAllJsonSorted();

    static QMap<QString, QString> getStatistics();

private:
    QSharedDataPointer<GlossarObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const Glossar &model);
    friend QDataStream &operator>>(QDataStream &ds, Glossar &model);
};

Q_DECLARE_METATYPE(Glossar)
Q_DECLARE_METATYPE(QList<Glossar>)

#endif // GLOSSAR_H
