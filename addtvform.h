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

private slots:
    void on_cancelButton_clicked();

    void on_saveButton_clicked();

private:
    Ui::AddTvForm *ui;
    QSqlDatabase m_db;
};

#endif // ADDTVFORM_H
