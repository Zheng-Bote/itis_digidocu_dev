#include <TreeFrogModel>
#include "stdsystem.h"
#include "sqlobjects/stdsystemobject.h"

StdSystem::StdSystem() :
    TAbstractModel(),
    d(new StdSystemObject())
{
    // set the initial parameters
}

StdSystem::StdSystem(const StdSystem &other) :
    TAbstractModel(),
    d(other.d)
{ }

StdSystem::StdSystem(const StdSystemObject &object) :
    TAbstractModel(),
    d(new StdSystemObject(object))
{ }

StdSystem::~StdSystem()
{
    // If the reference count becomes 0,
    // the shared data object 'StdSystemObject' is deleted.
}

// #####

QString StdSystem::convertDate(QDate buildtime)
{
    return buildtime.toString("yyyy-MM-dd");
}

QString StdSystem::getAppVersion()
{
    return ("IT-IS ReST API v00.01.00-Beta+20");
}

// #####

QJsonArray StdSystem::getAllJson(const QString &active, const QString &std_type)
{

    TSqlQuery query;
    QJsonObject jsonObject;
    QJsonArray jsonArray;
    QString msg;

    query.prepare("SELECT * FROM std_system WHERE active = ? AND std_type = ? order by sort");
    query.addBindValue(active);
    query.addBindValue(std_type);

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
        jsonObject["std_type"] = query.value(1).toString();
        jsonObject["std_attr"] = query.value(2).toString();
        jsonObject["std_val"] = query.value(3).toString();
        jsonObject["std_flag"] = query.value(4).toString();
        jsonObject["sort"] = query.value(5).toString();
        jsonObject["active"] = query.value(6).toString();

        jsonArray.append(jsonObject);
    }

    return jsonArray;
}

int StdSystem::id() const
{
    return d->id;
}

QString StdSystem::stdType() const
{
    return d->std_type;
}

void StdSystem::setStdType(const QString &stdType)
{
    d->std_type = stdType;
}

QString StdSystem::stdAttr() const
{
    return d->std_attr;
}

void StdSystem::setStdAttr(const QString &stdAttr)
{
    d->std_attr = stdAttr;
}

QString StdSystem::stdVal() const
{
    return d->std_val;
}

void StdSystem::setStdVal(const QString &stdVal)
{
    d->std_val = stdVal;
}

QString StdSystem::stdFlag() const
{
    return d->std_flag;
}

void StdSystem::setStdFlag(const QString &stdFlag)
{
    d->std_flag = stdFlag;
}

int StdSystem::sort() const
{
    return d->sort;
}

void StdSystem::setSort(int sort)
{
    d->sort = sort;
}

int StdSystem::active() const
{
    return d->active;
}

void StdSystem::setActive(int active)
{
    d->active = active;
}

StdSystem &StdSystem::operator=(const StdSystem &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

StdSystem StdSystem::create(const QString &stdType, const QString &stdAttr, const QString &stdVal, const QString &stdFlag, int sort, int active)
{
    StdSystemObject obj;
    obj.std_type = stdType;
    obj.std_attr = stdAttr;
    obj.std_val = stdVal;
    obj.std_flag = stdFlag;
    obj.sort = sort;
    obj.active = active;
    if (!obj.create()) {
        return StdSystem();
    }
    return StdSystem(obj);
}

StdSystem StdSystem::create(const QVariantMap &values)
{
    StdSystem model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

StdSystem StdSystem::get(int id)
{
    TSqlORMapper<StdSystemObject> mapper;
    return StdSystem(mapper.findByPrimaryKey(id));
}

int StdSystem::count()
{
    TSqlORMapper<StdSystemObject> mapper;
    return mapper.findCount();
}

QList<StdSystem> StdSystem::getAll()
{
    return tfGetModelListByCriteria<StdSystem, StdSystemObject>(TCriteria());
}

QJsonArray StdSystem::getAllJson()
{
    QJsonArray array;
    TSqlORMapper<StdSystemObject> mapper;

    if (mapper.find() > 0) {
        for (TSqlORMapperIterator<StdSystemObject> i(mapper); i.hasNext(); ) {
            array.append(QJsonValue(QJsonObject::fromVariantMap(StdSystem(i.next()).toVariantMap())));
        }
    }
    return array;
}

TModelObject *StdSystem::modelData()
{
    return d.data();
}

const TModelObject *StdSystem::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const StdSystem &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, StdSystem &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(StdSystem)
