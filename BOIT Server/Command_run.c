#include<Windows.h>
#include"CommandManager.h"
#include"APITransfer.h"
#include"InlineCommand.h"

MSGPROC CmdMsg_run_Proc(long long GroupID, long long QQID, WCHAR* AnonymousName, WCHAR* Msg)
{
	SendBackMessage(GroupID, QQID, L"���������д���Ŷ");
	return 0;
}

