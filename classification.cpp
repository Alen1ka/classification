#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
using namespace std;

int mistake(){
	//Задаем исходные значения и находим размер массива
	int all = 0;
	setlocale(LC_ALL, "RUS");
	string path = "ab.txt";
	ifstream file;
	file.open(path);
	string element;
	if (file.is_open())
	{
		while (!file.eof())
		{
			(file >> element).get();
			all++;
		}
	}
	else
	{ 
		cout << "Файл не существует" << endl; 
		system("pause"); 
		return 0;
	}
	file.close();

	//проверка количества значений
	int i = all / 3;
	int example_len = i + i - 1;
	file.open(path);
	string str;
	if (file.is_open())
	{
		for (int n = 0; n < 3; n++)
		{
			getline(file, str);
			//cout << str << endl;
			int length_str = str.length();
			//cout << length_str << endl;
			if ((length_str < example_len)||(all % 3 != 0)){
				cout << "Количества значений не равны\n";
				system("pause");
				return 0;
			}
		}
	}
	else
	{ 
		cout << "Файл не существует" << endl; 
		system("pause"); 
		return 0;
	}
	file.close();

	//Заполняем массив значениями из файла
	string *mas = new string[all];
	int number = 0;
	file.open(path);
	if (file.is_open())
	{
		while (!file.eof())
		{
			(file >> element).get();
			mas[number] = element;
			number++;
		}
	}
	else
	{
		cout << "Файл не существует" << endl;
		system("pause");
		return 0;
	}
	file.close();
	//cout << mas[i] << mas[i - 1] << endl;
	
	if ((all % 3 == 0) && ((mas[i - 1] == "A") || (mas[i - 1] == "B"))){

		//находим все D
		double N1;
		double N2;
		int n;
		cout << "Введите первое значение диапазона, который нужно найти и которму принадлежит N: ";
		cin >> N1;
		cout << "Введите второе значение диапазона, который нужно найти и которму принадлежит N: ";
		cin >> N2;
		cout << "Введите количество соседей: ";
		cin >> n;
		if (n>i){
			cout << "Количество соседей больше количества объектов\n";
		}
		else{
			double *D = new double[i];
			number = 0;
			for (int k = 0; k < i; k++){
				const char * _x = mas[number + i].c_str();
				double x = atof(_x);
				const char * _y = mas[number + i * 2].c_str();
				double y = atof(_y);
				D[k] = sqrt((x - N1)*(x - N1) + (y - N2)*(y - N2));
				number++;
				cout << "D[" << k+1 << "] = " << D[k] << "\n";
			}

			//находим минимальные D и считаем какого класса больше
			cout << "Минимальные значения D: ";
			int A = 0;
			int B = 0;
			int *mas_min = new int[n];
			for (int nomer = 0; nomer < n; nomer++){
				double max = numeric_limits<double>::max();
				double max2 = max;
				for (int k = 0; k < i; k++){
					if (D[k] < max2){
						max2 = D[k];
						mas_min[nomer] = k;
					}
				}
				int z = mas_min[nomer];
				D[z] = max;
				cout << "D[" << z + 1 << "], ";
				if (mas[z] == "A"){
					A++;
				}
				else B++;
			}

			//находим какому классу принадлежит N
			cout << "\nОтвет: ";
			if (A > B) cout << "N принадлежит A.";
			else cout << "N принадлежит B.";
			cout << "\n";
		}
	}
	else
		cout << "Количество классов не равно количеству объектов\n "; 
	system("pause");
	return 0;
}

int main()
{
	setlocale(LC_ALL, "RUS");
	mistake();
}
