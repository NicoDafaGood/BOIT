#pragma once
#include<Windows.h>

//������Command Event����д����CE�����������Ŀ�Ǹ�OIerд�ģ�CE��̫��������ȫ������EC��������


/* CoolQ���ڳ�ʼ�����߸�ָ���״μ��أ���Ҫ������ӦĿ¼
ParamA: δʹ��
ParamB: δʹ��  */
#define EC_DIRINIT 0x01 

/* ָ����أ����Խ���ָ���ʼ������
ParamA: δʹ��
ParamB: δʹ��  */
#define EC_CMDLOAD 0x02

/* ָ��ж�أ����Խ���ָ���������
ParamA: δʹ��
ParamB: δʹ��  */
#define EC_CMDFREE 0x03