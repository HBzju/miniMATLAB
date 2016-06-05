#include "formtest1.h"
#include "ui_formtest1.h"
#include <iostream>
#include <QMessageBox>
#include <ctime>
#include "supereqution.h"

using namespace std;

supereqution * equ;

Formtest::Formtest(QWidget *parent) :
    QWidget(parent),
    ui(new XS::Formtest)
{
    ui->setupUi(this);
}

Formtest::~Formtest()
{
    delete ui;
}

void Formtest::on_solve_clicked()
{
    ui->answer->setPlainText("正在求解，请稍后......");
    char buf[11];
    time_t start=clock();
    QString eqution=ui->eqution->toPlainText();
    int lo=ui->low->value();
    int hi=ui->hi->value();
    delete equ;
    equ=new supereqution(eqution);
    try{
        QString cons=equ->exe(lo,hi);
        time_t end=clock();
        sprintf(buf,"%d",int(end-start));
        string t="用了";t+=buf;t+="ms";
        ui->answer->setPlainText(cons+QString::fromStdString(t));
    }
    catch(Myerror e){
        QMessageBox::information(NULL, "error", QString::fromStdString(e.info), QMessageBox::Yes);
        cout<<e.info<<endl;
    }
}
