/********************************************************************************
** Form generated from reading UI file 'formtestUP3812.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef FORMTESTUP3812_H
#define FORMTESTUP3812_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Formtest
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QTextEdit *eqution;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_2;
    QSpinBox *low;
    QLabel *label;
    QSpinBox *hi;
    QPushButton *solve;
    QTextEdit *answer;

    void setupUi(QWidget *Formtest)
    {
        if (Formtest->objectName().isEmpty())
            Formtest->setObjectName(QStringLiteral("Formtest"));
        Formtest->resize(476, 355);
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
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_2 = new QLabel(Formtest);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_3->addWidget(label_2);

        low = new QSpinBox(Formtest);
        low->setObjectName(QStringLiteral("low"));
        low->setMinimum(-2000000000);
        low->setMaximum(2000000000);
        low->setValue(10);

        verticalLayout_3->addWidget(low);

        label = new QLabel(Formtest);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_3->addWidget(label);

        hi = new QSpinBox(Formtest);
        hi->setObjectName(QStringLiteral("hi"));
        hi->setMinimum(-2000000000);
        hi->setMaximum(2000000000);
        hi->setValue(-10);

        verticalLayout_3->addWidget(hi);


        gridLayout->addLayout(verticalLayout_3, 0, 0, 1, 1);


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
        eqution->setPlaceholderText(QApplication::translate("Formtest", "\346\261\202\350\247\243\350\266\205\350\266\212\346\226\271\347\250\213\357\274\214\346\224\257\346\214\201sin\357\274\214cos\357\274\214tan\357\274\214ln\357\274\214\345\222\214\345\270\270\351\207\217e\357\274\214\345\217\230\351\207\217\345\220\215\345\217\252\350\203\275\346\230\257x", 0));
        label_2->setText(QApplication::translate("Formtest", "\347\211\233\351\241\277\350\277\255\344\273\243\344\270\212\347\225\214", 0));
        label->setText(QApplication::translate("Formtest", "\347\211\233\351\241\277\350\277\255\344\273\243\344\270\213\347\225\214", 0));
        solve->setText(QApplication::translate("Formtest", "\350\247\243\346\226\271\347\250\213\357\274\201", 0));
    } // retranslateUi

};

namespace XS {
    class Formtest: public Ui_Formtest {};
} // namespace Ui

QT_END_NAMESPACE

#endif // FORMTESTUP3812_H


