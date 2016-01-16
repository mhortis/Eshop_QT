#ifndef CATEGORYORMANUFACTURERORALL_H
#define CATEGORYORMANUFACTURERORALL_H

#include <QDialog>

namespace Ui {
class CategoryOrManufacturerOrAll;
}

class CategoryOrManufacturerOrAll : public QDialog
{
    Q_OBJECT

public:
    explicit CategoryOrManufacturerOrAll(QWidget *parent = 0);
    ~CategoryOrManufacturerOrAll();

private slots:
    void on_showAll_clicked();

private:
    Ui::CategoryOrManufacturerOrAll *ui;
};

#endif // CATEGORYORMANUFACTURERORALL_H
