#ifndef SWIDGET_H
#define SWIDGET_H

#include <QWidget>

class SWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SWidget(QWidget *parent = 0);

signals:
    //设置回退信号
    void back();

public slots:
};

#endif // SWIDGET_H
