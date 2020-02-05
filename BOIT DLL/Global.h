#pragma once
#define WIN32_LEAN_AND_MEAN
#include<Windows.h>
#include"CoolQDef.h"

//��־����
#define _STR(x) #x
#define ADD_LOG(a, b, c) _ADD_LOG(a, b, c, __LINE__, __FUNCTION__)
#define _ADD_LOG(a, b, c, d, e) __ADD_LOG(a, b, c, d, e)
#define __ADD_LOG(a,b,c,d, e) AddLog(a, b, c "  ��ϸ��Ϣ: ���ļ� " __FILE__ " ���� " e " �� " #d " ��")
int AddLog(int priority, const char* category, const char* content);

#define LOG_DEBUG       CQLOG_DEBUG           //���� ��ɫ
#define LOG_INFO        CQLOG_INFO            //��Ϣ ��ɫ
#define LOG_INFOSUCCESS CQLOG_INFOSUCCESS     //��Ϣ(�ɹ�) ��ɫ
#define LOG_INFORECV    CQLOG_INFORECV        //��Ϣ(����) ��ɫ
#define LOG_INFOSEND    CQLOG_INFOSEND        //��Ϣ(����) ��ɫ
#define LOG_WARNING     CQLOG_WARNING         //���� ��ɫ
#define LOG_ERROR       CQLOG_ERROR           //���� ��ɫ
#define LOG_FATAL       CQLOG_FATAL           //�������� ���



//AppLifeRoutine ����
int AppInitialize();
int AppFinialize();
int AppEnabled();
int AppDisabled();


int HandlePrivateMessage(int subType, int msgId, long long fromQQ, const char* msg, int font);
int HandleGroupMessage(int subType, int msgId, long long fromGroup, long long fromQQ, const char* fromAnonymous, const char* msg, int font);