#ifndef PORTALADMINCONTROLLER_H
#define PORTALADMINCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT PortalAdminController : public ApplicationController
{
    Q_OBJECT
public:
    PortalAdminController() : ApplicationController() { }

public slots:
    void index();
};

#endif // PORTALADMINCONTROLLER_H
