#ifndef APPVARSCONTROLLER_H
#define APPVARSCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT AppVarsController : public ApplicationController
{
    Q_OBJECT
public:
    AppVarsController() : ApplicationController() {}

public slots:
    void index();
    void list_all();

    void show(const QString &id);
    void create();
    void save(const QString &id);
    void remove(const QString &id);
};

#endif // APPVARSCONTROLLER_H
