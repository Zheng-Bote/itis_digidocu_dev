#ifndef ANNEXMETA_H
#define ANNEXMETA_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class AnnexMetaObject;
class QJsonArray;


class T_MODEL_EXPORT AnnexMeta : public TAbstractModel
{
public:
    AnnexMeta();
    AnnexMeta(const AnnexMeta &other);
    AnnexMeta(const AnnexMetaObject &object);
    ~AnnexMeta();

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
    AnnexMeta &operator=(const AnnexMeta &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static AnnexMeta create(int specDataId, const QDateTime &specCreated, const QDateTime &specLastModified, const QDateTime &specValidStart, const QDateTime &specValidEnd, const QString &lastEditor, const QString &gLegacy, const QString &responsibility, const QString &specComment, const QString &specMarker, const QString &groups);
    static AnnexMeta create(const QVariantMap &values);
    static AnnexMeta get(int id);
    static AnnexMeta getBySpecDataId(int spec_data_id);
    static int count();
    static QList<AnnexMeta> getAll();
    static QJsonArray getAllJson();

private:
    QSharedDataPointer<AnnexMetaObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const AnnexMeta &model);
    friend QDataStream &operator>>(QDataStream &ds, AnnexMeta &model);
};

Q_DECLARE_METATYPE(AnnexMeta)
Q_DECLARE_METATYPE(QList<AnnexMeta>)

#endif // ANNEXMETA_H
