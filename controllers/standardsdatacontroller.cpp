#include "standardsdatacontroller.h"
#include "standardsdata.h"

#include "itisuser.h"
#include "itisgroups.h"
#include "accountcontroller.h"
#include "actionrights.h"

#include "objects.h"
#include "catclasses.h"
#include "stdsystem.h"
#include "acclasses.h"
#include "pcclasses.h"
#include "standardsmeta.h"
#include "standardsdatawaste.h"
#include "standardsdatacomments.h"

void StandardsDataController::doRecover(const QString &id)
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
            renderJson( StandardsDataWaste::doRecover(id.toInt()) );
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

void StandardsDataController::listWaste()
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
            int count = StandardsDataWaste::count();
            QString counter = QString::number(count);
            texport(counter);

            // bug in PROD
            auto standardsDataWasteList = StandardsDataWaste::getAll();
            //auto standardsDataWasteList = StandardsDataWaste::getAllJson();
            texport(standardsDataWasteList);

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

void StandardsDataController::getStdToc()
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
        stdDataMap["obj_sname"] = "BD";
        stdDataMap["cat_sname_en"] = "Construction";
        stdDataMap["country"] = "WW";
        stdDataMap["lang"] = "de_DE";
        stdDataMap["spec_active"] = "1";
        stdDataMap["ac_class"] = "3";
        stdDataMap["pc_class"] = "3";
        stdDataMap["spec_release"] = "draft";
        stdDataMap["getStdType"] = "show";
        */
        renderJson( StandardsData::getStdToc(stdDataMap) );
    }
    else
    {
        redirect(QUrl("/account/form"));
    }
}

/*!
 * \brief StandardsDataController::getStdList
 *
 * param = list | show
 *
*/
void StandardsDataController::getStdList()
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

            /* ####
            stdDataMap["obj_sname"] = "BD";
            stdDataMap["cat_sname_en"] = "Construction";
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
                renderJson( StandardsData::getStdList(stdDataMap) );
            }
            else
            {
                renderJson( StandardsData::getStdShow(stdDataMap) );
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

void StandardsDataController::getExistCountries()
{
    renderJson( StandardsData::getExistCountries() );
}

void StandardsDataController::showCiStd()
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


            /*/ ####
            QString obj_sname = "DBA";
            texport(obj_sname);
            QString country = "WW";
            texport(country);
            QString lang = "de_DE";
            texport(lang);
            QString ac_class = "2";
            texport(ac_class);
            QString pc_class = "3";
            texport(pc_class);
            QString spec_release = "pre-release";
            texport(spec_release);
            QString getStdType = "show";
            texport(getStdType);
            QString release_id = "19";
            texport(release_id);
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

void StandardsDataController::showStd()
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

            //QJsonArray jsonObjects = Objects::getAllJson("1");
            QJsonArray jsonObjects = Objects::getAllJson( "1", strGroups );
            texport(jsonObjects);

            //QJsonArray jsonCategories = CatClasses::getAllJson("1", "category");
            QJsonArray jsonCategories = CatClasses::getAllJson("1", "category", strGroups);
            texport(jsonCategories);

            QJsonArray jsonExistCountries = StandardsData::getExistCountries();
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

void StandardsDataController::showStdElectron()
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
            QJsonArray jsonReleaseTypes = StdSystem::getAllJson("1", "release_types");
            texport(jsonReleaseTypes);

            QJsonArray jsonLanguages = StdSystem::getAllJson("1", "languages");
            texport(jsonLanguages);

            QJsonArray jsonObjects = Objects::getAllJson("1");
            texport(jsonObjects);

            QJsonArray jsonCategories = CatClasses::getAllJson("1", "category");
            texport(jsonCategories);

            QJsonArray jsonExistCountries = StandardsData::getExistCountries();
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

void StandardsDataController::getStdSpec()
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
            renderJson( StandardsData::getStdSpec(lid) );
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

void StandardsDataController::listStd()
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

            //QJsonArray jsonObjects = Objects::getAllJson("1");
            QJsonArray jsonObjects = Objects::getAllJson( "1", strGroups );
            texport(jsonObjects);

            //QJsonArray jsonCategories= CatClasses::getAllJson("1", "category");
            QJsonArray jsonCategories= CatClasses::getAllJson("1", "category", strGroups);
            texport(jsonCategories);

            QJsonArray jsonExistCountries= StandardsData::getExistCountries();
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

void StandardsDataController::checkLfdnrCat()
{
    QString username = identityKeyOfLoginUser();
    ItisUser user = ItisUser::getByIdentityKey(username);
    if (!user.isNull())
    {
        QString countCheckLfdnrCat = QString::number( StandardsData::countCheckLfdnrCat() );
        texport(countCheckLfdnrCat);

        render();
    }
    else
    {
        redirect(QUrl("/account/form"));
    }
}

void StandardsDataController::getCheckLfdnrCat()
{
    QString username = identityKeyOfLoginUser();
    ItisUser user = ItisUser::getByIdentityKey(username);
    if (!user.isNull())
    {
        renderJson( StandardsData::getCheckLfdnrCat() );
    }
    else
    {
        redirect(QUrl("/account/form"));
    }
}

void StandardsDataController::uploadImg()
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

        QString fpath = "/webapp/html/itis/Img/Objspecs/" + origname;
        formdata.renameUploadedFile("upload", fpath);

        textObject["url"] = "/Objspecs/" + origname;
        renderJson(textObject);
    }
    else
    {
        redirect(QUrl("/account/form"));
    }
}

void StandardsDataController::getImages()
{
    QJsonObject jsonObject;
    QJsonArray jsonArray;
    QString pathToImg = "/webapp/html/itis/Img/Objspecs";
    QDir directory(pathToImg);
    QStringList images = directory.entryList(QStringList() << "*.jpg" << "*.jpeg" << "*.png" << "*.bmp" << "*.gif",QDir::Files);

    foreach(QString filename, images)
    {
       QFileInfo info(pathToImg + "/" + filename);
       jsonObject["size"] = info.size() / 1024;
       jsonObject["img"] = "/Objspecs/" + filename;
       jsonObject["name"] = filename;
       jsonArray.append(jsonObject);
    }
    renderJson(jsonArray);
}

void StandardsDataController::upReleased()
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
            renderJson( StandardsData::upReleased(lid) );
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

void StandardsDataController::doPreRelease()
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
            stdDataMap["doc_type"] = "standard";
            stdDataMap["rel_requester"] = user.email();
            stdDataMap["relrequest_date"] = httpRequest().formItemValue("relrequest_date");

            renderJson( StandardsData::doPreRelease(stdDataMap) );
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

void StandardsDataController::upPrelease()
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
            renderJson( StandardsData::upPrelease(lid) );
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

void StandardsDataController::updStdData()
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

            renderJson( StandardsData::updStdData(stdDataMap) );
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

void StandardsDataController::setStdData()
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

            renderJson( StandardsData::setStdData(stdDataMap) );
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

void StandardsDataController::getHighestLfdnr(const QString &category)
{
    renderJson( StandardsData::getHighestLfdnr(category) );
}

void StandardsDataController::chkLfdnrEditor()
{
    QMap<QString, QString> editMap;

    editMap["cat_class"] = httpRequest().queryItemValue("cat");
    editMap["lfdnr"] = httpRequest().queryItemValue("lfdnr");

    renderJson( StandardsData::chkLfdnrEditor(editMap) );
}

void StandardsDataController::editor_upd(const QString &id)
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
            QString strGroups = ItisUser::sqlGroups( user.groups(), "u" );

            auto standardsData = StandardsData::get(id.toInt());
            texport(standardsData);

            auto standardsMeta = StandardsMeta::getBySpecDataId(id.toInt());
            texport(standardsMeta);

            QJsonArray jsonReleaseTypes = StdSystem::getAllJson("1", "release_types");
            texport(jsonReleaseTypes);
            QJsonArray jsonPcClasses = PcClasses::getPcClassesJson();
            texport(jsonPcClasses);
            QJsonArray jsonAcClasses = AcClasses::getAcClassesJson();
            texport(jsonAcClasses);
            QJsonArray jsonLanguages = StdSystem::getAllJson("1", "languages");
            texport(jsonLanguages);
            QJsonArray jsonObjects = Objects::getAllJson( "1", strGroups );
            //QJsonArray jsonObjects = Objects::getAllJson( "1" );
            texport(jsonObjects);
            //QJsonArray jsonCategories= CatClasses::getAllJson("1", "category");
            QJsonArray jsonCategories= CatClasses::getAllJson("1", "category", strGroups);
            texport(jsonCategories);
            QString userMail = user.email();
            texport(userMail);
            QString textcomment = QString::number( StandardsDataComments::getSpecsCommentsCount(id.toInt() ));
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

void StandardsDataController::editor_add()
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
            QString strGroups = ItisUser::sqlGroups( user.groups(), "c" );

            QJsonArray jsonReleaseTypes = StdSystem::getAllJson("1", "release_types");
            texport(jsonReleaseTypes);
            QJsonArray jsonPcClasses = PcClasses::getPcClassesJson();
            texport(jsonPcClasses);
            QJsonArray jsonAcClasses = AcClasses::getAcClassesJson();
            texport(jsonAcClasses);
            QJsonArray jsonLanguages = StdSystem::getAllJson("1", "languages");
            texport(jsonLanguages);
            //QJsonArray jsonObjects = Objects::getAllJson("1");
            QJsonArray jsonObjects = Objects::getAllJson( "1", strGroups );
            texport(jsonObjects);
            //QJsonArray jsonCategories= CatClasses::getAllJson("1", "category");
            QJsonArray jsonCategories= CatClasses::getAllJson("1", "category", strGroups);
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

void StandardsDataController::getStatistics()
{
    renderJson( StandardsData::getStatistics() );
}

void StandardsDataController::list_all()
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
            auto standardsDataList = StandardsData::getAll();
            texport(standardsDataList);
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

void StandardsDataController::index()
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

void StandardsDataController::show(const QString &id)
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
            auto standardsData = StandardsData::get(id.toInt());
            texport(standardsData);
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

void StandardsDataController::showWaste(const QString &id)
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
            auto standardsDataWaste = StandardsDataWaste::get(id.toInt());
            texport(standardsDataWaste);
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


void StandardsDataController::create()
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
                auto standardsData = httpRequest().formItems("standardsData");
                auto model = StandardsData::create(standardsData);

                if (!model.isNull()) {
                    QString notice = "Created successfully.";
                    tflash(notice);
                    redirect(urla("show", model.id()));
                } else {
                    QString error = "Failed to create.";
                    texport(error);
                    texport(standardsData);
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

void StandardsDataController::save(const QString &id)
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
                auto model = StandardsData::get(id.toInt());
                if (!model.isNull()) {
                    auto standardsData = model.toVariantMap();
                    texport(standardsData);
                    render();
                }
                break; }

            case Tf::Post: {
                QString error;
                auto model = StandardsData::get(id.toInt());

                if (model.isNull()) {
                    error = "Original data not found. It may have been updated/removed by another transaction.";
                    tflash(error);
                    redirect(urla("save", id));
                    break;
                }

               // StandardsMeta::saveMeta( id.toInt(), user.username() );

                auto standardsData = httpRequest().formItems("standardsData");
                model.setProperties(standardsData);
                if (model.save()) {
                    QString notice = "Updated successfully.";
                    tflash(notice);
                    redirect(urla("show", model.id()));
                } else {
                    error = "Failed to update.";
                    texport(error);
                    texport(standardsData);
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

void StandardsDataController::remove(const QString &id)
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

            auto standardsData = StandardsData::get(id.toInt());
            standardsData.remove();

            auto standardsMeta = StandardsMeta::getBySpecDataId(id.toInt());
            standardsMeta.remove();

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

void StandardsDataController::removeWaste(const QString &id)
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

            auto standardsDataWaste = StandardsDataWaste::get(id.toInt());
            standardsDataWaste.remove();
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
T_DEFINE_CONTROLLER(StandardsDataController)
