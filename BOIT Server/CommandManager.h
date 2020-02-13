#pragma once
#include<Windows.h>

typedef INT(*COMPROC)(long long GroupID, long long QQID, WCHAR* AnonymousName, WCHAR* Msg);//�ص���������

//ָ���������ݽṹ����

#define COMMAND_MAX_ALIAS 4 // �������


typedef struct __tagCommand BOIT_COMMAND, * pBOIT_COMMAND;

typedef struct __tagCommand
{
	unsigned int CommandID;

	WCHAR* CommandName[COMMAND_MAX_ALIAS];//ָ������
	int AliasCount;//���ƣ�����˵�Ǳ���������
	COMPROC CommandProc;
	WCHAR* ManualMsg;
	int MatchMode;

	pBOIT_COMMAND NextCommand;
}BOIT_COMMAND,*pBOIT_COMMAND;

pBOIT_COMMAND RootCommand;

int CommandAllocID;

#define BOIT_MATCH_FULL 1 //ȫ��ƥ�䣬��Сд������
#define BOIT_MATCH_FULL_CASE 2 //ȫ��ƥ�䣬��Сд����
#define BOIT_MATCH_PARAM 3 //����һ������ƥ�䣬��Сд������
#define BOIT_MATCH_PARAM_CASE 4 //����һ������ƥ�䣬��Сд����
#define BOIT_MATCH_HEAD 5 //��ǰN���ַ�ƥ�䣬��Сд������
#define BOIT_MATCH_HEAD_CASE 6 //��ǰN���ַ�ƥ�䣬��Сд����




int InitializeCommandManager();

int FinalizeCommandManager();

pBOIT_COMMAND RegisterCommand(WCHAR* CommandName, COMPROC CommandProc, WCHAR* ManualMsg, int MatchMode);

int RemoveCommand(pBOIT_COMMAND Command);

BOOL CheckIsCommand(WCHAR* Msg, int* PrefixLen);

int CommandHandler(long long GroupID, long long QQID, WCHAR* AnonymousName, WCHAR* Msg);



int RegisterInlineCommand();//ע�������Դ�ָ��