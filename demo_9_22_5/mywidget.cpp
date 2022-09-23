#include "mywidget.h"
#include "ui_mywidget.h"
#include <QSpinBox>
#include <QSlider>

MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);

    //需求：改变QSpinBox的值 进度条QSlider随机值发生改变
    void (QSpinBox:: *p)(int) = &QSpinBox::valueChanged;
    connect(ui->spinBox,p,ui->horizontalSlider,&QSlider::setValue);

    //需求：拖动进度条QSlider QSpinBox的值发生改变
    connect(ui->horizontalSlider,&QSlider::valueChanged,ui->spinBox,&QSpinBox::setValue);
}

MyWidget::~MyWidget()
{
    delete ui;
}

void MyWidget::mySetValue(int value)
{
    //设置进度条QSlider的值
    ui->horizontalSlider->setValue(value);
}

int MyWidget::myGetValue()
{
    //获取进度条QSlider的值
    return ui->horizontalSlider->value();
}
