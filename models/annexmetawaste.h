#ifndef ANNEXMETAWASTE_H
#define ANNEXMETAWASTE_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class AnnexMetaWasteObject;
class QJsonArray;


class T_MODEL_EXPORT AnnexMetaWaste : public TAbstractModel
{
public:
    AnnexMetaWaste();
    AnnexMetaWaste(const AnnexMetaWaste &other);
    AnnexMetaWaste(const AnnexMetaWasteObject &object);
    ~AnnexMetaWaste();

    int id() const;
    QDateTime changedOn() const;
    void setChangedOn(const QDateTime &changedOn);
    int idOld() const;
    void setIdOld(int idOld);
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
    AnnexMetaWaste &operator=(const AnnexMetaWaste &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static AnnexMetaWaste create(const QDateTime &changedOn, int idOld, int specDataId, const QDateTime &specCreated, const QDateTime &specLastModified, const QDateTime &specValidStart, const QDateTime &specValidEnd, const QString &lastEditor, const QString &gLegacy, const QString &responsibility, const QString &specComment, const QString &specMarker, const QString &groups);
    static AnnexMetaWaste create(const QVariantMap &values);
    static AnnexMetaWaste get(int id);
    static int count();
    static QList<AnnexMetaWaste> getAll();
    static QJsonArray getAllJson();

private:
    QSharedDataPointer<AnnexMetaWasteObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const AnnexMetaWaste &model);
    friend QDataStream &operator>>(QDataStream &ds, AnnexMetaWaste &model);
};

Q_DECLARE_METATYPE(AnnexMetaWaste)
Q_DECLARE_METATYPE(QList<AnnexMetaWaste>)

#endif // ANNEXMETAWASTE_H
