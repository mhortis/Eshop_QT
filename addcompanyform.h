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

private:
    Ui::AddCompanyForm *ui;
};

#endif // ADDCOMPANYFORM_H
