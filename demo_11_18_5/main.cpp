#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();

    /*
     * &Teacher::hungry 取函数的入口地址
       注意：信号hungry被重载了 槽函数被重载了 发生报错
       解决方法：通过函数指针 明确那个信号
       void (Teacher :: *p1)(QString foodName) = &Teacher::hungry;
       void (Student :: *p2)(QString foodName) = &Student::treat;
       connect(tea,p1,stu,p2);
     */

    return a.exec();
}
