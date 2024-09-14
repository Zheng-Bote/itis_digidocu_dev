#ifndef ANNEXDATACOMMENTSOBJECT_H
#define ANNEXDATACOMMENTSOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT AnnexDataCommentsObject : public TSqlObject, public QSharedData
{
public:
    int id {0};
    QDateTime comment_created;
    int spec_id {0};
    QString spec_title;
    QString spec_version;
    QString user_comment;
    QString username;

    enum PropertyIndex {
        Id = 0,
        CommentCreated,
        SpecId,
        SpecTitle,
        SpecVersion,
        UserComment,
        Username,
    };

    int primaryKeyIndex() const override { return Id; }
    int autoValueIndex() const override { return Id; }
    QString tableName() const override { return QStringLiteral("annex_data_comments"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int id READ getid WRITE setid)
    T_DEFINE_PROPERTY(int, id)
    Q_PROPERTY(QDateTime comment_created READ getcomment_created WRITE setcomment_created)
    T_DEFINE_PROPERTY(QDateTime, comment_created)
    Q_PROPERTY(int spec_id READ getspec_id WRITE setspec_id)
    T_DEFINE_PROPERTY(int, spec_id)
    Q_PROPERTY(QString spec_title READ getspec_title WRITE setspec_title)
    T_DEFINE_PROPERTY(QString, spec_title)
    Q_PROPERTY(QString spec_version READ getspec_version WRITE setspec_version)
    T_DEFINE_PROPERTY(QString, spec_version)
    Q_PROPERTY(QString user_comment READ getuser_comment WRITE setuser_comment)
    T_DEFINE_PROPERTY(QString, user_comment)
    Q_PROPERTY(QString username READ getusername WRITE setusername)
    T_DEFINE_PROPERTY(QString, username)
};

#endif // ANNEXDATACOMMENTSOBJECT_H
