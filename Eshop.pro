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
    customerproductlist.cpp \
    updatetv.cpp \
    updatepc.cpp \
    updatesmartphone.cpp \
    neworder.cpp \
    customerorders.cpp \
    customerorder.cpp \
    adminlistcustomers.cpp \
    cart.cpp \
    operationcycle.cpp \
    showcart.cpp \
    orderspercustomer.cpp \
    orderslistandupdate.cpp \
    ordersperstatus.cpp

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
    customerproductlist.h \
    updatetv.h \
    updatepc.h \
    updatesmartphone.h \
    neworder.h \
    customerorders.h \
    customerorder.h \
    adminlistcustomers.h \
    cart.h \
    operationcycle.h \
    showcart.h \
    orderspercustomer.h \
    orderslistandupdate.h \
    ordersperstatus.h

FORMS    += mainwindow.ui \
    administratorpanel.ui \
    customerpanel.ui \
    maindocl.ui \
    logoutdialog.ui \
    customerorcompany.ui \
    addcompanyform.ui \
    addcustomerform.ui \
    tvorsmartphoneorpc.ui \
    addtvform.ui \
    addpcform.ui \
    addsmartphoneform.ui \
    adminlistproducts.ui \
    customerproductlist.ui \
    updatetv.ui \
    updatepc.ui \
    updatesmartphone.ui \
    neworder.ui \
    customerorders.ui \
    customerorder.ui \
    adminlistcustomers.ui \
    operationcycle.ui \
    showcart.ui \
    orderspercustomer.ui \
    orderslistandupdate.ui \
    ordersperstatus.ui

QT += sql

DISTFILES += \
    Eshop.pro.user
