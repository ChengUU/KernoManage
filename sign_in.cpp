#include "sign_in.h"
#include "ui_sign_in.h"

sign_In::sign_In(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::sign_In)
{
    ui->setupUi(this);
    readCard=ReadCard::getReadCard();
    connect(readCard,SIGNAL(readSuccess(QString,QString)),this,SLOT(readCardSucc(QString,QString)));


}

sign_In::~sign_In()
{
    delete ui;
}

ReadCard *sign_In::getReadCard()
{
    return this->readCard;
}

void sign_In::setReadCard(ReadCard *reader)
{
    this->readCard=reader;
}

void sign_In::on_pushButton_clicked()
{
    this->hide();
    this->ui->textBrowser->setText("");
    this->ui->label_2->setText("请刷卡......");
    parentWidget()->show();
    readCard->stop();
}


void sign_In::readCardSucc(QString uid, QString resType)
{
    if(resType!=QString(SIGN_IN)) return;


    StudentDAO stuDao;
    stu=stuDao.findByUId(Util::toStdString(uid));
    QString now=QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");

    string startTime=Util::toStdString(now);
    #ifdef DEBUG
        qDebug()<<Util::toQString(startTime);
    #endif

    Record record=Record();
    record.setStartTime(startTime);
    record.setEndTime(startTime);
    record.setCount(0);
    record.setStuId(stu.getId());

    RecordDao rcdDao;
    Record last=rcdDao.findLastByStuId(stu.getId());
    if(last.getStartTime().empty()){
        ui->textBrowser->setText("数据库访问异常......");
        return;
    }
    //已存在签到记录
    if(last.getStartTime()==last.getEndTime()){
        ui->textBrowser->setText("请勿重复签到......");
        return;
    }

    bool flag=rcdDao.insert(record);

    if(flag){
        ui->label_2->setText("签到成功......");
        list<Record> records=rcdDao.queryByStuIdDesc(stu.getId());
        string strRecord="*签到记录*";
        strRecord.append(stu.getName());
        strRecord.append("*\r\n");
        Util::setRecords(ui->textBrowser,records,strRecord);
    }else{ui->label_2->setText("签到失败......");}
}

void sign_In::closeEvent(QCloseEvent *event)
{
    getReadCard()->stop();
}
