#ifndef UPDATESMARTPHONE_H
#define UPDATESMARTPHONE_H

#include "dbconnection.h"
#include <QDialog>
#include "Smartphone.h"
#include "ProductDAO.h"

namespace Ui {
class UpdateSmartphone;
}

class UpdateSmartphone : public QDialog
{
    Q_OBJECT

public:
    explicit UpdateSmartphone(QWidget *parent = 0);
    void setProduct(ProductBase prod, int availability);
    void showProduct();
    ~UpdateSmartphone();

private slots:
    void on_updateButton_clicked();

    void on_cancelButton_clicked();

    void on_removeButton_clicked();

private:
    Ui::UpdateSmartphone *ui;
    ProductBase product;
    Smartphone smartphone;
    int availability;
    QSqlDatabase m_db;
};

#endif // UPDATESMARTPHONE_H
