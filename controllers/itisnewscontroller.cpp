#include "itisnewscontroller.h"
#include "itisnews.h"

#include "itisuser.h"
#include "itisgroups.h"
#include "accountcontroller.h"
#include "actionrights.h"

void ItisNewsController::list_all()
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
            auto itisNewsList = ItisNews::getAll();
            texport(itisNewsList);
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

void ItisNewsController::index()
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

void ItisNewsController::indexElectron()
{
    render();
}

void ItisNewsController::show(const QString &id)
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
            auto itisNews = ItisNews::get(id.toInt());
            texport(itisNews);
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

void ItisNewsController::create()
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
                QString usermail = user.email();
                texport(usermail);
                render();
                break;
            }

            case Tf::Post: {
                auto itisNews = httpRequest().formItems("itisNews");
                auto model = ItisNews::create(itisNews);

                if (!model.isNull()) {
                    QString notice = "Created successfully.";
                    tflash(notice);
                    redirect(urla("show", model.id()));
                } else {
                    QString error = "Failed to create.";
                    texport(error);
                    texport(itisNews);
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

void ItisNewsController::save(const QString &id)
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
                auto model = ItisNews::get(id.toInt());
                if (!model.isNull()) {
                    auto itisNews = model.toVariantMap();
                    texport(itisNews);
                    render();
                }
                break; }

            case Tf::Post: {
                QString error;
                auto model = ItisNews::get(id.toInt());

                if (model.isNull()) {
                    error = "Original data not found. It may have been updated/removed by another transaction.";
                    tflash(error);
                    redirect(urla("save", id));
                    break;
                }

                auto itisNews = httpRequest().formItems("itisNews");
                model.setProperties(itisNews);
                if (model.save()) {
                    QString notice = "Updated successfully.";
                    tflash(notice);
                    redirect(urla("show", model.id()));
                } else {
                    error = "Failed to update.";
                    texport(error);
                    texport(itisNews);
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

void ItisNewsController::remove(const QString &id)
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

            auto itisNews = ItisNews::get(id.toInt());
            itisNews.remove();
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
T_DEFINE_CONTROLLER(ItisNewsController)
