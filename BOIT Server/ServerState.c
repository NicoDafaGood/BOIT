#include<Windows.h>
#include"Global.h"

//���ڽ����Ǽ�¼server�Ƿ����������У��Ժ���ܼ���æµ�̶ȣ����ڴ����


int InitServerState()
{
	hEventServerStop = CreateEvent(0, 1, 0, 0);
	return 0;
}

int ServerStop()
{
	SetEvent(hEventServerStop);
	return 0;
}
