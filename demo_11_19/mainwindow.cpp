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

    //ͨ��UIָ���Ա ȥ���� UI�ļ��ϵĿؼ�
    connect(ui->actionNew, &QAction::triggered, [=](){
        qDebug() << "new file";
    });

#if 0
    //ģ̬�Ի���(Ӧ�ó��򼶱�)
    //������ģ̬�ĶԻ������ʱ���û��������ȶԶԻ�����н�����ֱ���رնԻ���Ȼ����ܷ��ʳ����������Ĵ��ڡ�
    //����һ���Ի���
    QDialog *dialog = new QDialog(this);

    //setAttribute() �������öԻ���ر�ʱ���Զ����ٶԻ���
    dialog->setAttribute(Qt::WA_DeleteOnClose);

    //�о��棺ԭ���ǵ����ĶԻ���̫С�ˣ��������öԻ���Ĵ�С
    dialog->resize(200,100);
    dialog->exec();
    qDebug() << "show modal dialog";
#endif

#if 0
    //ģ̬�Ի���(���ڼ���)
    //��ģ̬����������Ի�������Ĵ��ڣ�������Ȼ�����û���������������ڽ��������ڼ����ģ̬���������ڶര��ģʽ��
    //����һ���Ի���
    QDialog *dialog = new QDialog(this);
    //�о��棺ԭ���ǵ����ĶԻ���̫С�ˣ��������öԻ���Ĵ�С
    dialog->resize(200,100);
    dialog->open();
    qDebug() << "show modal dialog";
#endif

#if 0
    //��ģ̬�Ի���
    //����һ���Ի���
    QDialog *dialog = new QDialog(this);
    //�о��棺ԭ���ǵ����ĶԻ���̫С�ˣ��������öԻ���Ĵ�С
    dialog->resize(200,100);
    dialog->show();
    qDebug() << "show  unmodal dialog";
#endif

    //////////////////////////////////////////////////////
    //MessageBox(��Ϣ�Ի���) ������ʾ��Ϣ��ʾ������һ���ʹ�����ṩ�ļ��� static ������

#if 0
    //������Ϣ�Ի���(ģ̬�Ի���)
    QMessageBox::critical(this, "error","very critcal error,must solve at once!");
#endif
#if 0
    //��Ϣ��ʾ�Ի���(ģ̬�Ի���)
    QMessageBox::information(this, "info","important notice info");
#endif
#if 0
    //������ʾ�Ի���(ģ̬�Ի���)
    QMessageBox::warning(this, "warning","warning info");
#endif

#if 0
    //ѯ����ʾ�Ի���(ģ̬�Ի���)
    //QMessageBox::question(this, "question","reset at once,please"); //Ĭ���� Yes��No

    //�����ȡ�û�������
    //Ĭ���ǿ϶���ѡ��,����д��˳���޹�;����Ĭ��ѡ��Ϊ��
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
    //����Ի���
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
    //��ɫ�Ի���
#if 0
    QColor color;
    color = QColorDialog::getColor();
    qDebug() << "red = " << color.red() <<",green = " << color.red() << ",blue = " << color.blue() << endl;
#endif

    ////////////////////////////////////////////////////////////////////////
    //�ļ��Ի���
#if 1
    QString fileName;
    //ָ���򿪵�·����ָ����ɸѡ��ͼƬ�ļ�
    fileName = QFileDialog::getOpenFileName(this,"FileDialog","C:\\Users\\flyboy\\Desktop\\image",
                                            tr("Images(*.png *.xpm *.jpg)"));
    qDebug() << fileName << endl;
#endif

}

MainWindow::~MainWindow()
{
    delete ui;
}
