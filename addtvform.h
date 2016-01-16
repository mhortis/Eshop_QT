#ifndef ADDTVFORM_H
#define ADDTVFORM_H

#include <QDialog>

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
};

#endif // ADDTVFORM_H
