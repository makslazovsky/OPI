#ifndef DATA_SUBSCRIPTION_H
#define DATA_SUBSCRIPTION_H

#include "constants.h"

struct date
{
	int hour;
	int minute;
	int sec;
};

struct person
{
	char first_name[MAX_STRING_SIZE];
	char middle_name[MAX_STRING_SIZE];
	char last_name[MAX_STRING_SIZE];
};

struct data_subscription
{
	person reader;
	date start;
	date finish;
	char club[MAX_STRING_SIZE];
	int timeToInt(date Date) {
		return Date.hour * 3600 + Date.minute * 60 + Date.sec;
	};
	int timeDIff(date start, date finish)
	{
		return timeToInt(finish) - timeToInt(start);
	};
};

#endif
