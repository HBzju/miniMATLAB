/********************************************************************************
** Form generated from reading UI file 'formtestio9440.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef FORMTESTIO9440_H
#define FORMTESTIO9440_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Formtest: public QWidget
{
    Q_OBJECT
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QTextEdit *eqution;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QPushButton *solve;
    QTextEdit *answer;

    void setupUi(QWidget *Formtest)
    {
        if (Formtest->objectName().isEmpty())
            Formtest->setObjectName(QStringLiteral("Formtest"));
        Formtest->resize(400, 300);
        verticalLayout_2 = new QVBoxLayout(Formtest);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        eqution = new QTextEdit(Formtest);
        eqution->setObjectName(QStringLiteral("eqution"));

        horizontalLayout->addWidget(eqution);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));

        verticalLayout->addLayout(gridLayout);

        solve = new QPushButton(Formtest);
        solve->setObjectName(QStringLiteral("solve"));

        verticalLayout->addWidget(solve);


        horizontalLayout->addLayout(verticalLayout);


        verticalLayout_2->addLayout(horizontalLayout);

        answer = new QTextEdit(Formtest);
        answer->setObjectName(QStringLiteral("answer"));
        answer->setReadOnly(true);

        verticalLayout_2->addWidget(answer);


        retranslateUi(Formtest);

        QMetaObject::connectSlotsByName(Formtest);
    } // setupUi

    void retranslateUi(QWidget *Formtest)
    {
        Formtest->setWindowTitle(QApplication::translate("Formtest", "Form", 0));
        eqution->setPlaceholderText(QApplication::translate("Formtest", "这里可以解任意性线性方程组和最高次数不超过9的多项式方程对于线性方程组请一行输入一个方程，变量名字可以是任意字母组合,必须用+和-进行连接\n下面是一些例子\na+b+-4c=3\na+5c=9\na+2b=4\n对于多项式方程，变量名只能是x，最高次数不能超过九次，可能会找到两个相同的解，不同次也可能会找到不同的解。下面是一个例子\nx^2+2x-3=0", 0));
        solve->setText(QApplication::translate("Formtest", "\350\247\243\346\226\271\347\250\213\357\274\201", 0));
    } // retranslateUi

};

namespace XS {
    class Formtest: public Ui_Formtest {};
} // namespace Ui

QT_END_NAMESPACE

#endif // FORMTESTIO9440_H

