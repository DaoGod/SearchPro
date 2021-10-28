QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_mytests.cpp

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../searchfolderLibrary/release/ -lsearchfolderLibrary
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../searchfolderLibrary/debug/ -lsearchfolderLibrary
else:unix: LIBS += -L$$OUT_PWD/../searchfolderLibrary/ -lsearchfolderLibrary

INCLUDEPATH += $$PWD/../searchfolderLibrary
DEPENDPATH += $$PWD/../searchfolderLibrary
