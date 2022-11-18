#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    //Widget中的代码可以写在此处
    this->setWindowTitle("Hello Qt"); //设置窗口的标题
    this->resize(600, 400); //可以拉伸
    this->setFixedSize(400, 300); //不可以拉伸

    //添加按钮
    button = new QPushButton(); //未指定父对象指针
    button->setText("first button");
    button->show();

    //如果不给按钮指定父对象，那么按钮和窗口是单独现实的
    //如果给按钮指定了父对象，只要父对象显示了，按钮也会显示
    QPushButton * button2 = new QPushButton(this); //制定了父对象的指针(构造函数指定)

    //QPushButton * button2 = new QPushButton("second button",this);
    //button2->setParent(this);//制定了父对象的指针(成员函数指定)

    button2->setText("second button"); //设置文本
    button2->move(100, 100); //移动控件 以左上角的窗口顶点作为参照物
    button2->show(); //设置控件可见

    //注意：在 Qt 中，尽量在组件 "构造" 的时候就指定 parent 对象，并且大胆在 "堆区" 上创建。


}

Widget::~Widget()
{
}
