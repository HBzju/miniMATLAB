#include "mainwindow.h"
#include "calculus.h"
#include <QDialog>
#include <QString>
#include <QTextEdit>
#include <QPushButton>
#include <QMenuBar>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    mt=NULL;
    cal=NULL;
    st=NULL;
    eq=NULL;
    setFixedSize(640,480);
    QAction *sort=new QAction("Sort",this);
    QAction *matrix=new QAction("Matrix",this);
    QAction *equation=new QAction("Equation",this);
    QAction *integration=new QAction("Integration",this);

    setWindowTitle("miniMATLAB");
    QMenu *menu = menuBar()->addMenu(tr("&Menu"));
    QToolBar *toolbar=addToolBar("&ToolBar");
    toolbar->setAutoFillBackground(true);

    menu->addAction(integration);
    menu->addAction(matrix);
    menu->addAction(equation);
    menu->addAction(sort);

    toolbar->addAction(integration);
    toolbar->addAction(matrix);
    toolbar->addAction(equation);
    toolbar->addAction(sort);

    connect(sort,SIGNAL(triggered(bool)),this,SLOT(setSortWidget()));
    connect(matrix,SIGNAL(triggered(bool)),this,SLOT(setMatrixWidget()));
    connect(equation,SIGNAL(triggered(bool)),this,SLOT(setEquationWidget()));
    connect(integration,SIGNAL(triggered(bool)),this,SLOT(setIntegrationWidget()));

    calculus *cal=new calculus(this);
    setCentralWidget(cal);
}

MainWindow::~MainWindow()
{
}

void MainWindow::setSortWidget()
{
    if(st!=NULL)return;
    deleteNowCentralWidget();
    st=new option(this);
    setCentralWidget(st);
}

void MainWindow::setMatrixWidget()
{
    if(mt!=NULL)return;
    deleteNowCentralWidget();
    mt=new Matrix_YW(this);
    setCentralWidget(mt);
}

void MainWindow::setEquationWidget()
{
    if(eq!=NULL)return;
    deleteNowCentralWidget();
    eq=new equation_xs(this);
    setCentralWidget(eq);
}

void MainWindow::setIntegrationWidget()
{
    if(cal!=NULL)return;
    deleteNowCentralWidget();
    cal=new calculus(this);
    setCentralWidget(cal);
}

void MainWindow::deleteNowCentralWidget()
{
    if(cal!=NULL){
        delete cal;
        cal=NULL;
    }
    else if(mt!=NULL){
        delete mt;
        mt=NULL;
    }
    else if(st!=NULL){
        delete st;
        st=NULL;
    }
    else if(eq!=NULL){
        delete eq;
        eq=NULL;
    }
}
