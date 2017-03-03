#include "ReadCard.h"

ReadCard::ReadCard(QObject *parent):QThread(parent){
    stopped=false;

}
ReadCard* ReadCard::readcard=new ReadCard();

void ReadCard::stop()
{
    mutex.lock();
    stopped=true;
    mutex.unlock();
}

void ReadCard::start(QString reqType)
{
    mutex.lock();
    stopped=false;
    this->reqType=reqType;
    QThread::start();
    mutex.unlock();
}

ReadCard *ReadCard::getReadCard()
{
    return readcard;
}



void ReadCard::run()
{
    while(!stopped){
        SCard::getReader()->SetReader();
        SCard::getReader()->ConnectReader();
        RecvBuffer recvBuffer;
        DWORD recLen=sizeof(recvBuffer);
        BYTE comm[] = { 0xFF, 0xCA, 0x01, 0x00,0x00 };   //传入命令
        DWORD commLen = sizeof(comm);
        while (!SCard::getReader()->ConnectReader());
        SCard::getReader()->SendCommand(comm, commLen, recvBuffer, &recLen);
        QString uid=Util::toQString(Util::calStrUId(recvBuffer,recLen));
        SCard::getReader()->DisConnectReader();
        emit readSuccess(uid,reqType);
        sleep(3);
        #ifdef DEBUG
        qDebug()<<uid;
        #endif
    }

}
