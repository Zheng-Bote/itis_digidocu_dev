#ifndef PCCLASSESCONTROLLER_H
#define PCCLASSESCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT PcClassesController : public ApplicationController
{
    Q_OBJECT
public:
    PcClassesController() : ApplicationController() {}

public slots:
    void index();
    void list_all();

    void show(const QString &id);
    void create();
    void save(const QString &id);
    void remove(const QString &id);

    void getPcClassesJson();
    void getObjPcJson();
};

#endif // PCCLASSESCONTROLLER_H
