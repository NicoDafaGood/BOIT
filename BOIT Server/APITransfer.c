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
	SendGroupMessage(217886986, L"�յ�һ��˽����Ϣ");
	SendGroupMessage(217886986, Msg);
	return 0;
}

int SendGroupMessage(long long GroupID, WCHAR* Msg)
{
	SendEventGroupMsg(GroupID, Msg);
	return 0;
}

int RecvGroupMessage(long long GroupID, long long QQID, WCHAR* AnonymousName, WCHAR* Msg)
{
	SendPrivateMessage(1160386205, L"�յ�һ��Ⱥ����Ϣ");
	SendPrivateMessage(1160386205, Msg);
	return 0;
}
