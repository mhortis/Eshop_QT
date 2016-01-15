#include "addcompanyform.h"
#include "ui_addcompanyform.h"

AddCompanyForm::AddCompanyForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddCompanyForm)
{
    ui->setupUi(this);
}

AddCompanyForm::~AddCompanyForm()
{
    delete ui;
}
