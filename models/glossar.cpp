#include <TreeFrogModel>
#include "glossar.h"
#include "sqlobjects/glossarobject.h"

Glossar::Glossar() :
    TAbstractModel(),
    d(new GlossarObject())
{
    // set the initial parameters
}

Glossar::Glossar(const Glossar &other) :
    TAbstractModel(),
    d(other.d)
{ }

Glossar::Glossar(const GlossarObject &object) :
    TAbstractModel(),
    d(new GlossarObject(object))
{ }

Glossar::~Glossar()
{
    // If the reference count becomes 0,
    // the shared data object 'GlossarObject' is deleted.
}

// #####

QMap<QString, QString> Glossar::getStatistics()
{
    TSqlQuery query;
    QMap<QString, QString> qmapStat;

    // count
    query.prepare("SELECT count(id) FROM glossar");
    query.exec();
    query.next();
    qmapStat["glossar_count"] = query.value(0).toString();

    // active
    query.prepare("select count(term_de) from glossar where term_de != ''");
    query.exec();
    query.next();
    qmapStat["de_terms"] = query.value(0).toString();

    // countries
    query.prepare("select count(term_en) from glossar where term_en != ''");
    query.exec();
    query.next();
    qmapStat["en_terms"] = query.value(0).toString();

    return qmapStat;
}

int Glossar::id() const
{
    return d->id;
}

QString Glossar::acronym() const
{
    return d->acronym;
}

void Glossar::setAcronym(const QString &acronym)
{
    d->acronym = acronym;
}

QString Glossar::termDe() const
{
    return d->term_de;
}

void Glossar::setTermDe(const QString &termDe)
{
    d->term_de = termDe;
}

QString Glossar::termEn() const
{
    return d->term_en;
}

void Glossar::setTermEn(const QString &termEn)
{
    d->term_en = termEn;
}

QString Glossar::descDe() const
{
    return d->desc_de;
}

void Glossar::setDescDe(const QString &descDe)
{
    d->desc_de = descDe;
}

QString Glossar::descEn() const
{
    return d->desc_en;
}

void Glossar::setDescEn(const QString &descEn)
{
    d->desc_en = descEn;
}

int Glossar::sort() const
{
    return d->sort;
}

void Glossar::setSort(int sort)
{
    d->sort = sort;
}

int Glossar::active() const
{
    return d->active;
}

void Glossar::setActive(int active)
{
    d->active = active;
}

Glossar &Glossar::operator=(const Glossar &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

Glossar Glossar::create(const QString &acronym, const QString &termDe, const QString &termEn, const QString &descDe, const QString &descEn, int sort, int active)
{
    GlossarObject obj;
    obj.acronym = acronym;
    obj.term_de = termDe;
    obj.term_en = termEn;
    obj.desc_de = descDe;
    obj.desc_en = descEn;
    obj.sort = sort;
    obj.active = active;
    if (!obj.create()) {
        return Glossar();
    }
    return Glossar(obj);
}

Glossar Glossar::create(const QVariantMap &values)
{
    Glossar model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

Glossar Glossar::get(int id)
{
    TSqlORMapper<GlossarObject> mapper;
    return Glossar(mapper.findByPrimaryKey(id));
}

int Glossar::count()
{
    TSqlORMapper<GlossarObject> mapper;
    return mapper.findCount();
}

QList<Glossar> Glossar::getAll()
{
    return tfGetModelListByCriteria<Glossar, GlossarObject>(TCriteria());
}

QJsonArray Glossar::getAllJson()
{
    QJsonArray array;
    TSqlORMapper<GlossarObject> mapper;

    if (mapper.find() > 0) {
        for (TSqlORMapperIterator<GlossarObject> i(mapper); i.hasNext(); ) {
            array.append(QJsonValue(QJsonObject::fromVariantMap(Glossar(i.next()).toVariantMap())));
        }
    }
    return array;
}

QJsonArray Glossar::getAllJsonSorted()
{
    TSqlQuery query;
    QJsonObject jsonObject;
    QJsonArray jsonArray;

    query.prepare("SELECT acronym, term_de, term_en, desc_de, desc_en FROM public.glossar ORDER BY acronym");
    query.exec();
    while (query.next())
    {
        jsonObject["acronym"] = query.value(0).toString();
        jsonObject["termDe"] = query.value(1).toString();
        jsonObject["termEn"] = query.value(2).toString();
        jsonObject["descDe"] = query.value(3).toString();
        jsonObject["descEn"] = query.value(4).toString();
        jsonArray.append(jsonObject);
    }

    return jsonArray;
}

TModelObject *Glossar::modelData()
{
    return d.data();
}

const TModelObject *Glossar::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const Glossar &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, Glossar &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(Glossar)
