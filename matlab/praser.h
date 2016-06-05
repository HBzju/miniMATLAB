#ifndef PRASER_H
#define PRASER_H
#include <qstring.h>
#include <vector>
extern "C"
{
    #include <my++/myhead.h>
}

using namespace std;

QString praser(QString in);//解析用户的输入
vector<QString> split(QString in,char seq='\n');//把字符串按照输入的字符做切分
int testSplit();


#endif // PRASER_H

