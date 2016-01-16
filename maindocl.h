#ifndef MAINDOCL_H
#define MAINDOCL_H

#include <QDockWidget>
#include "dbconnection.h"

namespace Ui {
class MainDocl;
}

class MainDocl : public QDockWidget
{
    Q_OBJECT

public:
    explicit MainDocl(QWidget *parent = 0);
    ~MainDocl();

private:
    Ui::MainDocl *ui;
    QSqlDatabase m_db;
};

#endif // MAINDOCL_H
