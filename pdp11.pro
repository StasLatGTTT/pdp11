QT += widgets core gui

SOURCES += src/*.cc
SOURCES += src/emul/*.cc
SOURCES += src/gui/*.cc
SOURCES += src/gui/mainwindow.cpp

DESTDIR = bin

OBJECTS_DIR = bin/.obj

QMAKE_CXXFLAGS += -std=c++11 -g -O1

FORMS += config/mainwindow.ui

UI_DIR = src/gui
