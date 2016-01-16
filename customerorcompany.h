#ifndef CUSTOMERORCOMPANY_H
#define CUSTOMERORCOMPANY_H

#include <QDialog>
#include "dbconnection.h"

namespace Ui {
class CustomerOrCompany;
}

class CustomerOrCompany : public QDialog
{
    Q_OBJECT

public:
    explicit CustomerOrCompany(QWidget *parent = 0);
    ~CustomerOrCompany();

private slots:

    void on_addCompany_clicked();
    void on_addCustomer_clicked();

private:
    Ui::CustomerOrCompany *ui;
    QSqlDatabase m_db;
};

#endif // CUSTOMERORCOMPANY_H
