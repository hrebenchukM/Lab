#pragma once

class Queue
{
	// �������
	int* Wait;
	// ������������ ������ �������
	int MaxQueueLength;
	// ������� ������ �������
	int QueueLength;

public:
	// �����������
	Queue()=default;
	Queue(int m);
	
	//����������
	~Queue();

	// ���������� ��������
	void Add(int c);

	// ���������� ��������
	int Extract();

	// ������� �������
	void Clear();

	// �������� ������������� ��������� � �������
	bool IsEmpty();

	// �������� �� ������������ �������
	bool IsFull();

	// ���������� ��������� � �������//������� ������ � ������ ������ ������
	int GetCount();

	//������������ �������
	void Show();
};


