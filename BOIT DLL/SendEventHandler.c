#include<Windows.h>
#include"EstablishConn.h"
#include"CQAPITransfer.h"
#include"BOITEventType.h"
#include<process.h>

unsigned __stdcall SendEventThread(void* Args);

int StartSendEventHandler()
{
	_beginthreadex(NULL, 0, SendEventThread, (LPVOID)0, 0, NULL);
	
	return 0;
}


unsigned __stdcall SendEventThread(void *Args)
{
	while (1)
	{
		while (GetConnState() == 1)
		{
			if (ConnWaitForObject(hEventSendStart) == 0)
			{
				break;
			}
		
			//���ࣺ
			switch (pSharedMemSend->EventType)
			{
			case BOIT_EVENT_SEND_PRIVATE:
			{
				char* ToSendText;
				int ccbLen;
				ccbLen = WideCharToMultiByte(54936, 0, pSharedMemSend->u.PrivateMsg.Msg, -1, 0, 0, 0, 0);
				ToSendText = malloc(sizeof(char) * (ccbLen + 1));
				WideCharToMultiByte(54936, 0, pSharedMemSend->u.PrivateMsg.Msg, -1, ToSendText, ccbLen+1, 0, 0);
				SendPrivateMessage(pSharedMemSend->u.PrivateMsg.QQID, ToSendText);
				free(ToSendText);
			}
				break;
			case BOIT_EVENT_SEND_GROUP:
			{
				char* ToSendText;
				int ccbLen;
				ccbLen = WideCharToMultiByte(54936, 0, pSharedMemSend->u.GroupMsg.Msg, -1, 0, 0, 0, 0);
				ToSendText = malloc(sizeof(char) * (ccbLen + 1));
				WideCharToMultiByte(54936, 0, pSharedMemSend->u.GroupMsg.Msg, -1, ToSendText, (ccbLen + 1), 0, 0);
				SendGroupMessage(pSharedMemSend->u.GroupMsg.GroupID, ToSendText);
				free(ToSendText);
			}
				break;
			}
			
			SetEvent(hEventSendEnd);
		}
		Sleep(1000);
	}
	
}

