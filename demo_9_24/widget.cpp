#include "widget.h"
#include "ui_widget.h"
#include <QTimer>
#include <QPushButton>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //案例二：启动多个定时器
    //开启两个定时器
    this->id1 = this->startTimer(1000);
    this->id2 = this->startTimer(2000);


    //案例二：定时器对象 触发定时器
    //创建定时器对象
    QTimer *timer = new QTimer(this);
    //定时器超时信号时 添加动作
    connect(timer,&QTimer::timeout,[=](){
        static int num = 0;
        ui->label_3->setText(QString::number(num++));
    });
    //启动定时器
    connect(ui->pushButton,&QPushButton::clicked,[=](){
        timer->start(1000);
    });
    //暂停定时器
    connect(ui->pushButton_2,&QPushButton::clicked,[=](){
        timer->stop();
    });


    //案例三：静态成员函数singleShot(只执行一次) 实现延时效果
    QTimer::singleShot(5000,[=](){
        ui->label_4->setText("hello world");
        ui->label_5->setText("来了");
    });

}

Widget::~Widget()
{
    delete ui;
}

//重写定时器事件(定时器事件唯一)
void Widget::timerEvent(QTimerEvent *e)
{
    static int num1 = 0;
    static int num2 = 0;

    //必须timerId()判断是那个id触发
    if(e->timerId() == this->id1)
    {
        ui->label->setText(QString::number(num1++));
    }
    else if(e->timerId() == this->id2)
    {
         ui->label_2->setText(QString::number(num2++));
    }
}
