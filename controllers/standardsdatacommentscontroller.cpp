#include "standardsdatacommentscontroller.h"
#include "standardsdatacomments.h"

#include "itisuser.h"
#include "itisgroups.h"
#include "accountcontroller.h"
#include "actionrights.h"

void StandardsDataCommentsController::getSpecComments(const QString &spec_id)
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
            renderJson( StandardsDataComments::getSpecComments( spec_id.toInt() ) );
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

void StandardsDataCommentsController::list_all()
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
            auto standardsDataCommentsList = StandardsDataComments::getAll();
            texport(standardsDataCommentsList);
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

void StandardsDataCommentsController::index()
{
    QString username = identityKeyOfLoginUser();
    ItisUser user = ItisUser::getByIdentityKey(username);
    if (!user.isNull())
    {
        auto statistik = StandardsDataComments::getStatistics();

        QString count_id = statistik["count_id"];
        texport(count_id);
        QString count_users = statistik["count_users"];
        texport(count_users);

        render();
    }
    else
    {
        redirect(QUrl("/account/form"));
    }
}

void StandardsDataCommentsController::show(const QString &id)
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
            auto standardsDataComments = StandardsDataComments::get(id.toInt());
            texport(standardsDataComments);
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

void StandardsDataCommentsController::createComment()
{
    QString username = identityKeyOfLoginUser();
    ItisUser user = ItisUser::getByIdentityKey(username);
    if (!user.isNull())
    {
        QString spec_id = httpRequest().formItemValue("spec_id");
        QString spec_title = httpRequest().formItemValue("spec_title");
        QString spec_version = httpRequest().formItemValue("spec_version");
        QString user_comment = httpRequest().formItemValue("user_comment");

        renderJson( StandardsDataComments::createComment(spec_id.toInt(), spec_title, spec_version, user_comment, user.username()) );
    }
    else
    {
        redirect(QUrl("/account/form"));
    }
}

void StandardsDataCommentsController::create()
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
                render();
                break;

            case Tf::Post: {
                auto standardsDataComments = httpRequest().formItems("standardsDataComments");
                auto model = StandardsDataComments::create(standardsDataComments);

                if (!model.isNull()) {
                    QString notice = "Created successfully.";
                    tflash(notice);
                    redirect(urla("show", model.id()));
                } else {
                    QString error = "Failed to create.";
                    texport(error);
                    texport(standardsDataComments);
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

void StandardsDataCommentsController::save(const QString &id)
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
                auto model = StandardsDataComments::get(id.toInt());
                if (!model.isNull()) {
                    auto standardsDataComments = model.toVariantMap();
                    texport(standardsDataComments);
                    render();
                }
                break; }

            case Tf::Post: {
                QString error;
                auto model = StandardsDataComments::get(id.toInt());

                if (model.isNull()) {
                    error = "Original data not found. It may have been updated/removed by another transaction.";
                    tflash(error);
                    redirect(urla("save", id));
                    break;
                }

                auto standardsDataComments = httpRequest().formItems("standardsDataComments");
                model.setProperties(standardsDataComments);
                if (model.save()) {
                    QString notice = "Updated successfully.";
                    tflash(notice);
                    redirect(urla("show", model.id()));
                } else {
                    error = "Failed to update.";
                    texport(error);
                    texport(standardsDataComments);
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

void StandardsDataCommentsController::remove(const QString &id)
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

            auto standardsDataComments = StandardsDataComments::get(id.toInt());
            standardsDataComments.remove();
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
T_DEFINE_CONTROLLER(StandardsDataCommentsController)
