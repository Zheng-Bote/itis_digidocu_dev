#include <TreeFrogModel>
#include "catclasses.h"
#include "sqlobjects/catclassesobject.h"

CatClasses::CatClasses() :
    TAbstractModel(),
    d(new CatClassesObject())
{
    // set the initial parameters
}

CatClasses::CatClasses(const CatClasses &other) :
    TAbstractModel(),
    d(other.d)
{ }

CatClasses::CatClasses(const CatClassesObject &object) :
    TAbstractModel(),
    d(new CatClassesObject(object))
{ }

CatClasses::~CatClasses()
{
    // If the reference count becomes 0,
    // the shared data object 'CatClassesObject' is deleted.
}

// #####

QJsonArray CatClasses::getAllJson(const QString &active, const QString &class_type, const QString strGroups)
{

    TSqlQuery query;
    QJsonObject jsonObject;
    QJsonArray jsonArray;
    QString msg;

     QString andStr = strGroups;

    query.prepare("SELECT * FROM cat_classes WHERE active = ? AND class_type = ? and " + andStr + " order by sort");
    //query.prepare("SELECT * FROM cat_classes WHERE active = '1' AND class_type = 'category' and " + andStr + " order by sort");
    //query.bindValue(":active", active);
    query.addBindValue(active);
    //query.bindValue(":class_type", class_type);
    query.addBindValue(class_type);
    //query.addBindValue(andStr);

    if(!query.exec())
    {
        msg = query.lastError().text();
        jsonObject["sys_msg"] = msg;
        jsonObject["sys_err"] = "1";
        jsonArray.append(jsonObject);
        return jsonArray;
    }

    while (query.next())
    {
        jsonObject["id"] = query.value(0).toString();
        jsonObject["cat_lname_de"] = query.value(1).toString();
        jsonObject["cat_sname_de"] = query.value(2).toString();
        jsonObject["desc_de"] = query.value(3).toString();
        jsonObject["cat_lname_en"] = query.value(4).toString();
        jsonObject["cat_sname_en"] = query.value(5).toString();
        jsonObject["desc_en"] = query.value(6).toString();
        jsonObject["class_type"] = query.value(7).toString();
        jsonObject["groups"] = query.value(8).toString();
        jsonObject["sort"] = query.value(9).toString();
        jsonObject["active"] = query.value(10).toString();

        jsonArray.append(jsonObject);
    }

    return jsonArray;
}

QJsonArray CatClasses::getAllJson(const QString &active, const QString &class_type)
{

    TSqlQuery query;
    QJsonObject jsonObject;
    QJsonArray jsonArray;
    QString msg;

    query.prepare("SELECT * FROM cat_classes WHERE active = ? AND class_type = ? order by sort");
    query.addBindValue(active);
    query.addBindValue(class_type);

    if(!query.exec())
    {
        msg = query.lastError().text();
        jsonObject["sys_msg"] = msg;
        jsonObject["sys_err"] = "1";
        jsonArray.append(jsonObject);
        return jsonArray;
    }

    while (query.next())
    {
        jsonObject["id"] = query.value(0).toString();
        jsonObject["cat_lname_de"] = query.value(1).toString();
        jsonObject["cat_sname_de"] = query.value(2).toString();
        jsonObject["desc_de"] = query.value(3).toString();
        jsonObject["cat_lname_en"] = query.value(4).toString();
        jsonObject["cat_sname_en"] = query.value(5).toString();
        jsonObject["desc_en"] = query.value(6).toString();
        jsonObject["class_type"] = query.value(7).toString();
        jsonObject["groups"] = query.value(8).toString();
        jsonObject["sort"] = query.value(9).toString();
        jsonObject["active"] = query.value(10).toString();

        jsonArray.append(jsonObject);
    }

    return jsonArray;
}

int CatClasses::id() const
{
    return d->id;
}

QString CatClasses::catLnameDe() const
{
    return d->cat_lname_de;
}

void CatClasses::setCatLnameDe(const QString &catLnameDe)
{
    d->cat_lname_de = catLnameDe;
}

QString CatClasses::catSnameDe() const
{
    return d->cat_sname_de;
}

void CatClasses::setCatSnameDe(const QString &catSnameDe)
{
    d->cat_sname_de = catSnameDe;
}

QString CatClasses::descDe() const
{
    return d->desc_de;
}

void CatClasses::setDescDe(const QString &descDe)
{
    d->desc_de = descDe;
}

QString CatClasses::catLnameEn() const
{
    return d->cat_lname_en;
}

void CatClasses::setCatLnameEn(const QString &catLnameEn)
{
    d->cat_lname_en = catLnameEn;
}

QString CatClasses::catSnameEn() const
{
    return d->cat_sname_en;
}

void CatClasses::setCatSnameEn(const QString &catSnameEn)
{
    d->cat_sname_en = catSnameEn;
}

QString CatClasses::descEn() const
{
    return d->desc_en;
}

void CatClasses::setDescEn(const QString &descEn)
{
    d->desc_en = descEn;
}

QString CatClasses::classType() const
{
    return d->class_type;
}

void CatClasses::setClassType(const QString &classType)
{
    d->class_type = classType;
}

QString CatClasses::groups() const
{
    return d->groups;
}

void CatClasses::setGroups(const QString &groups)
{
    d->groups = groups;
}

int CatClasses::sort() const
{
    return d->sort;
}

void CatClasses::setSort(int sort)
{
    d->sort = sort;
}

int CatClasses::active() const
{
    return d->active;
}

void CatClasses::setActive(int active)
{
    d->active = active;
}

CatClasses &CatClasses::operator=(const CatClasses &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

CatClasses CatClasses::create(const QString &catLnameDe, const QString &catSnameDe, const QString &descDe, const QString &catLnameEn, const QString &catSnameEn, const QString &descEn, const QString &classType, const QString &groups, int sort, int active)
{
    CatClassesObject obj;
    obj.cat_lname_de = catLnameDe;
    obj.cat_sname_de = catSnameDe;
    obj.desc_de = descDe;
    obj.cat_lname_en = catLnameEn;
    obj.cat_sname_en = catSnameEn;
    obj.desc_en = descEn;
    obj.class_type = classType;
    obj.groups = groups;
    obj.sort = sort;
    obj.active = active;
    if (!obj.create()) {
        return CatClasses();
    }
    return CatClasses(obj);
}

CatClasses CatClasses::create(const QVariantMap &values)
{
    CatClasses model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

CatClasses CatClasses::get(int id)
{
    TSqlORMapper<CatClassesObject> mapper;
    return CatClasses(mapper.findByPrimaryKey(id));
}

int CatClasses::count()
{
    TSqlORMapper<CatClassesObject> mapper;
    return mapper.findCount();
}

QList<CatClasses> CatClasses::getAll()
{
    return tfGetModelListByCriteria<CatClasses, CatClassesObject>(TCriteria());
}

QJsonArray CatClasses::getAllJson()
{
    QJsonArray array;
    TSqlORMapper<CatClassesObject> mapper;

    if (mapper.find() > 0) {
        for (TSqlORMapperIterator<CatClassesObject> i(mapper); i.hasNext(); ) {
            array.append(QJsonValue(QJsonObject::fromVariantMap(CatClasses(i.next()).toVariantMap())));
        }
    }
    return array;
}

TModelObject *CatClasses::modelData()
{
    return d.data();
}

const TModelObject *CatClasses::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const CatClasses &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, CatClasses &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(CatClasses)
