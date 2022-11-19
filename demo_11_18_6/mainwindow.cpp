#include "mainwindow.h"
#include <QMenuBar>
#include <QMenu>
#include <QAction>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->resize(400, 300);
    //��QMainWindow��ȡ���˵���
    QMenuBar *menuBar = this->menuBar();
    //��˵�������Ӳ˵�
    QMenu * fileMenu = menuBar->addMenu("File");
    QMenu * editMenu = menuBar->addMenu("Edit");
    //��˵�����Ӳ˵���
    QAction * openAction = fileMenu->addAction("open");
    fileMenu->addSeparator();//��ӷָ���
    QAction * saveAction =fileMenu->addAction("save");
    fileMenu->addSeparator();
    QAction * closeAction =fileMenu->addAction("close");

    QAction * copyAction =editMenu->addAction("copy");
    fileMenu->addSeparator();
    QAction * pasteAction =editMenu->addAction("paste");
    fileMenu->addSeparator();
    QAction * cutAction =editMenu->addAction("cut");

}

MainWindow::~MainWindow()
{

}
