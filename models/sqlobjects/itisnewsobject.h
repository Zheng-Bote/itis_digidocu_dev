#ifndef ITISNEWSOBJECT_H
#define ITISNEWSOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT ItisNewsObject : public TSqlObject, public QSharedData
{
public:
    int id {0};
    QString news_type;
    QString news_type_sub;
    QString news_title_de;
    QString news_title_en;
    QString news_desc_de;
    QString news_desc_en;
    QString news_text_de;
    QString news_text_en;
    QString news_prio;
    QString author;
    QDateTime news_created;
    QDateTime news_valid_start;
    QDateTime news_valid_end;

    enum PropertyIndex {
        Id = 0,
        NewsType,
        NewsTypeSub,
        NewsTitleDe,
        NewsTitleEn,
        NewsDescDe,
        NewsDescEn,
        NewsTextDe,
        NewsTextEn,
        NewsPrio,
        Author,
        NewsCreated,
        NewsValidStart,
        NewsValidEnd,
    };

    int primaryKeyIndex() const override { return Id; }
    int autoValueIndex() const override { return Id; }
    QString tableName() const override { return QStringLiteral("itis_news"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int id READ getid WRITE setid)
    T_DEFINE_PROPERTY(int, id)
    Q_PROPERTY(QString news_type READ getnews_type WRITE setnews_type)
    T_DEFINE_PROPERTY(QString, news_type)
    Q_PROPERTY(QString news_type_sub READ getnews_type_sub WRITE setnews_type_sub)
    T_DEFINE_PROPERTY(QString, news_type_sub)
    Q_PROPERTY(QString news_title_de READ getnews_title_de WRITE setnews_title_de)
    T_DEFINE_PROPERTY(QString, news_title_de)
    Q_PROPERTY(QString news_title_en READ getnews_title_en WRITE setnews_title_en)
    T_DEFINE_PROPERTY(QString, news_title_en)
    Q_PROPERTY(QString news_desc_de READ getnews_desc_de WRITE setnews_desc_de)
    T_DEFINE_PROPERTY(QString, news_desc_de)
    Q_PROPERTY(QString news_desc_en READ getnews_desc_en WRITE setnews_desc_en)
    T_DEFINE_PROPERTY(QString, news_desc_en)
    Q_PROPERTY(QString news_text_de READ getnews_text_de WRITE setnews_text_de)
    T_DEFINE_PROPERTY(QString, news_text_de)
    Q_PROPERTY(QString news_text_en READ getnews_text_en WRITE setnews_text_en)
    T_DEFINE_PROPERTY(QString, news_text_en)
    Q_PROPERTY(QString news_prio READ getnews_prio WRITE setnews_prio)
    T_DEFINE_PROPERTY(QString, news_prio)
    Q_PROPERTY(QString author READ getauthor WRITE setauthor)
    T_DEFINE_PROPERTY(QString, author)
    Q_PROPERTY(QDateTime news_created READ getnews_created WRITE setnews_created)
    T_DEFINE_PROPERTY(QDateTime, news_created)
    Q_PROPERTY(QDateTime news_valid_start READ getnews_valid_start WRITE setnews_valid_start)
    T_DEFINE_PROPERTY(QDateTime, news_valid_start)
    Q_PROPERTY(QDateTime news_valid_end READ getnews_valid_end WRITE setnews_valid_end)
    T_DEFINE_PROPERTY(QDateTime, news_valid_end)
};

#endif // ITISNEWSOBJECT_H
