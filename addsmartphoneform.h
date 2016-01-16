#ifndef ADDSMARTPHONEFORM_H
#define ADDSMARTPHONEFORM_H

#include <QDialog>

namespace Ui {
class AddSmartphoneForm;
}

class AddSmartphoneForm : public QDialog
{
    Q_OBJECT

public:
    explicit AddSmartphoneForm(QWidget *parent = 0);
    ~AddSmartphoneForm();

private:
    Ui::AddSmartphoneForm *ui;
};

#endif // ADDSMARTPHONEFORM_H
