#include "processing.h"
#include "data_subscription.h"
#include <string>

char process(data_subscription* array[], int size) {

	int min = array[0]->timeDIff(array[0]->start, array[0]->finish);
	int numEl;
	for (int i = 1; i < size; i++)
	{
		
		int curr = array[i]->timeDIff(array[i]->start, array[i]->finish);
		if (curr > min)
	int numEl=1;
	for (int i = 0; i < size-1; i++)
	{

		int curr = array[i]->timeDIff(array[i]->start, array[i]->finish);
		if (curr <= min)
		{
			min = curr;
			numEl = i;
		}
	}
	char result = array[numEl]->finish.hour- array[numEl]->start.hour + ':' + array[numEl]->finish.minute - array[numEl]->start.minute + ':' + array[numEl]->finish.sec - array[numEl]->start.sec;
	return result;
};
	std::string result = std::to_string(array[numEl]->finish.hour - array[numEl]->start.hour) + ':' 
		+ std::to_string(array[numEl]->finish.minute - array[numEl]->start.minute) + ':' 
		+ std::to_string(array[numEl]->finish.sec - array[numEl]->start.sec);
	return *result.c_str();
};
