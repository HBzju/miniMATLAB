#ifndef CALCULUS_H
#define CALCULUS_H

#include <QWidget>
#include <QString>
#include <QTextEdit>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>

class calculus:public QWidget
{
    Q_OBJECT
private slots:
    void Tansfer();
signals:
    void Output(const QString& answer);
private:
    QTextEdit *input;
    QLabel *output;
    QPushButton *button;
    QLineEdit *range_left;
    QLineEdit *range_right;
public:
    calculus(QWidget *parent);
    void getRange(double &left,double &right);
    ~calculus(){};
};

class Range_Error{};
class TextEmpty_Error{};

#endif // CALCULUS_H
