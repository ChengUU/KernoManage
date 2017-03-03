#ifndef SIGN_OUT_H
#define SIGN_OUT_H

#include <QDialog>
#include<readcard.h>
#include<Student.h>
#include<StudentDAO.h>
#include<RecordDao.h>
#include<QTime>


namespace Ui {
class sign_out;
}

class sign_out : public QDialog
{
    Q_OBJECT

public:
    explicit sign_out(QWidget *parent = 0);
    ~sign_out();
    ReadCard* getReadCard();

private slots:
    void on_pushButton_2_clicked();
    void readCardSucc(QString uid, QString resType);

private:
    Ui::sign_out *ui;
    Student stu;
    ReadCard* readCard;
protected:
    void closeEvent(QCloseEvent* e);
};

#endif // SIGN_OUT_H
