#include "sonwidget.h"

SonWidget::SonWidget(QWidget *parent) : QWidget(parent)
{
    this->setWindowTitle("Son");
    this->resize(400, 300);

    this->button = new QPushButton(this);
    this->button->setText("hide son show father");

    //connect(this->button, &QPushButton::clicked, this, &SonWidget::emit_signal);

    //QT4µÄÐ´·¨
    connect(this->button, SIGNAL(clicked(bool)), this, SLOT(emit_signal()));
}

void SonWidget::emit_signal()
{
    emit show_hide_signal();
}
