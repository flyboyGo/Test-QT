#include "widget.h"
#include "ui_widget.h"
#include <QRadioButton>
#include <QDebug>
#include <QListWidget>
#include <QListWidgetItem>
#include <QList>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //给单选按钮添加动作
    //设置单选框默认选中
    ui->radioButtonMan->setChecked(true);
    ui->radioButtonNo->setChecked(true);
    connect(ui->radioButtonMan, &QRadioButton::clicked,[=](){
        qDebug() << "选中了男" << endl;
    });
    connect(ui->radioButtonWoman, &QRadioButton::clicked,[=](){
        qDebug() << "选中了女" << endl;
    });
    connect(ui->radioButtonYes, &QRadioButton::clicked,[=](){
        qDebug() << "选中了已婚" << endl;
    });
    connect(ui->radioButtonNo, &QRadioButton::clicked,[=](){
        qDebug() << "选中了未婚" << endl;
    });


    //////////列表控件
    //往列表控件中 添加 item
    QListWidgetItem *item = new QListWidgetItem("  歌单");
    ui->listWidget->addItem(item);

    //添加：静夜诗的后四句
    QStringList list;
    list << "西北情歌" << "寂寞沙洲冷" << "菊花台" << "默";
    ui->listWidget->addItems(list);

    //添加动作
    connect(ui->listWidget,&QListWidget::itemClicked,[=](QListWidgetItem *item){
        qDebug() << item->text() << endl;
    });


    ////////////树控件
    //代码实现树控件
    //设置树控件的头信息
    QStringList list2;
    list2 << "英雄" << "英雄介绍";
    ui->treeWidgetPlus->setHeaderLabels(list2);
    //方式二
    //QTreeWidgetItem *item = new QTreeWidgetItem(QStringList()<<"英雄" <<"英雄介绍");
    //ui->treeWidgetPlus->setHeaderItem(item);


    //添加顶层控件
//    QList<QTreeWidgetItem*> qL;
//    QTreeWidgetItem *item2 = new QTreeWidgetItem(QStringList()<<"猪女");
//    qL.append(item2);
//    ui->treeWidgetPlus->addTopLevelItems(qL);

    //方式二
    QTreeWidgetItem *item2 = new QTreeWidgetItem(QStringList()<<"猪女");
    ui->treeWidgetPlus->addTopLevelItem(item2);
    item2->addChild(new QTreeWidgetItem(QStringList()<<"坦克"<<"控制"));

    QTreeWidgetItem *item3 = new QTreeWidgetItem(QStringList()<<"皇子");
    ui->treeWidgetPlus->addTopLevelItem(item3);
    item3->addChild(new QTreeWidgetItem(QStringList()<<"战士"<<"打野"));

    QTreeWidgetItem *item4 = new QTreeWidgetItem(QStringList()<<"蝎子");
    ui->treeWidgetPlus->addTopLevelItem(item4);
    item4->addChild(new QTreeWidgetItem(QStringList()<<"打野"<<"控制"));

    //添加动作
    connect(ui->treeWidgetPlus,&QTreeWidget::itemClicked,[](QTreeWidgetItem *item,int column){
        qDebug() << item->text(column).toUtf8().data() << endl;
    });

}

Widget::~Widget()
{
    delete ui;
}
