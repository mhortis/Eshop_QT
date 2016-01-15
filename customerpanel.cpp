#include "customerpanel.h"
#include "ui_customerpanel.h"
#include "logoutdialog.h"
CustomerPanel::CustomerPanel(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CustomerPanel)
{
    setAttribute( Qt::WA_DeleteOnClose );
    ui->setupUi(this);
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
