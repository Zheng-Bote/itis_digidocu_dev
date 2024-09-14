#include "accountcontroller.h"

#include <TreeFrogModel>
#include "sqlobjects/itisuserobject.h"

#include "informationmailer.h"

#include "itisuser.h"
#include "itisgroups.h"
#include "accountcontroller.h"
#include "actionrights.h"

void AccountController::list_all()
{
    QString username = identityKeyOfLoginUser();
    ItisUser user = ItisUser::getByIdentityKey(username);
    if (!user.isNull())
    {
        auto conti = TActionController::name();
        auto con = TActionController::activeAction();
        QString uri = "/" + conti + "/" + con;

        if(ActionRights::isInGroups(user.groups(), "r", uri))
        {
            auto itisUserList = ItisUser::getAll();
            texport(itisUserList);
            render();
        }
        else
        {
            QString red_msg = "<img class=\"w3-red\" src=\"/Icons/exclamation-square.svg\">&nbsp; Not authorized to access the page or resource you were trying to reach.";
            texport(red_msg);
            render("index");
        }
    }
    else
    {
        redirect(QUrl("/account/form"));
    }
}

void AccountController::index()
{
    QString username = identityKeyOfLoginUser();
    ItisUser user = ItisUser::getByIdentityKey(username);
    if (!user.isNull())
    {
        render();
    }
    else
    {
        redirect(QUrl("/account/form"));
    }
}

void AccountController::show(const QString &id)
{
    QString username = identityKeyOfLoginUser();
    ItisUser user = ItisUser::getByIdentityKey(username);
    if (!user.isNull())
    {
        auto conti = TActionController::name();
        auto con = TActionController::activeAction();
        QString uri = "/" + conti + "/" + con;

        if(ActionRights::isInGroups(user.groups(), "r_d", uri))
        {
            auto user = ItisUser::get(id.toInt());
            texport(user);
            render();
        }
        else
        {
            QString red_msg = "<img class=\"w3-red\" src=\"/Icons/exclamation-square.svg\">&nbsp; Not authorized to access the page or resource you were trying to reach.";
            texport(red_msg);
            render("index");
        }
    }
    else
    {
        redirect(QUrl("/account/form"));
    }
}

void AccountController::userRegisterElectron()
{
    QJsonObject jsonObject;
    QJsonArray jsonArray;

    switch (httpRequest().method())
    {
    case Tf::Get:
        render();
        break;

    case Tf::Post:
    {
        QString username = httpRequest().formItemValue("username");
        QString firstname = httpRequest().formItemValue("firstname");
        QString surname = httpRequest().formItemValue("surname");
        QString email = httpRequest().formItemValue("email");
        QString company = httpRequest().formItemValue("company");
        QString userTimezone = httpRequest().formItemValue("userTimezone");
        QString groupname = httpRequest().formItemValue("groupname");
        QString groups = httpRequest().formItemValue("groups");
        QString pwd = httpRequest().formItemValue("password");
        QString newsletter = httpRequest().formItemValue("newsletter");
        QDateTime lastLogin(QDate(1970, 1, 1), QTime(1, 0, 0));
        QDateTime loginTime(QDate(1970, 1, 1), QTime(1, 0, 0));
        QDateTime loggedOut(QDate(1970, 1, 1), QTime(1, 0, 0));
        QDateTime pwdChangedTime = QDateTime::currentDateTime();

        QString pwdforce = httpRequest().formItemValue("pwdChangeForce");
        int pwdChangeForce = pwdforce.toInt();
        QString actv = httpRequest().formItemValue("active");
        int active = actv.toInt();

        auto model = ItisUser::create(username, firstname, surname, email, company, userTimezone, groupname, groups, pwd, lastLogin, loginTime, loggedOut, pwdChangedTime, pwdChangeForce, active);

        if (!model.isNull())
        {
            InformationMailer().regUserAdmInfo(model.username());
            //InformationMailer().crUserPwd(user.value("username").toString(), user.value("password").toString());
            ItisUser::setUserNewsCfg(username, newsletter);

            jsonObject["errMsg"] = "Created successfully";
            jsonObject["ERROR"] = "0";
            jsonArray.append(jsonObject);
            renderJson(jsonArray);
        } else
        {
            jsonObject["errMsg"] = "Failed to create.";
            jsonObject["ERROR"] = "1";
            jsonArray.append(jsonObject);
            renderJson(jsonArray);
        }
        break; }

    default:
        renderErrorResponse(Tf::NotFound);
        break;
    }
}

void AccountController::create()
{
    QString username = identityKeyOfLoginUser();
    ItisUser user = ItisUser::getByIdentityKey(username);
    if (!user.isNull())
    {
        auto conti = TActionController::name();
        auto con = TActionController::activeAction();
        QString uri = "/" + conti + "/" + con;

        if(ActionRights::isInGroups(user.groups(), "c", uri))
        {
            switch (httpRequest().method()) {
            case Tf::Get:
            {
                auto itisGroupsList = ItisGroups::getAll();
                texport(itisGroupsList);
                render();
                break;
            }

            case Tf::Post: {
                auto user = httpRequest().formItems("user");
                auto model = ItisUser::create(user);

                if (!model.isNull())
                {
                    InformationMailer().crUser(model.username());
                    InformationMailer().crUserPwd(user.value("username").toString(), user.value("password").toString());

                    QString notice = "Created successfully.";
                    tflash(notice);
                    redirect(urla("show", model.id()));
                } else {
                    QString error = "Failed to create.";
                    texport(error);
                    texport(user);
                    render();
                }
                break; }

            default:
                renderErrorResponse(Tf::NotFound);
                break;
            }
        }
        else
        {
            QString red_msg = "<img class=\"w3-red\" src=\"/Icons/exclamation-square.svg\">&nbsp; Not authorized to access the page or resource you were trying to reach.";
            texport(red_msg);
            render("index");
        }
    }
    else
    {
        redirect(QUrl("/account/form"));
    }
}

void AccountController::save(const QString &id)
{
    QString username = identityKeyOfLoginUser();
    ItisUser user = ItisUser::getByIdentityKey(username);
    if (!user.isNull())
    {
        auto conti = TActionController::name();
        auto con = TActionController::activeAction();
        QString uri = "/" + conti + "/" + con;

        if(ActionRights::isInGroups(user.groups(), "u", uri))
        {
            switch (httpRequest().method()) {
            case Tf::Get: {
                auto model = ItisUser::get(id.toInt());
                if (!model.isNull())
                {
                    auto itisGroupsList = ItisGroups::getAll();
                    texport(itisGroupsList);
                    auto user = model.toVariantMap();
                    texport(user);
                    render();
                }
                break; }

            case Tf::Post: {
                QString error;
                auto model = ItisUser::get(id.toInt());

                if (model.isNull()) {
                    error = "Original data not found. It may have been updated/removed by another transaction.";
                    tflash(error);
                    redirect(urla("save", id));
                    break;
                }

                auto user = httpRequest().formItems("user");
                model.setProperties(user);
                if (model.save()) {
                    QString notice = "Updated successfully.";
                    tflash(notice);
                    redirect(urla("show", model.id()));
                } else {
                    error = "Failed to update.";
                    texport(error);
                    texport(user);
                    render();
                }
                break; }

            default:
                renderErrorResponse(Tf::NotFound);
                break;
            }
        }
        else
        {
            QString red_msg = "<img class=\"w3-red\" src=\"/Icons/exclamation-square.svg\">&nbsp; Not authorized to access the page or resource you were trying to reach.";
            texport(red_msg);
            render("index");
        }
    }
    else
    {
        redirect(QUrl("/account/form"));
    }
}

void AccountController::remove(const QString &id)
{
    QString username = identityKeyOfLoginUser();
    ItisUser user = ItisUser::getByIdentityKey(username);
    if (!user.isNull())
    {
        auto conti = TActionController::name();
        auto con = TActionController::activeAction();
        QString uri = "/" + conti + "/" + con;

        if(ActionRights::isInGroups(user.groups(), "d", uri))
        {
            if (httpRequest().method() != Tf::Post) {
                renderErrorResponse(Tf::NotFound);
                return;
            }

            auto user = ItisUser::get(id.toInt());
            user.remove();
            redirect(urla("index"));
        }
        else
        {
            QString red_msg = "<img class=\"w3-red\" src=\"/Icons/exclamation-square.svg\">&nbsp; Not authorized to access the page or resource you were trying to reach.";
            texport(red_msg);
            render("index");
        }
    }
    else
    {
        redirect(QUrl("/account/form"));
    }
}

void AccountController::setUserPwd()
{
    QString username = identityKeyOfLoginUser();
    ItisUser user = ItisUser::getByIdentityKey(username);
    if (!user.isNull())
    {
        QString pwd = httpRequest().formItemValue("pwd");
        InformationMailer().infoUserPwd(user.username());
        renderJson( ItisUser::setUserPwd(user.username(), pwd) );
    }
    else
    {
        redirect(QUrl("/account/form"));
    }
}

void AccountController::userPwd()
{
    QString username = identityKeyOfLoginUser();
    ItisUser user = ItisUser::getByIdentityKey(username);
    if (!user.isNull())
    {
        QString uFname = user.firstname();
        texport(uFname);

        QString uSname = user.surname().toUpper();
        texport(uSname);

        render("userpwd");
    }
    else
    {
        redirect(QUrl("/account/form"));
    }
}

void AccountController::userPwdElectron()
{
    QString username = identityKeyOfLoginUser();
    ItisUser user = ItisUser::getByIdentityKey(username);
    if (!user.isNull())
    {
        QString uFname = user.firstname();
        texport(uFname);

        QString uSname = user.surname().toUpper();
        texport(uSname);

        render("userpwdElectron");
    }
    else
    {
        redirect(QUrl("/account/formElectron"));
    }
}

void AccountController::setUserNewsCfg()
{
    QString username = identityKeyOfLoginUser();
    ItisUser user = ItisUser::getByIdentityKey(username);
    if (!user.isNull())
    {
        QString username = httpRequest().formItemValue("username");
        QString newsletter = httpRequest().formItemValue("newsletter");

        //ItisUser::setUserNewsCfg(username, newsletter);
        renderJson( ItisUser::setUserNewsCfg(username, newsletter) );
    }
    else
    {
        redirect(QUrl("/account/formElectron"));
    }
}

void AccountController::userHome()
{
    QString username = identityKeyOfLoginUser();
    ItisUser user = ItisUser::getByIdentityKey(username);
    if (!user.isNull())
    {

        QString username = user.username();
        texport(username);

        QString firstname = user.firstname();
        texport(firstname);

        QString surname = user.surname();
        texport(surname);

        QString email = user.email();
        texport(email);

        QString company = user.company();
        texport(company);

        QString lastLogin = user.lastLogin().toString();
        texport(lastLogin);

        QString lastLogout = user.loggedOut().toString();
        texport(lastLogout);

        QString lastPwdChangeTime = user.pwdChangedTime().toString();
        texport(lastPwdChangeTime);

        QString usertimezone = user.userTimezone();
        texport(usertimezone);

        QString groupname = user.groupname();
        texport(groupname);

        QString groups = user.groups();
        texport(groups);

        QString newsletter = ItisUser::getUserNewsCfg( user.username() );
        texport(newsletter);

        quint64 difference = qAbs(user.pwdChangedTime().date().daysTo(QDateTime::currentDateTime().date()));

        QString pwdToChangeIn;
        int timediff = static_cast<int>(difference);

        if(timediff >= 30)
        {
            QString red_msg = "Ihr Passwort ist abgelaufen. Bitte ändern Sie aus Sicherheitsgründen Ihr Passwort!";
            texport(red_msg);
            render("userpwd");
        }
        else if(timediff > 20 && timediff < 30)
        {
            pwdToChangeIn = "Passwort-Änderung erforderlich in " + QString::number(30 - timediff) + " Tagen";
        }
        else
        {
            pwdToChangeIn = "Passwort-Änderung erforderlich in " + QString::number(30 - timediff) + " Tagen";
        }
        texport(pwdToChangeIn);

        render("userhome");
    }
    else
    {
        redirect(QUrl("/account/form"));
    }
}

void AccountController::userHomeElectron()
{
    QString username = identityKeyOfLoginUser();
    ItisUser user = ItisUser::getByIdentityKey(username);
    if (!user.isNull())
    {

        QString username = user.username();
        texport(username);

        QString firstname = user.firstname();
        texport(firstname);

        QString surname = user.surname();
        texport(surname);

        QString email = user.email();
        texport(email);

        QString company = user.company();
        texport(company);

        QString lastLogin = user.lastLogin().toString();
        texport(lastLogin);

        QString lastLogout = user.loggedOut().toString();
        texport(lastLogout);

        QString lastPwdChangeTime = user.pwdChangedTime().toString();
        texport(lastPwdChangeTime);

        QString usertimezone = user.userTimezone();
        texport(usertimezone);

        QString groupname = user.groupname();
        texport(groupname);

        QString groups = user.groups();
        texport(groups);

        QString newsletter = ItisUser::getUserNewsCfg( user.username() );
        texport(newsletter);

        quint64 difference = qAbs(user.pwdChangedTime().date().daysTo(QDateTime::currentDateTime().date()));

        QString pwdToChangeIn;
        int timediff = static_cast<int>(difference);

        if(timediff >= 30)
        {
            QString error = "Passwort-Änderung erforderlich! " + QString::number(timediff - 30);
            texport(error);
            render("userpwdElectron");
        }
        else if(timediff > 20 && timediff < 30)
        {
            pwdToChangeIn = "Passwort-Änderung erforderlich in " + QString::number(30 - timediff) + " Tagen";
        }
        else
        {
            pwdToChangeIn = "Passwort-Änderung erforderlich in " + QString::number(30 - timediff) + " Tagen";
        }
        texport(pwdToChangeIn);

        render("userhomeElectron");
    }
    else
    {
        redirect(QUrl("/account/formElectron"));
    }
}

/*!
 * \brief AccountController::form
 * Login Mask
*/
void AccountController::form()
{
    userLogout();  // forcibly logged out
    render();      // shows form view
}

void AccountController::formElectron()
{
    userLogout();  // forcibly logged out
    render();      // shows form view
}

void AccountController::login()
{
    QString username = httpRequest().formItemValue("username");
    QString s = httpRequest().formItemValue("password");

    QString error;
    QByteArray password = QCryptographicHash::hash(s.toLocal8Bit(), QCryptographicHash::Sha256);
    ItisUser user = ItisUser::authenticate(username, password);

    if (!user.isNull())
    {
        if(user.active() == 0)
        {
            error = "Your account is disabled, please contact your Admin.";
            texport(error);
            render("form");
        }
        userLogin(&user);
        session().insert("identityKey", username);
        user.setLoginTime(QDateTime::currentDateTime());

        if(user.pwdChangeForce() == 1)
        {
            error = "Bitte ändern Sie aus Sicherheitsgründen Ihr Passwort.";
            texport(error);
            render("userpwd");
        }

        redirect(QUrl("/account/userHome"));
    }
    else
    {
        error = "Login failed";
        texport(error);
        render("form");
    }
}

void AccountController::loginElectron()
{
    QString username = httpRequest().formItemValue("username");
    QString s = httpRequest().formItemValue("password");

    QByteArray password = QCryptographicHash::hash(s.toLocal8Bit(), QCryptographicHash::Sha256);

    ItisUser user = ItisUser::authenticate(username, password);
    if (!user.isNull())
    {
        if(user.active() == 0)
        {
            QString red_msg = "Your account is disabled, please contact your Admin.";
            texport(red_msg);
            render("formElectron");
        }
        userLogin(&user);
        session().insert("identityKey", username);
        user.setLoginTime(QDateTime::currentDateTime());

        if(user.pwdChangeForce() == 1)
        {
            QString red_msg = "Bitte ändern Sie aus Sicherheitsgründen Ihr Passwort.";
            texport(red_msg);
            render("userpwdElectron");
        }

        redirect(QUrl("/account/userHomeElectron"));
    }
    else
    {
        QString red_msg = "Login failed";
        texport(red_msg);
        render("formElectron");
    }
}

void AccountController::logout()
{
    QString username = identityKeyOfLoginUser();
    ItisUser user = ItisUser::getByIdentityKey(username);
    user.setLoggedOut(QDateTime::currentDateTime());
    userLogout();

    QString green_msg = "live long and prosper &#128406;";
    texport(green_msg);

    render("form");
}

void AccountController::logoutElectron()
{
    QString username = identityKeyOfLoginUser();
    ItisUser user = ItisUser::getByIdentityKey(username);
    user.setLoggedOut(QDateTime::currentDateTime());
    userLogout();

    QString green_msg = "Sie wurden vom System abgemeldet";
    texport(green_msg);
    render("formElectron");
}

// Don't remove below this line
T_DEFINE_CONTROLLER(AccountController)
