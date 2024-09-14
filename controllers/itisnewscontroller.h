#ifndef ITISNEWSCONTROLLER_H
#define ITISNEWSCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT ItisNewsController : public ApplicationController
{
    Q_OBJECT
public:
    ItisNewsController() : ApplicationController() {}

public slots:
    void index();
    void indexElectron();
    void list_all();

    void show(const QString &id);
    void create();
    void save(const QString &id);
    void remove(const QString &id);
};

#endif // ITISNEWSCONTROLLER_H
