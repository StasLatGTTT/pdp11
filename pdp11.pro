QT += core gui widgets

TEMPLATE = app

SOURCES += src/main.cc
SOURCES += src/emul/*.cc
SOURCES += src/gui/*.cc

HEADERS += src/gui/*.h

DESTDIR = bin
MOC_DIR = src/gui
OBJECTS_DIR = bin/.obj

QMAKE_CXXFLAGS += -std=c++11 -g -O1

FORMS += config/mainwindow.ui

UI_DIR = src/gui
