#include "LOHOTRON.h"
#include<time.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

void LOHOTRON::Init()
{
	drums = new Queue[3];
	for (int d = 0; d < 3; d++) {
		drums[d] = Queue(N);
		for (int i = 0; i < N; i++)//Заполняем три очереди символами в одном и том же порядке
		{
			drums[d].Add((int)symbols[i]);
		}
		display[d] = symbols[0];
	}
}

LOHOTRON::~LOHOTRON()
{
	delete[] drums;
}

void LOHOTRON::Roll()
{
	srand(time(NULL));
	int r;
	for (int d = 0; d < 3; d++) {
		r = 1 + rand() % 20;
		for (int i = 0; i < r; i++) {
			int e = drums[d].Extract();
			cout << "e=" << e;
			display[d] = (char)e;
		}
	}
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
