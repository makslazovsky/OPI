#include "filter.h"
#include <cstring>
#include <iostream>

data_subscription** filter(data_subscription* array[], int size, bool (*check)(data_subscription* element), int& result_size)
{
	data_subscription** result = new data_subscription * [size];
	result_size = 0;
	for (int i = 0; i < size; i++)
	{
		if (check(array[i]))
		{
			result[result_size++] = array[i];
		}
	}
	return result;
}

bool check_spartak(data_subscription* element)
{
	return strcmp(element->club, "Spartak") == 0;
}

bool check_speed(data_subscription* element)
{
    return element->timeToInt(element->finish) < 170;
}

data_subscription** bubblesort(data_subscription* array[], bool method)
{
    data_subscription** arr; // ��������� ��� ��������� ������ ��� ������
    int size = 5;
    arr = new data_subscription*[size]; // ��������� ������ ��� ������

    // ���������� �������
    for (int i = 0; i < size; i++) {
        arr[i] = array[i];
    }

    data_subscription* temp; // ��������� ���������� ��� ������ ��������� �������
    // ���������� ������� ���������
    if (method){
    for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {

                if (arr[j]->timeDIff(arr[j]->start,arr[j]->finish) > arr[j + 1]->timeDIff(arr[j+1]->start, arr[j+1]->finish)) {
                    // ������ �������� �������
                    temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }
    else
    {
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {

                if (strcmp(arr[j]->club, arr[j + 1]->club) > 0) {
                    // ������ �������� �������
                    temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }
    return arr;
}

data_subscription** quicksort(data_subscription* array[], int size, bool method) {
        //��������� � ������ � � ����� �������
        int i = 0;
        int j = size - 1;

        //����������� ������� �������
        data_subscription* mid = array[size / 2];
        if (method) {
            //����� ������
            do {
                //��������� ��������, ���� ��, ������� ����� ���������� � ������ �����
                //� ����� ����� ������� ����������(��������� �� �����) ��������, ������� ������ ������������
                while (array[i]->timeDIff(array[i]->start, array[i]->finish) < mid->timeDIff(mid->start, mid->finish)) {
                    i++;
                }
                //� ������ ����� ���������� ��������, ������� ������ ������������
                while (array[j]->timeDIff(array[j]->start, array[j]->finish) > mid->timeDIff(mid->start, mid->finish)) {
                    j--;
                }

                //������ �������� �������
                if (i <= j) {
                    data_subscription* tmp = array[i];
                    array[i] = array[j];
                    array[j] = tmp;

                    i++;
                    j--;
                }
            } 
            while (i <= j);

            //����������� ������, ���� ��������, ��� �����������
            if (j > 0) {
                //"����� �����"
                quicksort(array, j + 1, method);
            }
            if (i < size) {
                //"����� �����"
                quicksort(&array[i], size - i, method);
            }
        }
        else
        {
            //����� ������
            do {
                //��������� ��������, ���� ��, ������� ����� ���������� � ������ �����
                //� ����� ����� ������� ����������(��������� �� �����) ��������, ������� ������ ������������
                while (strcmp(array[i]->club, mid->club)<0) {
                    i++;
                }
                //� ������ ����� ���������� ��������, ������� ������ ������������
                while (strcmp(array[j]->club, mid->club)>0) {
                    j--;
                }

                //������ �������� �������
                if (i <= j) {
                    data_subscription* tmp = array[i];
                    array[i] = array[j];
                    array[j] = tmp;

                    i++;
                    j--;
                }
            } while (i <= j);

            //����������� ������, ���� ��������, ��� �����������
            if (j > 0) {
                //"����� �����"
                quicksort(array, j + 1, method);
            }
            if (i < size) {
                //"����� �����"
                quicksort(&array[i], size - i, method);
            }
        }
        return array;
}