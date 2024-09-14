#include <TreeFrogModel>
#include "annexdatawaste.h"
#include "sqlobjects/annexdatawasteobject.h"

AnnexDataWaste::AnnexDataWaste() :
    TAbstractModel(),
    d(new AnnexDataWasteObject())
{
    // set the initial parameters
}

AnnexDataWaste::AnnexDataWaste(const AnnexDataWaste &other) :
    TAbstractModel(),
    d(other.d)
{ }

AnnexDataWaste::AnnexDataWaste(const AnnexDataWasteObject &object) :
    TAbstractModel(),
    d(new AnnexDataWasteObject(object))
{ }

AnnexDataWaste::~AnnexDataWaste()
{
    // If the reference count becomes 0,
    // the shared data object 'AnnexDataWasteObject' is deleted.
}

// #####

QJsonArray AnnexDataWaste::doRecover(int id)
{
    TSqlQuery query;
    QString msg;
    QString changed_on, id_old, lfdnr, spec_title, spec_desc, spec_version, spec_release, obj_sname, ac_classes, pc_classes, cat_class, country, lang, spec_content, spec_active;

    QJsonObject jsonObj;
    QJsonArray jsonArr;

    query.prepare("SELECT changed_on, id_old, lfdnr, spec_title, spec_desc, spec_version, spec_release, obj_sname, ac_classes, pc_classes, cat_class, country, lang, spec_content, spec_active FROM public.standards_data_waste where id = ?");
    query.addBindValue(id);
    query.exec();

    while (query.next())
    {
        changed_on = query.value(0).toString();
        id_old = query.value(1).toString();
        lfdnr= query.value(2).toString();
        spec_title = query.value(3).toString();
        spec_desc = query.value(4).toString();
        spec_version = query.value(5).toString();
        spec_release = query.value(6).toString();
        obj_sname = query.value(7).toString();
        ac_classes = query.value(8).toString();
        pc_classes = query.value(9).toString();
        cat_class = query.value(10).toString();
        country = query.value(11).toString();
        lang = query.value(12).toString();
        spec_content = query.value(13).toString();
        spec_active = query.value(14).toString();
    }

    query.prepare("INSERT INTO public.standards_data (lfdnr, spec_title, spec_desc, spec_version, spec_release, obj_sname, ac_classes, pc_classes, cat_class, country, lang, spec_content, spec_active) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)");
    query.addBindValue(lfdnr);
    query.addBindValue(spec_title);
    query.addBindValue(spec_desc);
    query.addBindValue(spec_version);
    query.addBindValue(spec_release);
    query.addBindValue(obj_sname);
    query.addBindValue(ac_classes);
    query.addBindValue(pc_classes);
    query.addBindValue(cat_class);
    query.addBindValue(country);
    query.addBindValue(lang);
    query.addBindValue(spec_content);
    query.addBindValue(spec_active);

    if(!query.exec())
    {
        msg = query.lastError().text();
        jsonObj["ERROR"] = "1";
        jsonObj["errMsg"] = msg;
        jsonArr.append(jsonObj);
        return jsonArr;
    }

    int last_id = query.lastInsertId().toInt();
    jsonObj["last_data_id"] = QString::number(last_id);

    QString spec_data_id, spec_created, spec_last_modified, spec_valid_start, spec_valid_end, last_editor, g_legacy, responsibility, spec_comment, spec_marker, groups;
    query.prepare("SELECT changed_on, spec_data_id, spec_created, spec_last_modified, spec_valid_start, spec_valid_end, last_editor, g_legacy, responsibility, spec_comment, spec_marker, groups FROM public.standards_meta_waste WHERE spec_data_id = ?");
    query.addBindValue(id_old);
    query.exec();

    while (query.next())
    {
        changed_on = query.value(0).toString();
        spec_data_id = query.value(1).toString();
        spec_created = query.value(2).toString();
        spec_last_modified = query.value(3).toString();
        spec_valid_start = query.value(4).toString();
        spec_valid_end = query.value(5).toString();
        last_editor = query.value(6).toString();
        g_legacy = query.value(7).toString();
        responsibility = query.value(8).toString();
        spec_comment = query.value(9).toString();
        spec_marker = query.value(10).toString();
        groups = query.value(11).toString();
    }

    query.prepare("INSERT INTO public.standards_meta (spec_data_id, spec_created, spec_last_modified, spec_valid_start, spec_valid_end, last_editor, g_legacy, responsibility, spec_comment, spec_marker, groups) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)");
    query.addBindValue(last_id);
    query.addBindValue(spec_created);
    query.addBindValue(spec_last_modified);
    query.addBindValue(spec_valid_start);
    query.addBindValue(spec_valid_end);
    query.addBindValue(last_editor);
    query.addBindValue( g_legacy);
    query.addBindValue(responsibility);
    query.addBindValue(spec_comment);
    query.addBindValue(spec_marker);
    query.addBindValue(groups);

    if(!query.exec())
    {
        msg = query.lastError().text();
        jsonObj["ERROR"] = "1";
        jsonObj["errMsg"] = msg;
        jsonArr.append(jsonObj);
        return jsonArr;
    }

    int last_metaid = query.lastInsertId().toInt();
    jsonObj["last_meta_id"] = QString::number(last_metaid);

    query.prepare("DELETE FROM public.standards_data_waste WHERE id = ?");
    query.addBindValue(id);
    query.exec();
    query.prepare("DELETE FROM public.standards_meta_waste WHERE spec_data_id = ?");
    query.addBindValue(spec_data_id);
    query.exec();

    msg = "Recovery successfully.";
    msg.append("ID: " + QString::number(last_id));
    msg.append(" Meta-ID: " + QString::number(last_metaid));

    jsonObj["ERROR"] = "0";
    jsonObj["errMsg"] = msg;
    jsonArr.append(jsonObj);
    return jsonArr;
}

int AnnexDataWaste::id() const
{
    return d->id;
}

QDateTime AnnexDataWaste::changedOn() const
{
    return d->changed_on;
}

void AnnexDataWaste::setChangedOn(const QDateTime &changedOn)
{
    d->changed_on = changedOn;
}

int AnnexDataWaste::idOld() const
{
    return d->id_old;
}

void AnnexDataWaste::setIdOld(int idOld)
{
    d->id_old = idOld;
}

QString AnnexDataWaste::lfdnr() const
{
    return d->lfdnr;
}

void AnnexDataWaste::setLfdnr(const QString &lfdnr)
{
    d->lfdnr = lfdnr;
}

QString AnnexDataWaste::specTitle() const
{
    return d->spec_title;
}

void AnnexDataWaste::setSpecTitle(const QString &specTitle)
{
    d->spec_title = specTitle;
}

QString AnnexDataWaste::specDesc() const
{
    return d->spec_desc;
}

void AnnexDataWaste::setSpecDesc(const QString &specDesc)
{
    d->spec_desc = specDesc;
}

QString AnnexDataWaste::specVersion() const
{
    return d->spec_version;
}

void AnnexDataWaste::setSpecVersion(const QString &specVersion)
{
    d->spec_version = specVersion;
}

QString AnnexDataWaste::specRelease() const
{
    return d->spec_release;
}

void AnnexDataWaste::setSpecRelease(const QString &specRelease)
{
    d->spec_release = specRelease;
}

QString AnnexDataWaste::objSname() const
{
    return d->obj_sname;
}

void AnnexDataWaste::setObjSname(const QString &objSname)
{
    d->obj_sname = objSname;
}

QString AnnexDataWaste::acClasses() const
{
    return d->ac_classes;
}

void AnnexDataWaste::setAcClasses(const QString &acClasses)
{
    d->ac_classes = acClasses;
}

QString AnnexDataWaste::pcClasses() const
{
    return d->pc_classes;
}

void AnnexDataWaste::setPcClasses(const QString &pcClasses)
{
    d->pc_classes = pcClasses;
}

QString AnnexDataWaste::catClass() const
{
    return d->cat_class;
}

void AnnexDataWaste::setCatClass(const QString &catClass)
{
    d->cat_class = catClass;
}

QString AnnexDataWaste::country() const
{
    return d->country;
}

void AnnexDataWaste::setCountry(const QString &country)
{
    d->country = country;
}

QString AnnexDataWaste::lang() const
{
    return d->lang;
}

void AnnexDataWaste::setLang(const QString &lang)
{
    d->lang = lang;
}

QByteArray AnnexDataWaste::specContent() const
{
    return d->spec_content;
}

void AnnexDataWaste::setSpecContent(const QByteArray &specContent)
{
    d->spec_content = specContent;
}

int AnnexDataWaste::specActive() const
{
    return d->spec_active;
}

void AnnexDataWaste::setSpecActive(int specActive)
{
    d->spec_active = specActive;
}

AnnexDataWaste &AnnexDataWaste::operator=(const AnnexDataWaste &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

AnnexDataWaste AnnexDataWaste::create(const QDateTime &changedOn, int idOld, const QString &lfdnr, const QString &specTitle, const QString &specDesc, const QString &specVersion, const QString &specRelease, const QString &objSname, const QString &acClasses, const QString &pcClasses, const QString &catClass, const QString &country, const QString &lang, const QByteArray &specContent, int specActive)
{
    AnnexDataWasteObject obj;
    obj.changed_on = changedOn;
    obj.id_old = idOld;
    obj.lfdnr = lfdnr;
    obj.spec_title = specTitle;
    obj.spec_desc = specDesc;
    obj.spec_version = specVersion;
    obj.spec_release = specRelease;
    obj.obj_sname = objSname;
    obj.ac_classes = acClasses;
    obj.pc_classes = pcClasses;
    obj.cat_class = catClass;
    obj.country = country;
    obj.lang = lang;
    obj.spec_content = specContent;
    obj.spec_active = specActive;
    if (!obj.create()) {
        return AnnexDataWaste();
    }
    return AnnexDataWaste(obj);
}

AnnexDataWaste AnnexDataWaste::create(const QVariantMap &values)
{
    AnnexDataWaste model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

AnnexDataWaste AnnexDataWaste::get(int id)
{
    TSqlORMapper<AnnexDataWasteObject> mapper;
    return AnnexDataWaste(mapper.findByPrimaryKey(id));
}

int AnnexDataWaste::count()
{
    TSqlORMapper<AnnexDataWasteObject> mapper;
    return mapper.findCount();
}

QList<AnnexDataWaste> AnnexDataWaste::getAll()
{
    return tfGetModelListByCriteria<AnnexDataWaste, AnnexDataWasteObject>(TCriteria());
}

QJsonArray AnnexDataWaste::getAllJson()
{
    QJsonArray array;
    TSqlORMapper<AnnexDataWasteObject> mapper;

    if (mapper.find() > 0) {
        for (TSqlORMapperIterator<AnnexDataWasteObject> i(mapper); i.hasNext(); ) {
            array.append(QJsonValue(QJsonObject::fromVariantMap(AnnexDataWaste(i.next()).toVariantMap())));
        }
    }
    return array;
}

TModelObject *AnnexDataWaste::modelData()
{
    return d.data();
}

const TModelObject *AnnexDataWaste::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const AnnexDataWaste &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, AnnexDataWaste &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(AnnexDataWaste)
