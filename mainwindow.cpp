#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QtSql/QtSql"
#include <QString>
#include <QTDebug>
#include <QFileInfo>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    //db.setDatabaseName=("eshop_db");

    if(!db.open()){
        ui->statusLabel->setText("Failed to open the database");
    }else{
        ui->statusLabel->setText("Please Login...");
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_loginButton_clicked()
{
    QString username,password;
    username=ui->textUser->toPlainText();
    password=ui->textPass->toPlainText();

    if(!db.open()){
        qDebug()<<"Failed to open the database";
        return;
    }

    QSqlQuery query;



}

