#ifndef NODE
#define NODE

#include <string>
#include <iostream>
#include "myerror.h"
extern "C"
{
    #include <my++/myhead.h>
}

using namespace std;

class Node//语法树的节点超类
{
    string type;//节点的类型
public:
    Node(){}
    Node(string type){
        this->type=type;
    }
    virtual double exe()=0;//计算当前节点的值域
    string getType(){return type;}
};


class Valuenode : public Node//值类型的节点
{
    double value;
public:
    Valuenode(string type){
        if(type=="e")
            this->value=2.718281828459;
        else
            cout<<"type error";
            //throw Myerror{"type is wrong"};
    }

    Valuenode(double value){
        this->value=value;
    }
    double exe(){return value;}
};

class Onenode : public Node{//具有一个子节点的子节点
    Node * child;
    string type;
public:
    Onenode(string type, Node* child){
        this->type=type;
        this->child=child;
    }

    double exe(){
        if(type=="sin")
            return sin(child->exe());
        else if(type=="cos")
            return cos(child->exe());
        else if(type=="tan")
            return tan(child->exe());
        else if(type=="ln")
            return log(child->exe());
        else
            cout<<"type error";
            //throw Myerror{"type error"};
    }
};

class Twonode : public Node{//有两个操作数的节点
    Node *left;
    Node *right;
    string type;
   public:
    Twonode(string type,Node *left,Node*right){
        this->type=type;
        this->left=left;
        this->right=right;
    }

    double exe(){
        if(type=="+")
            return left->exe()+right->exe();
        else if(type=="-")
            return left->exe()-right->exe();
        else if(type=="*")
            return left->exe()*right->exe();
        else if(type=="/")
            return left->exe()/right->exe();
        else if(type=="^")
            return pow(left->exe(),right->exe());
        else
            cout<<"type error";
            //throw Myerror{"type error"};

    }
};

#endif // NODE

