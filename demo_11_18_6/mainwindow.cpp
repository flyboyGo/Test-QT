#include "mainwindow.h"
#include <QMenuBar>
#include <QMenu>
#include <QAction>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->resize(400, 300);
    //从QMainWindow中取出菜单栏
    QMenuBar *menuBar = this->menuBar();
    //向菜单栏中添加菜单
    QMenu * fileMenu = menuBar->addMenu("File");
    QMenu * editMenu = menuBar->addMenu("Edit");
    //向菜单中添加菜单项
    QAction * openAction = fileMenu->addAction("open");
    fileMenu->addSeparator();//添加分割线
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
