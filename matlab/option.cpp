#include <QApplication>
#include "ui_option.h"
#include "option.h"
#include "number.h"
#include "matrix.h"
#include <iostream>
using namespace std;

option::option(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::option)
{
    ui->setupUi(this);
}

option::~option()
{
    delete ui;
}



void option::on_MatrixSort_clicked()
{

    matrix *m = new matrix;
    m->show();
}
void option::on_DataSort_clicked()
{

    number* d=new number;
    d->show();
}

