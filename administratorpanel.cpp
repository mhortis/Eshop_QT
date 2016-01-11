#include "administratorpanel.h"
#include "ui_administratorpanel.h"

AdministratorPanel::AdministratorPanel(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AdministratorPanel)
{
    ui->setupUi(this);
}

AdministratorPanel::~AdministratorPanel()
{
    delete ui;
}
