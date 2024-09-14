#ifndef ANNEXDATACOMMENTS_H
#define ANNEXDATACOMMENTS_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class AnnexDataCommentsObject;
class QJsonArray;


class T_MODEL_EXPORT AnnexDataComments : public TAbstractModel
{
public:
    AnnexDataComments();
    AnnexDataComments(const AnnexDataComments &other);
    AnnexDataComments(const AnnexDataCommentsObject &object);
    ~AnnexDataComments();

    int id() const;
    QDateTime commentCreated() const;
    void setCommentCreated(const QDateTime &commentCreated);
    int specId() const;
    void setSpecId(int specId);
    QString specTitle() const;
    void setSpecTitle(const QString &specTitle);
    QString specVersion() const;
    void setSpecVersion(const QString &specVersion);
    QString userComment() const;
    void setUserComment(const QString &userComment);
    QString username() const;
    void setUsername(const QString &username);
    AnnexDataComments &operator=(const AnnexDataComments &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static QJsonArray createComment(int spec_id, const QString &spec_title, const QString &spec_version, const QString &user_comment, const QString &username);
    static AnnexDataComments create(const QDateTime &commentCreated, int specId, const QString &specTitle, const QString &specVersion, const QString &userComment, const QString &username);
    static AnnexDataComments create(const QVariantMap &values);
    static AnnexDataComments get(int id);
    static int count();
    static QList<AnnexDataComments> getAll();
    static QJsonArray getAllJson();
    static QMap<QString, QString> getStatistics();
    static int getSpecsCommentsCount(const int &spec_id);
    static QJsonArray getSpecComments(const int &spec_id);

private:
    QSharedDataPointer<AnnexDataCommentsObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const AnnexDataComments &model);
    friend QDataStream &operator>>(QDataStream &ds, AnnexDataComments &model);
};

Q_DECLARE_METATYPE(AnnexDataComments)
Q_DECLARE_METATYPE(QList<AnnexDataComments>)

#endif // ANNEXDATACOMMENTS_H
