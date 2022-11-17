#-------------------------------------------------
#
# Project created by QtCreator 2022-11-17T19:29:29
#
#-------------------------------------------------

QT       += core gui #包含的功能模块

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = demo_11_17 #项目名

TEMPLATE = app
#模板变量告诉 qmake 为这个应用程序生成哪种 makefile
#lib - 建立一个库的 makefile
#vcapp - 建立一个应用程序的 VisualStudio 项目文件。
#vclib - 建立一个库的 VisualStudio 项目文件。

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


#CONFIG += c++11 //使用 c++11 的特性
#在这里使用“+=”，是因为我们添加我们的配置选项到任何一个已经存在中

#源文件
SOURCES += main.cpp\
        widget.cpp

#库文件
HEADERS  += widget.h
