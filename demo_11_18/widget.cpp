#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    //Widget�еĴ������д�ڴ˴�
    this->setWindowTitle("Hello Qt"); //���ô��ڵı���
    this->resize(600, 400); //��������
    this->setFixedSize(400, 300); //����������

    //��Ӱ�ť
    button = new QPushButton(); //δָ��������ָ��
    button->setText("first button");
    button->show();

    //���������ťָ����������ô��ť�ʹ����ǵ�����ʵ��
    //�������ťָ���˸�����ֻҪ��������ʾ�ˣ���ťҲ����ʾ
    QPushButton * button2 = new QPushButton(this); //�ƶ��˸������ָ��(���캯��ָ��)

    //QPushButton * button2 = new QPushButton("second button",this);
    //button2->setParent(this);//�ƶ��˸������ָ��(��Ա����ָ��)

    button2->setText("second button"); //�����ı�
    button2->move(100, 100); //�ƶ��ؼ� �����ϽǵĴ��ڶ�����Ϊ������
    button2->show(); //���ÿؼ��ɼ�

    //ע�⣺�� Qt �У���������� "����" ��ʱ���ָ�� parent ���󣬲��Ҵ��� "����" �ϴ�����


}

Widget::~Widget()
{
}
