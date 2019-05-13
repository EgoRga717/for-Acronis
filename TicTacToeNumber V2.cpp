//Время работы 01:06
#include <iostream>

using namespace std;


void from10to3(int* mass, int a)//int mass[9];
{
	for (int i = 8; i >= 0; --i)
	{
		mass[i] = a % 3;
		a /= 3;
	}
}

int main()
{
	int pole[9];//0 1 2    Значения: 0 - пусто  По факту это 9-значное число в троичной истеме исчисления
				//3 4 5				 1 - крест
				//6 7 8				 2 - нолик
	int number = 0;//От 0 до 3^9 - 1 = 19682
	from10to3(pole, number);
	int sum = 0;
	bool end = 0;
	while (1)
	{
		//Проверка на реальность
		int Xnum = 0;
		int Onum = 0;
		for(int i = 0; i < 9; ++i)
		{
			if (pole[i] == 1)
				Xnum++;
			if (pole[i] == 2)
				Onum++;
		}
		if (Xnum - Onum == 0)//Проверка на количество, последний ход - ход О, нужно проверить, есть ли 3 X в ряд, если есть, то этот пример нереален.
		{
			//Всего 8 рядов из 3-х Х может быть
			if (!((pole[0] == 1 && pole[4] == 1 && pole[8] == 1) || (pole[2] == 1 && pole[4] == 1 && pole[6] == 1) || // диагонали
				(pole[0] == 1 && pole[1] == 1 && pole[2] == 1) || (pole[3] == 1 && pole[4] == 1 && pole[5] == 1) || (pole[6] == 1 && pole[7] == 1 && pole[8] == 1) ||//горизонтали
				(pole[0] == 1 && pole[3] == 1 && pole[6] == 1) || (pole[1] == 1 && pole[4] == 1 && pole[7] == 1) || (pole[2] == 1 && pole[5] == 1 && pole[8] == 1)))//вертикали
				++sum;
		}
		if (Xnum - Onum == 1)//Проверка на количество, последний ход - ход X, нужно проверить, есть ли 3 О в ряд, если есть, то этот пример нереален.
		{
			//Всего 8 рядов из 3-х О может быть
			if (!((pole[0] == 2 && pole[4] == 2 && pole[8] == 2) || (pole[2] == 2 && pole[4] == 2 && pole[6] == 2) || // диагонали
				(pole[0] == 2 && pole[1] == 2 && pole[2] == 2) || (pole[3] == 2 && pole[4] == 2 && pole[5] == 2) || (pole[6] == 2 && pole[7] == 2 && pole[8] == 2) ||//горизонтали
				(pole[0] == 2 && pole[3] == 2 && pole[6] == 2) || (pole[1] == 2 && pole[4] == 2 && pole[7] == 2) || (pole[2] == 2 && pole[5] == 2 && pole[8] == 2)))//вертикали
				++sum;
		}
		//Моделирование следующего поля:
		number++;
		from10to3(pole, number);
		cout << number << " / 19683\n";
		if (number == 19683)
			break;
	}
	
	
	from10to3(pole, 19682);
	for (int i = 0; i < 9; ++i)
		cout << pole[i];
	cout << "\nTOTAL: " << sum;
	return 0;
}

