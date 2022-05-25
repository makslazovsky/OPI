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

data_subscription** bubblesort(data_subscription* array[])
{
    data_subscription** arr; // указатель для выделения памяти под массив
    int size = 5;
    arr = new data_subscription*[size]; // выделение памяти под массив

    // заполнение массива
    for (int i = 0; i < size; i++) {
        arr[i] = array[i];
    }

    data_subscription* temp; // временная переменная для обмена элементов местами
    // Сортировка массива пузырьком
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {

            if (arr[j]->timeDIff(arr[j]->start,arr[j]->finish) > arr[j + 1]->timeDIff(arr[j+1]->start, arr[j+1]->finish)) {
                // меняем элементы местами
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    return arr;
}