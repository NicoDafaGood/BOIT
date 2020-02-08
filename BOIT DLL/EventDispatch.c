#include<Windows.h>
#include"ObjectName.h"
#include"EstablishConn.h"
#include<Process.h>
#include "EventDispatch.h"
#include"Global.h"

//��������CQ�ĸ����¼�������ת��




unsigned __stdcall WaitForConnThread(void* Args);

int InitializeEventDispatch()
{
	InitializeSRWLock(&SendLock);
	InitializeSRWLock(&RecvLock);

	InitEstablishConn();
	_beginthreadex(0, 0, WaitForConnThread, 0, 0, 0);
	return 0;
}

int FinalizeEventDispatch()
{
	CleanConn();
	return 0;
}

unsigned __stdcall WaitForConnThread(void *Args)
{
	TryEstablishConn();
	return 0;
}
