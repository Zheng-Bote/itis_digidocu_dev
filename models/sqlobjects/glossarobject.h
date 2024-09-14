#ifndef GLOSSAROBJECT_H
#define GLOSSAROBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT GlossarObject : public TSqlObject, public QSharedData
{
public:
    int id {0};
    QString acronym;
    QString term_de;
    QString term_en;
    QString desc_de;
    QString desc_en;
    int sort {0};
    int active {0};

    enum PropertyIndex {
        Id = 0,
        Acronym,
        TermDe,
        TermEn,
        DescDe,
        DescEn,
        Sort,
        Active,
    };

    int primaryKeyIndex() const override { return Id; }
    int autoValueIndex() const override { return Id; }
    QString tableName() const override { return QStringLiteral("glossar"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int id READ getid WRITE setid)
    T_DEFINE_PROPERTY(int, id)
    Q_PROPERTY(QString acronym READ getacronym WRITE setacronym)
    T_DEFINE_PROPERTY(QString, acronym)
    Q_PROPERTY(QString term_de READ getterm_de WRITE setterm_de)
    T_DEFINE_PROPERTY(QString, term_de)
    Q_PROPERTY(QString term_en READ getterm_en WRITE setterm_en)
    T_DEFINE_PROPERTY(QString, term_en)
    Q_PROPERTY(QString desc_de READ getdesc_de WRITE setdesc_de)
    T_DEFINE_PROPERTY(QString, desc_de)
    Q_PROPERTY(QString desc_en READ getdesc_en WRITE setdesc_en)
    T_DEFINE_PROPERTY(QString, desc_en)
    Q_PROPERTY(int sort READ getsort WRITE setsort)
    T_DEFINE_PROPERTY(int, sort)
    Q_PROPERTY(int active READ getactive WRITE setactive)
    T_DEFINE_PROPERTY(int, active)
};

#endif // GLOSSAROBJECT_H
