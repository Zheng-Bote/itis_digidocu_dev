#ifndef STANDARDSMETA_H
#define STANDARDSMETA_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class StandardsMetaObject;
class QJsonArray;


class T_MODEL_EXPORT StandardsMeta : public TAbstractModel
{
public:
    StandardsMeta();
    StandardsMeta(const StandardsMeta &other);
    StandardsMeta(const StandardsMetaObject &object);
    ~StandardsMeta();

    int id() const;
    int specDataId() const;
    void setSpecDataId(int specDataId);
    QDateTime specCreated() const;
    void setSpecCreated(const QDateTime &specCreated);
    QDateTime specLastModified() const;
    void setSpecLastModified(const QDateTime &specLastModified);
    QDateTime specValidStart() const;
    void setSpecValidStart(const QDateTime &specValidStart);
    QDateTime specValidEnd() const;
    void setSpecValidEnd(const QDateTime &specValidEnd);
    QString lastEditor() const;
    void setLastEditor(const QString &lastEditor);
    QString gLegacy() const;
    void setGLegacy(const QString &gLegacy);
    QString responsibility() const;
    void setResponsibility(const QString &responsibility);
    QString specComment() const;
    void setSpecComment(const QString &specComment);
    QString specMarker() const;
    void setSpecMarker(const QString &specMarker);
    QString groups() const;
    void setGroups(const QString &groups);
    StandardsMeta &operator=(const StandardsMeta &other);

    static void saveMeta(int id, QString username);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static StandardsMeta create(int specDataId, const QDateTime &specCreated, const QDateTime &specLastModified, const QDateTime &specValidStart, const QDateTime &specValidEnd, const QString &lastEditor, const QString &gLegacy, const QString &responsibility, const QString &specComment, const QString &specMarker, const QString &groups);
    static StandardsMeta create(const QVariantMap &values);
    static StandardsMeta get(int id);
    static StandardsMeta getBySpecDataId(int spec_data_id);
    static int count();
    static QList<StandardsMeta> getAll();
    static QJsonArray getAllJson();

private:
    QSharedDataPointer<StandardsMetaObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const StandardsMeta &model);
    friend QDataStream &operator>>(QDataStream &ds, StandardsMeta &model);
};

Q_DECLARE_METATYPE(StandardsMeta)
Q_DECLARE_METATYPE(QList<StandardsMeta>)

#endif // STANDARDSMETA_H
