#include <TreeFrogModel>
#include "acclasses.h"
#include "sqlobjects/acclassesobject.h"

AcClasses::AcClasses() :
    TAbstractModel(),
    d(new AcClassesObject())
{
    // set the initial parameters
}

AcClasses::AcClasses(const AcClasses &other) :
    TAbstractModel(),
    d(other.d)
{ }

AcClasses::AcClasses(const AcClassesObject &object) :
    TAbstractModel(),
    d(new AcClassesObject(object))
{ }

AcClasses::~AcClasses()
{
    // If the reference count becomes 0,
    // the shared data object 'AcClassesObject' is deleted.
}

// #####

QJsonArray AcClasses::getObjAcJson(QString &obj, int &active)
{
    TSqlQuery query;
    QJsonObject jsonObject;
    QJsonArray jsonArray;
    QString msg;

    query.prepare("SELECT id, obj_sname, ac_class, active FROM public.ac_classes WHERE obj_sname = ? AND active = ? order by ac_class");
    query.addBindValue(obj);
    query.addBindValue(active);

    if(!query.exec())
    {
        msg = query.lastError().text();
        jsonObject["errMsg"] = msg;
        jsonObject["ERROR"] = "1";
        jsonArray.append(jsonObject);
        return jsonArray;
    }

    while (query.next())
    {
        jsonObject["id"] = query.value(0).toString();
        jsonObject["obj_sname"] = query.value(1).toString();
        jsonObject["ac_class"] = query.value(2).toString();
        jsonObject["active"] = query.value(3).toString();
        jsonArray.append(jsonObject);
    }
    jsonObject = QJsonObject();
    jsonObject["ERROR"] = "0";
    jsonArray.append(jsonObject);
    return jsonArray;
}

QJsonArray AcClasses::getAcClassesJson()
{
    TSqlQuery query;
    QJsonObject jsonObject;
    QJsonArray jsonArray;
    QString msg;

    query.prepare("SELECT distinct(ac_class) FROM public.ac_classes order by ac_class;");

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
        jsonObject["ac_class"] = query.value(0).toString();
        jsonArray.append(jsonObject);
    }

    return jsonArray;
}

int AcClasses::id() const
{
    return d->id;
}

QString AcClasses::objSname() const
{
    return d->obj_sname;
}

void AcClasses::setObjSname(const QString &objSname)
{
    d->obj_sname = objSname;
}

int AcClasses::acClass() const
{
    return d->ac_class;
}

void AcClasses::setAcClass(int acClass)
{
    d->ac_class = acClass;
}

QString AcClasses::classType() const
{
    return d->class_type;
}

void AcClasses::setClassType(const QString &classType)
{
    d->class_type = classType;
}

int AcClasses::active() const
{
    return d->active;
}

void AcClasses::setActive(int active)
{
    d->active = active;
}

AcClasses &AcClasses::operator=(const AcClasses &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

AcClasses AcClasses::create(const QString &objSname, int acClass, const QString &classType, int active)
{
    AcClassesObject obj;
    obj.obj_sname = objSname;
    obj.ac_class = acClass;
    obj.class_type = classType;
    obj.active = active;
    if (!obj.create()) {
        return AcClasses();
    }
    return AcClasses(obj);
}

AcClasses AcClasses::create(const QVariantMap &values)
{
    AcClasses model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

AcClasses AcClasses::get(int id)
{
    TSqlORMapper<AcClassesObject> mapper;
    return AcClasses(mapper.findByPrimaryKey(id));
}

int AcClasses::count()
{
    TSqlORMapper<AcClassesObject> mapper;
    return mapper.findCount();
}

QList<AcClasses> AcClasses::getAll()
{
    return tfGetModelListByCriteria<AcClasses, AcClassesObject>(TCriteria());
}

QJsonArray AcClasses::getAllJson()
{
    QJsonArray array;
    TSqlORMapper<AcClassesObject> mapper;

    if (mapper.find() > 0) {
        for (TSqlORMapperIterator<AcClassesObject> i(mapper); i.hasNext(); ) {
            array.append(QJsonValue(QJsonObject::fromVariantMap(AcClasses(i.next()).toVariantMap())));
        }
    }
    return array;
}

TModelObject *AcClasses::modelData()
{
    return d.data();
}

const TModelObject *AcClasses::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const AcClasses &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, AcClasses &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(AcClasses)
