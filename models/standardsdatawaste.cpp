#include <TreeFrogModel>
#include "standardsdatawaste.h"
#include "sqlobjects/standardsdatawasteobject.h"

StandardsDataWaste::StandardsDataWaste() :
    TAbstractModel(),
    d(new StandardsDataWasteObject())
{
    // set the initial parameters
}

StandardsDataWaste::StandardsDataWaste(const StandardsDataWaste &other) :
    TAbstractModel(),
    d(other.d)
{ }

StandardsDataWaste::StandardsDataWaste(const StandardsDataWasteObject &object) :
    TAbstractModel(),
    d(new StandardsDataWasteObject(object))
{ }

StandardsDataWaste::~StandardsDataWaste()
{
    // If the reference count becomes 0,
    // the shared data object 'StandardsDataWasteObject' is deleted.
}

// #####
QJsonArray StandardsDataWaste::doRecover(int id)
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

int StandardsDataWaste::id() const
{
    return d->id;
}

QDateTime StandardsDataWaste::changedOn() const
{
    return d->changed_on;
}

void StandardsDataWaste::setChangedOn(const QDateTime &changedOn)
{
    d->changed_on = changedOn;
}

int StandardsDataWaste::idOld() const
{
    return d->id_old;
}

void StandardsDataWaste::setIdOld(int idOld)
{
    d->id_old = idOld;
}

QString StandardsDataWaste::lfdnr() const
{
    return d->lfdnr;
}

void StandardsDataWaste::setLfdnr(const QString &lfdnr)
{
    d->lfdnr = lfdnr;
}

QString StandardsDataWaste::specTitle() const
{
    return d->spec_title;
}

void StandardsDataWaste::setSpecTitle(const QString &specTitle)
{
    d->spec_title = specTitle;
}

QString StandardsDataWaste::specDesc() const
{
    return d->spec_desc;
}

void StandardsDataWaste::setSpecDesc(const QString &specDesc)
{
    d->spec_desc = specDesc;
}

QString StandardsDataWaste::specVersion() const
{
    return d->spec_version;
}

void StandardsDataWaste::setSpecVersion(const QString &specVersion)
{
    d->spec_version = specVersion;
}

QString StandardsDataWaste::specRelease() const
{
    return d->spec_release;
}

void StandardsDataWaste::setSpecRelease(const QString &specRelease)
{
    d->spec_release = specRelease;
}

QString StandardsDataWaste::objSname() const
{
    return d->obj_sname;
}

void StandardsDataWaste::setObjSname(const QString &objSname)
{
    d->obj_sname = objSname;
}

QString StandardsDataWaste::acClasses() const
{
    return d->ac_classes;
}

void StandardsDataWaste::setAcClasses(const QString &acClasses)
{
    d->ac_classes = acClasses;
}

QString StandardsDataWaste::pcClasses() const
{
    return d->pc_classes;
}

void StandardsDataWaste::setPcClasses(const QString &pcClasses)
{
    d->pc_classes = pcClasses;
}

QString StandardsDataWaste::catClass() const
{
    return d->cat_class;
}

void StandardsDataWaste::setCatClass(const QString &catClass)
{
    d->cat_class = catClass;
}

QString StandardsDataWaste::country() const
{
    return d->country;
}

void StandardsDataWaste::setCountry(const QString &country)
{
    d->country = country;
}

QString StandardsDataWaste::lang() const
{
    return d->lang;
}

void StandardsDataWaste::setLang(const QString &lang)
{
    d->lang = lang;
}

QByteArray StandardsDataWaste::specContent() const
{
    return d->spec_content;
}

void StandardsDataWaste::setSpecContent(const QByteArray &specContent)
{
    d->spec_content = specContent;
}

int StandardsDataWaste::specActive() const
{
    return d->spec_active;
}

void StandardsDataWaste::setSpecActive(int specActive)
{
    d->spec_active = specActive;
}

StandardsDataWaste &StandardsDataWaste::operator=(const StandardsDataWaste &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

StandardsDataWaste StandardsDataWaste::create(const QDateTime &changedOn, int idOld, const QString &lfdnr, const QString &specTitle, const QString &specDesc, const QString &specVersion, const QString &specRelease, const QString &objSname, const QString &acClasses, const QString &pcClasses, const QString &catClass, const QString &country, const QString &lang, const QByteArray &specContent, int specActive)
{
    StandardsDataWasteObject obj;
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
        return StandardsDataWaste();
    }
    return StandardsDataWaste(obj);
}

StandardsDataWaste StandardsDataWaste::create(const QVariantMap &values)
{
    StandardsDataWaste model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

StandardsDataWaste StandardsDataWaste::get(int id)
{
    TSqlORMapper<StandardsDataWasteObject> mapper;
    return StandardsDataWaste(mapper.findByPrimaryKey(id));
}

int StandardsDataWaste::count()
{
    TSqlORMapper<StandardsDataWasteObject> mapper;
    return mapper.findCount();
}

QList<StandardsDataWaste> StandardsDataWaste::getAll()
{
    return tfGetModelListByCriteria<StandardsDataWaste, StandardsDataWasteObject>(TCriteria());
}

QJsonArray StandardsDataWaste::getAllJson()
{
    QJsonArray array;
    TSqlORMapper<StandardsDataWasteObject> mapper;

    if (mapper.find() > 0) {
        for (TSqlORMapperIterator<StandardsDataWasteObject> i(mapper); i.hasNext(); ) {
            array.append(QJsonValue(QJsonObject::fromVariantMap(StandardsDataWaste(i.next()).toVariantMap())));
        }
    }
    return array;
}

TModelObject *StandardsDataWaste::modelData()
{
    return d.data();
}

const TModelObject *StandardsDataWaste::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const StandardsDataWaste &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, StandardsDataWaste &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(StandardsDataWaste)
