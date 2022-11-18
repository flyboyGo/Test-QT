#include "widget.h"
#include <QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    this->resize(400, 300);
    //案例：创建一个按钮，点击按钮，关闭窗口
    //创建按钮
    QPushButton * button = new QPushButton("close", this);
    //绑定槽函数
    connect(button, &QPushButton::clicked, this, &Widget::close);
}

Widget::~Widget()
{

}
