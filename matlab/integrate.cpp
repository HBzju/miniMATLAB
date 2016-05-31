#include <integrate.h>
string Function;
double integrate(double x, void *params)
{
    return tansform(x);
}

double tansform(double x)
{
    string::iterator it;
    stack<double> digit;
    stack<char> ch;
    for(it=Function.begin();it!=Function.end();it++){
        if(Is_Single(*it)){
            Single_Operation(it,ch);
        } //单目运算符
        else if(*it=='x')digit.push(x); //x
        else if(*it=='e')digit.push(2.718281828459045); //exp
        else if(*it==' '||*it=='\t'||*it=='\n')continue;
        else if((*it>='0'&&*it<='9')||(*it=='-'&&(it==Function.begin()||(*(it-1)=='(')))){
            double num=0;
            double symbol=1;
            if(*it=='-'){
                symbol=-1;
                it++;
            }
            for(;it!=Function.end()&&*it<='9'&&*it>='0';it++){
                num=num*10+*it-'0';
            }
            if(it==Function.end()){
                digit.push(symbol*num);
                break;
            }
            if(*it=='.'){
                int i=-1;
                for(it++;it!=Function.end()&&*it<='9'&&*it>='0';it++,i--){
                    num+=(*it-'0')*pow(10,i);
                }
            }
            digit.push(symbol*num);
            it--;
        }//数字
        else if(*it=='(')ch.push(*it);
        else if(*it==')'){
            while(!ch.empty()&&ch.top()!='('){
                Char_Operation(ch.top(),digit);
                ch.pop();
            }
            ch.pop();
            if(!ch.empty()){
                if(Is_Single(ch.top())){
                    Char_Operation(ch.top(),digit);
                    ch.pop();
                }
            }
        }
        else{
            int or1=Operation_Rank(*it);
            int or2=ch.empty()?-1:Operation_Rank(ch.top());
            if(or1==-1){
                OpType_Error ope;
                throw ope;
            }
            if(or1>or2)ch.push(*it);
            else{
                Char_Operation(ch.top(),digit);
                ch.pop();
                ch.push(*it);
            }
        }//其他运算符
    }
    while(!ch.empty()){
        Char_Operation(ch.top(),digit);
        ch.pop();
    }
    double answer=digit.top();
    digit.pop();
    return answer;
}

void Char_Operation(char op,stack<double>& digit)
{
    double num1=digit.top(),num;
    digit.pop();
    double num2=0;
    if(Is_Single(op)){
        switch(op){
            case 'l':
                if(num1<=0){
                    Zero_Error dive;
                    throw dive;
                }
                num=log(num1);
                break;
            case 'c':
                num=cos(num1);
                break;
            case 's':
                num=sin(num1);
                break;
            case 't':
                num=tan(num1);
                break;
            default:
                break;
        }
        digit.push(num);
        return;
    }

    if(!digit.empty()){
        num2=digit.top();
        digit.pop();
    }
    else{
        Empty_Error ee;
        throw ee;
    }
    switch(op){
        case '+':
            num=num1+num2;
            break;
        case '-':
            num=num2-num1;
            break;
        case '*':
            num=num1*num2;
            break;
        case '/':
            if(num1==0){
                Zero_Error dive;
                throw dive;
            }
            num=num2/num1;
            break;
        case '^':
            num=pow(num2,num1);
            break;
        default:
            break;
    }
    digit.push(num);
    //cout<<num1<<' '<<num2<<' '<<num<<' '<<op<<endl;
}

int Operation_Rank(char op)
{
    if(Is_Single(op))return 4;
    if(op=='(')return 0;
    else if(op=='+'||op=='-')return 1;
    else if(op=='*'||op=='/')return 2;
    else if(op=='^')return 3;
    else return -1;
}

bool Is_Single(char op)
{
    switch(op){
        case 'l':case 'c':case 's':case 't':return true;
        default:return false;
    }
}

void Single_Operation(string::iterator &it,stack<char> &ch)
{
    if(*it=='l'){
        if(*(it+1)=='o'&&*(it+2)=='g'){
            ch.push(*it);
            it+=2;
        }
        else{
            Log_Error loge;
            throw loge;
        }
    }
    else if(*it=='c'){
         if(*(it+1)=='o'&&*(it+2)=='s'){
            ch.push(*it);
            it+=2;
        }
        else{
            Cos_Error cose;
            throw cose;
        }
    }
    else if(*it=='s'){
         if(*(it+1)=='i'&&*(it+2)=='n'){
            ch.push(*it);
            it+=2;
        }
        else{
            Sin_Error sine;
            throw sine;
        }
    }
    else if(*it=='t'){
         if(*(it+1)=='a'&&*(it+2)=='n'){
            ch.push(*it);
            it+=2;
        }
        else{
            Tan_Error tane;
            throw tane;
        }
    }
}
