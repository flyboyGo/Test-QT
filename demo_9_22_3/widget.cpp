#include "widget.h"
#include "ui_widget.h"
#include <QString>
#include <QStringList>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QDebug>
#include <QIcon>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //设置列数、行数
    ui->tableWidget->setColumnCount(4);
    ui->tableWidget->setRowCount(3);

    //设置水平、垂直表头信息
    ui->tableWidget->setHorizontalHeaderLabels(QStringList()<<"英雄"<<"性别"<<"年龄"<<"头像");
    ui->tableWidget->setVerticalHeaderLabels(QStringList()<<"1"<<"2");
    QTableWidgetItem *item = new QTableWidgetItem();
    item->setText("3");
    ui->tableWidget->setVerticalHeaderItem(3,item);

    //往表中添加控件
    QStringList name;
    name << "刘备" << "关羽" << "张飞";
    QStringList sex;
    sex << "男" << "男" << "男";
    for(int i = 0; i < 3; i++)
    {
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(name[i]));
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(sex[i]));
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(QString::number(i + 20)));
        QIcon icon = QIcon(":/image/172145130218.png");
        ui->tableWidget->setItem(i,3,new QTableWidgetItem(icon,""));
    }

    //添加动作(信号)
//    connect(ui->tableWidget,&QTableWidget::itemClicked,[=](QTableWidgetItem *item){
//        qDebug() << item->text() << endl;
//    });

    connect(ui->tableWidget,&QTableWidget::cellClicked,[=](int row,int col){
        qDebug() << "row = " << row << " col = " << col << endl;
    });

}

Widget::~Widget()
{
    delete ui;
}
