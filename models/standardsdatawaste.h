#ifndef STANDARDSDATAWASTE_H
#define STANDARDSDATAWASTE_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class StandardsDataWasteObject;
class QJsonArray;


class T_MODEL_EXPORT StandardsDataWaste : public TAbstractModel
{
public:
    StandardsDataWaste();
    StandardsDataWaste(const StandardsDataWaste &other);
    StandardsDataWaste(const StandardsDataWasteObject &object);
    ~StandardsDataWaste();

    int id() const;
    QDateTime changedOn() const;
    void setChangedOn(const QDateTime &changedOn);
    int idOld() const;
    void setIdOld(int idOld);
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
    StandardsDataWaste &operator=(const StandardsDataWaste &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static StandardsDataWaste create(const QDateTime &changedOn, int idOld, const QString &lfdnr, const QString &specTitle, const QString &specDesc, const QString &specVersion, const QString &specRelease, const QString &objSname, const QString &acClasses, const QString &pcClasses, const QString &catClass, const QString &country, const QString &lang, const QByteArray &specContent, int specActive);
    static StandardsDataWaste create(const QVariantMap &values);
    static StandardsDataWaste get(int id);
    static int count();
    static QList<StandardsDataWaste> getAll();
    static QJsonArray getAllJson();

    static QJsonArray doRecover(int id);

private:
    QSharedDataPointer<StandardsDataWasteObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const StandardsDataWaste &model);
    friend QDataStream &operator>>(QDataStream &ds, StandardsDataWaste &model);
};

Q_DECLARE_METATYPE(StandardsDataWaste)
Q_DECLARE_METATYPE(QList<StandardsDataWaste>)

#endif // STANDARDSDATAWASTE_H
