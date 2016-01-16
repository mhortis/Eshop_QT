#ifndef CUSTOMERPANEL_H
#define CUSTOMERPANEL_H

#include <QMainWindow>
#include "dbconnection.h"

namespace Ui {
class CustomerPanel;
}

class CustomerPanel : public QMainWindow
{
    Q_OBJECT

public:
    explicit CustomerPanel(QWidget *parent = 0);
    ~CustomerPanel();

private slots:
    void on_actionLogout_triggered();
    int getPanelType();
    void on_actionList_Products_triggered();

private:
    Ui::CustomerPanel *ui;
    int panelType = 2;
    QSqlDatabase m_db;

};

#endif // CUSTOMERPANEL_H
