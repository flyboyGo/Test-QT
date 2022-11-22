#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //启动定时器
    int timerId = this->startTimer(1000); //单位是毫秒 函数返回的是定时器的Id
    qDebug() << "tiemrId = " << timerId << endl;
}

Widget::~Widget()
{
    delete ui;
}

//重写定时器事件
void Widget::timerEvent(QTimerEvent *event)
{
    static int time = 0;
    ui->label->setText(QString::number(time++));
    //qDebug() << "timerId = " <<  event->timerId() << endl;
}
