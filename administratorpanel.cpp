#include "administratorpanel.h"
#include "ui_administratorpanel.h"
#include "LogoutDialog.h"
#include "customerorcompany.h"
#include "tvorsmartphoneorpc.h"
#include "adminlistproducts.h"
#include "adminlistcustomers.h"

AdministratorPanel::AdministratorPanel(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AdministratorPanel)
{
    setAttribute(Qt::WA_DeleteOnClose);
    ui->setupUi(this);
    m_db = DBConnection::getInstance().getDB();
}

AdministratorPanel::~AdministratorPanel()
{
    delete ui;
}

int AdministratorPanel::getPanelType(){
    return panelType;
}

void AdministratorPanel::on_actionCustomers_triggered()
{
    AdminListCustomers customerList;
    customerList.setModal(true);
    customerList.exec();
}

void AdministratorPanel::on_actionLogout_triggered()
{
    this->close();
    LogoutDialog *logout = new LogoutDialog(this->getPanelType());
    logout->show();
}


void AdministratorPanel::on_actionAdd_User_triggered()
{
    CustomerOrCompany *coc = new CustomerOrCompany();
    coc->show();
}

void AdministratorPanel::on_actionAdd_Product_triggered()
{
    TvOrSmartphoneOrPc *tsp = new TvOrSmartphoneOrPc();
    tsp->show();
}

void AdministratorPanel::on_actionUpdate_Product_triggered()
{
    AdminListProducts adminListP;
    adminListP.setModal(true);
    adminListP.exec();
}
