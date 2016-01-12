#ifndef ADMINISTRATORPANEL_H
#define ADMINISTRATORPANEL_H

#include <QMainWindow>

namespace Ui {
class AdministratorPanel;
}

class AdministratorPanel : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdministratorPanel(QWidget *parent = 0);
    ~AdministratorPanel();

private:
    Ui::AdministratorPanel *ui;
};

#endif // ADMINISTRATORPANEL_H
