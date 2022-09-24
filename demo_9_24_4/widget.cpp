#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QBitmap>
#include <QPoint>
#include <QImage>
#include <QPicture>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->resize(400,300);

#if 0
    //定义QBitMap一个绘图设备
    QBitmap *bit = new QBitmap(200,200);
    //定义一个画家Painter
    QPainter *painter = new QPainter(bit);
    painter->drawEllipse(QPoint(100,100),100,100);
    //保存图片
    bit->save("D:\\QtWorkPlace\\demo_9_24_4\\bit01.jpg");
#endif


#if 0
    //定义QImage绘图设备
    QImage *img = new QImage();
    img->load(":/image/172145130218.png");
    for(int i = 50; i < 100; i++)
    {
        for(int j = 50; j < 100; j++)
        {
            int value = qRgb(255,0,0);
            img->setPixel(i,j,value);
        }
    }
    //定义一个画家painter
    QPainter *painter = new QPainter(img);
    painter->setPen(Qt::blue);
    painter->drawEllipse(0,0,100,100);
    img->save("D:\\QtWorkPlace\\demo_9_24_4\\img01.jpg");
#endif

#if 0
    //绘图设备
    QPicture *picture = new QPicture();
    //画家
    QPainter *painter = new QPainter(picture);
    //记录绘图指令
    painter->begin(picture);
    painter->drawEllipse(100,100,100,100);
    //结束绘图指令
    painter->end();
    //保存绘图指令
    picture->save("D:\\QtWorkPlace\\demo_9_24_4\\pic.order");

    //重现绘图指令 到主窗口中
#endif

}

Widget::~Widget()
{
    delete ui;
}

//重写绘图事件(实现)
void Widget::paintEvent(QPaintEvent *event)
{
#if 0
    //定义一个画家QPainter
    QPainter *painter = new QPainter(this);

    //案例：画线
    painter->drawLine(0,0,200,200);

    //设置画笔颜色
    painter->setPen(Qt::red);
    //设置画笔的样式
    //painter->setPen(Qt::DotLine);

    //画矩形框
    painter->drawRect(50,50,150,150);

    //画圆
    painter->setPen(Qt::blue);
    painter->drawEllipse(100,100,100,100);

    //画椭圆
    painter->setPen(Qt::green);
    painter->drawEllipse(150,150,150,100);
#endif

#if 1
    //重现绘图指令 到主窗口中
    QPicture picture;
    QPainter *painter = new QPainter(this);

    //绘图设备picture 加载绘图指令
    picture.load("D:\\QtWorkPlace\\demo_9_24_4\\pic.order");

    //画家根据绘图指令绘画
    painter->drawPicture(100,100,picture);
#endif
}
