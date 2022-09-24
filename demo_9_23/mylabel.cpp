#include "mylabel.h"
#include <QDebug>
#include <QEvent>
#include <QMouseEvent>
#include <QLabel>

MyLabel::MyLabel(QWidget *parent) : QLabel(parent)
{
    //鼠标跟踪 (用户 不用按下鼠标 也可以获得鼠标移动的位置) 设置鼠标跟踪功能(QWidget的公共函数中)
    this->setMouseTracking(false);

    //1、加载事件过滤器
    this->installEventFilter(this);

    //2、重写事件过滤器

}

void MyLabel::enterEvent(QEvent *event)
{
    qDebug() << "鼠标进入" << endl;
}

void MyLabel::leaveEvent(QEvent *event)
{
    qDebug() << "鼠标离开" << endl;
}

void MyLabel::mouseMoveEvent(QMouseEvent *event)
{
    //默认情况下  鼠标必须按下 才能移动
    //if(event->button() == Qt::LeftButton)
    {
        qDebug() << "鼠标左键移动 x = " << event->x() <<", y = " << event->y() << endl;
    }
    //else if(event->button() == Qt::RightButton)
    {
         qDebug() << "鼠标右键移动 x = " << event->x() <<", y = " << event->y() << endl;
    }
}

void MyLabel::mousePressEvent(QMouseEvent *event)
{
    //event包含了我们所需要的坐标信息
    if(event->button() == Qt::LeftButton)
    {
         qDebug() << "mousePressEvent鼠标左键按下 x = " << event->x() <<", y = " << event->y() << endl;
    }
    else if(event->button() == Qt::RightButton)
    {
         qDebug() << "mousePressEvent鼠标右键按下 x = " << event->x() <<", y = " << event->y() << endl;
    }
}

//事件分发器 (管理所有事件) e存放具体的事件
bool MyLabel::event(QEvent *e)
{
    //只处理鼠标单击事件
    if(e->type() == QEvent::MouseButtonPress)
    {
        qDebug() << "在事件分发器中鼠标单击了" <<endl;
        //注意：QEvent类中 没有x y 坐标
        //QMouseEvent类中有 x y坐标
        QMouseEvent *ev =  dynamic_cast<QMouseEvent *>(e);
        qDebug() << "x = " << ev->x() <<" , y = " << ev->y() << endl;
        return true; // 当前已经处理 不需要继续下发
    }

    //请调用父类QLable的event处理其他事件
    return QLabel::event(e);
}

//重写事件过滤器
bool MyLabel::eventFilter(QObject *watched, QEvent *event)
{
    //watched：事件发生的控件 event：控件具体产生的事件(鼠标事件、键盘事件)
    if(watched == this)
    {
        if(event->type() == QEvent::MouseButtonPress)
        {
            qDebug() << "事件过滤器中 鼠标被单击了" << endl;
            QMouseEvent *ev =  dynamic_cast<QMouseEvent *>(event);
            qDebug() << "x = " << ev->x() <<" , y = " << ev->y() << endl;
            return true; // 当前已经处理 不需要继续下发
        }
    }

    //对于其他控件以及自身其他事件 一律交给父类过滤器处理
    return QLabel::eventFilter(watched,event);

}
