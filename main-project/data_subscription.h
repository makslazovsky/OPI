#ifndef DATA_SUBSCRIPTION_H
#define DATA_SUBSCRIPTION_H

#include "constants.h"

struct time
{
    int hour;
    int minute;
    int sec;
};

struct person
{
    int number;
    char first_name[MAX_STRING_SIZE];
    char middle_name[MAX_STRING_SIZE];
    char last_name[MAX_STRING_SIZE];
    char club;
};

struct data_subscription
{
    person reader;
    time start;
    time finish;
};

#endif