#include <TreeFrogModel>
#include "lenkinfo.h"
#include "sqlobjects/lenkinfoobject.h"

#include "stdsystem.h"

Lenkinfo::Lenkinfo() :
    TAbstractModel(),
    d(new LenkinfoObject())
{
    // set the initial parameters
}

Lenkinfo::Lenkinfo(const Lenkinfo &other) :
    TAbstractModel(),
    d(other.d)
{ }

Lenkinfo::Lenkinfo(const LenkinfoObject &object) :
    TAbstractModel(),
    d(new LenkinfoObject(object))
{ }

Lenkinfo::~Lenkinfo()
{
    // If the reference count becomes 0,
    // the shared data object 'LenkinfoObject' is deleted.
}

// #####

/*
QString Lenkinfo::getLastLenkStatus(QMap<QString, QString> &stdDataMap)
{
    TSqlQuery query;
    QString lenkinfo;

    query.prepare("SELECT lenk_status WHERE spec_obj = ? AND ac_class = ? AND pc_class = ? AND country = ? AND lang = ? ORDER BY lenk_valid_startdate DESC LIMIT 1");
    query.addBindValue(stdDataMap["spec_obj"]);
    query.addBindValue(stdDataMap["ac_class"]);
    query.addBindValue(stdDataMap["pc_class"]);
    query.addBindValue(stdDataMap["country"]);
    query.addBindValue(stdDataMap["lang"]);

    query.exec();
    query.next();

    return query.value(0).toString();
}
*/

QJsonArray Lenkinfo::getJson(QMap<QString, QString> &stdDataMap)
{
    TSqlQuery query;
    QJsonObject jsonObject;
    QJsonArray jsonArray;
    QString msg;
    int counter = 0;

    query.prepare("SELECT id, spec_obj, spec_title, ac_class, pc_class, country, lang, lenk_version, lenk_status, lenk_valid_startdate, lenk_departments, lenk_content, lenk_creator, lenk_creator_date, lenk_auditor, lenk_auditor_date, lenk_approver, lenk_approver_date FROM public.lenkinfo WHERE spec_obj = ? AND ac_class = ? AND pc_class = ? AND country = ? AND lang = ? ORDER BY lenk_valid_startdate");
    query.addBindValue(stdDataMap["spec_obj"]);
    query.addBindValue(stdDataMap["ac_class"]);
    query.addBindValue(stdDataMap["pc_class"]);
    query.addBindValue(stdDataMap["country"]);
    query.addBindValue(stdDataMap["lang"]);

    if(!query.exec())
    {
        msg = query.lastError().text();
        jsonObject["errMsg"] = msg;
        jsonObject["ERROR"] = "1";
        jsonArray.append(jsonObject);

        return jsonArray;
    }

    while (query.next())
    {
        jsonObject["counter"] = QString::number(counter++);
        jsonObject["id"] = query.value(0).toString();
        jsonObject["spec_obj"] = query.value(1).toString();
        jsonObject["spec_title"] = query.value(2).toString();
        jsonObject["ac_class"] = query.value(3).toString();
        jsonObject["pc_class"] = query.value(4).toString();
        jsonObject["country"] = query.value(5).toString();
        jsonObject["lang"] = query.value(6).toString();
        jsonObject["lenk_version"] = query.value(7).toString();
        jsonObject["lenk_status"] = query.value(8).toString();
        jsonObject["lenk_valid_startdate"] = query.value(9).toString();
        jsonObject["lenk_departments"] = query.value(10).toString();
        jsonObject["lenk_content"] = query.value(11).toString();
        jsonObject["lenk_creator"] = query.value(12).toString();

        // jsonObject["lenk_creator_date"] = query.value(13).toString();
        //QDate buildtime = query.value(13).toDate();
        //jsonObject["lenk_creator_date"] = buildtime.toString("yyyy-MM-dd");
        jsonObject["lenk_creator_date"] = StdSystem::convertDate( query.value(13).toDate() );

        jsonObject["lenk_auditor"] = query.value(14).toString();
        jsonObject["lenk_auditor_date"] = StdSystem::convertDate( query.value(15).toDate() );
        jsonObject["lenk_approver"] = query.value(16).toString();
        jsonObject["lenk_approver_date"] = StdSystem::convertDate( query.value(17).toDate() );
        jsonArray.append(jsonObject);
    }

     return jsonArray;
}

int Lenkinfo::id() const
{
    return d->id;
}

QString Lenkinfo::specObj() const
{
    return d->spec_obj;
}

void Lenkinfo::setSpecObj(const QString &specObj)
{
    d->spec_obj = specObj;
}

QString Lenkinfo::specTitle() const
{
    return d->spec_title;
}

void Lenkinfo::setSpecTitle(const QString &specTitle)
{
    d->spec_title = specTitle;
}

int Lenkinfo::acClass() const
{
    return d->ac_class;
}

void Lenkinfo::setAcClass(int acClass)
{
    d->ac_class = acClass;
}

int Lenkinfo::pcClass() const
{
    return d->pc_class;
}

void Lenkinfo::setPcClass(int pcClass)
{
    d->pc_class = pcClass;
}

QString Lenkinfo::country() const
{
    return d->country;
}

void Lenkinfo::setCountry(const QString &country)
{
    d->country = country;
}

QString Lenkinfo::lang() const
{
    return d->lang;
}

void Lenkinfo::setLang(const QString &lang)
{
    d->lang = lang;
}

QString Lenkinfo::lenkVersion() const
{
    return d->lenk_version;
}

void Lenkinfo::setLenkVersion(const QString &lenkVersion)
{
    d->lenk_version = lenkVersion;
}

QString Lenkinfo::lenkStatus() const
{
    return d->lenk_status;
}

void Lenkinfo::setLenkStatus(const QString &lenkStatus)
{
    d->lenk_status = lenkStatus;
}

QDateTime Lenkinfo::lenkValidStartdate() const
{
    return d->lenk_valid_startdate;
}

void Lenkinfo::setLenkValidStartdate(const QDateTime &lenkValidStartdate)
{
    d->lenk_valid_startdate = lenkValidStartdate;
}

QString Lenkinfo::lenkDepartments() const
{
    return d->lenk_departments;
}

void Lenkinfo::setLenkDepartments(const QString &lenkDepartments)
{
    d->lenk_departments = lenkDepartments;
}

QString Lenkinfo::lenkContent() const
{
    return d->lenk_content;
}

void Lenkinfo::setLenkContent(const QString &lenkContent)
{
    d->lenk_content = lenkContent;
}

QString Lenkinfo::lenkCreator() const
{
    return d->lenk_creator;
}

void Lenkinfo::setLenkCreator(const QString &lenkCreator)
{
    d->lenk_creator = lenkCreator;
}

QDateTime Lenkinfo::lenkCreatorDate() const
{
    return d->lenk_creator_date;
}

void Lenkinfo::setLenkCreatorDate(const QDateTime &lenkCreatorDate)
{
    d->lenk_creator_date = lenkCreatorDate;
}

QString Lenkinfo::lenkAuditor() const
{
    return d->lenk_auditor;
}

void Lenkinfo::setLenkAuditor(const QString &lenkAuditor)
{
    d->lenk_auditor = lenkAuditor;
}

QDateTime Lenkinfo::lenkAuditorDate() const
{
    return d->lenk_auditor_date;
}

void Lenkinfo::setLenkAuditorDate(const QDateTime &lenkAuditorDate)
{
    d->lenk_auditor_date = lenkAuditorDate;
}

QString Lenkinfo::lenkApprover() const
{
    return d->lenk_approver;
}

void Lenkinfo::setLenkApprover(const QString &lenkApprover)
{
    d->lenk_approver = lenkApprover;
}

QDateTime Lenkinfo::lenkApproverDate() const
{
    return d->lenk_approver_date;
}

void Lenkinfo::setLenkApproverDate(const QDateTime &lenkApproverDate)
{
    d->lenk_approver_date = lenkApproverDate;
}

Lenkinfo &Lenkinfo::operator=(const Lenkinfo &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

Lenkinfo Lenkinfo::create(const QString &specObj, const QString &specTitle, int acClass, int pcClass, const QString &country, const QString &lang, const QString &lenkVersion, const QString &lenkStatus, const QDateTime &lenkValidStartdate, const QString &lenkDepartments, const QString &lenkContent, const QString &lenkCreator, const QDateTime &lenkCreatorDate, const QString &lenkAuditor, const QDateTime &lenkAuditorDate, const QString &lenkApprover, const QDateTime &lenkApproverDate)
{
    LenkinfoObject obj;
    obj.spec_obj = specObj;
    obj.spec_title = specTitle;
    obj.ac_class = acClass;
    obj.pc_class = pcClass;
    obj.country = country;
    obj.lang = lang;
    obj.lenk_version = lenkVersion;
    obj.lenk_status = lenkStatus;
    obj.lenk_valid_startdate = lenkValidStartdate;
    obj.lenk_departments = lenkDepartments;
    obj.lenk_content = lenkContent;
    obj.lenk_creator = lenkCreator;
    obj.lenk_creator_date = lenkCreatorDate;
    obj.lenk_auditor = lenkAuditor;
    obj.lenk_auditor_date = lenkAuditorDate;
    obj.lenk_approver = lenkApprover;
    obj.lenk_approver_date = lenkApproverDate;
    if (!obj.create()) {
        return Lenkinfo();
    }
    return Lenkinfo(obj);
}

Lenkinfo Lenkinfo::create(const QVariantMap &values)
{
    Lenkinfo model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

Lenkinfo Lenkinfo::get(int id)
{
    TSqlORMapper<LenkinfoObject> mapper;
    return Lenkinfo(mapper.findByPrimaryKey(id));
}

int Lenkinfo::count()
{
    TSqlORMapper<LenkinfoObject> mapper;
    return mapper.findCount();
}

QList<Lenkinfo> Lenkinfo::getAll()
{
    return tfGetModelListByCriteria<Lenkinfo, LenkinfoObject>(TCriteria());
}

QJsonArray Lenkinfo::getAllJson()
{
    QJsonArray array;
    TSqlORMapper<LenkinfoObject> mapper;

    if (mapper.find() > 0) {
        for (TSqlORMapperIterator<LenkinfoObject> i(mapper); i.hasNext(); ) {
            array.append(QJsonValue(QJsonObject::fromVariantMap(Lenkinfo(i.next()).toVariantMap())));
        }
    }
    return array;
}

TModelObject *Lenkinfo::modelData()
{
    return d.data();
}

const TModelObject *Lenkinfo::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const Lenkinfo &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, Lenkinfo &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(Lenkinfo)
