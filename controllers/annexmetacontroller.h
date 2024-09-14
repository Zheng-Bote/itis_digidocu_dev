#ifndef ANNEXMETACONTROLLER_H
#define ANNEXMETACONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT AnnexMetaController : public ApplicationController
{
    Q_OBJECT
public:
    AnnexMetaController() : ApplicationController() {}

public slots:
    void index();
    void show(const QString &id);
    void create();
    void save(const QString &id);
    void remove(const QString &id);

    void getBySpecDataId(const QString &spec_data_id);
};

#endif // ANNEXMETACONTROLLER_H
