#ifndef SONWIDGET_H
#define SONWIDGET_H

#include <QWidget>
#include <QPushButton>

class SonWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SonWidget(QWidget *parent = 0);
    QPushButton * button;

signals:
    //信号没有返回值，但可以有参数; 信号只需要声明，不需要定义
    void show_hide_signal();

public slots:
    void emit_signal();
};

#endif // SONWIDGET_H
