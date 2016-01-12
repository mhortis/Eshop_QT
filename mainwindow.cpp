#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QtSql/QtSql"
#include <QString>
#include <QTDebug>
#include <QFileInfo>
#include <administratorpanel.h>
#include <customerpanel.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QSqlDatabase m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    //m_db.setDatabaseName( QDir::homePath() + QDir::separator() + "eshop.db");
    m_db.setDatabaseName( "./eshop.db");

    if(!m_db.open()){
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
    username=ui->textUser->text();
    password=ui->textPass->text();

    if(!m_db.open()){
        qDebug()<<"Failed to open the database";
        return;
    }

    QSqlQuery query;
    query.prepare("select * from USERS where USERNAME='"+username+"' and PASSWORD='"+password+"'");
    //query.addBindValue(serial);

    if(query.exec()){
        int count=0;
        while(query.next()){
            count++;
        }

        if(count==1){
          switch(query.value(query.record().indexOf("TYPE")).toInt()){
            case 0:{
                this->hide();
                AdministratorPanel *adminPanel=  new AdministratorPanel();
                adminPanel->show();
            }
            case 1:{
                this->hide();
                CustomerPanel *customerPanel = new CustomerPanel();
                customerPanel->show();
            }
            default:{
                ui->statusLabel->setText("Wrong type of user!");
            }
          }
        }else if(count>1){
            ui->statusLabel->setText("The user exists more than 1 times");
        }else{
            ui->statusLabel->setText("Username and/or Password are invalid");
        }
    }


}

