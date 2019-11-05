#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QAction>
#include "mousemovewidget.h"
#include "information.h"
#include "databaseunit.h"

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

    // 获取当前界面数据信息
    Information getInformation();

    // 初始化
    void init();

    // 设置数据信息
    void setInformation(Information data);

    void on_pushButtonExit_clicked();

    void on_pushButtonDelete_clicked();

    void on_listWidgetAddress_itemSelectionChanged();

    // 设置可编辑性
    void setEditable(bool isEditable);

    void on_pushButtonModify_clicked();

    void on_pushButtonAdd_clicked();

    // 检察是否合法
    bool checkRight();

private:

    Ui::Widget *ui;

    dataBaseUnit dbUnit;

    QList<Information> informations;

    bool isEditable() const;

};
#endif // WIDGET_H
