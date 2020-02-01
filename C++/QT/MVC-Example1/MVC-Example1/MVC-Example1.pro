TEMPLATE = subdirs

CONFIG += c++11

SUBDIRS += \
    MVC-Example1-lib \
    MVC-Example1-ui

MVC-Example1-ui.depends = MVC-Example1-lib

!build_pass:message(MVC-Example1 project dir: $${PWD})
