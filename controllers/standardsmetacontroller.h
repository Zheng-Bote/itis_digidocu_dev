#ifndef STANDARDSMETACONTROLLER_H
#define STANDARDSMETACONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT StandardsMetaController : public ApplicationController
{
    Q_OBJECT
public:
    StandardsMetaController() : ApplicationController() {}

public slots:
    void index();
    void show(const QString &id);
    void getBySpecDataId(const QString &spec_data_id);
    void create();
    void save(const QString &id);
    void remove(const QString &id);
};

#endif // STANDARDSMETACONTROLLER_H
