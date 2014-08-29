#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    QString filename;
    QLabel *label=new QLabel(this);
    QPushButton *openbutton=new QPushButton(this);
    QPushButton *lastbutton=new QPushButton(this);
    QPushButton *nextbutton=new QPushButton(this);
    QPushButton *amplifybutton=new QPushButton(this);
    QPushButton *shrinkbutton=new QPushButton(this);
    QPushButton *fullscreenbutton=new QPushButton(this);
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;

    void keyPressEvent(QKeyEvent *event);

private slots:
    void OpenPhoto();
    void LastPhoto();
    void NextPhoto();
    void AmplifyPhoto();
    void ShrinkPhoto();
    void FullScreen();
};

#endif // WIDGET_H
