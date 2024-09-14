#ifndef ADMINCONTROLLER_H
#define ADMINCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT AdminController : public ApplicationController
{
    Q_OBJECT
public:
    AdminController() : ApplicationController() { }

public slots:
    void index();

    void showGallery();
};

#endif // ADMINCONTROLLER_H
