#include<Windows.h>
#include"SharedMemStruct.h"


HANDLE hEventConnect;

HANDLE hEventRecvStart;//��ʼ���� ��Ϣ/�¼� ��
HANDLE hEventRecvEnd;//���� ��Ϣ/�¼� ������

HANDLE hEventSendStart;//��ʼ���� ��Ϣ/�¼� ��
HANDLE hEventSendEnd;//���� ��Ϣ/�¼� ������

HANDLE hSharedMemProcess;//Server �� dll ��ؽ�����Ϣ
HANDLE hSharedMemRecv;
HANDLE hSharedMemSend;

HANDLE hOtherSideProcess;

pSHARED_PROCESS_INFO pSharedMemProcess;
pEVENT_RECV pSharedMemRecv;
pEVENT_SEND pSharedMemSend;

SRWLOCK ConnStateLock;
BOOL ConnState;


int InitEstablishConn();
int TryEstablishConn();
int GetConnState();