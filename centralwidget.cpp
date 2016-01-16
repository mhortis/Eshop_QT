#include "centralwidget.h"
#include "ui_centralwidget.h"

CentralWidget::CentralWidget(QWidget *parent) :
    QDockWidget(parent),
    ui(new Ui::CentralWidget)
{
    ui->setupUi(this);
    m_db = DBConnection::getInstance().getDB();
}

CentralWidget::~CentralWidget()
{
    delete ui;
}
