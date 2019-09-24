#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "mousemovewidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public MouseMoveWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_pushButtonExit_clicked();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
