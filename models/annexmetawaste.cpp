#include <TreeFrogModel>
#include "annexmetawaste.h"
#include "sqlobjects/annexmetawasteobject.h"

AnnexMetaWaste::AnnexMetaWaste() :
    TAbstractModel(),
    d(new AnnexMetaWasteObject())
{
    // set the initial parameters
}

AnnexMetaWaste::AnnexMetaWaste(const AnnexMetaWaste &other) :
    TAbstractModel(),
    d(other.d)
{ }

AnnexMetaWaste::AnnexMetaWaste(const AnnexMetaWasteObject &object) :
    TAbstractModel(),
    d(new AnnexMetaWasteObject(object))
{ }

AnnexMetaWaste::~AnnexMetaWaste()
{
    // If the reference count becomes 0,
    // the shared data object 'AnnexMetaWasteObject' is deleted.
}

int AnnexMetaWaste::id() const
{
    return d->id;
}

QDateTime AnnexMetaWaste::changedOn() const
{
    return d->changed_on;
}

void AnnexMetaWaste::setChangedOn(const QDateTime &changedOn)
{
    d->changed_on = changedOn;
}

int AnnexMetaWaste::idOld() const
{
    return d->id_old;
}

void AnnexMetaWaste::setIdOld(int idOld)
{
    d->id_old = idOld;
}

int AnnexMetaWaste::specDataId() const
{
    return d->spec_data_id;
}

void AnnexMetaWaste::setSpecDataId(int specDataId)
{
    d->spec_data_id = specDataId;
}

QDateTime AnnexMetaWaste::specCreated() const
{
    return d->spec_created;
}

void AnnexMetaWaste::setSpecCreated(const QDateTime &specCreated)
{
    d->spec_created = specCreated;
}

QDateTime AnnexMetaWaste::specLastModified() const
{
    return d->spec_last_modified;
}

void AnnexMetaWaste::setSpecLastModified(const QDateTime &specLastModified)
{
    d->spec_last_modified = specLastModified;
}

QDateTime AnnexMetaWaste::specValidStart() const
{
    return d->spec_valid_start;
}

void AnnexMetaWaste::setSpecValidStart(const QDateTime &specValidStart)
{
    d->spec_valid_start = specValidStart;
}

QDateTime AnnexMetaWaste::specValidEnd() const
{
    return d->spec_valid_end;
}

void AnnexMetaWaste::setSpecValidEnd(const QDateTime &specValidEnd)
{
    d->spec_valid_end = specValidEnd;
}

QString AnnexMetaWaste::lastEditor() const
{
    return d->last_editor;
}

void AnnexMetaWaste::setLastEditor(const QString &lastEditor)
{
    d->last_editor = lastEditor;
}

QString AnnexMetaWaste::gLegacy() const
{
    return d->g_legacy;
}

void AnnexMetaWaste::setGLegacy(const QString &gLegacy)
{
    d->g_legacy = gLegacy;
}

QString AnnexMetaWaste::responsibility() const
{
    return d->responsibility;
}

void AnnexMetaWaste::setResponsibility(const QString &responsibility)
{
    d->responsibility = responsibility;
}

QString AnnexMetaWaste::specComment() const
{
    return d->spec_comment;
}

void AnnexMetaWaste::setSpecComment(const QString &specComment)
{
    d->spec_comment = specComment;
}

QString AnnexMetaWaste::specMarker() const
{
    return d->spec_marker;
}

void AnnexMetaWaste::setSpecMarker(const QString &specMarker)
{
    d->spec_marker = specMarker;
}

QString AnnexMetaWaste::groups() const
{
    return d->groups;
}

void AnnexMetaWaste::setGroups(const QString &groups)
{
    d->groups = groups;
}

AnnexMetaWaste &AnnexMetaWaste::operator=(const AnnexMetaWaste &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

AnnexMetaWaste AnnexMetaWaste::create(const QDateTime &changedOn, int idOld, int specDataId, const QDateTime &specCreated, const QDateTime &specLastModified, const QDateTime &specValidStart, const QDateTime &specValidEnd, const QString &lastEditor, const QString &gLegacy, const QString &responsibility, const QString &specComment, const QString &specMarker, const QString &groups)
{
    AnnexMetaWasteObject obj;
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
        return AnnexMetaWaste();
    }
    return AnnexMetaWaste(obj);
}

AnnexMetaWaste AnnexMetaWaste::create(const QVariantMap &values)
{
    AnnexMetaWaste model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

AnnexMetaWaste AnnexMetaWaste::get(int id)
{
    TSqlORMapper<AnnexMetaWasteObject> mapper;
    return AnnexMetaWaste(mapper.findByPrimaryKey(id));
}

int AnnexMetaWaste::count()
{
    TSqlORMapper<AnnexMetaWasteObject> mapper;
    return mapper.findCount();
}

QList<AnnexMetaWaste> AnnexMetaWaste::getAll()
{
    return tfGetModelListByCriteria<AnnexMetaWaste, AnnexMetaWasteObject>(TCriteria());
}

QJsonArray AnnexMetaWaste::getAllJson()
{
    QJsonArray array;
    TSqlORMapper<AnnexMetaWasteObject> mapper;

    if (mapper.find() > 0) {
        for (TSqlORMapperIterator<AnnexMetaWasteObject> i(mapper); i.hasNext(); ) {
            array.append(QJsonValue(QJsonObject::fromVariantMap(AnnexMetaWaste(i.next()).toVariantMap())));
        }
    }
    return array;
}

TModelObject *AnnexMetaWaste::modelData()
{
    return d.data();
}

const TModelObject *AnnexMetaWaste::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const AnnexMetaWaste &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, AnnexMetaWaste &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(AnnexMetaWaste)
