#ifndef ADMINLISTPRODUCTS_H
#define ADMINLISTPRODUCTS_H
#include "dbconnection.h"
#include <QDialog>
#include "ProductDAO.h"
#include "ProductBase.h"
#include "updatetv.h"
#include "updatepc.h"
#include "updatesmartphone.h"

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

    void on_table_doubleClicked(const QModelIndex &index);

private:
    Ui::AdminListProducts *ui;
    vector<Availability> products;
    QSqlDatabase m_db;
};

#endif // ADMINLISTPRODUCTS_H
