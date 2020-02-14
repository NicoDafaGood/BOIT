#include<Windows.h>
#include"DirManagement.h"
#include<wchar.h>

int CheckPerUserDataExist(long long QQID)
{
	WCHAR PerUserDir[MAX_PATH];
	wcscpy_s(PerUserDir, MAX_PATH, GetBOITUserDataDir());
	WCHAR QQIDStr[16] = { 0 };
	swprintf_s(QQIDStr, 16, L"%lld\\", QQID);

	PathAppendW(PerUserDir, QQIDStr);

	if (PathFileExistsW(PerUserDir) == 0)
	{
		//�����û�Ŀ¼
		CreatePerUserData(PerUserDir);
	}
	return 0;
}

int CreatePerUserData(WCHAR * Path)
{
	CreateDirectoryW(Path,0);//�����ļ���

	WCHAR FolderPath[MAX_PATH];
	wcscpy_s(FolderPath, MAX_PATH, Path);
	PathAppendW(FolderPath, L"Sandbox\\"); //ɳ�л���

	CreateDirectoryW(FolderPath, 0);

	wcscpy_s(FolderPath, MAX_PATH, Path);
	PathAppendW(FolderPath, L"Compile\\"); //���뻷��

	CreateDirectoryW(FolderPath, 0);
	return 0;
}

