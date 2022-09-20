#include "widget.h"
#include "QPushButton"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    //设置窗口标题
    this->setWindowTitle("信号");
    //设置窗口大小
    this->resize(800,600);
    this->setFixedSize(800,600);
    //创建一个按钮
    QPushButton *button =new QPushButton("关闭",this);
    //需求：单击按钮 关闭主窗口
    //信号的发起者button 发出信号 主窗口this 关闭(槽函数)

    //建立：信号与槽函数的关系使用connect()
    connect(button,&QPushButton::clicked,this,&Widget::close);

    //lambda表达式
    QPushButton *button2 = new QPushButton("戳我一下",this);
    button2->move(400,300);
    //= 是lambda可以获取当前所在作用域中的控件
    connect(button2,&QPushButton::clicked,[=](){
        //获取按钮上的文本
        QString text = button2->text();
        qDebug() << text<< endl;

        //设置按钮的文本
        button2->setText("戳你乍地");
    });

}

Widget::~Widget()
{

}
