#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "stdafx.h"
#include <string>
#include "QtSql/QtSql"
#include <QString>
#include <QTDebug>
#include <QFileInfo>
#include "UserDAO.h"
#include "dbconnection.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void setLabel(std::string text);
    static int getUserID();
private slots:
    void on_loginButton_clicked();

private:

    Ui::MainWindow *ui;
    QSqlDatabase m_db;

};

#endif // MAINWINDOW_H
