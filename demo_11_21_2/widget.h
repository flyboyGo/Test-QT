#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>

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
    virtual void timerEvent(QTimerEvent *event);

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
