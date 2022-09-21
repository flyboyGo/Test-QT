#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QAction>
#include <QDebug>
#include <QDialog>
#include <QMessageBox>
#include <QFontDialog>
#include <QColorDialog>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //通过ui指针成员 去访问 UI文件上的控件
    connect(ui->actionNew,&QAction::triggered,[=](){
        qDebug() << "新建文件" << endl;
    });


 //对话框的分类   模态对话框：带阻塞 非模态对话框：不阻塞
#if 0
    //模态对话框
    QDialog *dlg = new QDialog(this);
    //有警告：原因是弹出的对话框太小 可以重置对话框的大小
    dlg->resize(200,100);
    dlg->exec();
    qDebug() << "显示模态对话框" << endl;
#endif

#if 0
    //非模态对话框
    QDialog *dlg = new QDialog(this);
    //有警告：原因是弹出的对话框太小 可以重置对话框的大小
    dlg->resize(200,100);
    dlg->show();
    qDebug() << "显示非模态对话框" << endl;
#endif


    //////消息对话框(QMessageBox) 主要包含 错误提示框、信息提示框、询问对话框(重要)
#if 0
    //弹出一个错误提示框(模态的)
    QMessageBox::critical(this,"错误","很严重的错误提示");
#endif
#if 0
    //弹出一个信息提示框(模态的)
    QMessageBox::information(this,"信息","重要信息");
#endif
#if 0
    //弹出一个询问对话框(模态的)
    //QMessageBox::question(this,"询问","余额不足,请立即重置");
    //需求：更改对话框按钮的显示信息 (默认选择的是Save, 如何改为Cancel,修改第五个参数)
    //如何获取用户的选择结果
    //QMessageBox::StandardButton ret;
    int ret;
    ret = QMessageBox::question(this,"询问","余额不足,请立即重置",
                          QMessageBox::Save | QMessageBox::Cancel,
                          QMessageBox::Cancel);
    if(ret == QMessageBox::Save)
    {
        qDebug() << "已保存" << endl;
    }
    else if(ret == QMessageBox::Cancel)
    {
        qDebug() << "已取消" << endl;
    }
#endif

    ////////字体对话框(QFontDialog)
#if 0
    //字体对话框(模态对话框)
    bool yes;
    QFont font;
    font = QFontDialog::getFont(&yes,QFont("宋体"),this);
    if(yes == true)
    {
         qDebug() << "字体为：" << font.family() <<",字体大小为：" << font.pointSize() << endl;
    }
#endif


    ////////颜色对话框(QColorDialog)
#if 0
    //颜色对话框(模态对话框)
    QColor color;
    color = QColorDialog::getColor();
    qDebug() << "red = " <<color.red() << " green = " << color.green()
             << " blue = " << color.blue() << endl;
#endif


    ///////文件对话框(QFileDialog)
#if 1
    //文件对话框(模态对话框)
    QString fileName;
    fileName = QFileDialog::getOpenFileName(this,"文件对话框","D:\\QtWorkPlace\\demo_9_21_2\\image",
                                            tr("Images (*.png *.jpg)"));
    qDebug() << fileName << endl;
#endif


}

MainWindow::~MainWindow()
{
    delete ui;
}
