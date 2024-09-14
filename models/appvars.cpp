#include <TreeFrogModel>
#include "appvars.h"
#include "sqlobjects/appvarsobject.h"

AppVars::AppVars() :
    TAbstractModel(),
    d(new AppVarsObject())
{
    // set the initial parameters
}

AppVars::AppVars(const AppVars &other) :
    TAbstractModel(),
    d(other.d)
{ }

AppVars::AppVars(const AppVarsObject &object) :
    TAbstractModel(),
    d(new AppVarsObject(object))
{ }

AppVars::~AppVars()
{
    // If the reference count becomes 0,
    // the shared data object 'AppVarsObject' is deleted.
}

int AppVars::id() const
{
    return d->id;
}

QString AppVars::stdType() const
{
    return d->std_type;
}

void AppVars::setStdType(const QString &stdType)
{
    d->std_type = stdType;
}

QString AppVars::stdAttr() const
{
    return d->std_attr;
}

void AppVars::setStdAttr(const QString &stdAttr)
{
    d->std_attr = stdAttr;
}

QString AppVars::stdValDe() const
{
    return d->std_val_de;
}

void AppVars::setStdValDe(const QString &stdValDe)
{
    d->std_val_de = stdValDe;
}

QString AppVars::stdValEn() const
{
    return d->std_val_en;
}

void AppVars::setStdValEn(const QString &stdValEn)
{
    d->std_val_en = stdValEn;
}

int AppVars::active() const
{
    return d->active;
}

void AppVars::setActive(int active)
{
    d->active = active;
}

AppVars &AppVars::operator=(const AppVars &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

AppVars AppVars::create(const QString &stdType, const QString &stdAttr, const QString &stdValDe, const QString &stdValEn, int active)
{
    AppVarsObject obj;
    obj.std_type = stdType;
    obj.std_attr = stdAttr;
    obj.std_val_de = stdValDe;
    obj.std_val_en = stdValEn;
    obj.active = active;
    if (!obj.create()) {
        return AppVars();
    }
    return AppVars(obj);
}

AppVars AppVars::create(const QVariantMap &values)
{
    AppVars model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

AppVars AppVars::get(int id)
{
    TSqlORMapper<AppVarsObject> mapper;
    return AppVars(mapper.findByPrimaryKey(id));
}

int AppVars::count()
{
    TSqlORMapper<AppVarsObject> mapper;
    return mapper.findCount();
}

QList<AppVars> AppVars::getAll()
{
    return tfGetModelListByCriteria<AppVars, AppVarsObject>(TCriteria());
}

QJsonArray AppVars::getAllJson()
{
    QJsonArray array;
    TSqlORMapper<AppVarsObject> mapper;

    if (mapper.find() > 0) {
        for (TSqlORMapperIterator<AppVarsObject> i(mapper); i.hasNext(); ) {
            array.append(QJsonValue(QJsonObject::fromVariantMap(AppVars(i.next()).toVariantMap())));
        }
    }
    return array;
}

TModelObject *AppVars::modelData()
{
    return d.data();
}

const TModelObject *AppVars::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const AppVars &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, AppVars &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(AppVars)
