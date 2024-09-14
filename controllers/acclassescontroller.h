#ifndef ACCLASSESCONTROLLER_H
#define ACCLASSESCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT AcClassesController : public ApplicationController
{
    Q_OBJECT
public:
    AcClassesController() : ApplicationController() {}

public slots:
    void index();
    void list_all();

    void show(const QString &id);
    void create();
    void save(const QString &id);
    void remove(const QString &id);

    void getAcClassesJson();
    void getObjAcJson();
};

#endif // ACCLASSESCONTROLLER_H
