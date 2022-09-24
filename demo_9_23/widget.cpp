#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //案例：在事件分发器中 处理鼠标单击事件
    //1、重写事件分发器(MyLabel类中)
    //2、判断出鼠标单击
}

Widget::~Widget()
{
    delete ui;
}
