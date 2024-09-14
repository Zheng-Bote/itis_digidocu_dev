#include <TreeFrogModel>
#include "objects.h"
#include "sqlobjects/objectsobject.h"

Objects::Objects() :
    TAbstractModel(),
    d(new ObjectsObject())
{
    // set the initial parameters
}

Objects::Objects(const Objects &other) :
    TAbstractModel(),
    d(other.d)
{ }

Objects::Objects(const ObjectsObject &object) :
    TAbstractModel(),
    d(new ObjectsObject(object))
{ }

Objects::~Objects()
{
    // If the reference count becomes 0,
    // the shared data object 'ObjectsObject' is deleted.
}

// #####

int Objects::id() const
{
    return d->id;
}

QString Objects::objSname() const
{
    return d->obj_sname;
}

void Objects::setObjSname(const QString &objSname)
{
    d->obj_sname = objSname;
}

QString Objects::objLnameDe() const
{
    return d->obj_lname_de;
}

void Objects::setObjLnameDe(const QString &objLnameDe)
{
    d->obj_lname_de = objLnameDe;
}

QString Objects::descDe() const
{
    return d->desc_de;
}

void Objects::setDescDe(const QString &descDe)
{
    d->desc_de = descDe;
}

QString Objects::objLnameEn() const
{
    return d->obj_lname_en;
}

void Objects::setObjLnameEn(const QString &objLnameEn)
{
    d->obj_lname_en = objLnameEn;
}

QString Objects::descEn() const
{
    return d->desc_en;
}

void Objects::setDescEn(const QString &descEn)
{
    d->desc_en = descEn;
}

int Objects::sort() const
{
    return d->sort;
}

void Objects::setSort(int sort)
{
    d->sort = sort;
}

int Objects::active() const
{
    return d->active;
}

void Objects::setActive(int active)
{
    d->active = active;
}

QString Objects::groups() const
{
    return d->groups;
}

void Objects::setGroups(const QString &groups)
{
    d->groups = groups;
}

Objects &Objects::operator=(const Objects &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

Objects Objects::create(const QString &objSname, const QString &objLnameDe, const QString &descDe, const QString &objLnameEn, const QString &descEn, int sort, int active, const QString &groups)
{
    ObjectsObject obj;
    obj.obj_sname = objSname;
    obj.obj_lname_de = objLnameDe;
    obj.desc_de = descDe;
    obj.obj_lname_en = objLnameEn;
    obj.desc_en = descEn;
    obj.sort = sort;
    obj.active = active;
    obj.groups = groups;
    if (!obj.create()) {
        return Objects();
    }
    return Objects(obj);
}

Objects Objects::create(const QVariantMap &values)
{
    Objects model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

Objects Objects::get(int id)
{
    TSqlORMapper<ObjectsObject> mapper;
    return Objects(mapper.findByPrimaryKey(id));
}

int Objects::count()
{
    TSqlORMapper<ObjectsObject> mapper;
    return mapper.findCount();
}

QList<Objects> Objects::getAll()
{
    return tfGetModelListByCriteria<Objects, ObjectsObject>(TCriteria());
}

QJsonArray Objects::getAllJson(const QString &active, const QString strGroups)
{

    TSqlQuery query;
    QJsonObject jsonObject;
    QJsonArray jsonArray;
    QString msg;

    QString andStr = strGroups;

 //id, obj_sname, obj_lname_de, desc_de, obj_lname_en, desc_en, sort, active
    //query.prepare("SELECT * FROM objects where active = ? order by sort");
    query.prepare("SELECT * FROM objects where " + andStr + " AND active = '1' order by sort");
    //query.addBindValue(active);
    query.addBindValue(andStr);

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
        jsonObject["obj_sname"] = query.value(1).toString();
        jsonObject["obj_lname_de"] = query.value(2).toString();
        jsonObject["desc_de"] = query.value(3).toString();
        jsonObject["obj_lname_en"] = query.value(4).toString();
        jsonObject["desc_en"] = query.value(5).toString();
        jsonObject["sort"] = query.value(6).toString();
        jsonObject["active"] = query.value(7).toString();
        jsonArray.append(jsonObject);
    }

    return jsonArray;
}

QJsonArray Objects::getAllJson(const QString &active)
{

    TSqlQuery query;
    QJsonObject jsonObject;
    QJsonArray jsonArray;
    QString msg;


 //id, obj_sname, obj_lname_de, desc_de, obj_lname_en, desc_en, sort, active
    query.prepare("SELECT * FROM objects where active = ? order by sort");
    query.addBindValue(active);

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
        jsonObject["obj_sname"] = query.value(1).toString();
        jsonObject["obj_lname_de"] = query.value(2).toString();
        jsonObject["desc_de"] = query.value(3).toString();
        jsonObject["obj_lname_en"] = query.value(4).toString();
        jsonObject["desc_en"] = query.value(5).toString();
        jsonObject["sort"] = query.value(6).toString();
        jsonObject["active"] = query.value(7).toString();
        jsonArray.append(jsonObject);
    }

    return jsonArray;
}

QJsonArray Objects::getAllJson()
{
    QJsonArray array;
    TSqlORMapper<ObjectsObject> mapper;

    if (mapper.find() > 0) {
        for (TSqlORMapperIterator<ObjectsObject> i(mapper); i.hasNext(); ) {
            array.append(QJsonValue(QJsonObject::fromVariantMap(Objects(i.next()).toVariantMap())));
        }
    }
    return array;
}

TModelObject *Objects::modelData()
{
    return d.data();
}

const TModelObject *Objects::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const Objects &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, Objects &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(Objects)
