#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //按钮设置进度条的数值
    connect(ui->pushButton, &QPushButton::clicked,[=](){
        ui->widget->mySetValue(50);
    });

    //按钮获取进度条的数值
    connect(ui->pushButton_2, &QPushButton::clicked,[=](){
        qDebug() << "value = " << ui->widget->myGetValue() << endl;
    });
}

Widget::~Widget()
{
    delete ui;
}
