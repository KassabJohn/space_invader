TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

#WINDOWS
# put SFML file in the same location as project
LIBS += -L"..\SFML-2.5.1\lib" #change this
LIBS += -L"..\SFML-2.5.1\bin" #change this

#MAC
#LIBS += -L"/usr/local/lib"

CONFIG(release, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-system -lsfml-network -lsfml-window
CONFIG(debug  , debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-system -lsfml-network -lsfml-window

#WINDOWS
INCLUDEPATH += "..\SFML-2.5.1\include"
DEPENDPATH += "..\SFML-2.5.1\include"

SOURCES += \
        bullet.cpp \
        enemy.cpp \
        game.cpp \
        main.cpp \
        player.cpp

HEADERS += \
    bullet.h \
    enemy.h \
    game.h \
    player.h
