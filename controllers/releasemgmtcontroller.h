#ifndef RELEASEMGMTCONTROLLER_H
#define RELEASEMGMTCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT ReleaseMgmtController : public ApplicationController
{
    Q_OBJECT
public:
    ReleaseMgmtController() : ApplicationController() {}

public slots:
    void index();
    void list_all();

    void list_allAnnexCi();
    void listAllAnnexCi();
    void list_allAnnexCd();
    void listAllAnnexCd();

    void list_allStdCi();
    void listAllStdCi();
    void list_allStdCd();
    void listAllStdCd();

    void index_ciannex();
    void getAnnexRelease();

    void showCdAnnex();
    void printCdAnnex();

    void getAnnexList();
    void getAnnexSpec();

    void show(const QString &id);
    void create();
    void save(const QString &id);
    void ci_update();

    void saveAnnex(const QString &id);

    void remove(const QString &id);

    void getAnnexToc();

    void getAnnexCiPDFs();
    void getAnnexCdPDFs();

    void getStdCiPDFs();
    void getStdCdPDFs();

    void list_pdf();
    void fileRemove();

    // Test
    void writeFile();

};

#endif // RELEASEMGMTCONTROLLER_H
