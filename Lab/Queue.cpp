#include "Queue.h"
#include <iostream>
#include <string.h>
#include <time.h>
using namespace std;



void Queue::Show() {
	cout << "\n-------------------------------------\n";
	//демонстрация очереди
	for (int i = 0; i < QueueLength; i++) {
		cout << Wait[i] << " ";
	}
	cout << "\n-------------------------------------\n";
}

Queue::~Queue()
{
	cout << "Queue destructor!";
	//удаление очереди
	delete[]Wait;
}

Queue::Queue(int m)
{
	//получаем размер
	MaxQueueLength = m;
	//создаем очередь
	Wait = new int[MaxQueueLength];
	// Изначально очередь пуста
	QueueLength = 0;//мы же только создали вот и ноль
}

void Queue::Clear()
{
	// Эффективная "очистка" очереди 
	QueueLength = 0;//УБОРЩИЦА ПРОГНАЛА ВСЕХ С КАССЫ НАФИГ
}

bool Queue::IsEmpty()
{
	// Пуст?
	return QueueLength == 0;
}

bool Queue::IsFull()
{
	// Полон?
	return QueueLength == MaxQueueLength;
}

int Queue::GetCount()
{
	// Количество присутствующих в стеке элементов
	return QueueLength;//текущее количество
}

void Queue::Add(int c)
{
	// Если в очереди есть свободное место, то увеличиваем количество
	// значений и вставляем новый элемент
	if (!IsFull())//ЕСЛИ ЕСТЬ МЕСТО В ОЧЕРЕДИ
		Wait[QueueLength++] = c;//3++=4. В ИНДЕКС 4 МЕСТО ПРИСВАИВАЕМ ЧЕЛА :С: РАЗ ЕСТЬ МЕСТО
}

int Queue::Extract()//Вернет первого чела
{
	// Если в очереди есть элементы, то возвращаем тот, 
	// который вошел первым и сдвигаем очередь	
	if (!IsEmpty()) {
		//запомнить первого чела
		int temp = Wait[0];

		//сдвинуть все элементы
		for (int i = 1; i < QueueLength; i++)
			Wait[i - 1] = Wait[i];//Сдвиг к началу на один и херим первого чела ,которого запомнили 

		//уменьшить количество
		//QueueLength--;
		Wait[QueueLength - 1] = temp;//Записываем к последнее место первого чела которого сохранили

		//вернуть первый(нулевой)
		return temp;
		
	}

	else {// Если в стеке элементов нет
		cout << "!!!!";
		return -1;//ЕСЛИ ОЧЕРЕДЬ ПУСТАЯ НИЧЕГО НЕ ДЕЛАЕМ и возвращаем -1
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