#ifndef LENKINFO_H
#define LENKINFO_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class LenkinfoObject;
class QJsonArray;


class T_MODEL_EXPORT Lenkinfo : public TAbstractModel
{
public:
    Lenkinfo();
    Lenkinfo(const Lenkinfo &other);
    Lenkinfo(const LenkinfoObject &object);
    ~Lenkinfo();

    int id() const;
    QString specObj() const;
    void setSpecObj(const QString &specObj);
    QString specTitle() const;
    void setSpecTitle(const QString &specTitle);
    int acClass() const;
    void setAcClass(int acClass);
    int pcClass() const;
    void setPcClass(int pcClass);
    QString country() const;
    void setCountry(const QString &country);
    QString lang() const;
    void setLang(const QString &lang);
    QString lenkVersion() const;
    void setLenkVersion(const QString &lenkVersion);
    QString lenkStatus() const;
    void setLenkStatus(const QString &lenkStatus);
    QDateTime lenkValidStartdate() const;
    void setLenkValidStartdate(const QDateTime &lenkValidStartdate);
    QString lenkDepartments() const;
    void setLenkDepartments(const QString &lenkDepartments);
    QString lenkContent() const;
    void setLenkContent(const QString &lenkContent);
    QString lenkCreator() const;
    void setLenkCreator(const QString &lenkCreator);
    QDateTime lenkCreatorDate() const;
    void setLenkCreatorDate(const QDateTime &lenkCreatorDate);
    QString lenkAuditor() const;
    void setLenkAuditor(const QString &lenkAuditor);
    QDateTime lenkAuditorDate() const;
    void setLenkAuditorDate(const QDateTime &lenkAuditorDate);
    QString lenkApprover() const;
    void setLenkApprover(const QString &lenkApprover);
    QDateTime lenkApproverDate() const;
    void setLenkApproverDate(const QDateTime &lenkApproverDate);
    Lenkinfo &operator=(const Lenkinfo &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static Lenkinfo create(const QString &specObj, const QString &specTitle, int acClass, int pcClass, const QString &country, const QString &lang, const QString &lenkVersion, const QString &lenkStatus, const QDateTime &lenkValidStartdate, const QString &lenkDepartments, const QString &lenkContent, const QString &lenkCreator, const QDateTime &lenkCreatorDate, const QString &lenkAuditor, const QDateTime &lenkAuditorDate, const QString &lenkApprover, const QDateTime &lenkApproverDate);
    static Lenkinfo create(const QVariantMap &values);
    static Lenkinfo get(int id);
    static int count();
    static QList<Lenkinfo> getAll();
    static QJsonArray getAllJson();
    static QJsonArray getJson(QMap<QString, QString> &stdDataMap);


private:
    QSharedDataPointer<LenkinfoObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const Lenkinfo &model);
    friend QDataStream &operator>>(QDataStream &ds, Lenkinfo &model);
};

Q_DECLARE_METATYPE(Lenkinfo)
Q_DECLARE_METATYPE(QList<Lenkinfo>)

#endif // LENKINFO_H
