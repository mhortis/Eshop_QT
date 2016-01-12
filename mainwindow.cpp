#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName=("eshop_db");

    if(!db.open()){
        ui->label->setText("Failed to open the database");
    }else{
        ui->label->setText("Please Login...");
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setLabel(std::string text){
    //ui->label->setText(QString::fromStdString(text));
}

void MainWindow::on_loginButton_clicked()
{
    QString username,password;
    username=ui->textUser->text();
    password=ui->textPass->text();

    if(!db.open()){
        qDebug()<<"Failed to open the database";
        return;
    }

    QSqlQuery query;



}

