#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>
#include <QLabel>
#include <QFileDialog>
#include <QKeyEvent>


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);


    openbutton->setObjectName("OpenButton");
    openbutton->setText(tr("打开图片"));
    openbutton->setGeometry(50,10,60,20);//设置button位置和大小

    lastbutton->setObjectName("LastButton");
    lastbutton->setText(tr("上一张"));
    lastbutton->setGeometry(130,10,60,20);

    nextbutton->setObjectName("NextButton");
    nextbutton->setText(tr("下一张"));
    nextbutton->setGeometry(210,10,60,20);

    amplifybutton->setObjectName("AmplifyButton");
    amplifybutton->setText(tr("放  大"));
    amplifybutton->setGeometry(290,10,60,20);

    shrinkbutton->setObjectName("ShrinkButton");
    shrinkbutton->setText(tr("缩  小"));
    shrinkbutton->setGeometry(370,10,60,20);

    fullscreenbutton->setObjectName("FullScreenButton");
    fullscreenbutton->setText(tr("全  屏"));
    fullscreenbutton->setGeometry(450,10,60,20);

    connect(openbutton,SIGNAL(clicked()),this,SLOT(OpenPhoto()));
    connect(amplifybutton,SIGNAL(clicked()),this,SLOT(AmplifyPhoto()));
    connect(fullscreenbutton,SIGNAL(clicked()),this,SLOT(FullScreen()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::OpenPhoto()
{
    label->setObjectName("ViewPhoto");
    label->setGeometry(0,50,1350,620);
    label->setAlignment(Qt::AlignCenter);//图片在label上居中显示
    filename=QFileDialog::getOpenFileName(this,tr("打开图片"),"E:/Photo/Camera",tr("图片格式(*.jpg *.png *.bmp);;所有(*.*)"));
    QPixmap pixmap(filename);

    float x,y;
    x=pixmap.width();
    y=pixmap.height();
    //如果图片超过label的大小，将图片成比例缩小至label大小
    if(x>label->width()||y>label->height())
    {
        label->clear();
        x=label->height()*x/y;
        y=label->height();
        pixmap=pixmap.scaled(x,y,Qt::KeepAspectRatio);
        label->setPixmap(pixmap);
        label->show();
    }
    else//图片比label小，不做处理
    {
        label->clear();
        label->setPixmap(pixmap);
        label->show();
    }
}

//下一张
void Widget::NextPhoto()
{

}

//上一张
void Widget::LastPhoto()
{

}

//放大
void Widget::AmplifyPhoto()
{
//    float x,y;
//    QPixmap pixmap(filename);
//    x=pixmap.width();
//    y=pixmap.height();
//    float x_amplify,y_amplify;
//    x_amplify=label->height()*x/y;
//    y_amplify=label->height();

//    pixmap=pixmap.scaled(x_amplify*1.5,y_amplify*1.5,Qt::KeepAspectRatio);

//    label->setPixmap(pixmap);
//    label->show();
}

//缩小
void Widget::ShrinkPhoto()
{

}

//全屏显示
void Widget::FullScreen()
{


    //全屏显示————隐藏QWidget上的所有控件，并重新绘制一个大小为1366*768的label，再显示
    //1.隐藏所有Button
    openbutton->hide();
    lastbutton->hide();
    nextbutton->hide();
    amplifybutton->hide();
    shrinkbutton->hide();
    fullscreenbutton->hide();

    //2.重新设置label大小
    label->setGeometry(0,0,1366,768);
    label->setAlignment(Qt::AlignCenter);
    QPixmap pixmap(filename);

    //3.重新显示图片
    float x,y;
    x=pixmap.width();
    y=pixmap.height();

    x=label->height()*x/y;
    y=label->height();
    pixmap=pixmap.scaled(x,y,Qt::KeepAspectRatio);
    label->setPixmap(pixmap);
    label->show();

    //4.让Widget全屏
    //注意：若将此步放在第一步，则显示效果不好
    this->showFullScreen();

}

//退出全屏
void Widget::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_Escape)
    {
        //1.显示被隐藏的按钮
        openbutton->show();
        lastbutton->show();
        nextbutton->show();
        amplifybutton->show();
        shrinkbutton->show();
        fullscreenbutton->show();

        //2.重新设置label大小
        label->setGeometry(0,50,1350,620);
        label->setAlignment(Qt::AlignCenter);
        QPixmap pixmap(filename);

        //3.重新显示图片
        float x,y;
        x=pixmap.width();
        y=pixmap.height();

        x=label->height()*x/y;
        y=label->height();
        pixmap=pixmap.scaled(x,y,Qt::KeepAspectRatio);
        label->setPixmap(pixmap);
        label->show();

        //4.窗体正常显示
        this->showNormal();

    }
}
