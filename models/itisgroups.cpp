#include <TreeFrogModel>
#include "itisgroups.h"
#include "sqlobjects/itisgroupsobject.h"

ItisGroups::ItisGroups() :
    TAbstractModel(),
    d(new ItisGroupsObject())
{
    // set the initial parameters
}

ItisGroups::ItisGroups(const ItisGroups &other) :
    TAbstractModel(),
    d(other.d)
{ }

ItisGroups::ItisGroups(const ItisGroupsObject &object) :
    TAbstractModel(),
    d(new ItisGroupsObject(object))
{ }

ItisGroups::~ItisGroups()
{
    // If the reference count becomes 0,
    // the shared data object 'ItisGroupsObject' is deleted.
}

// #####

int ItisGroups::id() const
{
    return d->id;
}

QString ItisGroups::groupname() const
{
    return d->groupname;
}

void ItisGroups::setGroupname(const QString &groupname)
{
    d->groupname = groupname;
}

QString ItisGroups::groupdesc() const
{
    return d->groupdesc;
}

void ItisGroups::setGroupdesc(const QString &groupdesc)
{
    d->groupdesc = groupdesc;
}

int ItisGroups::active() const
{
    return d->active;
}

void ItisGroups::setActive(int active)
{
    d->active = active;
}

ItisGroups &ItisGroups::operator=(const ItisGroups &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

ItisGroups ItisGroups::create(const QString &groupname, const QString &groupdesc, int active)
{
    ItisGroupsObject obj;
    obj.groupname = groupname;
    obj.groupdesc = groupdesc;
    obj.active = active;
    if (!obj.create()) {
        return ItisGroups();
    }
    return ItisGroups(obj);
}

ItisGroups ItisGroups::create(const QVariantMap &values)
{
    ItisGroups model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

ItisGroups ItisGroups::get(int id)
{
    TSqlORMapper<ItisGroupsObject> mapper;
    return ItisGroups(mapper.findByPrimaryKey(id));
}

int ItisGroups::count()
{
    TSqlORMapper<ItisGroupsObject> mapper;
    return mapper.findCount();
}

QList<ItisGroups> ItisGroups::getAll()
{
    return tfGetModelListByCriteria<ItisGroups, ItisGroupsObject>(TCriteria());
}

QJsonArray ItisGroups::getAllJson()
{
    QJsonArray array;
    TSqlORMapper<ItisGroupsObject> mapper;

    if (mapper.find() > 0) {
        for (TSqlORMapperIterator<ItisGroupsObject> i(mapper); i.hasNext(); ) {
            array.append(QJsonValue(QJsonObject::fromVariantMap(ItisGroups(i.next()).toVariantMap())));
        }
    }
    return array;
}

TModelObject *ItisGroups::modelData()
{
    return d.data();
}

const TModelObject *ItisGroups::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const ItisGroups &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, ItisGroups &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(ItisGroups)
