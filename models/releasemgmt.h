#ifndef RELEASEMGMT_H
#define RELEASEMGMT_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class ReleaseMgmtObject;
class QJsonArray;


class T_MODEL_EXPORT ReleaseMgmt : public TAbstractModel
{
public:
    ReleaseMgmt();
    ReleaseMgmt(const ReleaseMgmt &other);
    ReleaseMgmt(const ReleaseMgmtObject &object);
    ~ReleaseMgmt();

    int id() const;
    QString objSname() const;
    void setObjSname(const QString &objSname);
    QString specVersion() const;
    void setSpecVersion(const QString &specVersion);
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
    QString docType() const;
    void setDocType(const QString &docType);
    QString relRequester() const;
    void setRelRequester(const QString &relRequester);
    QDateTime relrequestDate() const;
    void setRelrequestDate(const QDateTime &relrequestDate);
    QString relCreator() const;
    void setRelCreator(const QString &relCreator);
    QDateTime relcreatorDecisdate() const;
    void setRelcreatorDecisdate(const QDateTime &relcreatorDecisdate);
    QString relInspector() const;
    void setRelInspector(const QString &relInspector);
    QDateTime relinspectDecisdate() const;
    void setRelinspectDecisdate(const QDateTime &relinspectDecisdate);
    QString relApprover() const;
    void setRelApprover(const QString &relApprover);
    QDateTime relapprovDecisdate() const;
    void setRelapprovDecisdate(const QDateTime &relapprovDecisdate);
    QDateTime ciDate() const;
    void setCiDate(const QDateTime &ciDate);
    QDateTime cdDate() const;
    void setCdDate(const QDateTime &cdDate);
    QDateTime cddDate() const;
    void setCddDate(const QDateTime &cddDate);
    ReleaseMgmt &operator=(const ReleaseMgmt &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static ReleaseMgmt create(const QString &objSname, const QString &specVersion, const QString &acClasses, const QString &pcClasses, const QString &catClass, const QString &country, const QString &lang, const QString &docType, const QString &relRequester, const QDateTime &relrequestDate, const QString &relCreator, const QDateTime &relcreatorDecisdate, const QString &relInspector, const QDateTime &relinspectDecisdate, const QString &relApprover, const QDateTime &relapprovDecisdate, const QDateTime &ciDate, const QDateTime &cdDate, const QDateTime &cddDate);
    static ReleaseMgmt create(const QVariantMap &values);
    static ReleaseMgmt get(int id);
    static int count();
    static QList<ReleaseMgmt> getAll();
    static QJsonArray getAllJson();
    static QJsonArray listall_ciannex();

    static QJsonArray list_allAnnexCi();
    static QJsonArray list_allAnnexCd();
    static QJsonArray list_allStdCi();
    static QJsonArray list_allStdCd();

    static QJsonArray ci_update(QMap<QString, QString> stdDataMap);

    static QJsonArray fileRemove(QMap<QString, QString> stdDataMap);

    static int crPDF(const QString &htmlFile, const QString &pdfFile);

private:
    QSharedDataPointer<ReleaseMgmtObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const ReleaseMgmt &model);
    friend QDataStream &operator>>(QDataStream &ds, ReleaseMgmt &model);
};

Q_DECLARE_METATYPE(ReleaseMgmt)
Q_DECLARE_METATYPE(QList<ReleaseMgmt>)

#endif // RELEASEMGMT_H
