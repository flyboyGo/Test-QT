#include "widget.h"
#include "ui_widget.h"
#include <QComboBox>
#include <QDebug>
#include <QLabel>
#include <QPixmap>
#include <QMovie>
#include <QSize>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //给下拉列表框 添加选项
    QStringList list;
    list << "大众" << "奔驰" << "宝马" << "奥迪";
    ui->comboBox_2->addItems(list);
    ui->comboBox_2->setCurrentIndex(3);

    //信号、槽函数发生重载时,需要通过指针单独指定
    void (QComboBox:: *cur)(int) = &QComboBox::currentIndexChanged;
    connect(ui->comboBox_2, cur, [=](int index){
        qDebug() <<  index << " : " << ui->comboBox_2->currentText().toUtf8().data();
    });


    //Label控件
    //设置文本
    ui->label->setText("flight again");
    //获取文本
    qDebug() << ui->label->text() << endl;

    //设置图片
    QPixmap pix;
    pix.load(":/image/172145130218.png");
    ui->label_2->resize(200,200);
    ui->label_2->setPixmap(pix);


    //设置动画
    QMovie *movie = new QMovie(":/image/mario.gif");
    //设置动画的大小
    movie->setScaledSize(QSize(400,200));
    ui->label_3->setMovie(movie);

    //设置动画播放、暂停的动作
    connect(ui->pushButton, &QPushButton::clicked,[=](){
        movie->start();
    });
    connect(ui->pushButton_2, &QPushButton::clicked,[=](){
        movie->stop();
    });

    //使用 QLineEdit 类的 setEchoMode () 函数设置文本的显示模式
    /*
     *EchoMode 是一个枚举类型,一共定义了四种显示模式:
      QLineEdit::Normal 模式显示方式，按照输入的内容显示。
      QLineEdit::NoEcho 不显示任何内容，此模式下无法看到用户的输入。
      QLineEdit::Password 密码模式，输入的字符会根据平台转换为特殊字符。
      QLineEdit::PasswordEchoOnEdit 编辑时显示字符否则显示字符作为密
     */

    //另外，我们再使用 QLineEdit 显示文本的时候，希望在左侧留出一段空白的区域，
    //那么，就可以使用 QLineEdit 给我们提供的 setTextMargins 函数：

}

Widget::~Widget()
{
    delete ui;
}
