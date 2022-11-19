#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    this->setWindowTitle("Father");
    this->resize(400,300);

    this->sonWidget = new SonWidget();
    //this->sonWidget->show(); //初始不显示子窗口

    this->button = new QPushButton(this);
    this->button->setText("hide father show son");

//    connect(this->button, &QPushButton::clicked, [=](){
//        this->hide();
//        this->sonWidget->show();
//    });
    /*
     * 发送者和接收者都需要是 QObject类 的子类
     * 当然槽函数如果是全局函数、Lambda表达式等 无需接收者的时候除外
     */

   connect(this->button, &QPushButton::clicked, this, &Widget::button_cb);
   connect(this->sonWidget, &SonWidget::show_hide_signal, this, &Widget::signal_cb);
}

Widget::~Widget()
{

}

void Widget::button_cb()
{
    this->hide();
    this->sonWidget->show();
}

void Widget::signal_cb()
{
    this->show();
    this->sonWidget->hide();
}
