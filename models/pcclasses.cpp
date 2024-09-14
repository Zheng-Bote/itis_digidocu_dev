#include <TreeFrogModel>
#include "pcclasses.h"
#include "sqlobjects/pcclassesobject.h"

PcClasses::PcClasses() :
    TAbstractModel(),
    d(new PcClassesObject())
{
    // set the initial parameters
}

PcClasses::PcClasses(const PcClasses &other) :
    TAbstractModel(),
    d(other.d)
{ }

PcClasses::PcClasses(const PcClassesObject &object) :
    TAbstractModel(),
    d(new PcClassesObject(object))
{ }

PcClasses::~PcClasses()
{
    // If the reference count becomes 0,
    // the shared data object 'PcClassesObject' is deleted.
}

// #####

QJsonArray PcClasses::getObjPcJson(QString &obj, int &active)
{
    TSqlQuery query;
    QJsonObject jsonObject;
    QJsonArray jsonArray;
    QString msg;

    query.prepare("SELECT id, obj_sname, pc_class, active FROM public.pc_classes WHERE obj_sname = ? AND active = ?  order by pc_class");
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
        jsonObject["pc_class"] = query.value(2).toString();
        jsonObject["active"] = query.value(3).toString();
        jsonArray.append(jsonObject);
    }
    jsonObject = QJsonObject();
    jsonObject["ERROR"] = "0";
    jsonArray.append(jsonObject);

    return jsonArray;
}

QJsonArray PcClasses::getPcClassesJson()
{
    TSqlQuery query;
    QJsonObject jsonObject;
    QJsonArray jsonArray;
    QString msg;

    query.prepare("SELECT distinct(pc_class) FROM public.pc_classes order by pc_class;");

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
        jsonObject["pc_class"] = query.value(0).toString();
        jsonArray.append(jsonObject);
    }

    return jsonArray;
}

int PcClasses::id() const
{
    return d->id;
}

QString PcClasses::objSname() const
{
    return d->obj_sname;
}

void PcClasses::setObjSname(const QString &objSname)
{
    d->obj_sname = objSname;
}

int PcClasses::pcClass() const
{
    return d->pc_class;
}

void PcClasses::setPcClass(int pcClass)
{
    d->pc_class = pcClass;
}

QString PcClasses::classType() const
{
    return d->class_type;
}

void PcClasses::setClassType(const QString &classType)
{
    d->class_type = classType;
}

int PcClasses::active() const
{
    return d->active;
}

void PcClasses::setActive(int active)
{
    d->active = active;
}

PcClasses &PcClasses::operator=(const PcClasses &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

PcClasses PcClasses::create(const QString &objSname, int pcClass, const QString &classType, int active)
{
    PcClassesObject obj;
    obj.obj_sname = objSname;
    obj.pc_class = pcClass;
    obj.class_type = classType;
    obj.active = active;
    if (!obj.create()) {
        return PcClasses();
    }
    return PcClasses(obj);
}

PcClasses PcClasses::create(const QVariantMap &values)
{
    PcClasses model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

PcClasses PcClasses::get(int id)
{
    TSqlORMapper<PcClassesObject> mapper;
    return PcClasses(mapper.findByPrimaryKey(id));
}

int PcClasses::count()
{
    TSqlORMapper<PcClassesObject> mapper;
    return mapper.findCount();
}

QList<PcClasses> PcClasses::getAll()
{
    return tfGetModelListByCriteria<PcClasses, PcClassesObject>(TCriteria());
}

QJsonArray PcClasses::getAllJson()
{
    QJsonArray array;
    TSqlORMapper<PcClassesObject> mapper;

    if (mapper.find() > 0) {
        for (TSqlORMapperIterator<PcClassesObject> i(mapper); i.hasNext(); ) {
            array.append(QJsonValue(QJsonObject::fromVariantMap(PcClasses(i.next()).toVariantMap())));
        }
    }
    return array;
}

TModelObject *PcClasses::modelData()
{
    return d.data();
}

const TModelObject *PcClasses::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const PcClasses &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, PcClasses &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(PcClasses)
