#ifndef INFORMATION_H
#define INFORMATION_H
#include <QString>

/*
 * 信息类
 * 储存基本信息
 */

class Information
{
private:
    int gender;
    int fixNumber;
    int mobileNumber;
    QString name;
    QString remark;
    QString otherInfo;
public:
    Information();
    Information(QString name,int gender,int fixNumber, int mobileNumber, QString remark,QString otherInfo);
    inline int getGender() { return gender; }
    inline QString getName() { return name; }
    inline int getFixNumber() { return fixNumber; }
    inline int getMobileNumber() { return mobileNumber; }
    inline QString getRemark() { return remark; }
    inline QString getOtherInfo() { return otherInfo; }
    inline void setGender(int gender) { this->gender = gender; }
    inline void setName(QString name) { this->name = name; }
    inline void setFixNumber(int fixNumber) { this->fixNumber = fixNumber; }
    inline void setMobileNumber(int mobileNumber) { this->mobileNumber = mobileNumber; }
    inline void setRemark(QString remark) { this->remark = remark; }
    inline void setOtherInfo(QString otherInfo) { this->otherInfo = otherInfo; }
    ~Information();

};

#endif // INFORMATION_H
