#ifndef STANDARDSDATACOMMENTS_H
#define STANDARDSDATACOMMENTS_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class StandardsDataCommentsObject;
class QJsonArray;


class T_MODEL_EXPORT StandardsDataComments : public TAbstractModel
{
public:
    StandardsDataComments();
    StandardsDataComments(const StandardsDataComments &other);
    StandardsDataComments(const StandardsDataCommentsObject &object);
    ~StandardsDataComments();

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
    StandardsDataComments &operator=(const StandardsDataComments &other);

    bool create() override { return TAbstractModel::create(); }  
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static QJsonArray createComment(int spec_id, const QString &spec_title, const QString &spec_version, const QString &user_comment, const QString &username);

    static StandardsDataComments create(const QDateTime &commentCreated, int specId, const QString &specTitle, const QString &specVersion, const QString &userComment, const QString &username);
    static StandardsDataComments create(const QVariantMap &values);
    static StandardsDataComments get(int id);
    static int count();
    static QList<StandardsDataComments> getAll();
    static QJsonArray getAllJson();
    static QMap<QString, QString> getStatistics();
    static int getSpecsCommentsCount(const int &spec_id);
    static QJsonArray getSpecComments(const int &spec_id);

private:
    QSharedDataPointer<StandardsDataCommentsObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const StandardsDataComments &model);
    friend QDataStream &operator>>(QDataStream &ds, StandardsDataComments &model);
};

Q_DECLARE_METATYPE(StandardsDataComments)
Q_DECLARE_METATYPE(QList<StandardsDataComments>)

#endif // STANDARDSDATACOMMENTS_H
