#ifndef LENKINFOCONTROLLER_H
#define LENKINFOCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT LenkinfoController : public ApplicationController
{
    Q_OBJECT
public:
    LenkinfoController() : ApplicationController() {}

public slots:
    void index();
    void list_all();

    void show(const QString &id);
    void create();
    void create_silent();
    void save(const QString &id);
    void remove(const QString &id);

    void getJson();
};

#endif // LENKINFOCONTROLLER_H
