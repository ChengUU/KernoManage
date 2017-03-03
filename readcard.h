#ifndef READCARD_H
#define READCARD_H
#include<QThread>
#include<QMutex>
#include<SCard.h>
#include<string>
#include<QDebug>
#include<Util.h>
#include <QMetaType>
#include<const.h>
typedef BYTE RecvBuffer[20];
using namespace std;
class ReadCard:public QThread
{
    Q_OBJECT
public:

    void stop();
    void start(QString reqType);
    //该线程的实例对象在整个应用程序执行期间有且只有一个(设计模式-单例模式)
    static ReadCard* getReadCard();

signals:
    void readSuccess(QString,QString);
protected:
    void run();
private:
    explicit ReadCard(QObject *parent=0);
    mutable QMutex mutex;
    bool stopped;
    QString reqType;
    static ReadCard* readcard;

};

#endif // READCARD_H
