#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMenu>
#include <QMenuBar>
#include <QDebug>
#include <QAction>
#include <QTabBar>
#include <QString>
#include <QFileDialog>
#include <QFile>
#include <QIODevice>
#include <QMessageBox>
#include <QTextStream>
#include <QTextEdit>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QMenuBar *menuBar = new QMenuBar(this);
    this->setMenuBar(menuBar);

    QMenu *file = new QMenu("文件",this);
    menuBar->addMenu(file);

    QAction *OpenFile = new QAction("打开",this);
    QAction *SaveFile = new QAction("保存",this);
    file->addAction(OpenFile);
    file->addAction(SaveFile);


    QToolBar *toolBar = new QToolBar(this);
    this->addToolBar(toolBar);

    toolBar->addAction(OpenFile);
    toolBar->addSeparator();
    toolBar->addAction(SaveFile);

    connect(OpenFile,&QAction::triggered,this,&MainWindow::openFile);
    connect(SaveFile,&QAction::triggered,this,&MainWindow::saveFile);

    textEdit = new QTextEdit(this);
    this->setCentralWidget(textEdit);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openFile()
{
    QString path = QFileDialog::getOpenFileName(this,tr("Open File"),
                                       ":/file/text.txt",tr("Text Files(*.txt)"));
    if(!path.isEmpty())
    {
        QFile file(path);
        if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            QMessageBox::warning(this,tr("Read File"),tr("Cannot open file:\n%1").arg(path));
            return;
        }

        QTextStream in(&file);
        textEdit->setText(in.readAll());
        file.close();
    }
    else
    {
        QMessageBox::warning(this, tr("Path"),tr("You did not select any file."));
    }
}

void MainWindow::saveFile()
{
    QString path = QFileDialog::getSaveFileName(this,tr("Save File"),
                                       ":/file/text.txt", tr("Text Files(*.txt)"));
    if(!path.isEmpty())
    {
        QFile file(path);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            QMessageBox::warning(this, tr("Write File"),
                              tr("Cannot open file:\n%1").arg(path));
            return;
        }
        QTextStream out(&file);
        out << textEdit->toPlainText();
        file.close();
    }
    else
    {
        QMessageBox::warning(this, tr("Path"),tr("You did not select any file."));
    }
}
