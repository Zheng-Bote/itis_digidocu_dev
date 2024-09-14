#include "admincontroller.h"

#include "itisuser.h"
#include "itisgroups.h"
#include "accountcontroller.h"
#include "actionrights.h"

void AdminController::showGallery()
{

    QJsonObject jsonObject;
    QJsonArray jsonArray;
    // PRO
    QString pathToImg = "/webapp/html/itis/Img/Annexspecs";
    // DEV QString pathToImg = "/webapp_dez/itis_app/public/images";
    QDir directory(pathToImg);
    QStringList images = directory.entryList(QStringList() << "*.jpg" << "*.jpeg" << "*.png" << "*.bmp" << "*.gif",QDir::Files);

    foreach(QString filename, images)
    {
       QFileInfo info(pathToImg + "/" + filename);
       jsonObject["size"] = info.size() / 1024;
       // PROD
       jsonObject["img"] = "/Annexspecs/" + filename;
       // DEV jsonObject["img"] = "/images/" + filename;
       jsonObject["name"] = filename;
       jsonArray.append(jsonObject);
    }

    pathToImg = "/webapp/html/itis/Img/Objspecs";
    QDir direct(pathToImg);
    QStringList imag = direct.entryList(QStringList() << "*.jpg" << "*.jpeg" << "*.png" << "*.bmp" << "*.gif",QDir::Files);

    foreach(QString filename, imag)
    {
       QFileInfo info(pathToImg + "/" + filename);
       jsonObject["size"] = info.size() / 1024;
       jsonObject["img"] = "/Objspecs/" + filename;
       jsonObject["name"] = filename;
       jsonArray.append(jsonObject);
    }

    //renderJson(jsonArray);
    texport(jsonArray);

    render();
}

void AdminController::index()
{
    QString username = identityKeyOfLoginUser();
    ItisUser user = ItisUser::getByIdentityKey(username);
    if (!user.isNull())
    {
        QString uFname = user.firstname();
        texport(uFname);

        QString lastLogin = user.lastLogin().toString();
        texport(lastLogin);

        QString lastLogout = user.loggedOut().toString();
        texport(lastLogout);

        QString lastPwdChangeTime = user.pwdChangedTime().toString();
        texport(lastPwdChangeTime);

        render("index");
    }
    else
    {
        redirect(QUrl("/account/form"));
    }
}

// Don't remove below this line
T_DEFINE_CONTROLLER(AdminController)
