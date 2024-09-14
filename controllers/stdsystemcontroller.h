#ifndef STDSYSTEMCONTROLLER_H
#define STDSYSTEMCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT StdSystemController : public ApplicationController
{
    Q_OBJECT
public:
    StdSystemController() : ApplicationController() {}

public slots:
    void index();
    void show(const QString &id);
    void create();
    void save(const QString &id);
    void remove(const QString &id);

    void list_all();
    void imprint();
    void license();

    void getAllJson(const QString &active, const QString &std_type);
};

#endif // STDSYSTEMCONTROLLER_H
