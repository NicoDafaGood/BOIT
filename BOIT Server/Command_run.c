#include<Windows.h>
#include"CommandManager.h"
#include"APITransfer.h"
#include"InlineCommand.h"
#include"DirManagement.h"

MSGPROC CmdMsg_run_Proc(long long GroupID, long long QQID, WCHAR* AnonymousName, WCHAR* Msg)
{
	//����û�Ŀ¼���Ƿ�����Ӧ�ļ���
	if (PerUserCreateDirIfNExist(QQID, L"Sandbox"))
	{
		//������Ӧ�ļ�
	}
	if (PerUserCreateDirIfNExist(QQID, L"Compile"))
	{
		//������Ӧ�ļ�
	}

	SendBackMessage(GroupID, QQID, L"���������д���Ŷ");
	return 0;
}

EVENTPROC CmdEvent_run_Proc(pBOIT_COMMAND pCmd, UINT Event, PARAMA ParamA, PARAMB ParamB)
{
	switch (Event)
	{
	case EC_DIRINIT:
		//���ﴴ�����������ļ�
		break;
	}
	return 0;
}