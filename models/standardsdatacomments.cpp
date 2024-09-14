#include <TreeFrogModel>
#include "standardsdatacomments.h"
#include "sqlobjects/standardsdatacommentsobject.h"

StandardsDataComments::StandardsDataComments() :
    TAbstractModel(),
    d(new StandardsDataCommentsObject())
{
    // set the initial parameters
}

StandardsDataComments::StandardsDataComments(const StandardsDataComments &other) :
    TAbstractModel(),
    d(other.d)
{ }

StandardsDataComments::StandardsDataComments(const StandardsDataCommentsObject &object) :
    TAbstractModel(),
    d(new StandardsDataCommentsObject(object))
{ }

StandardsDataComments::~StandardsDataComments()
{
    // If the reference count becomes 0,
    // the shared data object 'StandardsDataCommentsObject' is deleted.
}

// #####

int StandardsDataComments::getSpecsCommentsCount(const int &spec_id)
{
    TSqlQuery query;
    QJsonObject jsonObject;
    QJsonArray jsonArray;
    QString msg;

    query.prepare("SELECT count(id) FROM public.standards_data_comments WHERE spec_id = ?");
    query.addBindValue(spec_id);

    query.exec();
    query.next();
    return query.value(0).toInt();
}

QJsonArray StandardsDataComments::getSpecComments(const int &spec_id)
{
    TSqlQuery query;
    QJsonObject jsonObject;
    QJsonArray jsonArray;
    QString msg;

    query.prepare("SELECT id, spec_id, user_comment FROM public.standards_data_comments WHERE spec_id = ?");
    query.addBindValue(spec_id);

    if(!query.exec())
     {
        msg = query.lastError().text();
        jsonObject["errMsg"] = msg;
        jsonObject["ERROR"] = "1";
        jsonArray.append(jsonObject);
     }

     while (query.next())
     {
        jsonObject["id"] = query.value(0).toString();
        jsonObject["spec_id"] = query.value(1).toString();
        jsonObject["user_comment"] = query.value(2).toString();

        jsonArray.append(jsonObject);
     }

     return jsonArray;
}

QMap<QString, QString> StandardsDataComments::getStatistics()
{
    TSqlQuery query;
    QMap<QString, QString> qmapStatistik;

    // count
    query.prepare("SELECT count(id) FROM standards_data_comments");
    query.exec();
    query.next();
    qmapStatistik["count_id"] = query.value(0).toString();

    // users
    query.prepare("SELECT count (distinct username) FROM standards_data_comments");
    query.exec();
    query.next();
    qmapStatistik["count_users"] = query.value(0).toString();

    return qmapStatistik;
}

int StandardsDataComments::id() const
{
    return d->id;
}

QDateTime StandardsDataComments::commentCreated() const
{
    return d->comment_created;
}

void StandardsDataComments::setCommentCreated(const QDateTime &commentCreated)
{
    d->comment_created = commentCreated;
}

int StandardsDataComments::specId() const
{
    return d->spec_id;
}

void StandardsDataComments::setSpecId(int specId)
{
    d->spec_id = specId;
}

QString StandardsDataComments::specTitle() const
{
    return d->spec_title;
}

void StandardsDataComments::setSpecTitle(const QString &specTitle)
{
    d->spec_title = specTitle;
}

QString StandardsDataComments::specVersion() const
{
    return d->spec_version;
}

void StandardsDataComments::setSpecVersion(const QString &specVersion)
{
    d->spec_version = specVersion;
}

QString StandardsDataComments::userComment() const
{
    return d->user_comment;
}

void StandardsDataComments::setUserComment(const QString &userComment)
{
    d->user_comment = userComment;
}

QString StandardsDataComments::username() const
{
    return d->username;
}

void StandardsDataComments::setUsername(const QString &username)
{
    d->username = username;
}

StandardsDataComments &StandardsDataComments::operator=(const StandardsDataComments &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

QJsonArray StandardsDataComments::createComment(int spec_id, const QString &spec_title, const QString &spec_version, const QString &user_comment, const QString &username)
{
    TSqlQuery query;
    QString msg;
    QJsonObject jsonObj;
    QJsonArray jsonArray;

    query.prepare("INSERT INTO public.standards_data_comments(comment_created, spec_id, spec_title, spec_version, user_comment, username) VALUES((:comment_created),(:spec_id),(:spec_title),(:spec_version),(:user_comment),(:username))");
    query.bindValue(":comment_created", QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss"));
    query.bindValue(":spec_id", spec_id);
    query.bindValue(":spec_title", spec_title);
    query.bindValue(":spec_version", spec_version);
    query.bindValue(":user_comment", user_comment);
    query.bindValue(":username",username);

    if(!query.exec())
    {
        msg = query.lastError().text();
        jsonObj["ERROR"] = "1";
        jsonObj["errMsg"] = msg;
        tError("setUserPwd " + msg.toUtf8());
    }
    else
    {
        jsonObj["ERROR"] = "0";
        jsonObj["errMsg"] = "Newsletter config modified";
    }

    jsonArray.append(jsonObj);
    return jsonArray;
}

StandardsDataComments StandardsDataComments::create(const QDateTime &commentCreated, int specId, const QString &specTitle, const QString &specVersion, const QString &userComment, const QString &username)
{
    StandardsDataCommentsObject obj;
    obj.comment_created = commentCreated;
    obj.spec_id = specId;
    obj.spec_title = specTitle;
    obj.spec_version = specVersion;
    obj.user_comment = userComment;
    obj.username = username;
    if (!obj.create()) {
        return StandardsDataComments();
    }
    return StandardsDataComments(obj);
}

StandardsDataComments StandardsDataComments::create(const QVariantMap &values)
{
    StandardsDataComments model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

StandardsDataComments StandardsDataComments::get(int id)
{
    TSqlORMapper<StandardsDataCommentsObject> mapper;
    return StandardsDataComments(mapper.findByPrimaryKey(id));
}

int StandardsDataComments::count()
{
    TSqlORMapper<StandardsDataCommentsObject> mapper;
    return mapper.findCount();
}

QList<StandardsDataComments> StandardsDataComments::getAll()
{
    return tfGetModelListByCriteria<StandardsDataComments, StandardsDataCommentsObject>(TCriteria());
}

QJsonArray StandardsDataComments::getAllJson()
{
    QJsonArray array;
    TSqlORMapper<StandardsDataCommentsObject> mapper;

    if (mapper.find() > 0) {
        for (TSqlORMapperIterator<StandardsDataCommentsObject> i(mapper); i.hasNext(); ) {
            array.append(QJsonValue(QJsonObject::fromVariantMap(StandardsDataComments(i.next()).toVariantMap())));
        }
    }
    return array;
}

TModelObject *StandardsDataComments::modelData()
{
    return d.data();
}

const TModelObject *StandardsDataComments::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const StandardsDataComments &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, StandardsDataComments &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(StandardsDataComments)
