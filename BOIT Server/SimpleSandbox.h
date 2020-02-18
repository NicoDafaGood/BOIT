#pragma once
#include<Windows.h>

typedef struct __tagSandbox SANDBOX, * pSANDBOX, SANDBOX_CHAIN, * pSANDBOX_CHAIN;

//ɳ��ص���������
typedef INT(*SANDBOX_CALLBACK)(pSANDBOX Sandbox, PBYTE pData, UINT Event, PBYTE StdOutData, DWORD DataLen);

//Callback�¼�
#define SANDBOX_EVTNT_PROCESS_ZERO 1
#define SANDBOX_EVENT_STD_OUTPUT 2


typedef struct __tagSandbox
{
	HANDLE hJob;
	HANDLE hProcess;

	LONGLONG SandboxID;
	HANDLE hWaitableTimer;

	UINT ExitReason;

	SANDBOX_CALLBACK SandboxCallback;
	PBYTE pExternalData;

	pSANDBOX_CHAIN LastSandbox;
	pSANDBOX_CHAIN NextSandbox;
}SANDBOX, * pSANDBOX, SANDBOX_CHAIN, * pSANDBOX_CHAIN;

pSANDBOX_CHAIN RootSandbox;


int InitializeSandbox(int JobObjCompThreadNum, int PipeIOCompThreadNum);

int FinalizeSandbox();

pSANDBOX CreateSimpleSandboxW(WCHAR* ApplicationName,
	WCHAR* CommandLine,
	WCHAR* CurrentDirectory,
	long long TotUserTimeLimit,		//����ɳ�е�ʱ�����ƣ�msdn��˵��100����Ϊ��λ������֣��Ҿ�����10000*�룩��Ϊ-1������ʱ������
	long long TotMemoryLimit,		//����ɳ�е��ڴ����ƣ�ByteΪ��λ����Ϊ-1�������ڴ�����
	int CpuRateLimit,				//CPU���ƣ�1-10000����10000��ζ�ſ�����100%��CPU����������0����Ϊ-1����������
	PBYTE pExternalData,					//��������Ϣ
	SANDBOX_CALLBACK CallbackFunc	//�ص�����
);

int FreeSimpleSandboxW(pSANDBOX Sandbox);


//�˳�ԭ���� ExitReason -> ER
#define SANDBOX_ER_RUNNING 0	//��û�˳�
#define SANDBOX_ER_EXIT 1		//�����˳�
#define SANDBOX_ER_TIMEOUT 2	//����ʱ������
#define SANDBOX_ER_ABNORMAL 3	//�쳣�˳�
#define SANDBOX_ER_KILLED 4		//��ɳ��ǿ�ƹر���



