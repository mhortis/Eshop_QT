#include "addsmartphoneform.h"
#include "ui_addsmartphoneform.h"

AddSmartphoneForm::AddSmartphoneForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddSmartphoneForm)
{
    ui->setupUi(this);
    m_db = DBConnection::getInstance().getDB();
}

AddSmartphoneForm::~AddSmartphoneForm()
{
    delete ui;
}
