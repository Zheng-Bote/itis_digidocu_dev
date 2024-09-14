#include <TreeFrogModel>
#include "itisnews.h"
#include "sqlobjects/itisnewsobject.h"

ItisNews::ItisNews() :
    TAbstractModel(),
    d(new ItisNewsObject())
{
    // set the initial parameters
}

ItisNews::ItisNews(const ItisNews &other) :
    TAbstractModel(),
    d(other.d)
{ }

ItisNews::ItisNews(const ItisNewsObject &object) :
    TAbstractModel(),
    d(new ItisNewsObject(object))
{ }

ItisNews::~ItisNews()
{
    // If the reference count becomes 0,
    // the shared data object 'ItisNewsObject' is deleted.
}

int ItisNews::id() const
{
    return d->id;
}

QString ItisNews::newsType() const
{
    return d->news_type;
}

void ItisNews::setNewsType(const QString &newsType)
{
    d->news_type = newsType;
}

QString ItisNews::newsTypeSub() const
{
    return d->news_type_sub;
}

void ItisNews::setNewsTypeSub(const QString &newsTypeSub)
{
    d->news_type_sub = newsTypeSub;
}

QString ItisNews::newsTitleDe() const
{
    return d->news_title_de;
}

void ItisNews::setNewsTitleDe(const QString &newsTitleDe)
{
    d->news_title_de = newsTitleDe;
}

QString ItisNews::newsTitleEn() const
{
    return d->news_title_en;
}

void ItisNews::setNewsTitleEn(const QString &newsTitleEn)
{
    d->news_title_en = newsTitleEn;
}

QString ItisNews::newsDescDe() const
{
    return d->news_desc_de;
}

void ItisNews::setNewsDescDe(const QString &newsDescDe)
{
    d->news_desc_de = newsDescDe;
}

QString ItisNews::newsDescEn() const
{
    return d->news_desc_en;
}

void ItisNews::setNewsDescEn(const QString &newsDescEn)
{
    d->news_desc_en = newsDescEn;
}

QString ItisNews::newsTextDe() const
{
    return d->news_text_de;
}

void ItisNews::setNewsTextDe(const QString &newsTextDe)
{
    d->news_text_de = newsTextDe;
}

QString ItisNews::newsTextEn() const
{
    return d->news_text_en;
}

void ItisNews::setNewsTextEn(const QString &newsTextEn)
{
    d->news_text_en = newsTextEn;
}

QString ItisNews::newsPrio() const
{
    return d->news_prio;
}

void ItisNews::setNewsPrio(const QString &newsPrio)
{
    d->news_prio = newsPrio;
}

QString ItisNews::author() const
{
    return d->author;
}

void ItisNews::setAuthor(const QString &author)
{
    d->author = author;
}

QDateTime ItisNews::newsCreated() const
{
    return d->news_created;
}

void ItisNews::setNewsCreated(const QDateTime &newsCreated)
{
    d->news_created = newsCreated;
}

QDateTime ItisNews::newsValidStart() const
{
    return d->news_valid_start;
}

void ItisNews::setNewsValidStart(const QDateTime &newsValidStart)
{
    d->news_valid_start = newsValidStart;
}

QDateTime ItisNews::newsValidEnd() const
{
    return d->news_valid_end;
}

void ItisNews::setNewsValidEnd(const QDateTime &newsValidEnd)
{
    d->news_valid_end = newsValidEnd;
}

ItisNews &ItisNews::operator=(const ItisNews &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

ItisNews ItisNews::create(const QString &newsType, const QString &newsTypeSub, const QString &newsTitleDe, const QString &newsTitleEn, const QString &newsDescDe, const QString &newsDescEn, const QString &newsTextDe, const QString &newsTextEn, const QString &newsPrio, const QString &author, const QDateTime &newsCreated, const QDateTime &newsValidStart, const QDateTime &newsValidEnd)
{
    ItisNewsObject obj;
    obj.news_type = newsType;
    obj.news_type_sub = newsTypeSub;
    obj.news_title_de = newsTitleDe;
    obj.news_title_en = newsTitleEn;
    obj.news_desc_de = newsDescDe;
    obj.news_desc_en = newsDescEn;
    obj.news_text_de = newsTextDe;
    obj.news_text_en = newsTextEn;
    obj.news_prio = newsPrio;
    obj.author = author;
    obj.news_created = newsCreated;
    obj.news_valid_start = newsValidStart;
    obj.news_valid_end = newsValidEnd;
    if (!obj.create()) {
        return ItisNews();
    }
    return ItisNews(obj);
}

ItisNews ItisNews::create(const QVariantMap &values)
{
    ItisNews model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

ItisNews ItisNews::get(int id)
{
    TSqlORMapper<ItisNewsObject> mapper;
    return ItisNews(mapper.findByPrimaryKey(id));
}

int ItisNews::count()
{
    TSqlORMapper<ItisNewsObject> mapper;
    return mapper.findCount();
}

QList<ItisNews> ItisNews::getAll()
{
    return tfGetModelListByCriteria<ItisNews, ItisNewsObject>(TCriteria());
}

QJsonArray ItisNews::getAllJson()
{
    QJsonArray array;
    TSqlORMapper<ItisNewsObject> mapper;

    if (mapper.find() > 0) {
        for (TSqlORMapperIterator<ItisNewsObject> i(mapper); i.hasNext(); ) {
            array.append(QJsonValue(QJsonObject::fromVariantMap(ItisNews(i.next()).toVariantMap())));
        }
    }
    return array;
}

TModelObject *ItisNews::modelData()
{
    return d.data();
}

const TModelObject *ItisNews::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const ItisNews &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, ItisNews &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(ItisNews)
