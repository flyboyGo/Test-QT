#include "student.h"
#include <QDebug>

Student::Student(QObject *parent) : QObject(parent)
{

}

void Student::treat()
{
    qDebug() << "请老师吃饭" << endl;
}

void Student::treat(QString foodName)
{
    qDebug() << "请老师吃饭 " << foodName << endl;
}
