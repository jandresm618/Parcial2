TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        balistica.cpp \
        escenario.cpp \
        main.cpp \
        movimiento.cpp \
        proyectil.cpp

HEADERS += \
    balistica.h \
    escenario.h \
    movimiento.h \
    proyectil.h
