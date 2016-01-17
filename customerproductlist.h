#ifndef CUSTOMERPRODUCTLIST_H
#define CUSTOMERPRODUCTLIST_H

#include <QDialog>
#include <QSqlDatabase>
#include "Availability.h"

namespace Ui {
class CustomerProductList;
}

class CustomerProductList : public QDialog
{
    Q_OBJECT

public:
    explicit CustomerProductList(QWidget *parent = 0);
    ~CustomerProductList();

private slots:
    void on_showAll_clicked();
    void on_showTVs_clicked();
    void on_showPCs_clicked();
    void on_showSmPhones_clicked();
    void on_comboBox_activated(const QString &arg1);

private:
    Ui::CustomerProductList *ui;
    vector<Availability> products;
    vector<string> manufacturers;
    QSqlDatabase m_db;
};

#endif // CUSTOMERPRODUCTLIST_H
