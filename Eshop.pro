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
    OrderDAO.cpp \
    Order.cpp \
    PC.cpp \
    Person.cpp \
    ProductBase.cpp \
    ProductDAO.cpp \
    Smartphone.cpp \
    TV.cpp \
    UserBase.cpp \
    UserDAO.cpp \
    administratorpanel.cpp \
    customerpanel.cpp \
    maindocl.cpp \
    centralwidget.cpp \
    logoutdialog.cpp \
    customerorcompany.cpp \
    addcompanyform.cpp \
    addcustomerform.cpp \
    tvorsmartphoneorpc.cpp \
    addtvform.cpp \
    addpcform.cpp \
    addsmartphoneform.cpp \
    DBConnection.cpp \
    adminlistproducts.cpp \
    categoryormanufacturerorall.cpp \
    customerproductlist.cpp \
    updatetv.cpp \
    updatepc.cpp \
    updatesmartphone.cpp \
    adminlistcustomers.cpp

HEADERS  += mainwindow.h \
    Administrator.h \
    Availability.h \
    Company.h \
    Customer.h \
    OrderDAO.h \
    Order.h \
    PC.h \
    Person.h \
    ProductBase.h \
    ProductDAO.h \
    Smartphone.h \
    TV.h \
    UserBase.h \
    UserDAO.h \
    stdafx.h \
    administratorpanel.h \
    customerpanel.h \
    maindocl.h \
    centralwidget.h \
    logoutdialog.h \
    customerorcompany.h \
    addcompanyform.h \
    addcustomerform.h \
    tvorsmartphoneorpc.h \
    addtvform.h \
    addpcform.h \
    addsmartphoneform.h \
    DBConnection.h \
    adminlistproducts.h \
    categoryormanufacturerorall.h \
    customerproductlist.h \
    updatetv.h \
    updatepc.h \
    updatesmartphone.h \
    adminlistcustomers.h

FORMS    += mainwindow.ui \
    administratorpanel.ui \
    customerpanel.ui \
    maindocl.ui \
    centralwidget.ui \
    logoutdialog.ui \
    customerorcompany.ui \
    addcompanyform.ui \
    addcustomerform.ui \
    tvorsmartphoneorpc.ui \
    addtvform.ui \
    addpcform.ui \
    addsmartphoneform.ui \
    adminlistproducts.ui \
    categoryormanufacturerorall.ui \
    customerproductlist.ui \
    updatetv.ui \
    updatepc.ui \
    updatesmartphone.ui \
    adminlistcustomers.ui
QT += sql

DISTFILES += \
    Eshop.pro.user
