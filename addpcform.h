#ifndef ADDPCFORM_H
#define ADDPCFORM_H

#include <QDialog>
#include "dbconnection.h"

namespace Ui {
class AddPcForm;
}

class AddPcForm : public QDialog
{
    Q_OBJECT

public:
    explicit AddPcForm(QWidget *parent = 0);
    ~AddPcForm();

private:
    Ui::AddPcForm *ui;
    QSqlDatabase m_db;
};

#endif // ADDPCFORM_H
