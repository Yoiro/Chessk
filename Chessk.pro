#-------------------------------------------------
#
# Project created by QtCreator 2017-08-27T23:58:36
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Chessk
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    Models/board.cpp \
    Models/case.cpp \
    config/boardconfig.cpp \
    Models/engine/move.cpp \
    Models/engine/negamax.cpp \
    Models/piece/bishop.cpp \
    Models/piece/king.cpp \
    Models/piece/knight.cpp \
    Models/piece/pawn.cpp \
    Models/piece/piece.cpp \
    Models/piece/queen.cpp \
    Models/piece/rook.cpp \
    Models/util/direction.cpp \
    Models/util/jsonreader.cpp

HEADERS += \
        mainwindow.h \
    Models/board.h \
    Models/case.h \
    Models/engine/move.h \
    Models/engine/negamax.h \
    Models/piece/bishop.h \
    Models/piece/king.h \
    Models/piece/knight.h \
    Models/piece/pawn.h \
    Models/piece/piece.h \
    Models/piece/queen.h \
    Models/piece/rook.h \
    Models/util/direction.h \
    Models/util/jsonreader. \
    config/resourcesconfig.hpp \
    config/configuration.hpp \
    jsonreader.hpp \
    res/resourcemanager.hpp \
    config/boardconfig.hpp \
    util/position.hpp \
    util/utilities.hpp \
    util/direction.hpp

FORMS += \
        mainwindow.ui

DISTFILES += \
    res/img/board/board.jpg \
    res/img/pieces/gold/bishop.png \
    res/img/pieces/gold/king.png \
    res/img/pieces/gold/knight.png \
    res/img/pieces/gold/Pawn.png \
    res/img/pieces/gold/queen.png \
    res/img/pieces/gold/rook.png \
    res/img/pieces/green/bishop.png \
    res/img/pieces/green/king.png \
    res/img/pieces/green/knight.png \
    res/img/pieces/green/pawn.png \
    res/img/pieces/green/queen.png \
    res/img/pieces/green/rook.png
