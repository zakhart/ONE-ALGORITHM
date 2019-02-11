// zakhart
// c++
#include <iostream>
#include <conio.h>
#include <fstream>

using namespace std;

int main()
{
	const int N = 100;
	char buff[N]; // буфер для хранения считываемого текста из файла 
	ifstream INPUT("INPUT.txt");
	INPUT.getline(buff, N); //считываем строку с файла
	INPUT.close();

	int num = strlen(buff); //кол-во символов в INPUT.txt
	int count = 0; //количество единиц
	int MAX = 0; //переменная для вычисления самой длинной строки единиц

	for (int i = 0; i < num; i++)
	{
		if (buff[i] == 49)//1 в таблице ASCII = 49, а 0 = 48, так как ряд чисел записан в строке
		{
			count++;
			if (count > MAX)
				MAX = count;
		}
		else
			count = 0;
	}

	char ArrayOfOnes[N] = {};

	for (int i = 0; i < MAX; i++)
		ArrayOfOnes[i] = 49; //1 в таблице ASCII для строк = 49

	ofstream OUTPUT("OUTPUT.txt");
	OUTPUT << ArrayOfOnes; //записываем строку в файл
	OUTPUT.close();

	_getch();
	return 0;
}
