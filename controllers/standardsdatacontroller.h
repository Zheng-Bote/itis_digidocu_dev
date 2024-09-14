#ifndef STANDARDSDATACONTROLLER_H
#define STANDARDSDATACONTROLLER_H

#include "applicationcontroller.h"

class T_CONTROLLER_EXPORT StandardsDataController : public ApplicationController
{
    Q_OBJECT
public:
    StandardsDataController() : ApplicationController() {}

public slots:
    void index();
    void list_all();

    void getStatistics();
    void getHighestLfdnr(const QString &category);
    void getImages();
    void checkLfdnrCat();
    void getCheckLfdnrCat();

    void listStd();
    void showStd();
    void showCiStd();
    void showStdElectron();
    void listWaste();
    void getExistCountries();

    void show(const QString &id);
    void create();
    void save(const QString &id);
    void remove(const QString &id);

    void editor_add();
    void editor_upd(const QString &id);
    void chkLfdnrEditor();
    void setStdData();
    void updStdData();
    void upPrelease();
    void doPreRelease();
    void upReleased();

    void doRecover(const QString &id);
    void showWaste(const QString &id);
    void removeWaste(const QString &id);

    void uploadImg();

    void getStdList();
    void getStdSpec();
    void getStdToc();
};

#endif // STANDARDSDATACONTROLLER_H
