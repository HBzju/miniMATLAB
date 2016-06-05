/********************************************************************************
** Form generated from reading UI file 'number.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NUMBER_H
#define UI_NUMBER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_number
{
public:
    QTextEdit *source;
    QRadioButton *AscendingOrder;
    QRadioButton *DescendingOrder;
    QPushButton *SORT;
    QTextEdit *result;

    void setupUi(QWidget *number)
    {
        if (number->objectName().isEmpty())
            number->setObjectName(QStringLiteral("number"));
        number->resize(487, 316);
        source = new QTextEdit(number);
        source->setObjectName(QStringLiteral("source"));
        source->setGeometry(QRect(10, 10, 461, 121));
        AscendingOrder = new QRadioButton(number);
        AscendingOrder->setObjectName(QStringLiteral("AscendingOrder"));
        AscendingOrder->setGeometry(QRect(20, 140, 161, 21));
        DescendingOrder = new QRadioButton(number);
        DescendingOrder->setObjectName(QStringLiteral("DescendingOrder"));
        DescendingOrder->setGeometry(QRect(190, 140, 161, 21));
        SORT = new QPushButton(number);
        SORT->setObjectName(QStringLiteral("SORT"));
        SORT->setGeometry(QRect(360, 140, 93, 28));
        result = new QTextEdit(number);
        result->setObjectName(QStringLiteral("result"));
        result->setGeometry(QRect(10, 180, 461, 121));

        retranslateUi(number);

        QMetaObject::connectSlotsByName(number);
    } // setupUi

    void retranslateUi(QWidget *number)
    {
        number->setWindowTitle(QApplication::translate("number", "Number Sort", 0));
        source->setPlaceholderText(QApplication::translate("number", "\350\257\267\350\276\223\345\205\245\346\225\260\345\255\227\357\274\214\344\273\245\347\251\272\346\240\274\351\232\224\345\274\200\343\200\202", 0));
        AscendingOrder->setText(QApplication::translate("number", "Ascending Order", 0));
        DescendingOrder->setText(QApplication::translate("number", "Descending Order", 0));
        SORT->setText(QApplication::translate("number", "SORT", 0));
    } // retranslateUi

};

namespace Ui {
    class number: public Ui_number {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NUMBER_H
