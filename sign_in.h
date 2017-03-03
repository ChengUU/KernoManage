#ifndef SIGN_IN_H
#define SIGN_IN_H

#include <QDialog>
#include<readcard.h>
#include<Student.h>
#include<StudentDAO.h>
#include<RecordDao.h>
#include<QTime>
namespace Ui {
class sign_In;
}

class sign_In : public QDialog
{
    Q_OBJECT

public:
    explicit sign_In(QWidget *parent = 0);
    ~sign_In();
    ReadCard* getReadCard();
    void setReadCard(ReadCard* reader);

private slots:
    void on_pushButton_clicked();

    void readCardSucc(QString uid, QString resType);
private:
    Ui::sign_In *ui;
    ReadCard *readCard;
    Student stu;
protected:
    void closeEvent(QCloseEvent *event);

};

#endif // SIGN_IN_H
