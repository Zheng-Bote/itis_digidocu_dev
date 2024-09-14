#include <TreeFrogModel>
#include "annexdatacomments.h"
#include "sqlobjects/annexdatacommentsobject.h"

AnnexDataComments::AnnexDataComments() :
    TAbstractModel(),
    d(new AnnexDataCommentsObject())
{
    // set the initial parameters
}

AnnexDataComments::AnnexDataComments(const AnnexDataComments &other) :
    TAbstractModel(),
    d(other.d)
{ }

AnnexDataComments::AnnexDataComments(const AnnexDataCommentsObject &object) :
    TAbstractModel(),
    d(new AnnexDataCommentsObject(object))
{ }

AnnexDataComments::~AnnexDataComments()
{
    // If the reference count becomes 0,
    // the shared data object 'AnnexDataCommentsObject' is deleted.
}

// #####

int AnnexDataComments::getSpecsCommentsCount(const int &spec_id)
{
    TSqlQuery query;
    QJsonObject jsonObject;
    QJsonArray jsonArray;
    QString msg;

    query.prepare("SELECT count(id) FROM public.annex_data_comments WHERE spec_id = ?");
    query.addBindValue(spec_id);

    query.exec();
    query.next();
    return query.value(0).toInt();
}

QJsonArray AnnexDataComments::getSpecComments(const int &spec_id)
{
    TSqlQuery query;
    QJsonObject jsonObject;
    QJsonArray jsonArray;
    QString msg;

    query.prepare("SELECT id, spec_id, user_comment FROM public.annex_data_comments WHERE spec_id = ?");
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

QMap<QString, QString> AnnexDataComments::getStatistics()
{
    TSqlQuery query;
    QMap<QString, QString> qmapStatistik;

    // count
    query.prepare("SELECT count(id) FROM annex_data_comments");
    query.exec();
    query.next();
    qmapStatistik["count_id"] = query.value(0).toString();

    // users
    query.prepare("SELECT count (distinct username) FROM annex_data_comments");
    query.exec();
    query.next();
    qmapStatistik["count_users"] = query.value(0).toString();

    return qmapStatistik;
}

int AnnexDataComments::id() const
{
    return d->id;
}

QDateTime AnnexDataComments::commentCreated() const
{
    return d->comment_created;
}

void AnnexDataComments::setCommentCreated(const QDateTime &commentCreated)
{
    d->comment_created = commentCreated;
}

int AnnexDataComments::specId() const
{
    return d->spec_id;
}

void AnnexDataComments::setSpecId(int specId)
{
    d->spec_id = specId;
}

QString AnnexDataComments::specTitle() const
{
    return d->spec_title;
}

void AnnexDataComments::setSpecTitle(const QString &specTitle)
{
    d->spec_title = specTitle;
}

QString AnnexDataComments::specVersion() const
{
    return d->spec_version;
}

void AnnexDataComments::setSpecVersion(const QString &specVersion)
{
    d->spec_version = specVersion;
}

QString AnnexDataComments::userComment() const
{
    return d->user_comment;
}

void AnnexDataComments::setUserComment(const QString &userComment)
{
    d->user_comment = userComment;
}

QString AnnexDataComments::username() const
{
    return d->username;
}

void AnnexDataComments::setUsername(const QString &username)
{
    d->username = username;
}

AnnexDataComments &AnnexDataComments::operator=(const AnnexDataComments &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

QJsonArray AnnexDataComments::createComment(int spec_id, const QString &spec_title, const QString &spec_version, const QString &user_comment, const QString &username)
{
    TSqlQuery query;
    QString msg;
    QJsonObject jsonObj;
    QJsonArray jsonArray;

    query.prepare("INSERT INTO public.annex_data_comments(comment_created, spec_id, spec_title, spec_version, user_comment, username) VALUES((:comment_created),(:spec_id),(:spec_title),(:spec_version),(:user_comment),(:username))");
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
        tError("createComment " + msg.toUtf8());
    }
    else
    {
        jsonObj["ERROR"] = "0";
        jsonObj["errMsg"] = "Comment added";
    }

    jsonArray.append(jsonObj);
    return jsonArray;
}

AnnexDataComments AnnexDataComments::create(const QDateTime &commentCreated, int specId, const QString &specTitle, const QString &specVersion, const QString &userComment, const QString &username)
{
    AnnexDataCommentsObject obj;
    obj.comment_created = commentCreated;
    obj.spec_id = specId;
    obj.spec_title = specTitle;
    obj.spec_version = specVersion;
    obj.user_comment = userComment;
    obj.username = username;
    if (!obj.create()) {
        return AnnexDataComments();
    }
    return AnnexDataComments(obj);
}

AnnexDataComments AnnexDataComments::create(const QVariantMap &values)
{
    AnnexDataComments model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

AnnexDataComments AnnexDataComments::get(int id)
{
    TSqlORMapper<AnnexDataCommentsObject> mapper;
    return AnnexDataComments(mapper.findByPrimaryKey(id));
}

int AnnexDataComments::count()
{
    TSqlORMapper<AnnexDataCommentsObject> mapper;
    return mapper.findCount();
}

QList<AnnexDataComments> AnnexDataComments::getAll()
{
    return tfGetModelListByCriteria<AnnexDataComments, AnnexDataCommentsObject>(TCriteria());
}

QJsonArray AnnexDataComments::getAllJson()
{
    QJsonArray array;
    TSqlORMapper<AnnexDataCommentsObject> mapper;

    if (mapper.find() > 0) {
        for (TSqlORMapperIterator<AnnexDataCommentsObject> i(mapper); i.hasNext(); ) {
            array.append(QJsonValue(QJsonObject::fromVariantMap(AnnexDataComments(i.next()).toVariantMap())));
        }
    }
    return array;
}

TModelObject *AnnexDataComments::modelData()
{
    return d.data();
}

const TModelObject *AnnexDataComments::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const AnnexDataComments &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, AnnexDataComments &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(AnnexDataComments)
