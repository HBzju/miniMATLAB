#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QString>
#include <QTextEdit>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include "praser.h"

class equation_xs : public QWidget
{
    Q_OBJECT

public:
    equation_xs(QWidget *parent = 0);
    ~equation_xs();

private:
    QTextEdit *input;
    QTextEdit *output;
    QPushButton *button;

signals:
    void setAnswer(const QString &answer);

private slots:
    void equation_slots()
    {
        QString ip=input->toPlainText();
        QString op=praser(ip);

        emit setAnswer(op);
    }
};

#endif // WIDGET_H
