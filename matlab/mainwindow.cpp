#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "calculus.h"
#include <QDialog>
#include <QString>
#include <QTextEdit>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //ui->setupUi(this);
    this->setWindowTitle("miniMATLAB");
    calculus *cal=new calculus(this);
    setCentralWidget(cal);
}

MainWindow::~MainWindow()
{
    delete ui;
}
