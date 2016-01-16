#ifndef CUSTOMERPRODUCTLIST_H
#define CUSTOMERPRODUCTLIST_H

#include <QDialog>

namespace Ui {
class CustomerProductList;
}

class CustomerProductList : public QDialog
{
    Q_OBJECT

public:
    explicit CustomerProductList(QWidget *parent = 0);
    ~CustomerProductList();

private:
    Ui::CustomerProductList *ui;
};

#endif // CUSTOMERPRODUCTLIST_H
