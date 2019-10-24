#ifndef DATABASEUNIT_H
#define DATABASEUNIT_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <bits/ios_base.h>
#include "information.h"

/*
 * 数据库模块
 */
class dataBaseUnit
{
private:

    QString databaseName = "DB.db";
    QString tableName = "Address";
    QString createTable = QString("CREATE TABLE %1( \
                                  name CHAR(10) NOT NULL,\
                                  gender INT NOT NULL,\
                                  fix_number INT,\
                                  mobile_number INT UNIQUE NOT NULL,\
                                  remark CHAR(20),\
                                  other_infomation CHAR(50),\
                                  id INT PRIMARY KEY NOT NULL\
                                  );").arg(tableName);

    QString deleteTable = QString("DROP TABLE %1;").arg(tableName);
    QString insertSql = QString("INSERT INTO %1 VALUES(%2);").arg(tableName);
    QString updateSql = QString("UPDATE %1 SET %2 WHERE %3;").arg(tableName);
    QString deleteSql = QString("DELETE FROM %1 WHERE %2;").arg(tableName);
    QString selectSql = QString("SELECT %2 FROM %1 WHERE %3;").arg(tableName);
    QString selectTable = QString("SELECT * FROM sqlite_master WHERE type = 'table' AND name = '%1';").arg(tableName);

    QSqlDatabase db;
    QSqlQuery *query;

    // 获取参数
    QString argOfInformation(int id, Information data, int type);

public:
    dataBaseUnit();
    ~dataBaseUnit();
    // 添加一条数据
    bool Append(int id,Information data);
    //bool Delete();
    // 更改一条数据
    bool Change(int id, Information data);
    //bool Search();
    // 删除所有数据
    bool DeleteAllData();
    // 删除表
    bool DeleteTable();
    // 获取所有数据
    QList<Information> GetAllDatas();
}; 
#endif // DATABASEUNIT_H

