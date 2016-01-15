#include "maindocl.h"
#include "ui_maindocl.h"

MainDocl::MainDocl(QWidget *parent) :
    QDockWidget(parent),
    ui(new Ui::MainDocl)
{
    ui->setupUi(this);
}

MainDocl::~MainDocl()
{
    delete ui;
}
