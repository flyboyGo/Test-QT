#include "mybutton.h"
#include <QDebug>

MyButton::MyButton()
{

}

MyButton::~MyButton()
{
    qDebug() << "mybutton控件被析构了" << endl;
}
