#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

    //重写定时器事件
    virtual void timerEvent(QTimerEvent *e);

private:
    Ui::Widget *ui;

    //定义 定时器的id 接收开启定时器时函数的返回值
    int id1;
    int id2;
};

#endif // WIDGET_H
