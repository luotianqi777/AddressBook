#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : MouseMoveWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 获取所有信息
    informations = dbUnit.GetAllDatas();
    // 添加到listWidgt
    for(Information data: informations){
        QString name = data.getName();
        ui->listWidgetAddress->addItem(name);
    }
    // 设置listWidgt默认选择
    ui->listWidgetAddress->setCurrentRow(0);

    // 设置不可编辑
    setEditable(false);

}

Widget::~Widget()
{
    delete ui;
}

Information Widget::getInformation()
{
    Information data;
    data.setGender(ui->comboBoxGender->currentIndex());
    data.setName(ui->lineEditName->text());
    data.setRemark(ui->lineEditRemark->text());
    data.setFixNumber(ui->lineEditFixNumber->text().toInt());
    data.setMobileNumber(ui->lineEditMobileNumber->text().toInt());
    data.setOtherInfo(ui->textEdit->toPlainText());
    return data;
}

void Widget::setInformation(Information data)
{
    ui->comboBoxGender->setCurrentIndex(data.getGender());
    ui->lineEditName->setText(data.getName());
    ui->lineEditRemark->setText(data.getRemark());
    ui->lineEditFixNumber->setText(QString::number(data.getFixNumber()));
    ui->lineEditMobileNumber->setText(QString::number(data.getMobileNumber()));
    ui->textEdit->setText(data.getOtherInfo());
}

void Widget::on_pushButtonExit_clicked()
{
    // 强行维护数据
    // 仅适用于极小数据量
    // 无赖算法

    // 删除所有数据
    dbUnit.DeleteAllData();
    // 保存新数据
    for(int i=0;i<informations.size();i++){
        dbUnit.Append(i,informations.at(i));
    }
    // 退出
    this->close();
}

void Widget::on_pushButtonDelete_clicked()
{
    int index = ui->listWidgetAddress->currentRow();
    informations.removeAt(index);
    ui->listWidgetAddress->takeItem(index);
}

void Widget::on_listWidgetAddress_itemSelectionChanged()
{
    int id = ui->listWidgetAddress->currentRow();
    setInformation(informations.at(id));
}

void Widget::setEditable(bool isEditable)
{
    if(!isEditable){
        ui->lineEditName->setFocusPolicy(Qt::NoFocus);
        ui->lineEditRemark->setFocusPolicy(Qt::NoFocus);
        ui->lineEditFixNumber->setFocusPolicy(Qt::NoFocus);
        ui->lineEditMobileNumber->setFocusPolicy(Qt::NoFocus);
        ui->textEdit->setFocusPolicy(Qt::NoFocus);
        ui->comboBoxGender->setFocusPolicy(Qt::NoFocus);
    }else{
        ui->lineEditName->setFocusPolicy(Qt::FocusPolicy::ClickFocus);
        ui->lineEditRemark->setFocusPolicy(Qt::FocusPolicy::ClickFocus);
        ui->lineEditFixNumber->setFocusPolicy(Qt::FocusPolicy::ClickFocus);
        ui->lineEditMobileNumber->setFocusPolicy(Qt::FocusPolicy::ClickFocus);
        ui->textEdit->setFocusPolicy(Qt::FocusPolicy::ClickFocus);
        ui->comboBoxGender->setFocusPolicy(Qt::FocusPolicy::ClickFocus);
    }
    ui->lineEditName->setReadOnly(!isEditable);
    ui->lineEditRemark->setReadOnly(!isEditable);
    ui->lineEditFixNumber->setReadOnly(!isEditable);
    ui->lineEditMobileNumber->setReadOnly(!isEditable);
    ui->textEdit->setReadOnly(!isEditable);
    // 修改性别
    ui->comboBoxGender->setEnabled(isEditable);
    // 不可切换人物
    ui->listWidgetAddress->setEnabled(!isEditable);
}

void Widget::on_pushButtonModify_clicked()
{
    // 获取当前编辑状态
    bool isEditAble = ui->comboBoxGender->isEnabled();
    // 检查十分可编辑 是则检查是否非法
    if(isEditAble && !checkRight()){
        // 当前可编辑且非法
        QMessageBox::warning(this,"修改失败!","mobile必须不与其他人重复且不为零");
    }else{
        // 改变可编辑状态
        setEditable(!isEditAble);
    }
}

void Widget::on_pushButtonAdd_clicked()
{
    Information new_info("未命名",0,0,0,"无","无");
    informations.append(new_info);
    ui->listWidgetAddress->addItem(new_info.getName());
    ui->listWidgetAddress->setCurrentRow(informations.size()-1);
    setInformation(informations.at(informations.size()-1));
}

bool Widget::checkRight()
{
    Information current_info=getInformation();
    // mobile不能为零
    if(current_info.getMobileNumber()==0){
        return false;
    }
    int index = ui->listWidgetAddress->currentRow();
    bool updateSuccess = dbUnit.Change(index,current_info);
    if(updateSuccess){
        // 更新成功
        informations[index]=current_info;
        // 更新listWidget
        ui->listWidgetAddress->currentItem()->setText(current_info.getName());
        // 更新ui
        setInformation(current_info);
    }
    return updateSuccess;
}
