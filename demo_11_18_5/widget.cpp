#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    this->setWindowTitle("Father");
    this->resize(400,300);

    this->sonWidget = new SonWidget();
    //this->sonWidget->show(); //��ʼ����ʾ�Ӵ���

    this->button = new QPushButton(this);
    this->button->setText("hide father show son");

//    connect(this->button, &QPushButton::clicked, [=](){
//        this->hide();
//        this->sonWidget->show();
//    });
    /*
     * �����ߺͽ����߶���Ҫ�� QObject�� ������
     * ��Ȼ�ۺ��������ȫ�ֺ�����Lambda���ʽ�� ��������ߵ�ʱ�����
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
