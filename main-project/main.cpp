#include <iostream>
#include <iomanip>

using namespace std;

#include "data_subscription.h"
#include "file_reader.h"
#include "constants.h"
#include "filter.h"

void output(data_subscription* subscription)
{
	/********** вывод читателя **********/
	cout << "Участник........: ";
	// вывод фамилии
	cout << subscription->reader.last_name << " ";
	// вывод первой буквы имени
	cout << subscription->reader.first_name[0] << ". ";
	// вывод первой буквы отчества
	cout << subscription->reader.middle_name[0] << ".";
	cout << '\n';
	/********** вывод даты выдачи **********/
	// вывод года
	cout << "Старт.....: ";
	cout << setw(2) << setfill('0') << subscription->start.hour << ':';
	// вывод месяца
	cout << setw(2) << setfill('0') << subscription->start.minute<< ':';
	// вывод числа
	cout << setw(2) << setfill('0') << subscription->start.sec;
	cout << '\n';
	/********** вывод даты возврата **********/
	// вывод года
	cout << "Финиш...: ";
	cout << setw(2) << setfill('0') << subscription->finish.hour << ':';
	// вывод месяца
	cout << setw(2) << setfill('0') << subscription->finish.minute << ':';
	// вывод числа
	cout << setw(2) << setfill('0') << subscription->finish.sec;
	cout << '\n';
	cout << "Клуб: ";
	cout <<   subscription->club;
	cout << '\n';
	cout << '\n';
}

int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "Лабораторная работа №1. GIT\n";
	cout << "Вариант №1. Результаты марафона\n";
	cout << "Автор: Лазовский Максим\n";
	cout << "Группа: 14з\n\n";
	data_subscription* subscriptions[MAX_FILE_ROWS_COUNT];
	int size;
	try
	{
		read("data.txt", subscriptions, size);
		cout << "***** Результаты марафона *****\n\n";
		for (int i = 0; i < size; i++)
		{
			output(subscriptions[i]);
		}
		bool (*check_function)(data_subscription*) = NULL;
		bool (**sort_function)(data_subscription*) = NULL;
		cout << "\nВыберите способ фильтрации или обработки данных:\n";
		cout << "1) Клуб спартак\n";
		cout << "2) Те кто справился быстрее чем 2:50\n";
		cout << "3) ПУЗЫРЬ\n";
		cout << "\nВведите номер выбранного пункта: ";
		int item;
		cin >> item;
		cout << '\n';
		switch (item)
		{
		case 1:
			check_function = check_spartak; // присваиваем в указатель на функцию соответствующую функцию
			cout << "***** Записи Спартак *****\n\n";
			break;
		case 2:
			check_function = check_speed; // присваиваем в указатель на функцию соответствующую функцию
			cout << "***** Записи Те кто справился быстрее чем 2:50 *****\n\n";
			break;
		case 3:
		{
			cout << "***** ПУЗЫРЬ:\n\n";
			data_subscription** sorted = bubblesort(subscriptions);
			for (int i = 0; i < size; i++)
			{
				output(sorted[i]);
			}
			break;
		}
		default:
			throw "Некорректный номер пункта";
		}
		if (check_function)
		{
			int new_size;
			data_subscription** filtered = filter(subscriptions, size, check_function, new_size);
			for (int i = 0; i < new_size; i++)
			{
				output(filtered[i]);
			}
			delete[] filtered;
		}
		for (int i = 0; i < size; i++)
		{
			delete subscriptions[i];
		}
	}
	catch (const char* error)
	{
		cout << error << '\n';
	}
	return 0;
}
