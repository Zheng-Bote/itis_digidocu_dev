#include <TreeFrogModel>
#include "releasemgmt.h"
#include "sqlobjects/releasemgmtobject.h"

#include "stdsystem.h"

ReleaseMgmt::ReleaseMgmt() :
    TAbstractModel(),
    d(new ReleaseMgmtObject())
{
    // set the initial parameters
}

ReleaseMgmt::ReleaseMgmt(const ReleaseMgmt &other) :
    TAbstractModel(),
    d(other.d)
{ }

ReleaseMgmt::ReleaseMgmt(const ReleaseMgmtObject &object) :
    TAbstractModel(),
    d(new ReleaseMgmtObject(object))
{ }

ReleaseMgmt::~ReleaseMgmt()
{
    // If the reference count becomes 0,
    // the shared data object 'ReleaseMgmtObject' is deleted.
}

// #####

QJsonArray ReleaseMgmt::fileRemove(QMap<QString, QString> stdDataMap)
{
    QFile pathToFile("/webapp/html/itis/pdf/" + stdDataMap["doctype"] + "/" + stdDataMap["docrelease"] + "/" + stdDataMap["docname"]);

    QJsonObject jsonObject;
    QJsonArray jsonArray;

    if(pathToFile.exists() == 0) {
        tError("fielRemove 0");
        jsonObject["ERROR"] = "0";
        jsonObject["Msg"] = "alles ok";
    }
    else {
        tError("fileRemove != 0");
        jsonObject["ERROR"] = "1";
        jsonObject["errMsg"] = "NOK";
    }

    jsonArray.append(jsonObject);
    return jsonArray;
}

int ReleaseMgmt::crPDF(const QString &htmlFile, const QString &pdfFile)
{
    QProcess p;
    QString program;

    QDir devDir("/webapp_dez");
    QDir prodDir("/webapp");

    if(devDir.exists())
    {
        program = "/webapp_dez/itis_app/doit.sh";
    }
    else if(prodDir.exists())
    {
        program = "/webapp/itis_api/doit.sh";
    }

    QStringList arguments;
    arguments << htmlFile << pdfFile;

    p.start(program,arguments);
    p.waitForStarted();
    p.waitForReadyRead();
    p.waitForFinished();
    QString output = p.readAllStandardOutput();

    if(p.exitCode() != 0)
    {
        tError(output.toUtf8());
        return(1);
    }
    else
    {
        // OK
        return(0);
    }
}

QJsonArray ReleaseMgmt::ci_update(QMap<QString, QString> stdDataMap)
{
    TSqlQuery query;
    QJsonObject jsonObject;
    QJsonArray jsonArray;
    QString msg;

    /*
    stdDataMap["id"] = httpRequest().formItemValue("id");
    stdDataMap["specVersion"] = httpRequest().formItemValue("specVersion");
    stdDataMap["relCreator"] = httpRequest().formItemValue("relCreator");
    stdDataMap["relcreatorDecisdate"]
            */
    query.prepare("UPDATE public.release_mgmt set spec_version = ?, rel_creator = ?, relcreator_decisdate = ? WHERE id = ?");
    query.addBindValue(stdDataMap["specVersion"]);
    query.addBindValue(stdDataMap["relCreator"]);
    query.addBindValue(stdDataMap["relcreatorDecisdate"]);
    query.addBindValue(stdDataMap["id"]);

    if(!query.exec())
    {
        msg = query.lastError().text();
        jsonObject["errMsg"] = msg;
        jsonObject["ERROR"] = "1";
        jsonArray.append(jsonObject);
    }
    else
    {
        jsonObject["errMsg"] = "update OK";
        jsonObject["ERROR"] = "0";
        jsonArray.append(jsonObject);
    }

    return jsonArray;
}

int ReleaseMgmt::id() const
{
    return d->id;
}

QString ReleaseMgmt::objSname() const
{
    return d->obj_sname;
}

void ReleaseMgmt::setObjSname(const QString &objSname)
{
    d->obj_sname = objSname;
}

QString ReleaseMgmt::specVersion() const
{
    return d->spec_version;
}

void ReleaseMgmt::setSpecVersion(const QString &specVersion)
{
    d->spec_version = specVersion;
}

QString ReleaseMgmt::acClasses() const
{
    return d->ac_classes;
}

void ReleaseMgmt::setAcClasses(const QString &acClasses)
{
    d->ac_classes = acClasses;
}

QString ReleaseMgmt::pcClasses() const
{
    return d->pc_classes;
}

void ReleaseMgmt::setPcClasses(const QString &pcClasses)
{
    d->pc_classes = pcClasses;
}

QString ReleaseMgmt::catClass() const
{
    return d->cat_class;
}

void ReleaseMgmt::setCatClass(const QString &catClass)
{
    d->cat_class = catClass;
}

QString ReleaseMgmt::country() const
{
    return d->country;
}

void ReleaseMgmt::setCountry(const QString &country)
{
    d->country = country;
}

QString ReleaseMgmt::lang() const
{
    return d->lang;
}

void ReleaseMgmt::setLang(const QString &lang)
{
    d->lang = lang;
}

QString ReleaseMgmt::docType() const
{
    return d->doc_type;
}

void ReleaseMgmt::setDocType(const QString &docType)
{
    d->doc_type = docType;
}

QString ReleaseMgmt::relRequester() const
{
    return d->rel_requester;
}

void ReleaseMgmt::setRelRequester(const QString &relRequester)
{
    d->rel_requester = relRequester;
}

QDateTime ReleaseMgmt::relrequestDate() const
{
    return d->relrequest_date;
}

void ReleaseMgmt::setRelrequestDate(const QDateTime &relrequestDate)
{
    d->relrequest_date = relrequestDate;
}

QString ReleaseMgmt::relCreator() const
{
    return d->rel_creator;
}

void ReleaseMgmt::setRelCreator(const QString &relCreator)
{
    d->rel_creator = relCreator;
}

QDateTime ReleaseMgmt::relcreatorDecisdate() const
{
    return d->relcreator_decisdate;
}

void ReleaseMgmt::setRelcreatorDecisdate(const QDateTime &relcreatorDecisdate)
{
    d->relcreator_decisdate = relcreatorDecisdate;
}

QString ReleaseMgmt::relInspector() const
{
    return d->rel_inspector;
}

void ReleaseMgmt::setRelInspector(const QString &relInspector)
{
    d->rel_inspector = relInspector;
}

QDateTime ReleaseMgmt::relinspectDecisdate() const
{
    return d->relinspect_decisdate;
}

void ReleaseMgmt::setRelinspectDecisdate(const QDateTime &relinspectDecisdate)
{
    d->relinspect_decisdate = relinspectDecisdate;
}

QString ReleaseMgmt::relApprover() const
{
    return d->rel_approver;
}

void ReleaseMgmt::setRelApprover(const QString &relApprover)
{
    d->rel_approver = relApprover;
}

QDateTime ReleaseMgmt::relapprovDecisdate() const
{
    return d->relapprov_decisdate;
}

void ReleaseMgmt::setRelapprovDecisdate(const QDateTime &relapprovDecisdate)
{
    d->relapprov_decisdate = relapprovDecisdate;
}

QDateTime ReleaseMgmt::ciDate() const
{
    return d->ci_date;
}

void ReleaseMgmt::setCiDate(const QDateTime &ciDate)
{
    d->ci_date = ciDate;
}

QDateTime ReleaseMgmt::cdDate() const
{
    return d->cd_date;
}

void ReleaseMgmt::setCdDate(const QDateTime &cdDate)
{
    d->cd_date = cdDate;
}

QDateTime ReleaseMgmt::cddDate() const
{
    return d->cdd_date;
}

void ReleaseMgmt::setCddDate(const QDateTime &cddDate)
{
    d->cdd_date = cddDate;
}

ReleaseMgmt &ReleaseMgmt::operator=(const ReleaseMgmt &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

ReleaseMgmt ReleaseMgmt::create(const QString &objSname, const QString &specVersion, const QString &acClasses, const QString &pcClasses, const QString &catClass, const QString &country, const QString &lang, const QString &docType, const QString &relRequester, const QDateTime &relrequestDate, const QString &relCreator, const QDateTime &relcreatorDecisdate, const QString &relInspector, const QDateTime &relinspectDecisdate, const QString &relApprover, const QDateTime &relapprovDecisdate, const QDateTime &ciDate, const QDateTime &cdDate, const QDateTime &cddDate)
{
    ReleaseMgmtObject obj;
    obj.obj_sname = objSname;
    obj.spec_version = specVersion;
    obj.ac_classes = acClasses;
    obj.pc_classes = pcClasses;
    obj.cat_class = catClass;
    obj.country = country;
    obj.lang = lang;
    obj.doc_type = docType;
    obj.rel_requester = relRequester;
    obj.relrequest_date = relrequestDate;
    obj.rel_creator = relCreator;
    obj.relcreator_decisdate = relcreatorDecisdate;
    obj.rel_inspector = relInspector;
    obj.relinspect_decisdate = relinspectDecisdate;
    obj.rel_approver = relApprover;
    obj.relapprov_decisdate = relapprovDecisdate;
    obj.ci_date = ciDate;
    obj.cd_date = cdDate;
    obj.cdd_date = cddDate;
    if (!obj.create()) {
        return ReleaseMgmt();
    }
    return ReleaseMgmt(obj);
}

ReleaseMgmt ReleaseMgmt::create(const QVariantMap &values)
{
    ReleaseMgmt model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

ReleaseMgmt ReleaseMgmt::get(int id)
{
    TSqlORMapper<ReleaseMgmtObject> mapper;
    return ReleaseMgmt(mapper.findByPrimaryKey(id));
}

int ReleaseMgmt::count()
{
    TSqlORMapper<ReleaseMgmtObject> mapper;
    return mapper.findCount();
}

QList<ReleaseMgmt> ReleaseMgmt::getAll()
{
    return tfGetModelListByCriteria<ReleaseMgmt, ReleaseMgmtObject>(TCriteria());
}

QJsonArray ReleaseMgmt::list_allAnnexCi()
{
    TSqlQuery query;
    QJsonObject jsonObject;
    QJsonArray jsonArray;
    QString msg;

    query.prepare("SELECT id, obj_sname, spec_version, ac_classes, pc_classes, cat_class, country, lang, doc_type, rel_requester, relrequest_date, rel_creator, relcreator_decisdate, rel_inspector, relinspect_decisdate, rel_approver, relapprov_decisdate, ci_date, cd_date, cdd_date FROM public.release_mgmt WHERE doc_type = 'annex' AND cd_date is null GROUP BY(id, obj_sname,ac_classes, pc_classes, country, lang)");

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
        jsonObject["obj_sname"] = query.value(1).toString();
        jsonObject["spec_version"] = query.value(2).toString();
        jsonObject["ac_classes"] = query.value(3).toString();
        jsonObject["pc_classes"] = query.value(4).toString();
        jsonObject["cat_class"] = query.value(5).toString();
        jsonObject["country"] = query.value(6).toString();
        jsonObject["lang"] = query.value(7).toString();
        jsonObject["doc_type"] = query.value(8).toString();
        jsonObject["rel_requester"] = query.value(9).toString();
        jsonObject["relrequest_date"] = StdSystem::convertDate( query.value(10).toDate() );
        jsonObject["rel_creator"] = query.value(11).toString();
        jsonObject["relcreator_decisdate"] = StdSystem::convertDate( query.value(12).toDate() );
        jsonObject["rel_inspector"] = query.value(13).toString();
        jsonObject["relinspect_decisdate"] = StdSystem::convertDate( query.value(14).toDate() );
        jsonObject["rel_approver"] = query.value(15).toString();
        jsonObject["relapprov_decisdate"] = StdSystem::convertDate( query.value(16).toDate() );
        jsonObject["ci_date"] = StdSystem::convertDate( query.value(17).toDate() );

        jsonArray.append(jsonObject);
    }
    return jsonArray;
}
QJsonArray ReleaseMgmt::list_allAnnexCd()
{
    TSqlQuery query;
    QJsonObject jsonObject;
    QJsonArray jsonArray;
    QString msg;

    query.prepare("SELECT id, obj_sname, spec_version, ac_classes, pc_classes, cat_class, country, lang, doc_type, rel_requester, relrequest_date, rel_creator, relcreator_decisdate, rel_inspector, relinspect_decisdate, rel_approver, relapprov_decisdate, ci_date, cd_date, cdd_date FROM public.release_mgmt WHERE doc_type = 'annex' AND cd_date is not null GROUP BY(id, obj_sname,ac_classes, pc_classes, country, lang)");

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
        jsonObject["obj_sname"] = query.value(1).toString();
        jsonObject["spec_version"] = query.value(2).toString();
        jsonObject["ac_classes"] = query.value(3).toString();
        jsonObject["pc_classes"] = query.value(4).toString();
        jsonObject["cat_class"] = query.value(5).toString();
        jsonObject["country"] = query.value(6).toString();
        jsonObject["lang"] = query.value(7).toString();
        jsonObject["doc_type"] = query.value(8).toString();
        jsonObject["rel_requester"] = query.value(9).toString();
        jsonObject["relrequest_date"] = StdSystem::convertDate( query.value(10).toDate() );
        jsonObject["rel_creator"] = query.value(11).toString();
        jsonObject["relcreator_decisdate"] = StdSystem::convertDate( query.value(12).toDate() );
        jsonObject["rel_inspector"] = query.value(13).toString();
        jsonObject["relinspect_decisdate"] = StdSystem::convertDate( query.value(14).toDate() );
        jsonObject["rel_approver"] = query.value(15).toString();
        jsonObject["relapprov_decisdate"] = StdSystem::convertDate( query.value(16).toDate() );
        jsonObject["ci_date"] = StdSystem::convertDate( query.value(17).toDate() );
        jsonObject["cd_date"] = StdSystem::convertDate( query.value(18).toDate() );
        jsonObject["cdd_date"] = StdSystem::convertDate( query.value(19).toDate() );


        jsonArray.append(jsonObject);
    }
    return jsonArray;
}
QJsonArray ReleaseMgmt::list_allStdCi()
{
    TSqlQuery query;
    QJsonObject jsonObject;
    QJsonArray jsonArray;
    QString msg;

    query.prepare("SELECT id, obj_sname, spec_version, ac_classes, pc_classes, cat_class, country, lang, doc_type, rel_requester, relrequest_date, rel_creator, relcreator_decisdate, rel_inspector, relinspect_decisdate, rel_approver, relapprov_decisdate, ci_date, cd_date, cdd_date FROM public.release_mgmt WHERE doc_type = 'standard' AND cd_date is null GROUP BY(id, obj_sname,ac_classes, pc_classes, country, lang)");

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
        jsonObject["obj_sname"] = query.value(1).toString();
        jsonObject["spec_version"] = query.value(2).toString();
        jsonObject["ac_classes"] = query.value(3).toString();
        jsonObject["pc_classes"] = query.value(4).toString();
        jsonObject["cat_class"] = query.value(5).toString();
        jsonObject["country"] = query.value(6).toString();
        jsonObject["lang"] = query.value(7).toString();
        jsonObject["doc_type"] = query.value(8).toString();
        jsonObject["rel_requester"] = query.value(9).toString();
        jsonObject["relrequest_date"] = StdSystem::convertDate( query.value(10).toDate() );
        jsonObject["rel_creator"] = query.value(11).toString();
        jsonObject["relcreator_decisdate"] = StdSystem::convertDate( query.value(12).toDate() );
        jsonObject["rel_inspector"] = query.value(13).toString();
        jsonObject["relinspect_decisdate"] = StdSystem::convertDate( query.value(14).toDate() );
        jsonObject["rel_approver"] = query.value(15).toString();
        jsonObject["relapprov_decisdate"] = StdSystem::convertDate( query.value(16).toDate() );
        jsonObject["ci_date"] = StdSystem::convertDate( query.value(17).toDate() );

        jsonArray.append(jsonObject);
    }
    return jsonArray;
}
QJsonArray ReleaseMgmt::list_allStdCd()
{
    TSqlQuery query;
    QJsonObject jsonObject;
    QJsonArray jsonArray;
    QString msg;

    query.prepare("SELECT id, obj_sname, spec_version, ac_classes, pc_classes, cat_class, country, lang, doc_type, rel_requester, relrequest_date, rel_creator, relcreator_decisdate, rel_inspector, relinspect_decisdate, rel_approver, relapprov_decisdate, ci_date, cd_date, cdd_date FROM public.release_mgmt WHERE doc_type = 'standard' AND cd_date is not null GROUP BY(id, obj_sname,ac_classes, pc_classes, country, lang)");

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
        jsonObject["obj_sname"] = query.value(1).toString();
        jsonObject["spec_version"] = query.value(2).toString();
        jsonObject["ac_classes"] = query.value(3).toString();
        jsonObject["pc_classes"] = query.value(4).toString();
        jsonObject["cat_class"] = query.value(5).toString();
        jsonObject["country"] = query.value(6).toString();
        jsonObject["lang"] = query.value(7).toString();
        jsonObject["doc_type"] = query.value(8).toString();
        jsonObject["rel_requester"] = query.value(9).toString();
        jsonObject["relrequest_date"] = StdSystem::convertDate( query.value(10).toDate() );
        jsonObject["rel_creator"] = query.value(11).toString();
        jsonObject["relcreator_decisdate"] = StdSystem::convertDate( query.value(12).toDate() );
        jsonObject["rel_inspector"] = query.value(13).toString();
        jsonObject["relinspect_decisdate"] = StdSystem::convertDate( query.value(14).toDate() );
        jsonObject["rel_approver"] = query.value(15).toString();
        jsonObject["relapprov_decisdate"] = StdSystem::convertDate( query.value(16).toDate() );
        jsonObject["ci_date"] = StdSystem::convertDate( query.value(17).toDate() );
        jsonObject["cd_date"] = StdSystem::convertDate( query.value(18).toDate() );
        jsonObject["cdd_date"] = StdSystem::convertDate( query.value(19).toDate() );

        jsonArray.append(jsonObject);
    }
    return jsonArray;
}

QJsonArray ReleaseMgmt::getAllJson()
{
    QJsonArray array;
    TSqlORMapper<ReleaseMgmtObject> mapper;

    if (mapper.find() > 0) {
        for (TSqlORMapperIterator<ReleaseMgmtObject> i(mapper); i.hasNext(); ) {
            array.append(QJsonValue(QJsonObject::fromVariantMap(ReleaseMgmt(i.next()).toVariantMap())));
        }
    }
    return array;
}

TModelObject *ReleaseMgmt::modelData()
{
    return d.data();
}

const TModelObject *ReleaseMgmt::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const ReleaseMgmt &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, ReleaseMgmt &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(ReleaseMgmt)
