QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_filesearchertest.cpp

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../file_search/release/ -lfile_search
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../file_search/debug/ -lfile_search
else:unix: LIBS += -L$$OUT_PWD/../file_search/ -lfile_search

INCLUDEPATH += $$PWD/../file_search
DEPENDPATH += $$PWD/../file_search
