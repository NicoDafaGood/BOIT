#include<Windows.h>
#include"APITransfer.h"
#include"CommandManager.h"
#include"InlineCommand.h"

int RegisterInlineCommand()
{
	pBOIT_COMMAND Command_qwq = RegisterCommand(L"qwq", Command_qwq_Proc, L"����", BOIT_MATCH_FULL);
	AddCommandAlias(Command_qwq, L"pwp");
	RegisterCommand(L"about", Command_about_Proc, L"����", BOIT_MATCH_FULL);
	RegisterCommand(L"TreeNewBee", Command_commingfeature_Proc, L"��ţ��(�����еĹ���)", BOIT_MATCH_FULL);
	RegisterCommand(L"help", Command_help_Proc, L"������Ϣ", BOIT_MATCH_PARAM);
	
	return 0;
}