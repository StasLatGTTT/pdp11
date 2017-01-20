QT += widgets

SOURCES += src/*.cc
SOURCES += src/emul/*.cc
SOURCES += src/gui/*.cc

DESTDIR = bin

OBJECTS_DIR = bin/.obj

QMAKE_CXXFLAGS += -std=c++11 -g -O1
