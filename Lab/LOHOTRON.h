#pragma once
#include "Queue.h"

class LOHOTRON
{
	static const int N = 10;
	Queue* drums;//������������ ���� ������ ��������

	char display[3];//Show 3 znachka
	char symbols[N] = {'@', '#', '$', '%', '&', '*', '7', '?', 'X', 'Y'};
	
public:

	~LOHOTRON();//��������� Queue ������������ ����
	void Init();
	int Input();//���� �� ������������ ���� ���� ������ �����
	void Roll();//������� ��������
	void Show();//�������� ��� ������
};

