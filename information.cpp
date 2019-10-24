#include "information.h"

Information::Information()
{
    // 调用另一个构造
    Information("未命名",0,0,0,"无","无");
}

Information::Information(QString name, int gender, int fixNumber, int mobileNumber, QString remark, QString otherInfo)
{
    this->name = name;
    this->gender = gender;
    this->fixNumber = fixNumber;
    this->mobileNumber = mobileNumber;
    this->remark = remark;
    this->otherInfo = otherInfo;
}

Information::~Information()
{

}

