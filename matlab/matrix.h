#ifndef MATRIX_H
#define MATRIX_H

#include <QWidget>
#include <QString>
#include <QTextEdit>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <string.h>
using namespace std;

class matrix:public QWidget
{
    Q_OBJECT
public:
    void getInput(string &ip1,string &ip2);
    void matrixAddOperation(string &ip1,string &ip2,string &op);
    void Output(string &op);
    matrix(QWidget *parent=0);
    ~matrix();
private:
    QTextEdit *input1;
    QTextEdit *input2;
    QTextEdit *output;
    QLabel *tips;
    QPushButton *add;
    QPushButton *minus;
private slots:
    void addMatrix();
    void minusMatrix(){}
signals:
    void setOutput(const QString& op);
};

#endif // MATRIX_H
