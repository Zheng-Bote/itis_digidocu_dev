#include <TreeFrogModel>
#include "annexdata.h"
#include "sqlobjects/annexdataobject.h"

#include <string>
#include <regex>
#include<string.h>

#include "catclasses.h"
#include "annexdatacomments.h"

AnnexData::AnnexData() :
    TAbstractModel(),
    d(new AnnexDataObject())
{
    // set the initial parameters
}

AnnexData::AnnexData(const AnnexData &other) :
    TAbstractModel(),
    d(other.d)
{ }

AnnexData::AnnexData(const AnnexDataObject &object) :
    TAbstractModel(),
    d(new AnnexDataObject(object))
{ }

AnnexData::~AnnexData()
{
    // If the reference count becomes 0,
    // the shared data object 'AnnexDataObject' is deleted.
}

// #####

void AnnexData::writeAnnexHtml(QMap<QString, QString> &stdDataMap)
{
    QJsonValue id, spec_title, lfdnr, spec_version, spec_last_modified, specContent;


    QFile file(stdDataMap["htmlFileDir"]);
    file.open(QIODevice::WriteOnly | QIODevice::Append);
    QTextStream stream(&file);
    stream.setAutoDetectUnicode(true);


    // ["General","Planning", "Environment", "Construction", "Power", "Cabling", "Safety", "Security","Management","Operations","Appendix"];

    // data = new URLSearchParams([["getStdType", "show"], ["obj_sname", obj_name], ["cat_sname_en", cat], ["country", stdObj.country], ["lang", stdObj.lang], ["spec_active", stdObj.spec_active], ["ac_class", stdObj.ac_class], ["pc_class", stdObj.pc_class], ["spec_release", stdObj.spec_release]]);


    foreach (const QJsonValue & value, AnnexData::getAnnexList(stdDataMap))
    {
        QJsonObject objclass = value.toObject();
        id = objclass.value(QString("id"));
        lfdnr = objclass.value(QString("lfdnr"));
        spec_title = objclass.value(QString("spec_title"));
        spec_version = objclass.value(QString("spec_version"));
        spec_last_modified = objclass.value(QString("spec_last_modified"));
        stream << spec_title.toString() << '\n';
        stream << id.toString() << " " << lfdnr.toString() << " " << spec_last_modified.toString() << " " << spec_version.toString() << '\n';
        stream << "AC: " << objclass.value(QString("ac_classes")).toString() << " PC: " << objclass.value(QString("pc_classes")).toString() << " Country: " << objclass.value(QString("country")).toString() << '\n';

        QString msg = id.toString();
        int specId = msg.toInt();

        QJsonArray val =  AnnexData::getAnnexSpec(specId);

        foreach (const QJsonValue & val, val)
        {
            QJsonObject obj = val.toObject();
            stream << '\n' << obj["spec_content"].toString() << '\n';
        }
    }
    file.flush();
    file.close();
}
void AnnexData::writeAnnex(QMap<QString, QString> &stdDataMap)
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


<!--        <script src="https://itis.hitchhiker.tech/js/struct-data/StructData.js" /></script>
        <script src="https://itis.hitchhiker.tech/js/lenkinfo-data/LenkInfo.js"></script>
        <script src="https://itis.hitchhiker.tech/js/annexlist-data/AnnexlistData.js"></script>
        <script src="https://itis.hitchhiker.tech/js/glossar-data/GlossarData.js" /></script>
-->
    </head>
<body>
)";
    QString footer= R"(

</body>
</html>
)";

    stdDataMap["curentDateTime"] = QDateTime::currentDateTime().toString("yyyy-MM-dd_HHmmss");

    QString msg, doctitle, htmlFileDir, htmlFileUri;
    doctitle = stdDataMap["obj_sname"];
    doctitle.replace(" ", "_");

    QString dev_dir = "/webapp_dez/html/itis/pdf/annex/" + stdDataMap["spec_release"] + "/";
    QString prod_dir = "/webapp/html/itis/pdf/annex/" + stdDataMap["spec_release"] + "/";

    QString htmlFile = stdDataMap["curentDateTime"] + "_" + doctitle + "_v" + stdDataMap["release_version"] + "-" + stdDataMap["spec_release"] + ".html";

    QDir devDir(dev_dir);
    QDir prodDir(prod_dir);

    if(devDir.exists())
    {
        htmlFileDir = dev_dir + htmlFile;
        htmlFileUri = "http://localhost:8080" + htmlFile;
    }
    else if(prodDir.exists())
    {
        htmlFileDir = prod_dir + htmlFile;
        htmlFileUri = "https://itis.hitchhiker.tech/" + htmlFile;
    }

    stdDataMap["htmlFileDir"] = htmlFileDir;
    QMap<QString, QString> stdGeneralMap = stdDataMap;

    QFile file(htmlFileDir);
    file.open(QIODevice::WriteOnly | QIODevice::Append);
    QTextStream stream(&file);
    stream.setAutoDetectUnicode(true);
    stream << header << '\n';

    stream << "<span id=\"obj_name\" style=\"display:none;\">" << stdDataMap["obj_sname"] << "</span>" << '\n';
    stream << "<span id=\"lang\" style=\"display:none;\">" << stdDataMap["lang"] << "</span>" << '\n';

    file.flush();
    file.close();

    stdGeneralMap["obj_sname"] = "General";
    stdGeneralMap["country"] = "WW";
    stdGeneralMap["lang"] = "de_DE";
    stdGeneralMap["spec_active"] = "1";
    stdGeneralMap["ac_class"] = "0";
    stdGeneralMap["pc_class"] = "0";
    stdGeneralMap["spec_release"] = "pre-release";
    stdGeneralMap["getStdType"] = "show";
    stdGeneralMap["cat_sname_en"] = "General";

    AnnexData::writeAnnexHtml(stdGeneralMap);

    QStringList categories = {"General","Planning", "Environment", "Construction", "Power", "Cabling", "Safety", "Security","Management","Operations","Appendix"};

    for(int i = 0; i < categories.size(); ++i)
    {
        stdDataMap["cat_sname_en"] = categories.at(i).toLocal8Bit().constData();
        msg = stdDataMap["cat_sname_en"];
        qWarning("TEST: " + msg.toUtf8());
        AnnexData::writeAnnexHtml(stdDataMap);
    }

    file.open(QIODevice::WriteOnly | QIODevice::Append);
    stream.setAutoDetectUnicode(true);
    stream << footer << '\n';
    file.flush();
    file.close();
}

QJsonArray AnnexData::getAnnexSpec(int &id)
{
    TSqlQuery query;
    QJsonObject jsonObject;
    QJsonArray jsonArray;
    QString msg, lang;

    query.prepare("SELECT annex_data.id, lfdnr, spec_title, spec_desc, spec_version, spec_release, obj_sname, ac_classes, pc_classes, cat_class, country, lang, spec_active, spec_created, spec_last_modified, spec_valid_start, spec_valid_end, last_editor, g_legacy, responsibility, spec_comment, spec_marker, groups, spec_content FROM annex_data INNER JOIN annex_meta ON annex_meta.spec_data_id = annex_data.id WHERE annex_data.id = ?");
    query.addBindValue(id);

    if(!query.exec())
    {
        msg = query.lastError().text();
        jsonObject["errMsg"] = msg;
        jsonObject["ERROR"] = "1";
        jsonArray.append(jsonObject);

        return jsonArray;
     }

    while (query.next())
    {
        jsonObject["id"] = query.value(0).toString();
        jsonObject["lfdnr"] = query.value(1).toString();
        jsonObject["spec_title"] = query.value(2).toString();
        jsonObject["spec_desc"] = query.value(3).toString();
        jsonObject["spec_version"] = query.value(4).toString();
        jsonObject["spec_release"] = query.value(5).toString();
        jsonObject["obj_sname"] = query.value(6).toString();
        jsonObject["ac_classes"] = query.value(7).toString();
        jsonObject["pc_classes"] = query.value(8).toString();
        jsonObject["cat_class"] = query.value(9).toString();
        jsonObject["country"] = query.value(10).toString();
        jsonObject["lang"] = query.value(11).toString();
        lang = query.value(11).toString();
        jsonObject["spec_active"] = query.value(12).toString();
        jsonObject["spec_created"] = query.value(13).toString();
        jsonObject["spec_last_modified"] = query.value(14).toString();
        jsonObject["spec_valid_start"] = query.value(15).toString();
        jsonObject["spec_valid_end"] = query.value(16).toString();
        jsonObject["last_editor"] = query.value(17).toString();
        jsonObject["g_legacy"] = query.value(18).toString();
        jsonObject["responsibility"] = query.value(19).toString();
        jsonObject["spec_comment"] = query.value(20).toString();
        jsonObject["spec_marker"] = query.value(21).toString();
        jsonObject["groups"] = query.value(22).toString();

        std::string erg = query.value(23).toString().toStdString();
        findAndReplaceAll(erg, lang, "standard");
        jsonObject["spec_content"] = erg.c_str();

        std::string line = erg.c_str();

        std::regex reg1("(<h1>)(.{0,100})(</h1>)", std::regex_constants::icase);
        std::smatch match1;

        std::regex reg2("(<h2>)(.{0,100})(</h2>)", std::regex_constants::icase);
        std::smatch match2;

        std::regex reg3("(<h3>)(.{0,100})(</h3>)", std::regex_constants::icase);
        std::smatch match3;

        std::regex reg4("(<h4>)(.{0,100})(</h4>)", std::regex_constants::icase);
        std::smatch match4;

        QString toc;
        std::string ahref1 = "<li><a href=\"#";
        std::string ahref2 = ">";
        std::string ahref3 = "</a></li>";

        std::string class1 = "\" class='htoc1'";
        std::string class2 = "\" class='htoc2'";
        std::string class3 = "\" class='htoc3'";
        std::string class4 = "\" class='htoc4'";

        //std::string line = query.value(16).toString().toStdString();

        try
        {
            //std::regex re("((<h1>.{0,100}</h1>)|(<h2>.{0,100}</h2>)|(<h3>.{0,100}</h3>)|(<h4>.{0,100}</h4>))", std::regex_constants::icase);
            std::regex re("((<h1.{0,100}>.{0,100}</h1>)|(<h2.{0,100}>.{0,100}</h2>)|(<h3.{0,100}>.{0,100}</h3>)|(<h4.{0,100}>.{0,100}</h4>))", std::regex_constants::icase);
            std::sregex_iterator next(line.begin(), line.end(), re);
            std::sregex_iterator end;
            while (next != end)
            {
                std::smatch match = *next;
                //std::cout << "MATCH: " << match.str() << "\n";
                std::string item = match.str();
                if(std::regex_search(item, match1, reg1))
                {
                    std::string to = match1.str();

                    std::regex style_re("( style=\"[a-z]*-?[a-z]*:[a-z]*;\")");
                    to = regex_replace(to, style_re, "");

                    std::regex vowel_re("(<h1>)|(</h1>)");
                    to = regex_replace(to, vowel_re, "");
                    to = ahref1 + query.value(0).toString().toStdString() + class1 + ahref2 + to + ahref3;
                    toc.append(to.c_str());
                    next++;
                    continue;
                }
                if(std::regex_search(item, match2, reg2))
                {
                    std::string to = match2.str();

                    std::regex style_re("( style=\"[a-z]*-?[a-z]*:[a-z]*;\")");
                    to = regex_replace(to, style_re, "");

                    std::regex vowel_re("(<h2>)|(</h2>)");
                    to = regex_replace(to, vowel_re, "");
                    to = ahref1 + query.value(0).toString().toStdString() + class2 + ahref2 + to + ahref3;
                    toc.append(to.c_str());
                    next++;
                    continue;
                }
                if(std::regex_search(item, match3, reg3))
                {
                    std::string to = match3.str();

                    std::regex style_re("( style=\"[a-z]*-?[a-z]*:[a-z]*;\")");
                    to = regex_replace(to, style_re, "");

                    std::regex vowel_re("(<h3>)|(</h3>)");
                    to = regex_replace(to, vowel_re, "");
                    to = ahref1 + query.value(0).toString().toStdString() + class3 + ahref2 + to + ahref3;
                    toc.append(to.c_str());
                    next++;
                    continue;
                }
                if(std::regex_search(item, match4, reg4))
                {
                    std::string to = match4.str();

                    std::regex style_re("( style=\"[a-z]*-?[a-z]*:[a-z]*;\")");
                    to = regex_replace(to, style_re, "");

                    std::regex vowel_re("(<h4>)|(</h4>)");
                    to = regex_replace(to, vowel_re, "");
                    to = ahref1 + query.value(0).toString().toStdString() + class4 + ahref2 + to + ahref3;
                    toc.append(to.c_str());
                    next++;
                    continue;
                }

                next++;
            }
            jsonObject["toc"] = toc;
            toc = "";
        }
        catch (std::regex_error& e)
        {
            //std::cout << "Syntax error in the regular expression" << std::endl;
        }

        jsonArray.append(jsonObject);

    }

    return jsonArray;
}

void AnnexData::findAndReplaceAll(std::string &data, QString &lang, QString std_type)
{
    TSqlQuery query;
    std::string toSearch, replaceStr;

    std::string year = QDateTime::currentDateTime().toString("yyyy").toStdString();
    std::string y = "{{YYYY}}";
    std::string month = QDateTime::currentDateTime().toString("MM").toStdString();
    std::string m = "{{MM}}";

    size_t pos2 = data.find(y);
    // Repeat till end is reached
    while( pos2 != std::string::npos)
    {
        // Replace this occurrence of Sub String
        data.replace(pos2, y.size(), year);
        // Get the next occurrence from the current position
        pos2 =data.find(y, pos2 + y.size());
    }
    pos2 = data.find(m);
    // Repeat till end is reached
    while( pos2 != std::string::npos)
    {
        // Replace this occurrence of Sub String
        data.replace(pos2, m.size(), month);
        // Get the next occurrence from the current position
        pos2 =data.find(m, pos2 + m.size());
    }

    if( lang.compare("de_DE") == 0 )
    {
        query.prepare("SELECT std_attr, std_val_de FROM public.app_vars WHERE std_type = ? AND active = 1");
    }
    else
    {
        query.prepare("SELECT std_attr, std_val_en FROM public.app_vars WHERE std_type = ? AND active = 1");
    }
    // SELECT id, std_type, std_attr, std_val_de, std_val_en, active FROM public.app_vars;
    query.addBindValue(std_type);

    query.exec();

     while (query.next())
     {
         toSearch = "{{" + query.value(0).toString().toStdString() + "}}";
         replaceStr = query.value(1).toString().toStdString();

        // Get the first occurrence
        size_t pos = data.find(toSearch);
        // Repeat till end is reached
        while( pos != std::string::npos)
        {
            // Replace this occurrence of Sub String
            data.replace(pos, toSearch.size(), replaceStr);
            // Get the next occurrence from the current position
            pos =data.find(toSearch, pos + replaceStr.size());
        }
     }
}

QJsonArray AnnexData::sqlGet_crObjCatalog(bool doToc, QMap<QString, QString> outList)
{
    TSqlQuery query;
    QJsonObject jsonObject;
    QJsonArray jsonArray;
    QString msg, id, lang;

    QMapIterator<QString,QString> i(outList);
    while(i.hasNext())
    {
        i.next();
        id = i.value();

        if(doToc == false)
        {
            query.prepare("SELECT annex_data.id, lfdnr, spec_title, spec_desc, spec_version, spec_release, obj_sname, ac_classes, pc_classes, cat_class, country, lang, spec_active, spec_created, spec_last_modified, spec_valid_start, spec_valid_end, last_editor, g_legacy, responsibility, spec_comment, spec_marker, groups FROM annex_data INNER JOIN annex_meta ON annex_meta.spec_data_id = annex_data.id WHERE annex_data.id = ?");
            query.addBindValue(id);
        }
        else
        {
            query.prepare("SELECT annex_data.id, spec_title, spec_content, cat_class FROM annex_data WHERE annex_data.id = ?");
            query.addBindValue(id);
        }

        if(!query.exec())
         {
            msg = query.lastError().text();
            jsonObject["errMsg"] = msg;
            jsonObject["ERROR"] = "1";
            jsonArray.append(jsonObject);
         }

         while (query.next())
         {
             if(doToc == false)
             {
                 jsonObject["id"] = query.value(0).toString();
                 jsonObject["lfdnr"] = query.value(1).toString();
                 jsonObject["spec_title"] = query.value(2).toString();
                 jsonObject["spec_desc"] = query.value(3).toString();
                 jsonObject["spec_version"] = query.value(4).toString();
                 jsonObject["spec_release"] = query.value(5).toString();
                 jsonObject["obj_sname"] = query.value(6).toString();
                 jsonObject["ac_classes"] = query.value(7).toString();
                 jsonObject["pc_classes"] = query.value(8).toString();
                 jsonObject["cat_class"] = query.value(9).toString();
                 jsonObject["country"] = query.value(10).toString();
                 jsonObject["lang"] = query.value(11).toString();
                 lang = query.value(11).toString();
                 jsonObject["spec_active"] = query.value(12).toString();
                 jsonObject["spec_created"] = query.value(13).toString();
                 jsonObject["spec_last_modified"] = query.value(14).toString();
                 jsonObject["spec_valid_start"] = query.value(15).toString();
                 jsonObject["spec_valid_end"] = query.value(16).toString();
                 jsonObject["last_editor"] = query.value(17).toString();
                 jsonObject["g_legacy"] = query.value(18).toString();
                 jsonObject["responsibility"] = query.value(19).toString();
                 jsonObject["spec_comment"] = query.value(20).toString();
                 jsonObject["spec_marker"] = query.value(21).toString();
                 jsonObject["groups"] = query.value(22).toString();

                 jsonObject["comments_count"] = QString::number( AnnexDataComments::getSpecsCommentsCount(id.toInt() ));

                 jsonArray.append(jsonObject);
             }
             else
             {
                 jsonObject["id"] = query.value(0).toString();
                 jsonObject["spec_title"] = query.value(1).toString();
                 jsonObject["cat_class"] = query.value(3).toString();

                 //jsonObject["spec_content"] = query.value(2).toString();
                 std::string erg = query.value(2).toString().toStdString();
                 findAndReplaceAll(erg, lang, "standard");
                 std::string line = erg.c_str();

                 std::regex reg1("(<h1.{0,100}>)(.{0,100})(</h1>)", std::regex_constants::icase);
                 std::smatch match1;

                 std::regex reg2("(<h2.{0,100}>)(.{0,100})(</h2>)", std::regex_constants::icase);
                 std::smatch match2;

                 std::regex reg3("(<h3.{0,100}>)(.{0,100})(</h3>)", std::regex_constants::icase);
                 std::smatch match3;

                 std::regex reg4("(<h4>)(.{0,100})(</h4>)", std::regex_constants::icase);
                 std::smatch match4;

                 QString toc;
                 std::string ahref1 = "<a href=\"#";
                 std::string ahref2 = ">";
                 std::string ahref3 = "</a><br>";

                 std::string class1 = "\" class='htoc1'";
                 std::string class2 = "\" class='htoc2'";
                 std::string class3 = "\" class='htoc3'";
                 std::string class4 = "\" class='htoc4'";

                 //std::string line = query.value(16).toString().toStdString();

                 try
                 {
                   std::regex re("((<h1.{0,100}>.{0,100}</h1>)|(<h2.{0,100}>.{0,100}</h2>)|(<h3.{0,100}>.{0,100}</h3>))", std::regex_constants::icase);
                   std::sregex_iterator next(line.begin(), line.end(), re);
                   std::sregex_iterator end;
                   while (next != end)
                   {
                     std::smatch match = *next;
                     //std::cout << "MATCH: " << match.str() << "\n";
                     std::string item = match.str();

                     if(std::regex_search(item, match1, reg1))
                     {
                         std::string to = match1.str();

                         std::regex style_re("( style=\"[a-z]*-?[a-z]*:[a-z]*;\")");
                         to = regex_replace(to, style_re, "");

                         std::regex vowel_re("(<h1>)|(</h1>)");
                         to = regex_replace(to, vowel_re, "");
                         to = ahref1 + query.value(0).toString().toStdString() + class1 + ahref2 + to + ahref3;
                         toc.append(to.c_str());
                         next++;
                         continue;
                     }
                     if(std::regex_search(item, match2, reg2))
                     {
                         std::string to = match2.str();

                         std::regex style_re("( style=\"[a-z]*-?[a-z]*:[a-z]*;\")");
                         to = regex_replace(to, style_re, "");

                         std::regex vowel_re("(<h2>)|(</h2>)");
                         to = regex_replace(to, vowel_re, "");
                         to = ahref1 + query.value(0).toString().toStdString() + class2 + ahref2 + to + ahref3;
                         toc.append(to.c_str());
                         next++;
                         continue;
                     }
                     if(std::regex_search(item, match3, reg3))
                     {
                         std::string to = match3.str();

                         std::regex style_re("( style=\"[a-z]*-?[a-z]*:[a-z]*;\")");
                         to = regex_replace(to, style_re, "");

                         std::regex vowel_re("(<h3>)|(</h3>)");
                         to = regex_replace(to, vowel_re, "");
                         to = ahref1 + query.value(0).toString().toStdString() + class3 + ahref2 + to + ahref3;
                         toc.append(to.c_str());
                         next++;
                         continue;
                     }
                     if(std::regex_search(item, match4, reg4))
                     {
                         std::string to = match4.str();

                         std::regex style_re("( style=\"[a-z]*-?[a-z]*:[a-z]*;\")");
                         to = regex_replace(to, style_re, "");

                         std::regex vowel_re("(<h4>)|(</h4>)");
                         to = regex_replace(to, vowel_re, "");
                         to = ahref1 + query.value(0).toString().toStdString() + class4 + ahref2 + to + ahref3;
                         toc.append(to.c_str());
                         next++;
                         continue;
                     }

                     next++;
                   }
                   jsonObject["toc"] = toc;
                   toc = "";
                 }
                   catch (std::regex_error& e)
                   {
                     //std::cout << "Syntax error in the regular expression" << std::endl;
                   }

                 jsonArray.append(jsonObject);

             }
         }
    }
    return jsonArray;
}

QMap<QString, QString> AnnexData::checkObjCatalog(QMap<QString, QString> wwList, QMap<QString, QString> localList)
{
    QMapIterator<QString,QString> i(localList);
    while (i.hasNext())
    {
        i.next();
        if(localList.contains(i.key()))
        {
            wwList[i.key()] = localList[i.key()];
        }
    }

    return wwList;
}

QMap<QString, QString> AnnexData::sqlObjCatalog(QString name, QString ac, QString pc, QString country, QString lang, QString cat, QString spec_active, QString release)
{
    TSqlQuery query;

    QString msg, obj_name, ac_classes, pc_classes;
    QMap<QString, QString> inList;

    obj_name = "%" + name + "%";
    ac_classes = "%" + ac + "%";
    pc_classes = "%" + pc + "%";

    query.prepare("select lfdnr, id from annex_data where obj_sname LIKE ? and ac_classes LIKE ? and pc_classes LIKE ? and lang = ? and country = ? and cat_class = ? AND spec_active = ? AND (spec_release = ? or spec_release = 'pre-release') order by lfdnr");
    query.addBindValue(obj_name);
    query.addBindValue(ac_classes);
    query.addBindValue(pc_classes);
    query.addBindValue(lang);
    query.addBindValue(country);
    query.addBindValue(cat);
    query.addBindValue(spec_active);
    query.addBindValue(release);

    if(!query.exec())
    {
        msg = query.lastError().text();
        qWarning("ERROR: " + msg.toUtf8());
        //tDebug(msg.toUtf8());
    }

    while (query.next())
    {
        /*msg = "sqlObjCatalog: " + query.value(0).toString() + " " + query.value(1).toString();
        tDebug(msg.toUtf8()); */
        inList.insert(query.value(0).toString(),query.value(1).toString());
    }

    return inList;
}

QJsonArray AnnexData::listObjCatalog(bool doToc, QMap<QString, QString> editMap)
{
    QMap<QString, QString> localList, wwList, outList;
    QJsonArray array, tomerge;

    // General
    if(editMap["obj_sname"].compare("General") == 0)
    {

        wwList.clear(); localList.clear(); outList.clear();
        localList= AnnexData::sqlObjCatalog("General", "0", "0", editMap["country"], editMap["lang"], "General", editMap["spec_active"], editMap["spec_release"]);
        wwList = AnnexData::sqlObjCatalog("General", "0", "0", "WW", editMap["lang"], "General", editMap["spec_active"], editMap["spec_release"]);

        outList = AnnexData::checkObjCatalog(wwList, localList);
        return AnnexData::sqlGet_crObjCatalog(doToc, outList);
    }

    if(editMap["cat_sname_en"].compare("General") == 0)
    {
        wwList.clear(); localList.clear(); outList.clear();
        localList= AnnexData::sqlObjCatalog(editMap["obj_sname"], "0", "0", editMap["country"], editMap["lang"], "General", editMap["spec_active"], editMap["spec_release"]);
        wwList = AnnexData::sqlObjCatalog(editMap["obj_sname"], "0", "0", "WW", editMap["lang"], "General", editMap["spec_active"], editMap["spec_release"]);
        outList = AnnexData::checkObjCatalog(wwList, localList);
        array = AnnexData::sqlGet_crObjCatalog(doToc, outList);

        wwList.clear(); localList.clear(); outList.clear();
        localList= AnnexData::sqlObjCatalog(editMap["obj_sname"], editMap["ac_class"], editMap["pc_class"], editMap["country"], editMap["lang"], "General", editMap["spec_active"], editMap["spec_release"]);
        wwList = AnnexData::sqlObjCatalog(editMap["obj_sname"], editMap["ac_class"], editMap["pc_class"], "WW", editMap["lang"], "General", editMap["spec_active"], editMap["spec_release"]);
        outList = AnnexData::checkObjCatalog(wwList, localList);
        tomerge = AnnexData::sqlGet_crObjCatalog(doToc, outList);

        for(int i = 0; i < tomerge.size(); i++)
        {
            array.append(tomerge[i]);
        }
        return array;
    }
    else
    {
        // Cat
        wwList.clear(); localList.clear(); outList.clear();
        localList= AnnexData::sqlObjCatalog(editMap["obj_sname"], editMap["ac_class"], editMap["pc_class"], editMap["country"], editMap["lang"], editMap["cat_sname_en"], editMap["spec_active"], editMap["spec_release"]);
        wwList = AnnexData::sqlObjCatalog(editMap["obj_sname"], editMap["ac_class"], editMap["pc_class"], "WW", editMap["lang"], editMap["cat_sname_en"], editMap["spec_active"], editMap["spec_release"]);
        outList = AnnexData::checkObjCatalog(wwList, localList);
        return AnnexData::sqlGet_crObjCatalog(doToc, outList);
    }
}

QJsonArray AnnexData::doReleased(QMap<QString, QString> editMap)
{
    TSqlQuery query;
    QJsonObject jsonObj;
    QJsonArray array;
    QString msg;

    query.prepare("UPDATE public.release_mgmt SET rel_creator = ?, relcreator_decisdate = now(), cd_date = now() WHERE id = ?");
    query.addBindValue(editMap["rel_creator"]);
    query.addBindValue(editMap["release_id"].toInt());

    if(!query.exec())
    {
        msg = query.lastError().text();
        jsonObj["ERROR"] = "1";
        jsonObj["errMsg"] = "doReleased : " + msg;
        jsonObj["query"] = query.lastQuery();
        msg = "doRelease : ";
        msg.append(msg);
        msg.append(" : ");
        msg.append(query.lastQuery());
        tError(msg.toUtf8());

        array.append(jsonObj);
        return array;
    }
    else
    {
        jsonObj["ERROR"] = "0";
        jsonObj["errMsg"] = "Datensatz aktualisiert";

        array.append(jsonObj);
    }

    return array;
}

QJsonArray AnnexData::upReleased(int id)
{

    TSqlQuery query;
    QJsonObject jsonObj;
    QJsonArray jsonArr;
    QString msg;

    query.prepare("SELECT annex_data.id, lfdnr, spec_title, spec_desc, spec_version, obj_sname, ac_classes, pc_classes, cat_class, country, lang, spec_content, spec_created, spec_last_modified, spec_valid_start, spec_valid_end, last_editor, g_legacy, responsibility, spec_comment, spec_marker, groups, spec_active FROM annex_data INNER JOIN annex_meta ON annex_meta.spec_data_id = annex_data.id WHERE annex_data.id = ?");
    query.addBindValue(id);

    if(!query.exec())
    {
        msg = query.lastError().text();
        jsonObj["ERROR"] = "1";
        jsonObj["errMsg"] = msg;
        jsonObj["query"] = query.lastQuery();
        msg = "upReleased : ";
        msg.append(msg);
        msg.append(" : ");
        msg.append(query.lastQuery());
        tError(msg.toUtf8());

        jsonArr.append(jsonObj);
        return jsonArr;
    }

    query.next();

    QString lfdnr, spec_title, spec_desc, spec_version, spec_release, obj_sname, ac_class, pc_class, cat_class, country, lang, spec_content, spec_created, spec_last_modified, spec_valid_start, spec_valid_end, last_editor, g_legacy, responsibility, spec_comment, spec_marker, groups, spec_active;
    lfdnr = query.value(1).toString();
    spec_title = query.value(2).toString();
    spec_desc = query.value(3).toString();
    spec_version = query.value(4).toString();
    obj_sname = query.value(5).toString();
    ac_class = query.value(6).toString();
    pc_class = query.value(7).toString();
    cat_class = query.value(8).toString();
    country = query.value(9).toString();
    lang = query.value(10).toString();
    spec_content = query.value(11).toByteArray();
    spec_created = query.value(12).toString();
    spec_last_modified = query.value(13).toString();
    spec_valid_start = query.value(14).toString();
    spec_valid_end = query.value(15).toString();
    last_editor = query.value(16).toString();
    g_legacy = query.value(17).toString();
    responsibility = query.value(18).toString();
    spec_comment = query.value(19).toString();
    spec_marker = query.value(20).toString();
    groups = query.value(21).toString();
    spec_active = "0"; //query.value(22).toString();

    query.prepare("INSERT INTO public.release_annex(lfdnr, spec_title, spec_desc, spec_version, obj_sname, ac_class, pc_class, cat_class, country, lang, spec_content, spec_created, spec_last_modified, spec_valid_start, spec_valid_end, last_editor, g_legacy, responsibility, spec_comment, spec_marker, groups, spec_active, spec_release) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)");
    query.addBindValue(lfdnr);
    query.addBindValue(spec_title);
    query.addBindValue(spec_desc);
    query.addBindValue(spec_version);
    query.addBindValue(obj_sname);
    query.addBindValue(ac_class);
    query.addBindValue(pc_class);
    query.addBindValue(cat_class);
    query.addBindValue(country);
    query.addBindValue(lang);
    query.addBindValue(spec_content);
    query.addBindValue(spec_created);
    query.addBindValue(spec_last_modified);
    query.addBindValue(spec_valid_start);
    query.addBindValue(spec_valid_end);
    query.addBindValue(last_editor);
    query.addBindValue(g_legacy);
    query.addBindValue(responsibility);
    query.addBindValue(spec_comment);
    query.addBindValue(spec_marker);
    query.addBindValue(groups);
    query.addBindValue(spec_active);
    query.addBindValue("released");

    if(!query.exec())
    {
        msg = query.lastError().text();
        jsonObj["ERROR"] = "1";
        jsonObj["errMsg"] = msg;
        jsonObj["query"] = query.lastQuery();
        msg = "upReleased : ";
        msg.append(msg);
        msg.append(" : ");
        msg.append(query.lastQuery());
        tError(msg.toUtf8());

        jsonArr.append(jsonObj);
        return jsonArr;
    }
    else
    {
        jsonObj["ERROR"] = "0";
        jsonObj["errMsg"] = "Datensatz eingefügt";
        jsonObj["last_data_id"] = query.lastInsertId().toInt();
        msg = "Released: " + QDateTime::currentDateTime().toString("yyyy-MM-dd");;
        AnnexData::setDraft(id, msg);
    }

    jsonArr.append(jsonObj);
    return jsonArr;

}

void AnnexData::setDraft(int id, QString comment)
{
    TSqlQuery query;

    query.prepare("UPDATE public.annex_data SET spec_release='draft' WHERE id=?");
    query.addBindValue(id);
    query.exec();

    query.prepare("UPDATE public.annex_meta SET spec_comment=? WHERE spec_data_id=?");
    query.addBindValue(comment);
    query.addBindValue(id);
    query.exec();
}

QJsonArray AnnexData::doPreRelease(QMap<QString, QString> editMap)
{
    TSqlQuery query;
    QJsonObject jsonObj;
    QJsonArray array;
    QString msg;

    //obj_sname, spec_version, ac_classes, pc_classes, cat_class, country, lang, doc_type, rel_requester, relrequest_date, rel_creator, relcreator_decisdate, rel_inspector, relinspect_decisdate, rel_approver, relapprov_decisdate, ci_date, cd_date, cdd_date)

    query.prepare("INSERT INTO public.release_mgmt(obj_sname, ac_classes, pc_classes, cat_class, country, lang, doc_type, rel_requester, relrequest_date, ci_date) VALUES (?, ?, ?, ?, ?, ?, ?, ?, now(), now())");
    query.addBindValue(editMap["obj_sname"]);
    query.addBindValue(editMap["ac_classes"]);
    query.addBindValue(editMap["pc_classes"]);
    query.addBindValue(editMap["cat_class"]);
    query.addBindValue(editMap["country"]);
    query.addBindValue(editMap["lang"]);
    query.addBindValue(editMap["doc_type"]);
    query.addBindValue(editMap["rel_requester"]);
    //query.addBindValue(editMap["relrequest_date"]);

    if(!query.exec())
    {
        msg = query.lastError().text();
        jsonObj["ERROR"] = "1";
        jsonObj["errMsg"] = msg;
        tError(msg.toUtf8());

        array.append(jsonObj);
        return array;
    }
    else
    {
        jsonObj["ERROR"] = "0";
        jsonObj["errMsg"] = "Pre-Release eingestellt";
        jsonObj["last_id"] = query.lastInsertId().toInt();
    }

    array.append(jsonObj);
    return array;
}

QJsonArray AnnexData::upPrelease(int id)
{
    TSqlQuery query;
    QJsonObject jsonObj;
    QJsonArray array;
    QString msg;

    query.prepare("UPDATE public.annex_data SET spec_release='pre-release' WHERE id = ?");
    query.addBindValue(id);

    if(!query.exec())
    {
        msg = query.lastError().text();
        jsonObj["ERROR"] = "1";
        jsonObj["errMsg"] = "upPrelease : " + msg;
        jsonObj["query"] = query.lastQuery();
        msg = "upPrelease : ";
        msg.append(msg);
        msg.append(" : ");
        msg.append(query.lastQuery());
        tError(msg.toUtf8());

        array.append(jsonObj);
        return array;
    }
    else
    {
        jsonObj["ERROR"] = "0";
        jsonObj["errMsg"] = "Datensatz aktualisiert";

        array.append(jsonObj);
    }

    return array;
}

QJsonArray AnnexData::updAnnexData(QMap<QString, QString> editMap)
{
    TSqlQuery query;
    QJsonObject jsonObj;
    QJsonArray array;
    QString msg;

    editMap["country"] = editMap["country"].toUpper();

    if(editMap["lfdnr"].count() < 2)
    {
        editMap["lfdnr"] = "00" + editMap["lfdnr"];
    }
    else if(editMap["lfdnr"].count() < 3)
    {
        editMap["lfdnr"] = "0" + editMap["lfdnr"];
    }

    //QString searchtxt = "<p>{{page-break}}</p>";
    QRegularExpression re("<p>{{page-break}}</p>");
    QRegularExpressionMatchIterator i = re.globalMatch(editMap["spec_content"]);
    while (i.hasNext())
    {
        QRegularExpressionMatch match = i.next();
        editMap["spec_content"].replace(re, "{{page-break}}");
    }

    query.prepare("UPDATE public.annex_data	SET id=?, lfdnr=?, spec_title=?, spec_desc=?, spec_version=?, spec_release=?, obj_sname=?, ac_classes=?, pc_classes=?, cat_class=?, country=?, lang=?, spec_content=?, spec_active=? WHERE id = ?");

    query.addBindValue(editMap["id"]);
    query.addBindValue(editMap["lfdnr"]);
    query.addBindValue(editMap["spec_title"]);
    query.addBindValue(editMap["spec_desc"]);
    query.addBindValue(editMap["spec_version_new"]);
    query.addBindValue(editMap["spec_release"]);
    query.addBindValue(editMap["obj_sname"]);
    query.addBindValue(editMap["ac_classes"]);
    query.addBindValue(editMap["pc_classes"]);
    query.addBindValue(editMap["cat_class"]);
    query.addBindValue(editMap["country"]);
    query.addBindValue(editMap["lang"]);
    query.addBindValue(editMap["spec_content"]);
    query.addBindValue(editMap["spec_active"]);
    query.addBindValue(editMap["id"]);

    if(!query.exec())
    {
        msg = query.lastError().text();
        jsonObj["ERROR"] = "1";
        jsonObj["errMsg"] = msg;
        jsonObj["query"] = query.lastQuery();
        msg = "setObjSpecs : ";
        msg.append(msg);
        msg.append(" : ");
        msg.append(query.lastQuery());
        tError(msg.toUtf8());

        array.append(jsonObj);
        return array;
    }

    query.prepare("UPDATE public.annex_meta	SET spec_last_modified=?, spec_valid_start=?, spec_valid_end=?, last_editor=?, g_legacy=?, responsibility=?, spec_comment=?, spec_marker=? WHERE spec_data_id = ?");

    query.addBindValue(editMap["spec_valid_start"]);
    query.addBindValue(editMap["spec_valid_start"]);
    query.addBindValue(editMap["spec_valid_end"]);
    query.addBindValue(editMap["last_editor"]);
    query.addBindValue(editMap["g_legacy"]);
    query.addBindValue(editMap["resp"]);
    query.addBindValue(editMap["comment"]);
    query.addBindValue(editMap["marker"]);
    query.addBindValue(editMap["id"]);

    if(!query.exec())
    {
        msg = query.lastError().text();
        jsonObj["ERROR"] = "1";
        jsonObj["errMsg"] = msg;
        jsonObj["query"] = query.lastQuery();
        msg = "updStdData : ";
        msg.append(msg);
        msg.append(" : ");
        msg.append(query.lastQuery());
        tError(msg.toUtf8());

        array.append(jsonObj);
        return array;
    }
    else
    {
        jsonObj["ERROR"] = "0";
        jsonObj["errMsg"] = "Datensatz aktualisiert";
        jsonObj["data_id"] = editMap["id"];
    }

    array.append(jsonObj);
    return array;
}

QJsonArray AnnexData::setAnnexData(QMap<QString, QString> editMap)
{
    TSqlQuery query;
    QJsonObject jsonObj;
    QJsonArray jsonArr;
    QString msg;

    editMap["country"] = editMap["country"].toUpper();

    if(editMap["lfdnr"].count() < 2)
    {
        editMap["lfdnr"] = "00" + editMap["lfdnr"];
    }
    else if(editMap["lfdnr"].count() < 3)
    {
        editMap["lfdnr"] = "0" + editMap["lfdnr"];
    }

    query.prepare("INSERT INTO annex_data(lfdnr, spec_title, spec_desc, spec_version, spec_release, obj_sname, ac_classes, pc_classes, cat_class, country, lang, spec_content, spec_active) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)");

    query.addBindValue(editMap["lfdnr"]);
    query.addBindValue(editMap["spec_title"]);
    query.addBindValue(editMap["spec_desc"]);
    query.addBindValue(editMap["spec_version"]);
    query.addBindValue(editMap["spec_release"]);
    query.addBindValue(editMap["obj_sname"]);
    query.addBindValue(editMap["ac_classes"]);
    query.addBindValue(editMap["pc_classes"]);
    query.addBindValue(editMap["cat_class"]);
    query.addBindValue(editMap["country"]);
    query.addBindValue(editMap["lang"]);
    query.addBindValue(editMap["spec_content"]);
    query.addBindValue(editMap["spec_active"]);

    if(!query.exec())
    {
        msg = query.lastError().text();
        jsonObj["ERROR"] = "1";
        jsonObj["errMsg"] = msg;
        jsonObj["query"] = query.lastQuery();
        msg = "setObjSpecs : ";
        msg.append(msg);
        msg.append(" : ");
        msg.append(query.lastQuery());
        tError(msg.toUtf8());

        jsonArr.append(jsonObj);
        return jsonArr;
    }

    int last_id = query.lastInsertId().toInt();

    query.prepare("INSERT INTO annex_meta(spec_data_id, spec_created, spec_last_modified, spec_valid_start, spec_valid_end, last_editor, g_legacy, responsibility, spec_comment, spec_marker, groups) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)");

    query.addBindValue(last_id);
    query.addBindValue(editMap["spec_valid_start"]);
    query.addBindValue(editMap["spec_valid_start"]);
    query.addBindValue(editMap["spec_valid_start"]);
    query.addBindValue(editMap["spec_valid_start"]);
    query.addBindValue(editMap["last_editor"]);
    query.addBindValue(editMap["g_legacy"]);
    query.addBindValue(editMap["resp"]);
    query.addBindValue(editMap["comment"]);
    query.addBindValue(editMap["marker"]);

    query.addBindValue("{ALL}");

    if(!query.exec())
    {
        msg = query.lastError().text();
        jsonObj["ERROR"] = "1";
        jsonObj["errMsg"] = msg;
        jsonObj["query"] = query.lastQuery();
        msg = "setObjSpecs : ";
        msg.append(msg);
        msg.append(" : ");
        msg.append(query.lastQuery());
        tError(msg.toUtf8());

        jsonArr.append(jsonObj);
        return jsonArr;
    }
    else
    {
        jsonObj["ERROR"] = "0";
        jsonObj["errMsg"] = "Datensatz eingefügt";
        jsonObj["last_data_id"] = last_id;
        jsonObj["last_meta_id"] = query.lastInsertId().toInt();
    }

    jsonArr.append(jsonObj);
    return jsonArr;
}

QJsonArray AnnexData::getAnnexToc(QMap<QString, QString> &stdDataMap)
{
    QJsonObject jsonObject, jsonObjContent;
    QJsonValue jsonObjVal;
    QJsonArray jsonArr;

    QString obj_sname = stdDataMap["obj_sname"];

    stdDataMap["obj_sname"] = "General";
    foreach (const QJsonValue & value, AnnexData::listObjCatalog(true, stdDataMap) )
    {
        jsonObjContent = value.toObject();
        jsonObject["obj_sname"] = stdDataMap["obj_sname"];

        jsonObjVal = jsonObjContent.value(QString("cat_class"));
        jsonObject["cat_class"] =  jsonObjVal;

        jsonObjVal = jsonObjContent.value(QString("id"));
        jsonObject["id"] = jsonObjVal;

        jsonObjVal = jsonObjContent.value(QString("spec_title"));
        jsonObject["spec_title"] = jsonObjVal;

        jsonObjVal = jsonObjContent.value(QString("toc"));
        jsonObject["toc"] = jsonObjVal;

        jsonArr.append(jsonObject);
    }

    stdDataMap["obj_sname"] = obj_sname;
    foreach (const QJsonValue & value, CatClasses::getAllJson("1", "category"))
    {
        QJsonObject objclass = value.toObject();
        QJsonValue obj_class_name = objclass.value(QString("cat_sname_en"));
        if(obj_class_name.toString().compare("") == 1 )
        {
            stdDataMap["cat_sname_en"] = obj_class_name.toString();
            foreach (const QJsonValue & value, AnnexData::listObjCatalog(true, stdDataMap) )
            {
                jsonObjContent = value.toObject();
                jsonObject["obj_sname"] = stdDataMap["obj_sname"];

                jsonObjVal = jsonObjContent.value(QString("cat_class"));
                jsonObject["cat_class"] = jsonObjVal;

                jsonObjVal = jsonObjContent.value(QString("id"));
                jsonObject["id"] = jsonObjVal;

                jsonObjVal = jsonObjContent.value(QString("spec_title"));
                jsonObject["spec_title"] = jsonObjVal;

                jsonObjVal = jsonObjContent.value(QString("toc"));
                jsonObject["toc"] = jsonObjVal;

                jsonArr.append(jsonObject);
            }
        }
    }

    //return StandardsData::listObjCatalog(true, stdDataMap);
    return jsonArr;
}

QJsonArray AnnexData::getAnnexShow(QMap<QString, QString> &stdDataMap)
{
    return AnnexData::listObjCatalog(false, stdDataMap);
}

QJsonArray AnnexData::getAnnexList(QMap<QString, QString> &stdDataMap)
{
    TSqlQuery query;
    QJsonObject jsonObject;
    QJsonArray jsonArray;
    QString msg, obj_sname, ac_class, pc_class, id;

    obj_sname = "%" + stdDataMap["obj_sname"] + "%";
    ac_class = "%" + stdDataMap["ac_class"] + "%";
    pc_class = "%" + stdDataMap["pc_class"] + "%";

    query.prepare("SELECT annex_data.id, lfdnr, spec_title, spec_desc, spec_version, spec_release, obj_sname, ac_classes, pc_classes, cat_class, country, lang, spec_active, spec_created, spec_last_modified, spec_valid_start, spec_valid_end, last_editor, g_legacy, responsibility, spec_comment, spec_marker, groups FROM annex_data INNER JOIN annex_meta ON annex_meta.spec_data_id = annex_data.id WHERE obj_sname like ? AND cat_class = ? AND country = ? AND lang = ? AND spec_active = ? AND ac_classes like ? AND pc_classes like ? AND spec_release = ? order by lfdnr");
    //query.prepare("SELECT annex_data.id, lfdnr, spec_title, spec_desc, spec_version, spec_release, obj_sname, ac_classes, pc_classes, cat_class, country, lang, spec_active, spec_created, spec_last_modified, spec_valid_start, spec_valid_end, last_editor, g_legacy, responsibility, spec_comment, spec_marker, groups FROM annex_data INNER JOIN annex_meta ON annex_meta.spec_data_id = annex_data.id WHERE obj_sname like '%Annex D%' AND cat_class = 'Cabling' AND country = 'WW' AND lang = 'de_DE' AND spec_active = 1 AND ac_classes like '%2%' AND pc_classes like '%2%' AND spec_release = 'draft'");

    query.addBindValue(obj_sname);
    query.addBindValue(stdDataMap["cat_sname_en"]);
    query.addBindValue(stdDataMap["country"]);
    query.addBindValue(stdDataMap["lang"]);
    query.addBindValue(stdDataMap["spec_active"]);
    query.addBindValue(ac_class);
    query.addBindValue(pc_class);
    query.addBindValue(stdDataMap["spec_release"]);

    if(!query.exec())
     {
        msg = query.lastError().text();
        jsonObject["errMsg"] = msg;
        jsonObject["ERROR"] = "1";
        jsonArray.append(jsonObject);

        return jsonArray;
     }

     while (query.next())
     {
        id = query.value(0).toString();
        jsonObject["id"] = query.value(0).toString();
        jsonObject["lfdnr"] = query.value(1).toString();
        jsonObject["spec_title"] = query.value(2).toString();
        jsonObject["spec_desc"] = query.value(3).toString();
        jsonObject["spec_version"] = query.value(4).toString();
        jsonObject["spec_release"] = query.value(5).toString();
        jsonObject["obj_sname"] = query.value(6).toString();
        jsonObject["ac_classes"] = query.value(7).toString();
        jsonObject["pc_classes"] = query.value(8).toString();
        jsonObject["cat_class"] = query.value(9).toString();
        jsonObject["country"] = query.value(10).toString();
        jsonObject["lang"] = query.value(11).toString();
        jsonObject["spec_active"] = query.value(12).toString();
        jsonObject["spec_created"] = query.value(13).toString();
        jsonObject["spec_last_modified"] = query.value(14).toString();
        jsonObject["spec_valid_start"] = query.value(15).toString();
        jsonObject["spec_valid_end"] = query.value(16).toString();
        jsonObject["last_editor"] = query.value(17).toString();
        jsonObject["g_legacy"] = query.value(18).toString();
        jsonObject["responsibility"] = query.value(19).toString();
        jsonObject["spec_comment"] = query.value(20).toString();
        jsonObject["spec_marker"] = query.value(21).toString();
        jsonObject["groups"] = query.value(22).toString();

        jsonArray.append(jsonObject);
     }

     return jsonArray;
}

QJsonArray AnnexData::getExistCountries()
{
    TSqlQuery query;
    QJsonObject jsonObject;
    QJsonArray jsonArray;
    QString msg;

    query.prepare("SELECT DISTINCT(country) FROM public.annex_data ORDER BY country");

    if(!query.exec())
     {
        msg = query.lastError().text();
        jsonObject["errMsg"] = msg;
        jsonObject["ERROR"] = "1";
        jsonArray.append(jsonObject);
     }

     while (query.next())
     {
         jsonObject["country"] = query.value(0).toString();
         jsonArray.append(jsonObject);
     }
     return jsonArray;
}

QJsonArray AnnexData::getHighestLfdnr(const QString &category)
{
    TSqlQuery query;
    QJsonObject jsonObject;
    QJsonArray jsonArray;
    QString msg;

    query.prepare("SELECT MAX(lfdnr) FROM public.annex_data WHERE cat_class = ?");
    query.addBindValue(category);

    query.exec();
    query.next();

    jsonObject["lfdnr"] = query.value(0).toString();
    jsonObject["cat"] = category;
    jsonArray.append(jsonObject);

    return jsonArray;
}

int AnnexData::countCheckLfdnrCat()
{
    TSqlQuery query;
    int counter = 0;

    query.prepare("SELECT id, obj_sname, cat_class, lfdnr, country, lang, spec_title FROM public.annex_data a WHERE not Exists ( SELECT lfdnr FROM public.annex_data c WHERE a.lang != c.lang AND a.cat_class = c.cat_class and a.lfdnr = c.lfdnr) order by  (cat_class,lfdnr)");

    query.exec();

    while (query.next())
    {
        counter++;
    }

    return counter;
}

QJsonArray AnnexData::chkLfdnrEditor(QMap<QString, QString> editMap)
{
    TSqlQuery query;
    QJsonObject jsonObject;
    QJsonArray jsonArray;
    QString msg;

    query.prepare("SELECT id, lfdnr, spec_title, obj_sname, country, lang FROM public.annex_data WHERE cat_class = ? AND lfdnr = ?");
    query.addBindValue(editMap["cat_class"]);
    query.addBindValue(editMap["lfdnr"]);

    if(!query.exec())
     {
        msg = query.lastError().text();
        jsonObject["MSG"] = msg;
        jsonObject["ERROR"] = "1";
        jsonArray.append(jsonObject);
     }

     while (query.next())
     {
         jsonObject["id"] = query.value(0).toString();
         jsonObject["lfdnr"] = query.value(1).toString();
         jsonObject["spec_title"] = query.value(2).toString();
         jsonObject["obj_sname"] = query.value(3).toString();
         jsonObject["country"] = query.value(4).toString();
         jsonObject["lang"] = query.value(5).toString();

         jsonArray.append(jsonObject);
     }

     return jsonArray;
}

QJsonArray AnnexData::getStatistics()
{
    TSqlQuery query;
    QJsonObject jsonObject, jsonObjReleaseTypes;
    QJsonArray jsonArray, jsonArrReleaseTypes;
    QString msg;
    QList<QString> releaseTypes;

    // count
    query.prepare("SELECT count(id) FROM annex_data");
    query.exec();
    query.next();
    jsonObject["count_id"] = query.value(0).toString();

    // active
    query.prepare("select count(id) from annex_data where spec_active = 1");
    query.exec();
    query.next();
    jsonObject["count_active"] = query.value(0).toString();

    // countries
    query.prepare("select count(distinct country) from annex_data");
    query.exec();
    query.next();
    jsonObject["count_countries"] = query.value(0).toString();

    // languages
    query.prepare("select count(lang) from annex_data where lang = 'de_DE'");
    query.exec();
    query.next();
    jsonObject["count_language_de"] = query.value(0).toString();
    query.prepare("select count(lang) from annex_data where lang = 'en_GB'");
    query.exec();
    query.next();
    jsonObject["count_language_en"] = query.value(0).toString();

    // waste
    query.prepare("select count(id) from annex_data_waste");
    query.exec();
    query.next();
    jsonObject["count_Annexwaste"] = query.value(0).toString();

    // releases
    query.prepare("SELECT std_attr FROM std_system WHERE std_type = 'release_types' ORDER BY sort");
    query.exec();
    while (query.next())
    {
        releaseTypes.append(query.value(0).toString());
    }

    QList<QString>::iterator i;
    for (i = releaseTypes.begin(); i != releaseTypes.end(); ++i)
    {
        query.prepare("select count(spec_release) from annex_data where spec_release = ?");
        query.addBindValue(*i);
        query.exec();
        query.next();
        jsonObjReleaseTypes["release_type"] = *i;
        jsonObjReleaseTypes["count_release_type"] = query.value(0).toString();
        jsonArrReleaseTypes.append(jsonObjReleaseTypes);
    }

    jsonObject["countCheckLfdnrCat"] = QString::number( AnnexData::countCheckLfdnrCat() );

    jsonArray.append(jsonObject);
    jsonArray.append(jsonArrReleaseTypes);

    return jsonArray;
}

int AnnexData::id() const
{
    return d->id;
}

QString AnnexData::lfdnr() const
{
    return d->lfdnr;
}

void AnnexData::setLfdnr(const QString &lfdnr)
{
    d->lfdnr = lfdnr;
}

QString AnnexData::specTitle() const
{
    return d->spec_title;
}

void AnnexData::setSpecTitle(const QString &specTitle)
{
    d->spec_title = specTitle;
}

QString AnnexData::specDesc() const
{
    return d->spec_desc;
}

void AnnexData::setSpecDesc(const QString &specDesc)
{
    d->spec_desc = specDesc;
}

QString AnnexData::specVersion() const
{
    return d->spec_version;
}

void AnnexData::setSpecVersion(const QString &specVersion)
{
    d->spec_version = specVersion;
}

QString AnnexData::specRelease() const
{
    return d->spec_release;
}

void AnnexData::setSpecRelease(const QString &specRelease)
{
    d->spec_release = specRelease;
}

QString AnnexData::objSname() const
{
    return d->obj_sname;
}

void AnnexData::setObjSname(const QString &objSname)
{
    d->obj_sname = objSname;
}

QString AnnexData::acClasses() const
{
    return d->ac_classes;
}

void AnnexData::setAcClasses(const QString &acClasses)
{
    d->ac_classes = acClasses;
}

QString AnnexData::pcClasses() const
{
    return d->pc_classes;
}

void AnnexData::setPcClasses(const QString &pcClasses)
{
    d->pc_classes = pcClasses;
}

QString AnnexData::catClass() const
{
    return d->cat_class;
}

void AnnexData::setCatClass(const QString &catClass)
{
    d->cat_class = catClass;
}

QString AnnexData::country() const
{
    return d->country;
}

void AnnexData::setCountry(const QString &country)
{
    d->country = country;
}

QString AnnexData::lang() const
{
    return d->lang;
}

void AnnexData::setLang(const QString &lang)
{
    d->lang = lang;
}

QByteArray AnnexData::specContent() const
{
    return d->spec_content;
}

void AnnexData::setSpecContent(const QByteArray &specContent)
{
    d->spec_content = specContent;
}

int AnnexData::specActive() const
{
    return d->spec_active;
}

void AnnexData::setSpecActive(int specActive)
{
    d->spec_active = specActive;
}

AnnexData &AnnexData::operator=(const AnnexData &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

AnnexData AnnexData::create(const QString &lfdnr, const QString &specTitle, const QString &specDesc, const QString &specVersion, const QString &specRelease, const QString &objSname, const QString &acClasses, const QString &pcClasses, const QString &catClass, const QString &country, const QString &lang, const QByteArray &specContent, int specActive)
{
    AnnexDataObject obj;
    obj.lfdnr = lfdnr;
    obj.spec_title = specTitle;
    obj.spec_desc = specDesc;
    obj.spec_version = specVersion;
    obj.spec_release = specRelease;
    obj.obj_sname = objSname;
    obj.ac_classes = acClasses;
    obj.pc_classes = pcClasses;
    obj.cat_class = catClass;
    obj.country = country;
    obj.lang = lang;
    obj.spec_content = specContent;
    obj.spec_active = specActive;
    if (!obj.create()) {
        return AnnexData();
    }
    return AnnexData(obj);
}

AnnexData AnnexData::create(const QVariantMap &values)
{
    AnnexData model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

AnnexData AnnexData::get(int id)
{
    TSqlORMapper<AnnexDataObject> mapper;
    return AnnexData(mapper.findByPrimaryKey(id));
}

int AnnexData::count()
{
    TSqlORMapper<AnnexDataObject> mapper;
    return mapper.findCount();
}

QList<AnnexData> AnnexData::getAll()
{
    return tfGetModelListByCriteria<AnnexData, AnnexDataObject>(TCriteria());
}

QJsonArray AnnexData::getAllJson()
{
    QJsonArray array;
    TSqlORMapper<AnnexDataObject> mapper;

    if (mapper.find() > 0) {
        for (TSqlORMapperIterator<AnnexDataObject> i(mapper); i.hasNext(); ) {
            array.append(QJsonValue(QJsonObject::fromVariantMap(AnnexData(i.next()).toVariantMap())));
        }
    }
    return array;
}

QJsonArray AnnexData::getAllJsonCi()
{
    TSqlQuery query;
    QJsonObject jsonObject;
    QJsonArray jsonArray;
    QString msg;

    query.prepare("select id, obj_sname, spec_title, cat_class,lfdnr, lang, country FROM public.annex_data WHERE spec_release = 'released' group by (id, obj_sname, spec_title, cat_class, lfdnr, lang, country) order by (obj_sname,lfdnr)");

    if(!query.exec())
     {
        msg = query.lastError().text();
        jsonObject["MSG"] = msg;
        jsonObject["ERROR"] = "1";
        jsonArray.append(jsonObject);
     }

     while (query.next())
     {
         jsonObject["id"] = query.value(0).toString();
         jsonObject["obj_sname"] = query.value(1).toString();
         jsonObject["spec_title"] = query.value(2).toString();
         jsonObject["cat_class"] = query.value(3).toString();
         jsonObject["lfdnr"] = query.value(4).toString();
         jsonObject["lang"] = query.value(5).toString();
         jsonObject["country"] = query.value(6).toString();

         jsonArray.append(jsonObject);
     }

     return jsonArray;
}

TModelObject *AnnexData::modelData()
{
    return d.data();
}

const TModelObject *AnnexData::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const AnnexData &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, AnnexData &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(AnnexData)
