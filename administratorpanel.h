#ifndef ADMINISTRATORPANEL_H
#define ADMINISTRATORPANEL_H

#include <QMainWindow>
#include <QFormLayout>
#include <QGroupBox>
#include <QLineEdit>
#include <QComboBox>
#include <QSpinBox>
#include <QLAbel>
#include "dbconnection.h"

namespace Ui {
class AdministratorPanel;
}

class AdministratorPanel : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdministratorPanel(QWidget *parent = 0);
    void createAddUserForm();
    void logout_yes();
    void logout_no();
    ~AdministratorPanel();

private slots:
    void on_actionCustomers_triggered();

    void on_actionLogout_triggered();
    int getPanelType();
    void on_actionAdd_User_triggered();

    void on_actionAdd_Product_triggered();

    void on_actionUpdate_Product_triggered();

private:
    Ui::AdministratorPanel *ui;
    int panelType = 1;
    QSqlDatabase m_db;
};

#endif // ADMINISTRATORPANEL_H
