QT += core
QT -= gui

CONFIG += c++11

TARGET = classes
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    vetor.cpp

HEADERS += \
    vetor.h
