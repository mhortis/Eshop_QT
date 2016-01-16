#ifndef ADDPCFORM_H
#define ADDPCFORM_H

#include <QDialog>

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
};

#endif // ADDPCFORM_H
