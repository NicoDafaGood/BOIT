#pragma once
#include<Windows.h>
#include"CommandManager.h"

int CmdMsg_qwq_Proc(pBOIT_COMMAND pCmd, long long GroupID, long long QQID, WCHAR * AnonymousName, WCHAR * Msg);
int CmdMsg_about_Proc(pBOIT_COMMAND pCmd, long long GroupID, long long QQID, WCHAR* AnonymousName, WCHAR* Msg);
int CmdMsg_commingfeature_Proc(pBOIT_COMMAND pCmd, long long GroupID, long long QQID, WCHAR* AnonymousName, WCHAR* Msg);
int CmdMsg_help_Proc(pBOIT_COMMAND pCmd, long long GroupID, long long QQID, WCHAR* AnonymousName, WCHAR* Msg);
int CmdMsg_run_Proc(pBOIT_COMMAND pCmd, long long GroupID, long long QQID, WCHAR* AnonymousName, WCHAR* Msg);
int CmdMsg_stop_Proc(pBOIT_COMMAND pCmd, long long GroupID, long long QQID, WCHAR* AnonymousName, WCHAR* Msg);
int CmdMsg_q_and_a_Proc(pBOIT_COMMAND pCmd, long long GroupID, long long QQID, WCHAR* AnonymousName, WCHAR* Msg);

int CmdEvent_run_Proc(pBOIT_COMMAND pCmd, UINT Event, PARAMA ParamA, PARAMB ParamB);
