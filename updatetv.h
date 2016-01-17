#ifndef UPDATETV_H
#define UPDATETV_H

#include "dbconnection.h"
#include <QDialog>
#include "TV.h"
#include "ProductDAO.h"

namespace Ui {
class UpdateTV;
}

class UpdateTV : public QDialog
{
    Q_OBJECT

public:
    explicit UpdateTV(QWidget *parent = 0);
    void setProduct(ProductBase prod, int availability);
    void showProduct();
    ~UpdateTV();

private slots:
    void on_updateButton_clicked();

    void on_cancelButton_clicked();

    void on_removeButton_clicked();

private:
    Ui::UpdateTV *ui;
    ProductBase product;
    TV tv;
    int availability;
    QSqlDatabase m_db;
};

#endif // UPDATETV_H
