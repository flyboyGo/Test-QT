#include "widget.h"
#include "ui_widget.h"
#include <QRadioButton>
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //设置单选框 默认被选中的项
    ui->radioButton_man->setChecked(true);
    ui->radioButton_unmarried->setChecked(true);

    connect(ui->radioButton_man, &QRadioButton::clicked, [=](){
         qDebug() << "click radioButton_man" << endl;
    });

    connect(ui->radioButton_felman, &QRadioButton::clicked, [=](){
         qDebug() << "click radioButton_felman" << endl;
    });

    connect(ui->radioButton_married, &QRadioButton::clicked, [=](){
         qDebug() << "click radioButton_married" << endl;
    });

    connect(ui->radioButton_unmarried, &QRadioButton::clicked, [=](){
         qDebug() << "click radioButton_unmarried" << endl;
    });
}

Widget::~Widget()
{
    delete ui;
}
