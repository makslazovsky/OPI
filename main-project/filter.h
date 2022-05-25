#ifndef FILTER_H
#define FILTER_H

#include "data_subscription.h"

data_subscription** filter(data_subscription* array[], int size, bool (*check)(data_subscription* element), int& result_size);


bool check_spartak(data_subscription* element);


bool check_speed(data_subscription* element);

data_subscription** bubblesort(data_subscription* array[]);

#endif