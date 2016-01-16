#ifndef ADDCUSTOMERFORM_H
#define ADDCUSTOMERFORM_H

#include <QDialog>
#include "dbconnection.h"

namespace Ui {
class AddCustomerForm;
}

class AddCustomerForm : public QDialog
{
    Q_OBJECT

public:
    explicit AddCustomerForm(QWidget *parent = 0);
    ~AddCustomerForm();

private slots:
    void on_cancelButton_clicked();

    void on_saveButton_clicked();

private:
    Ui::AddCustomerForm *ui;
    QSqlDatabase m_db;
};

#endif // ADDCUSTOMERFORM_H
