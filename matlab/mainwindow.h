#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QToolBar>
#include <QAction>
#include <QMenu>
#include <calculus.h>
#include <matrix.h>

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
    matrix *mt;
    //sort st;
    //equation eq;
};

#endif // MAINWINDOW_H
