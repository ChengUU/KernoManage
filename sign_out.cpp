#include "sign_out.h"
#include "ui_sign_out.h"

sign_out::sign_out(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::sign_out)
{
    ui->setupUi(this);
    readCard=ReadCard::getReadCard();
    connect(readCard,SIGNAL(readSuccess(QString,QString)),this,SLOT(readCardSucc(QString,QString)));
}

sign_out::~sign_out()
{
    delete ui;
}

ReadCard *sign_out::getReadCard()
{
    return this->readCard;
}

void sign_out::on_pushButton_2_clicked()
{
    this->hide();
    this->parentWidget()->show();
    ui->textBrowser->setText("");
    this->ui->label_2->setText("请刷卡......");
    readCard->stop();
}

void sign_out::readCardSucc(QString uid, QString resType)
{
    if(resType!=QString(SIGN_OUT)) return;
    QDateTime now=QDateTime::currentDateTime();
    string endTime=Util::toStdString(now.toString("yyyy-MM-dd hh:mm:ss"));
    #ifdef DEBUG
        qDebug()<<Util::toQString(endTime);
    #endif

    StudentDAO stuDao;
    stu=stuDao.findByUId(Util::toStdString(uid));

    RecordDao rcdDao;
    Record last=rcdDao.findLastByStuId(stu.getId());
    string lastStartTime=last.getStartTime();
    string lastEndTime=last.getEndTime();
    lastStartTime=lastStartTime.replace(10,1," ");
    lastEndTime=lastEndTime.replace(10,1," ");
    QDateTime startTime=QDateTime::fromString(Util::toQString(lastStartTime),"yyyy-MM-dd hh:mm:ss");
    QDateTime lastET=QDateTime::fromString(Util::toQString(lastEndTime),"yyyy-MM-dd hh:mm:ss");
    qint64 lst=startTime.toSecsSinceEpoch();
    qint64 let=lastET.toSecsSinceEpoch();
    qint64 et=now.toSecsSinceEpoch();
    qint64 intervalue=et-lst;
    #ifdef DEBUG
        qDebug()<<"startTime:"<<startTime.toString();
        qDebug()<<"lastET:"<<lastET.toString();
        qDebug()<<"lst:"<<lst;
        qDebug()<<"let:"<<let;
    #endif
    //不存在签到记录
    if(lst!=let){
        //最后一条记录的开始时间不等于结束时间
        ui->textBrowser->setText("请勿重复签退......");
        #ifdef DEBUG
        qDebug()<<"lst!=let";
        #endif
        return;
    }
    //当前用户最后一条记录开始时间等于结束时间（表示存在签到记录）
    if(intervalue<SIGN_OUT_MIN) {
        ui->textBrowser->setText("未达到最低签退时间......");
        return;
    }
    #ifdef DEBUG
    qDebug()<<intervalue;
    #endif
    if(intervalue>SIGN_OUT_MAX){
        ui->label_2->setText("本次签退失效......");
        last.setEndTime(endTime);
        rcdDao.update(last);
        list<Record> records=rcdDao.queryByStuIdDesc(stu.getId());
        string strRecord="*签到记录-";

        strRecord.append(stu.getName());
        strRecord.append("*\r\n");
        Util::setRecords(ui->textBrowser,records,strRecord);
        return;
    }
    last.setEndTime(endTime);
    last.setCount(1.0*intervalue/3600);
    bool flag=rcdDao.update(last);

    if(flag){
        ui->label_2->setText("签退成功......");
        list<Record> records=rcdDao.queryByStuIdDesc(stu.getId());
        string strRecord="*签到记录*";
        strRecord.append(stu.getName());
        strRecord.append("*\r\n");
        strRecord.append(rcdDao.queryCountByStuId(stu.getId()));
        strRecord.append("*\r\n");
        Util::setRecords(ui->textBrowser,records,strRecord);
    }else{ui->label_2->setText("签退失败......");}
}
void sign_out::closeEvent(QCloseEvent *event){
    this->getReadCard()->stop();
}

