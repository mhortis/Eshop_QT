#include "customerproductlist.h"
#include "ui_customerproductlist.h"

CustomerProductList::CustomerProductList(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CustomerProductList)
{
    ui->setupUi(this);


}

CustomerProductList::~CustomerProductList()
{
    delete ui;
}
