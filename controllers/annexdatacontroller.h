#ifndef ANNEXDATACONTROLLER_H
#define ANNEXDATACONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT AnnexDataController : public ApplicationController
{
    Q_OBJECT
public:
    AnnexDataController() : ApplicationController() {}

public slots:
    void index();
    void list_all();

    void show(const QString &id);
    void create();
    void save(const QString &id);
    void remove(const QString &id);

    void getStatistics();
    void getHighestLfdnr(const QString &category);
    void getImages();
    void checkLfdnrCat();
    void getCheckLfdnrCat();

    void listAnnex();
    void showAnnex();
    void showCiAnnex();
    void printCiAnnex();
    void showAnnexElectron();
    void listWaste();
    void getExistCountries();

    void editor_add();
    void editor_upd(const QString &id);
    void chkLfdnrEditor();
    void setAnnexData();
    void updAnnexData();
    void upPrelease();
    void doPreRelease();
    void upReleased();
    void doReleased();

    void doRecover(const QString &id);
    void showWaste(const QString &id);
    void removeWaste(const QString &id);

    void uploadImg();

    void getAnnexList();
    void getAnnexSpec();
    void getAnnexToc();

    void writeAnnex();
};

#endif // ANNEXDATACONTROLLER_H
