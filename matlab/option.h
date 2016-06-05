#ifndef OPTION_H
#define OPTION_H
#include <QWidget>
namespace Ui{
    class option;
}
class option:public QWidget
{
    Q_OBJECT
public:
    explicit option(QWidget *parent=0);
    ~option();
private slots:

    void on_DataSort_clicked();

    void on_MatrixSort_clicked();

private:
    Ui::option *ui;
};
#endif // OPTION_H
