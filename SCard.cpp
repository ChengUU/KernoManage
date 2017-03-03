#include "SCard.h"
#include<iostream>
#include<qdebug.h>
using namespace std;


SCard::SCard()
{
    lReturn = SCardEstablishContext(SCARD_SCOPE_USER, NULL, NULL, &hSC);

    if (lReturn != SCARD_S_SUCCESS)
    {
        qDebug() << "SCardEstablishContext() error "<<endl;
        exit(1);
    }

}

SCard::~SCard()
{
    lReturn = SCardReleaseContext(hSC);
    if (lReturn != SCARD_S_SUCCESS)
        printf("Failed SCardReleaseContext\n");
}
SCard* SCard::reader=new SCard();

SCard *SCard::getReader()
{
    return reader;
}

void SCard::SetReader()
{
    dwLen = sizeof(mszReaders);
    lReturn = SCardListReaders(hSC, NULL, (LPTSTR)mszReaders, &dwLen);
    pReader = (LPTSTR)mszReaders;
    if (lReturn != SCARD_S_SUCCESS)
    {
        qDebug() << "SCardlistcards() error " << mszReaders << endl;
        exit(1);
    }

}

int SCard::ConnectReader()
{
    lReturn = SCardConnect(
        hSC,
        pReader,
        SCARD_SHARE_SHARED,
        SCARD_PROTOCOL_T1 ,
        &hCardHandle,
        &dwAP);

    if (lReturn != SCARD_S_SUCCESS)
    {
        return 0;
    }
    return 1;
}

int SCard::DisConnectReader()
{
    SCardDisconnect(hCardHandle, SCARD_EJECT_CARD);
    return 0;
}

int SCard::SendCommand(BYTE command[], DWORD commandLength, BYTE result[], DWORD *resultLength)
{
    int flag=1;
    SCARD_IO_REQUEST  ScardIoRequest;
    ScardIoRequest.dwProtocol = dwAP;
    ScardIoRequest.cbPciLength = sizeof(dwAP);
    lReturn = SCardTransmit(
        hCardHandle,
        SCARD_PCI_T1,
        command,
        commandLength,
        NULL,
        result,
        resultLength);

    if (lReturn != SCARD_S_SUCCESS)
    {
        qDebug() << "SendCommand() error"<<endl;
        flag=0;
    }
    return flag;
}

int SCard::ReadTheCard(BYTE *recvBuffer, DWORD &recvlen)
{
    BYTE Comm[] = { 0xFF, 0xCA, 0x01, 0x00,0x00 };   //传入命令
    DWORD commLen = sizeof(Comm);

    qDebug() << "请放入智能卡"<<endl;							//输入提示
    while (!ConnectReader());

    SendCommand(Comm, commLen, recvBuffer, &recvlen);
    qDebug() << "读取成功请取走卡"<<endl;

    while (ConnectReader())
    {
        DisConnectReader();
    }
    return 0;
}
