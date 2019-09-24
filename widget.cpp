#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : MouseMoveWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButtonExit_clicked()
{
    this->close();
}
