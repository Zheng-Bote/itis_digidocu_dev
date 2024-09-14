#ifndef OBJECTSCONTROLLER_H
#define OBJECTSCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT ObjectsController : public ApplicationController
{
    Q_OBJECT
public:
    ObjectsController() : ApplicationController() {}

public slots:
    void index();
    void list_all();

    void getAllJson();
    void getAllJson(const QString &active);
    void getAllJson(const QString &active, QString strGroups);

    void show(const QString &id);
    void create();
    void save(const QString &id);
    void remove(const QString &id);
};

#endif // OBJECTSCONTROLLER_H
