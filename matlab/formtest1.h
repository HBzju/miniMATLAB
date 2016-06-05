#ifndef FORMTEST_H
#define FORMTEST_H

#include <QWidget>

namespace XS {
class Formtest;
}

class Formtest : public QWidget
{
    Q_OBJECT

public:
    explicit Formtest(QWidget *parent = 0);
    ~Formtest();

private slots:
    void on_solve_clicked();

private:
    XS::Formtest *ui;
};

#endif // FORMTEST_H
