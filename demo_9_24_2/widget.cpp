#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QPixmap>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->resize(400,300);
}

Widget::~Widget()
{
    delete ui;
}

//重写绘图事件(实现) 主窗口加载时 调用绘图事件
void Widget::paintEvent(QPaintEvent *event)
{
    //实现绘制背景图片
    //定义一个画家(QPainter) 画图片
    QPainter *painter = new QPainter(this);

    //定义一个图片控件 记载图片
    QPixmap pix;
    pix.load(":/image/172145130218.png");
    //修改图片大小(和窗口的大小一致)
    pix.scaled(this->width(),this->height());

    //画家在主窗口绘画
    painter->drawPixmap(0,0,this->width(),this->height(),pix);

}
