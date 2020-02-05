#define WIN32_LEAN_AND_MEAN
#include<Windows.h>
#include"CoolQDef.h"
#include"CoolQ_State.h"

int SendPrivateMessage(long long QQID, const char* msg)
{
	return CQ_sendPrivateMsg(CQAuthCode, QQID, msg);
}


int SendGroupMessage(long long GroupID, const char* msg)
{
	return CQ_sendGroupMsg(CQAuthCode, GroupID, msg);
}