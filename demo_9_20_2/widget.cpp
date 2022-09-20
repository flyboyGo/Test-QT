#include "widget.h"
#include "teacher.h"
#include "student.h"
#include <QPushButton>
#define N 1

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    //设置主窗口大小
    this->resize(800,600);
    //实例化一个老师
    Teacher *tea = new Teacher(this);
    //实例化一个学生
    Student *stu = new Student(this);

#if N
    //connect建立老师、学生的关系
    void (Teacher:: *p1)() = &Teacher::hungry;
    void (Student:: *p2)() = &Student::treat;
    connect(tea,p1,stu,p2);
#else
    //&Teacher::hungry 取函数的入口地址
    //注意：信号hungry被重载了 槽函数被重载了 发生报错
    //解决方法：通过函数指针 明确那个信号
    void (Teacher:: *p1)(QString foodName) = &Teacher::hungry;
    void (Student:: *p2)(QString foodName) = &Student::treat;
    connect(tea,p1,stu,p2);
#endif

    //信号 连接 信号
//    QPushButton *button3 = new QPushButton("下课",this);
//    connect(button3,&QPushButton::clicked,tea,p1);

    //一旦下课 老师饿了
    //3、用户可以使用emit发出信号
    QPushButton *button = new QPushButton("下课",this);
    connect(button,&QPushButton::clicked,[=](){
#if N
        //下课函数：让老师发出饿的信号
        emit tea->hungry();
#else
        emit tea->hungry("黄焖鸡");
#endif

    });
}
/*
 * 总结：
1、一个信号可以和多个槽相连
   如果是这种情况，这些槽会一个接一个的被调用，但是它们的 调用顺序是不确定的。
2、多个信号可以连接到一个槽
   只要任意一个信号发出，这个槽就会被调用。
3、一个信号可以连接到另外的一个信号
  当第一个信号发出时，第二个信号被发出。除此之外，这种信号-信号的形式和信号-槽的形式没有什么区别。
4、槽可以被取消链接
   这种情况并不经常出现，因为当一个对象delete之后，Qt自动取消所有连接到这个对象上面的槽。
5、Qt4版本的信号槽写法
   connect(tea,SIGNAL(hungry()), stu, SLOT(treat()))
6、Qt5版本的信号槽写法
   connect(tea, &Teacher::hungry, stu, &Student::treat)
 */

Widget::~Widget()
{

}
