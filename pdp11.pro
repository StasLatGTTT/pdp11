QT += widgets

FORMS += config/testwidget.ui

SOURCES += src/*.cc
SOURCES += src/emul/*.cc
SOURCES += src/gui/*.cc

DESTDIR = bin

OBJECTS_DIR = bin/.obj
