#ifndef MOUSEMOVEWIDGET_H
#define MOUSEMOVEWIDGET_H

#include <QWidget>
#include <QMouseEvent>

class MouseMoveWidget : public QWidget
{
    Q_OBJECT

private:
    // 记录鼠标按下时在窗口内的位置
    QPoint mouse_pos;

public:
    explicit MouseMoveWidget(QWidget *parent = nullptr);

signals:

public slots:


    // QWidget interface
protected:

    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
};

#endif // MOUSEMOVEWIDGET_H
