#ifndef LOGOUTDIALOG_H
#define LOGOUTDIALOG_H

#include <QWidget>
#include "dbconnection.h"

namespace Ui {
class LogoutDialog;
}

class LogoutDialog : public QWidget
{
    Q_OBJECT

public:
    explicit LogoutDialog(int panelType, QWidget *parent = 0);
    void logout_yes();
    void logout_no();
    ~LogoutDialog();

private:
    Ui::LogoutDialog *ui;
};

#endif // LOGOUTDIALOG_H
