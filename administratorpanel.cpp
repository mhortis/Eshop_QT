#include "administratorpanel.h"
#include "ui_administratorpanel.h"
#include "LogoutDialog.h"
#include "customerorcompany.h"
#include "tvorsmartphoneorpc.h"
#include "adminlistproducts.h"
#include "adminlistcustomers.h"
#include "operationcycle.h"

AdministratorPanel::AdministratorPanel(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AdministratorPanel)
{
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
    CustomerOrCompany coc;
    coc.exec();
}

void AdministratorPanel::on_actionAdd_Product_triggered()
{
    TvOrSmartphoneOrPc tsp;
    tsp.exec();
}

void AdministratorPanel::on_actionUpdate_Product_triggered()
{
    AdminListProducts adminListP;
    adminListP.exec();
}

void AdministratorPanel::on_actionCalculation_triggered()
{
    operationCycle showOC;
    showOC.exec();
}

void AdministratorPanel::on_actionView_Per_Customer_triggered()
{
    OrderDAO orderDAO(m_db);
    vector<int> customers = orderDAO.fetchCustomerIDsWithOrders();
    OrdersPerCustomer ordersPerCustomer;
    ordersPerCustomer.setCustomers(customers);
    ordersPerCustomer.showCustomers();
    ordersPerCustomer.exec();
}

void AdministratorPanel::on_actionView_Per_Status_triggered()
{
    OrdersPerStatus ordersPerStatus;
    ordersPerStatus.exec();
}
