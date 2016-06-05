#include "formtest.h"
#include "ui_formtest.h"
#include "lineareuqtions.h"
#include "praser.h"
#include <iostream>
#include <QMessageBox>
#include <ctime>

using namespace std;

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
    char buf[11];
    time_t start=clock();
    QString equ=ui->eqution->toPlainText();
    ui->answer->setPlainText("正在求解，请稍后......");
    try{
        QString cons=praser(equ);
        time_t end=clock();
        sprintf(buf,"%d",end-start);
        string t="用了";t+=buf;t+="ms";
        ui->answer->setPlainText(cons+QString::fromStdString(t));
    }
    catch(myerror e){
        QMessageBox::information(NULL, "error", QString::fromStdString(e.info), QMessageBox::Yes);
        cout<<e.info<<endl;
    }
}
