#include <TreeFrogModel>
#include "webmenu.h"
#include "sqlobjects/webmenuobject.h"

Webmenu::Webmenu() :
    TAbstractModel(),
    d(new WebmenuObject())
{
    // set the initial parameters
}

Webmenu::Webmenu(const Webmenu &other) :
    TAbstractModel(),
    d(other.d)
{ }

Webmenu::Webmenu(const WebmenuObject &object) :
    TAbstractModel(),
    d(new WebmenuObject(object))
{ }

Webmenu::~Webmenu()
{
    // If the reference count becomes 0,
    // the shared data object 'WebmenuObject' is deleted.
}

// #####

QJsonArray Webmenu::getMnu(QString strGroups)
{
    TSqlQuery query;
    QJsonObject jsonObject;
    QJsonArray jsonArray;
    QString msg;

    QString andStr = strGroups;
/*
    strGroups.replace("{", "");
    strGroups.replace("}", "");
    QStringList groups = strGroups.split(",");

    QString andStr;

    int i = 0;
    do
    {
        if(i == 0)
        {
            andStr.append("('" + groups[i] + "' = ANY (groups)");
        }
        else
        {
            andStr.append(" OR '" + groups[i] + "' = ANY (groups)");
        }
        i++;
    }while(i < groups.size());
    andStr.append(")");
*/

    query.prepare("select * from webmenu where (mnu_id = 0 and mnu_sub_id = 0) and " + andStr + " AND active = '1' order by sort");
    query.addBindValue(andStr);

    if(!query.exec())
    {
        msg = query.lastError().text();
        jsonObject["ERR_MSG"] = msg;
        jsonObject["ERR_RET"] = "1";
        jsonArray.append(jsonObject);
     }

     while (query.next())
     {
         jsonObject["id"] = query.value(0).toString();
         jsonObject["mnu_id"] = query.value(1).toString();
         jsonObject["mnu_sub_id"] = query.value(2).toString();
         jsonObject["name_de"] = query.value(3).toString();
         jsonObject["desc_de"] = query.value(4).toString();
         jsonObject["name_en"] = query.value(5).toString();
         jsonObject["desc_en"] = query.value(6).toString();
         jsonObject["mnu_uri"] = query.value(7).toString();
         jsonObject["mnu_item"] = query.value(9).toString();
         jsonObject["sort"] = query.value(10).toString();
        jsonArray.append(jsonObject);
     }

     return jsonArray;
}

QJsonArray Webmenu::getMnuSub(QString &mnu, QString strGroups)
{
    TSqlQuery query;
    QJsonObject jsonObject;
    QJsonArray jsonArray;
    QString msg;

    QString andStr = strGroups;
/*
    strGroups.replace("{", "");
    strGroups.replace("}", "");
    QStringList groups = strGroups.split(",");

    QString andStr;
    int i = 0;
    do
    {
        if(i == 0)
        {
            andStr.append("('" + groups[i] + "' = ANY (groups)");
        }
        else
        {
            andStr.append(" OR '" + groups[i] + "' = ANY (groups)");
        }
        i++;
    }while(i < groups.size());
    andStr.append(")");
*/

    // query.prepare("select * from webmenu where (mnu_item = ? and mnu_sub_id = 1) and " + andStr + " AND active = '1' order by sort");
    query.prepare("select * from webmenu where (mnu_item ILIKE ? and mnu_sub_id = 1) and " + andStr + " AND active = '1' order by sort");
    query.addBindValue(mnu);

    if(!query.exec())
    {
        msg = query.lastError().text();
        jsonObject["ERR_MSG"] = msg;
        jsonObject["ERR_RET"] = "1";
        jsonArray.append(jsonObject);
     }

     while (query.next())
     {

        QString erg = query.value(6).toString();
        erg.replace("{", "");
        erg.replace("}", "");
        QStringList groups = erg.split(",");

        /*
        jsonObject["test"] = groups[0];

        if(groups.contains("BMW",Qt::CaseInsensitive))
        {
            jsonObject["BMW"] = "yepp";
        }
        if(groups.contains("BmW",Qt::CaseInsensitive))
        {
            jsonObject["BmW"] = "auchyepp";
        }
        */
        jsonObject["id"] = query.value(0).toString();
        jsonObject["mnu_id"] = query.value(1).toString();
        jsonObject["mnu_sub_id"] = query.value(2).toString();
        jsonObject["name_de"] = query.value(3).toString();
        jsonObject["desc_de"] = query.value(4).toString();
        jsonObject["name_en"] = query.value(5).toString();
        jsonObject["desc_en"] = query.value(6).toString();
        jsonObject["mnu_uri"] = query.value(7).toString();
        jsonObject["mnu_item"] = query.value(9).toString();
        jsonObject["sort"] = query.value(10).toString();
        jsonArray.append(jsonObject);
     }

     return jsonArray;
}

int Webmenu::id() const
{
    return d->id;
}

int Webmenu::mnuId() const
{
    return d->mnu_id;
}

void Webmenu::setMnuId(int mnuId)
{
    d->mnu_id = mnuId;
}

int Webmenu::mnuSubId() const
{
    return d->mnu_sub_id;
}

void Webmenu::setMnuSubId(int mnuSubId)
{
    d->mnu_sub_id = mnuSubId;
}

QString Webmenu::nameDe() const
{
    return d->name_de;
}

void Webmenu::setNameDe(const QString &nameDe)
{
    d->name_de = nameDe;
}

QString Webmenu::descDe() const
{
    return d->desc_de;
}

void Webmenu::setDescDe(const QString &descDe)
{
    d->desc_de = descDe;
}

QString Webmenu::nameEn() const
{
    return d->name_en;
}

void Webmenu::setNameEn(const QString &nameEn)
{
    d->name_en = nameEn;
}

QString Webmenu::descEn() const
{
    return d->desc_en;
}

void Webmenu::setDescEn(const QString &descEn)
{
    d->desc_en = descEn;
}

QString Webmenu::mnuUri() const
{
    return d->mnu_uri;
}

void Webmenu::setMnuUri(const QString &mnuUri)
{
    d->mnu_uri = mnuUri;
}

QString Webmenu::groups() const
{
    return d->groups;
}

void Webmenu::setGroups(const QString &groups)
{
    d->groups = groups;
}

QString Webmenu::mnuItem() const
{
    return d->mnu_item;
}

void Webmenu::setMnuItem(const QString &mnuItem)
{
    d->mnu_item = mnuItem;
}

int Webmenu::sort() const
{
    return d->sort;
}

void Webmenu::setSort(int sort)
{
    d->sort = sort;
}

int Webmenu::active() const
{
    return d->active;
}

void Webmenu::setActive(int active)
{
    d->active = active;
}

Webmenu &Webmenu::operator=(const Webmenu &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

Webmenu Webmenu::create(int mnuId, int mnuSubId, const QString &nameDe, const QString &descDe, const QString &nameEn, const QString &descEn, const QString &mnuUri, const QString &groups, const QString &mnuItem, int sort, int active)
{
    WebmenuObject obj;
    obj.mnu_id = mnuId;
    obj.mnu_sub_id = mnuSubId;
    obj.name_de = nameDe;
    obj.desc_de = descDe;
    obj.name_en = nameEn;
    obj.desc_en = descEn;
    obj.mnu_uri = mnuUri;
    obj.groups = groups;
    obj.mnu_item = mnuItem;
    obj.sort = sort;
    obj.active = active;
    if (!obj.create()) {
        return Webmenu();
    }
    return Webmenu(obj);
}

Webmenu Webmenu::create(const QVariantMap &values)
{
    Webmenu model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

Webmenu Webmenu::get(int id)
{
    TSqlORMapper<WebmenuObject> mapper;
    return Webmenu(mapper.findByPrimaryKey(id));
}

int Webmenu::count()
{
    TSqlORMapper<WebmenuObject> mapper;
    return mapper.findCount();
}

QList<Webmenu> Webmenu::getAll()
{
    return tfGetModelListByCriteria<Webmenu, WebmenuObject>(TCriteria());
}

QJsonArray Webmenu::getAllJson()
{
    QJsonArray array;
    TSqlORMapper<WebmenuObject> mapper;

    if (mapper.find() > 0) {
        for (TSqlORMapperIterator<WebmenuObject> i(mapper); i.hasNext(); ) {
            array.append(QJsonValue(QJsonObject::fromVariantMap(Webmenu(i.next()).toVariantMap())));
        }
    }
    return array;
}

TModelObject *Webmenu::modelData()
{
    return d.data();
}

const TModelObject *Webmenu::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const Webmenu &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, Webmenu &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(Webmenu)
