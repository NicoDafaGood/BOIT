#include<Windows.h>
#include"RecvEventHandler.h"
#include "APITransfer.h"
#include"SendEventDispatch.h"

//�����￪ʼ��Ϣ����ʽ����Ӧ�ò�

int SendPrivateMessage(long long QQID, WCHAR * Msg)
{
	SendEventPrivateMsg(QQID, Msg);
	return 0;
}

int RecvPrivateMessage(long long QQID, WCHAR* Msg)
{
	return 0;
}

int SendGroupMessage(long long GroupID, WCHAR* Msg)
{
	SendEventGroupMsg(GroupID, Msg);
	return 0;
}

int RecvGroupMessage(long long GroupID, long long QQID, WCHAR* AnonymousName, WCHAR* Msg)
{
	return 0;
}
