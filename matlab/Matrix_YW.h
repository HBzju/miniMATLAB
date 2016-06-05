#ifndef Matrix_YW_H
#define Matrix_YW_H

#include <QWidget>
#include <QString>
#include <QTextEdit>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <string.h>
using namespace std;

class Matrix_YW:public QWidget
{
    Q_OBJECT
public:
    void getInput(string &ip1,string &ip2);
    void Matrix_YWAddOperation(string &ip1,string &ip2,string &op);
    void Output(string &op);
    Matrix_YW(QWidget *parent=0);
    ~Matrix_YW();
private:
    QTextEdit *input1;
    QTextEdit *input2;
    QTextEdit *output;
    QLabel *tips;
    QPushButton *add;
    QPushButton *minus;
private slots:
    void addMatrix_YW();
    void minusMatrix_YW(){}
signals:
    void setOutput(const QString& op);
};

#endif // Matrix_YW_H
