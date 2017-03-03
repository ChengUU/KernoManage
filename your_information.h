#ifndef YOUR_INFORMATION_H
#define YOUR_INFORMATION_H

#include <QDialog>
#include<readcard.h>
#include<Student.h>
#include<list>
#include<record.h>
#include<StudentDao.h>
#include<RecordDao.h>

namespace Ui {
class your_information;
}

class your_information : public QDialog
{
    Q_OBJECT

public:
    explicit your_information(QWidget *parent = 0);
    ~your_information();
    ReadCard* getReadCard();

private slots:
    void on_pushButton_2_clicked();
     void readCardSucc(QString uid, QString resType);

private:
    Ui::your_information *ui;
    ReadCard* readCard;
    Student stu;
};

#endif // YOUR_INFORMATION_H
