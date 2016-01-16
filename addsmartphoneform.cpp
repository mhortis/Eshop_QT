#include "addsmartphoneform.h"
#include "ui_addsmartphoneform.h"

AddSmartphoneForm::AddSmartphoneForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddSmartphoneForm)
{
    ui->setupUi(this);
}

AddSmartphoneForm::~AddSmartphoneForm()
{
    delete ui;
}
