#pragma once
#include "Queue.h"

class LOHOTRON
{
	static const int N = 10;
	Queue* drums;//Динамические поля класса лохотрон

	char display[3];//Show 3 znachka
	char symbols[N] = {'@', '#', '$', '%', '&', '*', '7', '?', 'X', 'Y'};
	
public:

	~LOHOTRON();//Почистить Queue Динамические поля
	void Init();
	int Input();//Ввод от пользователя ждем пока дернет рычаг
	void Roll();//крутить барабаны
	void Show();//Показать что выпало
};

