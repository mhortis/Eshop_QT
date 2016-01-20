#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QtSql/QtSql"
#include <QString>
#include <QTDebug>
#include <QFileInfo>
#include <QMessageBox>
#include <administratorpanel.h>
#include <customerpanel.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    m_db = DBConnection::getInstance().getDB();
    ui->setupUi(this);
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
        QMessageBox::warning(
                this,
                tr("Eshop"),
                tr("Username and/or Password are invalid") );
    }
    else if(userCount > 1){
        QMessageBox::warning(
                this,
                tr("Eshop"),
                tr("The user exists more than 1 times") );
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
                Cart::getInstance().clearCart();
                this->hide();
                CustomerPanel *customerPanel = new CustomerPanel();
                customerPanel->setCustomer(userDAO.fetchPersonDetailsFromDB(user.getUserID()));
                customerPanel->show();
                break;
            }
            case 2:{
                Cart::getInstance().clearCart();
                this->hide();
                CustomerPanel *customerPanel = new CustomerPanel();
                customerPanel->setCustomer(userDAO.fetchCompanyDetailsFromDB(user.getUserID()));
                customerPanel->show();
                break;
            }
            default:{
                QMessageBox::warning(
                        this,
                        tr("Eshop"),
                        tr("Wrong type of user!") );
                }
        }
    }
}


