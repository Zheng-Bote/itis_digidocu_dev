#ifndef ITISGROUPSCONTROLLER_H
#define ITISGROUPSCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT ItisGroupsController : public ApplicationController
{
    Q_OBJECT
public:
    ItisGroupsController() : ApplicationController() {}

public slots:
    void index();
    void list_all();

    void show(const QString &id);
    void create();
    void save(const QString &id);
    void remove(const QString &id);
};

#endif // ITISGROUPSCONTROLLER_H
