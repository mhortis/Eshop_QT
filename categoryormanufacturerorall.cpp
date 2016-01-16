#include "categoryormanufacturerorall.h"
#include "ui_categoryormanufacturerorall.h"
#include "adminlistproducts.h"

CategoryOrManufacturerOrAll::CategoryOrManufacturerOrAll(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CategoryOrManufacturerOrAll)
{
    ui->setupUi(this);
}

CategoryOrManufacturerOrAll::~CategoryOrManufacturerOrAll()
{
    delete ui;
}

void CategoryOrManufacturerOrAll::on_showAll_clicked()
{

}
