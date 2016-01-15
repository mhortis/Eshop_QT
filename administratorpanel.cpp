#include "administratorpanel.h"
#include "ui_administratorpanel.h"
#include "LogoutDialog.h"
#include "customerorcompany.h"

AdministratorPanel::AdministratorPanel(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AdministratorPanel)
{
    setAttribute(Qt::WA_DeleteOnClose);
    ui->setupUi(this);
}

AdministratorPanel::~AdministratorPanel()
{
    delete ui;
}

int AdministratorPanel::getPanelType(){
    return panelType;
}

/*void AdministratorPanel::createAddUserForm()
{
    QGroupBox *formGroupBox = new QGroupBox(tr("Form layout"));
    QFormLayout *layout = new QFormLayout;
    layout->addRow(new QLabel(tr("Line 1:")), new QLineEdit);
    layout->addRow(new QLabel(tr("Line 2, long text:")), new QComboBox);
    layout->addRow(new QLabel(tr("Line 3:")), new QSpinBox);
    formGroupBox->setLayout(layout);
}*/

void AdministratorPanel::on_actionCustomers_triggered()
{
   // createAddUserForm();
    QGroupBox *formGroupBox = new QGroupBox(tr("Form layout"));
    QFormLayout *layout = new QFormLayout;
    layout->addRow(new QLabel(tr("Line 1:")), new QLineEdit);
    layout->addRow(new QLabel(tr("Line 2, long text:")), new QComboBox);
    layout->addRow(new QLabel(tr("Line 3:")), new QSpinBox);
    formGroupBox->setLayout(layout);
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
