#include "appvarscontroller.h"
#include "appvars.h"

#include "itisuser.h"
#include "itisgroups.h"
#include "accountcontroller.h"
#include "actionrights.h"

void AppVarsController::list_all()
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
            auto appVarsList = AppVars::getAll();
            texport(appVarsList);
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

void AppVarsController::index()
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

void AppVarsController::show(const QString &id)
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
            auto appVars = AppVars::get(id.toInt());
            texport(appVars);
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

void AppVarsController::create()
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
            switch (httpRequest().method())
            {
            case Tf::Get:
                render();
                break;

            case Tf::Post: {
                auto appVars = httpRequest().formItems("appVars");
                auto model = AppVars::create(appVars);

                if (!model.isNull()) {
                    QString notice = "Created successfully.";
                    tflash(notice);
                    redirect(urla("show", model.id()));
                } else {
                    QString error = "Failed to create.";
                    texport(error);
                    texport(appVars);
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

void AppVarsController::save(const QString &id)
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
                auto model = AppVars::get(id.toInt());
                if (!model.isNull()) {
                    auto appVars = model.toVariantMap();
                    texport(appVars);
                    render();
                }
                break; }

            case Tf::Post: {
                QString error;
                auto model = AppVars::get(id.toInt());

                if (model.isNull()) {
                    error = "Original data not found. It may have been updated/removed by another transaction.";
                    tflash(error);
                    redirect(urla("save", id));
                    break;
                }

                auto appVars = httpRequest().formItems("appVars");
                model.setProperties(appVars);
                if (model.save()) {
                    QString notice = "Updated successfully.";
                    tflash(notice);
                    redirect(urla("show", model.id()));
                } else {
                    error = "Failed to update.";
                    texport(error);
                    texport(appVars);
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

void AppVarsController::remove(const QString &id)
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
            if (httpRequest().method() != Tf::Post)
            {
                renderErrorResponse(Tf::NotFound);
                return;
            }

            auto appVars = AppVars::get(id.toInt());
            appVars.remove();
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


// Don't remove below this line
T_DEFINE_CONTROLLER(AppVarsController)
