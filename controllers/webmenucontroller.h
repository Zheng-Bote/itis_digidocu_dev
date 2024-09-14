#ifndef WEBMENUCONTROLLER_H
#define WEBMENUCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT WebmenuController : public ApplicationController
{
    Q_OBJECT
public:
    WebmenuController() : ApplicationController() {}

public slots:
    void index();
    void show(const QString &id);
    void create();
    void save(const QString &id);
    void remove(const QString &id);

    void list_all();
    void getMnu();
    void getMnuSub();
};

#endif // WEBMENUCONTROLLER_H
