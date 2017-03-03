#ifndef NEWREGISTER_H
#define NEWREGISTER_H
#include <QDialog>
#include<readcard.h>
#include<Student.h>
namespace Ui {
    class NewRegister;
}
class NewRegister:public QDialog
{
    Q_OBJECT
public:
    explicit NewRegister(QWidget *parent = 0);
    ~NewRegister();
    readCard* getReadSCard();
private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();


    void readCardSuccess(RecvBuffer recvBuffer, BYTE recvLen);
private:
    Ui::NewRegister *ui;
    readCard *readSCard;
    Student tempStu;
};

#endif // NEWREGISTER_H
