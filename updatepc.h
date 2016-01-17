#ifndef UPDATEPC_H
#define UPDATEPC_H

#include "dbconnection.h"
#include <QDialog>
#include "PC.h"
#include "ProductDAO.h"

namespace Ui {
class UpdatePC;
}

class UpdatePC : public QDialog
{
    Q_OBJECT

public:
    explicit UpdatePC(QWidget *parent = 0);
    void setProduct(ProductBase prod, int availability);
    void showProduct();
    ~UpdatePC();

private slots:
    void on_updateButton_clicked();

    void on_cancelButton_clicked();

    void on_removeButton_clicked();

private:
    Ui::UpdatePC *ui;
    ProductBase product;
    PC pc;
    int availability;
    QSqlDatabase m_db;
};

#endif // UPDATEPC_H
