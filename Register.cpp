#include "Register.h"
#include "ui_Register.h"
#include<StudentDao.h>

Register::Register(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);
    bool flag=true;
    readcard = ReadCard::getReadCard();
    flag=connect(readcard, SIGNAL(readSuccess(QString,QString)), this, SLOT(readCardSuccess(QString,QString)));
    #ifdef DEBUC
    if(flag)
        qDebug()<<"CONNECT:REGISTER-READCARD";
    #endif
}

Register::~Register()
{
    delete ui;
    readcard->stop();
}


void Register::on_pushButton_2_clicked()
{
    this->hide();

    parentWidget()->show();
}

void Register::on_pushButton_clicked()
{
    ui->label_4->setText("");
    QString name, num;
    string majors[5] = { "计算机科学与技术 ","软件工程 ","物联网工程 ","网络工程 ","其他 " };
    int major;
    //读取控件的TEXT
    name = ui->lineEdit->text();
    num = ui->lineEdit_2->text();
    major = ui->comboBox->currentIndex();/*0为空
                                         1计算机科学与技术
                                         2软件工程
                                         3物联网工程
                                         4网络工程
                                         5其他
                                         */
                                         //用于debug
#ifdef DEBUG
    qDebug() << "name=" << name;
    qDebug() << "num=" << num;
    qDebug() << "major" << major;
#endif

    //智障测试
    if (name == NULL)
    {
        ui->label_4->setText("姓名不能为空");
        return;
    }
    else if (num == NULL)
    {
        ui->label_4->setText("学号不能为空");
        return;
    }
    else if (major == 0)
    {
        ui->label_4->setText("请选择专业");
        return;
    }

    StudentDAO stuDao;
    if (stuDao.queryById(Util::toStdString(num)))
    {
        ui->label_4->setText("不要重复注册");
    }
    else
    {
#ifdef DEBUG
        qDebug() << Util::toQString(majors[major - 1].substr(0, majors[major - 1].length() - 1));
#endif
        //这里开始写验证成功后的代码
        ui->label_4->setText("请刷卡！");
        string pro = majors[major - 1].substr(0, majors[major - 1].length() - 1);
        tempStu = Student(pro, Util::toStdString(num), Util::toStdString(name));
        readcard->start(QString(REGISTER));
#ifdef DEBUG
        qDebug() << "After readSCard->start()";
#endif

    }
}

void Register::readCardSuccess(QString uid, QString resType)
{
    if(resType!=REGISTER) return;
    tempStu.setUId(Util::toStdString(uid));
    StudentDAO stuDao;
    bool flag = stuDao.insert(tempStu);
    #ifdef DEBUG
    qDebug()<<"--读取成功";
    #endif
    if (flag) { ui->label_4->setText("注册成功......"); }
    else { ui->label_4->setText("未能写入数据库，注册失败......"); }
    #ifdef DEBUG
    qDebug()<<"-*读取成功";
    #endif
    readcard->stop();

}
