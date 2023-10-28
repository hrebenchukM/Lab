#include "LOHOTRON.h"
#include<time.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

void LOHOTRON::Init()
{
	//cout << "ENTER Init";
//	drums = new Queue[3];
	for (int d = 0; d < 3; d++) {
		Queue* qptr = new Queue(N);//Создаем указатель в котором создаем на куче очереди три раза на 10 єлементов
		drums[d] = *qptr;// К массиву очередей Присваиваем этот казатель


		//Вопрос ? Нафиг это было делать? Чтоб после Init все не удалялось ибо в стеке оно удалялось 
		//Если ты не пишешь new то переменная сидит в стеке и после выхода из стека удаляются все очереди.А нам надо чтоб сохранялось .
		//  А new єто всегда указатель потому что создался обьект где-то на куче и возвращает указатель в котором адрес этого обьекта в куче.


		for (int i = 0; i < N; i++)//Заполняем три очереди символами в одном и том же порядке
		{
			drums[d].Add((int)symbols[i]);
		}
		display[d] = symbols[0];
	}
//	cout << "EXIT Init";
}

LOHOTRON::~LOHOTRON()
{
	delete[] drums;
}

void LOHOTRON::Roll()
{
	//cout << "ENTER Roll";
	srand(time(NULL));
	int r;
	for (int d = 0; d < 3; d++) {
		r = 1 + rand() % 20;
		for (int i = 0; i < r; i++) {
			int e = drums[d].Extract();
//			cout << "e=" << e;
			display[d] = (char)e;
		}
	}
	//cout << "EXIT Roll";
}

void LOHOTRON::Show()
{
	for (int d = 0; d < 3; d++) {
		cout << " [" << display[d] << "] ";
	}
}

int LOHOTRON::Input() {
	int c = 0;
	do {
		cout << endl << "Press <1> for one more round, <0> for exit";
		cin >> c;
	} while (c!=0 && c!=1);
	return c;
}
