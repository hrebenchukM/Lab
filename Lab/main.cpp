#include "Queue.h"
#include <iostream>
#include <string.h>
#include <time.h>
#include "LOHOTRON.h"
using namespace std;

int main()
{
	LOHOTRON loh;
	loh.Init();

	do {
		loh.Roll();
		loh.Show();
	} while (loh.Input());
	cout << endl << "Bye!" << endl;


	//Queue q(3);
	//q.Add(1);
	//q.Add(2);
	//q.Add(3);

	//for (int i=0; i<10; i++) {
	//	q.Show();
	//	cout << endl << q.Extract();
	//}

	
	/*srand(time(0));

	создание очереди
	Queue QU(25);

	заполнение части элементов
	for (int i = 0; i < 5; i++) {
		QU.Add(rand() % 50);
	}
	показ очереди
	QU.Show();

	извлечение элемента
	QU.Extract();

	показ очереди
	QU.Show();
	QU.Extract();

	показ очереди
	QU.Show();*/




}


