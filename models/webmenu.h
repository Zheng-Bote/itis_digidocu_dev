#ifndef WEBMENU_H
#define WEBMENU_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class WebmenuObject;
class QJsonArray;


class T_MODEL_EXPORT Webmenu : public TAbstractModel
{
public:
    Webmenu();
    Webmenu(const Webmenu &other);
    Webmenu(const WebmenuObject &object);
    ~Webmenu();

    int id() const;
    int mnuId() const;
    void setMnuId(int mnuId);
    int mnuSubId() const;
    void setMnuSubId(int mnuSubId);
    QString nameDe() const;
    void setNameDe(const QString &nameDe);
    QString descDe() const;
    void setDescDe(const QString &descDe);
    QString nameEn() const;
    void setNameEn(const QString &nameEn);
    QString descEn() const;
    void setDescEn(const QString &descEn);
    QString mnuUri() const;
    void setMnuUri(const QString &mnuUri);
    QString groups() const;
    void setGroups(const QString &groups);
    QString mnuItem() const;
    void setMnuItem(const QString &mnuItem);
    int sort() const;
    void setSort(int sort);
    int active() const;
    void setActive(int active);
    Webmenu &operator=(const Webmenu &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static Webmenu create(int mnuId, int mnuSubId, const QString &nameDe, const QString &descDe, const QString &nameEn, const QString &descEn, const QString &mnuUri, const QString &groups, const QString &mnuItem, int sort, int active);
    static Webmenu create(const QVariantMap &values);
    static Webmenu get(int id);
    static int count();
    static QList<Webmenu> getAll();
    static QJsonArray getAllJson();

    static QJsonArray getMnu(QString groups);
    static QJsonArray getMnuSub(QString &mnu, QString groups);

private:
    QSharedDataPointer<WebmenuObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const Webmenu &model);
    friend QDataStream &operator>>(QDataStream &ds, Webmenu &model);
};

Q_DECLARE_METATYPE(Webmenu)
Q_DECLARE_METATYPE(QList<Webmenu>)

#endif // WEBMENU_H
