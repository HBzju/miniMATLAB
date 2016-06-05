#ifndef MATRIX_H
#define MATRIX_H
#include <QWidget>
namespace Ui{
    class matrix;
}
class matrix:public QWidget
{
    Q_OBJECT

public:
    explicit matrix(QWidget *parent=0);
    ~matrix();

private slots:

    void on_SORT_clicked();

private:
    Ui::matrix *ui;
};
#endif // MATRIX_H
