#include "Matrix_YW.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLayout>
#include <iostream>

Matrix_YW::Matrix_YW(QWidget *parent)
    :QWidget(parent)
{
    input1=new QTextEdit;
    input2=new QTextEdit;
    output=new QTextEdit;
    input1->setPlaceholderText("Input Your First Matrix_YW");
    input2->setPlaceholderText("Input Your Second Matrix_YW");
    output->setPlaceholderText("Your answer is here");
    input1->setFixedSize(280,200);
    input2->setFixedSize(280,200);
    output->setFixedSize(280,200);
    output->setReadOnly(true);
    add=new QPushButton(tr("&ADD"));
    minus=new QPushButton(tr("&MINUS"));
    add->setFixedWidth(280);
    minus->setFixedWidth(280);
    tips=new QLabel("应嘤嘤的矩阵计算工具~");

    QHBoxLayout *hlayout1=new QHBoxLayout;
    hlayout1->addWidget(input1);
    hlayout1->addWidget(input2);

    QVBoxLayout *vlayout1=new QVBoxLayout;
    vlayout1->addWidget(add);
    vlayout1->addWidget(minus);

    QHBoxLayout *hlayout2=new QHBoxLayout;
    hlayout2->addLayout(vlayout1);
    hlayout2->addWidget(output);

    QVBoxLayout *vlayout2=new QVBoxLayout;
    vlayout2->addWidget(tips);
    vlayout2->addLayout(hlayout1);
    vlayout2->addLayout(hlayout2);

    setLayout(vlayout2);

    connect(add,SIGNAL(clicked(bool)),this,SLOT(addMatrix_YW()));
    connect(this,SIGNAL(setOutput(const QString&)),output,SLOT(setText(const QString&)));
}

Matrix_YW::~Matrix_YW()
{
}

void Matrix_YW::Output(string &op)
{
    QString QT_op;
    QT_op=QString::fromStdString(op);
    emit setOutput(QT_op);
}

void Matrix_YW::getInput(string &ip1,string &ip2)
{
    ip1=input1->toPlainText().toStdString();
    ip2=input2->toPlainText().toStdString();
}

/*-------------------coding here---------------------------------*/

void Matrix_YW::addMatrix_YW()
{
    string ip1,ip2,op;
    getInput(ip1,ip2);
    Matrix_YWAddOperation(ip1,ip2,op);
    Output(op);
}

/*void Matrix_YW::minusMatrix_YW()
{
    string ip1,ip2,op;
    getInput(ip1,ip2);
    Matrix_YWMinusOperation(ip1,ip2,op);
    Output(op);
}*/

void Matrix_YW::Matrix_YWAddOperation(string &ip1,string &ip2,string &op)
{
    op=ip1+ip2;
}
