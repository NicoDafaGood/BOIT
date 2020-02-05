#include<Windows.h>
#include"ObjectName.h"
#include"EstablishConn.h"
#
//����ļ��Ĵ����ǹ���ģ����ڽ���DLL��Server֮�������


#define JUDGE_OBJ(Obj, iRet) \
if(Obj){\
if(GetLastError() == ERROR_ALREADY_EXISTS){\
if(iRet == -2 || iRet == 1){iRet = 1;}else{__leave;}\
}\
else{\
if(iRet == -2 || iRet == 0){iRet = 0;}else{__leave;}\
}\
}\
else{\
__leave;\
}


int TryEstablishConn()//return -1����ʧ�� 0����ɹ��������󲢵ȴ������� 1����ɹ�����
{
	int iRet = -2;
	__try
	{
		hEventConnect = CreateEvent(0, 0, 0, GET_OBJ_NAME(EVENT_CONNECT));
		JUDGE_OBJ(hEventConnect, iRet);


	}
	__finally
	{
		switch(iRet)
		{
		case -1:
			CloseHandle(hEventConnect);
			break;
		case 0:
			WaitForSingleObject(hEventConnect, INFINITE);
			break;
		case 1:
			SetEvent(hEventConnect);
			break;
		}
		
	}
	
	return iRet;
}


