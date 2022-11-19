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
    //�ź�û�з���ֵ���������в���; �ź�ֻ��Ҫ����������Ҫ����
    void show_hide_signal();

public slots:
    void emit_signal();
};

#endif // SONWIDGET_H
