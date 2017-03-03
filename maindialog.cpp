#include "maindialog.h"
#include "ui_maindialog.h"

mainDialog::mainDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mainDialog)
{
    ui->setupUi(this);
//初始化窗体
    newregister = new Register(this);
    signIn = new sign_In(this);
    signOut = new sign_out(this);
    yourInformation = new your_information(this);
//窗体名字
    newregister->setWindowTitle(QString("主菜单\注册"));
    signIn->setWindowTitle(QString("主菜单\签到"));
    signOut->setWindowTitle(QString("主菜单\签退"));
    yourInformation->setWindowTitle(QString("主菜单\查询信息"));
    this->setWindowTitle(QString("酷诺软件外包团队管理系统"));
}

mainDialog::~mainDialog()
{
    delete ui;
}

void mainDialog::on_pushButton_clicked()//注册按钮事件
{
//窗体切换
    newregister->show();
    this->hide();

}

void mainDialog::on_pushButton_2_clicked()//签到按钮
{
//窗体切换
    signIn->show();
    this->hide();
    signIn->getReadCard()->start(QString(SIGN_IN));

}

void mainDialog::on_pushButton_3_clicked()//签退按钮
{
//窗体切换
    signOut->show();
    this->hide();
    signOut->getReadCard()->start(QString(SIGN_OUT));

}

void mainDialog::on_pushButton_4_clicked()//信息查询按钮
{
//窗体切换
    yourInformation->show();
    this->hide();
    yourInformation->getReadCard()->start(QString(RECORD_QUERY));
}

void mainDialog::closeEvent(QCloseEvent *event)
{
}
