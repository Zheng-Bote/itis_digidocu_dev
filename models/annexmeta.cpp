#include <TreeFrogModel>
#include "annexmeta.h"
#include "sqlobjects/annexmetaobject.h"

AnnexMeta::AnnexMeta() :
    TAbstractModel(),
    d(new AnnexMetaObject())
{
    // set the initial parameters
}

AnnexMeta::AnnexMeta(const AnnexMeta &other) :
    TAbstractModel(),
    d(other.d)
{ }

AnnexMeta::AnnexMeta(const AnnexMetaObject &object) :
    TAbstractModel(),
    d(new AnnexMetaObject(object))
{ }

AnnexMeta::~AnnexMeta()
{
    // If the reference count becomes 0,
    // the shared data object 'AnnexMetaObject' is deleted.
}

// #####

AnnexMeta AnnexMeta::getBySpecDataId(int spec_data_id)
{
    TSqlQuery query;

    query.prepare("SELECT id FROM public.annex_meta WHERE spec_data_id = ?");
    query.addBindValue(spec_data_id);

    query.exec();
    query.next();

    TSqlORMapper<AnnexMetaObject> mapper;
    return AnnexMeta(mapper.findByPrimaryKey(query.value(0).toInt()));
}

int AnnexMeta::id() const
{
    return d->id;
}

int AnnexMeta::specDataId() const
{
    return d->spec_data_id;
}

void AnnexMeta::setSpecDataId(int specDataId)
{
    d->spec_data_id = specDataId;
}

QDateTime AnnexMeta::specCreated() const
{
    return d->spec_created;
}

void AnnexMeta::setSpecCreated(const QDateTime &specCreated)
{
    d->spec_created = specCreated;
}

QDateTime AnnexMeta::specLastModified() const
{
    return d->spec_last_modified;
}

void AnnexMeta::setSpecLastModified(const QDateTime &specLastModified)
{
    d->spec_last_modified = specLastModified;
}

QDateTime AnnexMeta::specValidStart() const
{
    return d->spec_valid_start;
}

void AnnexMeta::setSpecValidStart(const QDateTime &specValidStart)
{
    d->spec_valid_start = specValidStart;
}

QDateTime AnnexMeta::specValidEnd() const
{
    return d->spec_valid_end;
}

void AnnexMeta::setSpecValidEnd(const QDateTime &specValidEnd)
{
    d->spec_valid_end = specValidEnd;
}

QString AnnexMeta::lastEditor() const
{
    return d->last_editor;
}

void AnnexMeta::setLastEditor(const QString &lastEditor)
{
    d->last_editor = lastEditor;
}

QString AnnexMeta::gLegacy() const
{
    return d->g_legacy;
}

void AnnexMeta::setGLegacy(const QString &gLegacy)
{
    d->g_legacy = gLegacy;
}

QString AnnexMeta::responsibility() const
{
    return d->responsibility;
}

void AnnexMeta::setResponsibility(const QString &responsibility)
{
    d->responsibility = responsibility;
}

QString AnnexMeta::specComment() const
{
    return d->spec_comment;
}

void AnnexMeta::setSpecComment(const QString &specComment)
{
    d->spec_comment = specComment;
}

QString AnnexMeta::specMarker() const
{
    return d->spec_marker;
}

void AnnexMeta::setSpecMarker(const QString &specMarker)
{
    d->spec_marker = specMarker;
}

QString AnnexMeta::groups() const
{
    return d->groups;
}

void AnnexMeta::setGroups(const QString &groups)
{
    d->groups = groups;
}

AnnexMeta &AnnexMeta::operator=(const AnnexMeta &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

AnnexMeta AnnexMeta::create(int specDataId, const QDateTime &specCreated, const QDateTime &specLastModified, const QDateTime &specValidStart, const QDateTime &specValidEnd, const QString &lastEditor, const QString &gLegacy, const QString &responsibility, const QString &specComment, const QString &specMarker, const QString &groups)
{
    AnnexMetaObject obj;
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
        return AnnexMeta();
    }
    return AnnexMeta(obj);
}

AnnexMeta AnnexMeta::create(const QVariantMap &values)
{
    AnnexMeta model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

AnnexMeta AnnexMeta::get(int id)
{
    TSqlORMapper<AnnexMetaObject> mapper;
    return AnnexMeta(mapper.findByPrimaryKey(id));
}

int AnnexMeta::count()
{
    TSqlORMapper<AnnexMetaObject> mapper;
    return mapper.findCount();
}

QList<AnnexMeta> AnnexMeta::getAll()
{
    return tfGetModelListByCriteria<AnnexMeta, AnnexMetaObject>(TCriteria());
}

QJsonArray AnnexMeta::getAllJson()
{
    QJsonArray array;
    TSqlORMapper<AnnexMetaObject> mapper;

    if (mapper.find() > 0) {
        for (TSqlORMapperIterator<AnnexMetaObject> i(mapper); i.hasNext(); ) {
            array.append(QJsonValue(QJsonObject::fromVariantMap(AnnexMeta(i.next()).toVariantMap())));
        }
    }
    return array;
}

TModelObject *AnnexMeta::modelData()
{
    return d.data();
}

const TModelObject *AnnexMeta::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const AnnexMeta &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, AnnexMeta &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(AnnexMeta)
