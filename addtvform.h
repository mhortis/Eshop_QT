#ifndef ADDTVFORM_H
#define ADDTVFORM_H

#include <QDialog>
#include "dbconnection.h"

namespace Ui {
class AddTvForm;
}

class AddTvForm : public QDialog
{
    Q_OBJECT

public:
    explicit AddTvForm(QWidget *parent = 0);
    ~AddTvForm();

private:
    Ui::AddTvForm *ui;
    QSqlDatabase m_db;
};

#endif // ADDTVFORM_H
