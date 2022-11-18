#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    button = new QPushButton("Print",this);

    //注册 信号与槽的链接
    //自定义槽函数
    //槽函数可以是普通的成员函数、lambda表达式等
    //connect(button, &QPushButton::pressed, this, &Widget::print);

    connect(button, &QPushButton::pressed, [](){
        qDebug() << "hello world";
    });

}

Widget::~Widget()
{

}

void Widget::print()
{
    qDebug() << "hello world";
}
