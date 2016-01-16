#include "customerpanel.h"
#include "ui_customerpanel.h"
#include "logoutdialog.h"
#include <QStringList>

CustomerPanel::CustomerPanel(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CustomerPanel)
{
    setAttribute( Qt::WA_DeleteOnClose );
    ui->setupUi(this);
    m_db = DBConnection::getInstance().getDB();
}

CustomerPanel::~CustomerPanel()
{
    delete ui;
}

int CustomerPanel::getPanelType(){
    return panelType;
}

void CustomerPanel::on_actionLogout_triggered()
{
    this->close();
    LogoutDialog *logout = new LogoutDialog(this->getPanelType());
    logout->show();
}

void CustomerPanel::on_actionList_Products_triggered()
{


}
