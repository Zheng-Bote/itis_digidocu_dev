#include "annexdatacontroller.h"
#include "annexdata.h"

#include "itisuser.h"
#include "itisgroups.h"
#include "accountcontroller.h"
#include "actionrights.h"

#include "objects.h"
#include "catclasses.h"
#include "stdsystem.h"
#include "acclasses.h"
#include "pcclasses.h"
#include "annexmeta.h"
#include "annexdatawaste.h"
#include "annexdatacomments.h"

void AnnexDataController::writeAnnex()
{

    QMap<QString, QString> stdDataMap;
    QString msg;

    stdDataMap["obj_sname"] = "Annex A";
    stdDataMap["country"] = "WW";
    stdDataMap["lang"] = "de_DE";
    stdDataMap["spec_active"] = "1";
    stdDataMap["ac_class"] = "1";
    stdDataMap["pc_class"] = "1";
    stdDataMap["spec_release"] = "pre-release";
    stdDataMap["release_version"] = "01.00.00";
    stdDataMap["getStdType"] = "show";

    AnnexData::writeAnnex(stdDataMap);
}

void AnnexDataController::doReleased()
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
            QMap<QString, QString> stdDataMap;

            stdDataMap["release_id"] = httpRequest().formItemValue("release_id");
            stdDataMap["rel_creator"] = user.email();

            renderJson( AnnexData::doReleased(stdDataMap) );
        }
        else
        {
            QString red_msg = "<img class=\"w3-red\" src=\"/Icons/exclamation-square.svg\">&nbsp; Not authorized to access the page or resource you were trying to reach. " + uri;
            texport(red_msg);
            render("index");
        }
    }
    else
    {
        redirect(QUrl("/account/form"));
    }
}

void AnnexDataController::upReleased()
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
            QString id = httpRequest().formItemValue("id");
            int lid = id.toInt();
            renderJson( AnnexData::upReleased(lid) );
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

void AnnexDataController::doPreRelease()
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
            QMap<QString, QString> stdDataMap;

            stdDataMap["obj_sname"] = httpRequest().formItemValue("obj_sname");
            stdDataMap["ac_classes"] = httpRequest().formItemValue("ac_classes");
            stdDataMap["pc_classes"] = httpRequest().formItemValue("pc_classes");
            stdDataMap["cat_class"] = httpRequest().formItemValue("cat_class");
            stdDataMap["country"] = httpRequest().formItemValue("country");
            stdDataMap["lang"] = httpRequest().formItemValue("lang");
            stdDataMap["doc_type"] = "annex";
            stdDataMap["rel_requester"] = user.email();
            stdDataMap["relrequest_date"] = httpRequest().formItemValue("relrequest_date");

            renderJson( AnnexData::doPreRelease(stdDataMap) );
        }
        else
        {
            QString red_msg = "<img class=\"w3-red\" src=\"/Icons/exclamation-square.svg\">&nbsp; Not authorized to access the page or resource you were trying to reach. " + uri;
            texport(red_msg);
            render("index");
        }
    }
    else
    {
        redirect(QUrl("/account/form"));
    }
}

void AnnexDataController::upPrelease()
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
            QString id = httpRequest().formItemValue("id");
            int lid = id.toInt();
            renderJson( AnnexData::upPrelease(lid) );
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

void AnnexDataController::updAnnexData()
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
            QMap<QString, QString> stdDataMap;

            stdDataMap["id"] = httpRequest().formItemValue("id");
            stdDataMap["spec_title"] = httpRequest().formItemValue("spec_title");
            stdDataMap["spec_desc"] = httpRequest().formItemValue("spec_desc");
            stdDataMap["obj_sname"] = httpRequest().formItemValue("obj_sname");
            stdDataMap["cat_class"] = httpRequest().formItemValue("cat_class");
            stdDataMap["country"] = httpRequest().formItemValue("country");
            stdDataMap["lang"] = httpRequest().formItemValue("lang");
            stdDataMap["ac_classes"] = httpRequest().formItemValue("ac_classes");
            stdDataMap["pc_classes"] = httpRequest().formItemValue("pc_classes");
            stdDataMap["spec_version"] = httpRequest().formItemValue("spec_version");
            stdDataMap["spec_version_new"] = httpRequest().formItemValue("spec_version_new");
            stdDataMap["lfdnr"] = httpRequest().formItemValue("lfdnr");
            stdDataMap["spec_release"] = httpRequest().formItemValue("spec_release");
            stdDataMap["last_editor"] = httpRequest().formItemValue("last_editor");
            stdDataMap["spec_valid_start"] = httpRequest().formItemValue("spec_valid_start");
            stdDataMap["spec_valid_end"] = httpRequest().formItemValue("spec_valid_end");
            stdDataMap["spec_active"] = httpRequest().formItemValue("spec_active");
            stdDataMap["spec_content"] = httpRequest().formItemValue("spec_content");
            stdDataMap["g_legacy"] = httpRequest().formItemValue("g_legacy");
            stdDataMap["resp"] = httpRequest().formItemValue("resp");
            stdDataMap["comment"] = httpRequest().formItemValue("comment");
            stdDataMap["marker"] = httpRequest().formItemValue("marker");

            renderJson( AnnexData::updAnnexData(stdDataMap) );
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

void AnnexDataController::setAnnexData()
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
            QMap<QString, QString> stdDataMap;

            stdDataMap["spec_title"] = httpRequest().formItemValue("spec_title");
            stdDataMap["spec_desc"] = httpRequest().formItemValue("spec_desc");
            stdDataMap["obj_sname"] = httpRequest().formItemValue("obj_sname");
            stdDataMap["cat_class"] = httpRequest().formItemValue("cat_class");
            stdDataMap["country"] = httpRequest().formItemValue("country");
            stdDataMap["lang"] = httpRequest().formItemValue("lang");
            stdDataMap["ac_classes"] = httpRequest().formItemValue("ac_classes");
            stdDataMap["pc_classes"] = httpRequest().formItemValue("pc_classes");
            stdDataMap["spec_version"] = httpRequest().formItemValue("spec_version");
            stdDataMap["spec_version_new"] = httpRequest().formItemValue("spec_version_new");
            stdDataMap["lfdnr"] = httpRequest().formItemValue("lfdnr");
            stdDataMap["spec_release"] = httpRequest().formItemValue("spec_release");
            stdDataMap["last_editor"] = httpRequest().formItemValue("last_editor");
            stdDataMap["spec_valid_start"] = httpRequest().formItemValue("spec_valid_start");
            stdDataMap["spec_valid_end"] = httpRequest().formItemValue("spec_valid_end");
            stdDataMap["spec_active"] = httpRequest().formItemValue("spec_active");
            stdDataMap["spec_content"] = httpRequest().formItemValue("spec_content");
            stdDataMap["g_legacy"] = httpRequest().formItemValue("g_legacy");
            stdDataMap["resp"] = httpRequest().formItemValue("resp");
            stdDataMap["comment"] = httpRequest().formItemValue("comment");
            stdDataMap["marker"] = httpRequest().formItemValue("marker");

            renderJson( AnnexData::setAnnexData(stdDataMap) );
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

void AnnexDataController::getAnnexSpec()
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
            QString id = httpRequest().queryItemValue("id");
            int lid  = id.toInt();
            renderJson( AnnexData::getAnnexSpec(lid) );
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

void AnnexDataController::getAnnexToc()
{
    QString username = identityKeyOfLoginUser();
    ItisUser user = ItisUser::getByIdentityKey(username);
    if (!user.isNull())
    {
        QMap<QString, QString> stdDataMap;

        stdDataMap["obj_sname"] = httpRequest().formItemValue("obj_sname");
        stdDataMap["cat_sname_en"] = httpRequest().formItemValue("cat_sname_en");
        stdDataMap["country"] = httpRequest().formItemValue("country");
        stdDataMap["lang"] = httpRequest().formItemValue("lang");
        stdDataMap["spec_active"] = httpRequest().formItemValue("spec_active");
        stdDataMap["ac_class"] = httpRequest().formItemValue("ac_class");
        stdDataMap["pc_class"] = httpRequest().formItemValue("pc_class");
        stdDataMap["spec_release"] = httpRequest().formItemValue("spec_release");
        stdDataMap["getStdType"] = httpRequest().formItemValue("getStdType");

            /* ####
            stdDataMap["obj_sname"] = "Annex D";
            stdDataMap["cat_sname_en"] = "Cabling";
            stdDataMap["country"] = "WW";
            stdDataMap["lang"] = "de_DE";
            stdDataMap["spec_active"] = "1";
            stdDataMap["ac_class"] = "3";
            stdDataMap["pc_class"] = "3";
            stdDataMap["spec_release"] = "draft";
            stdDataMap["getStdType"] = "show";
            */

        renderJson( AnnexData::getAnnexToc(stdDataMap) );
    }
    else
    {
        redirect(QUrl("/account/form"));
    }
}

void AnnexDataController::getAnnexList()
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
            QMap<QString, QString> stdDataMap;

            stdDataMap["obj_sname"] = httpRequest().formItemValue("obj_sname");
            stdDataMap["cat_sname_en"] = httpRequest().formItemValue("cat_sname_en");
            stdDataMap["country"] = httpRequest().formItemValue("country");
            stdDataMap["lang"] = httpRequest().formItemValue("lang");
            stdDataMap["spec_active"] = httpRequest().formItemValue("spec_active");
            stdDataMap["ac_class"] = httpRequest().formItemValue("ac_class");
            stdDataMap["pc_class"] = httpRequest().formItemValue("pc_class");
            stdDataMap["spec_release"] = httpRequest().formItemValue("spec_release");
            stdDataMap["getStdType"] = httpRequest().formItemValue("getStdType");

            /*/ ####
            stdDataMap["obj_sname"] = "Annex A";
            stdDataMap["cat_sname_en"] = "Cabling";
            stdDataMap["country"] = "WW";
            stdDataMap["lang"] = "de_DE";
            stdDataMap["spec_active"] = "1";
            stdDataMap["ac_class"] = "3";
            stdDataMap["pc_class"] = "3";
            stdDataMap["spec_release"] = "draft";
            stdDataMap["getStdType"] = "show";
            */

            if(stdDataMap["getStdType"].compare("list") == 0)
            {
                renderJson( AnnexData::getAnnexList(stdDataMap) );
            }
            else
            {
                renderJson( AnnexData::getAnnexShow(stdDataMap) );
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

void AnnexDataController::getExistCountries()
{
    renderJson( AnnexData::getExistCountries() );
}

void AnnexDataController::printCiAnnex()
{

     QJsonArray jsonCategories = CatClasses::getAllJson("1", "category", "{Portal-Admin}");
            texport(jsonCategories);
/*
            QString obj_sname = httpRequest().formItemValue("obj_sname");
            texport(obj_sname);
            QString country = httpRequest().formItemValue("country");
            texport(country);
            QString lang = httpRequest().formItemValue("lang");
            texport(lang);
            QString ac_class = httpRequest().formItemValue("ac_class");
            texport(ac_class);
            QString pc_class = httpRequest().formItemValue("pc_class");
            texport(pc_class);
            QString spec_release = httpRequest().formItemValue("spec_release");
            texport(spec_release);
            QString getStdTyp = httpRequest().formItemValue("getStdType");
            texport(getStdTyp);
            QString release_id = httpRequest().formItemValue("release_id");
            texport(release_id);
*/
            //* / ####
            QString obj_sname = "Annex G4";
            texport(obj_sname);
            QString country = "DE";
            texport(country);
            QString lang = "de_DE";
            texport(lang);
            QString ac_class = "3";
            texport(ac_class);
            QString pc_class = "3";
            texport(pc_class);
            QString spec_release = "draft";
            texport(spec_release);
            QString getStdType = "show";
            texport(getStdType);
            //*/

            render();

}

void AnnexDataController::showCiAnnex()
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

            QString strGroups = ItisUser::sqlGroups( user.groups(), "r" );
            QJsonArray jsonCategories = CatClasses::getAllJson("1", "category", strGroups);
    // QJsonArray jsonCategories = CatClasses::getAllJson("1", "category", "{Portal-Admin}");
            texport(jsonCategories);

            QString obj_sname = httpRequest().formItemValue("obj_sname");
            texport(obj_sname);
            QString country = httpRequest().formItemValue("country");
            texport(country);
            QString lang = httpRequest().formItemValue("lang");
            texport(lang);
            QString ac_class = httpRequest().formItemValue("ac_class");
            texport(ac_class);
            QString pc_class = httpRequest().formItemValue("pc_class");
            texport(pc_class);
            QString spec_release = httpRequest().formItemValue("spec_release");
            texport(spec_release);
            QString getStdTyp = httpRequest().formItemValue("getStdType");
            texport(getStdTyp);
            QString release_id = httpRequest().formItemValue("release_id");
            texport(release_id);

            /* / ####
            QString obj_sname = "Annex G4";
            texport(obj_sname);
            QString country = "DE";
            texport(country);
            QString lang = "de_DE";
            texport(lang);
            QString ac_class = "3";
            texport(ac_class);
            QString pc_class = "3";
            texport(pc_class);
            QString spec_release = "pre-release";
            texport(spec_release);
            QString getStdType = "show";
            texport(getStdType);
            */

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

void AnnexDataController::showAnnex()
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
            QString strGroups = ItisUser::sqlGroups( user.groups(), "r" );

            QJsonArray jsonReleaseTypes = StdSystem::getAllJson("1", "release_types");
            texport(jsonReleaseTypes);

            QJsonArray jsonLanguages = StdSystem::getAllJson("1", "languages");
            texport(jsonLanguages);

            //QJsonArray jsonObjects = CatClasses::getAllJson("1", "annex");
            QJsonArray jsonObjects = CatClasses::getAllJson("1", "annex", strGroups);
            texport(jsonObjects);

            // QJsonArray jsonCategories= CatClasses::getAllJson("1", "category");
            QJsonArray jsonCategories = CatClasses::getAllJson("1", "category", strGroups);
            texport(jsonCategories);

            QJsonArray jsonExistCountries= AnnexData::getExistCountries();
            texport(jsonExistCountries);

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

void AnnexDataController::showAnnexElectron()
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
            QString strGroups = ItisUser::sqlGroups( user.groups(), "r" );

            QJsonArray jsonReleaseTypes = StdSystem::getAllJson("1", "release_types");
            texport(jsonReleaseTypes);

            QJsonArray jsonLanguages = StdSystem::getAllJson("1", "languages");
            texport(jsonLanguages);

            QJsonArray jsonObjects = CatClasses::getAllJson("1", "annex", strGroups);
            texport(jsonObjects);

            //QJsonArray jsonCategories= CatClasses::getAllJson("1", "category");
            QJsonArray jsonCategories = CatClasses::getAllJson("1", "category", strGroups);
            texport(jsonCategories);

            QJsonArray jsonExistCountries= AnnexData::getExistCountries();
            texport(jsonExistCountries);

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

void AnnexDataController::listAnnex()
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
            QString strGroups = ItisUser::sqlGroups( user.groups(), "r" );

            QJsonArray jsonReleaseTypes = StdSystem::getAllJson("1", "release_types");
            texport(jsonReleaseTypes);

            QJsonArray jsonLanguages = StdSystem::getAllJson("1", "languages");
            texport(jsonLanguages);

            //QJsonArray jsonObjects = CatClasses::getAllJson("1", "annex");
            QJsonArray jsonObjects = CatClasses::getAllJson("1", "annex", strGroups);
            texport(jsonObjects);

            //QJsonArray jsonCategories= CatClasses::getAllJson("1", "category");
            QJsonArray jsonCategories = CatClasses::getAllJson("1", "category", strGroups);
            texport(jsonCategories);

            QJsonArray jsonExistCountries= AnnexData::getExistCountries();
            texport(jsonExistCountries);

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

void AnnexDataController::doRecover(const QString &id)
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
            renderJson( AnnexDataWaste::doRecover(id.toInt()) );
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

void AnnexDataController::listWaste()
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
            int count = AnnexDataWaste::count();
            QString counter = QString::number(count);
            texport(counter);

            // bug in PROD
            auto annexDataWasteList = AnnexDataWaste::getAll();
            texport(annexDataWasteList);

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

void AnnexDataController::chkLfdnrEditor()
{
    QMap<QString, QString> editMap;

    editMap["cat_class"] = httpRequest().queryItemValue("cat");
    editMap["lfdnr"] = httpRequest().queryItemValue("lfdnr");

    renderJson( AnnexData::chkLfdnrEditor(editMap) );
}

void AnnexDataController::getHighestLfdnr(const QString &category)
{
    renderJson( AnnexData::getHighestLfdnr(category) );
}

void AnnexDataController::editor_upd(const QString &id)
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
            auto annexData = AnnexData::get(id.toInt());
            texport(annexData);

            auto annexMeta = AnnexMeta::getBySpecDataId(id.toInt());
            texport(annexMeta);

            QJsonArray jsonReleaseTypes = StdSystem::getAllJson("1", "release_types");
            texport(jsonReleaseTypes);
            QJsonArray jsonPcClasses = PcClasses::getPcClassesJson();
            texport(jsonPcClasses);
            QJsonArray jsonAcClasses = AcClasses::getAcClassesJson();
            texport(jsonAcClasses);
            QJsonArray jsonLanguages = StdSystem::getAllJson("1", "languages");
            texport(jsonLanguages);
            QJsonArray jsonObjects = CatClasses::getAllJson("1", "annex");
            texport(jsonObjects);
            QJsonArray jsonCategories= CatClasses::getAllJson("1", "category");
            texport(jsonCategories);
            QString userMail = user.email();
            texport(userMail);
            QString textcomment = QString::number( AnnexDataComments::getSpecsCommentsCount(id.toInt() ));
            texport(textcomment);

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

void AnnexDataController::editor_add()
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
            QJsonArray jsonReleaseTypes = StdSystem::getAllJson("1", "release_types");
            texport(jsonReleaseTypes);
            QJsonArray jsonPcClasses = PcClasses::getPcClassesJson();
            texport(jsonPcClasses);
            QJsonArray jsonAcClasses = AcClasses::getAcClassesJson();
            texport(jsonAcClasses);
            QJsonArray jsonLanguages = StdSystem::getAllJson("1", "languages");
            texport(jsonLanguages);
            QJsonArray jsonObjects = CatClasses::getAllJson("1", "annex");
            texport(jsonObjects);
            QJsonArray jsonCategories= CatClasses::getAllJson("1", "category");
            texport(jsonCategories);
            QString userMail = user.email();
            texport(userMail);

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

void AnnexDataController::uploadImg()
{
    QString username = identityKeyOfLoginUser();
    ItisUser user = ItisUser::getByIdentityKey(username);
    if (!user.isNull())
    {
        QJsonObject textObject;

        TMultipartFormData &formdata = httpRequest().multipartFormData();
        //QString origname = formdata.originalFileName("picture");

        QString origname = formdata.originalFileName("upload");
        origname = origname.toLower();

        QString fpath = "/webapp/html/itis/Img/Annexspecs/" + origname;
        formdata.renameUploadedFile("upload", fpath);

        textObject["url"] = "/Annexspecs/" + origname;
        renderJson(textObject);
    }
    else
    {
        redirect(QUrl("/account/form"));
    }
}

void AnnexDataController::getImages()
{
    QJsonObject jsonObject;
    QJsonArray jsonArray;
    QString pathToImg = "/webapp/html/itis/Img/Annexspecs";
    //QString pathToImg = "/webapp_dez/itis_app/public/images";
    QDir directory(pathToImg);
    QStringList images = directory.entryList(QStringList() << "*.jpg" << "*.jpeg" << "*.png" << "*.bmp" << "*.gif",QDir::Files);

    foreach(QString filename, images)
    {
       QFileInfo info(pathToImg + "/" + filename);
       jsonObject["size"] = info.size() / 1024;
       jsonObject["img"] = "/Annexspecs/" + filename;
       //jsonObject["img"] = "/images/" + filename;
       jsonObject["name"] = filename;
       jsonArray.append(jsonObject);
    }
    renderJson(jsonArray);
}

void AnnexDataController::checkLfdnrCat()
{
    QString username = identityKeyOfLoginUser();
    ItisUser user = ItisUser::getByIdentityKey(username);
    if (!user.isNull())
    {
        QString countCheckLfdnrCat = QString::number( AnnexData::countCheckLfdnrCat() );
        texport(countCheckLfdnrCat);

        render();
    }
    else
    {
        redirect(QUrl("/account/form"));
    }
}

void AnnexDataController::getStatistics()
{
    renderJson( AnnexData::getStatistics() );
}

void AnnexDataController::list_all()
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
            auto annexDataList = AnnexData::getAll();
            texport(annexDataList);
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

void AnnexDataController::index()
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

void AnnexDataController::show(const QString &id)
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
            auto annexData = AnnexData::get(id.toInt());
            texport(annexData);
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

void AnnexDataController::showWaste(const QString &id)
{
    QString username = identityKeyOfLoginUser();
    ItisUser user = ItisUser::getByIdentityKey(username);
    if (!user.isNull())
    {
        auto conti = TActionController::name();
        auto con = TActionController::activeAction();
        QString uri = "/" + conti + "/" + con;

        if(ActionRights::isInGroups(user.groups(), "cr_d", uri))
        {
            auto annexDataWaste = AnnexDataWaste::get(id.toInt());
            texport(annexDataWaste);
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

void AnnexDataController::create()
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
                auto annexData = httpRequest().formItems("annexData");
                auto model = AnnexData::create(annexData);

                if (!model.isNull()) {
                    QString notice = "Created successfully.";
                    tflash(notice);
                    redirect(urla("show", model.id()));
                } else {
                    QString error = "Failed to create.";
                    texport(error);
                    texport(annexData);
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

void AnnexDataController::save(const QString &id)
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
                auto model = AnnexData::get(id.toInt());
                if (!model.isNull()) {
                    auto annexData = model.toVariantMap();
                    texport(annexData);
                    render();
                }
                break; }

            case Tf::Post: {
                QString error;
                auto model = AnnexData::get(id.toInt());

                if (model.isNull()) {
                    error = "Original data not found. It may have been updated/removed by another transaction.";
                    tflash(error);
                    redirect(urla("save", id));
                    break;
                }

                auto annexData = httpRequest().formItems("annexData");
                model.setProperties(annexData);
                if (model.save()) {
                    QString notice = "Updated successfully.";
                    tflash(notice);
                    redirect(urla("show", model.id()));
                } else {
                    error = "Failed to update.";
                    texport(error);
                    texport(annexData);
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

void AnnexDataController::remove(const QString &id)
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

            auto annexData = AnnexData::get(id.toInt());
            annexData.remove();
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

void AnnexDataController::removeWaste(const QString &id)
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

            auto annexDataWaste = AnnexDataWaste::get(id.toInt());
            annexDataWaste.remove();
            redirect(urla("listWaste"));
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
T_DEFINE_CONTROLLER(AnnexDataController)
