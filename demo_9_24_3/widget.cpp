#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QPixmap>
#include <QTimer>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->resize(800,600);

    //将button移动到最下方的中间位置
    //窗口的 宽：this->width()、高：this->height()
    //按钮的 宽：ui->pushButton->width() 高：ui->pushButton->height()
    ui->pushButton->resize(120,60);
    ui->pushButton->move((this->width()-ui->pushButton->width())*0.5,
                          this->height()-ui->pushButton->height());

    //button添加动作
    connect(ui->pushButton,&QPushButton::clicked,[=](){
        //重新加载绘图事件
        this->update();
    });


    //使用定时器
    QTimer *timer = new QTimer(this);
    //定时器超时信号时 添加动作
    connect(timer,&QTimer::timeout,[=](){
        this->update();
    });
    //启动定时器
    timer->start(20);
}

Widget::~Widget()
{
    delete ui;
}

//重写绘图事件(实现)
//案例：使用update() 实现加载绘图事件
void Widget::paintEvent(QPaintEvent *event)
{
    static int x = 0;
    //定义一个画家Painter
    QPainter *painter = new QPainter(this);

    //定义图片控件QPixmap
    QPixmap pix;
    pix.load(":/image/172145130218.png");
    //此时pix默认无大小,加载完图片后 pxi的大小是图片的大小
    pix.scaled(pix.width()*0.5,pix.height()*0.5);

    //画家绘图
    //drawPixmap前两个参数是起点坐标
    painter->drawPixmap(x,0,pix.width(),pix.height(),pix);
    if(x >= this->width())
    {
        x = 0;
    }
    else
    {
        x+=1;
    }
}
