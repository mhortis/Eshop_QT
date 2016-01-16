#include "addpcform.h"
#include "ui_addpcform.h"

AddPcForm::AddPcForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddPcForm)
{
    ui->setupUi(this);
}

AddPcForm::~AddPcForm()
{
    delete ui;
}

void AddPcForm::on_cancelButton_clicked()
{
    this->hide();
}
