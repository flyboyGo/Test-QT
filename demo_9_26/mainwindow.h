#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextEdit>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    //打开文件函数
    void openFile();

    //保存文件函数
    void saveFile();

    //定义成员变量
    QTextEdit * textEdit;

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
