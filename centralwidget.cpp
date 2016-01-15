#include "centralwidget.h"
#include "ui_centralwidget.h"

CentralWidget::CentralWidget(QWidget *parent) :
    QDockWidget(parent),
    ui(new Ui::CentralWidget)
{
    ui->setupUi(this);
}

CentralWidget::~CentralWidget()
{
    delete ui;
}
