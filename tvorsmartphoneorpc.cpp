#include "tvorsmartphoneorpc.h"
#include "ui_tvorsmartphoneorpc.h"
#include "addpcform.h"
#include "addsmartphoneform.h"
#include "addtvform.h"

TvOrSmartphoneOrPc::TvOrSmartphoneOrPc(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TvOrSmartphoneOrPc)
{
    ui->setupUi(this);
}

TvOrSmartphoneOrPc::~TvOrSmartphoneOrPc()
{
    delete ui;
}

void TvOrSmartphoneOrPc::on_addTV_clicked()
{
    this->hide();
    AddTvForm addTv;
    addTv.setModal(true);
    addTv.exec();
}

void TvOrSmartphoneOrPc::on_addSmartphone_clicked()
{
    this->hide();
    AddSmartphoneForm addSmartPhone;
    addSmartPhone.setModal(true);
    addSmartPhone.exec();

}

void TvOrSmartphoneOrPc::on_addPC_clicked()
{
    this->hide();
    AddPcForm addPc;
    addPc.setModal(true);
    addPc.exec();
}
