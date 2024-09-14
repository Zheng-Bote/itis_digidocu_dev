#ifndef ACCOUNTCONTROLLER_H
#define ACCOUNTCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT AccountController : public ApplicationController
{
    Q_OBJECT
public:
    AccountController() : ApplicationController() { }

public slots:
    void index();
    void list_all();

    void form();
    void login();
    void logout();
    void logoutElectron();

    void formElectron();
    void loginElectron();
    void userHomeElectron();
    void userPwdElectron();

    void userHome();
    void userPwd();
    void setUserPwd();
    void setUserNewsCfg();

    void show(const QString &id);
    void create();
    void userRegisterElectron();
    void save(const QString &id);
    void remove(const QString &id);
};

#endif // ACCOUNTCONTROLLER_H
