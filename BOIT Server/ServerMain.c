﻿#include<Windows.h>
#include<stdio.h>
#include"EstablishConn.h"
#include"Global.h"
#include"RecvEventHandler.h"
#include"RegisterRW.h"
#include"DirManagement.h"
#include"Settings.h"
#include<conio.h>
#include"CommandManager.h"
#include"DirManagement.h"
#include<Shlwapi.h>
#include"SimpleSandbox.h"


int main()
{
	puts("BOIT Server正在启动\n");

	InitializeSandbox(2, 2);
	InitializeCommandManager();
	RegisterInlineCommand();//注册所有指令

	//读取注册表，检查配置
	switch (RegisterRead(GetBOITBaseDir()))
	{
	case SETTINGS_LOADED:
		puts("注册表加载成功\n");
		InitBOITDirVar();
		break;
	case SETTINGS_ERROR:
		while (1)
		{
			puts("注册表加载失败，是否清空设置并初始化? (y/n)");
			char Answer[128] = { 0 };
			scanf_s("%s", Answer, 127);
			getchar();//读掉那个换行
			if (strcmp(Answer,"y") == 0 || 
				strcmp(Answer, "Y") == 0 ||
				strcmp(Answer, "yes") == 0 ||
				strcmp(Answer, "Yes") == 0
				)
			{
				break;
			}
			else if (strcmp(Answer, "n") == 0 ||
				strcmp(Answer, "N") == 0 ||
				strcmp(Answer, "no") == 0 ||
				strcmp(Answer, "No") == 0
				)
			{
				return 0;
			}
		}
		//清理注册表
		if (ClearSettings() == SETTINGS_ERROR)
		{
			puts("清空设置失败，按任意键退出程序");
			_getch();
			return 0;
		}
		//fall
	case SETTINGS_NOT_FOUND:
	{
		puts("欢迎使用BOIT qwq\n");
		char InBaseDir[MAX_PATH + 4] = { 0 };
		while (1)
		{
			puts("请输入BOIT根目录（无需引号，完整输入一行后换行）");

			scanf_s("%[^\n]", &InBaseDir, MAX_PATH);
			getchar();//读掉 \n
			if (IsPathDirA(InBaseDir) == TRUE)
			{
				PathSimplifyA(InBaseDir);
				PathAddBackslashA(InBaseDir);
				//if(InBaseDir[strlen(InBaseDir) - 1] != \)
				break;
			}
		}

		printf("将在目录 %s 初始化BOIT\n", InBaseDir);
		PathAppendA(InBaseDir, "BOIT\\");

		
		MultiByteToWideChar(CP_ACP, 0, InBaseDir, -1, GetBOITBaseDir(), MAX_PATH);
		
		if (InitializeSettings(GetBOITBaseDir()) != SETTINGS_INITIALIZED)
		{
			//Opps
			puts("初始化注册表失败，按任意键退出程序");
			_getch();
			return 0;
		}
		else
		{
			//初始化目录等
			//TODO: 检查是不是空目录
			InitBOITDirVar();

			InitBOITDir();

			

		}
		break;
	}
		
	}

	
	BroadcastCommandEvent(EC_CMDLOAD, 0, 0);

	InitServerState();
	InitSendEventDispatch();;
	InitEstablishConn();
	TryEstablishConn();

	printf("连接成功！\n");
	
	StartRecvEventHandler();

	WaitForSingleObject(hEventServerStop, INFINITE);

	//清理工作
	BroadcastCommandEvent(EC_CMDFREE, 0, 0);
	FinalizeCommandManager();
	FinalizeSandbox();
	return 0;
}