#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    //������������ ���ڹ���ĺ��������
    //this ������ǵ�ǰ��������

    //���������ڵı���
    this->setWindowTitle("������");
    //��ȡ���ڵı���
    //this->windowTitle();
}

Widget::~Widget()
{

}
