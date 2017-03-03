#include "RecordDao.h"

RecordDao::RecordDao()
{

}

bool RecordDao::insert(Record record)
{
    //get database connection
     QSqlDatabase dbSQL=DatabaseConnection::getConnection();
     if(!dbSQL.isOpen()) return false;
    //construct the database query object
    QSqlQuery query;
    query.prepare("insert  into signrecord(ID,studentID,startTime,endTime,intervalTime) values(?,?,?,?,?)");
    query.bindValue(1,Util::toQString(record.getStuId()));
    query.bindValue(2,Util::toQString(record.getStartTime()));
    query.bindValue(3,Util::toQString(record.getEndTime()));
    query.bindValue(4,record.getCount());
    //get the result of execute the query string
    bool succ=query.exec();
    if(succ) qDebug()<<"插入成功";
    else qDebug()<<"插入失败"<<query.lastError();
    return succ;
}

list<Record> RecordDao::findAll()
{
    list<Record> records;
    //get database connection
     QSqlDatabase dbSQL=DatabaseConnection::getConnection();
    //construct the database query object
    QSqlQuery query;
    query.prepare("select * from signrecord");
    //get the result of execute the query string
    bool succ=query.exec();
    int numRows=succ?0:-1;
    if(dbSQL.driver()->hasFeature(QSqlDriver::QuerySize)){
        numRows=query.size();
    } else{
        query.last();
        numRows=query.at()+1;
    }
    Record record;
    while(query.next()){
        record.setId(query.value(0).toString().toInt());
        record.setStuId(query.value(1).toString().toStdString());
        record.setStartTime(query.value(2).toString().toStdString());
        record.setEndTime(query.value(3).toString().toStdString());
        record.setCount(query.value(4).toString().toFloat());
        records.push_back(record);
    }
    DatabaseConnection::close(dbSQL);
    return records;

}

Record RecordDao::findById(string id)
{
    Record record;
   //get database connection
    QSqlDatabase dbSQL=DatabaseConnection::getConnection();
    if(!dbSQL.isOpen()) return record;
   //construct the database query object
   QSqlQuery query;
   query.prepare("select  * from signrecord where ID=?");
   query.bindValue(0,QString::fromStdString(id));
   //get the result of execute the query string
   bool succ=query.exec();
   if(!succ) return record;
   if(query.next()){
       record.setId(query.value(0).toString().toInt());
       record.setStuId(query.value(1).toString().toStdString());
       record.setStartTime(query.value(2).toString().toStdString());
       record.setEndTime(query.value(3).toString().toStdString());
       record.setCount(query.value(4).toString().toFloat());
   }
   DatabaseConnection::close(dbSQL);
   return record;
}

bool RecordDao::deleteById(string id)
{
    //get database connection
     QSqlDatabase dbSQL=DatabaseConnection::getConnection();
    //construct the database query object
    QSqlQuery query;
    query.prepare("delete from signrecord where ID=?");
    query.bindValue(0,Util::toQString(id));
    //get the result of execute the query string
    bool succ=query.exec();
    DatabaseConnection::close(dbSQL);
    return succ;
}

bool RecordDao::update(Record record)
{
    //get database connection
     QSqlDatabase dbSQL=DatabaseConnection::getConnection();
    //construct the database query object
    QSqlQuery query;
    query.prepare("update signrecord set studentID=?,startTime=?,endTime=?,intervalTime=? where ID=?");
    query.bindValue(0,Util::toQString(record.getStuId()));
    query.bindValue(1,Util::toQString(record.getStartTime()));
    query.bindValue(2,Util::toQString(record.getEndTime()));
    query.bindValue(3,record.getCount());
    query.bindValue(4,record.getId());
    //get the result of execute the query string
    bool succ=query.exec();
    DatabaseConnection::close(dbSQL);
    return succ;
}

list<Record> RecordDao::queryByStuId(string id)
{
    list<Record> records;
    //get database connection
     QSqlDatabase dbSQL=DatabaseConnection::getConnection();
    //construct the database query object
    QSqlQuery query;
    query.prepare("select * from signrecord where studentID=?");
    query.bindValue(0,Util::toQString(id));
    //get the result of execute the query string
    bool succ=query.exec();
    int numRows=succ?0:-1;
    if(dbSQL.driver()->hasFeature(QSqlDriver::QuerySize)){
        numRows=query.size();
    } else{
        query.last();
        numRows=query.at()+1;
    }
    Record record;
    while(query.next()){
        record.setId(query.value(0).toString().toInt());
        record.setStuId(query.value(1).toString().toStdString());
        record.setStartTime(query.value(2).toString().toStdString());
        record.setEndTime(query.value(3).toString().toStdString());
        record.setCount(query.value(4).toString().toFloat());
        records.push_back(record);
    }
    DatabaseConnection::close(dbSQL);
    return records;
}
//this list will be oredered by start time desc
list<Record> RecordDao::queryByStuIdDesc(string id)
{
    list<Record> records;
    //get database connection
     QSqlDatabase dbSQL=DatabaseConnection::getConnection();
    //construct the database query object
    QSqlQuery query;
    query.prepare("select * from signrecord where studentID=? order by startTime desc");
    query.bindValue(0,Util::toQString(id));
    //get the result of execute the query string
    bool succ=query.exec();
    int numRows=succ?0:-1;
    if(dbSQL.driver()->hasFeature(QSqlDriver::QuerySize)){
        numRows=query.size();
    } else{
        query.last();
        numRows=query.at()+1;
    }
    Record record;
    while(query.next()){
        record.setId(query.value(0).toString().toInt());
        record.setStuId(query.value(1).toString().toStdString());
        record.setStartTime(query.value(2).toString().toStdString());
        record.setEndTime(query.value(3).toString().toStdString());
        record.setCount(query.value(4).toString().toFloat());
        records.push_back(record);
    }
    DatabaseConnection::close(dbSQL);
    return records;
}

Record RecordDao::findLastByStuId(string stuid)
{
    Record record;
    //get database connection
     QSqlDatabase dbSQL=DatabaseConnection::getConnection();
    //construct the database query object
    QSqlQuery query;
    query.prepare("select * from signrecord where studentID=? order by startTime desc limit 0,1");
    query.bindValue(0,Util::toQString(stuid));
    //get the result of execute the query string
    bool succ=query.exec();
    int numRows=succ?0:-1;
    if(dbSQL.driver()->hasFeature(QSqlDriver::QuerySize)){
        numRows=query.size();
    } else{
        query.last();
        numRows=query.at()+1;
    }
    if(query.next()){
        record.setId(query.value(0).toString().toInt());
        record.setStuId(query.value(1).toString().toStdString());
        record.setStartTime(query.value(2).toString().toStdString());
        record.setEndTime(query.value(3).toString().toStdString());
        record.setCount(query.value(4).toString().toFloat());
    }
    DatabaseConnection::close(dbSQL);
    #ifdef DEBUG
    qDebug()<<Util::toQString(record.toString());
    #endif
    return record;
}

string RecordDao::queryCountByStuId(string stuid)
{
    string str="*合计：0 次     0小时";
    QSqlDatabase dbSQL=DatabaseConnection::getConnection();
   //construct the database query object
   QSqlQuery query;
   query.prepare("select count(*),SUM(intervalTime) FROM signrecord WHERE studentID=?");
   query.bindValue(0,Util::toQString(stuid));
   //get the result of execute the query string
   bool succ=query.exec();
   int numRows=succ?0:-1;
   if(dbSQL.driver()->hasFeature(QSqlDriver::QuerySize)){
       numRows=query.size();
   } else{
       query.last();
       numRows=query.at()+1;
   }
   if(query.next()){
       str.clear();
       str.append("*合计:　");
       str.append(Util::toStdString(query.value(0).toString()));
       str.append("次　　");
       string sum=Util::toStdString(QString::number(query.value(1).toFloat(),'g',4));
       str.append(sum);
       str.append("小时");
   }
   DatabaseConnection::close(dbSQL);
   return str;
}
