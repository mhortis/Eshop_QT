#ifndef CENTRALWIDGET_H
#define CENTRALWIDGET_H

#include <QDockWidget>

namespace Ui {
class CentralWidget;
}

class CentralWidget : public QDockWidget
{
    Q_OBJECT

public:
    explicit CentralWidget(QWidget *parent = 0);
    ~CentralWidget();

private:
    Ui::CentralWidget *ui;
};

#endif // CENTRALWIDGET_H
