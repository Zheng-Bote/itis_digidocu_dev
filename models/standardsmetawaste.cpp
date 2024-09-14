#include <TreeFrogModel>
#include "standardsmetawaste.h"
#include "sqlobjects/standardsmetawasteobject.h"

StandardsMetaWaste::StandardsMetaWaste() :
    TAbstractModel(),
    d(new StandardsMetaWasteObject())
{
    // set the initial parameters
}

StandardsMetaWaste::StandardsMetaWaste(const StandardsMetaWaste &other) :
    TAbstractModel(),
    d(other.d)
{ }

StandardsMetaWaste::StandardsMetaWaste(const StandardsMetaWasteObject &object) :
    TAbstractModel(),
    d(new StandardsMetaWasteObject(object))
{ }

StandardsMetaWaste::~StandardsMetaWaste()
{
    // If the reference count becomes 0,
    // the shared data object 'StandardsMetaWasteObject' is deleted.
}

int StandardsMetaWaste::id() const
{
    return d->id;
}

QDateTime StandardsMetaWaste::changedOn() const
{
    return d->changed_on;
}

void StandardsMetaWaste::setChangedOn(const QDateTime &changedOn)
{
    d->changed_on = changedOn;
}

int StandardsMetaWaste::idOld() const
{
    return d->id_old;
}

void StandardsMetaWaste::setIdOld(int idOld)
{
    d->id_old = idOld;
}

int StandardsMetaWaste::specDataId() const
{
    return d->spec_data_id;
}

void StandardsMetaWaste::setSpecDataId(int specDataId)
{
    d->spec_data_id = specDataId;
}

QDateTime StandardsMetaWaste::specCreated() const
{
    return d->spec_created;
}

void StandardsMetaWaste::setSpecCreated(const QDateTime &specCreated)
{
    d->spec_created = specCreated;
}

QDateTime StandardsMetaWaste::specLastModified() const
{
    return d->spec_last_modified;
}

void StandardsMetaWaste::setSpecLastModified(const QDateTime &specLastModified)
{
    d->spec_last_modified = specLastModified;
}

QDateTime StandardsMetaWaste::specValidStart() const
{
    return d->spec_valid_start;
}

void StandardsMetaWaste::setSpecValidStart(const QDateTime &specValidStart)
{
    d->spec_valid_start = specValidStart;
}

QDateTime StandardsMetaWaste::specValidEnd() const
{
    return d->spec_valid_end;
}

void StandardsMetaWaste::setSpecValidEnd(const QDateTime &specValidEnd)
{
    d->spec_valid_end = specValidEnd;
}

QString StandardsMetaWaste::lastEditor() const
{
    return d->last_editor;
}

void StandardsMetaWaste::setLastEditor(const QString &lastEditor)
{
    d->last_editor = lastEditor;
}

QString StandardsMetaWaste::gLegacy() const
{
    return d->g_legacy;
}

void StandardsMetaWaste::setGLegacy(const QString &gLegacy)
{
    d->g_legacy = gLegacy;
}

QString StandardsMetaWaste::responsibility() const
{
    return d->responsibility;
}

void StandardsMetaWaste::setResponsibility(const QString &responsibility)
{
    d->responsibility = responsibility;
}

QString StandardsMetaWaste::specComment() const
{
    return d->spec_comment;
}

void StandardsMetaWaste::setSpecComment(const QString &specComment)
{
    d->spec_comment = specComment;
}

QString StandardsMetaWaste::specMarker() const
{
    return d->spec_marker;
}

void StandardsMetaWaste::setSpecMarker(const QString &specMarker)
{
    d->spec_marker = specMarker;
}

QString StandardsMetaWaste::groups() const
{
    return d->groups;
}

void StandardsMetaWaste::setGroups(const QString &groups)
{
    d->groups = groups;
}

StandardsMetaWaste &StandardsMetaWaste::operator=(const StandardsMetaWaste &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

StandardsMetaWaste StandardsMetaWaste::create(const QDateTime &changedOn, int idOld, int specDataId, const QDateTime &specCreated, const QDateTime &specLastModified, const QDateTime &specValidStart, const QDateTime &specValidEnd, const QString &lastEditor, const QString &gLegacy, const QString &responsibility, const QString &specComment, const QString &specMarker, const QString &groups)
{
    StandardsMetaWasteObject obj;
    obj.changed_on = changedOn;
    obj.id_old = idOld;
    obj.spec_data_id = specDataId;
    obj.spec_created = specCreated;
    obj.spec_last_modified = specLastModified;
    obj.spec_valid_start = specValidStart;
    obj.spec_valid_end = specValidEnd;
    obj.last_editor = lastEditor;
    obj.g_legacy = gLegacy;
    obj.responsibility = responsibility;
    obj.spec_comment = specComment;
    obj.spec_marker = specMarker;
    obj.groups = groups;
    if (!obj.create()) {
        return StandardsMetaWaste();
    }
    return StandardsMetaWaste(obj);
}

StandardsMetaWaste StandardsMetaWaste::create(const QVariantMap &values)
{
    StandardsMetaWaste model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

StandardsMetaWaste StandardsMetaWaste::get(int id)
{
    TSqlORMapper<StandardsMetaWasteObject> mapper;
    return StandardsMetaWaste(mapper.findByPrimaryKey(id));
}

int StandardsMetaWaste::count()
{
    TSqlORMapper<StandardsMetaWasteObject> mapper;
    return mapper.findCount();
}

QList<StandardsMetaWaste> StandardsMetaWaste::getAll()
{
    return tfGetModelListByCriteria<StandardsMetaWaste, StandardsMetaWasteObject>(TCriteria());
}

QJsonArray StandardsMetaWaste::getAllJson()
{
    QJsonArray array;
    TSqlORMapper<StandardsMetaWasteObject> mapper;

    if (mapper.find() > 0) {
        for (TSqlORMapperIterator<StandardsMetaWasteObject> i(mapper); i.hasNext(); ) {
            array.append(QJsonValue(QJsonObject::fromVariantMap(StandardsMetaWaste(i.next()).toVariantMap())));
        }
    }
    return array;
}

TModelObject *StandardsMetaWaste::modelData()
{
    return d.data();
}

const TModelObject *StandardsMetaWaste::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const StandardsMetaWaste &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, StandardsMetaWaste &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(StandardsMetaWaste)
