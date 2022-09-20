#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    //界面的设计是在 窗口构造的函数中设计
    //this 代表的是当前的主窗口

    //设置主窗口的标题
    this->setWindowTitle("主窗口");
    //获取窗口的标题
    //this->windowTitle();
}

Widget::~Widget()
{

}
