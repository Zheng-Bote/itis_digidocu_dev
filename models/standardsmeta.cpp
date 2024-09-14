#include <TreeFrogModel>
#include "standardsmeta.h"
#include "sqlobjects/standardsmetaobject.h"

StandardsMeta::StandardsMeta() :
    TAbstractModel(),
    d(new StandardsMetaObject())
{
    // set the initial parameters
}

StandardsMeta::StandardsMeta(const StandardsMeta &other) :
    TAbstractModel(),
    d(other.d)
{ }

StandardsMeta::StandardsMeta(const StandardsMetaObject &object) :
    TAbstractModel(),
    d(new StandardsMetaObject(object))
{ }

StandardsMeta::~StandardsMeta()
{
    // If the reference count becomes 0,
    // the shared data object 'StandardsMetaObject' is deleted.
}

// #####
void StandardsMeta::saveMeta(int id, QString username)
{
    TSqlQuery query;

    int year = QDate::currentDate().year() + 1;
    int month = QDate::currentDate().month();
    int day = QDate::currentDate().day();
    QString datetimeNext = QString::number(year);
    datetimeNext.append("-" + QString::number(month));
    datetimeNext.append("-" + QString::number(day));
    datetimeNext.append(" " + QDateTime::currentDateTime().toString());

    query.prepare("UPDATE public.standards_meta SET spec_last_modified=?, spec_valid_end=?, last_editor=? WHERE spec_data_id=?");
    query.addBindValue(QDateTime::currentDateTime());
    query.addBindValue(datetimeNext);
    query.addBindValue(username);
    query.addBindValue(id);
    query.exec();
}

int StandardsMeta::id() const
{
    return d->id;
}

int StandardsMeta::specDataId() const
{
    return d->spec_data_id;
}

void StandardsMeta::setSpecDataId(int specDataId)
{
    d->spec_data_id = specDataId;
}

QDateTime StandardsMeta::specCreated() const
{
    return d->spec_created;
}

void StandardsMeta::setSpecCreated(const QDateTime &specCreated)
{
    d->spec_created = specCreated;
}

QDateTime StandardsMeta::specLastModified() const
{
    return d->spec_last_modified;
}

void StandardsMeta::setSpecLastModified(const QDateTime &specLastModified)
{
    d->spec_last_modified = specLastModified;
}

QDateTime StandardsMeta::specValidStart() const
{
    return d->spec_valid_start;
}

void StandardsMeta::setSpecValidStart(const QDateTime &specValidStart)
{
    d->spec_valid_start = specValidStart;
}

QDateTime StandardsMeta::specValidEnd() const
{
    return d->spec_valid_end;
}

void StandardsMeta::setSpecValidEnd(const QDateTime &specValidEnd)
{
    d->spec_valid_end = specValidEnd;
}

QString StandardsMeta::lastEditor() const
{
    return d->last_editor;
}

void StandardsMeta::setLastEditor(const QString &lastEditor)
{
    d->last_editor = lastEditor;
}

QString StandardsMeta::gLegacy() const
{
    return d->g_legacy;
}

void StandardsMeta::setGLegacy(const QString &gLegacy)
{
    d->g_legacy = gLegacy;
}

QString StandardsMeta::responsibility() const
{
    return d->responsibility;
}

void StandardsMeta::setResponsibility(const QString &responsibility)
{
    d->responsibility = responsibility;
}

QString StandardsMeta::specComment() const
{
    return d->spec_comment;
}

void StandardsMeta::setSpecComment(const QString &specComment)
{
    d->spec_comment = specComment;
}

QString StandardsMeta::specMarker() const
{
    return d->spec_marker;
}

void StandardsMeta::setSpecMarker(const QString &specMarker)
{
    d->spec_marker = specMarker;
}

QString StandardsMeta::groups() const
{
    return d->groups;
}

void StandardsMeta::setGroups(const QString &groups)
{
    d->groups = groups;
}

StandardsMeta &StandardsMeta::operator=(const StandardsMeta &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

StandardsMeta StandardsMeta::create(int specDataId, const QDateTime &specCreated, const QDateTime &specLastModified, const QDateTime &specValidStart, const QDateTime &specValidEnd, const QString &lastEditor, const QString &gLegacy, const QString &responsibility, const QString &specComment, const QString &specMarker, const QString &groups)
{
    StandardsMetaObject obj;
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
        return StandardsMeta();
    }
    return StandardsMeta(obj);
}

StandardsMeta StandardsMeta::create(const QVariantMap &values)
{
    StandardsMeta model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

StandardsMeta StandardsMeta::getBySpecDataId(int spec_data_id)
{
    TSqlQuery query;

    query.prepare("SELECT id FROM public.standards_meta WHERE spec_data_id = ?");
    query.addBindValue(spec_data_id);

    query.exec();
    query.next();

    TSqlORMapper<StandardsMetaObject> mapper;
    return StandardsMeta(mapper.findByPrimaryKey(query.value(0).toInt()));
}

StandardsMeta StandardsMeta::get(int id)
{
    TSqlORMapper<StandardsMetaObject> mapper;
    return StandardsMeta(mapper.findByPrimaryKey(id));
}

int StandardsMeta::count()
{
    TSqlORMapper<StandardsMetaObject> mapper;
    return mapper.findCount();
}

QList<StandardsMeta> StandardsMeta::getAll()
{
    return tfGetModelListByCriteria<StandardsMeta, StandardsMetaObject>(TCriteria());
}

QJsonArray StandardsMeta::getAllJson()
{
    QJsonArray array;
    TSqlORMapper<StandardsMetaObject> mapper;

    if (mapper.find() > 0) {
        for (TSqlORMapperIterator<StandardsMetaObject> i(mapper); i.hasNext(); ) {
            array.append(QJsonValue(QJsonObject::fromVariantMap(StandardsMeta(i.next()).toVariantMap())));
        }
    }
    return array;
}

TModelObject *StandardsMeta::modelData()
{
    return d.data();
}

const TModelObject *StandardsMeta::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const StandardsMeta &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, StandardsMeta &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(StandardsMeta)
