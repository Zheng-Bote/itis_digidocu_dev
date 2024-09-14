#ifndef ANNEXDATACOMMENTSCONTROLLER_H
#define ANNEXDATACOMMENTSCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT AnnexDataCommentsController : public ApplicationController
{
    Q_OBJECT
public:
    AnnexDataCommentsController() : ApplicationController() {}

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

#endif // ANNEXDATACOMMENTSCONTROLLER_H
