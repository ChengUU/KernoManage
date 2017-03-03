#ifndef REGISTER_H
#define REGISTER_H

#include <QDialog>
#include<Student.h>
#include<readcard.h>
#include<Util.h>
#include<const.h>
#define DEBUG
typedef BYTE RecvBuffer[20];
using namespace std;


namespace Ui {
class Register;
}

class Register : public QDialog
{
    Q_OBJECT

public:
    explicit Register(QWidget *parent = 0);

    ~Register();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void readCardSuccess(QString uid, QString resType);

private:
    Ui::Register *ui;
    Student tempStu;
    ReadCard* readcard;
};

#endif // REGISTER_H
