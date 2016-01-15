#ifndef CUSTOMERORCOMPANY_H
#define CUSTOMERORCOMPANY_H

#include <QDialog>

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
};

#endif // CUSTOMERORCOMPANY_H
