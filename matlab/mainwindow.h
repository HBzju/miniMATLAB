#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QToolBar>
#include <QAction>
#include <QMenu>
#include <calculus.h>
#include <Matrix_YW.h>
#include <option.h>
#include "equation_xs.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    void deleteNowCentralWidget();
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void setSortWidget();
    void setMatrixWidget();
    void setEquationWidget();
    void setIntegrationWidget();
private:
    calculus *cal;
    Matrix_YW *mt;
    option *st;
    equation_xs *eq;
};

#endif // MAINWINDOW_H
