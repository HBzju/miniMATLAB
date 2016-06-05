#include "ui_matrix.h"
#include "matrix.h"
#include <iostream>
#include <algorithm>
using namespace std;

matrix::matrix(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::matrix)
{
    ui->setupUi(this);
}

matrix::~matrix()
{
    delete ui;
}
int m;
bool cmpa(double* a,double* b)
{
    return a[m]<b[m];//升序
}
bool cmpd(double* a,double* b)
{
    return a[m]>b[m];//降序
}
void matrix::on_SORT_clicked()
{
    QString source=ui->source->toPlainText();
    QStringList sRow=source.split("\n", QString::SkipEmptyParts);//用换行分割
    QStringList* Matrix=new QStringList[sRow.size()];
    for(int i=0;i<sRow.size();i++){
        Matrix[i]=sRow[i].split(" ",QString::SkipEmptyParts);
        if(Matrix[i].size()!=Matrix[0].size()){
            QString output="矩阵格式不对!";
            ui->result->setPlainText(output);
            return;
        }
    }
    if(ui->Row_2->isChecked()){//按矩阵的某行进行排序
        m=ui->Row->value();
        if(m>sRow.size()){
            QString output="行数超过限制!";
            ui->result->setPlainText(output);
            return;
        }
        double** col=new double*[Matrix[0].size()];
        for(int i=0;i<Matrix[0].size();i++){
            col[i]=new double[sRow.size()];
        }
        for(int i=0;i<sRow.size();i++){
            for(int j=0;j<Matrix[0].size();j++){
                col[j][i]=Matrix[i][j].toDouble();//QString转Double
            }
        }
        if(ui->AscendingOrder->isChecked())
            sort(col,col+Matrix[0].size(),cmpa);
        else if(ui->DescendingOrder->isChecked())
            sort(col,col+Matrix[0].size(),cmpd);
        else{
            QString output="请选择排序方式!";
            ui->result->setPlainText(output);
            return;
        }
        QString output;
        for(int i=0;i<sRow.size();i++){
            for(int j=0;j<Matrix[0].size();j++){
                output.append(QString::number(col[j][i],'g',10));
                output.append(" ");
            }
            output.append("\n");
        }
        ui->result->setPlainText(output);

    }
    else if(ui->Col_2->isChecked()){//按矩阵的列进行排序
        m=ui->Col->value();
        if(m>Matrix[0].size()){
            QString output="列数超过限制!";
            ui->result->setPlainText(output);
            return;
        }
        double** row=new double*[sRow.size()];
        for(int i=0;i<sRow.size();i++){
            row[i]=new double[Matrix[0].size()];
        }
        for(int i=0;i<sRow.size();i++){
            for(int j=0;j<Matrix[0].size();j++){
                row[i][j]=Matrix[i][j].toDouble();//QString转Double
            }
        }
        if(ui->AscendingOrder->isChecked())
            sort(row,row+sRow.size(),cmpa);
        else if(ui->DescendingOrder->isChecked())
            sort(row,row+sRow.size(),cmpd);
        else{
            QString output="请选择排序方式!";
            ui->result->setPlainText(output);
            return;
        }
        QString output;
        for(int i=0;i<sRow.size();i++){
            for(int j=0;j<Matrix[0].size();j++){
                output.append(QString::number(row[i][j],'g',10));
                output.append(" ");
            }
            output.append("\n");
        }
        ui->result->setPlainText(output);
    }
    else{
        QString output="请选择排序方式!";
        ui->result->setPlainText(output);
        return;
    }


}
