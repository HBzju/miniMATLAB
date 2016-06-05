#include "lineareuqtions.h"
#include "praser.h"
#include <string>
#include <regex>
#include <map>
#include <iostream>
#include "rank.h"
#define MAX 20


using namespace std;

void linearequtions::clearMap(){
    for(auto p=varibles.begin();p!=varibles.end();p++){
        p->second=0;
    }
}

linearequtions::linearequtions(vector<QString> * equtions){
    this->linearEqutions=equtions;
    prase();
}

bool linearequtions::isValid(){
    return myRank(left,row,column)==myRank(moreMat,row,column+1);
}

void linearequtions::prase(){
    findVars();//找到所有的变量
    row=linearEqutions->size();//矩阵的行
    column=varibles.size();//矩阵的列
    int i=0,j=0,k=0;
    double matrix[row*column];
    double moreMatrix[row*(column+1)];
    double vec[row];
    for(auto equ: * linearEqutions){
        findKeys(equ);
        for(auto x: varibles){
            matrix[i]=x.second;
            moreMatrix[j]=matrix[i];
            j++; i++;
        }
        vec[k]=findValue(equ);
        moreMatrix[j]=vec[k];
        k++; j++;
    }

    left=toMatrix(matrix,row,column);
    moreMat=toMatrix(moreMatrix,row,column+1);
    right=toVector(vec,row);//矩阵，向量和增广矩阵
}

QString linearequtions::exe(){
    QString out;
    int i=0;

    if(!isValid()){
        throw myerror{"no solution"};
    }
    Vector *anwser=lspinvlinsolveVector(left,right);//结果
    char t[20];
    for(auto p=varibles.begin();p!=varibles.end();p++,i++){
        sprintf(t,"%f",getVector(anwser,i));
        out=QString::fromStdString(out.toStdString()+p->first+": "+t+"\n");//格式化结果
    }
    return out;
}

void linearequtions::findKeys(QString equ){
    int pos;
    string str;
    smatch matches;
    clearMap();//先把变量表清零
    regex pat2 {"(-{0,1}[0-9]*)([[:alpha:]]+)"};//正则表达式，捕获变量和对应的值
    while((pos=equ.indexOf('+'))!=-1){
        str=equ.left(pos).toStdString();
        equ=equ.mid(pos+1);
        regex_search(str,matches,pat2);
        varibles[matches[2]]=matches[1]==""? 1:atoi(((string)matches[1]).c_str());
    }
    pos=equ.indexOf('=');
    str=equ.left(pos).toStdString();
    regex_search(str,matches,pat2);
    varibles[matches[2]]=matches[1]==""? 1:atoi(((string)matches[1]).c_str());
}

double linearequtions::findValue(QString equ){
    int pos=equ.indexOf("=");
    double out=equ.mid(pos+1).toDouble();
    return out;
}

void linearequtions::findVars(){
    string str;
    int pos;
    regex pat {"((-{0,1}[0-9]*[[:alpha:]]+)\\+)*((-{0,1}[0-9]*[[:alpha:]]+))=[0-9]+"};//正则表达式，匹配正确的方程
    regex pat2 {"(-{0,1}[0-9]*)([[:alpha:]]+)"};//正则表达式，捕获变量和对应的值
    smatch matches;
    for(auto x: *linearEqutions){//先遍历一遍方程找到所有的变量名并加到map当中
        str=x.toStdString();
        if(!regex_match(str,pat))
            throw  myerror{"format is not acceptable"};//方程输入有错抛出异常
        else{
            while((pos=x.indexOf('+'))!=-1){
                str=x.left(pos).toStdString();
                x=x.mid(pos+1);
                regex_search(str,matches,pat2);
                //cout<<matches[2]<<endl;
                if(varibles.find(matches[2])==varibles.end()){
                    varibles[matches[2]]=0;
                }
            }
            pos=x.indexOf('=');
            str=x.left(pos).toStdString();
            regex_search(str,matches,pat2);
            //cout<<matches[2]<<endl;
            if(varibles.find(matches[2])==varibles.end()){
                varibles[matches[2]]=0;
            }
        }

    }
}

void linearequtions::test(){//只是一个测试函数
    /*findVars();
    for(auto p:varibles){
        cout<<p.first<<" "<<p.second<<endl;
    }
    for(auto x:*linearEqutions){
        cout<<x.toStdString()<<endl;
        findKeys(x);
        for(auto p:varibles){
            cout<<p.first<<" "<<p.second<<endl;
        }
    }*/
        exe();
}


