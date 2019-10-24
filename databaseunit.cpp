#include "databaseunit.h"


QString dataBaseUnit::argOfInformation(int id, Information data, int type)
{
    if(type == 0){
        return QString("mobile_number=%1,name='%2',gender=%3,fix_number=%4,remark='%5',other_infomation='%6'").arg(
                    data.getMobileNumber()).arg(
                    data.getName()).arg(
                    data.getGender()).arg(
                    data.getFixNumber()).arg(
                    data.getRemark()).arg(
                    data.getOtherInfo());
    }else if(type == 1){
        return QString("'%1',%2,%3,%4,'%5','%6',%7").arg(
                    data.getName()).arg(
                    data.getGender()).arg(
                    data.getFixNumber()).arg(
                    data.getMobileNumber()).arg(
                    data.getRemark()).arg(
                    data.getOtherInfo()).arg(
                    id);
    }else{
        return QString();
    }
}


dataBaseUnit::dataBaseUnit()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./"+databaseName);
    bool isOpen = db.open();
    query = new QSqlQuery(db);
    if(isOpen){
        // 数据库打开成功
        qDebug() << "database open success";
        // 查询表是否存在
        //query->exec(deleteTable);
        query->exec(selectTable);
        if(!query->next()){
            // 表不存在
            // 创建表
            if(query->exec(createTable)){
                // 创建成功
                qDebug() << QString("create table %1 success").arg(tableName);
            }else{
                // 创建失败
                qDebug() << QString("create table %1 failure").arg(tableName);
            }
        }else{
            // 表已存在
            qDebug() << QString("table %1 are exist").arg(tableName);
        }
    }else{
        // 数据库打开失败
        qDebug() << "database open failure";
    }
}

dataBaseUnit::~dataBaseUnit()
{
    // 释放内存
    delete query;
    // 关闭数据库
    db.close();
}


bool dataBaseUnit::Append(int id, Information data)
{
    QString sql = argOfInformation(id,data,1);
    qDebug()<<insertSql.arg(sql);
    return query->exec(insertSql.arg(sql));
}

bool dataBaseUnit::Change(int id, Information data)
{
    QString sql = argOfInformation(id,data,0);
    QString condition = QString("id=%1").arg(id);
    qDebug()<<updateSql.arg(sql).arg(condition);
    return query->exec(updateSql.arg(sql).arg(condition));
}

bool dataBaseUnit::DeleteAllData()
{
    bool res = query->exec(deleteSql.arg("TRUE"));
    query->lastError();
    return res;
}

bool dataBaseUnit::DeleteTable()
{
    return query->exec(deleteTable);
}

QList<Information> dataBaseUnit::GetAllDatas()
{
    query->exec(selectSql.arg('*').arg("TRUE"));
    QList<Information> datas;
    while(query->next()){
        Information data;
        data.setName(query->value(0).toString());
        data.setGender(query->value(1).toInt());
        data.setFixNumber(query->value(2).toInt());
        data.setMobileNumber(query->value(3).toInt());
        data.setRemark(query->value(4).toString());
        data.setOtherInfo(query->value(5).toString());
        datas.append(data);
    }
    return datas;
}
