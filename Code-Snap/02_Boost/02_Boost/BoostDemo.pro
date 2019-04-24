TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp
INCLUDEPATH+=/home/xuqi/boost_1_69_0/
CFLAGS = -std=gnu++0x
LIBS += -L/home/xuqi/boost_1_69_0/stage/lib

