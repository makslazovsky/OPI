#include <iostream>
#include <iomanip>

using namespace std;

#include "data_subscription.h"
#include "file_reader.h"
#include "constants.h"
#include "filter.h"

void output(data_subscription* subscription)
{
	/********** ����� �������� **********/
	cout << "��������........: ";
	// ����� �������
	cout << subscription->reader.last_name << " ";
	// ����� ������ ����� �����
	cout << subscription->reader.first_name[0] << ". ";
	// ����� ������ ����� ��������
	cout << subscription->reader.middle_name[0] << ".";
	cout << '\n';
	/********** ����� ���� ������ **********/
	// ����� ����
	cout << "�����.....: ";
	cout << setw(2) << setfill('0') << subscription->start.hour << ':';
	// ����� ������
	cout << setw(2) << setfill('0') << subscription->start.minute<< ':';
	// ����� �����
	cout << setw(2) << setfill('0') << subscription->start.sec;
	cout << '\n';
	/********** ����� ���� �������� **********/
	// ����� ����
	cout << "�����...: ";
	cout << setw(2) << setfill('0') << subscription->finish.hour << ':';
	// ����� ������
	cout << setw(2) << setfill('0') << subscription->finish.minute << ':';
	// ����� �����
	cout << setw(2) << setfill('0') << subscription->finish.sec;
	cout << '\n';
	cout << "����: ";
	cout <<   subscription->club;
	cout << '\n';
	cout << '\n';
}

int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "������������ ������ �1. GIT\n";
	cout << "������� �1. ���������� ��������\n";
	cout << "�����: ��������� ������\n";
	cout << "������: 14�\n\n";
	data_subscription* subscriptions[MAX_FILE_ROWS_COUNT];
	int size;
	try
	{
		read("data.txt", subscriptions, size);
		cout << "***** ���������� �������� *****\n\n";
		for (int i = 0; i < size; i++)
		{
			output(subscriptions[i]);
		}
		bool (*check_function)(data_subscription*) = NULL;
		bool (**sort_function)(data_subscription*) = NULL;
		cout << "\n�������� ������ ���������� ��� ��������� ������:\n";
		cout << "1) ���� �������\n";
		cout << "2) �� ��� ��������� ������� ��� 2:50\n";
		cout << "3) ������\n";
		cout << "\n������� ����� ���������� ������: ";
		int item;
		cin >> item;
		cout << '\n';
		switch (item)
		{
		case 1:
			check_function = check_spartak; // ����������� � ��������� �� ������� ��������������� �������
			cout << "***** ������ ������� *****\n\n";
			break;
		case 2:
			check_function = check_speed; // ����������� � ��������� �� ������� ��������������� �������
			cout << "***** ������ �� ��� ��������� ������� ��� 2:50 *****\n\n";
			break;
		case 3:
		{
			cout << "***** ������:\n\n";
			data_subscription** sorted = bubblesort(subscriptions);
			for (int i = 0; i < size; i++)
			{
				output(sorted[i]);
			}
			break;
		}
		default:
			throw "������������ ����� ������";
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
