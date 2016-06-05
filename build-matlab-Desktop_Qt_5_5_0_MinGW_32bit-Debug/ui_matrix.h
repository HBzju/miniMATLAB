/********************************************************************************
** Form generated from reading UI file 'matrix.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MATRIX_H
#define UI_MATRIX_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_matrix
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout_5;
    QGroupBox *groupBox;
    QRadioButton *Row_2;
    QSpinBox *Row;
    QRadioButton *Col_2;
    QSpinBox *Col;
    QPushButton *SORT;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox_2;
    QRadioButton *AscendingOrder;
    QRadioButton *DescendingOrder;
    QTextEdit *source;
    QTextEdit *result;

    void setupUi(QWidget *matrix)
    {
        if (matrix->objectName().isEmpty())
            matrix->setObjectName(QStringLiteral("matrix"));
        matrix->resize(662, 373);
        layoutWidget = new QWidget(matrix);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(275, 12, 113, 351));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(10, 0, 10, 0);
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        groupBox = new QGroupBox(layoutWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        Row_2 = new QRadioButton(groupBox);
        Row_2->setObjectName(QStringLiteral("Row_2"));
        Row_2->setGeometry(QRect(0, 10, 91, 19));
        Row = new QSpinBox(groupBox);
        Row->setObjectName(QStringLiteral("Row"));
        Row->setGeometry(QRect(0, 40, 91, 21));
        Col_2 = new QRadioButton(groupBox);
        Col_2->setObjectName(QStringLiteral("Col_2"));
        Col_2->setGeometry(QRect(0, 70, 91, 19));
        Col = new QSpinBox(groupBox);
        Col->setObjectName(QStringLiteral("Col"));
        Col->setGeometry(QRect(0, 100, 91, 21));

        verticalLayout_5->addWidget(groupBox);


        verticalLayout_2->addLayout(verticalLayout_5);

        SORT = new QPushButton(layoutWidget);
        SORT->setObjectName(QStringLiteral("SORT"));

        verticalLayout_2->addWidget(SORT);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(-1, 0, -1, -1);
        groupBox_2 = new QGroupBox(layoutWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        AscendingOrder = new QRadioButton(groupBox_2);
        AscendingOrder->setObjectName(QStringLiteral("AscendingOrder"));
        AscendingOrder->setGeometry(QRect(0, 20, 81, 41));
        DescendingOrder = new QRadioButton(groupBox_2);
        DescendingOrder->setObjectName(QStringLiteral("DescendingOrder"));
        DescendingOrder->setGeometry(QRect(0, 70, 115, 19));

        verticalLayout_3->addWidget(groupBox_2);


        verticalLayout_2->addLayout(verticalLayout_3);

        source = new QTextEdit(matrix);
        source->setObjectName(QStringLiteral("source"));
        source->setGeometry(QRect(12, 12, 256, 351));
        result = new QTextEdit(matrix);
        result->setObjectName(QStringLiteral("result"));
        result->setGeometry(QRect(395, 12, 256, 351));

        retranslateUi(matrix);

        QMetaObject::connectSlotsByName(matrix);
    } // setupUi

    void retranslateUi(QWidget *matrix)
    {
        matrix->setWindowTitle(QApplication::translate("matrix", "Matrix Sort", 0));
        groupBox->setTitle(QString());
        Row_2->setText(QApplication::translate("matrix", "Row", 0));
        Col_2->setText(QApplication::translate("matrix", "Col", 0));
        SORT->setText(QApplication::translate("matrix", "SORT", 0));
        groupBox_2->setTitle(QString());
        AscendingOrder->setText(QApplication::translate("matrix", "Asc", 0));
        DescendingOrder->setText(QApplication::translate("matrix", "Des", 0));
        source->setPlaceholderText(QApplication::translate("matrix", "\350\257\267\351\241\272\345\272\217\350\276\223\345\205\245\347\237\251\351\230\265\345\205\203\347\264\240\357\274\214\347\224\250\347\251\272\346\240\274\351\232\224\345\274\200\343\200\202", 0));
        result->setPlaceholderText(QApplication::translate("matrix", "Row\345\222\214Col\351\273\230\350\256\244\344\273\2160\345\274\200\345\247\213\343\200\202", 0));
    } // retranslateUi

};

namespace Ui {
    class matrix: public Ui_matrix {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MATRIX_H
