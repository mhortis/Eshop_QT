#-------------------------------------------------
#
# Project created by QtCreator 2016-01-11T13:58:10
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Eshop
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    Administrator.cpp \
    Availability.cpp \
    Company.cpp \
    Customer.cpp \
    Order.cpp \
    PC.cpp \
    Person.cpp \
    ProductBase.cpp \
    ProductDAO.cpp \
    Smartphone.cpp \
    TV.cpp \
    UserBase.cpp \
    UserDAO.cpp

HEADERS  += mainwindow.h \
    Administrator.h \
    Availability.h \
    Company.h \
    Customer.h \
    Order.h \
    PC.h \
    Person.h \
    ProductBase.h \
    ProductDAO.h \
    Smartphone.h \
    TV.h \
    UserBase.h \
    UserDAO.h \
    stdafx.h

FORMS    += mainwindow.ui
QT += sql

DISTFILES += \
    Eshop.pro.user
