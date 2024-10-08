TARGET = model
TEMPLATE = lib
CONFIG += shared c++14 x86_64
QT += sql qml
QT -= gui
DEFINES += TF_DLL
DESTDIR = ../lib
INCLUDEPATH += ../helpers
DEPENDPATH  += ../helpers
LIBS += -L../lib -lhelper
MOC_DIR = .obj/
OBJECTS_DIR = .obj/

include(../appbase.pri)
HEADERS += sqlobjects/standardsdataobject.h
HEADERS += standardsdata.h
SOURCES += standardsdata.cpp
HEADERS += sqlobjects/standardsmetaobject.h
HEADERS += standardsmeta.h
SOURCES += standardsmeta.cpp
HEADERS += sqlobjects/stdsystemobject.h
HEADERS += stdsystem.h
SOURCES += stdsystem.cpp
HEADERS += sqlobjects/webmenuobject.h
HEADERS += webmenu.h
SOURCES += webmenu.cpp
HEADERS += sqlobjects/itisuserobject.h
HEADERS += itisuser.h
SOURCES += itisuser.cpp
HEADERS += sqlobjects/objectsobject.h
HEADERS += objects.h
SOURCES += objects.cpp
HEADERS += sqlobjects/catclassesobject.h
HEADERS += catclasses.h
SOURCES += catclasses.cpp
HEADERS += sqlobjects/acclassesobject.h
HEADERS += acclasses.h
SOURCES += acclasses.cpp
HEADERS += sqlobjects/pcclassesobject.h
HEADERS += pcclasses.h
SOURCES += pcclasses.cpp
HEADERS += sqlobjects/standardsdatawasteobject.h
HEADERS += standardsdatawaste.h
SOURCES += standardsdatawaste.cpp
HEADERS += sqlobjects/standardsmetawasteobject.h
HEADERS += standardsmetawaste.h
SOURCES += standardsmetawaste.cpp
HEADERS += sqlobjects/annexdataobject.h
HEADERS += annexdata.h
SOURCES += annexdata.cpp
HEADERS += sqlobjects/annexmetaobject.h
HEADERS += annexmeta.h
SOURCES += annexmeta.cpp
HEADERS += sqlobjects/annexdatawasteobject.h
HEADERS += annexdatawaste.h
SOURCES += annexdatawaste.cpp
HEADERS += sqlobjects/annexmetawasteobject.h
HEADERS += annexmetawaste.h
SOURCES += annexmetawaste.cpp
HEADERS += sqlobjects/glossarobject.h
HEADERS += glossar.h
SOURCES += glossar.cpp
HEADERS += sqlobjects/standardsdatacommentsobject.h
HEADERS += standardsdatacomments.h
SOURCES += standardsdatacomments.cpp
HEADERS += sqlobjects/appvarsobject.h
HEADERS += appvars.h
SOURCES += appvars.cpp
HEADERS += sqlobjects/itisnewsobject.h
HEADERS += itisnews.h
SOURCES += itisnews.cpp
HEADERS += sqlobjects/actionrightsobject.h
HEADERS += actionrights.h
SOURCES += actionrights.cpp
HEADERS += sqlobjects/itisgroupsobject.h
HEADERS += itisgroups.h
SOURCES += itisgroups.cpp
HEADERS += sqlobjects/annexdatacommentsobject.h
HEADERS += annexdatacomments.h
SOURCES += annexdatacomments.cpp
HEADERS += sqlobjects/releasemgmtobject.h
HEADERS += releasemgmt.h
SOURCES += releasemgmt.cpp
HEADERS += sqlobjects/releaseannexobject.h
HEADERS += releaseannex.h
SOURCES += releaseannex.cpp
HEADERS += sqlobjects/lenkinfoobject.h
HEADERS += lenkinfo.h
SOURCES += lenkinfo.cpp
