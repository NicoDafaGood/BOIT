#include<Windows.h>
#include<stdio.h>
#include"EstablishConn.h"
#include"Global.h"
#include"RecvEventHandler.h"


int main()
{
	printf("BOIT Server��������\n");
	InitServerState();
	InitSendEventDispatch();;
	InitEstablishConn();
	TryEstablishConn();

	printf("���ӳɹ���\n");
	
	StartRecvEventHandler();

	WaitForSingleObject(hEventServerStop, INFINITE);

	//TODO:������

	return 0;
}