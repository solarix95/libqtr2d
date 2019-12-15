######################################################################
# Automatically generated by qmake (3.1) Tue Nov 19 21:02:12 2019
######################################################################

TEMPLATE     = app
TARGET       = minigame4_submarine
INCLUDEPATH += .
CONFIG      += debug

include(../../libpixelschlacht/libpixelschlacht.pro)

DEFINES += QT_DEPRECATED_WARNINGS

# Input
SOURCES += \
    main.cc \
    gamezone.cc  \
    gamemap.cc \
    background.cc \
    submarine.cc \
    gamewidget.cc \
    bubble.cc

HEADERS += \
    gamezone.h   \
    gamemap.h    \
    background.h \
    submarine.h  \
    gamewidget.h \
    bubble.h

RESOURCES += \
    submarine.qrc
