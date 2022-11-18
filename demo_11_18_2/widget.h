#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "mybutton.h"

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

    MyButton * my_button;
};

#endif // WIDGET_H
