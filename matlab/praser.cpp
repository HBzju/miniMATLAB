#include "praser.h"
#include <iostream>
#include "lineareuqtions.h"
#include <regex>

using namespace std;


QString praser(QString in){
    vector<QString> equtions=split(in,'\n');
    linearequtions A(&equtions);//构造方程组对象
    return A.exe();//运算并返回结果
}

vector<QString> split(QString in, char seq){//按照seq切分QString
    if(in[in.length()-1]!='\n')
        in+="\n";
    vector<QString> out;
    QString current;
    int i=0;
    while(i<in.length()){
        if(in[i]!=seq){
            current+=in[i];
        }
        else{
            out.push_back(current);
            current="";
        }
        i++;
    }
    return out;
}

int testSplit(){//对split函数的测试
    QString test="a\nb\nc\n";
    auto x=split(test,'\n');
    for(auto t:x){
        QByteArray ba(t.toUtf8());
        cout<<ba.data()<<endl;
    }
    return 0;
}
