#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    button = new QPushButton("Print",this);

    //ע�� �ź���۵�����
    //�Զ���ۺ���
    //�ۺ�����������ͨ�ĳ�Ա������lambda���ʽ��
    //connect(button, &QPushButton::pressed, this, &Widget::print);

    connect(button, &QPushButton::pressed, [](){
        qDebug() << "hello world";
    });

}

Widget::~Widget()
{

}

void Widget::print()
{
    qDebug() << "hello world";
}
