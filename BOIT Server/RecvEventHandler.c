#include<Windows.h>
#include "RecvEventHandler.h"
#include"EstablishConn.h"
#include"Global.h"

unsigned __stdcall RecvEventThread();


int StartRecvEventHandler()
{
	SYSTEM_INFO SysInfo;//����ȡ��CPU��������Ϣ
	GetSystemInfo(&SysInfo);

	for (unsigned int i = 0; i < SysInfo.dwNumberOfProcessors; i++)
	{
		_beginthreadex(NULL, 0, RecvEventThread, (LPVOID)0, 0, NULL);
	}
	return 0;
}


unsigned __stdcall RecvEventThread()
{
	while (1)
	{
		while (GetConnState() == 1)
		{
			if (ConnWaitForObject(hEventRecvStart) == 0)
			{
				break;
			}
			pEVENT_RECV RecvEvent;
			//TODO: ���ƶ��󣬷ַ�����
			MessageBoxW(0, pSharedMemRecv->u.PrivateMsg.Msg, L"qwq", 0);
			SendEventPrivateMsg(pSharedMemRecv->u.PrivateMsg.QQID, L"nihao");
			SetEvent(hEventRecvEnd);
		}
		Sleep(1000);
	}
}

