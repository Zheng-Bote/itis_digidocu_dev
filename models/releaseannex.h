#ifndef RELEASEANNEX_H
#define RELEASEANNEX_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>



class TModelObject;
class ReleaseAnnexObject;
class QJsonArray;


class T_MODEL_EXPORT ReleaseAnnex : public TAbstractModel
{
public:
    ReleaseAnnex();
    ReleaseAnnex(const ReleaseAnnex &other);
    ReleaseAnnex(const ReleaseAnnexObject &object);
    ~ReleaseAnnex();

    int id() const;
    QString lfdnr() const;
    void setLfdnr(const QString &lfdnr);
    QString specTitle() const;
    void setSpecTitle(const QString &specTitle);
    QString specDesc() const;
    void setSpecDesc(const QString &specDesc);
    QString specVersion() const;
    void setSpecVersion(const QString &specVersion);
    QString releaseVersion() const;
    void setReleaseVersion(const QString &releaseVersion);
    QString specRelease() const;
    void setSpecRelease(const QString &specRelease);
    QString objSname() const;
    void setObjSname(const QString &objSname);
    QString acClass() const;
    void setAcClass(const QString &acClass);
    QString pcClass() const;
    void setPcClass(const QString &pcClass);
    QString catClass() const;
    void setCatClass(const QString &catClass);
    QString country() const;
    void setCountry(const QString &country);
    QString lang() const;
    void setLang(const QString &lang);
    QByteArray specContent() const;
    void setSpecContent(const QByteArray &specContent);
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
    int specActive() const;
    void setSpecActive(int specActive);

    static QJsonArray getAnnexList(QMap<QString, QString> &stdDataMap);
    static QJsonArray getAnnexSpec(int &id);
    static void findAndReplaceAll(std::string &data, QString &lang, QString std_type);

    ReleaseAnnex &operator=(const ReleaseAnnex &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static ReleaseAnnex create(const QString &lfdnr, const QString &specTitle, const QString &specDesc, const QString &specVersion, const QString &releaseVersion, const QString &specRelease, const QString &objSname, const QString &acClass, const QString &pcClass, const QString &catClass, const QString &country, const QString &lang, const QByteArray &specContent, const QDateTime &specCreated, const QDateTime &specLastModified, const QDateTime &specValidStart, const QDateTime &specValidEnd, const QString &lastEditor, const QString &gLegacy, const QString &responsibility, const QString &specComment, const QString &specMarker, const QString &groups, int specActive);
    static ReleaseAnnex create(const QVariantMap &values);
    static ReleaseAnnex get(int id);
    static int count();
    static QList<ReleaseAnnex> getAll();
    static QJsonArray getAllJson();

    static QJsonArray getAnnexToc(QMap<QString, QString> &stdDataMap);
    //static QJsonArray listObjCatalog(QMap<QString, QString> editMap);
    static QJsonArray listObjCatalog(bool doToc, QMap<QString, QString> editMap);
    static QMap<QString, QString> sqlObjCatalog(QString name, QString ac, QString pc, QString country, QString lang, QString cat, QString spec_active, QString release);
    static QMap<QString, QString> checkObjCatalog(QMap<QString, QString> wwList, QMap<QString, QString> localList);
    // static QJsonArray sqlGet_crObjCatalog(QMap<QString, QString> outList);
    static QJsonArray sqlGet_crObjCatalog(bool doToc, QMap<QString, QString> outList);

private:
    QSharedDataPointer<ReleaseAnnexObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const ReleaseAnnex &model);
    friend QDataStream &operator>>(QDataStream &ds, ReleaseAnnex &model);
};

Q_DECLARE_METATYPE(ReleaseAnnex)
Q_DECLARE_METATYPE(QList<ReleaseAnnex>)

#endif // RELEASEANNEX_H
