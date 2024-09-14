#include <TreeFrogModel>
#include "releaseannex.h"
#include "sqlobjects/releaseannexobject.h"

#include "catclasses.h"

#include <string>
#include <regex>
#include<string.h>

ReleaseAnnex::ReleaseAnnex() :
    TAbstractModel(),
    d(new ReleaseAnnexObject())
{
    // set the initial parameters
}

ReleaseAnnex::ReleaseAnnex(const ReleaseAnnex &other) :
    TAbstractModel(),
    d(other.d)
{ }

ReleaseAnnex::ReleaseAnnex(const ReleaseAnnexObject &object) :
    TAbstractModel(),
    d(new ReleaseAnnexObject(object))
{ }

ReleaseAnnex::~ReleaseAnnex()
{
    // If the reference count becomes 0,
    // the shared data object 'ReleaseAnnexObject' is deleted.
}

// #####

QJsonArray ReleaseAnnex::sqlGet_crObjCatalog(bool doToc, QMap<QString, QString> outList)
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
            query.prepare("SELECT id, lfdnr, spec_title, spec_desc, spec_version, spec_release, obj_sname, ac_class, pc_class, cat_class, country, lang, spec_active, spec_created, spec_last_modified, spec_valid_start, spec_valid_end, last_editor, g_legacy, responsibility, spec_comment, spec_marker, groups FROM release_annex WHERE id = ?");
            query.addBindValue(id);
        }
        else
        {
            query.prepare("SELECT id, spec_title, spec_content, cat_class FROM release_annex WHERE id = ?");
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

                // jsonObject["comments_count"] = QString::number( AnnexDataComments::getSpecsCommentsCount(id.toInt() ));

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

QMap<QString, QString> ReleaseAnnex::checkObjCatalog(QMap<QString, QString> wwList, QMap<QString, QString> localList)
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

QMap<QString, QString> ReleaseAnnex::sqlObjCatalog(QString name, QString ac, QString pc, QString country, QString lang, QString cat, QString spec_active, QString release)
{
    TSqlQuery query;

    QString msg, obj_name, ac_classes, pc_classes;
    QMap<QString, QString> inList;

    obj_name = "%" + name + "%";
    ac_classes = "%" + ac + "%";
    pc_classes = "%" + pc + "%";

    query.prepare("select lfdnr, id from release_annex where obj_sname LIKE ? and ac_class LIKE ? and pc_class LIKE ? and lang = ? and country = ? and cat_class = ? AND spec_active = ? AND spec_release = ? order by lfdnr");
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

QJsonArray ReleaseAnnex::listObjCatalog(bool doToc, QMap<QString, QString> editMap)
{
    QMap<QString, QString> localList, wwList, outList;
    QJsonArray array, tomerge;

    // General
    if(editMap["obj_sname"].compare("General") == 0)
    {

        wwList.clear(); localList.clear(); outList.clear();
        localList= ReleaseAnnex::sqlObjCatalog("General", "0", "0", editMap["country"], editMap["lang"], "General", editMap["spec_active"], editMap["spec_release"]);
        wwList = ReleaseAnnex::sqlObjCatalog("General", "0", "0", "WW", editMap["lang"], "General", editMap["spec_active"], editMap["spec_release"]);

        outList = ReleaseAnnex::checkObjCatalog(wwList, localList);
        return ReleaseAnnex::sqlGet_crObjCatalog(doToc, outList);
    }

    if(editMap["cat_sname_en"].compare("General") == 0)
    {
        wwList.clear(); localList.clear(); outList.clear();
        localList= ReleaseAnnex::sqlObjCatalog(editMap["obj_sname"], "0", "0", editMap["country"], editMap["lang"], "General", editMap["spec_active"], editMap["spec_release"]);
        wwList = ReleaseAnnex::sqlObjCatalog(editMap["obj_sname"], "0", "0", "WW", editMap["lang"], "General", editMap["spec_active"], editMap["spec_release"]);
        outList = ReleaseAnnex::checkObjCatalog(wwList, localList);
        array = ReleaseAnnex::sqlGet_crObjCatalog(doToc, outList);

        wwList.clear(); localList.clear(); outList.clear();
        localList= ReleaseAnnex::sqlObjCatalog(editMap["obj_sname"], editMap["ac_class"], editMap["pc_class"], editMap["country"], editMap["lang"], "General", editMap["spec_active"], editMap["spec_release"]);
        wwList = ReleaseAnnex::sqlObjCatalog(editMap["obj_sname"], editMap["ac_class"], editMap["pc_class"], "WW", editMap["lang"], "General", editMap["spec_active"], editMap["spec_release"]);
        outList = ReleaseAnnex::checkObjCatalog(wwList, localList);
        tomerge = ReleaseAnnex::sqlGet_crObjCatalog(doToc, outList);

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
        localList= ReleaseAnnex::sqlObjCatalog(editMap["obj_sname"], editMap["ac_class"], editMap["pc_class"], editMap["country"], editMap["lang"], editMap["cat_sname_en"], editMap["spec_active"], editMap["spec_release"]);
        wwList = ReleaseAnnex::sqlObjCatalog(editMap["obj_sname"], editMap["ac_class"], editMap["pc_class"], "WW", editMap["lang"], editMap["cat_sname_en"], editMap["spec_active"], editMap["spec_release"]);
        outList = ReleaseAnnex::checkObjCatalog(wwList, localList);
        return ReleaseAnnex::sqlGet_crObjCatalog(doToc, outList);
    }
}

QJsonArray ReleaseAnnex::getAnnexToc(QMap<QString, QString> &stdDataMap)
{
    QJsonObject jsonObject, jsonObjContent;
    QJsonValue jsonObjVal;
    QJsonArray jsonArr;

    QString obj_sname = stdDataMap["obj_sname"];

    stdDataMap["obj_sname"] = "General";
    foreach (const QJsonValue & value, ReleaseAnnex::listObjCatalog(true, stdDataMap) )
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
            foreach (const QJsonValue & value, ReleaseAnnex::listObjCatalog(true, stdDataMap) )
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

    return jsonArr;
}

QJsonArray ReleaseAnnex::getAnnexSpec(int &id)
{
    TSqlQuery query;
    QJsonObject jsonObject;
    QJsonArray jsonArray;
    QString msg, lang;

    query.prepare("SELECT id, lfdnr, spec_title, spec_desc, spec_version, release_version, obj_sname, ac_class, pc_class, cat_class, country, lang, spec_active, spec_created, spec_last_modified, spec_valid_start, spec_valid_end, last_editor, g_legacy, responsibility, spec_comment, spec_marker, groups, spec_content FROM public.release_annex WHERE id = ?");
    //query.prepare("SELECT * FROM public.release_annex WHERE id = 7");
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
        jsonObject["release_version"] = query.value(5).toString();
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

void ReleaseAnnex::findAndReplaceAll(std::string &data, QString &lang, QString std_type)
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

QJsonArray ReleaseAnnex::getAnnexList(QMap<QString, QString> &stdDataMap)
{
    TSqlQuery query;
    QJsonObject jsonObject;
    QJsonArray jsonArray;
    QString msg, obj_sname, ac_class, pc_class, id;

    obj_sname = "%" + stdDataMap["obj_sname"] + "%";
    ac_class = "%" + stdDataMap["ac_class"] + "%";
    pc_class = "%" + stdDataMap["pc_class"] + "%";

    // query.prepare("SELECT id, lfdnr, spec_title, spec_desc, spec_version, release_version, spec_release, obj_sname, ac_class, pc_class, cat_class, country, lang, spec_content, spec_created, spec_last_modified, spec_valid_start, spec_valid_end, last_editor, g_legacy, responsibility, spec_comment, spec_marker, groups, spec_active FROM public.release_annex WHERE obj_sname like ? AND cat_class = ? AND country = ? AND lang = ? AND spec_active = ? AND ac_classes like ? AND pc_classes like ? AND spec_release = ? order by lfdnr");
    //query.prepare("SELECT * FROM public.release_annex where cat_class = 'General' order by lfdnr");
    query.prepare("SELECT id, lfdnr, spec_title, spec_desc, spec_version, release_version, obj_sname, ac_class, pc_class, cat_class, country, lang, spec_active, spec_created, spec_last_modified, spec_valid_start, spec_valid_end, last_editor, g_legacy, responsibility, spec_comment, spec_marker, groups FROM public.release_annex WHERE obj_sname like ? AND cat_class = ? AND country = ? AND lang = ? AND spec_active = ? AND ac_class like ? AND pc_class like ? AND spec_release = ? order by lfdnr");
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
         jsonObject["id"] = query.value(0).toString();
         jsonObject["lfdnr"] = query.value(1).toString();
         jsonObject["spec_title"] = query.value(2).toString();
         jsonObject["spec_desc"] = query.value(3).toString();
         jsonObject["spec_version"] = query.value(4).toString();
         jsonObject["release_version"] = query.value(5).toString();
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


int ReleaseAnnex::id() const
{
    return d->id;
}

QString ReleaseAnnex::lfdnr() const
{
    return d->lfdnr;
}

void ReleaseAnnex::setLfdnr(const QString &lfdnr)
{
    d->lfdnr = lfdnr;
}

QString ReleaseAnnex::specTitle() const
{
    return d->spec_title;
}

void ReleaseAnnex::setSpecTitle(const QString &specTitle)
{
    d->spec_title = specTitle;
}

QString ReleaseAnnex::specDesc() const
{
    return d->spec_desc;
}

void ReleaseAnnex::setSpecDesc(const QString &specDesc)
{
    d->spec_desc = specDesc;
}

QString ReleaseAnnex::specVersion() const
{
    return d->spec_version;
}

void ReleaseAnnex::setSpecVersion(const QString &specVersion)
{
    d->spec_version = specVersion;
}

QString ReleaseAnnex::releaseVersion() const
{
    return d->release_version;
}

void ReleaseAnnex::setReleaseVersion(const QString &releaseVersion)
{
    d->release_version = releaseVersion;
}

QString ReleaseAnnex::specRelease() const
{
    return d->spec_release;
}

void ReleaseAnnex::setSpecRelease(const QString &specRelease)
{
    d->spec_release = specRelease;
}

QString ReleaseAnnex::objSname() const
{
    return d->obj_sname;
}

void ReleaseAnnex::setObjSname(const QString &objSname)
{
    d->obj_sname = objSname;
}

QString ReleaseAnnex::acClass() const
{
    return d->ac_class;
}

void ReleaseAnnex::setAcClass(const QString &acClass)
{
    d->ac_class = acClass;
}

QString ReleaseAnnex::pcClass() const
{
    return d->pc_class;
}

void ReleaseAnnex::setPcClass(const QString &pcClass)
{
    d->pc_class = pcClass;
}

QString ReleaseAnnex::catClass() const
{
    return d->cat_class;
}

void ReleaseAnnex::setCatClass(const QString &catClass)
{
    d->cat_class = catClass;
}

QString ReleaseAnnex::country() const
{
    return d->country;
}

void ReleaseAnnex::setCountry(const QString &country)
{
    d->country = country;
}

QString ReleaseAnnex::lang() const
{
    return d->lang;
}

void ReleaseAnnex::setLang(const QString &lang)
{
    d->lang = lang;
}

QByteArray ReleaseAnnex::specContent() const
{
    return d->spec_content;
}

void ReleaseAnnex::setSpecContent(const QByteArray &specContent)
{
    d->spec_content = specContent;
}

QDateTime ReleaseAnnex::specCreated() const
{
    return d->spec_created;
}

void ReleaseAnnex::setSpecCreated(const QDateTime &specCreated)
{
    d->spec_created = specCreated;
}

QDateTime ReleaseAnnex::specLastModified() const
{
    return d->spec_last_modified;
}

void ReleaseAnnex::setSpecLastModified(const QDateTime &specLastModified)
{
    d->spec_last_modified = specLastModified;
}

QDateTime ReleaseAnnex::specValidStart() const
{
    return d->spec_valid_start;
}

void ReleaseAnnex::setSpecValidStart(const QDateTime &specValidStart)
{
    d->spec_valid_start = specValidStart;
}

QDateTime ReleaseAnnex::specValidEnd() const
{
    return d->spec_valid_end;
}

void ReleaseAnnex::setSpecValidEnd(const QDateTime &specValidEnd)
{
    d->spec_valid_end = specValidEnd;
}

QString ReleaseAnnex::lastEditor() const
{
    return d->last_editor;
}

void ReleaseAnnex::setLastEditor(const QString &lastEditor)
{
    d->last_editor = lastEditor;
}

QString ReleaseAnnex::gLegacy() const
{
    return d->g_legacy;
}

void ReleaseAnnex::setGLegacy(const QString &gLegacy)
{
    d->g_legacy = gLegacy;
}

QString ReleaseAnnex::responsibility() const
{
    return d->responsibility;
}

void ReleaseAnnex::setResponsibility(const QString &responsibility)
{
    d->responsibility = responsibility;
}

QString ReleaseAnnex::specComment() const
{
    return d->spec_comment;
}

void ReleaseAnnex::setSpecComment(const QString &specComment)
{
    d->spec_comment = specComment;
}

QString ReleaseAnnex::specMarker() const
{
    return d->spec_marker;
}

void ReleaseAnnex::setSpecMarker(const QString &specMarker)
{
    d->spec_marker = specMarker;
}

QString ReleaseAnnex::groups() const
{
    return d->groups;
}

void ReleaseAnnex::setGroups(const QString &groups)
{
    d->groups = groups;
}

int ReleaseAnnex::specActive() const
{
    return d->spec_active;
}

void ReleaseAnnex::setSpecActive(int specActive)
{
    d->spec_active = specActive;
}

ReleaseAnnex &ReleaseAnnex::operator=(const ReleaseAnnex &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

ReleaseAnnex ReleaseAnnex::create(const QString &lfdnr, const QString &specTitle, const QString &specDesc, const QString &specVersion, const QString &releaseVersion, const QString &specRelease, const QString &objSname, const QString &acClass, const QString &pcClass, const QString &catClass, const QString &country, const QString &lang, const QByteArray &specContent, const QDateTime &specCreated, const QDateTime &specLastModified, const QDateTime &specValidStart, const QDateTime &specValidEnd, const QString &lastEditor, const QString &gLegacy, const QString &responsibility, const QString &specComment, const QString &specMarker, const QString &groups, int specActive)
{
    ReleaseAnnexObject obj;
    obj.lfdnr = lfdnr;
    obj.spec_title = specTitle;
    obj.spec_desc = specDesc;
    obj.spec_version = specVersion;
    obj.release_version = releaseVersion;
    obj.spec_release = specRelease;
    obj.obj_sname = objSname;
    obj.ac_class = acClass;
    obj.pc_class = pcClass;
    obj.cat_class = catClass;
    obj.country = country;
    obj.lang = lang;
    obj.spec_content = specContent;
    obj.spec_created = specCreated;
    obj.spec_last_modified = specLastModified;
    obj.spec_valid_start = specValidStart;
    obj.spec_valid_end = specValidEnd;
    obj.last_editor = lastEditor;
    obj.g_legacy = gLegacy;
    obj.responsibility = responsibility;
    obj.spec_comment = specComment;
    obj.spec_marker = specMarker;
    obj.groups = groups;
    obj.spec_active = specActive;
    if (!obj.create()) {
        return ReleaseAnnex();
    }
    return ReleaseAnnex(obj);
}

ReleaseAnnex ReleaseAnnex::create(const QVariantMap &values)
{
    ReleaseAnnex model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

ReleaseAnnex ReleaseAnnex::get(int id)
{
    TSqlORMapper<ReleaseAnnexObject> mapper;
    return ReleaseAnnex(mapper.findByPrimaryKey(id));
}

int ReleaseAnnex::count()
{
    TSqlORMapper<ReleaseAnnexObject> mapper;
    return mapper.findCount();
}

QList<ReleaseAnnex> ReleaseAnnex::getAll()
{
    return tfGetModelListByCriteria<ReleaseAnnex, ReleaseAnnexObject>(TCriteria());
}

QJsonArray ReleaseAnnex::getAllJson()
{
    QJsonArray array;
    TSqlORMapper<ReleaseAnnexObject> mapper;

    if (mapper.find() > 0) {
        for (TSqlORMapperIterator<ReleaseAnnexObject> i(mapper); i.hasNext(); ) {
            array.append(QJsonValue(QJsonObject::fromVariantMap(ReleaseAnnex(i.next()).toVariantMap())));
        }
    }
    return array;
}

TModelObject *ReleaseAnnex::modelData()
{
    return d.data();
}

const TModelObject *ReleaseAnnex::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const ReleaseAnnex &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, ReleaseAnnex &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(ReleaseAnnex)
