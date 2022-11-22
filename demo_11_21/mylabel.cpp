#include "mylabel.h"
#include <QDebug>
#include <QMouseEvent>
#include <QEvent>

MyLabel::MyLabel(QWidget *parent) : QLabel(parent)
{
    //设置鼠标跟踪功能(用户不需要按下鼠标再移动 也可以获取鼠标的移动位置),QWidget中的公共函数
    this->setMouseTracking(false);

    //1、加载事件过滤器(QObject类中Public Functions找到)
    this->installEventFilter(this);
}

//重写鼠标进入事件
void MyLabel::enterEvent(QEvent *event)
{
    qDebug() << "鼠标进入了" << endl;
}

//重写鼠标离开事件
void MyLabel::leaveEvent(QEvent *event)
{
    qDebug() << "鼠标离开了" << endl;
}

//重写事件按下事件
void MyLabel::mousePressEvent(QMouseEvent *event)
{
    //ev包含了我们所需要的坐标信息、按键信息等各项信息
    if(event->button() == Qt::LeftButton)
    {
        //全局坐标信息
        qDebug() << "mousePressEvent鼠标左键按下了" << "x = " << event->globalX() << " y = " << event->globalY() << endl;
    }
    else if(event->button() == Qt::RightButton)
    {
        //局部坐标信息
        qDebug() << "mousePressEvent鼠标右键按下了" << "x = " << event->x() << " y = " << event->y() << endl;
    }
}

//重写鼠标移动事件
void MyLabel::mouseMoveEvent(QMouseEvent *event)
{
    //mouse move事件 的返回值永远是Qt:NoButton 所以根本不会打印左右键移动
    //默认情况下 必须鼠标按下后再移动 才能识别到鼠标移动事件
    //鼠标跟踪(用户不需要按下鼠标再移动 也可以获取鼠标的移动位置),QWidget中的公共函数
    qDebug() << "鼠标移动了" << "x = " << event->x() << " y = " << event->y() << endl;
}

//重写事件分发器(每一个类(控件)，都有一个从父类继承过来的分发器)  event存放具体的事件
bool MyLabel::event(QEvent *event)
{
    //只处理鼠标按下事件
    if(event->type() == QEvent::MouseButtonPress)
    {
        qDebug() << "事件分发器中鼠标单击" << endl;
        //return QLabel::event(event); //交给父类的事件分发器，继续按照原有的路线继续处理
        //注意：QEvent类没有 x,y;QMouseEvent类有x,y
        QMouseEvent *ev = static_cast<QMouseEvent *>(event);
        qDebug() << ev->x() << " , " << ev->y() << endl;
        return true; //当前已经处理 不需要继续下分
    }

    //其他事件,调用父类的事件分发器，继续处理其他事件
    return QLabel::event(event);
}

//定义事件过滤函数
/*
 *  事件过滤器的调用时间是目标对象（也就是参数里面的 watched 对象）接收到事件对象之前。
 *  也就是说，如果你在事件过滤器中停止了某个事件，
 *  那么watched 对象以及以后所有的事件过滤器根本不会知道这么一个事件
 */
//2、重写事件过滤器(1、在mylabel.h声明 事件过滤器函数 2、在mylabel.cpp中实现 事件过滤函数)
bool MyLabel::eventFilter(QObject *watched, QEvent *event)
{
    //watched:事件发生的控件
    //event:具体的事件信息
    if(watched == this)
    {
        if(event->type() == QEvent::MouseButtonPress)
        {
            QMouseEvent *ev = static_cast<QMouseEvent *>(event);
            qDebug() << "事件过滤器中鼠标被单击了" << "x = " << ev->x() << " y = " << ev->y() << endl;
            return true; //当前控件 的 鼠标点击事件 已处理
        }
    }

    //对于其他控件以及事件 统统交给父类的过滤函数处理
    return QLabel::eventFilter(watched, event);

}

/*
 * 事件
过滤器可以安装到任意 QObject 类型上面，并且可以安装多个。
如果要实现全局的事件过滤器，则可以安装到 QApplication 或者 QCoreApplication 上面。

这里需要注意的是，如果使用 installEventFilter()函数给一个对象安装事件过滤器，
那么该事件过滤器只对该对象有效，只有这个对象的事件需要先传递给事件过滤器的 eventFilter() 函数进行过滤,
其它对象不受影响。

如果给QApplication 对象安装事件过滤器，那么该过滤器对程序中的每一个对象都有效，
任何对象的事件都是先传给 eventFilter()函数。
 */
