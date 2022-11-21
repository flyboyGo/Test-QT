#include "mywidget.h"
#include "ui_mywidget.h"
#include <QSpinBox>
#include <QSlider>

MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);

    //改变spinbox的数值,slider随机发生改变
    void (QSpinBox:: *sb)(int) = &QSpinBox::valueChanged;
    connect(ui->spinBox, sb, ui->horizontalSlider, &QSlider::setValue);

    //改变slider的数值,spinbox随机发生改变
    connect(ui->horizontalSlider, &QSlider::valueChanged, ui->spinBox, &QSpinBox::setValue);
}

MyWidget::~MyWidget()
{
    delete ui;
}

//设置进度条的数值
void MyWidget::mySetValue(int value)
{
    ui->horizontalSlider->setValue(value);
}

//获取进度条的数值
int MyWidget::myGetValue()
{
    return ui->horizontalSlider->value();
}
