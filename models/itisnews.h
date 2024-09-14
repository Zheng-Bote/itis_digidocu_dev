#ifndef ITISNEWS_H
#define ITISNEWS_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class ItisNewsObject;
class QJsonArray;


class T_MODEL_EXPORT ItisNews : public TAbstractModel
{
public:
    ItisNews();
    ItisNews(const ItisNews &other);
    ItisNews(const ItisNewsObject &object);
    ~ItisNews();

    int id() const;
    QString newsType() const;
    void setNewsType(const QString &newsType);
    QString newsTypeSub() const;
    void setNewsTypeSub(const QString &newsTypeSub);
    QString newsTitleDe() const;
    void setNewsTitleDe(const QString &newsTitleDe);
    QString newsTitleEn() const;
    void setNewsTitleEn(const QString &newsTitleEn);
    QString newsDescDe() const;
    void setNewsDescDe(const QString &newsDescDe);
    QString newsDescEn() const;
    void setNewsDescEn(const QString &newsDescEn);
    QString newsTextDe() const;
    void setNewsTextDe(const QString &newsTextDe);
    QString newsTextEn() const;
    void setNewsTextEn(const QString &newsTextEn);
    QString newsPrio() const;
    void setNewsPrio(const QString &newsPrio);
    QString author() const;
    void setAuthor(const QString &author);
    QDateTime newsCreated() const;
    void setNewsCreated(const QDateTime &newsCreated);
    QDateTime newsValidStart() const;
    void setNewsValidStart(const QDateTime &newsValidStart);
    QDateTime newsValidEnd() const;
    void setNewsValidEnd(const QDateTime &newsValidEnd);
    ItisNews &operator=(const ItisNews &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static ItisNews create(const QString &newsType, const QString &newsTypeSub, const QString &newsTitleDe, const QString &newsTitleEn, const QString &newsDescDe, const QString &newsDescEn, const QString &newsTextDe, const QString &newsTextEn, const QString &newsPrio, const QString &author, const QDateTime &newsCreated, const QDateTime &newsValidStart, const QDateTime &newsValidEnd);
    static ItisNews create(const QVariantMap &values);
    static ItisNews get(int id);
    static int count();
    static QList<ItisNews> getAll();
    static QJsonArray getAllJson();

private:
    QSharedDataPointer<ItisNewsObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const ItisNews &model);
    friend QDataStream &operator>>(QDataStream &ds, ItisNews &model);
};

Q_DECLARE_METATYPE(ItisNews)
Q_DECLARE_METATYPE(QList<ItisNews>)

#endif // ITISNEWS_H
