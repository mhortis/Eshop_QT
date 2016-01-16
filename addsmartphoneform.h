#ifndef ADDSMARTPHONEFORM_H
#define ADDSMARTPHONEFORM_H

#include <QDialog>
#include "dbconnection.h"

namespace Ui {
class AddSmartphoneForm;
}

class AddSmartphoneForm : public QDialog
{
    Q_OBJECT

public:
    explicit AddSmartphoneForm(QWidget *parent = 0);
    ~AddSmartphoneForm();

private slots:
    void on_cancelButton_clicked();

private:
    Ui::AddSmartphoneForm *ui;
    QSqlDatabase m_db;
};

#endif // ADDSMARTPHONEFORM_H
