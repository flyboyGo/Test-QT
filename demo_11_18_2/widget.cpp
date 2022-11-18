#include "widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    my_button = new MyButton();
    my_button->setParent(this);
    my_button->setText("my_button");
    //my_button->hide();
}

Widget::~Widget()
{
    qDebug() << "Widget±»Îö¹¹" << endl;
}
