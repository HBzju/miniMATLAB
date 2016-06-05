#include "ui_number.h"
#include "number.h"
#include <iostream>
#include <array>
#include <algorithm>
using namespace std;

number::number(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::number)
{
    ui->setupUi(this);
}

number::~number()
{
    delete ui;
}

bool cmp(int a,int b)
{
    return a>b;//降序
}
void number::on_SORT_clicked()
{
    QString source=ui->source->toPlainText();
    QStringList sourcelist=source.split(" ", QString::SkipEmptyParts);//用空格分割
    int capacity=50;
    double* result=new double[capacity];
    int i=0;
    for(i=0;i<sourcelist.size();i++){
        double val=sourcelist[i].toDouble();//QString转换成double
        if(i<capacity)
            result[i]=val;
        else{//扩容
            double* temp = new double[capacity+50];
            for(int j=0;j<=i;j++){
                temp[j]=result[j];
            }
            temp[i]=val;
            delete[] result;
            result=temp;
            capacity+=50;//更新数组容量
        }
    }
    if(ui->AscendingOrder->isChecked())
        sort(result,result+i);
    else if(ui->DescendingOrder->isChecked())
        sort(result,result+i,cmp);
    else{
        QString output="请选择排序方式!";
        ui->result->setPlainText(output);
        return;
    }
    QString output;
    for(int j=0;j<i;j++){
        if(j%10==0){
            if(j)
                output.append("\n");
            output.append("Columns ");
            output.append(QString::number(j+1,'g',10));
            output.append(" through ");
            if(j+11<i+1)
                output.append(QString::number(j+10,'g',10));
            else
                output.append(QString::number(i,'g',10));
            output.append("\n");
        }
        output.append(QString::number(result[j],'g',10));
        output.append(" ");
    }
    ui->result->setPlainText(output);
   // delete[] result;
}

