/********************************************************************************
** Form generated from reading UI file 'option.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPTION_H
#define UI_OPTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_option
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *DataSort;
    QPushButton *MatrixSort;

    void setupUi(QWidget *option)
    {
        if (option->objectName().isEmpty())
            option->setObjectName(QStringLiteral("option"));
        option->resize(631, 346);
        option->setMinimumSize(QSize(480, 0));
        verticalLayoutWidget = new QWidget(option);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(270, 170, 120, 66));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        DataSort = new QPushButton(verticalLayoutWidget);
        DataSort->setObjectName(QStringLiteral("DataSort"));

        verticalLayout->addWidget(DataSort);

        MatrixSort = new QPushButton(verticalLayoutWidget);
        MatrixSort->setObjectName(QStringLiteral("MatrixSort"));

        verticalLayout->addWidget(MatrixSort);

        verticalLayoutWidget->raise();
        DataSort->raise();
        MatrixSort->raise();
        DataSort->raise();

        retranslateUi(option);

        QMetaObject::connectSlotsByName(option);
    } // setupUi

    void retranslateUi(QWidget *option)
    {
        option->setWindowTitle(QApplication::translate("option", "Form", 0));
        DataSort->setText(QApplication::translate("option", "Number Sort", 0));
        MatrixSort->setText(QApplication::translate("option", "Matrix Sort", 0));
    } // retranslateUi

};

namespace Ui {
    class option: public Ui_option {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPTION_H
