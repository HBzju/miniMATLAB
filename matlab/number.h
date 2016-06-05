#ifndef NUMBER_H
#define NUMBER_H
#include <QWidget>
namespace Ui{
    class number;
}
class number:public QWidget
{
    Q_OBJECT
public:
    explicit number(QWidget *parent=0);
    ~number();
private slots:
    void on_SORT_clicked();
private:
    Ui::number *ui;
};
#endif // NUMBER_H
