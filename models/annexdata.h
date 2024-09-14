#ifndef ANNEXDATA_H
#define ANNEXDATA_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class AnnexDataObject;
class QJsonArray;


class T_MODEL_EXPORT AnnexData : public TAbstractModel
{
public:
    AnnexData();
    AnnexData(const AnnexData &other);
    AnnexData(const AnnexDataObject &object);
    ~AnnexData();

    int id() const;
    QString lfdnr() const;
    void setLfdnr(const QString &lfdnr);
    QString specTitle() const;
    void setSpecTitle(const QString &specTitle);
    QString specDesc() const;
    void setSpecDesc(const QString &specDesc);
    QString specVersion() const;
    void setSpecVersion(const QString &specVersion);
    QString specRelease() const;
    void setSpecRelease(const QString &specRelease);
    QString objSname() const;
    void setObjSname(const QString &objSname);
    QString acClasses() const;
    void setAcClasses(const QString &acClasses);
    QString pcClasses() const;
    void setPcClasses(const QString &pcClasses);
    QString catClass() const;
    void setCatClass(const QString &catClass);
    QString country() const;
    void setCountry(const QString &country);
    QString lang() const;
    void setLang(const QString &lang);
    QByteArray specContent() const;
    void setSpecContent(const QByteArray &specContent);
    int specActive() const;
    void setSpecActive(int specActive);
    AnnexData &operator=(const AnnexData &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }
    static QJsonArray setAnnexData(QMap<QString, QString> editMap);
    static QJsonArray updAnnexData(QMap<QString, QString> editMap);
    static QJsonArray upPrelease(int id);
    static QJsonArray doPreRelease(QMap<QString, QString> editMap);
    static QJsonArray upReleased(int id);
    static QJsonArray doReleased(QMap<QString, QString> editMap);
    static void setDraft(int id, QString comment);

    static AnnexData create(const QString &lfdnr, const QString &specTitle, const QString &specDesc, const QString &specVersion, const QString &specRelease, const QString &objSname, const QString &acClasses, const QString &pcClasses, const QString &catClass, const QString &country, const QString &lang, const QByteArray &specContent, int specActive);
    static AnnexData create(const QVariantMap &values);
    static AnnexData get(int id);
    static int count();

    static QList<AnnexData> getAll();
    static QJsonArray getAllJson();
    static QJsonArray getAllJsonCi();
    static QJsonArray getStatistics();
    static QJsonArray getExistCountries();
    static QJsonArray getAnnexList(QMap<QString, QString> &stdDataMap);
    static QJsonArray getAnnexShow(QMap<QString, QString> &stdDataMap);
    static QJsonArray getAnnexSpec(int &id);
    static QJsonArray getAnnexToc(QMap<QString, QString> &stdDataMap);
    static void findAndReplaceAll(std::string &data, QString &lang, QString std_type);

    //static QJsonArray listObjCatalog(QMap<QString, QString> editMap);
    static QJsonArray listObjCatalog(bool doToc, QMap<QString, QString> editMap);
    static QMap<QString, QString> sqlObjCatalog(QString name, QString ac, QString pc, QString country, QString lang, QString cat, QString spec_active, QString release);
    static QMap<QString, QString> checkObjCatalog(QMap<QString, QString> wwList, QMap<QString, QString> localList);
    // static QJsonArray sqlGet_crObjCatalog(QMap<QString, QString> outList);
    static QJsonArray sqlGet_crObjCatalog(bool doToc, QMap<QString, QString> outList);

    static int countCheckLfdnrCat();
    static QJsonArray getHighestLfdnr(const QString &category);
    static QJsonArray chkLfdnrEditor(QMap<QString, QString> editMap);

    static void writeAnnex(QMap<QString, QString> &stdDataMap);
    static void writeAnnexHtml(QMap<QString, QString> &stdDataMap);

private:
    QSharedDataPointer<AnnexDataObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const AnnexData &model);
    friend QDataStream &operator>>(QDataStream &ds, AnnexData &model);
};

Q_DECLARE_METATYPE(AnnexData)
Q_DECLARE_METATYPE(QList<AnnexData>)

#endif // ANNEXDATA_H
