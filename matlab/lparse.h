#ifndef LPARSE
#define LPARSE
#include "node.h"
#include <vector>
#include <set>
#include <map>
#include <iostream>

vector<string> * Lparse(string eqution);
vector<string> * toPostfix(vector<string> * splited);
string replace(string str,char from,char to);
bool isNum(string str);
bool isOper(string str);
int getOperNum(string str);
int compareOper(string a,string b);
Node * buildTree(vector<string> * post);
int todigit(string str);

using namespace std;

Node * buildTree(vector<string> * post,double x0){//把后缀表达式转换为语法树
    Node *left;
    Node *right;
    vector<Node*> *nodes=new vector<Node*>;
    for(auto e: *post){
        if(isNum(e)){
            if(e=="x")
                nodes->push_back(new Valuenode(x0));
            else if(e=="e")
                nodes->push_back(new Valuenode(e));
            else
                nodes->push_back(new Valuenode(atof(e.c_str())));
        }
        else if (isOper(e)){
            if(getOperNum(e)==1){
                left=nodes->back();
                nodes->pop_back();
                nodes->push_back(new Onenode(e,left));
            }
            else if(getOperNum(e)==2){
                right=nodes->back();
                nodes->pop_back();
                left=nodes->back();
                nodes->pop_back();
                nodes->push_back(new Twonode(e,left,right));
            }
        }
    }
    if(nodes->size()!=1){
        cout<<"nodes are not equal to 1";
        throw Myerror{"nodes are not equal to 1"};
    }
    return nodes->back();
}

vector<string> * Lparse(string eqution){//对方程的词法分析
    unsigned int i=0;
    vector<string> * splited=new vector<string>;
    set<char> splitor{'+','*','-','/','(',')','^'};//分割符号
    string temp="";
    std::cout<<eqution.find('=');
    if(eqution.find('=')==-1){
        throw Myerror{"there is no = in the eqution"};
    }
    for(i=0;i<eqution.length();i++){
        if(eqution[i]=='='){
            splited->push_back(temp);
            temp="";
            splited->push_back("-");
            for(i++;i<eqution.length();i++){
                temp+=eqution[i];
            }
            break;
        }
        if(splitor.find(eqution[i])!=splitor.end()){
            if(temp!="")
                splited->push_back(temp);
            temp=eqution[i];
            splited->push_back(temp);
            temp="";
        }
        else{
            temp+=eqution[i];
        }
    }
    if(temp!="")
        splited->push_back(temp);
    return splited;
}

vector<string> * toPostfix(vector<string> *splited){
    vector<string> * oper=new vector<string>;//the stack use to store operator
    vector<string> * num=new vector<string>;//the stack use to store numbers
    vector<string> * postfix=new vector<string>;//postfix eqution
    string num1,num2,op;
    for(auto str: *splited){
        if(isNum(str)){
            num->push_back(str);

        }
        else if(isOper(str)){
            if(oper->size()>=1){
                op=oper->back();
                while(compareOper(op,str)>=0){
                    if(getOperNum(op)==0){
                        break;//遇到括号
                    }
                    else if(getOperNum(op)==1){
                        oper->pop_back();
                        num1=num->back();
                        num->pop_back();
                        num->push_back(" "+num1+" "+op+" ");
                        if(oper->size()<1)
                            break;
                        op=oper->back();
                    }
                    else if(getOperNum(op)==2){
                        oper->pop_back();
                        num1=num->back();
                        num->pop_back();
                        num2=num->back();
                        num->pop_back();
                        num->push_back(" "+num2+" "+num1+" "+op+" ");//first in first in
                        if(oper->size()<1)
                            break;
                        op=oper->back();
                    }
                }
            }
            if(str!=")")
                oper->push_back(str);
            else
                oper->pop_back();
        }
        else
            throw Myerror{"can't understand the equtiion"};
    }
    num1=num->back();
    num->pop_back();
    num2=num->back();
    num->pop_back();
    op=oper->back();
    oper->pop_back();

    if(num->size()!=0||oper->size()!=0)
        throw Myerror{"the eqution has mistake"};

    string temp="";
    num2=" "+num2+" "+num1+" "+op+" ";
    for(unsigned int i=0;i<num2.size();i++){
     if(num2[i]==' '){
         if(temp!="")
            postfix->push_back(temp);
         temp="";
     }
     else
         temp+=num2[i];
    }
    if(temp!="")
       postfix->push_back(temp);
    return postfix;
}

string replace(string str, char from, char to){
    string out="";
    for(unsigned i=0;i<str.length();i++){
        if(str[i]==from)
            out+=to;
        else
            out+=str[i];
    }
    return out;
}


bool isdigitl(string str){
    if(str[0]=='0'&&str.length()>1)
        return false;
    for(unsigned int i=0;i<str.length();i++){
        if(!isdigit(str[i])){
            return false;
        }
    }
    return true;
}

bool isNum(string str){
    return isdigitl(str)||str=="x"||str=="e";
}

bool isOper(string str){
    static set<string> oper={"ln","(",")","^","+","-","*","/","sin","cos","tan"};
    return oper.find(str)!=oper.end();
}

int getOperNum(string str){//得到一个操作符号有几个操作数
    static set<string> zero{"(",")"};
    static set<string> one{"sin","cos","ln","tan"};
    static set<string> two{"+","-","*","/","^"};
    if(zero.find(str)!=zero.end())
        return 0;
    else if(one.find(str)!=one.end())
        return 1;
    else if(two.find(str)!=two.end())
        return 2;
    else
        throw Myerror{"can't recognise the operator"};
}

int compareOper(string a, string b){
    static map<string,int> prioritymap{
        {"(",5},
        {"+",1},
        {"-",1},
        {"*",2},
        {"/",2},
        {"^",3},
        {"sin",4},
        {"cos",4},
        {"tan",4},
        {"ln",4},
        {")",0},
    };//priority map
    if(prioritymap[a]==prioritymap[b])
        return 0;
    else
        return prioritymap[a]>prioritymap[b]? 1:-1;
}
#endif // LPARSE

