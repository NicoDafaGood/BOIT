#include<Windows.h>
#include"CommandManager.h"
#include"APITransfer.h"
#include"InlineCommand.h"

MSGPROC CmdMsg_qwq_Proc(long long GroupID, long long QQID, WCHAR * AnonymousName, WCHAR * Msg)
{
	WCHAR ReplyMessage[][16] = {
		L"pwp",
		L"qwq",
		L"/w\\",
		L"QwQ",
		L"/qwq\\",
		L"�d(�R���Q*)o",
		L"`(*>�n<*)��",
		L"(o�b���b)o��" ,
		L"(*/�أ�*)"};
	SendBackMessage(GroupID, QQID, ReplyMessage + rand() % _countof(ReplyMessage));
	return 0;
}