#include "addtvform.h"
#include "ui_addtvform.h"

AddTvForm::AddTvForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddTvForm)
{
    ui->setupUi(this);
}

AddTvForm::~AddTvForm()
{
    delete ui;
}

void AddTvForm::on_cancelButton_clicked()
{
    this->hide();
}
