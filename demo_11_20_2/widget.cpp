#include "widget.h"
#include "ui_widget.h"
#include <QTableWidget>
#include <QStringList>
#include <QPushButton>
#include <QDebug>
#include <QPixmap>
#include <QIcon>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //设置列数
    ui->tableWidget_2->setColumnCount(4);
    //设置行数
    ui->tableWidget_2->setRowCount(3);
    //设置水平、垂直表头信息
    ui->tableWidget_2->setHorizontalHeaderLabels(QStringList() << "头像" << "英雄" <<"介绍" << "难度");

    //向表格控件中填充信息
    QStringList nameList;
    nameList << "皇子" << "蝎子" << "蒙多";
    QStringList infoList;
    infoList << "打野" << "打野" << "上路";
    QStringList levelList;
    levelList << "3星" << "3星" << "3星";

    QPixmap pic;
    pic.load(":/image/172145130218.png");

    for(int i = 0; i < 3 ; i++)
    {
        ui->tableWidget_2->setItem(i, 0, new QTableWidgetItem(QIcon(pic),"头像"));
        ui->tableWidget_2->setItem(i, 1, new QTableWidgetItem(nameList[i]));
        ui->tableWidget_2->setItem(i, 2, new QTableWidgetItem(infoList[i]));
        ui->tableWidget_2->setItem(i, 3, new QTableWidgetItem(levelList[i]));
    }

    connect(ui->tableWidget_2, &QTableWidget::itemClicked, [=](QTableWidgetItem * item){
        qDebug() << item->text().toUtf8().data() << endl;
    });
    connect(ui->tableWidget_2, &QTableWidget::cellClicked, [=](int row, int column){
        qDebug() << "row = " << row << ", col = " << column << endl;
    });


}

Widget::~Widget()
{
    delete ui;
}
