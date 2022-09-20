#include "swidget.h"
#include "QPushButton"

SWidget::SWidget(QWidget *parent) : QWidget(parent)
{
    //设置窗口大小
    this->resize(600,400);
    this->setWindowTitle("查询窗口");

    //创建一个返回按钮
    QPushButton *button =new QPushButton("back",this);
    connect(button,&QPushButton::clicked,[=](){
        //发送回退信号
        emit this->back();
    });
}
