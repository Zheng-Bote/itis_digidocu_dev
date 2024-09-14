#ifndef ACTIONRIGHTSCONTROLLER_H
#define ACTIONRIGHTSCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT ActionRightsController : public ApplicationController
{
    Q_OBJECT
public:
    ActionRightsController() : ApplicationController() {}

public slots:
    void index();
    void list_all();

    void getRoutes();

    void show(const QString &id);
    void create();
    void save(const QString &id);
    void remove(const QString &id);
};

#endif // ACTIONRIGHTSCONTROLLER_H
