#ifndef LINEAREQUTIONS_H
#define LINEAREQUTIONS_H
#include "eqution.h"
#include <vector>
#include <qstring.h>
#include <map>
extern "C"
{
    #include <my++/myhead.h>
}

using namespace std;

class linearequtions :eqution
{
    private:
        int row;
        int column;
        vector<QString>* linearEqutions;
        map<string,int> varibles;
        Matrix * left;//方程左边
        Vector * right;//方程右边
        Matrix * moreMat;//线性方程组的增广矩阵
        void prase();//解析方程得到矩阵
        void findVars();//找到所有的变量
        void findKeys(QString equ);//找到一个方程当中变量的对应值
        double findValue(QString equ);
        void clearMap();
        QString toString();

    public:
        linearequtions(vector<QString> * equtions);
        bool isValid();//方程组是否有解法
        QString exe();//解方程
        void test();//只是测试

};

class myerror{//自定义的异常类

public:
    string info;
    myerror(string info){
        this->info=info;
    }
};
#endif // LINEAREQUTIONS_H
