#ifndef MYLABEL_H
#define MYLABEL_H

#include <QLabel>

//MyLabel 继承于 QLabel 就可以在MyLabel类中 重写 QLabeL的事件

//如果想要重写 某个类的事件 一般情况 就要自定义一个类 继承于该控件的类型
//然后将控件的类 提升为 自定义的类 这样我们就可以在自定义类中 重写控件类型的事件函数

class MyLabel : public QLabel
{
    Q_OBJECT
public:
    explicit MyLabel(QWidget *parent = 0);

    //重写鼠标进入事件
    virtual void enterEvent(QEvent *event);

    //重写鼠标离开事件
    virtual void leaveEvent(QEvent *event);

    //重写鼠标按下事件
    virtual void mousePressEvent(QMouseEvent *event);

    //重写鼠标移动事件
    virtual void mouseMoveEvent(QMouseEvent *event);

    //重写事件分发器
    virtual bool event(QEvent *event);

    //声明事件过滤函数
    //watched:事件发生的控件
    //event:具体的事件信息 (鼠标移动 鼠标按下 键盘事件等等)
    virtual bool eventFilter(QObject *watched, QEvent *event);

signals:

public slots:
};

#endif // MYLABEL_H
