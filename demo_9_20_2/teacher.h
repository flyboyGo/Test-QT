#ifndef TEACHER_H
#define TEACHER_H

#include <QObject>
#include <QString>

class Teacher : public QObject
{
    Q_OBJECT
public:
    explicit Teacher(QObject *parent = 0);

signals: //1、自定义信号函数
//定义信号的规则 (返回值类型为void 只需声明 无需实现 可以有参数 可以重载)
void hungry();

//信号中含有参数 发送信号时 槽函数可以选择是否接收(槽函数声明中可以定义参数接收)
void hungry(QString foodName);

public slots:
};

#endif // TEACHER_H
