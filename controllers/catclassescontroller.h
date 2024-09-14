#ifndef CATCLASSESCONTROLLER_H
#define CATCLASSESCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT CatClassesController : public ApplicationController
{
    Q_OBJECT
public:
    CatClassesController() : ApplicationController() {}

public slots:
    void index();
    void list_all();

    void show(const QString &id);
    void create();
    void save(const QString &id);
    void remove(const QString &id);

    void getAllJson();
    void getAllJson(const QString &active, const QString &class_type);
    void getAllJson(const QString &active, const QString &class_type, const QString strGroups);
};

#endif // CATCLASSESCONTROLLER_H
