#include "widget.h"
#include "ui_widget.h"
#include <QComboBox>
#include <QString>
#include <QStringList>
#include <QDebug>
#include <QLabel>
#include <QPixmap>
#include <QMovie>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //下拉列表框 添加选项
    QStringList list;
    list << "宝马" <<"奔驰" <<"奥迪" << "大众";
    ui->comboBox_2->addItems(list);

    //设置默认项
    ui->comboBox_2->setCurrentIndex(3);

    //设置动作(信号)
    //重载的信号函数 不可以直接使用 需要使用函数指针匹配(使用系统槽函数也需要注意)
    void (QComboBox:: *p)(int) = &QComboBox::currentIndexChanged;//函数名地址
    connect(ui->comboBox_2,p,[=](int index){
        qDebug() << "index = " << index << endl;
        qDebug() << ui->comboBox_2->currentText() << endl;
    });

//    connect(ui->comboBox_2,&QComboBox::currentTextChanged,[=](QString text){
//        qDebug() << text << endl;
//    });


    //Label控件
    //设置文本、获取文本
    ui->label_2->setText("hehe");
    qDebug() << ui->label_2->text() << endl;

    //设置图片
    //QPixmap控件加载图片
    QPixmap pix;
    pix.load(":/image/172145130218.png");
    ui->label_3->setPixmap(pix);

    //设置动画
    //QMovie控件加载动画
    QMovie *move = new QMovie(":/image/mario.gif");
    //设置动画页面的大小
    //move->setScaledSize(QSize(800,300));
    ui->label_4->setMovie(move);

    //播放动画
    connect(ui->pushButtonStart,&QPushButton::clicked,[=](){
        move->start();
    });
    //结束动画
    connect(ui->pushButtonStop,&QPushButton::clicked,[=](){
        move->stop();
    });

}

Widget::~Widget()
{
    delete ui;
}
