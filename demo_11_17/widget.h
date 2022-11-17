#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget> //所有控件的基类 就是一个空白窗口 所有的控件都是在一个空白的窗口(Widget)上衍生而来
/*
 * 在 Qt 中，我们将窗口和控件统称为部件（Widget）。
   窗口是指程序的整体界面，可以包含标题栏、菜单栏、工具栏、关闭按钮、最小化按钮、最大化按钮等。
   控件是指按钮、复选框、文本框、表格、进度条等这些组成程序的基本元素。
   一个程序可以有多个窗口，一个窗口也可以有多个控件。

    QWidget 是所有用户界面元素的基类，窗口和控件都是直接或间接继承自 QWidget，
    QMainWindow、QWidget、QDialog 三个类就是用来创建窗口的，可以直接使用也可以继承后再使用。
    QMainWindow 窗口可以包含菜单栏、工具栏、状态栏、标题栏等，是最常见的窗口形式，可以作为 GUI 程序的主窗口。

    如果是主窗口，就使用 QMainWindow；如果是对话框，就是用 QDialog；
    如果不确定，或有可能作为顶级窗口，也有可能嵌入到其他窗口中，那么使用 QWidget。

    需要注意的是，窗口和控件都继承自 QWidget，如果不为控件指定父对象，它就会被作为窗口处理，
    这时 setWindowTitle() 和 setWindowIcon() 函数就会生效
 */


class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
};

#endif // WIDGET_H
