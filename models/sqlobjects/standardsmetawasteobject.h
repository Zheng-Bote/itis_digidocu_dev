#ifndef STANDARDSMETAWASTEOBJECT_H
#define STANDARDSMETAWASTEOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT StandardsMetaWasteObject : public TSqlObject, public QSharedData
{
public:
    int id {0};
    QDateTime changed_on;
    int id_old {0};
    int spec_data_id {0};
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

    enum PropertyIndex {
        Id = 0,
        ChangedOn,
        IdOld,
        SpecDataId,
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
    };

    int primaryKeyIndex() const override { return Id; }
    int autoValueIndex() const override { return Id; }
    QString tableName() const override { return QStringLiteral("standards_meta_waste"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int id READ getid WRITE setid)
    T_DEFINE_PROPERTY(int, id)
    Q_PROPERTY(QDateTime changed_on READ getchanged_on WRITE setchanged_on)
    T_DEFINE_PROPERTY(QDateTime, changed_on)
    Q_PROPERTY(int id_old READ getid_old WRITE setid_old)
    T_DEFINE_PROPERTY(int, id_old)
    Q_PROPERTY(int spec_data_id READ getspec_data_id WRITE setspec_data_id)
    T_DEFINE_PROPERTY(int, spec_data_id)
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
};

#endif // STANDARDSMETAWASTEOBJECT_H
