#include<Windows.h>
#include"Global.h"


//��������

int AppInitialize()//��ʼ��ʱ�ᱻִ��
{
	return 0;
}

int AppFinialize()//����ʱ�ᱻִ��
{
	return 0;
}

int AppEnabled()//����ʱִ�У������ʼ��ʱ�����õģ�����AppInitialize��ִ��һ�Σ�
{
	return 0;
}

int AppDisabled()//����ʱִ�У��������ʱ�����õģ�����AppFinializeǰִ��һ�Σ�����cqԭ��������һ����
{
	return 0;
}



int HandlePrivateMessage(int subType, int msgId, long long fromQQ, const char* msg, int font)
{
	return 0;
}


int HandleGroupMessage(int subType, int msgId, long long fromGroup, long long fromQQ, const char * fromAnonymous, const char * msg, int font)
{
	return 0;
}
