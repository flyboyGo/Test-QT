#include "widget.h"
#include "ui_widget.h"
#include <QTreeWidget>
#include <QStringList>
#include <QString>
#include <QTreeWidgetItem>
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //设置树控件的头信息
    QStringList stringList;
    stringList << "英雄" << "英雄介绍" <<"难度";
    ui->treeWidget_2->setHeaderLabels(stringList);
    //ui->treeWidget_2->setHeaderItem(new QTreeWidgetItem(stringList));

    //添加顶层控件
    QTreeWidgetItem * item = new QTreeWidgetItem(QStringList() << "德玛" << "坦克、抗伤" << "1星");
    ui->treeWidget_2->addTopLevelItem(item);
    //添加次层控件
    QTreeWidgetItem *child = new QTreeWidgetItem(QStringList() << "上单");
    item->addChild(child);

    //添加顶层控件
    QTreeWidgetItem * item2 = new QTreeWidgetItem(QStringList() << "蒙多" << "坦克、抗伤" << "2星");
    ui->treeWidget_2->addTopLevelItem(item2);
    //添加次层控件
    item2->addChild(new QTreeWidgetItem(QStringList() << "上单"));

    //添加动作
    connect(ui->treeWidget, &QTreeWidget::itemClicked, [=](QTreeWidgetItem * item, int colum){
        qDebug() << item->text(colum).toUtf8().data() << endl;
    });

}

Widget::~Widget()
{
    delete ui;
}
