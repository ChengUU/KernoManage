#ifndef MAINDIALOG_H
#define MAINDIALOG_H

#include<Register.h>
#include"sign_in.h"
#include"sign_out.h"
#include"your_information.h"
#include<const.h>

#include <QDialog>
#include<const.h>

namespace Ui {
class mainDialog;
}

class mainDialog : public QDialog
{
    Q_OBJECT

public:
    explicit mainDialog(QWidget *parent = 0);
    ~mainDialog();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::mainDialog *ui;
    your_information *yourInformation;
    Register *newregister;
    sign_In *signIn;
    sign_out *signOut;
    Student tempStu;
protected:
     void closeEvent(QCloseEvent *event);
};

#endif // MAINDIALOG_H
