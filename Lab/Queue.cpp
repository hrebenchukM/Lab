#include "Queue.h"
#include <iostream>
#include <string.h>
#include <time.h>
using namespace std;



void Queue::Show() {
	cout << "\n-------------------------------------\n";
	//������������ �������
	for (int i = 0; i < QueueLength; i++) {
		cout << Wait[i] << " ";
	}
	cout << "\n-------------------------------------\n";
}

Queue::~Queue()
{
	cout << "Queue destructor!";
	//�������� �������
	delete[]Wait;
}

Queue::Queue(int m)
{
	//�������� ������
	MaxQueueLength = m;
	//������� �������
	Wait = new int[MaxQueueLength];
	// ���������� ������� �����
	QueueLength = 0;//�� �� ������ ������� ��� � ����
}

void Queue::Clear()
{
	// ����������� "�������" ������� 
	QueueLength = 0;//�������� �������� ���� � ����� �����
}

bool Queue::IsEmpty()
{
	// ����?
	return QueueLength == 0;
}

bool Queue::IsFull()
{
	// �����?
	return QueueLength == MaxQueueLength;
}

int Queue::GetCount()
{
	// ���������� �������������� � ����� ���������
	return QueueLength;//������� ����������
}

void Queue::Add(int c)
{
	// ���� � ������� ���� ��������� �����, �� ����������� ����������
	// �������� � ��������� ����� �������
	if (!IsFull())//���� ���� ����� � �������
		Wait[QueueLength++] = c;//3++=4. � ������ 4 ����� ����������� ���� :�: ��� ���� �����
}

int Queue::Extract()//������ ������� ����
{
	// ���� � ������� ���� ��������, �� ���������� ���, 
	// ������� ����� ������ � �������� �������	
	if (!IsEmpty()) {
		//��������� ������� ����
		int temp = Wait[0];

		//�������� ��� ��������
		for (int i = 1; i < QueueLength; i++)
			Wait[i - 1] = Wait[i];//����� � ������ �� ���� � ����� ������� ���� ,�������� ��������� 

		//��������� ����������
		//QueueLength--;
		Wait[QueueLength - 1] = temp;//���������� � ��������� ����� ������� ���� �������� ���������

		//������� ������(�������)
		return temp;
		
	}

	else {// ���� � ����� ��������� ���
		cout << "!!!!";
		return -1;//���� ������� ������ ������ �� ������ � ���������� -1
	}
}
Queue::Queue(const Queue& other)
{
	
	MaxQueueLength = other.MaxQueueLength;
	Wait = new int[MaxQueueLength];

	for (int i = 0; i < other.QueueLength; ++i) {
		Wait[i] = other.Wait[i];
	}

	QueueLength = other.QueueLength;
}