#include<Windows.h>
#include<stdio.h>
#include"EstablishConn.h"

int main()
{
	printf("BOIT Server��������");
	InitEstablishConn();
	TryEstablishConn();

	Sleep(100000);
	return 0;
}