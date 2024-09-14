#include <TreeFrogModel>
#include "actionrights.h"
#include "sqlobjects/actionrightsobject.h"

ActionRights::ActionRights() :
    TAbstractModel(),
    d(new ActionRightsObject())
{
    // set the initial parameters
}

ActionRights::ActionRights(const ActionRights &other) :
    TAbstractModel(),
    d(other.d)
{ }

ActionRights::ActionRights(const ActionRightsObject &object) :
    TAbstractModel(),
    d(new ActionRightsObject(object))
{ }

ActionRights::~ActionRights()
{
    // If the reference count becomes 0,
    // the shared data object 'ActionRightsObject' is deleted.
}

// #####

bool ActionRights::isInGroups(const QString &userGroups, const QString &crud, const QString &uri)
{
    TSqlQuery query;
    QString msg;

    QString user_groups = userGroups;
    user_groups.replace("{", "").replace("}", "");
    QStringList usergroups = user_groups.split(",");

    QString andStr;

    int i = 0;
    do
    {
        if(i == 0)
        {
            andStr.append("(array_to_string(groups, ',') like '%" + usergroups[i] + ":%" + crud + "%'");
        }
        else
        {
            //andStr.append(" OR array_to_string(groups, ',') like '" + usergroups[i] + ":%" + crud + "%'");
            andStr.append(" OR array_to_string(groups, ',') like '%" + usergroups[i] + ":%" + crud + "%'");
        }
        i++;
    }while(i < usergroups.size());
    andStr.append(")");

    query.prepare("SELECT * FROM public.action_rights WHERE uri = ? AND " + andStr + " AND active = '1'");
    query.addBindValue(uri.toLower());

    if(!query.exec())
    {
        msg = query.lastError().text();
        //qWarning("ERROR: " + msg.toUtf8());
        tError("ERROR: " + msg.toUtf8());
        return false;
    }

    while (query.next())
    {
        //msg = query.value(0).toString();
        //tInfo("OK: " + msg.toUtf8());
        return true;
    }

    return false;
}

int ActionRights::id() const
{
    return d->id;
}

QString ActionRights::uri() const
{
    return d->uri;
}

void ActionRights::setUri(const QString &uri)
{
    d->uri = uri;
}

QString ActionRights::groups() const
{
    return d->groups;
}

void ActionRights::setGroups(const QString &groups)
{
    d->groups = groups;
}

QString ActionRights::rights() const
{
    return d->rights;
}

void ActionRights::setRights(const QString &rights)
{
    d->rights = rights;
}

int ActionRights::active() const
{
    return d->active;
}

void ActionRights::setActive(int active)
{
    d->active = active;
}

ActionRights &ActionRights::operator=(const ActionRights &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

ActionRights ActionRights::create(const QString &uri, const QString &groups, const QString &rights, int active)
{
    ActionRightsObject obj;
    obj.uri = uri;
    obj.groups = groups;
    obj.rights = rights;
    obj.active = active;
    if (!obj.create()) {
        return ActionRights();
    }
    return ActionRights(obj);
}

ActionRights ActionRights::create(const QVariantMap &values)
{
    ActionRights model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

ActionRights ActionRights::get(int id)
{
    TSqlORMapper<ActionRightsObject> mapper;
    return ActionRights(mapper.findByPrimaryKey(id));
}

int ActionRights::count()
{
    TSqlORMapper<ActionRightsObject> mapper;
    return mapper.findCount();
}

QList<ActionRights> ActionRights::getAll()
{
    TSqlQuery query;

    QProcess p;
    QString program = "itis_routes";
    QStringList arguments;
    arguments << "";

    p.start(program,arguments);
    p.waitForStarted();
    p.waitForReadyRead();
    p.waitForFinished();
    QString line= p.readAllStandardOutput();

    return tfGetModelListByCriteria<ActionRights, ActionRightsObject>(TCriteria());
}

QJsonArray ActionRights::getAllJson()
{
    QJsonArray array;
    TSqlORMapper<ActionRightsObject> mapper;

    if (mapper.find() > 0) {
        for (TSqlORMapperIterator<ActionRightsObject> i(mapper); i.hasNext(); ) {
            array.append(QJsonValue(QJsonObject::fromVariantMap(ActionRights(i.next()).toVariantMap())));
        }
    }
    return array;
}

TModelObject *ActionRights::modelData()
{
    return d.data();
}

const TModelObject *ActionRights::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const ActionRights &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, ActionRights &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(ActionRights)
