#ifndef OPERATIONCYCLE_H
#define OPERATIONCYCLE_H
#include <QDialog>
#include "DBConnection.h"
#include <QSqlDatabase>
#include "OrderDAO.h"

namespace Ui {
class operationCycle;
}

class operationCycle : public QDialog
{
    Q_OBJECT

public:
    explicit operationCycle(QWidget *parent = 0);
    ~operationCycle();

private:
    Ui::operationCycle *ui;
    QSqlDatabase m_db;
    vector<double> totalOrders;
};

#endif // OPERATIONCYCLE_H
