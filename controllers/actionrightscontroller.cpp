#include "actionrightscontroller.h"
#include "actionrights.h"

#include "itisuser.h"
#include "itisgroups.h"
#include "accountcontroller.h"
#include "actionrights.h"

void ActionRightsController::getRoutes()
{
    QString username = identityKeyOfLoginUser();
    ItisUser user = ItisUser::getByIdentityKey(username);
    if (!user.isNull())
    {
        auto conti = TActionController::name();
        auto con = TActionController::activeAction();
        QString uri = "/" + conti + "/" + con;

        if(ActionRights::isInGroups(user.groups(), "crud", uri))
        {
            //auto conti = TActionController::name(); auto con = TActionController::activeAction();

            QJsonObject jsonObject;
            QJsonArray jsonArray;

            QProcess p;
            QString program = "treefrog";
            QStringList arguments;
            arguments << "--show-routes";

            p.start(program,arguments);
            p.waitForStarted();
            p.waitForReadyRead();
            p.waitForFinished();
            QString line= p.readAllStandardOutput();

            QStringList list;
            list = line.split(QRegExp("match"));

            QRegularExpression re(".*Available controllers:.*");
            QRegularExpression re1("(\\s+)([\\/|a-z|A-Z|_]+)(/:param|)(\\s+->)");
            for (int i = 0; i < list.size(); ++i)
            {
                QRegularExpressionMatch match = re.match(list[i]);
                if (! match.hasMatch())
                {
                    //jsonObject["output"] = list[i];
                    //jsonArray.append(jsonObject);

                    match = re1.match(list[i]);
                    if (match.hasMatch())
                    {
                        //jsonObject["output"] = list[i];
                        jsonObject["output"] = match.captured(2);
                        jsonArray.append(jsonObject);
                    }
                }
            }

            QStringList contis = TActionController::availableControllers();
            for (int i = 0; i < contis.size(); ++i)
            {
                jsonObject["controller"] = contis[i];
                jsonArray.append(jsonObject);
            }

            renderJson(jsonArray);
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

void ActionRightsController::list_all()
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
            auto actionRightsList = ActionRights::getAll();
            texport(actionRightsList);
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

void ActionRightsController::index()
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

void ActionRightsController::show(const QString &id)
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
            auto actionRights = ActionRights::get(id.toInt());
            texport(actionRights);
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

void ActionRightsController::create()
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
                auto actionRights = httpRequest().formItems("actionRights");
                auto model = ActionRights::create(actionRights);

                if (!model.isNull()) {
                    QString notice = "Created successfully.";
                    tflash(notice);
                    redirect(urla("show", model.id()));
                } else {
                    QString error = "Failed to create.";
                    texport(error);
                    texport(actionRights);
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

void ActionRightsController::save(const QString &id)
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
                auto model = ActionRights::get(id.toInt());
                if (!model.isNull()) {
                    auto actionRights = model.toVariantMap();
                    texport(actionRights);

                    auto itisGroupsList = ItisGroups::getAll();
                    texport(itisGroupsList);

                    render();
                }
                break; }

            case Tf::Post: {
                QString error;
                auto model = ActionRights::get(id.toInt());

                if (model.isNull()) {
                    error = "Original data not found. It may have been updated/removed by another transaction.";
                    tflash(error);
                    redirect(urla("save", id));
                    break;
                }

                auto actionRights = httpRequest().formItems("actionRights");
                model.setProperties(actionRights);
                if (model.save()) {
                    QString notice = "Updated successfully.";
                    tflash(notice);
                    redirect(urla("show", model.id()));
                } else {
                    error = "Failed to update.";
                    texport(error);
                    texport(actionRights);
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

void ActionRightsController::remove(const QString &id)
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

            auto actionRights = ActionRights::get(id.toInt());
            actionRights.remove();
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
T_DEFINE_CONTROLLER(ActionRightsController)
