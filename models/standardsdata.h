#ifndef STANDARDSDATA_H
#define STANDARDSDATA_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class StandardsDataObject;
class QJsonArray;


class T_MODEL_EXPORT StandardsData : public TAbstractModel
{
public:
    StandardsData();
    StandardsData(const StandardsData &other);
    StandardsData(const StandardsDataObject &object);
    ~StandardsData();

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
    StandardsData &operator=(const StandardsData &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }
    static QJsonArray setStdData(QMap<QString, QString> editMap);
    static QJsonArray updStdData(QMap<QString, QString> editMap);
    static QJsonArray upPrelease(int id);
    static QJsonArray doPreRelease(QMap<QString, QString> editMap);
    static QJsonArray upReleased(int id);
    static void setDraft(int id, QString comment);

    static StandardsData create(const QString &lfdnr, const QString &specTitle, const QString &specDesc, const QString &specVersion, const QString &specRelease, const QString &objSname, const QString &acClasses, const QString &pcClasses, const QString &catClass, const QString &country, const QString &lang, const QByteArray &specContent, int specActive);
    static StandardsData create(const QVariantMap &values);
    static StandardsData get(int id);
    static int count();

    static QList<StandardsData> getAll();
    static QJsonArray getAllJson();
    static QJsonArray getStatistics();
    static QJsonArray getHighestLfdnr(const QString &category);
    static QJsonArray getCheckLfdnrCat();
    static int countCheckLfdnrCat();
    static QJsonArray getExistCountries();
    static QJsonArray getStdList(QMap<QString, QString> &stdDataMap);
    static QJsonArray getStdShow(QMap<QString, QString> &stdDataMap);
    static QJsonArray getStdToc(QMap<QString, QString> &stdDataMap);
    static QJsonArray getStdSpec(int &id);
    static void findAndReplaceAll(std::string &data, QString &lang, QString std_type);

    static QJsonArray listObjCatalog(bool doToc, QMap<QString, QString> editMap);
    static QMap<QString, QString> sqlObjCatalog(QString name, QString ac, QString pc, QString country, QString lang, QString cat, QString spec_active, QString release);
    static QMap<QString, QString> checkObjCatalog(QMap<QString, QString> wwList, QMap<QString, QString> localList);
    static QJsonArray sqlGet_crObjCatalog(bool doToc, QMap<QString, QString> outList);

    static QJsonArray chkLfdnrEditor(QMap<QString, QString> editMap);

private:
    QSharedDataPointer<StandardsDataObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const StandardsData &model);
    friend QDataStream &operator>>(QDataStream &ds, StandardsData &model);
};

Q_DECLARE_METATYPE(StandardsData)
Q_DECLARE_METATYPE(QList<StandardsData>)

#endif // STANDARDSDATA_H
