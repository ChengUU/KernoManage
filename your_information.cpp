#include "your_information.h"
#include "ui_your_information.h"

your_information::your_information(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::your_information)
{
    ui->setupUi(this);
    readCard=ReadCard::getReadCard();
    connect(readCard,SIGNAL(readSuccess(QString,QString)),this,SLOT(readCardSucc(QString,QString)));
}

your_information::~your_information()
{
    delete ui;
}

ReadCard *your_information::getReadCard()
{
    return this->readCard;
}

void your_information::on_pushButton_2_clicked()
{
    this->hide();
    this->parentWidget()->show();
    this->ui->textBrowser->setText(" ");
    this->ui->label_2->setText("请刷卡......");
    this->readCard->stop();

}

void your_information::readCardSucc(QString uid, QString resType)
{
    if(resType!=QString(RECORD_QUERY)) return;


    StudentDAO stuDao;
    stu=stuDao.findByUId(Util::toStdString(uid));
    if(stu.getId().empty()){
        ui->textBrowser->setText("未找到相关记录......");
        return;
    }

    ui->label_2->setText("查询成功......");
    RecordDao rcdDao;
    list<Record> records=rcdDao.queryByStuIdDesc(stu.getId());
    string strRecord="*签到记录*";
    strRecord.append(stu.getName());
    strRecord.append("*\r\n");
    strRecord.append(rcdDao.queryCountByStuId(stu.getId()));
    strRecord.append("*\r\n");
    Util::setRecords(ui->textBrowser,records,strRecord);
}
