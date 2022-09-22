#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>
#include <QString>
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //单击登录 获取用户输入的用户名、密码
    connect(ui->LoginInButton,&QPushButton::clicked,[=](){
        //获取用户名、密码
        QString username = ui->lineEditUser->text();
        QString pwd = ui->lineEditPwd->text();
        qDebug() << "用户名 = " << username << " 密码 = " << pwd << endl;

    });
}

Widget::~Widget()
{
    delete ui;
}
