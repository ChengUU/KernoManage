#pragma once
#include"WINSCARD.H"
#include<QMutex>
#pragma comment (lib, "winscard.lib")
class SCard
{
private:
    SCARDCONTEXT hSC;										//OK
    LONG lReturn;											//OK
    char mszReaders[1024];									//OK
    LPTSTR pReader, pReaderName;							//pReader is OK
    DWORD dwLen;											//OK
    int nReaders, nCurrentReader;							//
    SCARDHANDLE hCardHandle;								//OK
    DWORD dwAP;
    QMutex mutex;
    static SCard* reader;
    SCard(); //建立上下文、取读卡器列表
    ~SCard(); //释放上下文

public:
    static SCard* getReader();
                                                                            //基本读卡功能
    void SetReader();
    int ConnectReader(); //与当前读卡器建立连接
    int DisConnectReader(); //与当前读卡器断开连接
    int SendCommand(BYTE command[], DWORD commandLength, BYTE result[], DWORD *resultLength); //向读卡器发送命令，并接收返回的数据。返回值为sw
    int ReadTheCard(BYTE *recvBuffer, DWORD &recvlen);//新增读卡功能
};

