#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //定时器(QTimer)触发的三种方式
    //1、定时器事件触发(timerEvent)循环执行
    //重写定时器事件
    //启动定时器事件(startTimer 返回值为定时器Id)

    //案例一：启动一个定时器
    this->startTimer(1000);//单位是毫秒

    //2、定时器对象(信号)触发 循环执行
    //3、定时器 静态成员函数singleShot触发 只执行一次

}

Widget::~Widget()
{
    delete ui;
}

//重写定时器事件(定时器事件唯一)
void Widget::timerEvent(QTimerEvent *e)
{
    static int time = 0;
    ui->label->setText(QString::number(time++));
}
