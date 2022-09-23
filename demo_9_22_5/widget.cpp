#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //自定义控件 不是让你创造一个全新的控件 使用已有控件 拼出一个新的控件
    //1、定义一个自定义的控件
    //2、给自己的ui文件添加控件
    //3、在其他ui文件中使用 自定义控件MyWidget

    //自定义控件 提供外部接口
    //自定义ui控件的头文件声明接口
    //自定义ui控件的源文件中实现接口

    //需求：单击button 设置、获取QSlider进度条的值
    connect(ui->pushButton,&QPushButton::clicked,[=](){
        ui->widget->mySetValue(50);
    });
    connect(ui->pushButton_2,&QPushButton::clicked,[=](){
        qDebug() << ui->widget->myGetValue() << endl;
    });
}

Widget::~Widget()
{
    delete ui;
}
