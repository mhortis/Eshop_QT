#ifndef TVORSMARTPHONEORPC_H
#define TVORSMARTPHONEORPC_H

#include <QDialog>

namespace Ui {
class TvOrSmartphoneOrPc;
}

class TvOrSmartphoneOrPc : public QDialog
{
    Q_OBJECT

public:
    explicit TvOrSmartphoneOrPc(QWidget *parent = 0);
    ~TvOrSmartphoneOrPc();

private slots:
    void on_addTV_clicked();

    void on_addSmartphone_clicked();

    void on_addPC_clicked();

private:
    Ui::TvOrSmartphoneOrPc *ui;
};

#endif // TVORSMARTPHONEORPC_H
