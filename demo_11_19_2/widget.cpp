#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>
#include <QLabel>
#include <QDebug>
#include <QString>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //单击登录，获取用户输入的用户名和密码
    connect(ui->pushButton_login, &QPushButton::clicked, [=](){
        //获取用户名、密码
        QString usr_name =  ui->lineEdit_name->text();
        QString usr_pwd =  ui->lineEdit_pwd->text();

        qDebug() <<"user_name:" << usr_name << ", usr_pwd:" << usr_pwd << endl;

    });

    connect(ui->pushButton_cancel, &QPushButton::clicked, [=](){
        ui->lineEdit_name->setText("");
        ui->lineEdit_pwd->setText("");
    });
}

Widget::~Widget()
{
    delete ui;
}
