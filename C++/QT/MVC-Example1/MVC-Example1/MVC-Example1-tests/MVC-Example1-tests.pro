QT += testlib
QT -= gui

TARGET = MVC-Example1_tests

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle
CONFIG += c++14

TEMPLATE = app

INCLUDEPATH += source
SOURCES +=  source/models/client_tests.cpp
