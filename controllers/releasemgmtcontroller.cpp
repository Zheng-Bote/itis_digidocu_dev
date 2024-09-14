#include "releasemgmtcontroller.h"
#include "releasemgmt.h"

#include "itisuser.h"
#include "itisgroups.h"
#include "accountcontroller.h"
#include "actionrights.h"

#include "catclasses.h"
#include "releaseannex.h"
#include "lenkinfo.h"


void ReleaseMgmtController::fileRemove()
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

            stdDataMap["doctype"] = httpRequest().formItemValue("doctype");
            stdDataMap["docrelease"] = httpRequest().formItemValue("docrelease");
            stdDataMap["docname"] = httpRequest().formItemValue("docname");

            renderJson( ReleaseMgmt::fileRemove(stdDataMap) );
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

void ReleaseMgmtController::writeFile()
{
    QString header= R"(<!DOCTYPE html>

<html>
    <head>
        <meta charset="utf-8">
        <meta http-equiv="content-type" content="text/html; charset=UTF-8" />
        <meta name="viewport" content="width=device-width, initial-scale=1.0, user-scalable=yes">

        <title>PDF</title>

        <meta name="description" content="IaaS::IT-IS ReST API">
        <meta name="author" content="ZHENG Robert" />

        <link rel="icon" type="image/svg+xml" href="https://itis.hitchhiker.tech/favicon.svg">
        <link rel="alternate icon" href="https://itis.hitchhiker.tech/favicon.ico">
        <link rel="mask-icon" href="https://itis.hitchhiker.tech/favicon.svg" color="#b2b2b2">

        <link rel="stylesheet" href="https://itis.hitchhiker.tech/css/ci_print.css" type="text/css" media="all" />
    </head>
<body>

)";
    QString footer= R"(

</body>
</html>
)";

    QJsonObject jsonObj;
    QMap<QString, QString> stdDataMap;
    stdDataMap["content"] = httpRequest().formItemValue("doccontent");
 usleep(2000);
    QString msg = QString::number(stdDataMap["content"].length());
    tWarn("Länge: " + msg.toUtf8());
    QString docsize = httpRequest().formItemValue("docsize");
    QString doctype = httpRequest().formItemValue("doctype");
    QString doctitle = httpRequest().formItemValue("doctitle");
    QString docrelease = httpRequest().formItemValue("docrelease");
    QString lenkinfo = httpRequest().formItemValue("lenkinfo");

    if(docsize.compare(msg))
    {
        tError("Länge ungleich");

        jsonObj["ERROR"] = "1";
        jsonObj["errMsg"] = "Fehler bei der Übertragung";
        jsonObj["Msg"] = "Länge: " + docsize + " " + QString::number(stdDataMap["content"].length());
stdDataMap["content"] = httpRequest().formItemValue("doccontent");
msg = QString::number(stdDataMap["content"].length());
tWarn("Länge: " + msg.toUtf8());
        renderJson( jsonObj );
    }
    else
    {
        doctitle.replace(" ", "_");
        QString fileContent = header + stdDataMap["content"] + footer;

        QString curentDateTime = QDateTime::currentDateTime().toString("yyyy-MM-dd_HHmmss");
        QString dev_dir = "/webapp_dez/html/itis/pdf/" + doctype + "/" + docrelease + "/";
        QString prod_dir = "/webapp/html/itis/pdf/" + doctype + "/" + docrelease + "/";

        QString writeHtmlFile = curentDateTime + "_" + doctitle + "_v" + lenkinfo + "-" + docrelease + ".html";
        QString htmlFile = "/pdf/" + doctype + "/" + docrelease + "/" + writeHtmlFile;
        QString pdfFile = curentDateTime + "_" + doctitle + "_v" + lenkinfo + "-" + docrelease + ".pdf";

        QDir devDir(dev_dir);
        QDir prodDir(prod_dir);

        if(devDir.exists())
        {
            writeHtmlFile = dev_dir + writeHtmlFile;
            pdfFile = dev_dir + pdfFile;
            htmlFile = "http://localhost:8080" + htmlFile;
        }
        else if(prodDir.exists())
        {
            writeHtmlFile = prod_dir + writeHtmlFile;
            pdfFile = prod_dir + pdfFile;
            htmlFile = "https://itis.hitchhiker.tech/" + htmlFile;
        }

        QFile file(writeHtmlFile);
        file.open(QIODevice::WriteOnly);

        QTextStream stream(&file);
        stream.setAutoDetectUnicode(true);
        //stream.setCodec("UTF-8");

        stream << fileContent << '\n';

        file.flush();
        file.close();

        int ret = ReleaseMgmt::crPDF(htmlFile, pdfFile);
        jsonObj["ERROR"] = QString::number(ret);
        jsonObj["errMsg"] = doctitle;
        jsonObj["Msg"] = "Länge: " + docsize + " " + QString::number(stdDataMap["content"].length());

        renderJson( jsonObj );
    }
}

void ReleaseMgmtController::ci_update()
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
            stdDataMap["specVersion"] = httpRequest().formItemValue("specVersion");
            stdDataMap["relCreator"] = httpRequest().formItemValue("relCreator");
            stdDataMap["relcreatorDecisdate"] = httpRequest().formItemValue("relcreatorDecisdate");

            renderJson( ReleaseMgmt::ci_update(stdDataMap) );
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

void ReleaseMgmtController::listAllAnnexCi()
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

void ReleaseMgmtController::list_allAnnexCi()
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
            renderJson( ReleaseMgmt::list_allAnnexCi() );
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

void ReleaseMgmtController::listAllAnnexCd()
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

void ReleaseMgmtController::list_allAnnexCd()
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
            renderJson( ReleaseMgmt::list_allAnnexCd() );
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

void ReleaseMgmtController::listAllStdCi()
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

void ReleaseMgmtController::list_allStdCi()
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
            renderJson( ReleaseMgmt::list_allStdCi() );
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

void ReleaseMgmtController::listAllStdCd()
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

void ReleaseMgmtController::list_allStdCd()
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
            renderJson( ReleaseMgmt::list_allStdCd() );
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

void ReleaseMgmtController::list_pdf()
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

void ReleaseMgmtController::getStdCiPDFs()
{
    QJsonObject jsonObject;
    QJsonArray jsonArray;

    // PROD:
    QString pathToImg = "/webapp/html/itis/pdf/standard/pre-release";
    // DEV:     QString pathToImg = "/webapp_dez/html/itis/pdf/annex/pre-release";

    QDir directory(pathToImg);
    QStringList images = directory.entryList(QStringList() << "*.pdf" << "*.docx" << "*.odt",QDir::Files);

    foreach(QString filename, images)
    {
       QFileInfo info(pathToImg + "/" + filename);
       jsonObject["size"] = info.size() / 1024;
       jsonObject["uri"] = "/standard/pre-release/" + filename;
       jsonObject["last_modified"] = info.lastModified().toString("yyyy-MM-dd HH:mm:ss");
       jsonObject["name"] = filename;
       jsonArray.append(jsonObject);
    }
    renderJson(jsonArray);
}

void ReleaseMgmtController::getStdCdPDFs()
{
    QJsonObject jsonObject;
    QJsonArray jsonArray;

    // PROD:
    QString pathToImg = "/webapp/html/itis/pdf/standard/released";
    // DEV:     QString pathToImg = "/webapp_dez/html/itis/pdf/annex/released";

    QDir directory(pathToImg);
    QStringList images = directory.entryList(QStringList() << "*.pdf" << "*.docx" << "*.odt",QDir::Files);

    foreach(QString filename, images)
    {
       QFileInfo info(pathToImg + "/" + filename);
       jsonObject["size"] = info.size() / 1024;
       jsonObject["uri"] = "/standard/released/" + filename;
       jsonObject["last_modified"] = info.lastModified().toString("yyyy-MM-dd HH:mm:ss");
       jsonObject["name"] = filename;
       jsonArray.append(jsonObject);
    }
    renderJson(jsonArray);
}

void ReleaseMgmtController::getAnnexCiPDFs()
{
    QJsonObject jsonObject;
    QJsonArray jsonArray;

    // PROD:
    QString pathToImg = "/webapp/html/itis/pdf/annex/pre-release";
    // DEV:     QString pathToImg = "/webapp_dez/html/itis/pdf/annex/pre-release";

    QDir directory(pathToImg);
    QStringList images = directory.entryList(QStringList() << "*.pdf" << "*.docx" << "*.odt",QDir::Files);

    foreach(QString filename, images)
    {
       QFileInfo info(pathToImg + "/" + filename);
       jsonObject["size"] = info.size() / 1024;
       jsonObject["uri"] = "/annex/pre-release/" + filename;
       jsonObject["last_modified"] = info.lastModified().toString("yyyy-MM-dd HH:mm:ss");
       jsonObject["name"] = filename;
       jsonArray.append(jsonObject);
    }
    renderJson(jsonArray);
}

void ReleaseMgmtController::getAnnexCdPDFs()
{
    QJsonObject jsonObject;
    QJsonArray jsonArray;

    // PROD:
    QString pathToImg = "/webapp/html/itis/pdf/annex/released";
    // DEV:     QString pathToImg = "/webapp_dez/html/itis/pdf/annex/released";

    QDir directory(pathToImg);
    QStringList images = directory.entryList(QStringList() << "*.pdf" << "*.docx" << "*.odt",QDir::Files);

    foreach(QString filename, images)
    {
       QFileInfo info(pathToImg + "/" + filename);
       jsonObject["size"] = info.size() / 1024;
       jsonObject["uri"] = "/annex/released/" + filename;
       jsonObject["last_modified"] = info.lastModified().toString("yyyy-MM-dd HH:mm:ss");
       jsonObject["name"] = filename;
       jsonArray.append(jsonObject);
    }
    renderJson(jsonArray);
}

void ReleaseMgmtController::getAnnexToc()
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

        renderJson( ReleaseAnnex::getAnnexToc(stdDataMap) );
    }
    else
    {
        redirect(QUrl("/account/form"));
    }
}

void ReleaseMgmtController::getAnnexRelease()
{
    renderJson( ReleaseAnnex::getAllJson() );
}

void ReleaseMgmtController::getAnnexSpec()
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
            renderJson( ReleaseAnnex::getAnnexSpec(lid) );
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

void ReleaseMgmtController::getAnnexList()
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
            stdDataMap["obj_sname"] = "Annex B-3";
            stdDataMap["cat_sname_en"] = "Planning";
            stdDataMap["country"] = "WW";
            stdDataMap["lang"] = "de_DE";
            stdDataMap["spec_active"] = "1";
            stdDataMap["ac_class"] = "1";
            stdDataMap["pc_class"] = "1";
            stdDataMap["spec_release"] = "released";
            stdDataMap["getStdType"] = "show";
            */

            renderJson( ReleaseAnnex::getAnnexList(stdDataMap) );
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

void ReleaseMgmtController::printCdAnnex()
{

            //QString strGroups = ItisUser::sqlGroups( user.groups(), "r" );
            // QJsonArray jsonCategories = CatClasses::getAllJson("1", "category", strGroups);
            QJsonArray jsonCategories = CatClasses::getAllJson("1", "category");
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
            QString spec_release =  "released"; //httpRequest().formItemValue("spec_release");
            texport(spec_release);
            QString getStdTyp =  "show"; // httpRequest().formItemValue("getStdType");
            texport(getStdTyp);
            QString release_id = httpRequest().formItemValue("release_id");
            texport(release_id);

            /* / ####
            QString obj_sname = "Annex B-3";
            texport(obj_sname);
            QString country = "WW";
            texport(country);
            QString lang = "de_DE";
            texport(lang);
            QString ac_class = "1";
            texport(ac_class);
            QString pc_class = "1";
            texport(pc_class);
            QString spec_release = "released";
            texport(spec_release);
            QString getStdType = "show";
            texport(getStdType);
            QString release_id = "7";
            texport(release_id);
            /*/

            render();

}

void ReleaseMgmtController::showCdAnnex()
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
            QString spec_release =  "released"; //httpRequest().formItemValue("spec_release");
            texport(spec_release);
            QString getStdTyp =  "show"; // httpRequest().formItemValue("getStdType");
            texport(getStdTyp);
            QString release_id = httpRequest().formItemValue("release_id");
            texport(release_id);

            /* / ####
            QString obj_sname = "Annex B-3";
            texport(obj_sname);
            QString country = "WW";
            texport(country);
            QString lang = "de_DE";
            texport(lang);
            QString ac_class = "1";
            texport(ac_class);
            QString pc_class = "1";
            texport(pc_class);
            QString spec_release = "released";
            texport(spec_release);
            QString getStdType = "show";
            texport(getStdType);
            QString release_id = "7";
            texport(release_id);
            /*/

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

void ReleaseMgmtController::index_ciannex()
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

void ReleaseMgmtController::list_all()
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
            auto releaseMgmtList = ReleaseMgmt::getAll();
            texport(releaseMgmtList);
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

void ReleaseMgmtController::index()
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


void ReleaseMgmtController::show(const QString &id)
{
    auto releaseMgmt = ReleaseMgmt::get(id.toInt());
    texport(releaseMgmt);
    render();
}

void ReleaseMgmtController::create()
{
    switch (httpRequest().method()) {
    case Tf::Get:
        render();
        break;

    case Tf::Post: {
        auto releaseMgmt = httpRequest().formItems("releaseMgmt");
        auto model = ReleaseMgmt::create(releaseMgmt);

        if (!model.isNull()) {
            QString notice = "Created successfully.";
            tflash(notice);
            redirect(urla("show", model.id()));
        } else {
            QString error = "Failed to create.";
            texport(error);
            texport(releaseMgmt);
            render();
        }
        break; }

    default:
        renderErrorResponse(Tf::NotFound);
        break;
    }
}

void ReleaseMgmtController::saveAnnex(const QString &id)
{
    switch (httpRequest().method()) {
    case Tf::Get: {
        auto model = ReleaseAnnex::get(id.toInt());
        if (!model.isNull()) {
            auto releaseAnnex = model.toVariantMap();
            texport(releaseAnnex);
            render();
        }
        break; }

    case Tf::Post: {
        QString error;
        auto model = ReleaseAnnex::get(id.toInt());

        if (model.isNull()) {
            error = "Original data not found. It may have been updated/removed by another transaction.";
            tflash(error);
            redirect(urla("saveAnnex", id));
            break;
        }

        auto releaseAnnex = httpRequest().formItems("releaseAnnex");
        model.setProperties(releaseAnnex);

        if (model.save()) {
            QString notice = "Updated successfully.";
            tflash(notice);
            redirect(urla("saveAnnex", model.id()));
        } else {
            error = "Failed to update.";
            texport(error);
            texport(releaseAnnex);
            render();
        }
        break; }

    default:
        renderErrorResponse(Tf::NotFound);
        break;
    }
}

void ReleaseMgmtController::save(const QString &id)
{
    switch (httpRequest().method()) {
    case Tf::Get: {
        auto model = ReleaseMgmt::get(id.toInt());
        if (!model.isNull()) {
            auto releaseMgmt = model.toVariantMap();
            texport(releaseMgmt);

           // auto lenkinfo = Lenkinfo::model.toVariantMap();
           // texport(lenkinfo);

            render();
        }
        break; }

    case Tf::Post: {
        QString error;
        auto model = ReleaseMgmt::get(id.toInt());
        
        if (model.isNull()) {
            error = "Original data not found. It may have been updated/removed by another transaction.";
            tflash(error);
            redirect(urla("save", id));
            break;
        }

        auto releaseMgmt = httpRequest().formItems("releaseMgmt");
        model.setProperties(releaseMgmt);
        if (model.save()) {
            QString notice = "Updated successfully.";
            tflash(notice);
            redirect(urla("show", model.id()));
        } else {
            error = "Failed to update.";
            texport(error);
            texport(releaseMgmt);
            render();
        }
        break; }

    default:
        renderErrorResponse(Tf::NotFound);
        break;
    }
}

void ReleaseMgmtController::remove(const QString &id)
{
    if (httpRequest().method() != Tf::Post) {
        renderErrorResponse(Tf::NotFound);
        return;
    }

    auto releaseMgmt = ReleaseMgmt::get(id.toInt());
    releaseMgmt.remove();
    redirect(urla("index"));
}


// Don't remove below this line
T_DEFINE_CONTROLLER(ReleaseMgmtController)
