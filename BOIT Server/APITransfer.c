#include<Windows.h>
#include"RecvEventHandler.h"
#include "APITransfer.h"
#include"SendEventDispatch.h"
#include"CommandManager.h"

//从这里开始消息流正式进入应用层

int SendPrivateMessage(long long QQID, WCHAR * Msg)
{
	SendEventPrivateMsg(QQID, Msg);
	return 0;
}

int RecvPrivateMessage(long long QQID, WCHAR* Msg)
{
	int PrefixLen;
	if (CheckIsCommand(Msg, &PrefixLen))
	{
		CommandHandler(0, QQID, 0, Msg + PrefixLen);
	}
	return 0;
}

int SendGroupMessage(long long GroupID, WCHAR* Msg)
{
	SendEventGroupMsg(GroupID, Msg);
	return 0;
}

int RecvGroupMessage(long long GroupID, long long QQID, WCHAR* AnonymousName, WCHAR* Msg)
{
	int PrefixLen;
	if (CheckIsCommand(Msg, &PrefixLen))
	{
		CommandHandler(GroupID, QQID, AnonymousName, Msg + PrefixLen);
	}
	return 0;
}



int SendBackMessage(long long GroupID, long long QQID, WCHAR* Msg)
{
	if (GroupID)
	{
		SendGroupMessage(GroupID, Msg);
	}
	else
	{
		SendPrivateMessage(QQID, Msg);
	}
	return 0;
}
