#pragma once

class Queue
{
	// Очередь
	int* Wait;
	// Максимальный размер очереди
	int MaxQueueLength;
	// Текущий размер очереди
	int QueueLength;

public:
	// Конструктор
	Queue()=default;
	Queue(int m);
	
	//Деструктор
	~Queue();

	// Добавление элемента
	void Add(int c);

	// Извлечение элемента
	int Extract();

	// Очистка очереди
	void Clear();

	// Проверка существования элементов в очереди
	bool IsEmpty();

	// Проверка на переполнение очереди
	bool IsFull();

	// Количество элементов в очереди//сколько сейчас в данный момент зайдет
	int GetCount();

	//демонстрация очереди
	void Show();
};


