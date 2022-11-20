#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QAction>
#include <QDebug>
#include <QDialog>
#include <QMessageBox>
#include <QFontDialog>
#include <QFont>
#include <QColorDialog>
#include <QColor>
#include <QFileDialog>
#include <QFile>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->resize(400,300);

    //通过UI指针成员 去访问 UI文件上的控件
    connect(ui->actionNew, &QAction::triggered, [=](){
        qDebug() << "new file";
    });

#if 0
    //模态对话框(应用程序级别)
    //当该种模态的对话框出现时，用户必须首先对对话框进行交互，直到关闭对话框，然后才能访问程序中其他的窗口。
    //创建一个对话框
    QDialog *dialog = new QDialog(this);

    //setAttribute() 函数设置对话框关闭时，自动销毁对话框
    dialog->setAttribute(Qt::WA_DeleteOnClose);

    //有警告：原因是弹出的对话框太小了，可以重置对话框的大小
    dialog->resize(200,100);
    dialog->exec();
    qDebug() << "show modal dialog";
#endif

#if 0
    //模态对话框(窗口级别)
    //该模态仅仅阻塞与对话框关联的窗口，但是依然允许用户与程序中其它窗口交互。窗口级别的模态尤其适用于多窗口模式。
    //创建一个对话框
    QDialog *dialog = new QDialog(this);
    //有警告：原因是弹出的对话框太小了，可以重置对话框的大小
    dialog->resize(200,100);
    dialog->open();
    qDebug() << "show modal dialog";
#endif

#if 0
    //非模态对话框
    //创建一个对话框
    QDialog *dialog = new QDialog(this);
    //有警告：原因是弹出的对话框太小了，可以重置对话框的大小
    dialog->resize(200,100);
    dialog->show();
    qDebug() << "show  unmodal dialog";
#endif

    //////////////////////////////////////////////////////
    //MessageBox(消息对话框) 用于显示消息提示。我们一般会使用其提供的几个 static 函数：

#if 0
    //错误消息对话框(模态对话框)
    QMessageBox::critical(this, "error","very critcal error,must solve at once!");
#endif
#if 0
    //信息提示对话框(模态对话框)
    QMessageBox::information(this, "info","important notice info");
#endif
#if 0
    //警告提示对话框(模态对话框)
    QMessageBox::warning(this, "warning","warning info");
#endif

#if 0
    //询问提示对话框(模态对话框)
    //QMessageBox::question(this, "question","reset at once,please"); //默认是 Yes、No

    //如果获取用户的输入
    //默认是肯定的选择,与填写的顺序无关;设置默认选择为否定
    //QMessageBox::StandardButton ret;
    int ret;
    ret = QMessageBox::question(this, "question","reset at once,please",
                    QMessageBox::Save | QMessageBox::Cancel, QMessageBox::Cancel);

    if(ret == QMessageBox::Save)
    {
        qDebug() << "User has selected save";
    }
    else if(ret == QMessageBox::Cancel)
    {
        qDebug() << "User has selected cancel";
    }

#endif

    ////////////////////////////////////////////////////////////////////////
    //字体对话框
#if 0
    bool ret;
    QFont font;
    font = QFontDialog::getFont(&ret,QFont("Consolas"),this);
    if(ret == true)
    {
        qDebug() << "font family : " << font.family() << ", font size : " << font.pointSize() << endl;
    }
#endif

    ////////////////////////////////////////////////////////////////////////
    //颜色对话框
#if 0
    QColor color;
    color = QColorDialog::getColor();
    qDebug() << "red = " << color.red() <<",green = " << color.red() << ",blue = " << color.blue() << endl;
#endif

    ////////////////////////////////////////////////////////////////////////
    //文件对话框
#if 1
    QString fileName;
    //指定打开的路径、指定所筛选的图片文件
    fileName = QFileDialog::getOpenFileName(this,"FileDialog","C:\\Users\\flyboy\\Desktop\\image",
                                            tr("Images(*.png *.xpm *.jpg)"));
    qDebug() << fileName << endl;
#endif

}

MainWindow::~MainWindow()
{
    delete ui;
}
