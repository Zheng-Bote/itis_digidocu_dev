#ifndef RELEASEANNEXOBJECT_H
#define RELEASEANNEXOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT ReleaseAnnexObject : public TSqlObject, public QSharedData
{
public:
    int id {0};
    QString lfdnr;
    QString spec_title;
    QString spec_desc;
    QString spec_version;
    QString release_version;
    QString spec_release;
    QString obj_sname;
    QString ac_class;
    QString pc_class;
    QString cat_class;
    QString country;
    QString lang;
    QByteArray spec_content;
    QDateTime spec_created;
    QDateTime spec_last_modified;
    QDateTime spec_valid_start;
    QDateTime spec_valid_end;
    QString last_editor;
    QString g_legacy;
    QString responsibility;
    QString spec_comment;
    QString spec_marker;
    QString groups;
    int spec_active {0};

    enum PropertyIndex {
        Id = 0,
        Lfdnr,
        SpecTitle,
        SpecDesc,
        SpecVersion,
        ReleaseVersion,
        SpecRelease,
        ObjSname,
        AcClass,
        PcClass,
        CatClass,
        Country,
        Lang,
        SpecContent,
        SpecCreated,
        SpecLastModified,
        SpecValidStart,
        SpecValidEnd,
        LastEditor,
        GLegacy,
        Responsibility,
        SpecComment,
        SpecMarker,
        Groups,
        SpecActive,
    };

    int primaryKeyIndex() const override { return Id; }
    int autoValueIndex() const override { return Id; }
    QString tableName() const override { return QStringLiteral("release_annex"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int id READ getid WRITE setid)
    T_DEFINE_PROPERTY(int, id)
    Q_PROPERTY(QString lfdnr READ getlfdnr WRITE setlfdnr)
    T_DEFINE_PROPERTY(QString, lfdnr)
    Q_PROPERTY(QString spec_title READ getspec_title WRITE setspec_title)
    T_DEFINE_PROPERTY(QString, spec_title)
    Q_PROPERTY(QString spec_desc READ getspec_desc WRITE setspec_desc)
    T_DEFINE_PROPERTY(QString, spec_desc)
    Q_PROPERTY(QString spec_version READ getspec_version WRITE setspec_version)
    T_DEFINE_PROPERTY(QString, spec_version)
    Q_PROPERTY(QString release_version READ getrelease_version WRITE setrelease_version)
    T_DEFINE_PROPERTY(QString, release_version)
    Q_PROPERTY(QString spec_release READ getspec_release WRITE setspec_release)
    T_DEFINE_PROPERTY(QString, spec_release)
    Q_PROPERTY(QString obj_sname READ getobj_sname WRITE setobj_sname)
    T_DEFINE_PROPERTY(QString, obj_sname)
    Q_PROPERTY(QString ac_class READ getac_class WRITE setac_class)
    T_DEFINE_PROPERTY(QString, ac_class)
    Q_PROPERTY(QString pc_class READ getpc_class WRITE setpc_class)
    T_DEFINE_PROPERTY(QString, pc_class)
    Q_PROPERTY(QString cat_class READ getcat_class WRITE setcat_class)
    T_DEFINE_PROPERTY(QString, cat_class)
    Q_PROPERTY(QString country READ getcountry WRITE setcountry)
    T_DEFINE_PROPERTY(QString, country)
    Q_PROPERTY(QString lang READ getlang WRITE setlang)
    T_DEFINE_PROPERTY(QString, lang)
    Q_PROPERTY(QByteArray spec_content READ getspec_content WRITE setspec_content)
    T_DEFINE_PROPERTY(QByteArray, spec_content)
    Q_PROPERTY(QDateTime spec_created READ getspec_created WRITE setspec_created)
    T_DEFINE_PROPERTY(QDateTime, spec_created)
    Q_PROPERTY(QDateTime spec_last_modified READ getspec_last_modified WRITE setspec_last_modified)
    T_DEFINE_PROPERTY(QDateTime, spec_last_modified)
    Q_PROPERTY(QDateTime spec_valid_start READ getspec_valid_start WRITE setspec_valid_start)
    T_DEFINE_PROPERTY(QDateTime, spec_valid_start)
    Q_PROPERTY(QDateTime spec_valid_end READ getspec_valid_end WRITE setspec_valid_end)
    T_DEFINE_PROPERTY(QDateTime, spec_valid_end)
    Q_PROPERTY(QString last_editor READ getlast_editor WRITE setlast_editor)
    T_DEFINE_PROPERTY(QString, last_editor)
    Q_PROPERTY(QString g_legacy READ getg_legacy WRITE setg_legacy)
    T_DEFINE_PROPERTY(QString, g_legacy)
    Q_PROPERTY(QString responsibility READ getresponsibility WRITE setresponsibility)
    T_DEFINE_PROPERTY(QString, responsibility)
    Q_PROPERTY(QString spec_comment READ getspec_comment WRITE setspec_comment)
    T_DEFINE_PROPERTY(QString, spec_comment)
    Q_PROPERTY(QString spec_marker READ getspec_marker WRITE setspec_marker)
    T_DEFINE_PROPERTY(QString, spec_marker)
    Q_PROPERTY(QString groups READ getgroups WRITE setgroups)
    T_DEFINE_PROPERTY(QString, groups)
    Q_PROPERTY(int spec_active READ getspec_active WRITE setspec_active)
    T_DEFINE_PROPERTY(int, spec_active)
};

#endif // RELEASEANNEXOBJECT_H
