#include "mousemovewidget.h"
#include <QDebug>

MouseMoveWidget::MouseMoveWidget(QWidget *parent) : QWidget(parent)
{
    // 去掉标题栏
    this->setWindowFlag(Qt::FramelessWindowHint);
}

void MouseMoveWidget::mousePressEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton){
        // 记录坐标
        mouse_pos=event->pos();
    }
}

void MouseMoveWidget::mouseMoveEvent(QMouseEvent *event)
{
    // 鼠标托动窗口
    this->move(event->globalPos() - mouse_pos);
}
