#include "maindocl.h"
#include "ui_maindocl.h"

MainDocl::MainDocl(QWidget *parent) :
    QDockWidget(parent),
    ui(new Ui::MainDocl)
{
    ui->setupUi(this);
    m_db = DBConnection::getInstance().getDB();
}

MainDocl::~MainDocl()
{
    delete ui;
}
