#include "widget.h"
#include <QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    this->resize(400, 300);
    //����������һ����ť�������ť���رմ���
    //������ť
    QPushButton * button = new QPushButton("close", this);
    //�󶨲ۺ���
    connect(button, &QPushButton::clicked, this, &Widget::close);
}

Widget::~Widget()
{

}
