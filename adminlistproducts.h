#ifndef ADMINLISTPRODUCTS_H
#define ADMINLISTPRODUCTS_H
#include "dbconnection.h"
#include <QDialog>

namespace Ui {
class AdminListProducts;
}

class AdminListProducts : public QDialog
{
    Q_OBJECT

public:
    explicit AdminListProducts(QWidget *parent = 0);
    void listAllProducts();
    void listPerCategory(int type=1);
    void listPerManufacturer(const char* manufacturer);
    ~AdminListProducts();

private slots:

private:
    Ui::AdminListProducts *ui;
    QSqlDatabase m_db;
};

#endif // ADMINLISTPRODUCTS_H
