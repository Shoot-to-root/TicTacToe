QT += core
QT -= gui

CONFIG += c++11

TARGET = TTT
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    com.cpp \
    player.cpp

HEADERS += \
    com.h \
    player.h
