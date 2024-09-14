#ifndef STANDARDSDATACOMMENTSCONTROLLER_H
#define STANDARDSDATACOMMENTSCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT StandardsDataCommentsController : public ApplicationController
{
    Q_OBJECT
public:
    StandardsDataCommentsController() : ApplicationController() {}

public slots:
    void index();
    void list_all();

    void show(const QString &id);
    void create();
    void createComment();
    void save(const QString &id);
    void remove(const QString &id);

    void getSpecComments(const QString &spec_id);

};

#endif // STANDARDSDATACOMMENTSCONTROLLER_H
