#ifndef ADDCOMPANYFORM_H
#define ADDCOMPANYFORM_H

#include <QDialog>
#include "dbconnection.h"
namespace Ui {
class AddCompanyForm;
}

class AddCompanyForm : public QDialog
{
    Q_OBJECT

public:
    explicit AddCompanyForm(QWidget *parent = 0);
    ~AddCompanyForm();

private slots:


    void on_cancelButton_clicked();

    void on_saveButton_clicked();

private:
    Ui::AddCompanyForm *ui;
};

#endif // ADDCOMPANYFORM_H
