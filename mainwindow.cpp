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
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    QDir dir = QDir::currentPath();
    QString dbPath =  dir.canonicalPath() + "/eshop.db";
    m_db.setDatabaseName( dbPath);
    //m_db.setDatabaseName( "./eshop.db");

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

    if(!m_db.isOpen()){
        qDebug()<<"Failed to open the database";
        return;
    }

    UserDAO userDAO = UserDAO(m_db);
    int userCount = userDAO.userExistsInDB(username.toStdString(), password.toStdString());

    if(userCount <= 0){
        ui->statusLabel->setText("Username and/or Password are invalid");
    }
    else if(userCount > 1){
        ui->statusLabel->setText("The user exists more than 1 times");
    }
    else{
        UserBase user = userDAO.fetchUserByUsernamePwdFromDB(username.toStdString(), password.toStdString());
        switch(user.getType()){
            case 0:{
                this->hide();
                AdministratorPanel *adminPanel=  new AdministratorPanel();
                adminPanel->show();
                break;
            }
            case 1:{
                this->hide();
                CustomerPanel *customerPanel = new CustomerPanel();
                customerPanel->show();
                break;
            }
            default:{
                ui->statusLabel->setText("Wrong type of user!");
            }
        }
    }
}

