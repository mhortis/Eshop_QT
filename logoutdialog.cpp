#include "logoutdialog.h"
#include "ui_logoutdialog.h"
//#include <QApplication>
#include <administratorpanel.h>
#include <customerpanel.h>
#include <QMessageBox>
#include <QDebug>
#include "mainwindow.h"

LogoutDialog::LogoutDialog(int panelType, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LogoutDialog)
{
    setAttribute( Qt::WA_DeleteOnClose );
    ui->setupUi(this);
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Logout ", "Are you sure you want to logout?",
                                  QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes) {
      qDebug() << "Logged out";
      this->close();
      MainWindow *mainW = new MainWindow();
      mainW->show();
    } else {
      qDebug() << "Not logged out";
      this->close();
      if (panelType==1){
          AdministratorPanel *adminPanel=  new AdministratorPanel();
          adminPanel->show();
      }else{
          CustomerPanel *customerPanel=  new CustomerPanel();
          customerPanel->show();
      }
    }
}

LogoutDialog::~LogoutDialog()
{
    delete ui;
}


