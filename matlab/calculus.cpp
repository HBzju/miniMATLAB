#include "calculus.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLayout>
#include "integrate.h"
#include <iostream>
using namespace std;
calculus::calculus(QWidget *parent)
    :QWidget(parent)
{
    input=new QTextEdit(this);
    input->setFixedSize(480,300);
    input->setPlaceholderText("请输入函数（变量为x）");
    output=new QLabel(tr("Answer:"),this);
    output->setFixedSize(300,40);
    output->setWordWrap(true);
    button=new QPushButton(tr("Calculate"),this);
    button->setFixedSize(100,20);
    range_left=new QLineEdit("");
    range_right=new QLineEdit("");
    range_left->setFixedWidth(180);
    range_right->setFixedWidth(180);
    range_left->setPlaceholderText("积分下限");
    range_right->setPlaceholderText("积分上限");

    QHBoxLayout *Hlayout=new QHBoxLayout;
    Hlayout->addWidget(range_left);
    Hlayout->addWidget(range_right);

    QVBoxLayout *Vlayout=new QVBoxLayout;
    Vlayout->addWidget(input,0,Qt::AlignHCenter);
    Vlayout->addLayout(Hlayout);
    Vlayout->addWidget(output,0,Qt::AlignHCenter);
    Vlayout->addWidget(button,0,Qt::AlignHCenter);

    connect(button,SIGNAL(clicked()),this,SLOT(Tansfer()));
    connect(this,SIGNAL(Output(const QString&)),output,SLOT(setText(const QString&)));

    setLayout(Vlayout);
}

extern string Function;
void calculus::Tansfer()
{
    Function=input->toPlainText().toStdString();
    double x=1.7;
    double answer_d;
    double left,right;
    QString answer;

    try{
        if(Function.empty()){
            TextEmpty_Error te;
            throw te;
        }
        getRange(left,right);
        answer_d=integrate(x,NULL);
        answer=QString("Answer: %1").arg(answer_d, 0, 'f', 5);
    }
    catch(Empty_Error){
        answer="Too match operations!Please check your function!";
    }
    catch(Zero_Error){
        answer="Some operation used zero as dividend or some arguements which are wrong!";
    }
    catch(TextEmpty_Error){
        answer="You did not input any functions!";
    }
    catch(Range_Error){
        answer="Ranges are not double type or empty!";
    }
    catch(...){
        answer="Your functions like sin/cos/tan/log... may be wrong!";
    }

    emit Output(answer);
}

void calculus::getRange(double &left,double &right)
{
    bool ok1,ok2;
    ok1=ok2=false;
    left=range_left->text().toDouble(&ok1);
    right=range_right->text().toDouble(&ok2);
    if(ok1==false||ok2==false){
        Range_Error re;
        throw re;
    }
}

//15+log(1.5-cos(3.14/2))+1/7
