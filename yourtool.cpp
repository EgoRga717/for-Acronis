#include <iostream>
#include <cstring>
#include <clocale>
#include <windows.h>//библиотека для заклинания в Windows.

using namespace std;

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "");
	SetConsoleCP(1251);//Заклинания, позволяют работать с русскими и не только текстами в Windows.
	SetConsoleOutputCP(1251);// Разве что шрифт нужно поменять на Lucida Console
	int* sizeArgv = new int[argc - 1];//Можно и обойтись и без этого массива, и просто в цикле вызывать strlen. Но это замедлит работу программы.
	for (int i = 1; i < argc; ++i)
		sizeArgv[i - 1] = strlen(argv[i]);
	int* progress = new int[argc - 1]; // Прогресс, т.е. на каком символе сейчас идет совпадение для каждого аргумента
	for (int i = 0; i < argc - 1; ++i)
		progress[i] = 0;
	char in;
	while (cin.get(in))
	{
		cout << in;
		if (in != '\n') //Я здесь переход строки как полноценный символ решил не считать
		{
			for (int i = 0; i < argc - 1; ++i)
			{
				if (argv[i + 1][progress[i]] == in)
					++progress[i];
				else
					progress[i] = 0;
				if (sizeArgv[i] == progress[i])
				{
					cout << '*';
					progress[i] = 0;
				}
			}
		}
	}
	delete[] sizeArgv;
	delete[] progress;
	return 0;
}
