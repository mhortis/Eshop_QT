#ifndef CUSTOMERPANEL_H
#define CUSTOMERPANEL_H

#include <QMainWindow>

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
private:
    Ui::CustomerPanel *ui;
    int panelType = 2;

};

#endif // CUSTOMERPANEL_H
