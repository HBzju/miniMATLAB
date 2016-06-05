#ifndef SUPEREQUTION
#define SUPEREQUTION

#include "node.h"
#include "lparse.h"
#include <vector>
#include "qstring.h"
#include <stdlib.h>

vector<string> * postfix;


class supereqution
{
    string eqution;
    vector<string> * splited;//词法分析后的超越方程
public:
    supereqution(QString eqution)
    {
        this->eqution=eqution.toStdString();
    }
    QString exe(double lo,double hi);
};

Vector *f(Vector *x){
    double x0=getVector(x,0),y0;
    Vector *y=newVector(1);
    Node *root=buildTree(postfix,x0);
    y0=root->exe();
    setVector(y,0,y0);
    return(y);
}

QString supereqution::exe(double lo, double hi){
    QString out;
    char acc1[20],acc2[20],cons1[20],cons2[20];
    Vector *L,*U;

    splited=Lparse(eqution);//词法解析后的的超越方程
    postfix=toPostfix(splited);//转为前缀表达式之后的方程
    double low[]={lo},up[]={hi};
    L=toVector(low,1);
    U=toVector(up,1);
    Matrix *m1=roots(f,L,U,30,10,1);
    Matrix *m2=roots(f,L,U,30,10,2);
    sprintf(acc1,"%f",getMatrix(m1,0,0));
    sprintf(cons1,"%f",getMatrix(m1,1,0));
    sprintf(acc2,"%f",getMatrix(m2,0,0));
    sprintf(cons2,"%f",getMatrix(m1,1,0));

    if(atof(acc1)==0)
        out=QString::fromStdString(out.toStdString()+cons1+"\n");
    if(atof(acc2)==0)
        out=QString::fromStdString(out.toStdString()+cons2+"\n");
    if(atof(acc1)!=0&&atof(acc2)!=0)
        return "无法找到解";
    return out;
}

#endif // SUPEREQUTION

