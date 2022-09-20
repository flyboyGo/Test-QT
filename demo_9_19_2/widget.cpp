#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    //this 代表当前主窗口
    //设置标题
    this->setWindowTitle("主窗口");

    //设置窗口大小(可拖动)
    this->resize(800,600);
    //固定窗口(不可拖动)
    //this->setFixedSize(800,600);

    //窗口上设置一个按钮
    //1、导入头文件 以及 相关的qmake
    //2、使用控件相对应的类、创建控件对象
    //第一个参数 按钮控件显示的文本内容
    //第二个参数：parent父对象 控件归属的对象(使用this表示主窗口 按钮控件归属于主窗口)
    QPushButton *button = new QPushButton("戳我一下",this);

    QPushButton *button2 = new QPushButton();
    button2->setParent(this);
    button2->setWindowTitle("再戳我一下");

    //控件默认显示到主窗口的左上方
    button2->move(400,300);
}

Widget::~Widget()
{

}
