#ifndef GLOSSARCONTROLLER_H
#define GLOSSARCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT GlossarController : public ApplicationController
{
    Q_OBJECT
public:
    GlossarController() : ApplicationController() {}

public slots:
    void index();
    void list_all();
    void list_allElectron();

    void getAllJson();
    void getAllJsonSorted();

    void show(const QString &id);
    void create();
    void save(const QString &id);
    void remove(const QString &id);
};

#endif // GLOSSARCONTROLLER_H
